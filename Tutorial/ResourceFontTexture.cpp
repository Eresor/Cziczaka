#include "ResourceFontTexture.h"



ResourceFontTexture::ResourceFontTexture(const std::string& t, ResourceFont font, SDL_Renderer * renderer, Color color)
	:text(t)
{
	LoadResource(t, font, renderer, color);
}

bool ResourceFontTexture::LoadResource(const std::string& text, ResourceFont font, SDL_Renderer * renderer, Color color)
{
	if (initialized)
	{
		DEBUG_LOG("Trying to load resource in already initialized instantion.");
		return false;
	}
	SDL_Surface * surface = TTF_RenderText_Solid(font.getFont(), text.c_str(), {color.r,color.g,color.b,color.a});
	if (surface == nullptr)
	{
		DEBUG_LOG("Error loading surface from font.");
		return false;
	}

	texture.reset(SDL_CreateTextureFromSurface(renderer, surface), SDL_DestroyTexture);
	SDL_FreeSurface(surface);
	if (texture == nullptr)
	{
		DEBUG_LOG("Failed to create texture from surface");
		return false;
	}
	initialized = true;
	return true;
}

ResourceFontTexture::ResourceFontTexture(const ResourceFontTexture& other)
{
	texture = other.texture;
	text = other.text;
	initialized = other.initialized;
}

ResourceFontTexture& ResourceFontTexture::operator=(const ResourceFontTexture& other)
{
	texture = other.texture;
	text = other.text;
	initialized = other.initialized;
	return *this;
}

ResourceFontTexture::~ResourceFontTexture()
{

}
