#include "RenderableRectangle.h"



RenderableRectangle::RenderableRectangle(Vec2 <int> pos, Vec2<int> sizeArg, Color color)
	:RenderableObject(pos,color),size(sizeArg)
{
}

Vec2<int> RenderableRectangle::center()
{
	return Vec2<int>(position.x + size.x / 2, position.y + size.y / 2);
}

void RenderableRectangle::Render(Renderer  * renderer)
{
	SDL_SetRenderDrawColor(renderer->getSDLRenderer(), baseColor.r, baseColor.g, baseColor.b, baseColor.a);
	SDL_Rect rect = { position.x,position.y,size.x*scale.x,size.y*scale.y };
	SDL_RenderDrawRect(renderer->getSDLRenderer(), &rect);
}

Vec2<int> RenderableRectangle::getSize()
{
	return Vec2<int>(size.x*scale.x,size.y*scale.y);
}

RenderableObject * RenderableRectangle::clone()
{
	return new RenderableRectangle(*this);
}

RenderableRectangle::~RenderableRectangle()
{
}

RenderableRectangleFilled::RenderableRectangleFilled(Vec2 <int> pos, Vec2<int> sizeArg, Color color, Color fillColorArg)
	:RenderableObject(pos,color),size(sizeArg),fillColor(color)
{
}

void RenderableRectangleFilled::Render(Renderer *  renderer)
{
	SDL_SetRenderDrawColor(renderer->getSDLRenderer(), baseColor.r, baseColor.g, baseColor.b, baseColor.a);
	SDL_Rect rect = { position.x,position.y,size.x*scale.x,size.y*scale.y };
	SDL_RenderFillRect(renderer->getSDLRenderer(), &rect);
}

RenderableObject * RenderableRectangleFilled::clone()
{
	return new RenderableRectangleFilled(*this);
}

RenderableRectangleFilled::~RenderableRectangleFilled()
{
}

Vec2<int> RenderableRectangleFilled::center()
{
	return Vec2<int>(position.x + size.x / 2, position.y + size.y / 2);
}

Vec2<int> RenderableRectangleFilled::getSize()
{
	return Vec2<int>(size.x*scale.x, size.y*scale.y);
}

