#include "src/ScriptingEnvironment.h"
// #include <JavaScriptCore/JavaScriptCore.h>

// ===========================================================
// org.andengine.extension.scripting.ScriptingEnvironment
// ===========================================================

static Context* sContext;
static JavaVM* sJavaVM;
static JNIEnv* sJNIEnv;
static Engine* sEngine;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* pJavaVM, void* pReserved) {
	sJavaVM = pJavaVM;
 
	return JNI_VERSION_1_4;
}

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sJNIEnv = pJNIEnv;
}

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeInit(JNIEnv* pJNIEnv, jclass pJClass, jobject pContext, jstring pAPKPath, jobject pEngine) {
	sContext = new Context(pContext);
	setAPKPath(pJNIEnv, pJClass, pAPKPath);
	sEngine = new Engine(pEngine);
}

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeAttachCurrentThread(JNIEnv* pJNIEnv, jclass pJClass) {
	
}

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeDetachCurrentThread(JNIEnv* pJNIEnv, jclass pJClass) {
	
}

JavaVM* JAVA_VM() {
	return sJavaVM;
}

JNIEnv* JNI_ENV() {
	return sJNIEnv;
}

Engine* getEngine() {
	return sEngine;
}

Context* getContext() {
	return sContext;
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
