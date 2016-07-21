#include "RenderableRectangle.h"



RenderableRectangle::RenderableRectangle(Vec2 <uint> pos, Vec2<uint> sizeArg, Color color)
	:RenderableObject(pos,color),size(sizeArg)
{
}

Vec2<uint> RenderableRectangle::center()
{
	return Vec2<uint>(position.x + size.x / 2, position.y + size.y / 2);
}

void RenderableRectangle::Render(Renderer  * renderer)
{
	SDL_SetRenderDrawColor(renderer->getSDLRenderer(), baseColor.r, baseColor.g, baseColor.b, baseColor.a);
	SDL_Rect rect = { position.x,position.y,size.x,size.y };
	SDL_RenderDrawRect(renderer->getSDLRenderer(), &rect);
}

RenderableObject * RenderableRectangle::clone()
{
	return new RenderableRectangle(*this);
}

RenderableRectangle::~RenderableRectangle()
{
}

RenderableRectangleFilled::RenderableRectangleFilled(Vec2 <uint> pos, Vec2<uint> sizeArg, Color color, Color fillColorArg)
	:RenderableObject(pos,color),size(sizeArg),fillColor(color)
{
}

void RenderableRectangleFilled::Render(Renderer *  renderer)
{
	SDL_SetRenderDrawColor(renderer->getSDLRenderer(), baseColor.r, baseColor.g, baseColor.b, baseColor.a);
	SDL_Rect rect = { position.x,position.y,size.x,size.y };
	SDL_RenderFillRect(renderer->getSDLRenderer(), &rect);
}

RenderableObject * RenderableRectangleFilled::clone()
{
	return new RenderableRectangleFilled(*this);
}

RenderableRectangleFilled::~RenderableRectangleFilled()
{
}

Vec2<uint> RenderableRectangleFilled::center()
{
	return Vec2<uint>(position.x + size.x / 2, position.y + size.y / 2);
}

