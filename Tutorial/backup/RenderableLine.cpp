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
