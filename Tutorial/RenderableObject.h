#pragma once
#include "Utils.h"
#include "Renderer.h"

class RenderableObject
{
public:
	
	RenderableObject();

	RenderableObject(Vec2 <uint> position, Color color = Color::COLOR_BLACK);

	RenderableObject(uint x, uint y, Color color= Color::COLOR_BLACK);
	
	virtual Vec2 <uint> center()=0;

	virtual void Render(Renderer * renderer)=0;

	~RenderableObject();

protected:

	Color baseColor;

	Vec2 <uint> position;
};

