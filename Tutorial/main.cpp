#include <SDL.h>
#include "Window.h"
#include "TestScene.h"

int main(int argc, char* args[])
{
	Window win("Test Scene", WIDTH, HEIGHT, WINDOW_DEFAULT);
	TestScene sc(*win.getRenderer());
	sc.start();
	return 0;
}