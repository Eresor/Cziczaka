#pragma once
#include "Resource.h"
#include <SDL_ttf.h>
#include <memory>

class ResourceFont :
	public Resource
{
public:

	ResourceFont(const std::string& dir, int heigh);

	ResourceFont(ResourceFont&);

	ResourceFont(ResourceFont&&);

	ResourceFont& operator=(ResourceFont);

	bool LoadResource(const std::string& dir, int heigh);

	~ResourceFont();
	
	bool Destroy();

	TTF_Font * getFont();

	bool good();
	
private:
	std::shared_ptr<TTF_Font> font;

	int height;

	static void swap(ResourceFont&, ResourceFont&);
};

