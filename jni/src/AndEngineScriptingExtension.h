#ifndef AndEngineScriptingExtension_H
#define AndEngineScriptingExtension_H

#include <jni.h>
#include <jsapi.h>
#include "src/Util.h"
#include "src/ScriptingCore.h"
#include "src/Context.h"
#include "src/org/andengine/engine/Engine.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.AndEngineScriptingExtension
	// ===========================================================

	JNIEXPORT jstring JNICALL Java_org_andengine_extension_scripting_AndEngineScriptingExtension_getJavaScriptVMVersion(JNIEnv*, jclass);
	JNIEXPORT jint JNICALL Java_org_andengine_extension_scripting_AndEngineScriptingExtension_runScript(JNIEnv*, jclass, jstring);

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_AndEngineScriptingExtension_nativeInitClass(JNIEnv*, jclass);
	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_AndEngineScriptingExtension_nativeInit(JNIEnv*, jclass, jobject, jobject);

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_AndEngineScriptingExtension_nativeAttachCurrentThread(JNIEnv*, jclass);
	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_AndEngineScriptingExtension_nativeDetachCurrentThread(JNIEnv*, jclass);
}

Context* getContext();
JNIEnv* JNI_ENV();
Engine* getEngine();

#endif
