#ifndef ScriptingEnvironment_H
#define ScriptingEnvironment_H

#include <jni.h>
#include "EngineProxy.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.ScriptingEnvironment
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeInit(JNIEnv*, jclass, jobject, jstring, jobject);
}

JNIEnv* JNI_ENV();
EngineProxy* getEngine();

void setAPKPath(JNIEnv*, jclass, jstring);

#endif
