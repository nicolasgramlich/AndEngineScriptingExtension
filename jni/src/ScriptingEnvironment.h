#ifndef ScriptingEnvironment_H
#define ScriptingEnvironment_H

#include <jni.h>
#include "src/Context.h"
#include "src/org/andengine/engine/Engine.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.ScriptingEnvironment
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeInitClass(JNIEnv*, jclass);
	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeInit(JNIEnv*, jclass, jobject, jstring);

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeAttachCurrentThread(JNIEnv*, jclass);
	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeDetachCurrentThread(JNIEnv*, jclass);

//	JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeOnCreateEngineOptions(JNIEnv*, jclass);
	JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeOnCreateEngine(JNIEnv*, jclass, jobject);
}

Context* getContext();
JNIEnv* JNI_ENV();
Engine* getEngine();

void setAPKPath(JNIEnv*, jclass, jstring);

#endif
