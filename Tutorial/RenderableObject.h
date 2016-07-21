#pragma once
#include "Utils.h"
#include "Renderer.h"

class RenderableObject
{
public:
	
	/*memory management todo*/
	RenderableObject();

	RenderableObject(Vec2 <uint> position, Color color = Color::COLOR_BLACK);

	RenderableObject(uint x, uint y, Color color= Color::COLOR_BLACK);
	
	virtual Vec2 <uint> center()=0;

	virtual void Render(Renderer * renderer)=0;

	~RenderableObject();

	virtual RenderableObject * clone() = 0;

	virtual Vec2<uint> getPosition();

	virtual void setPosition(Vec2<uint>);

	void setScale(Vec2<float> scale);

	Vec2<float> getScale();

	virtual Vec2<uint> getSize()=0;

protected:

	Color baseColor;

	Vec2 <uint> position;

	Vec2 <float> scale;
};

