#include "src/AndEngineScriptingExtension.h"
#include "src/Test.h"
#include "src/Util.h"
#include "src/org/andengine/opengl/texture/ITexture.h"
#include "src/org/andengine/opengl/texture/Texture.h"
#include "src/org/andengine/opengl/texture/bitmap/BitmapTexture.h"
#include "src/org/andengine/opengl/texture/bitmap/AssetBitmapTexture.h"
#include "src/org/andengine/opengl/texture/region/ITextureRegion.h"
#include "src/org/andengine/opengl/texture/region/TextureRegion.h"
#include "src/org/andengine/entity/Entity.h"
#include "src/org/andengine/entity/primitive/Rectangle.h"
#include "src/org/andengine/entity/sprite/Sprite.h"

// ===========================================================
// org.andengine.extension.scripting.Test
// ===========================================================

JNIEXPORT jobject JNICALL Java_org_andengine_extension_scripting_Test_test(JNIEnv* pJNIEnv, jclass pJClass) {
	Engine* engine = getEngine();
	Context* context = getContext();

	/* */
	AssetManager* assetManager = context->getAssetManager();
	TextureManager* textureManager = engine->getTextureManager();
	VertexBufferObjectManager* vertexBufferObjectManager = engine->getVertexBufferObjectManager();

	ITexture* texture = new AssetBitmapTexture(textureManager, assetManager, JNI_ENV()->NewStringUTF("gfx/box.png"));
	texture->load();

	ITextureRegion* textureRegion = new TextureRegion(texture, 0, 0, texture->getWidth(), texture->getHeight());

	int size = 100;

	Entity* entity = new Sprite(360 - (size / 2), 240 - (size / 2), size, size, textureRegion, vertexBufferObjectManager);
//	Entity* entity = new Rectangle(360 - (size / 2), 240 - (size / 2), size, size, vertexBufferObjectManager);

	entity->setRotation(45);
	entity->setScale(2);
	
//	delete texture;
	delete vertexBufferObjectManager;
	delete textureManager;
	delete assetManager;

	return entity->unwrap();
}
