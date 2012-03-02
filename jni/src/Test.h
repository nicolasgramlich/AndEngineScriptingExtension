#include <jni.h>
#include "ScriptingEnvironment.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.Test
	// ===========================================================
	
	JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_Test_test(JNIEnv*, jclass, jobject);
}
