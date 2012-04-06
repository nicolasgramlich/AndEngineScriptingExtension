#ifndef IResolutionPolicy_H
#define IResolutionPolicy_H

#include <memory>
#include <jni.h>

class IResolutionPolicy {

	public:
		virtual jobject unwrap() = 0;

};
#endif

