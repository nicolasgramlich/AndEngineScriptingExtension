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
 
//	JNIEnv* env;
//	vm->GetEnv((void**)&env, JNI_VERSION_1_4);

	// Register methods for org.cocos2dx.hellojs.HelloJS
//	jclass hellojs_class = env->FindClass("org/cocos2dx/hellojs/HelloJS");
//	env->RegisterNatives(hellojs_class, hellojs_methods, sizeof(hellojs_methods)/sizeof(hellojs_methods[0]));

	return JNI_VERSION_1_4;
}

JNIEXPORT jstring JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_getJavaScriptVMVersion(JNIEnv* pJNIEnv, jclass pJClass) {
	const char* version = JS_GetImplementationVersion();
	return pJNIEnv->NewStringUTF(version);
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
	// TODO
}

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeDetachCurrentThread(JNIEnv* pJNIEnv, jclass pJClass) {
	// TODO
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
//	const char* apkPath;
//	jboolean isCopy;
//	apkPath = env->GetStringUTFChars(pAPKPath, &isCopy);
//	if(isCopy) {
//		setResourcePath(apkPath);
//		env->ReleaseStringUTFChars(pAPKPath, apkPath);
//	}
}
