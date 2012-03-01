#ifndef ScriptingEnvironment_H
#define ScriptingEnvironment_H

#include <jni.h>
#include "C_Engine.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.ScriptingEnvironment
	// ===========================================================
	
	JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_init(JNIEnv*, jclass, jstring, jobject);
}

JNIEnv* JNI_ENV();
C_Engine* getEngine();

void setAPKPath(JNIEnv*, jclass, jstring);

#endif
