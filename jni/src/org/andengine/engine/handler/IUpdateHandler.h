#ifndef IUpdateHandler_H
#define IUpdateHandler_H

#include <memory>
#include <jni.h>

class IUpdateHandler {

	public:
		virtual jobject unwrap() = 0;

};
#endif

