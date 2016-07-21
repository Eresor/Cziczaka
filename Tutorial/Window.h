#pragma once
#include <SDL.h>
#include <string>
#include "Utils.h"
#include "Renderer.h"

enum WindowProperties
{
	WINDOW_DEFAULT = NULL,
	WINDOW_FULLSCREEN = SDL_WINDOW_FULLSCREEN,
	WINDOW_MINIMIZED = SDL_WINDOW_MINIMIZED,
	WINDOW_MAXIMIZED = SDL_WINDOW_MAXIMIZED
};

class Window
{
public:

	Window(std::string name, int w, int h, WindowProperties props);

	Window(const Window&);

	Window& operator=(Window&);

	Renderer * getRenderer();

	~Window();

private:
	SDL_Window * window;
	Renderer * renderer;
};

