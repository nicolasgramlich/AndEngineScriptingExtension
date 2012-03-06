#include "ScriptingEnvironment.h"
#include "Test.h"
#include "RectangleProxy.h"
#include "SpriteProxy.h"
#include "Util.h"

// ===========================================================
// org.andengine.extension.scripting.Test
// ===========================================================

JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_Test_test(JNIEnv* pJNIEnv, jclass pJClass, jobject pTextureRegion) {
	int size = 100;

	EntityProxy* entity = new SpriteProxy(360 - (size / 2), 240 - (size / 2), size, size, pTextureRegion, getEngineProxy()->getVertexBufferObjectManager());

	entity->setRotation(45);

	return entity->unwrap();
}
