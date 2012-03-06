#ifndef FontManager_H
#define FontManager_H

#include <jni.h>
#include "src/Wrapper.h"
#include "src/org/andengine/opengl/font/Font.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.opengl.font.FontManagerProxy
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_opengl_font_FontManagerProxy_nativeInitClass(JNIEnv*, jclass);
}

class Font; // Forward declaration!

class FontManager : public Wrapper {
	public:
		/* Constructors */
		FontManager(jobject);

		/* Methods. */
		bool loadFont(Font*);
		bool unloadFont(Font*);
};

#endif
