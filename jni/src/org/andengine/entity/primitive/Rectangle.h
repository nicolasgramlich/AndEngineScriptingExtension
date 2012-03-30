#ifndef Rectangle_H
#define Rectangle_H

#include <jni.h>
#include "src/AndEngineScriptingExtension.h"
#include "src/org/andengine/entity/shape/Shape.h"
#include "src/org/andengine/opengl/vbo/VertexBufferObjectManager.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.entity.primtive.RectangleProxy
	// ===========================================================
	
	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_primitive_RectangleProxy_nativeInitClass(JNIEnv*, jclass);
	
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_primitive_RectangleProxy_nativeOnAttached(JNIEnv*, jobject, jlong);
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_primitive_RectangleProxy_nativeOnDetached(JNIEnv*, jobject, jlong);
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_primitive_RectangleProxy_nativeOnAreaTouched(JNIEnv*, jobject, jlong, jobject, jfloat, jfloat);
}

class Rectangle : public Shape {
	protected:
		/* Constructors */
 		Rectangle();
	public:
		/* Constructors */ 
		Rectangle(float, float, float, float, VertexBufferObjectManager*);
};

#endif
