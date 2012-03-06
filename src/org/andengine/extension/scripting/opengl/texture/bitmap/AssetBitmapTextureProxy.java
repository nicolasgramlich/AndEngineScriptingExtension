package org.andengine.extension.scripting.opengl.texture.bitmap;

import java.io.IOException;

import org.andengine.opengl.texture.TextureManager;
import org.andengine.opengl.texture.bitmap.AssetBitmapTexture;

import android.content.res.AssetManager;

/**
 * (c) Zynga 2012
 *
 * @author Nicolas Gramlich <ngramlich@zynga.com>
 * @since 18:26:44 - 05.03.2012
 */
public class AssetBitmapTextureProxy extends AssetBitmapTexture {
	// ===========================================================
	// Constants
	// ===========================================================

	public static native void nativeInitClass();

	// ===========================================================
	// Fields
	// ===========================================================

	private final long mAddress;

	// ===========================================================
	// Constructors
	// ===========================================================

	public AssetBitmapTextureProxy(final long pAddress, final TextureManager pTextureManager, final AssetManager pAssetManager, final String pAssetPath) throws IOException {
		super(pTextureManager, pAssetManager, pAssetPath);

		this.mAddress = pAddress;
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
