package org.andengine.extension.scripting;

import org.andengine.engine.Engine;

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

	public static native void init(final String pAPKPath, final Engine pEngine);

	// ===========================================================
	// Inner and Anonymous Classes
	// ===========================================================
}
