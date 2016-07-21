#pragma once
#include "RenderableObject.h"
#include "ResourceTexture.h"
class RenderableTexture :
	public RenderableObject
{
public:

	RenderableTexture(Vec2<uint> pos, ResourceTexture texture, float a=0.0, Uint8 alpha=255);

	~RenderableTexture();

	Vec2<uint> center();

	RenderableObject * clone();

	virtual void Render(Renderer  * renderer);

protected:

	float angle;

	ResourceTexture texture;

	Uint8 alpha;

	Vec2<uint> size;

	Uint32 format;

};

