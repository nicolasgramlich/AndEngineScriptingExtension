#include "EngineProxy.h"
#include "ScriptingEnvironment.h"

EngineProxy::EngineProxy(jobject pEngine) {
	mUnwrapped = pEngine;
}

jobject EngineProxy::getVertexBufferObjectManager() {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/engine/Engine");

	jmethodID getVertexBufferObjectManagerMethod = JNI_ENV()->GetMethodID(clazz, "getVertexBufferObjectManager", "()Lorg/andengine/opengl/vbo/VertexBufferObjectManager;");

	return JNI_ENV()->CallObjectMethod(this->mUnwrapped, getVertexBufferObjectManagerMethod);
}

jobject EngineProxy::getTextureManager() {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/engine/Engine");

	jmethodID getTextureManagerMethod = JNI_ENV()->GetMethodID(clazz, "getTextureManager", "()Lorg/andengine/opengl/texture/TextureManager;");

	return JNI_ENV()->CallObjectMethod(this->mUnwrapped, getTextureManagerMethod);
}

jobject EngineProxy::getFontManager() {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/engine/Engine");

	jmethodID getFontManagerMethod = JNI_ENV()->GetMethodID(clazz, "getFontManager", "()Lorg/andengine/opengl/font/FontManager;");

	return JNI_ENV()->CallObjectMethod(this->mUnwrapped, getFontManagerMethod);
}
