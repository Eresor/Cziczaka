#include "RenderableLine.h"



RenderableLine::RenderableLine(Vec2<uint> posStart, Vec2<uint> posEnd, Color color)
	:RenderableObject(posStart, color),positionEnd(posEnd)
{
}

Vec2 <uint> RenderableLine::center()
{
	return Vec2<uint>((position.x + positionEnd.x) / 2, (position.y + positionEnd.y) / 2);
}

RenderableLine::~RenderableLine()
{
}

void RenderableLine::Render(Renderer *  renderer)
{
	SDL_SetRenderDrawColor(renderer->getSDLRenderer(), baseColor.r, baseColor.g, baseColor.b, baseColor.a);
	SDL_RenderDrawLine(renderer->getSDLRenderer(), position.x, position.y, positionEnd.x, positionEnd.y);
}

RenderableObject * RenderableLine::clone()
{
	return new RenderableLine(*this);
}
