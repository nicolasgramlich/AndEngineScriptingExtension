package org.andengine.extension.scripting.input.touch;

import org.andengine.input.touch.TouchEvent;
import org.andengine.util.exception.MethodNotSupportedException;

/**
 * (c) Zynga 2012
 *
 * @author Nicolas Gramlich <ngramlich@zynga.com>
 * @since 18:59:49 - 26.03.2012
 */
public abstract class TouchEventProxy extends TouchEvent {
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

	public TouchEventProxy() {
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
