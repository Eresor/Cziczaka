#include "ResourceTexture.h"



ResourceTexture::ResourceTexture()
	:Resource(),texture(nullptr)
{
}

ResourceTexture::ResourceTexture(const ResourceTexture& other)
	:texture(other.texture)
{
	initialized = other.initialized;
}

ResourceTexture::ResourceTexture(ResourceTexture && other)
{
	ResourceTexture::swap(*this, other);
}

ResourceTexture& ResourceTexture::operator=(ResourceTexture other)
{
	ResourceTexture::swap(*this, other);
	return *this;
}

ResourceTexture::ResourceTexture(const std::string& dir, SDL_Renderer * renderer)
	: Resource(),texture(nullptr)
{
	LoadResource(dir, renderer);
}

bool ResourceTexture::good()
{
	return initialized && texture != nullptr;
}

bool ResourceTexture::LoadResource(const std::string& dir, SDL_Renderer * renderer)
{
	if (initialized)
	{
		DEBUG_LOG("Trying to load resource in already initialized instantion.");
		return false;
	}

	SDL_Surface * surface = IMG_Load(dir.c_str());
	if (surface == nullptr)
	{
		DEBUG_LOG("Missing directory.");
		return false;
	}

	//texture=std::make_shared<SDL_Texture>(SDL_CreateTextureFromSurface(renderer, surface), SDL_DestroyTexture);
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

bool ResourceTexture::Destroy()
{
	if (initialized && texture.unique())
	{
		SDL_DestroyTexture(texture.get());
		texture.reset();
		return true;
	}
	else
	{
		DEBUG_LOG("Trying to destroy texture with more than one references");
		return false;
	}
}

SDL_Texture * ResourceTexture::getTexture()
{
	return texture.get();
}

ResourceTexture::~ResourceTexture()
{
}

void ResourceTexture::swap(ResourceTexture& r1, ResourceTexture& r2)
{
	Resource::swap(r1, r2);
	r1.texture.swap(r2.texture);
}
