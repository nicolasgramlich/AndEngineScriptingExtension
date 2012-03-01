#ifndef C_Rectangle_H
#define C_Rectangle_H

#include <jni.h>
#include "ScriptingEnvironment.h"
#include "C_Entity.h"

class C_Rectangle : public C_Entity {
	protected:
		/* Constructors */
 		C_Rectangle();
	public:
		/* Constructors */ 
		C_Rectangle(float, float, float, float, jobject);
};

#endif
