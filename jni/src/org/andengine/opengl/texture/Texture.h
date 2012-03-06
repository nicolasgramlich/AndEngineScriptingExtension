#ifndef Texture_H
#define Texture_H

#include <jni.h>
#include "src/Wrapper.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.opengl.texture.TextureProxy
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_opengl_texture_TextureProxy_nativeInitClass(JNIEnv*, jclass);
}

class Texture : public Wrapper {
	protected:
		/* Constructors */
		Texture();

	public:
		/* Getter & Setter. */
		int getWidth();
		int getHeight();

		/* Methods. */
		void load();
		void unload();
};

#endif
