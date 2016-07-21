#include "RenderablePoint.h"



RenderablePoint::RenderablePoint(Vec2<uint> vec, Color color)
	:RenderableObject(vec, color)
{
}

_forceinline Vec2<uint> RenderablePoint::center()
{
	return position;
};


RenderablePoint::~RenderablePoint()
{
}

void RenderablePoint::Render(Renderer  * renderer)
{
	SDL_SetRenderDrawColor(renderer->getSDLRenderer(), baseColor.r, baseColor.g, baseColor.b, baseColor.a);
	SDL_RenderDrawPoint(renderer->getSDLRenderer(), position.x, position.y);
}

RenderableObject * RenderablePoint::clone()
{
	return new RenderablePoint(*this);
}
