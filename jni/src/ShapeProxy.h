#ifndef ShapeProxy_H
#define ShapeProxy_H

#include <jni.h>
#include "ScriptingEnvironment.h"
#include "EntityProxy.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.entity.shape.ShapeProxy
	// ===========================================================
	
	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_shape_ShapeProxy_nativeInitClass(JNIEnv*, jclass);
}

class ShapeProxy : public EntityProxy {
	protected:
		/* Constructors */ 
		ShapeProxy();

	public:
		/* Callbacks. */
		bool onAreaTouched(jobject pSceneTouchEvent, jfloat pTouchAreaLocalX, jfloat pTouchAreaLocalY);
};

#endif
