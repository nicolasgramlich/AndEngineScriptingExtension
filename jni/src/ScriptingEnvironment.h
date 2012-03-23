#ifndef ScriptingEnvironment_H
#define ScriptingEnvironment_H

#include <jni.h>
#include <jsapi.h>
#include "src/Util.h"
#include "src/Context.h"
#include "src/org/andengine/engine/Engine.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.ScriptingEnvironment
	// ===========================================================

	JNIEXPORT jstring JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_getJavaScriptVMVersion(JNIEnv*, jclass);

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeInitClass(JNIEnv*, jclass);
	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeInit(JNIEnv*, jclass, jobject, jstring, jobject);

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeAttachCurrentThread(JNIEnv*, jclass);
	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeDetachCurrentThread(JNIEnv*, jclass);
}

Context* getContext();
JNIEnv* JNI_ENV();
Engine* getEngine();

void setAPKPath(JNIEnv*, jclass, jstring);

#endif
