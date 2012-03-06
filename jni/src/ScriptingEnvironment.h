#ifndef ScriptingEnvironment_H
#define ScriptingEnvironment_H

#include <jni.h>
#include "EngineProxy.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.ScriptingEnvironment
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeInitClass(JNIEnv*, jclass);
	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeInit(JNIEnv*, jclass, jobject, jstring);
	// JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeOnCreateEngineOptions(JNIEnv*, jclass);
	JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeOnCreateEngine(JNIEnv*, jclass, jobject);
}

JNIEnv* JNI_ENV();
EngineProxy* getEngineProxy();

void setAPKPath(JNIEnv*, jclass, jstring);

#endif
