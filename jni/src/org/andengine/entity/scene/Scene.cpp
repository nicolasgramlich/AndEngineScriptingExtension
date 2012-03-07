#include <cstdlib>
#include "src/org/andengine/entity/scene/Scene.h"

static jclass sSceneClass;

static jmethodID sConstructor;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_scene_SceneProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sSceneClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);

	sConstructor = JNI_ENV()->GetMethodID(sSceneClass, "<init>", "(J)V");
}

// ===========================================================
// org.andengine.extension.scripting.entity.scene.SceneProxy
// ===========================================================

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_scene_SceneProxy_nativeOnAttached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	Scene* scene = (Scene*)pAddress;

	return scene->onAttached();
}

JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_scene_SceneProxy_nativeOnDetached(JNIEnv* pJNIEnv, jobject pJObject, jlong pAddress) {
	Scene* scene = (Scene*)pAddress;

	return scene->onDetached();
}


Scene::Scene() {
	this->mUnwrapped = JNI_ENV()->NewObject(sSceneClass, sConstructor, (jlong)this);
}
