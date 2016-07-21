#pragma once
#include "ResourceTexture.h"
#include "ResourceFont.h"

class ResourceFontTexture :
	public ResourceTexture
{
public:

	ResourceFontTexture(const std::string& text, ResourceFont font, SDL_Renderer * renderer, Color color);
	
	ResourceFontTexture(const ResourceFontTexture&);

	ResourceFontTexture(ResourceFontTexture&&);

	ResourceFontTexture& operator=(const ResourceFontTexture);

	bool LoadResource(const std::string& text, ResourceFont font, SDL_Renderer * renderer, Color color);
	
	~ResourceFontTexture();

private:
	std::string text;

	static void swap(ResourceFontTexture r1, ResourceFontTexture r2);
};

