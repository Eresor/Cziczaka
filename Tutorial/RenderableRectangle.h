#pragma once
#include "RenderableObject.h"
class RenderableRectangle :
	public RenderableObject
{
public:

	RenderableRectangle(Vec2 <int> pos, Vec2<int> sizeArg, Color color);

	Vec2 <int> center();
	
	~RenderableRectangle();

	virtual void Render(Renderer *  renderer);

	Vec2<int> getSize();

	RenderableObject * clone();

private:

	Vec2 <int> size;

};

class RenderableRectangleFilled :
	public RenderableObject
{
public:

	RenderableRectangleFilled(Vec2 <int> pos, Vec2<int> sizeArg, Color color, Color fillColorArg);

	Vec2 <int> center();

	~RenderableRectangleFilled();

	virtual void Render(Renderer *  renderer);

	RenderableObject * clone();

	Vec2<int> getSize();

protected:
	
	Vec2 <int> size;

	Color fillColor;
};

