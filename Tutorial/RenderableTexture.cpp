#include "RenderableTexture.h"


RenderableTexture::RenderableTexture(Vec2<int> pos, ResourceTexture texture, float a, Uint8 alph)
	:RenderableObject(pos), texture(texture),alpha(alph),angle(a)
{
	int access;
	if (!texture.good())
	{
		DEBUG_LOG("Unitialized texture used");
	}
	SDL_SetTextureBlendMode(texture.getTexture(), SDL_BLENDMODE_BLEND);
	SDL_QueryTexture(texture.getTexture(), &(this->format), &access,reinterpret_cast<int*>(&(this->size.x)), reinterpret_cast<int*>(&(this->size.y)));
}


Vec2<int> RenderableTexture::center()
{
	return Vec2<int>(position.x + size.x / 2, position.y + size.y / 2);
}

RenderableObject * RenderableTexture::clone()
{
	return new RenderableTexture(*this);
}


RenderableTexture::~RenderableTexture()
{
}

void RenderableTexture::Render(Renderer  * renderer)
{
	SDL_SetTextureAlphaMod(texture.getTexture(), alpha);
	SDL_Rect source = { 0,0,size.x,size.y };
	SDL_Rect dest = { position.x, position.y, size.x*scale.x, size.y*scale.x };
	Vec2<int> cen = center();
	SDL_Point center = { cen.x, cen.y };
	SDL_RenderCopyEx(renderer->getSDLRenderer(), texture.getTexture(), &source, &dest, angle, &center, SDL_FLIP_NONE);
}

Vec2<int> RenderableTexture::getSize()
{
	return Vec2<int>(size.x*scale.x,size.y*scale.y);
}

