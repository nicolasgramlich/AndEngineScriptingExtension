#ifndef ScriptingCore_H
#define ScriptingCore_H

#include <jni.h>
#include <jsapi.h>
#include "src/Util.h"

class ScriptingCore {
	JSRuntime* mJSRuntime;
	JSContext* mJSContext;
	JSObject* mGlobal;

	public:
		ScriptingCore();
		~ScriptingCore();

		int runScript(const char*);
		const char* getJavaScriptVMVersion();		
};

#endif
