#pragma once
#include <SDL.h>
#include <vector>
#include "RenderableObject.h"

class Renderer
{
public:
	
	Renderer(SDL_Window *);

	~Renderer();

	SDL_Renderer * getSDLRenderer();

	void Render(std::vector<RenderableObject>);

private:

	SDL_Renderer * renderer;

	Renderer(const Renderer&);

	Renderer& operator=(const Renderer&)
	{

	};
};

