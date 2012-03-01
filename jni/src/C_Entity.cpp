#include "C_Entity.h"

C_Entity::C_Entity () {
	/* Intentionally empty. */
}

C_Entity::C_Entity (float pX, float pY) {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/entity/Entity");

	jmethodID constructor = JNI_ENV()->GetMethodID(clazz, "<init>", "(FF)V");

	this->mUnwrapped = JNI_ENV()->NewObject(clazz, constructor, pX, pY);
}

void C_Entity::setRotation(float pRotation) {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/entity/Entity");

	jmethodID setRotationMethod = JNI_ENV()->GetMethodID(clazz, "setRotation", "(F)V");

	JNI_ENV()->CallVoidMethod(this->mUnwrapped, setRotationMethod, pRotation);
}

void C_Entity::setScale(float pScale) {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/entity/Entity");

	jmethodID setScaleMethod = JNI_ENV()->GetMethodID(clazz, "setScale", "(F)V");

	JNI_ENV()->CallVoidMethod(this->mUnwrapped, setScaleMethod, pScale);
}
