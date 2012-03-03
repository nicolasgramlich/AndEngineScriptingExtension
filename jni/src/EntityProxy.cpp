#include <cstdlib>
#include "EntityProxy.h"

static jclass sEntityProxyClass;

static jmethodID sConstructor;
static jmethodID sGetRotationMethod;
static jmethodID sSetRotationMethod;
static jmethodID sGetScaleXMethod;
static jmethodID sGetScaleYMethod;
static jmethodID sSetScaleMethod;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_EntityProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sEntityProxyClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);

	sConstructor = JNI_ENV()->GetMethodID(sEntityProxyClass, "<init>", "(JFF)V");
	sGetRotationMethod = JNI_ENV()->GetMethodID(sEntityProxyClass, "getRotation", "()F");
	sSetRotationMethod = JNI_ENV()->GetMethodID(sEntityProxyClass, "setRotation", "(F)V");
	sGetScaleXMethod = JNI_ENV()->GetMethodID(sEntityProxyClass, "getScaleX", "()F");
	sGetScaleYMethod = JNI_ENV()->GetMethodID(sEntityProxyClass, "getScaleY", "()F");
	sSetScaleMethod = JNI_ENV()->GetMethodID(sEntityProxyClass, "setScale", "(F)V");
}

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
	this->mUnwrapped = JNI_ENV()->NewObject(sEntityProxyClass, sConstructor, (jlong)this, pX, pY);
}


float EntityProxy::getRotation() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sGetRotationMethod);
}

void EntityProxy::setRotation(float pRotation) {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sSetRotationMethod, pRotation);
}

void EntityProxy::setScale(float pScale) {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sSetScaleMethod, pScale);
}

float EntityProxy::getScaleX() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sGetScaleXMethod);
}

float EntityProxy::getScaleY() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sGetScaleYMethod);
}

bool EntityProxy::onAttached() {
	return false;
}

bool EntityProxy::onDetached() {
	return false;
}
