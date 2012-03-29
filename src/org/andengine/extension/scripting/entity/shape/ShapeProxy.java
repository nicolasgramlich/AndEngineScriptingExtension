package org.andengine.extension.scripting.entity.shape;

import org.andengine.entity.shape.Shape;
import org.andengine.opengl.shader.ShaderProgram;
import org.andengine.util.exception.MethodNotSupportedException;

/**
 * (c) Zynga 2012
 *
 * @author Nicolas Gramlich <ngramlich@zynga.com>
 * @since 15:44:41 - 02.03.2012
 */
public abstract class ShapeProxy extends Shape {
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

	public ShapeProxy(final float pX, final float pY, final ShaderProgram pShaderProgram) {
		super(pX, pY, pShaderProgram);

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
