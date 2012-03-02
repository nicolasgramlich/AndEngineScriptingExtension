#ifndef EngineProxy_H
#define EngineProxy_H

#include <jni.h>
#include "Wrapper.h"

class EngineProxy : public Wrapper {
	public:
		/* Constructors */
		 // TODO For now the constructor takes a 'Engine' java object, later on it should be able to take sth like a EngineProxyOptions object. 
		EngineProxy(jobject);

		/* Getter & Setter */
		jobject getVertexBufferObjectManager();
		jobject getTextureManager();
		jobject getFontManager();
};

#endif
