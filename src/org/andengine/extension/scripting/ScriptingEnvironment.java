package org.andengine.extension.scripting;

import org.andengine.engine.Engine;
import org.andengine.extension.scripting.entity.EntityProxy;
import org.andengine.extension.scripting.entity.primitive.RectangleProxy;
import org.andengine.extension.scripting.entity.shape.ShapeProxy;
import org.andengine.extension.scripting.entity.sprite.SpriteProxy;

import android.content.Context;

/**
 * (c) Zynga 2012
 *
 * @author Nicolas Gramlich <ngramlich@zynga.com>
 * @since 17:01:34 - 28.02.2012
 */
public class ScriptingEnvironment {
	// ===========================================================
	// Constants
	// ===========================================================

	static {
		System.loadLibrary("gnustl_shared");
//		System.loadLibrary("js");
		System.loadLibrary("andenginescriptingextension");
	}

	// ===========================================================
	// Fields
	// ===========================================================

	// ===========================================================
	// Constructors
	// ===========================================================

	// ===========================================================
	// Getter & Setter
	// ===========================================================

	// ===========================================================
	// Methods for/from SuperClass/Interfaces
	// ===========================================================

	// ===========================================================
	// Methods
	// ===========================================================

	/**
	 * It is critical from which {@link Thread} this method is called!
	 *
	 * @param pContext
	 * @param pAPKPath
	 * @param pEngine
	 */
	public static void init(final Context pContext, final String pAPKPath, final Engine pEngine) {
		ScriptingEnvironment.nativeInit(pContext, pAPKPath, pEngine);

		EntityProxy.nativeInitClass();
		ShapeProxy.nativeInitClass();
		RectangleProxy.nativeInitClass();
		SpriteProxy.nativeInitClass();
	}

	private static native void nativeInit(final Context pContext, final String pAPKPath, final Engine pEngine);

	/**
	 * TODO read throughly about it before implementing!
	 */
	public static native void attachCurrentThread();

	// ===========================================================
	// Inner and Anonymous Classes
	// ===========================================================
}
