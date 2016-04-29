#pragma once
#include "RenderableObject.h"
class RenderableRectangle :
	public RenderableObject
{
public:

	RenderableRectangle(Vec2 <uint> pos, Vec2<uint> sizeArg, Color color);

	Vec2 <uint> center();
	
	~RenderableRectangle();

	virtual void Render(Renderer *  renderer);

private:

	Vec2 <uint> size;

};

class RenderableRectangleFilled :
	public RenderableObject
{
public:

	RenderableRectangleFilled(Vec2 <uint> pos, Vec2<uint> sizeArg, Color color, Color fillColorArg);

	Vec2 <uint> center();

	~RenderableRectangleFilled();

	virtual void Render(Renderer *  renderer);

protected:
	
	Vec2 <uint> size;

	Color fillColor;
};

