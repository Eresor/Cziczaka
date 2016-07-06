#include "ResourceFont.h"



ResourceFont::ResourceFont(const std::string& dir, uint h)
	:height(h)
{
	LoadResource(dir, h);
}


bool ResourceFont::LoadResource(const std::string& dir, uint heigh)
{
	if (initialized)
	{
		if (font.use_count() >0)
		{
			DEBUG_LOG("Trying to reinitialized font in use.");
			return false;
		}
	}
	TTF_Init();
	font.reset(TTF_OpenFont(dir.c_str(), height), TTF_CloseFont);
	if (font == nullptr)
	{
		DEBUG_LOG("Failed to create texture from surface");
		return false;
	}
	initialized = true;
	return true;
}

ResourceFont::ResourceFont(ResourceFont& res)
	:font(res.font)
{
	initialized = res.initialized;
}

ResourceFont& ResourceFont::operator=(ResourceFont& res)
{
	initialized = res.initialized;
	font = res.font;
	return *this;
}

bool ResourceFont::good()
{
	return initialized;
}

bool ResourceFont::Destroy()
{
	if (initialized && font.unique())
	{
		TTF_CloseFont(font.get());
		font.reset();
		return true;
	}
	else
	{
		DEBUG_LOG("Trying to destroy texture with more than one references");
		return false;
	}
}

TTF_Font * ResourceFont::getFont()
{
	return font.get();
}

ResourceFont::~ResourceFont()
{
}
