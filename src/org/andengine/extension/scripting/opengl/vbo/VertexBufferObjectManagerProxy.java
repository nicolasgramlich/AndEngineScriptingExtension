package org.andengine.extension.scripting.opengl.vbo;

import org.andengine.opengl.vbo.VertexBufferObjectManager;
import org.andengine.util.exception.MethodNotSupportedException;


/**
 * (c) Zynga 2012
 *
 * @author Nicolas Gramlich <ngramlich@zynga.com>
 * @since 22:22:46 - 05.03.2012
 */
public abstract class VertexBufferObjectManagerProxy extends VertexBufferObjectManager {
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

	public VertexBufferObjectManagerProxy() {
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
