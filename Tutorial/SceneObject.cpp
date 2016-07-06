#include "SceneObject.h"


SceneObject::SceneObject(SceneBase * sc)
	:parentScene(sc)
{
	sc->addObject(this);
}


SceneObject::~SceneObject()
{
}
