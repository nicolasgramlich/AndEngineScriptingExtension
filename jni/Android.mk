LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE				:= andenginescriptingextension_shared
LOCAL_MODULE_FILENAME		:= libandenginescriptingextension
LOCAL_CFLAGS				:= -Werror
LOCAL_SRC_FILES				:= src/ScriptingEnvironment.cpp \
								src/Context.cpp \
								src/Wrapper.cpp \
								src/Test.cpp \
								src/org/andengine/engine/Engine.cpp \
								src/org/andengine/entity/Entity.cpp \
								src/org/andengine/entity/shape/Shape.cpp \
								src/org/andengine/entity/primitive/Rectangle.cpp \
								src/org/andengine/entity/sprite/Sprite.cpp \
								src/org/andengine/entity/scene/Scene.cpp \
								src/org/andengine/opengl/texture/TextureManager.cpp \
								src/org/andengine/opengl/texture/Texture.cpp \
								src/org/andengine/opengl/texture/bitmap/AssetBitmapTexture.cpp \
								src/org/andengine/opengl/texture/region/TextureRegion.cpp \
								src/org/andengine/opengl/font/FontManager.cpp \
								src/org/andengine/opengl/font/Font.cpp \
								src/org/andengine/opengl/vbo/VertexBufferObjectManager.cpp

LOCAL_LDLIBS 				:= -llog

LOCAL_WHOLE_STATIC_LIBRARIES := spidermonkey_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,spidermonkey/android)
