#ifndef EngineProxy_H
#define EngineProxy_H

#include <jni.h>
#include "Wrapper.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.ScriptingEnvironment
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_engine_EngineProxy_nativeInitClass(JNIEnv*, jclass);
}

class EngineProxy : public Wrapper {
	public:
		/* Constructors */
		EngineProxy(jobject);

		/* Getter & Setter */
		jobject getVertexBufferObjectManager();
		jobject getTextureManager();
		jobject getFontManager();
};

#endif
