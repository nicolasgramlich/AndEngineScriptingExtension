package org.andengine.extension.scripting.opengl.font;

import org.andengine.opengl.font.FontManager;
import org.andengine.util.exception.MethodNotSupportedException;


/**
 * (c) Zynga 2012
 *
 * @author Nicolas Gramlich <ngramlich@zynga.com>
 * @since 22:23:51 - 05.03.2012
 */
public abstract class FontManagerProxy extends FontManager {
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

	public FontManagerProxy() {
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
