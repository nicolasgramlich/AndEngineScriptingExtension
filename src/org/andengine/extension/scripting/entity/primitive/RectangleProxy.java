package org.andengine.extension.scripting.entity.primitive;

import org.andengine.entity.primitive.Rectangle;
import org.andengine.opengl.vbo.VertexBufferObjectManager;
import org.andengine.util.debug.Debug;

/**
 * (c) Zynga 2012
 *
 * @author Nicolas Gramlich <ngramlich@zynga.com>
 * @since 13:24:46 - 01.03.2012
 */
public class RectangleProxy extends Rectangle {
	// ===========================================================
	// Constants
	// ===========================================================

	// ===========================================================
	// Fields
	// ===========================================================

	private final long mAddress;

	// ===========================================================
	// Constructors
	// ===========================================================

	public RectangleProxy(final long pAddress, final float pX, final float pY, final float pWidth, final float pHeight, final VertexBufferObjectManager pVertexBufferObjectManager) {
		super(pX, pY, pWidth, pHeight, pVertexBufferObjectManager);

		Debug.d("WORKS!");
		if(pVertexBufferObjectManager != null) {
			Debug.d("NOT NULL!");
			Debug.d("NATIVE CRASH: " + pVertexBufferObjectManager);
		}

		this.mAddress = pAddress;
	}

	// ===========================================================
	// Getter & Setter
	// ===========================================================

	// ===========================================================
	// Methods for/from SuperClass/Interfaces
	// ===========================================================

	@Override
	public void onAttached() {
		if(!this.nativeOnAttached(this.mAddress)) {
			super.onAttached();
		}
	}

	private native boolean nativeOnAttached(final long pAddress);

	@Override
	public void onDetached() {
		if(!this.nativeOnDetached(this.mAddress)) {
			super.onDetached();
		}
	}

	private native boolean nativeOnDetached(final long pAddress);

	// ===========================================================
	// Methods
	// ===========================================================

	// ===========================================================
	// Inner and Anonymous Classes
	// ===========================================================
}
