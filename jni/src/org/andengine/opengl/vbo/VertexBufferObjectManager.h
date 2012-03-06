#ifndef VertexBufferObjectManager_H
#define VertexBufferObjectManager_H

#include <jni.h>
#include "src/Wrapper.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.opengl.vbo.VertexBufferObjectManagerProxy
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_opengl_vbo_VertexBufferObjectManagerProxy_nativeInitClass(JNIEnv*, jclass);
}

class VertexBufferObjectManager : public Wrapper {
	public:
		/* Constructors */
		VertexBufferObjectManager(jobject);

		/* Methods. */
};

#endif
