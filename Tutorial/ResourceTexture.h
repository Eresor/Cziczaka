#pragma once
#include "Resource.h"
#include <SDL.h>
#include <SDL_image.h>
#include <memory>

class ResourceTexture
	:public Resource
{
public:

	ResourceTexture();

	ResourceTexture(const ResourceTexture&);

	ResourceTexture& operator=(const ResourceTexture&);

	ResourceTexture(const std::string& dir, SDL_Renderer * renderer);

	bool LoadResource(const std::string& dir, SDL_Renderer * renderer);

	bool Destroy();

	bool good();

	SDL_Texture * getTexture();
	
	~ResourceTexture();

protected:
	std::shared_ptr <SDL_Texture> texture;
};

