#pragma once
#include "RenderableObject.h"
#include "ResourceTexture.h"
class RenderableTexture :
	public RenderableObject
{
public:

	RenderableTexture(Vec2<int> pos, ResourceTexture texture, float a=0.0, Uint8 alpha=255);

	~RenderableTexture();

	Vec2<int> center();

	RenderableObject * clone();

	virtual void Render(Renderer  * renderer);

	Vec2<int> getSize();

protected:

	float angle;

	ResourceTexture texture;

	Uint8 alpha;

	Vec2<int> size;

	Uint32 format;

};

