LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE			 := andenginescriptingextension_shared
LOCAL_MODULE_FILENAME	:= libandenginescriptingextension
LOCAL_CFLAGS			 := -Werror
LOCAL_SRC_FILES		  := src/ScriptingEnvironment.cpp \
							 src/Wrapper.cpp \
							 src/EngineProxy.cpp \
							 src/EntityProxy.cpp \
							 src/ShapeProxy.cpp \
							 src/RectangleProxy.cpp \
							 src/SpriteProxy.cpp \
							 src/Test.cpp

LOCAL_LDLIBS := -llog

# LOCAL_SHARED_LIBRARIES   := andengine_shared
# LOCAL_SHARED_LIBRARIES   += cutils_shared
# LOCAL_SHARED_LIBRARIES   += icu4c_shared
# LOCAL_SHARED_LIBRARIES   += js_shared

include $(BUILD_SHARED_LIBRARY)

# $(call import-module, graphic_engines/AndEngine/AndEngine/jni)
# $(call import-module, JavaScriptCore-X/jsc-android/jni/Source/JavaScriptCore/cutils)
# $(call import-module, JavaScriptCore-X/jsc-android/platform_external_icu4c)
# $(call import-module, JavaScriptCore-X/jsc-android/jni)
