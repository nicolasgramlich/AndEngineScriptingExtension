package org.andengine.extension.scripting;

import org.andengine.engine.Engine;
import org.andengine.engine.options.EngineOptions;
import org.andengine.extension.scripting.engine.EngineProxy;
import org.andengine.extension.scripting.entity.EntityProxy;
import org.andengine.extension.scripting.entity.primitive.RectangleProxy;
import org.andengine.extension.scripting.entity.shape.ShapeProxy;
import org.andengine.extension.scripting.entity.sprite.SpriteProxy;
import org.andengine.extension.scripting.opengl.font.FontManagerProxy;
import org.andengine.extension.scripting.opengl.font.FontProxy;
import org.andengine.extension.scripting.opengl.texture.TextureManagerProxy;
import org.andengine.extension.scripting.opengl.texture.TextureProxy;
import org.andengine.extension.scripting.opengl.texture.bitmap.AssetBitmapTextureProxy;
import org.andengine.extension.scripting.opengl.texture.region.TextureRegionProxy;
import org.andengine.extension.scripting.opengl.vbo.VertexBufferObjectManagerProxy;

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

	public static Engine onCreateEngine(final EngineOptions pEngineOptions) {
		return ScriptingEnvironment.nativeOnCreateEngine(pEngineOptions);
	}

	private static native Engine nativeOnCreateEngine(EngineOptions pEngineOptions);

	/**
	 * It is critical from which {@link Thread} this method is called!
	 *
	 * @param pContext
	 * @param pAPKPath
	 */
	public static void init(final Context pContext, final String pAPKPath) {
		ScriptingEnvironment.nativeInitClass();
		ScriptingEnvironment.nativeInit(pContext, pAPKPath);

		ContextProxy.nativeInitClass();

		EngineProxy.nativeInitClass();

		VertexBufferObjectManagerProxy.nativeInitClass();

		TextureManagerProxy.nativeInitClass();
		TextureProxy.nativeInitClass();
		AssetBitmapTextureProxy.nativeInitClass();
		TextureRegionProxy.nativeInitClass();

		FontManagerProxy.nativeInitClass();
		FontProxy.nativeInitClass();

		EntityProxy.nativeInitClass();
		ShapeProxy.nativeInitClass();
		RectangleProxy.nativeInitClass();
		SpriteProxy.nativeInitClass();
	}

	private static native void nativeInitClass();
	private static native void nativeInit(final Context pContext, final String pAPKPath);

	/**
	 * TODO read throughly about it before implementing!
	 */
	public static native void attachCurrentThread();

	// ===========================================================
	// Inner and Anonymous Classes
	// ===========================================================
}
