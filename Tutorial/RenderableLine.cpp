#include "RenderableLine.h"



RenderableLine::RenderableLine(Vec2<int> posStart, Vec2<int> posEnd, Color color)
	:RenderableObject(posStart, color),positionEnd(posEnd)
{
}

Vec2 <int> RenderableLine::center()
{
	return Vec2<int>((position.x + positionEnd.x) / 2, (position.y + positionEnd.y) / 2);
}

RenderableLine::~RenderableLine()
{
}

void RenderableLine::Render(Renderer *  renderer)
{
	SDL_SetRenderDrawColor(renderer->getSDLRenderer(), baseColor.r, baseColor.g, baseColor.b, baseColor.a);
	SDL_RenderDrawLine(renderer->getSDLRenderer(), position.x, position.y, positionEnd.x, positionEnd.y);
}

Vec2<int> RenderableLine::getPosition()
{
	return Vec2<int>(SDL_min(position.x,positionEnd.x),SDL_min(position.y,positionEnd.y));
}

void RenderableLine::setPositon(Vec2<int> newPositon)
{
	Vec2<int> delta(newPositon.x - getPosition().x, newPositon.y - getPosition().y);
	position.x += delta.x;
	position.y += delta.y;
	positionEnd.x += delta.x;
	positionEnd.y += delta.y;
}

Vec2<int> RenderableLine::getSize()
{
	return Vec2<int>(scale.x*SDL_abs(position.x-positionEnd.x),scale.y*SDL_abs(position.y-positionEnd.y));
}

RenderableObject * RenderableLine::clone()
{
	return new RenderableLine(*this);
}
