#include "src/org/andengine/opengl/texture/bitmap/AssetBitmapTexture.h"
#include "src/ScriptingEnvironment.h"

static jclass sAssetBitmapTextureClass;

static jmethodID sConstructor;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_opengl_texture_bitmap_AssetBitmapTextureProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sAssetBitmapTextureClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);

	sConstructor = JNI_ENV()->GetMethodID(sAssetBitmapTextureClass, "<init>", "(JLorg/andengine/opengl/texture/TextureManager;Landroid/content/res/AssetManager;Ljava/lang/String;)V");
}

// ===========================================================
// org.andengine.extension.scripting.opengl.texture.bitmap.AssetBitmapTextureProxy
// ===========================================================

AssetBitmapTexture::AssetBitmapTexture(jobject pTextureManager, jobject pAssetManager, jstring pAssetPath) {
	this->mUnwrapped = JNI_ENV()->NewObject(sAssetBitmapTextureClass, sConstructor, (jlong)this, pTextureManager, pAssetManager, pAssetPath);
}
