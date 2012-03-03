#include <cstdlib>
#include "ShapeProxy.h"

static jclass sShapeProxyClass;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_shape_ShapeProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sShapeProxyClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);
}

// ===========================================================
// org.andengine.extension.scripting.entity.EntityProxy
// ===========================================================

ShapeProxy::ShapeProxy() {
	/* Intentionally empty. */
}

bool ShapeProxy::onAreaTouched(jobject pSceneTouchEvent, jfloat pTouchAreaLocalX, jfloat pTouchAreaLocalY) {
	this->setRotation(this->getRotation() + 1);

	return true;
}
