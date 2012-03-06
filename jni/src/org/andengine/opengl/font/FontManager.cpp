#include "src/org/andengine/opengl/font/FontManager.h"
#include "src/ScriptingEnvironment.h"

static jclass sFontManagerClass;

static jmethodID sLoadFontMethod;
static jmethodID sUnloadFontMethod;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_opengl_font_FontManagerProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sFontManagerClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);

	sLoadFontMethod = JNI_ENV()->GetMethodID(sFontManagerClass, "loadFont", "(Lorg/andengine/opengl/font/Font;)V");
	sUnloadFontMethod = JNI_ENV()->GetMethodID(sFontManagerClass, "unloadFont", "(Lorg/andengine/opengl/font/Font;)V");
}

// ===========================================================
// org.andengine.extension.scripting.opengl.font.FontManagerProxy
// ===========================================================

FontManager::FontManager(jobject pFontManager) {
	this->mUnwrapped = pFontManager;
}

bool FontManager::loadFont(Font* pFont) {
	return JNI_ENV()->CallBooleanMethod(this->mUnwrapped, sLoadFontMethod, pFont->unwrap());
}

bool FontManager::unloadFont(Font* pFont) {
	return JNI_ENV()->CallBooleanMethod(this->mUnwrapped, sUnloadFontMethod, pFont->unwrap());
}
