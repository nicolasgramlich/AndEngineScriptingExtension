#include "ScriptingEnvironment.h"
#include "Test.h"
#include "RectangleProxy.h"
#include <android/log.h>

#define  LOG_TAG    "AndEngine"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

// ===========================================================
// org.andengine.extension.scripting.Test
// ===========================================================

JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_Test_mirror(JNIEnv* pJNIEnv, jclass pJClass, jobject pJObject) {
	return pJObject;
}

JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_Test_test(JNIEnv* pJNIEnv, jclass pJClass) {
	LOGD("test(1)");

	jobject vertexBufferObjectManager = getEngine()->getVertexBufferObjectManager();
	
	// LOGD(getClassName(vertexBufferObjectManager));

	RectangleProxy* rect = new RectangleProxy(10, 10, 100, 100, vertexBufferObjectManager);

	LOGD("test(2)");

	rect->setRotation(45);

	LOGD("test(3)");

	jobject unwrapped = rect->unwrap();

	LOGD("test(4)");

    return unwrapped;
}
