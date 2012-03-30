#include "src/org/andengine/opengl/texture/Texture.h"
#include "src/AndEngineScriptingExtension.h"

static jclass sTextureClass;

static jmethodID sLoadMethod;
static jmethodID sUnloadMethod;
static jmethodID sGetWidthMethod;
static jmethodID sGetHeightMethod;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_opengl_texture_TextureProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sTextureClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);

	sLoadMethod = JNI_ENV()->GetMethodID(sTextureClass, "load", "()V");
	sUnloadMethod = JNI_ENV()->GetMethodID(sTextureClass, "unload", "()V");
	sGetWidthMethod = JNI_ENV()->GetMethodID(sTextureClass, "getWidth", "()I");
	sGetHeightMethod = JNI_ENV()->GetMethodID(sTextureClass, "getHeight", "()I");
}

// ===========================================================
// org.andengine.extension.scripting.opengl.texture.TextureProxy
// ===========================================================

Texture::Texture() {
	/* Intentionally empty. */
}

void Texture::load() {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sLoadMethod);
}

void Texture::unload() {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sUnloadMethod);
}

int Texture::getWidth() {
	return JNI_ENV()->CallIntMethod(this->mUnwrapped, sGetWidthMethod);
}

int Texture::getHeight() {
	return JNI_ENV()->CallIntMethod(this->mUnwrapped, sGetHeightMethod);
}
