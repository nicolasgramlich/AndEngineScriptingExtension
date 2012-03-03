#ifndef EntityProxy_H
#define EntityProxy_H

#include <jni.h>
#include "ScriptingEnvironment.h"
#include "Wrapper.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.entity.EntityProxy
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_entity_EntityProxy_nativeInitClass(JNIEnv*, jclass);
	
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_EntityProxy_nativeOnAttached(JNIEnv*, jobject, jlong);
	JNIEXPORT jboolean JNICALL Java_org_andengine_extension_scripting_entity_EntityProxy_nativeOnDetached(JNIEnv*, jobject, jlong);
}

class EntityProxy : public Wrapper {
	protected:
		/* Constructors */ 
		EntityProxy();

	public:
		/* Constructors. */ 
		EntityProxy(float, float);

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
