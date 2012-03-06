#include <cstdlib>
#include "src/org/andengine/entity/sprite/Sprite.h"

static jclass sSpriteClass;

static jmethodID sConstructor;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sSpriteClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);
	
	sConstructor = JNI_ENV()->GetMethodID(sSpriteClass, "<init>", "(JFFFFLorg/andengine/opengl/texture/region/ITextureRegion;Lorg/andengine/opengl/vbo/VertexBufferObjectManager;)V");
}

// ===========================================================
// org.andengine.extension.scripting.entity.sprite.SpriteProxy
// ===========================================================

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeOnAttached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	Sprite* rectangle = (Sprite*)pAddress;

	return rectangle->onAttached();
}

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeOnDetached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	Sprite* rectangle = (Sprite*)pAddress;

	return rectangle->onDetached();
}

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeOnAreaTouched(JNIEnv*, jobject pJObject, jlong pAddress, jobject pSceneTouchEvent, jfloat pTouchAreaLocalX, jfloat pTouchAreaLocalY) {
	Sprite* rectangle = (Sprite*)pAddress;

	return rectangle->onAreaTouched(pSceneTouchEvent, pTouchAreaLocalX, pTouchAreaLocalY);
}


Sprite::Sprite() {
	/* Intentionally empty. */
}

Sprite::Sprite(float pX, float pY, float pWidth, float pHeight, jobject pTextureRegion, jobject pVertexBufferObjectManager) {
	this->mUnwrapped = JNI_ENV()->NewObject(sSpriteClass, sConstructor, (jlong)this, pX, pY, pWidth, pHeight, pTextureRegion, pVertexBufferObjectManager);
}
