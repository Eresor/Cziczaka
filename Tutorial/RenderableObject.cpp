#include "RenderableObject.h"



RenderableObject::RenderableObject()
	:position(),baseColor(Color::COLOR_BLACK)
{
}

RenderableObject::RenderableObject(Vec2 <int> vec, Color color)
	:position(vec),baseColor(color)
{
}

RenderableObject::RenderableObject(int x, int y, Color color)
	: position(x, y), baseColor(color)
{
}

RenderableObject::~RenderableObject()
{
}

Vec2<int> RenderableObject::getPosition()
{
	return position;
}

void RenderableObject::setPosition(Vec2<int>)
{
	this->position = position;
}

void RenderableObject::setScale(Vec2<float> scale)
{
	this->scale = scale;
}

Vec2<float> RenderableObject::getScale()
{
	return scale;
}
