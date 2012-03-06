#ifndef Engine_H
#define Engine_H

#include <jni.h>
#include "src/Wrapper.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.engine.EngineProxy
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_engine_EngineProxy_nativeInitClass(JNIEnv*, jclass);
}

class Engine : public Wrapper {
	public:
		/* Constructors */
		Engine(jobject);

		/* Getter & Setter */
		jobject getVertexBufferObjectManager();
		jobject getTextureManager();
		jobject getFontManager();
};

#endif
