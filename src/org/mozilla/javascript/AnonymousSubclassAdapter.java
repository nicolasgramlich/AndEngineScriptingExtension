/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Rhino code, released
 * May 6, 1999.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1997-1999
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Igor Bukanov
 *
 * Alternatively, the contents of this file may be used under the terms of
 * the GNU General Public License Version 2 or later (the "GPL"), in which
 * case the provisions of the GPL are applicable instead of those above. If
 * you wish to allow use of your version of this file only under the terms of
 * the GPL and not to allow others to use your version of this file under the
 * MPL, indicate your decision by deleting the provisions above and replacing
 * them with the notice and other provisions required by the GPL. If you do
 * not delete the provisions above, a recipient may use your version of this
 * file under either the MPL or the GPL.
 *
 * ***** END LICENSE BLOCK ***** */

package org.mozilla.javascript;

import java.lang.reflect.Method;

import org.andengine.util.exception.MethodNotSupportedException;
import org.mozilla.javascript.ScriptableObject.Slot;

/**
 * Adapter to use JS function as implementation of Java interfaces with
 * single method or multiple methods with the same signature.
 */
public class AnonymousSubclassAdapter {
	private final Object proxyHelper;

	/**
	 * Make glue object implementing interface cl that will
	 * call the supplied JS function when called.
	 * Only interfaces were all methods have the same signature is supported.
	 *
	 * @return The glue object or null if <tt>cl</tt> is not interface or
	 *         has methods with different signatures.
	 */
	static Object create(final Context cx, final Class<?> cl, final ScriptableObject object, final Object o, final Slot[] pSlots) {
		final Scriptable topScope = ScriptRuntime.getTopCallScope(cx);
		final ClassCache cache = ClassCache.get(topScope);
		AnonymousSubclassAdapter adapter;
		adapter = (AnonymousSubclassAdapter) cache.getAnonymousSubclassAdapter(cl);
		final ContextFactory cf = cx.getFactory();
		if(adapter == null) {
			if(object instanceof Callable) {
				final Method[] methods = cl.getMethods();
				// Check if interface can be implemented by a single function.
				// We allow this if the interface has only one method or multiple
				// methods with the same name (in which case they'd result in
				// the same function to be invoked anyway).
				final int length = methods.length;
				if(length == 0) {
					throw Context.reportRuntimeError1("msg.no.empty.interface.conversion", cl.getName());
				}
				if(length > 1) {
					final String methodName = methods[0].getName();
					for(int i = 1; i < length; i++) {
						if(!methodName.equals(methods[i].getName())) {
							throw Context.reportRuntimeError1("msg.no.function.interface.conversion", cl.getName());
						}
					}
				}
			}
			adapter = new AnonymousSubclassAdapter(cf, cl);
			cache.cacheInterfaceAdapter(cl, adapter);
		}
		return VMBridge.instance.newAnonymousSubclassProxy(adapter.proxyHelper, cf, adapter, object, topScope, o, pSlots);
	}

	private AnonymousSubclassAdapter(final ContextFactory cf, final Class cl) {
		this.proxyHelper = VMBridge.instance.getAnonymousSubclassProxyHelper(cf, cl);
	}

	public Object invoke(final ContextFactory cf, final Object target, final Scriptable topScope, final Method method, final Object[] args, final Object pO, final Slot[] pSlots) {
		final ContextAction action = new ContextAction() {
			@Override
			public Object run(final Context cx) {
				try {
					return AnonymousSubclassAdapter.this.invokeImpl(cx, target, topScope, method, args);
				} catch (MethodNotSupportedException e) {
					final Object o = pO;
					final Slot[] slots = pSlots;

					return AnonymousSubclassAdapter.this.invokeImpl(cx, o, topScope, method, args);
				}
			}
		};
		return cf.call(action);
	}

	Object invokeImpl(final Context cx, final Object target, final Scriptable topScope, final Method method, final Object[] args) {
		final int N = (args == null) ? 0 : args.length;

		Callable function;
		if(target instanceof Callable) {
			function = (Callable) target;
		} else {
			final Scriptable s = (Scriptable) target;
			final String methodName = method.getName();
			final Object value = ScriptableObject.getProperty(s, methodName);
			if(value == Scriptable.NOT_FOUND) {
				throw new MethodNotSupportedException();
			}
			if(!(value instanceof Callable)) {
				throw Context.reportRuntimeError1("msg.not.function.interface", methodName);
			}
			function = (Callable) value;
		}
		final Object[] jsargs = new Object[N + 1];
		jsargs[N] = method.getName();
		if(N != 0) {
			final WrapFactory wf = cx.getWrapFactory();
			for(int i = 0; i != N; ++i) {
				jsargs[i] = wf.wrap(cx, topScope, args[i], null);
			}
		}

		Object result = function.call(cx, topScope, topScope, jsargs);
		final Class<?> javaResultType = method.getReturnType();
		if(javaResultType == Void.TYPE) {
			result = null;
		} else {
			result = Context.jsToJava(result, javaResultType);
		}
		return result;
	}
}