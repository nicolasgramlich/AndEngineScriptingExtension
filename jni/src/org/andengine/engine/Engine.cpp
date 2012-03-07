#include "src/org/andengine/engine/Engine.h"
#include "src/ScriptingEnvironment.h"

static jclass sEngineClass;

static jmethodID sConstructor;
static jmethodID sGetVertexBufferObjectManagerMethod;
static jmethodID sGetTextureManagerMethod;
static jmethodID sGetFontManagerMethod;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_engine_EngineProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sEngineClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);

	sConstructor = JNI_ENV()->GetMethodID(sEngineClass, "<init>", "(JLorg/andengine/engine/options/EngineOptions;)V");
	sGetVertexBufferObjectManagerMethod = JNI_ENV()->GetMethodID(sEngineClass, "getVertexBufferObjectManager", "()Lorg/andengine/opengl/vbo/VertexBufferObjectManager;");
	sGetTextureManagerMethod = JNI_ENV()->GetMethodID(sEngineClass, "getTextureManager", "()Lorg/andengine/opengl/texture/TextureManager;");
	sGetFontManagerMethod = JNI_ENV()->GetMethodID(sEngineClass, "getFontManager", "()Lorg/andengine/opengl/font/FontManager;");
}

// ===========================================================
// org.andengine.extension.scripting.engine.EngineProxy
// ===========================================================

Engine::Engine(jobject pEngine) {
	this->mUnwrapped = pEngine;

	this->mVertexBufferObjectManager = new VertexBufferObjectManager(JNI_ENV()->CallObjectMethod(this->mUnwrapped, sGetVertexBufferObjectManagerMethod));	
	this->mTextureManager = new TextureManager(JNI_ENV()->CallObjectMethod(this->mUnwrapped, sGetTextureManagerMethod));	
	this->mFontManager = new FontManager(JNI_ENV()->CallObjectMethod(this->mUnwrapped, sGetFontManagerMethod));	
}

VertexBufferObjectManager* Engine::getVertexBufferObjectManager() {
	return this->mVertexBufferObjectManager;
}

TextureManager* Engine::getTextureManager() {
	return this->mTextureManager;
}

FontManager* Engine::getFontManager() {
	return this->mFontManager;
}
