#include "SpriteProxy.h"

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
	jclass clazz = JNI_ENV()->FindClass("org/andengine/extension/scripting/entity/sprite/SpriteProxy");

	jmethodID constructor = JNI_ENV()->GetMethodID(clazz, "<init>", "(JFFFFLorg/andengine/opengl/texture/region/ITextureRegion;Lorg/andengine/opengl/vbo/VertexBufferObjectManager;)V");

	this->mUnwrapped = JNI_ENV()->NewObject(clazz, constructor, (jlong)this, pX, pY, pWidth, pHeight, pTextureRegion, pVertexBufferObjectManager);
}
