#ifndef IDisposable_H
#define IDisposable_H

#include <memory>
#include <jni.h>

class IDisposable {

	public:
		virtual jobject unwrap() = 0;

};
#endif

