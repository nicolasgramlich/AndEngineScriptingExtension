#include "src/org/andengine/input/touch/TouchEvent.h"
#include "src/ScriptingEnvironment.h"

static jclass sTouchEventClass;

static jmethodID sGetXMethod;
static jmethodID sGetYMethod;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_input_touch_TouchEventProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	jclass contextClass = JNI_ENV()->FindClass("android/content/TouchEvent");
	sTouchEventClass = (jclass)JNI_ENV()->NewGlobalRef(contextClass);

	sGetXMethod = JNI_ENV()->GetMethodID(sTouchEventClass, "getX", "()F");
	sGetYMethod = JNI_ENV()->GetMethodID(sTouchEventClass, "getY", "()F");
}

// ===========================================================
// org.andengine.extension.scripting.input.touch.TouchEventProxy
// ===========================================================

TouchEvent::TouchEvent(jobject pTouchEvent) {
	this->mUnwrapped = pTouchEvent;
}

jfloat TouchEvent::getX() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sGetXMethod);
}

jfloat TouchEvent::getY() {
	return JNI_ENV()->CallFloatMethod(this->mUnwrapped, sGetYMethod);
}
