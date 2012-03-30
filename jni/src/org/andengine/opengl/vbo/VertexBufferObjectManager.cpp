#include "src/org/andengine/opengl/vbo/VertexBufferObjectManager.h"
#include "src/AndEngineScriptingExtension.h"

static jclass sVertexBufferObjectManagerClass;

JNIEXPORT void JNICALL Java_org_andengine_extension_scripting_opengl_vbo_VertexBufferObjectManagerProxy_nativeInitClass(JNIEnv* pJNIEnv, jclass pJClass) {
	sVertexBufferObjectManagerClass = (jclass)JNI_ENV()->NewGlobalRef(pJClass);
}

// ===========================================================
// org.andengine.extension.scripting.opengl.vbo.VertexBufferObjectManagerProxy
// ===========================================================

VertexBufferObjectManager::VertexBufferObjectManager(jobject pVertexBufferObjectManager) {
	this->mUnwrapped = pVertexBufferObjectManager;
}
