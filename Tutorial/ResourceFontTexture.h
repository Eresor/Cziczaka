#pragma once
#include "ResourceTexture.h"
#include "ResourceFont.h"

class ResourceFontTexture :
	public ResourceTexture
{
public:

	ResourceFontTexture(std::string text, ResourceFont font, SDL_Renderer * renderer, Color color);
	
	ResourceFontTexture(const ResourceFontTexture&);

	ResourceFontTexture& operator=(const ResourceFontTexture&);

	bool LoadResource(std::string text, ResourceFont font, SDL_Renderer * renderer, Color color);
	
	~ResourceFontTexture();

private:
	std::string text;
};

