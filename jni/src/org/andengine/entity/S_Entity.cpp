#include <cstdlib>
#include "src/org/andengine/entity/S_Entity.h"

JSClass* S_Entity::sJSClass = NULL;
JSObject* S_Entity::sJSObject = NULL;

bool S_Entity::onAttached() {
	JSContext* jsContext = getJSContext();
	JSBool found;

	/* Check if JS function exists. */
	JS_HasProperty(jsContext, this->mJSObject, "onAttached", &found);
	if(JS_TRUE == found) {
		/* Get JS function. */
		jsval fval;
		JS_GetProperty(jsContext, this->mJSObject, "onAttached", &fval);

		/* Call JS function and get return value. */
		jsval rval;
		JS_CallFunctionValue(jsContext, this->mJSObject, fval, 0, 0, &rval);

		if(JSVAL_IS_BOOLEAN(rval)) {
			bool result = JS_TRUE == JSVAL_TO_BOOLEAN(rval);
			return result;
		} else {
			// TODO throw Exception?
			return false;
		}
	} else {
		return false;
	}
}

bool S_Entity::onDetached() {
	return true;
}