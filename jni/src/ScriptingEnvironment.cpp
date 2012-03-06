#include "ScriptingEnvironment.h"
// #include <JavaScriptCore/JavaScriptCore.h>

// ===========================================================
// org.andengine.extension.scripting.ScriptingEnvironment
// ===========================================================

static jobject sContext;
static JavaVM* sJavaVM;
static JNIEnv* sJNIEnv;
static EngineProxy* sEngineProxy;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* pJavaVM, void* pReserved) {
	sJavaVM = pJavaVM;
 
	return JNI_VERSION_1_4;
}

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {

}

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeInit(JNIEnv* pJNIEnv, jclass pJClass, jobject pContext, jstring pAPKPath) {
	sContext = pContext;
	sJNIEnv = pJNIEnv;

	setAPKPath(pJNIEnv, pJClass, pAPKPath);
}

//JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeOnCreateEngineOPtions(JNIEnv* pJNIEnv, jclass pJClass) {
//	
//}

JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeOnCreateEngine(JNIEnv* pJNIEnv, jclass pJClass, jobject pEngineOptions) {
	sEngineProxy = new EngineProxy(pEngineOptions);

	return sEngineProxy->unwrap();
}

JNIEnv* JNI_ENV() {
	return sJNIEnv;
}

EngineProxy* getEngineProxy() {
	return sEngineProxy;
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
