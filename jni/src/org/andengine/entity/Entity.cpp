#include <cstdlib>
#include "src/org/andengine/entity/Entity.h"

static jclass sEntityClass;

static jmethodID sConstructor;
static jmethodID sGetXMethod;
static jmethodID sGetYMethod;
static jmethodID sSetXMethod;
static jmethodID sSetYMethod;
static jmethodID sGetRotationMethod;
static jmethodID sSetRotationMethod;
static jmethodID sGetScaleXMethod;
static jmethodID sGetScaleYMethod;
static jmethodID sSetScaleMethod;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_EntityProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sEntityClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);

	sConstructor = JNI_ENV()->GetMethodID(sEntityClass, "<init>", "(JFF)V");
	sGetXMethod = JNI_ENV()->GetMethodID(sEntityClass, "getX", "()F");
	sGetYMethod = JNI_ENV()->GetMethodID(sEntityClass, "getY", "()F");
	sSetXMethod = JNI_ENV()->GetMethodID(sEntityClass, "setX", "(F)V");
	sSetYMethod = JNI_ENV()->GetMethodID(sEntityClass, "setY", "(F)V");
	sGetRotationMethod = JNI_ENV()->GetMethodID(sEntityClass, "getRotation", "()F");
	sSetRotationMethod = JNI_ENV()->GetMethodID(sEntityClass, "setRotation", "(F)V");
	sGetScaleXMethod = JNI_ENV()->GetMethodID(sEntityClass, "getScaleX", "()F");
	sGetScaleYMethod = JNI_ENV()->GetMethodID(sEntityClass, "getScaleY", "()F");
	sSetScaleMethod = JNI_ENV()->GetMethodID(sEntityClass, "setScale", "(F)V");
}

// ===========================================================
// org.andengine.extension.scripting.entity.EntityProxy
// ===========================================================

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_Entity_nativeOnAttached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	Entity* entity = (Entity*)pAddress;

	return entity->onAttached();
}

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_Entity_nativeOnDetached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	Entity* entity = (Entity*)pAddress;

	return entity->onDetached();
}



Entity::Entity() {
	/* Intentionally empty. */
}

Entity::Entity(float pX, float pY) {
	this->mUnwrapped = JNI_ENV()->NewObject(sEntityClass, sConstructor, (jlong)this, pX, pY);
}


float Entity::getX() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sGetXMethod);
}

float Entity::getY() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sGetYMethod);
}

void Entity::setX(float pX) {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sSetXMethod, pX);
}

void Entity::setY(float pY) {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sSetYMethod, pY);
}

float Entity::getRotation() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sGetRotationMethod);
}

void Entity::setRotation(float pRotation) {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sSetRotationMethod, pRotation);
}

void Entity::setScale(float pScale) {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sSetScaleMethod, pScale);
}

float Entity::getScaleX() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sGetScaleXMethod);
}

float Entity::getScaleY() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sGetScaleYMethod);
}

bool Entity::onAttached() {
	return false;
}

bool Entity::onDetached() {
	return false;
}