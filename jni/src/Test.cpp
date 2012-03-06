#include "src/ScriptingEnvironment.h"
#include "src/Test.h"
#include "src/Util.h"
#include "src/org/andengine/entity/primitive/Rectangle.h"
#include "src/org/andengine/entity/sprite/Sprite.h"

// ===========================================================
// org.andengine.extension.scripting.Test
// ===========================================================

JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_Test_test(JNIEnv* pJNIEnv, jclass pJClass, jobject pTextureRegion) {
	int size = 100;

	Entity* entity = new Sprite(360 - (size / 2), 240 - (size / 2), size, size, pTextureRegion, getEngine()->getVertexBufferObjectManager());

	entity->setRotation(45);

	return entity->unwrap();
}
