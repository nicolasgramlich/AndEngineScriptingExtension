#ifndef SpriteProxy_H
#define SpriteProxy_H

#include <jni.h>
#include "ScriptingEnvironment.h"
#include "ShapeProxy.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.entity.sprite.SpriteProxy
	// ===========================================================
	
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeOnAttached(JNIEnv*, jobject, jlong);
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeOnDetached(JNIEnv*, jobject, jlong);
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeOnAreaTouched(JNIEnv*, jobject, jlong, jobject, jfloat, jfloat);
}

class SpriteProxy : public ShapeProxy {
	protected:
		/* Constructors */
 		SpriteProxy();
	public:
		/* Constructors */ 
		SpriteProxy(float, float, float, float, jobject, jobject);
};

#endif
