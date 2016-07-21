#pragma once
#include "RenderableObject.h"
class RenderableLine : RenderableObject
{
public:

	RenderableLine(Vec2<int> posStart, Vec2<int> posEnd, Color color);
	
	virtual Vec2<int> center();

	virtual void Render(Renderer * renderer);

	Vec2<int> getPosition();

	void setPositon(Vec2<int> newPositon);

	Vec2<int> getSize();

	RenderableObject * clone();
	
	~RenderableLine();

protected:
	Vec2 <int> positionEnd;
};

