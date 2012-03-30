#ifndef Scene_H
#define Scene_H

#include <jni.h>
#include "src/AndEngineScriptingExtension.h"
#include "src/org/andengine/entity/shape/Shape.h"
#include "src/org/andengine/opengl/texture/region/TextureRegion.h"
#include "src/org/andengine/opengl/vbo/VertexBufferObjectManager.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.entity.scene.SceneProxy
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_scene_SceneProxy_nativeInitClass(JNIEnv*, jclass);

	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_scene_SceneProxy_nativeOnAttached(JNIEnv*, jobject, jlong);
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_scene_SceneProxy_nativeOnDetached(JNIEnv*, jobject, jlong);
}

class Scene : public Entity {
	public:
		/* Constructors */
 		Scene();
};

#endif
