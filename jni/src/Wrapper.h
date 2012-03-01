#ifndef Wrapper_H
#define Wrapper_H

#include <jni.h>

class Wrapper {
	protected:
		jobject mUnwrapped;

	public:
		/* Unwrapper. */
		jobject unwrap();
};

#endif
