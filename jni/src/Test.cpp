#include "ScriptingEnvironment.h"
#include "Test.h"
#include "RectangleProxy.h"
#include "Util.h"

// ===========================================================
// org.andengine.extension.scripting.Test
// ===========================================================

JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_Test_mirror(JNIEnv* pJNIEnv, jclass pJClass, jobject pJObject) {
	return pJObject;
}

JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_Test_test(JNIEnv* pJNIEnv, jclass pJClass) {
	RectangleProxy* rect = new RectangleProxy(10, 10, 100, 100, getEngine()->getVertexBufferObjectManager());

	rect->setRotation(45);

    return rect->unwrap();
}
