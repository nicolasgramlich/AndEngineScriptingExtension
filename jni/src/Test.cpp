#include "src/AndEngineScriptingExtension.h"
#include "src/Test.h"
#include "src/Util.h"
#include "src/org/andengine/entity/primitive/Rectangle.h"
#include "src/org/andengine/entity/sprite/Sprite.h"
#include "src/org/andengine/opengl/texture/Texture.h"
#include "src/org/andengine/opengl/texture/bitmap/AssetBitmapTexture.h"
#include "src/org/andengine/opengl/texture/region/TextureRegion.h"

// ===========================================================
// org.andengine.extension.scripting.Test
// ===========================================================

JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_Test_test(JNIEnv* pJNIEnv, jclass pJClass) {
	Texture* texture = new AssetBitmapTexture(getEngine()->getTextureManager(), getContext()->getAssets(), JNI_ENV()->NewStringUTF("gfx/box.png"));
	texture->load();

	TextureRegion* textureRegion = new TextureRegion(texture, 0, 0, texture->getWidth(), texture->getHeight());

	int size = 100;

	Entity* entity = new Sprite(360 - (size / 2), 240 - (size / 2), size, size, textureRegion, getEngine()->getVertexBufferObjectManager());

	entity->setRotation(45);
	entity->setScale(2);

	return entity->unwrap();
}
