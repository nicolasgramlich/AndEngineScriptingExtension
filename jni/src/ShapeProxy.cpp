#include "ShapeProxy.h"

// ===========================================================
// org.andengine.extension.scripting.entity.EntityProxy
// ===========================================================

ShapeProxy::ShapeProxy() {
	/* Intentionally empty. */
}

bool ShapeProxy::onAreaTouched(jobject pSceneTouchEvent, jfloat pTouchAreaLocalX, jfloat pTouchAreaLocalY) {
	this->setScale(2);

	return true;
}
