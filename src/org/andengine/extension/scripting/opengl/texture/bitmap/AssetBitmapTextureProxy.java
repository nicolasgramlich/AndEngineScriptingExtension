package org.andengine.extension.scripting.opengl.texture.bitmap;

import android.content.res.AssetManager;
import android.content.res.AssetManager;
import android.content.res.AssetManager;
import android.content.res.AssetManager;
import android.content.res.AssetManager;

import org.andengine.opengl.texture.ITextureStateListener;
import org.andengine.opengl.texture.TextureManager;
import org.andengine.opengl.texture.TextureManager;
import org.andengine.opengl.texture.TextureManager;
import org.andengine.opengl.texture.TextureManager;
import org.andengine.opengl.texture.TextureManager;
import org.andengine.opengl.texture.TextureOptions;
import org.andengine.opengl.texture.TextureOptions;
import org.andengine.opengl.texture.TextureOptions;
import org.andengine.opengl.texture.bitmap.AssetBitmapTexture;
import org.andengine.opengl.texture.bitmap.BitmapTextureFormat;
import org.andengine.opengl.texture.bitmap.BitmapTextureFormat;
import org.andengine.opengl.texture.bitmap.BitmapTextureFormat;
import org.andengine.opengl.util.GLState;
import org.andengine.opengl.util.GLState;

import java.io.IOException;
import java.io.IOException;
import java.io.IOException;
import java.io.IOException;
import java.io.IOException;


public class AssetBitmapTextureProxy extends AssetBitmapTexture {
    private final long mAddress;

    public AssetBitmapTextureProxy(final long pAddress,
        final TextureManager pTextureManager, final AssetManager pAssetManager,
        final String pAssetPath) throws IOException {
        super(pTextureManager, pAssetManager, pAssetPath);
        this.mAddress = pAddress;
    }

    public AssetBitmapTextureProxy(final long pAddress,
        final TextureManager pTextureManager, final AssetManager pAssetManager,
        final String pAssetPath, final BitmapTextureFormat pBitmapTextureFormat)
        throws IOException {
        super(pTextureManager, pAssetManager, pAssetPath, pBitmapTextureFormat);
        this.mAddress = pAddress;
    }

    public AssetBitmapTextureProxy(final long pAddress,
        final TextureManager pTextureManager, final AssetManager pAssetManager,
        final String pAssetPath, final TextureOptions pTextureOptions)
        throws IOException {
        super(pTextureManager, pAssetManager, pAssetPath, pTextureOptions);
        this.mAddress = pAddress;
    }

    public AssetBitmapTextureProxy(final long pAddress,
        final TextureManager pTextureManager, final AssetManager pAssetManager,
        final String pAssetPath,
        final BitmapTextureFormat pBitmapTextureFormat,
        final TextureOptions pTextureOptions) throws IOException {
        super(pTextureManager, pAssetManager, pAssetPath, pBitmapTextureFormat,
            pTextureOptions);
        this.mAddress = pAddress;
    }

    public AssetBitmapTextureProxy(final long pAddress,
        final TextureManager pTextureManager, final AssetManager pAssetManager,
        final String pAssetPath,
        final BitmapTextureFormat pBitmapTextureFormat,
        final TextureOptions pTextureOptions,
        final ITextureStateListener pTextureStateListener)
        throws IOException {
        super(pTextureManager, pAssetManager, pAssetPath, pBitmapTextureFormat,
            pTextureOptions, pTextureStateListener);
        this.mAddress = pAddress;
    }

    public static native void nativeInitClass();
}
