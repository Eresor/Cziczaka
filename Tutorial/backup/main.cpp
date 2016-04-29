#include <SDL.h>
#include "Utils.h"
#include "Window.h"
#include "ResourceFont.h"
#include "ResourceFontTexture.h"

void test()
{
	Window * win = new Window("okno", 800, 600, WINDOW_DEFAULT);

	ResourceFont font(ResourceFont("IsiniScript.ttf", 50));

	ResourceFontTexture text("witaj swiecie", font, win->getRenderer()->getSDLRenderer(), Color::COLOR_WHITE);

	bool close = false;

	while (!close)
	{
		SDL_RenderClear(win->getRenderer()->getSDLRenderer());
		SDL_RenderCopy(win->getRenderer()->getSDLRenderer(), text.getTexture(), NULL, NULL);
		SDL_RenderPresent(win->getRenderer()->getSDLRenderer());
	}

	delete win;

}

int main(int argc, char* args[])
{
	Color c = { 0x00,0xAA,0xBB,0xCC };
	test();
	return 0;
}