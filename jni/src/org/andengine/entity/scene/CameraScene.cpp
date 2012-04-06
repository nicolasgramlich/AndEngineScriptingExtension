#include <cstdlib>
#include "src/org/andengine/entity/scene/CameraScene.h"

static jclass sCameraSceneClass;
static jmethodID sConstructor____org_andengine_engine_camera_Camera__;
static jmethodID sConstructor;
static jmethodID sMethod__GetY;
static jmethodID sMethod__GetX;
static jmethodID sMethod__GetRotation;
static jmethodID sMethod__SetRotation__F;
static jmethodID sMethod__AttachChild____org_andengine_entity_IEntity__;
static jmethodID sMethod__AttachChild____org_andengine_entity_IEntity__I;
static jmethodID sMethod__SetX__F;
static jmethodID sMethod__SetY__F;
static jmethodID sMethod__GetScaleX;
static jmethodID sMethod__GetScaleY;
static jmethodID sMethod__SetScale__F;
static jmethodID sMethod__SetScale__FF;
static jmethodID sMethod__GetSkewX;
static jmethodID sMethod__GetSkewY;
static jmethodID sMethod__SetSkew__FF;
static jmethodID sMethod__SetSkew__F;
static jmethodID sMethod__DetachChild____org_andengine_entity_IEntityMatcher__;
static jmethodID sMethod__DetachChild____org_andengine_entity_IEntity__;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_scene_CameraSceneProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sCameraSceneClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);
	sConstructor____org_andengine_engine_camera_Camera__ = JNI_ENV()->GetMethodID(sCameraSceneClass, "<init>", "(JLorg/andengine/engine/camera/Camera;)V");
	sConstructor = JNI_ENV()->GetMethodID(sCameraSceneClass, "<init>", "(J)V");
	sMethod__GetY = JNI_ENV()->GetMethodID(sCameraSceneClass, "getY", "()F");
	sMethod__GetX = JNI_ENV()->GetMethodID(sCameraSceneClass, "getX", "()F");
	sMethod__GetRotation = JNI_ENV()->GetMethodID(sCameraSceneClass, "getRotation", "()F");
	sMethod__SetRotation__F = JNI_ENV()->GetMethodID(sCameraSceneClass, "setRotation", "(F)V");
	sMethod__AttachChild____org_andengine_entity_IEntity__ = JNI_ENV()->GetMethodID(sCameraSceneClass, "attachChild", "(Lorg/andengine/entity/IEntity;)V");
	sMethod__AttachChild____org_andengine_entity_IEntity__I = JNI_ENV()->GetMethodID(sCameraSceneClass, "attachChild", "(Lorg/andengine/entity/IEntity;I)Z");
	sMethod__SetX__F = JNI_ENV()->GetMethodID(sCameraSceneClass, "setX", "(F)V");
	sMethod__SetY__F = JNI_ENV()->GetMethodID(sCameraSceneClass, "setY", "(F)V");
	sMethod__GetScaleX = JNI_ENV()->GetMethodID(sCameraSceneClass, "getScaleX", "()F");
	sMethod__GetScaleY = JNI_ENV()->GetMethodID(sCameraSceneClass, "getScaleY", "()F");
	sMethod__SetScale__F = JNI_ENV()->GetMethodID(sCameraSceneClass, "setScale", "(F)V");
	sMethod__SetScale__FF = JNI_ENV()->GetMethodID(sCameraSceneClass, "setScale", "(FF)V");
	sMethod__GetSkewX = JNI_ENV()->GetMethodID(sCameraSceneClass, "getSkewX", "()F");
	sMethod__GetSkewY = JNI_ENV()->GetMethodID(sCameraSceneClass, "getSkewY", "()F");
	sMethod__SetSkew__FF = JNI_ENV()->GetMethodID(sCameraSceneClass, "setSkew", "(FF)V");
	sMethod__SetSkew__F = JNI_ENV()->GetMethodID(sCameraSceneClass, "setSkew", "(F)V");
	sMethod__DetachChild____org_andengine_entity_IEntityMatcher__ = JNI_ENV()->GetMethodID(sCameraSceneClass, "detachChild", "(Lorg/andengine/entity/IEntityMatcher;)Lorg/andengine/entity/IEntity;");
	sMethod__DetachChild____org_andengine_entity_IEntity__ = JNI_ENV()->GetMethodID(sCameraSceneClass, "detachChild", "(Lorg/andengine/entity/IEntity;)Z");
}

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_scene_CameraSceneProxy_nativeOnAttached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	CameraScene* cameraScene = (CameraScene*)pAddress;
	return cameraScene->onAttached();
}
JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_scene_CameraSceneProxy_nativeOnDetached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	CameraScene* cameraScene = (CameraScene*)pAddress;
	return cameraScene->onDetached();
}

