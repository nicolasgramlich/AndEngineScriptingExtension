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
	fprintf(stderr, "%s:%u:%s\n", report->filename ? report->filename : "<no filename>", (unsigned int) report->lineno, message);
}

JNIEXPORT jint JNICALL Java_org_andengine_extension_scripting_ScriptingEnvironment_runScript(JNIEnv* pJNIEnv, jclass pJClass, jstring pCode) {
	/* JS variables. */
	JSRuntime *rt;
	JSContext *cx;
	JSObject *global; 

	/* Create a JS runtime. */
	rt = JS_NewRuntime(8L * 1024L * 1024L);
	if (rt == NULL) return 1;

	/* Create a context. */
	cx = JS_NewContext(rt, 8192);
	if (cx == NULL) return 1;

//	JS_SetOptions(cx, JSOPTION_VAROBJFIX | JSOPTION_JIT | JSOPTION_METHODJIT);
	JS_SetOptions(cx, JSOPTION_VAROBJFIX | JSOPTION_METHODJIT);
	JS_SetVersion(cx, JSVERSION_LATEST);
	JS_SetErrorReporter(cx, reportError);

	/* Create the global object in a new compartment. */
	global = JS_NewCompartmentAndGlobalObject(cx, &global_class, NULL);
	if (global == NULL) return 1;

	/* Populate the global object with the standard globals, like Object and Array. */
	if (!JS_InitStandardClasses(cx, global)) return 1;

	/* Your application code here. This may include JSAPI calls to create your own custom JS objects and run scripts. */
	/* These should indicate source location for diagnostics. */
	{
		char* filename;
		uint lineno;

		/*
		 * The return value comes back here -- if it could be a GC thing, you must
		 * add it to the GC's "root set" with JS_AddRoot(cx, &thing) where thing
		 * is a JSString *, JSObject *, or jsdouble *, and remove the root before
		 * rval goes out of scope, or when rval is no longer needed.
		 */
		jsval rval;
		JSBool ok;

		/*
		 * Some example source in a C string.  Larger, non-null-terminated buffers
		 * can be used, if you pass the buffer length to JS_EvaluateScript.
		 */
		const char* source = "var x=10;x*x;";

//		ok = JS_EvaluateScript(cx, global, source, strlen(source), filename, lineno, &rval);
//	
//		if(ok) {
//		    /* Should get a number back from the example source. */
////		    jsdouble d;
//		
////		    ok = JS_ValueToNumber(cx, rval, &d);
//		}
		LOG_D("[JS] - ...");
	}

	/* Cleanup. */
	JS_DestroyContext(cx);
	JS_DestroyRuntime(rt);
	JS_ShutDown();

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
