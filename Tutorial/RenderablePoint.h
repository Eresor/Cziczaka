#pragma once
#include "RenderableObject.h"
class RenderablePoint :
	public RenderableObject
{
public:

	RenderablePoint(Vec2<uint> vec, Color color);

	_forceinline Vec2<uint> center();

	virtual void Render(Renderer *  renderer);

	RenderableObject * clone();
	
	~RenderablePoint();
};

