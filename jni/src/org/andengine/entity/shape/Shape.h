#ifndef Shape_H
#define Shape_H

#include <jni.h>
#include "src/ScriptingEnvironment.h"
#include "src/org/andengine/entity/Entity.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.entity.shape.ShapeProxy
	// ===========================================================
	
	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_shape_ShapeProxy_nativeInitClass(JNIEnv*, jclass);
}

class Shape : public Entity {
	protected:
		/* Constructors */ 
		Shape();

	public:
		/* Callbacks. */
		bool onAreaTouched(jobject pSceneTouchEvent, jfloat pTouchAreaLocalX, jfloat pTouchAreaLocalY);
};

#endif
