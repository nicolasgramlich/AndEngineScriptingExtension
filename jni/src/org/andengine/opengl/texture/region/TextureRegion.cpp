#include "src/org/andengine/opengl/texture/region/TextureRegion.h"
#include "src/AndEngineScriptingExtension.h"

static jclass sTextureRegionClass;

static jmethodID sConstructor;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_opengl_texture_region_TextureRegionProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sTextureRegionClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);

	sConstructor = JNI_ENV()->GetMethodID(sTextureRegionClass, "<init>", "(JLorg/andengine/opengl/texture/ITexture;FFFF)V");
}

// ===========================================================
// org.andengine.extension.scripting.opengl.texture.bitmap.TextureRegionProxy
// ===========================================================

TextureRegion::TextureRegion(Texture* pTexture, float pTextureX, float pTextureY, float pTextureWidth, float pTextureHeight) {
	this->mUnwrapped = JNI_ENV()->NewObject(sTextureRegionClass, sConstructor, (jlong)this, pTexture->unwrap(), pTextureX, pTextureY, pTextureWidth, pTextureHeight);
}
