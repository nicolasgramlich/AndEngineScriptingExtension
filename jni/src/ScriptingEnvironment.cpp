#include "ScriptingEnvironment.h"
// #include <JavaScriptCore/JavaScriptCore.h>

// ===========================================================
// org.andengine.extension.scripting.ScriptingEnvironment
// ===========================================================

static jobject sContext;
static JavaVM* sJavaVM;
static JNIEnv* sJNIEnv;
static EngineProxy* sEngine;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* pJavaVM, void* pReserved) {
	sJavaVM = pJavaVM;
 
	return JNI_VERSION_1_4;
}

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeInit(JNIEnv* pJNIEnv, jclass pJClass, jobject pContext, jstring pAPKPath, jobject pEngine) {
	sContext = pContext;
	sJNIEnv = pJNIEnv;

	setAPKPath(pJNIEnv, pJClass, pAPKPath);

	sEngine = new EngineProxy(pEngine);
}

JNIEnv* JNI_ENV() {
	return sJNIEnv;
}

EngineProxy* getEngine() {
	return sEngine;
}

void setAPKPath(JNIEnv* pJNIEnv, jclass pJClass, jstring pAPKPath) {
//	const char* str;
//	jboolean isCopy;
//	str = env->GetStringUTFChars(pAPKPath, &isCopy);
//	if (isCopy) {
//		setResourcePath(str);
//		env->ReleaseStringUTFChars(pAPKPath, str);
//	}
}
