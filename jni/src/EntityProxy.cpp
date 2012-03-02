#include "EntityProxy.h"

// ===========================================================
// org.andengine.extension.scripting.entity.EntityProxy
// ===========================================================

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_EntityProxy_nativeOnAttached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	EntityProxy* entity = (EntityProxy*)pAddress;

	return entity->onAttached();
}

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_EntityProxy_nativeOnDetached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	EntityProxy* entity = (EntityProxy*)pAddress;

	return entity->onDetached();
}



EntityProxy::EntityProxy() {
	/* Intentionally empty. */
}

EntityProxy::EntityProxy(float pX, float pY) {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/extension/scripting/entity/EntityProxy");

	jmethodID constructor = JNI_ENV()->GetMethodID(clazz, "<init>", "(JFF)V");

	this->mUnwrapped = JNI_ENV()->NewObject(clazz, constructor, (jlong)this, pX, pY);
}

void EntityProxy::setRotation(float pRotation) {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/extension/scripting/entity/EntityProxy");

	jmethodID setRotationMethod = JNI_ENV()->GetMethodID(clazz, "setRotation", "(F)V");

	JNI_ENV()->CallVoidMethod(this->mUnwrapped, setRotationMethod, pRotation);
}

void EntityProxy::setScale(float pScale) {
	jclass clazz = JNI_ENV()->FindClass("org/andengine/extension/scripting/entity/EntityProxy");

	jmethodID setScaleMethod = JNI_ENV()->GetMethodID(clazz, "setScale", "(F)V");

	JNI_ENV()->CallVoidMethod(this->mUnwrapped, setScaleMethod, pScale);
}

bool EntityProxy::onAttached() {
	return false;
}

bool EntityProxy::onDetached() {
	return false;
}
