#include "EngineProxy.h"
#include "ScriptingEnvironment.h"

static jclass sEngineProxyClass;

static jmethodID sConstructor;
static jmethodID sGetVertexBufferObjectManagerMethod;
static jmethodID sGetTextureManagerMethod;
static jmethodID sGetFontManagerMethod;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_engine_EngineProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sEngineProxyClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);

	sConstructor = JNI_ENV()->GetMethodID(sEngineProxyClass, "<init>", "(JLorg/andengine/engine/options/EngineOptions;)V");
	sGetVertexBufferObjectManagerMethod = JNI_ENV()->GetMethodID(sEngineProxyClass, "getVertexBufferObjectManager", "()Lorg/andengine/opengl/vbo/VertexBufferObjectManager;");
	sGetTextureManagerMethod = JNI_ENV()->GetMethodID(sEngineProxyClass, "getTextureManager", "()Lorg/andengine/opengl/texture/TextureManager;");
	sGetFontManagerMethod = JNI_ENV()->GetMethodID(sEngineProxyClass, "getFontManager", "()Lorg/andengine/opengl/font/FontManager;");
}

// ===========================================================
// org.andengine.extension.scripting.entity.primitive.RectangleProxy
// ===========================================================

EngineProxy::EngineProxy(jobject pEngineOptions) {
	this->mUnwrapped = JNI_ENV()->NewObject(sEngineProxyClass, sConstructor, (jlong)this, pEngineOptions);
}

jobject EngineProxy::getVertexBufferObjectManager() {
	return JNI_ENV()->CallObjectMethod(this->mUnwrapped, sGetVertexBufferObjectManagerMethod);
}

jobject EngineProxy::getTextureManager() {
	return JNI_ENV()->CallObjectMethod(this->mUnwrapped, sGetTextureManagerMethod);
}

jobject EngineProxy::getFontManager() {
	return JNI_ENV()->CallObjectMethod(this->mUnwrapped, sGetFontManagerMethod);
}
