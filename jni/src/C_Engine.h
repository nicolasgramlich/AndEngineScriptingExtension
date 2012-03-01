#ifndef C_Engine_H
#define C_Engine_H

#include <jni.h>

class C_Engine {
	jobject mUnwrapped;

	public:
		/* Constructors */
		 // TODO For now the constructor takes a 'Engine' java object, later on it should be able to take sth like a C_EngineOptions object. 
		C_Engine(jobject);

		/* Getter & Setter */
		jobject getVertexBufferObjectManager();
		jobject getTextureManager();
		jobject getFontManager();
};

#endif
