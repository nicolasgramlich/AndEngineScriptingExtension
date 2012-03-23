package org.andengine.extension.scripting;

import org.andengine.engine.Engine;
import org.andengine.extension.scripting.engine.EngineProxy;
import org.andengine.extension.scripting.entity.EntityProxy;
import org.andengine.extension.scripting.entity.primitive.RectangleProxy;
import org.andengine.extension.scripting.entity.scene.SceneProxy;
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

	/**
	 * It is critical from which {@link Thread} this method is called!
	 *
	 * @param pContext
	 * @param pAPKPath
	 * @param pEngine
	 */
	public static void init(final Context pContext, final String pAPKPath, final Engine pEngine) {
		ScriptingEnvironment.nativeInitClass();

		/* Setup. */
		ContextProxy.nativeInitClass();
		
		EngineProxy.nativeInitClass();

		/* VBO. */
		VertexBufferObjectManagerProxy.nativeInitClass();

		/* Texture. */
		TextureManagerProxy.nativeInitClass();
		TextureProxy.nativeInitClass();
		AssetBitmapTextureProxy.nativeInitClass();
		TextureRegionProxy.nativeInitClass();

		/* Font. */
		FontManagerProxy.nativeInitClass();
		FontProxy.nativeInitClass();

		/* Entity. */
		EntityProxy.nativeInitClass();
		ShapeProxy.nativeInitClass();
		RectangleProxy.nativeInitClass();
		SpriteProxy.nativeInitClass();
		SceneProxy.nativeInitClass();

		/* Actual init. */
		ScriptingEnvironment.nativeInit(pContext, pAPKPath, pEngine);
	}

	public static native String getJavaScriptVMVersion();

	private static native void nativeInitClass();
	private static native void nativeInit(final Context pContext, final String pAPKPath, final Engine pEngine);


	public static void attachCurrentThread() {
		ScriptingEnvironment.nativeAttachCurrentThread();
	}

	private static native void nativeAttachCurrentThread();

	public static void detachCurrentThread() {
		ScriptingEnvironment.nativeDetachCurrentThread();
	}

	private static native void nativeDetachCurrentThread();

	// ===========================================================
	// Inner and Anonymous Classes
	// ===========================================================
}