CameraScene::CameraScene(jobject pCameraSceneProxy) {
	this->mUnwrapped = pCameraSceneProxy;
}
jobject CameraScene::unwrap() {
	return this->mUnwrapped;
}
CameraScene::CameraScene(Camera* pCamera) {
	this->mUnwrapped = JNI_ENV()->NewObject(sCameraSceneClass, sConstructor____org_andengine_engine_camera_Camera__, (jlong)this, pCamera->unwrap());
}
CameraScene::CameraScene() {
	this->mUnwrapped = JNI_ENV()->NewObject(sCameraSceneClass, sConstructor, (jlong)this);
}
jfloat CameraScene::getY() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sMethod__GetY);
}
jfloat CameraScene::getX() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sMethod__GetX);
}
jfloat CameraScene::getRotation() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sMethod__GetRotation);
}
void CameraScene::setRotation(jfloat pRotation) {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sMethod__SetRotation__F, pRotation);
}
void CameraScene::attachChild(IEntity* pEntity) {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sMethod__AttachChild____org_andengine_entity_IEntity__, pEntity->unwrap());
}
jboolean CameraScene::attachChild(IEntity* pEntity, jint pIndex) {
	return JNI_ENV()->CallBooleanMethod(this->mUnwrapped, sMethod__AttachChild____org_andengine_entity_IEntity__I, pEntity->unwrap(), pIndex);
}
void CameraScene::setX(jfloat pX) {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sMethod__SetX__F, pX);
}
void CameraScene::setY(jfloat pY) {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sMethod__SetY__F, pY);
}
jfloat CameraScene::getScaleX() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sMethod__GetScaleX);
}
jfloat CameraScene::getScaleY() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sMethod__GetScaleY);
}
void CameraScene::setScale(jfloat pScale) {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sMethod__SetScale__F, pScale);
}
void CameraScene::setScale(jfloat pScaleX, jfloat pScaleY) {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sMethod__SetScale__FF, pScaleX, pScaleY);
}
jfloat CameraScene::getSkewX() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sMethod__GetSkewX);
}
jfloat CameraScene::getSkewY() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sMethod__GetSkewY);
}
void CameraScene::setSkew(jfloat pSkewX, jfloat pSkewY) {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sMethod__SetSkew__FF, pSkewX, pSkewY);
}
void CameraScene::setSkew(jfloat pSkew) {
	JNI_ENV()->CallVoidMethod(this->mUnwrapped, sMethod__SetSkew__F, pSkew);
}
IEntity* CameraScene::detachChild(IEntityMatcher* pEntityMatcher) {
	return new Entity(JNI_ENV()->CallObjectMethod(this->mUnwrapped, sMethod__DetachChild____org_andengine_entity_IEntityMatcher__, pEntityMatcher->unwrap()));
}
jboolean CameraScene::detachChild(IEntity* pEntity) {
	return JNI_ENV()->CallBooleanMethod(this->mUnwrapped, sMethod__DetachChild____org_andengine_entity_IEntity__, pEntity->unwrap());
}
jboolean CameraScene::onAttached() {
	return false;
}
jboolean CameraScene::onDetached() {
	return false;
}

