#include "src/org/andengine/opengl/texture/TextureManager.h"
#include "src/ScriptingEnvironment.h"

static jclass sTextureManagerClass;

static jmethodID sLoadTextureMethod;
static jmethodID sUnloadTextureMethod;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_opengl_texture_TextureManagerProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sTextureManagerClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);

	sLoadTextureMethod = JNI_ENV()->GetMethodID(sTextureManagerClass, "loadTexture", "(Lorg/andengine/opengl/texture/ITexture;)Z");
	sUnloadTextureMethod = JNI_ENV()->GetMethodID(sTextureManagerClass, "unloadTexture", "(Lorg/andengine/opengl/texture/ITexture;)Z");
}

// ===========================================================
// org.andengine.extension.scripting.opengl.texture.TextureManagerProxy
// ===========================================================

TextureManager::TextureManager(jobject pTextureManager) {
	this->mUnwrapped = pTextureManager;
}

bool TextureManager::loadTexture(Texture* pTexture) {
	return JNI_ENV()->CallBooleanMethod(this->mUnwrapped, sLoadTextureMethod, pTexture->unwrap());
}

bool TextureManager::unloadTexture(Texture* pTexture) {
	return JNI_ENV()->CallBooleanMethod(this->mUnwrapped, sUnloadTextureMethod, pTexture->unwrap());
}
