#include <cstdlib>
#include "src/org/andengine/entity/primitive/Rectangle.h"

static jclass sRectangleClass;

static jmethodID sConstructor;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_primitive_RectangleProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sRectangleClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);

	sConstructor = JNI_ENV()->GetMethodID(sRectangleClass, "<init>", "(JFFFFLorg/andengine/opengl/vbo/VertexBufferObjectManager;)V");
}

// ===========================================================
// org.andengine.extension.scripting.entity.primitive.RectangleProxy
// ===========================================================

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_primitive_RectangleProxy_nativeOnAttached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	Rectangle* rectangle = (Rectangle*)pAddress;

	return rectangle->onAttached();
}

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_primitive_RectangleProxy_nativeOnDetached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	Rectangle* rectangle = (Rectangle*)pAddress;

	return rectangle->onDetached();
}

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_primitive_RectangleProxy_nativeOnAreaTouched(JNIEnv*, jobject pJObject, jlong pAddress, jobject pSceneTouchEvent, jfloat pTouchAreaLocalX, jfloat pTouchAreaLocalY) {
	Rectangle* rectangle = (Rectangle*)pAddress;

	return rectangle->onAreaTouched(pSceneTouchEvent, pTouchAreaLocalX, pTouchAreaLocalY);
}


Rectangle::Rectangle() {
	/* Intentionally empty. */
}

Rectangle::Rectangle(float pX, float pY, float pWidth, float pHeight, VertexBufferObjectManager* pVertexBufferObjectManager) {
	this->mUnwrapped = JNI_ENV()->NewObject(sRectangleClass, sConstructor, (jlong)this, pX, pY, pWidth, pHeight, pVertexBufferObjectManager->unwrap());
}
