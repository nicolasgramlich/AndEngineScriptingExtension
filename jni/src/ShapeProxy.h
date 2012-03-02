#ifndef ShapeProxy_H
#define ShapeProxy_H

#include <jni.h>
#include "ScriptingEnvironment.h"
#include "EntityProxy.h"

class ShapeProxy : public EntityProxy {
	protected:
		/* Constructors */ 
		ShapeProxy();

	public:
		/* Callbacks. */
		bool onAreaTouched(jobject pSceneTouchEvent, jfloat pTouchAreaLocalX, jfloat pTouchAreaLocalY);
};

#endif
