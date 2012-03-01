#include "C_Rectangle.h"

C_Rectangle::C_Rectangle () {
	/* Intentionally empty. */
}

C_Rectangle::C_Rectangle(float pX, float pY, float pWidth, float pHeight, jobject pVertexBufferObjectManager) {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/entity/primitive/Rectangle");

	jmethodID constructor = JNI_ENV()->GetMethodID(clazz, "<init>", "(FFFFLorg/andengine/opengl/vbo/VertexBufferObjectManager;)V");

	this->mUnwrapped = JNI_ENV()->NewObject(clazz, constructor, pX, pY, pWidth, pHeight, pVertexBufferObjectManager);
}
