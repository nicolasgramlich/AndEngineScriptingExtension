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
		float getRotation();
		void setRotation(float);
		float getScaleX();
		float getScaleY();
		void setScale(float);

		/* Callbacks. */
		bool onAttached();
		bool onDetached();
};

#endif
