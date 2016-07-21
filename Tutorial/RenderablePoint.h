#pragma once
#include "RenderableObject.h"
class RenderablePoint :
	public RenderableObject
{
public:

	RenderablePoint(Vec2<int> vec, Color color);

	_forceinline Vec2<int> center();

	virtual void Render(Renderer *  renderer);

	RenderableObject * clone();

	Vec2<int> getSize();
	
	~RenderablePoint();
};

