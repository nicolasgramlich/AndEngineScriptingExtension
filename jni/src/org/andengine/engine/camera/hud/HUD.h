#ifndef HUD_H
#define HUD_H

#include <memory>
#include <jni.h>
#include "src/AndEngineScriptingExtension.h"
#include "src/org/andengine/entity/scene/CameraScene.h"
#include "src/org/andengine/entity/IEntity.h"
#include "src/org/andengine/entity/IEntity.h"
#include "src/org/andengine/entity/IEntityMatcher.h"
#include "src/org/andengine/entity/IEntity.h"
#include "src/org/andengine/entity/IEntity.h"

extern "C" {
	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_engine_camera_hud_HUDProxy_nativeInitClass(JNIEnv*, jclass);
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_engine_camera_hud_HUDProxy_nativeOnAttached(JNIEnv*, jobject, jlong);
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_engine_camera_hud_HUDProxy_nativeOnDetached(JNIEnv*, jobject, jlong);
}

class HUD : public CameraScene {

	public:
		HUD(jobject);
		virtual jobject unwrap();
		HUD();
		virtual jfloat getY();
		virtual jfloat getX();
		virtual jfloat getRotation();
		virtual void setRotation(jfloat);
		virtual void attachChild(IEntity*);
		virtual jboolean attachChild(IEntity*, jint);
		virtual void setX(jfloat);
		virtual void setY(jfloat);
		virtual jfloat getScaleX();
		virtual jfloat getScaleY();
		virtual void setScale(jfloat);
		virtual void setScale(jfloat, jfloat);
		virtual jfloat getSkewX();
		virtual jfloat getSkewY();
		virtual void setSkew(jfloat, jfloat);
		virtual void setSkew(jfloat);
		virtual IEntity* detachChild(IEntityMatcher*);
		virtual jboolean detachChild(IEntity*);
		virtual jboolean onAttached();
		virtual jboolean onDetached();

	protected:

	private:

};
#endif

