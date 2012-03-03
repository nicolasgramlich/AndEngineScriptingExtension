#include <cstdlib>
#include "SpriteProxy.h"

static jclass sSpriteProxyClass;

static jmethodID sConstructor;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sSpriteProxyClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);
	
	sConstructor = JNI_ENV()->GetMethodID(sSpriteProxyClass, "<init>", "(JFFFFLorg/andengine/opengl/texture/region/ITextureRegion;Lorg/andengine/opengl/vbo/VertexBufferObjectManager;)V");
}

// ===========================================================
// org.andengine.extension.scripting.entity.sprite.SpriteProxy
// ===========================================================

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeOnAttached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	SpriteProxy* rectangle = (SpriteProxy*)pAddress;

	return rectangle->onAttached();
}

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeOnDetached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	SpriteProxy* rectangle = (SpriteProxy*)pAddress;

	return rectangle->onDetached();
}

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeOnAreaTouched(JNIEnv*, jobject pJObject, jlong pAddress, jobject pSceneTouchEvent, jfloat pTouchAreaLocalX, jfloat pTouchAreaLocalY) {
	SpriteProxy* rectangle = (SpriteProxy*)pAddress;

	return rectangle->onAreaTouched(pSceneTouchEvent, pTouchAreaLocalX, pTouchAreaLocalY);
}


SpriteProxy::SpriteProxy() {
	/* Intentionally empty. */
}

SpriteProxy::SpriteProxy(float pX, float pY, float pWidth, float pHeight, jobject pTextureRegion, jobject pVertexBufferObjectManager) {
	this->mUnwrapped = JNI_ENV()->NewObject(sSpriteProxyClass, sConstructor, (jlong)this, pX, pY, pWidth, pHeight, pTextureRegion, pVertexBufferObjectManager);
}
