#include "src/ScriptingEnvironment.h"

// ===========================================================
// org.andengine.extension.scripting.ScriptingEnvironment
// ===========================================================

static Context* sContext;
static JavaVM* sJavaVM;
static JNIEnv* sJNIEnv;
static Engine* sEngine;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* pJavaVM, void* pReserved) {
	sJavaVM = pJavaVM;
 
//	JNIEnv* env;
//	vm->GetEnv((void**)&env, JNI_VERSION_1_4);

	// Register methods for org.cocos2dx.hellojs.HelloJS
//	jclass hellojs_class = env->FindClass("org/cocos2dx/hellojs/HelloJS");
//	env->RegisterNatives(hellojs_class, hellojs_methods, sizeof(hellojs_methods)/sizeof(hellojs_methods[0]));

	return JNI_VERSION_1_4;
}

/* The class of the global object. */
static JSClass global_class = { "global", JSCLASS_GLOBAL_FLAGS, JS_PropertyStub, JS_PropertyStub, JS_PropertyStub, JS_StrictPropertyStub, JS_EnumerateStub, JS_ResolveStub, JS_ConvertStub, JS_FinalizeStub, JSCLASS_NO_OPTIONAL_MEMBERS };

/* The error reporter callback. */
void reportError(JSContext *cx, const char *message, JSErrorReport *report) {
	LOG_D("%s:%u:%s\n", report->filename ? report->filename : "<no filename>", (unsigned int) report->lineno, message);
}

JNIEXPORT jint JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_runScript(JNIEnv* pJNIEnv, jclass pJClass, jstring pScript) {
	const char* script = JNI_ENV()->GetStringUTFChars(pScript, 0);

	runScript(script);
}

int runScript(const char* pScript) {
	LOG_D("runScript");
	LOG_D("##############################");
	LOG_D(pScript);
	LOG_D("##############################");

	/* Create a JS runtime. */
	JSRuntime *rt = JS_NewRuntime(8L * 1024L * 1024L);
	if (rt == NULL) {
		LOG_D("(rt == NULL)");
		return 1;
	}

	/* Create a context. */
	JSContext *cx = JS_NewContext(rt, 8192);
	if (cx == NULL) {
		LOG_D("(cx == NULL)");
		return 1;
	}

	JS_SetOptions(cx, JSOPTION_VAROBJFIX);
	JS_SetVersion(cx, JSVERSION_LATEST);
	JS_SetErrorReporter(cx, reportError);

	/* Create the global object in a new compartment. */
	JSObject *global =
	JS_NewCompartmentAndGlobalObject(cx, &global_class, NULL);
	if (global == NULL) {
		LOG_D("(global == NULL)");
		return 1;
	}

	// Populate the global object with the standard globals,
	// like Object and Array.
	if (!JS_InitStandardClasses(cx, global)) {
		LOG_D("(!JS_InitStandardClasses(cx, global))");
		return 1;
	}

	const char *filename = NULL;
	int lineno = 0;  

	jsval rval;
	JSBool evaluatedOK = JS_EvaluateScript(cx, global, pScript, strlen(pScript), filename, lineno, &rval);  

	if (JS_FALSE == evaluatedOK) {
		LOG_D("evaluatedOK == JS_FALSE)");
		// return 1;
	} else {
		if (JSVAL_IS_NULL(rval)) {
			LOG_D("rval : (JSVAL_IS_NULL(rval)");
			// return 1;
		} else if ((JSVAL_IS_BOOLEAN(rval)) &&
				   (JS_FALSE == (JSVAL_TO_BOOLEAN(rval)))) {
			LOG_D("rval : (return value is JS_FALSE");
			// return 1;
		} else if (JSVAL_IS_STRING(rval)) {
			JSString *str = JS_ValueToString(cx, rval);  
			if (NULL == str) {
				LOG_D("rval : return string is NULL");
			} else {
				LOG_D("rval : return string =\n%s\n", JS_EncodeString(cx, str));
			}
		} else if (JSVAL_IS_NUMBER(rval)) {
			double number;
			if (JS_FALSE == JS_ValueToNumber(cx, rval, &number)) {
				LOG_D("rval : return number could not be converted");
			} else {
				LOG_D("rval : return number =\n%f", number);
			}
		}
	}

	// Cleanup
	JS_DestroyContext(cx);
	JS_DestroyRuntime(rt);
	JS_ShutDown();

	LOG_D("runScript done.");
	return 0;
}

JNIEXPORT jstring JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_getJavaScriptVMVersion(JNIEnv* pJNIEnv, jclass pJClass) {
	const char* version = JS_GetImplementationVersion();
	return pJNIEnv->NewStringUTF(version);
}

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sJNIEnv = pJNIEnv;
}

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeInit(JNIEnv* pJNIEnv, jclass pJClass, jobject pContext, jstring pAPKPath, jobject pEngine) {
	sContext = new Context(pContext);
	setAPKPath(pJNIEnv, pJClass, pAPKPath);
	sEngine = new Engine(pEngine);
}

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeAttachCurrentThread(JNIEnv* pJNIEnv, jclass pJClass) {
	// TODO
}

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_nativeDetachCurrentThread(JNIEnv* pJNIEnv, jclass pJClass) {
	// TODO
}

JavaVM* JAVA_VM() {
	return sJavaVM;
}

JNIEnv* JNI_ENV() {
	return sJNIEnv;
}

Engine* getEngine() {
	return sEngine;
}

Context* getContext() {
	return sContext;
}

void setAPKPath(JNIEnv* pJNIEnv, jclass pJClass, jstring pAPKPath) {
//	const char* apkPath;
//	jboolean isCopy;
//	apkPath = env->GetStringUTFChars(pAPKPath, &isCopy);
//	if(isCopy) {
//		setResourcePath(apkPath);
//		env->ReleaseStringUTFChars(pAPKPath, apkPath);
//	}
}
