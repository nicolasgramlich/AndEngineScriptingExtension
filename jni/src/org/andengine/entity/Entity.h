#ifndef Entity_H
#define Entity_H

#include <jni.h>
#include "src/AndEngineScriptingExtension.h"
#include "src/Wrapper.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.entity.EntityProxy
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_EntityProxy_nativeInitClass(JNIEnv*, jclass);
	
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_EntityProxy_nativeOnAttached(JNIEnv*, jobject, jlong);
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_EntityProxy_nativeOnDetached(JNIEnv*, jobject, jlong);
}

class Entity : public Wrapper {
	protected:
		/* Constructors */ 
		Entity();

	public:
		/* Constructors. */ 
		Entity(float, float);

		/* Getter & Setter. */
		virtual float getX();
		virtual float getY();
		virtual void setX(float);
		virtual void setY(float);
		virtual float getRotation();
		virtual void setRotation(float);
		virtual float getScaleX();
		virtual float getScaleY();
		virtual void setScale(float);

		/* Callbacks. */
		virtual bool onAttached();
		virtual bool onDetached();
};

#endif
