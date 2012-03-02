#ifndef RectangleProxy_H
#define RectangleProxy_H

#include <jni.h>
#include "ScriptingEnvironment.h"
#include "ShapeProxy.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.entity.primtive.RectangleProxy
	// ===========================================================
	
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_primitive_RectangleProxy_nativeOnAttached(JNIEnv*, jobject, jlong);
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_primitive_RectangleProxy_nativeOnDetached(JNIEnv*, jobject, jlong);
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_primitive_RectangleProxy_nativeOnAreaTouched(JNIEnv*, jobject, jlong, jobject, jfloat, jfloat);
}

class RectangleProxy : public ShapeProxy {
	protected:
		/* Constructors */
 		RectangleProxy();
	public:
		/* Constructors */ 
		RectangleProxy(float, float, float, float, jobject);
};

#endif
