#include <cstdlib>
#include "src/org/andengine/entity/shape/Shape.h"

static jclass sShapeClass;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_shape_ShapeProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sShapeClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);
}

// ===========================================================
// org.andengine.extension.scripting.entity.EntityProxy
// ===========================================================

Shape::Shape() {
	/* Intentionally empty. */
}

bool Shape::onAreaTouched(jobject pSceneTouchEvent, jfloat pTouchAreaLocalX, jfloat pTouchAreaLocalY) {
	this->setRotation(this->getRotation() + 1);

	return true;
}
