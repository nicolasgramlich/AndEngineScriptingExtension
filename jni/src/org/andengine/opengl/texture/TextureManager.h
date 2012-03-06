#ifndef TextureManager_H
#define TextureManager_H

#include <jni.h>
#include "src/Wrapper.h"
#include "src/org/andengine/opengl/texture/Texture.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.opengl.texture.TextureManagerProxy
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_opengl_texture_TextureManagerProxy_nativeInitClass(JNIEnv*, jclass);
}

class TextureManager : public Wrapper {
	public:
		/* Constructors */
		TextureManager(jobject);

		/* Methods. */
		bool loadTexture(Texture*);
		bool unloadTexture(Texture*);
};

#endif
