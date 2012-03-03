#include "EngineProxy.h"
#include "ScriptingEnvironment.h"

EngineProxy::EngineProxy(jobject pEngine) {
	// TODO http://android-developers.blogspot.com/2011/11/jni-local-reference-changes-in-ics.html
	mUnwrapped = pEngine;
}

jobject EngineProxy::getVertexBufferObjectManager() {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/engine/Engine");

	jmethodID getVertexBufferObjectManagerMethod = JNI_ENV()->GetMethodID(clazz, "getVertexBufferObjectManager", "()Lorg/andengine/opengl/vbo/VertexBufferObjectManager;");
	
	jobject result = JNI_ENV()->CallObjectMethod(this->mUnwrapped, getVertexBufferObjectManagerMethod);

	JNI_ENV()->DeleteLocalRef(clazz);

	return result;
}

jobject EngineProxy::getTextureManager() {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/engine/Engine");

	jmethodID getTextureManagerMethod = JNI_ENV()->GetMethodID(clazz, "getTextureManager", "()Lorg/andengine/opengl/texture/TextureManager;");
	
	jobject result = JNI_ENV()->CallObjectMethod(this->mUnwrapped, getTextureManagerMethod);

	JNI_ENV()->DeleteLocalRef(clazz);

	return result;
}

jobject EngineProxy::getFontManager() {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/engine/Engine");

	jmethodID getFontManagerMethod = JNI_ENV()->GetMethodID(clazz, "getFontManager", "()Lorg/andengine/opengl/font/FontManager;");
	
	jobject result = JNI_ENV()->CallObjectMethod(this->mUnwrapped, getFontManagerMethod);
	
	JNI_ENV()->DeleteLocalRef(clazz);

	return result;
}
