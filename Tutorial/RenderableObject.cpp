#include "RenderableObject.h"



RenderableObject::RenderableObject()
	:position(),baseColor(Color::COLOR_BLACK)
{
}

RenderableObject::RenderableObject(Vec2 <uint> vec, Color color)
	:position(vec),baseColor(color)
{
}

RenderableObject::RenderableObject(uint x, uint y, Color color)
	: position(x, y), baseColor(color)
{
}

RenderableObject::~RenderableObject()
{
}
