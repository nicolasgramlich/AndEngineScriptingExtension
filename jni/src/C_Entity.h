#ifndef C_Entity_H
#define C_Entity_H

#include <jni.h>
#include "ScriptingEnvironment.h"
#include "Wrapper.h"

class C_Entity : public Wrapper {
	protected:
		/* Constructors */ 
		C_Entity();

	public:
		/* Constructors. */ 
		C_Entity(float, float);

		/* Getter & Setter */
		void setRotation(float);
		void setScale(float);
};

#endif
