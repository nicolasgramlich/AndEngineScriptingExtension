#ifndef TextureRegion_H
#define TextureRegion_H

#include <jni.h>
#include "src/org/andengine/opengl/texture/Texture.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.opengl.texture.bitmap.TextureRegionProxy
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_opengl_texture_region_TextureRegionProxy_nativeInitClass(JNIEnv*, jclass);
}

class TextureRegion : public Texture {
	public:
		/* Constructors */
		TextureRegion(Texture*, float, float, float, float);
};

#endif
