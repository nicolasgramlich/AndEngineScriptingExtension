#include <cstdlib>
#include "src/org/andengine/util/color/Color.h"

static jclass sColorClass;
static jmethodID sConstructor____org_andengine_util_color_Color__;
static jmethodID sConstructor__FFF;
static jmethodID sConstructor__FFFF;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_util_color_ColorProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sColorClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);
	sConstructor____org_andengine_util_color_Color__ = JNI_ENV()->GetMethodID(sColorClass, "<init>", "(JLorg/andengine/util/color/Color;)V");
	sConstructor__FFF = JNI_ENV()->GetMethodID(sColorClass, "<init>", "(JFFF)V");
	sConstructor__FFFF = JNI_ENV()->GetMethodID(sColorClass, "<init>", "(JFFFF)V");
}

Color::Color(jobject pColorProxy) {
	this->mUnwrapped = pColorProxy;
}
jobject Color::unwrap() {
	return this->mUnwrapped;
}
Color::Color(Color* pColor) {
	this->mUnwrapped = JNI_ENV()->NewObject(sColorClass, sConstructor____org_andengine_util_color_Color__, (jlong)this, pColor->unwrap());
}
Color::Color(jfloat pRed, jfloat pGreen, jfloat pBlue) {
	this->mUnwrapped = JNI_ENV()->NewObject(sColorClass, sConstructor__FFF, (jlong)this, pRed, pGreen, pBlue);
}
Color::Color(jfloat pRed, jfloat pGreen, jfloat pBlue, jfloat pAlpha) {
	this->mUnwrapped = JNI_ENV()->NewObject(sColorClass, sConstructor__FFFF, (jlong)this, pRed, pGreen, pBlue, pAlpha);
}
Color::Color() {

}

