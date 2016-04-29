#include "Renderer.h"

Renderer::Renderer(SDL_Window * window)
	:renderer(SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED))
{

}

Renderer::~Renderer()
{
	if (renderer != nullptr)
	{
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;
	}
}

SDL_Renderer * Renderer::getSDLRenderer()
{
	return renderer;
}

void Renderer::Render(std::vector<RenderableObject> objects)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	for (auto obj : objects)
	{
		obj.Render();
	}
	SDL_RenderPresent(renderer);
}
