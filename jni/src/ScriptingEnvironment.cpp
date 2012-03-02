#include "ScriptingEnvironment.h"
// #include <JavaScriptCore/JavaScriptCore.h>

// ===========================================================
// org.andengine.extension.scripting.ScriptingEnvironment
// ===========================================================

JNIEnv* mJNIEnv;
EngineProxy* mEngine;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* pJavaVM, void* pReserved) {
	return JNI_VERSION_1_4;
}

JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_init(JNIEnv* pJNIEnv, jclass pJClass, jstring pAPKPath, jobject pEngine) {
	mJNIEnv = pJNIEnv;

	setAPKPath(pJNIEnv, pJClass, pAPKPath);

	mEngine = new EngineProxy(pEngine);
}

JNIEnv* JNI_ENV() {
	return mJNIEnv;
}

EngineProxy* getEngine() {
	return mEngine;
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
