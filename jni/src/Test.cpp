#include "ScriptingEnvironment.h"
#include "Test.h"
#include "C_Rectangle.h"

// ===========================================================
// org.andengine.extension.scripting.Test
// ===========================================================

JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_Test_test(JNIEnv* pJNIEnv, jclass pJClass) {
	C_Rectangle* rect = new C_Rectangle(10, 10, 100, 100, getEngine()->getVertexBufferObjectManager());

	rect->setRotation(45);

    return rect->unwrap();
}
