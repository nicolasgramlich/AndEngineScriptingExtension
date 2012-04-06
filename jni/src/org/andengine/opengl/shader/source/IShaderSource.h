#ifndef IShaderSource_H
#define IShaderSource_H

#include <memory>
#include <jni.h>

class IShaderSource {

	public:
		virtual jobject unwrap() = 0;

};
#endif

