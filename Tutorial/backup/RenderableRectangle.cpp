#include "RenderableRectangle.h"



RenderableRectangle::RenderableRectangle(Vec2 <uint> pos, Vec2<uint> sizeArg, Color color)
	:RenderableObject(pos,color),size(sizeArg)
{
}

Vec2<uint> RenderableRectangle::center()
{
	return Vec2<uint>(position.x + size.x / 2, position.y + size.y / 2);
}

RenderableRectangle::~RenderableRectangle()
{
}

RenderableRectangleFilled::RenderableRectangleFilled(Vec2 <uint> pos, Vec2<uint> sizeArg, Color color, Color fillColorArg)
	:RenderableObject(pos,color),size(sizeArg),fillColor(color)
{
}

RenderableRectangleFilled::~RenderableRectangleFilled()
{
}

Vec2<uint> RenderableRectangleFilled::center()
{
	return Vec2<uint>(position.x + size.x / 2, position.y + size.y / 2);
}