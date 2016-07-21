#pragma once
#include "Utils.h"
#include "Renderer.h"

class RenderableObject
{
public:
	
	/*memory management todo*/
	RenderableObject();

	RenderableObject(Vec2 <int> position, Color color = Color::COLOR_BLACK);

	RenderableObject(int x, int y, Color color= Color::COLOR_BLACK);
	
	virtual Vec2 <int> center()=0;

	virtual void Render(Renderer * renderer)=0;

	~RenderableObject();

	virtual RenderableObject * clone() = 0;

	virtual Vec2<int> getPosition();

	virtual void setPosition(Vec2<int>);

	void setScale(Vec2<float> scale);

	Vec2<float> getScale();

	virtual Vec2<int> getSize()=0;

protected:

	Color baseColor;

	Vec2 <int> position;

	Vec2 <float> scale;
};

