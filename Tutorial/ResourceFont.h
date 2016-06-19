#pragma once
#include "Resource.h"
#include <SDL_ttf.h>
#include <memory>

class ResourceFont :
	public Resource
{
public:

	ResourceFont(const std::string& dir, uint heigh);

	ResourceFont(ResourceFont&);

	ResourceFont& operator=(ResourceFont&);

	bool LoadResource(const std::string& dir, uint heigh);

	~ResourceFont();
	
	bool Destroy();

	TTF_Font * getFont();

	bool good();
	
private:
	std::shared_ptr<TTF_Font> font;

	bool initialized;

	uint height;
};

