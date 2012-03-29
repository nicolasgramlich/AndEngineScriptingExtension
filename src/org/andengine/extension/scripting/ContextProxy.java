package org.andengine.extension.scripting;

import org.andengine.util.exception.MethodNotSupportedException;

import android.content.Context;

/**
 * (c) Zynga 2012
 *
 * @author Nicolas Gramlich <ngramlich@zynga.com>
 * @since 17:37:39 - 05.03.2012
 */
public abstract class ContextProxy extends Context {
	// ===========================================================
	// Constants
	// ===========================================================

	public static native void nativeInitClass();

	// ===========================================================
	// Fields
	// ===========================================================

	// ===========================================================
	// Constructors
	// ===========================================================

	public ContextProxy() {
		throw new MethodNotSupportedException();
	}

	// ===========================================================
	// Getter & Setter
	// ===========================================================

	// ===========================================================
	// Methods for/from SuperClass/Interfaces
	// ===========================================================

	// ===========================================================
	// Methods
	// ===========================================================

	// ===========================================================
	// Inner and Anonymous Classes
	// ===========================================================
}
