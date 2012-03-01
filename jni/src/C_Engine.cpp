#include "C_Engine.h"
#include "ScriptingEnvironment.h"

C_Engine::C_Engine (jobject pEngine) {
	mUnwrapped = pEngine;
}

jobject C_Engine::getVertexBufferObjectManager() {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/engine/Engine");

	jmethodID getVertexBufferObjectManagerMethod = JNI_ENV()->GetMethodID(clazz, "getVertexBufferObjectManager", "()Lorg/andengine/opengl/vbo/VertexBufferObjectManager;");

	return JNI_ENV()->CallObjectMethod(this->mUnwrapped, getVertexBufferObjectManagerMethod);
}

jobject C_Engine::getTextureManager() {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/engine/Engine");

	jmethodID getTextureManagerMethod = JNI_ENV()->GetMethodID(clazz, "getTextureManager", "()Lorg/andengine/opengl/texture/TextureManager;");

	return JNI_ENV()->CallObjectMethod(this->mUnwrapped, getTextureManagerMethod);
}

jobject C_Engine::getFontManager() {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/engine/Engine");

	jmethodID getFontManagerMethod = JNI_ENV()->GetMethodID(clazz, "getFontManager", "()Lorg/andengine/opengl/font/FontManager;");

	return JNI_ENV()->CallObjectMethod(this->mUnwrapped, getFontManagerMethod);
}
