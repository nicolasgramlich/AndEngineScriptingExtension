#include "src/Context.h"
#include "src/AndEngineScriptingExtension.h"

static jclass sContextClass;

static jmethodID sGetAssetsMethod;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ContextProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	jclass contextClass = JNI_ENV()->FindClass("android/content/Context");
	sContextClass = (jclass)JNI_ENV()->NewGlobalRef(contextClass);

	sGetAssetsMethod = JNI_ENV()->GetMethodID(sContextClass, "getAssets", "()Landroid/content/res/AssetManager;");
}

// ===========================================================
// org.andengine.extension.scripting.engine.ContextProxy
// ===========================================================

Context::Context(jobject pContext) {
	this->mUnwrapped = pContext;
}

jobject Context::getAssets() {
	return JNI_ENV()->CallObjectMethod(this->mUnwrapped, sGetAssetsMethod);
}
