#pragma once
#include "RenderableObject.h"
class RenderableLine : RenderableObject
{
public:

	RenderableLine(Vec2<uint> posStart, Vec2<uint> posEnd, Color color);
	
	virtual Vec2<uint> center();

	virtual void Render(Renderer renderer);
	
	~RenderableLine();

protected:
	Vec2 <uint> positionEnd;
};

