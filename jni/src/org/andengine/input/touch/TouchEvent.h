#ifndef TouchEvent_H
#define TouchEvent_H

#include <jni.h>
#include "src/Wrapper.h"

extern "C" {
	// ===========================================================
	// org.andengine.extension.scripting.input.touch.TouchEventProxy
	// ===========================================================

	JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_input_touch_TouchEventProxy_nativeInitClass(JNIEnv*, jclass);
}

class TouchEvent : public Wrapper {
	public:
		/* Constructors */
		TouchEvent(jobject);

		/* Getter & Setter */
		jfloat getX();
		jfloat getY();
};

#endif
