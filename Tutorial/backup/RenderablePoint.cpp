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
