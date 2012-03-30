#ifndef Sprite_H
#define Sprite_H

#include <jni.h>
#include "src/AndEngineScriptingExtension.h"
#include "src/org/andengine/entity/shape/Shape.h"
#include "src/org/andengine/opengl/texture/region/TextureRegion.h"
#include "src/org/andengine/opengl/vbo/VertexBufferObjectManager.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.entity.sprite.SpriteProxy
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeInitClass(JNIEnv*, jclass);

	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeOnAttached(JNIEnv*, jobject, jlong);
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeOnDetached(JNIEnv*, jobject, jlong);
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_sprite_SpriteProxy_nativeOnAreaTouched(JNIEnv*, jobject, jlong, jobject, jfloat, jfloat);
}

class Sprite : public Shape {
	protected:
		/* Constructors */
 		Sprite();
	public:
		/* Constructors */ 
		Sprite(float, float, float, float, TextureRegion*, VertexBufferObjectManager*);
};

#endif
