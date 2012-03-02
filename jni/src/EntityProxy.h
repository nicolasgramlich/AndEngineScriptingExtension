#ifndef EntityProxy_H
#define EntityProxy_H

#include <jni.h>
#include "ScriptingEnvironment.h"
#include "Wrapper.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.entity.EntityProxy
	// ===========================================================
	
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
		void setRotation(float);
		void setScale(float);

		/* Callbacks. */
		bool onAttached();
		bool onDetached();
};

#endif
