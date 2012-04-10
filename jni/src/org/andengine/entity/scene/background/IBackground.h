#ifndef IBackground_H
#define IBackground_H

#include <memory>
#include <jni.h>
#include "src/org/andengine/engine/handler/IDrawHandler.h"
#include "src/org/andengine/engine/handler/IUpdateHandler.h"

class IBackground : public IDrawHandler, public IUpdateHandler {

	public:
		virtual ~IBackground() { };
		virtual jobject unwrap() = 0;

};
#endif

