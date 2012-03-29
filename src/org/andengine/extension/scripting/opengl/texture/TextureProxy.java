package org.andengine.extension.scripting.opengl.texture;

import org.andengine.opengl.texture.PixelFormat;
import org.andengine.opengl.texture.Texture;
import org.andengine.opengl.texture.TextureManager;
import org.andengine.opengl.texture.TextureOptions;


/**
 * (c) Zynga 2012
 *
 * @author Nicolas Gramlich <ngramlich@zynga.com>
 * @since 18:43:18 - 05.03.2012
 */
public abstract class TextureProxy extends Texture {
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

	public TextureProxy(TextureManager pTextureManager, PixelFormat pPixelFormat, TextureOptions pTextureOptions, ITextureStateListener pTextureStateListener) throws IllegalArgumentException {
		super(pTextureManager, pPixelFormat, pTextureOptions, pTextureStateListener);
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
