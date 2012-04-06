#ifndef IEntity_H
#define IEntity_H

#include <memory>
#include <jni.h>
#include "src/org/andengine/engine/handler/IDrawHandler.h"
#include "src/org/andengine/engine/handler/IUpdateHandler.h"
#include "src/org/andengine/util/IDisposable.h"
#include "src/org/andengine/entity/IEntity.h"
#include "src/org/andengine/entity/IEntity.h"
#include "src/org/andengine/entity/IEntityMatcher.h"
#include "src/org/andengine/entity/IEntity.h"
#include "src/org/andengine/entity/IEntity.h"

class IEntity : public IDrawHandler, public IUpdateHandler, public IDisposable {

	public:
		virtual jobject unwrap() = 0;
		virtual jfloat getY() = 0;
		virtual jfloat getX() = 0;
		virtual jfloat getRotation() = 0;
		virtual void setRotation(jfloat) = 0;
		virtual void attachChild(IEntity*) = 0;
		virtual jboolean attachChild(IEntity*, jint) = 0;
		virtual void setX(jfloat) = 0;
		virtual void setY(jfloat) = 0;
		virtual jfloat getScaleX() = 0;
		virtual jfloat getScaleY() = 0;
		virtual void setScale(jfloat) = 0;
		virtual void setScale(jfloat, jfloat) = 0;
		virtual jfloat getSkewX() = 0;
		virtual jfloat getSkewY() = 0;
		virtual void setSkew(jfloat, jfloat) = 0;
		virtual void setSkew(jfloat) = 0;
		virtual IEntity* detachChild(IEntityMatcher*) = 0;
		virtual jboolean detachChild(IEntity*) = 0;
		virtual jboolean onAttached() = 0;
		virtual jboolean onDetached() = 0;

};
#endif

