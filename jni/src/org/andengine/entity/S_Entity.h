#ifndef S_Entity_H
#define S_Entity_H

#include <jsapi.h>
#include "src/Util.h"
#include "src/AndEngineScriptingExtension.h"
#include "src/org/andengine/entity/Entity.h"

class S_Entity : public Entity {
	JSObject* mJSObject;

	public:
		virtual jboolean onAttached();
		virtual jboolean onDetached();

		static JSClass* sJSClass;
		static JSObject* sJSObject;

		enum {
			kX = 1,
			kY
		};

		S_Entity(JSObject*);
		S_Entity(JSObject*, float, float);

		static JSBool jsConstructor(JSContext* pJSContext, uint32_t pArgumentCount, jsval* pArguments) {
			JSObject* obj = JS_NewObject(pJSContext, S_Entity::sJSClass, S_Entity::sJSObject, NULL);

			double x;
			double y;

			if(!JS_ConvertArguments(pJSContext, pArgumentCount, JS_ARGV(pJSContext, pArguments), "dd", &x, &y)) {
        		return JS_FALSE;
        	}

			S_Entity* cobj = new S_Entity(obj, x, y);

			pointerShell_t* pt = (pointerShell_t*)JS_malloc(pJSContext, sizeof(pointerShell_t));
			pt->flags = 0;
			pt->data = cobj;

			JS_SetPrivate(obj, pt);
			JS_SET_RVAL(pJSContext, pArguments, OBJECT_TO_JSVAL(obj));

			return JS_TRUE;
		};

		static void jsFinalize(JSContext* pJSContext, JSObject* pJSObject) {
			pointerShell_t* pt = (pointerShell_t*)JS_GetPrivate(pJSObject);
			if(pt) {
				if(!(pt->flags & kPointerTemporary) && pt->data) {
					delete (S_Entity*)pt->data;
				}
				JS_free(pJSContext, pt);
			}
		};

		static JSBool jsPropertyGet(JSContext* pJSContext, JSObject* pJSObject, jsid pJSID, jsval* pJSVal) {
			S_Entity* cobj; 
			JSGET_PTRSHELL(S_Entity, cobj, pJSObject);
			if(!cobj) {
				return JS_FALSE;
			}
			switch(JSID_TO_INT(pJSID)) {
				case kX:
					JS_NewNumberValue(pJSContext, cobj->getX(), pJSVal);
					return JS_TRUE;
				case kY:
					JS_NewNumberValue(pJSContext, cobj->getY(), pJSVal);
					return JS_TRUE;
				default:
					return JS_FALSE;
			}
		};

		static JSBool jsPropertySet(JSContext* pJSContext, JSObject* pJSObject, jsid pJSID, JSBool pStrict, jsval* pJSVal) {
			S_Entity* cobj;
			JSGET_PTRSHELL(S_Entity, cobj, pJSObject);
			if(!cobj) {
				return JS_FALSE;
			}
			switch(JSID_TO_INT(pJSID)) {
				case kX:
					{ 
						double tmp;
						JS_ValueToNumber(pJSContext, *pJSVal, &tmp);
						cobj->setX(tmp);
						return JS_TRUE;
					}
				case kY:
					{
						double tmp;
						JS_ValueToNumber(pJSContext, *pJSVal, &tmp);
						cobj->setY(tmp);
						return JS_TRUE;
					}
				default:
					return JS_FALSE;
			}
		};

		static void jsCreateClass(JSContext* pJSContext, JSObject* pGlobal, const char* pName) {
			sJSClass = (JSClass*)calloc(1, sizeof(JSClass));
			sJSClass->name = pName;
			sJSClass->addProperty = JS_PropertyStub;
			sJSClass->delProperty = JS_PropertyStub;
			sJSClass->getProperty = JS_PropertyStub;
			sJSClass->setProperty = JS_StrictPropertyStub;
			sJSClass->enumerate = JS_EnumerateStub;
			sJSClass->resolve = JS_ResolveStub;
			sJSClass->convert = JS_ConvertStub;
			sJSClass->finalize = jsFinalize;
			sJSClass->flags = JSCLASS_HAS_PRIVATE;
			static JSPropertySpec properties[] = {
				{"x", kX, JSPROP_PERMANENT | JSPROP_SHARED, S_Entity::jsPropertyGet, S_Entity::jsPropertySet},
				{"y", kY, JSPROP_PERMANENT | JSPROP_SHARED, S_Entity::jsPropertyGet, S_Entity::jsPropertySet},
				{0}
			};

			sJSObject = JS_InitClass(pJSContext, pGlobal, NULL, sJSClass, S_Entity::jsConstructor, 2, properties, NULL, NULL, NULL);
		};
};

#endif