#include "Window.h"

Window::Window(std::string name, int w, int h, WindowProperties props)
	:window(SDL_CreateWindow(name.c_str(),SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,w,h,props))
{
	this->renderer = new Renderer(window);
}

Window::Window(const Window& other)
{
	int w, h;
	SDL_GetWindowSize(other.window, &w, &h);
	Uint32 flags;
	flags = SDL_GetWindowFlags(other.window);
	std::string name(SDL_GetWindowTitle(other.window));

	this->window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);
	this->renderer = new Renderer(other.window);
}

Window & Window::operator=(Window & other)
{
	int w, h;
	SDL_GetWindowSize(other.window, &w, &h);
	Uint32 flags;
	flags = SDL_GetWindowFlags(other.window);
	std::string name(SDL_GetWindowTitle(other.window));

	this->window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);
	this->renderer = new Renderer(other.window);
	return *this;
}

Renderer * Window::getRenderer()
{
	return renderer;
}

Window::~Window()
{
	if (renderer != nullptr)
	{
		delete renderer;
		renderer = nullptr;
	}
	if (window != nullptr)
	{
		SDL_DestroyWindow(window);
		window = nullptr;
	}
}
