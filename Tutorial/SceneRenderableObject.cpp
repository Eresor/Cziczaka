#include "SceneRenderableObject.h"


SceneRenderableObject::SceneRenderableObject(RenderableObject *&& obj)
	:renderableObject(obj),SceneObject(), scale(1.0f, 1.0f)
{

}

SceneRenderableObject::SceneRenderableObject(const SceneRenderableObject & other)
{
	renderableObject = other.renderableObject->clone();
	//todo
}

SceneRenderableObject & SceneRenderableObject::operator=(const SceneRenderableObject & other)
{
	// TODO: insert return statement here
	//todo
	renderableObject = other.renderableObject->clone();
	return *this;
}


SceneRenderableObject::~SceneRenderableObject()
{
	if (renderableObject != nullptr)
	{
		delete renderableObject;
	}
}

RenderableObject * SceneRenderableObject::getRenderableObject()
{
	return renderableObject;
}

void SceneRenderableObject::setScale(Vec2<float> scale)
{
	this->scale = scale;
}

Vec2<float> SceneRenderableObject::getScale()
{
	return scale;
}
