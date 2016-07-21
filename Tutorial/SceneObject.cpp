#include "SceneObject.h"


SceneObject::SceneObject()
{
	
}


SceneObject::~SceneObject()
{
}

void SceneObject::Update()
{
}

Vec2<float> SceneObject::getPosition()
{
	return position;
}

void SceneObject::setPosition(Vec2<float> pos)
{
	this->position = pos;
}
