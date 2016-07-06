#include "EventManager.h"

EventManager::EventManager(SceneBase * sc)
	:scene(sc)
{
}

void EventManager::processSDLEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
		case SDL_QUIT:
			scene->close();
			break;

		case SDL_KEYDOWN:
			sendKeyDownMessage(event.key.keysym.scancode);
			break;

		default:
			break;
		}
	}
}

void EventManager::sendKeyDownMessage(SDL_BUTTON_ID_TYPE key)
{
	for (auto obj : listeners)
	{
		obj->KeyDown(key);
	}
}

void EventManager::regiesterListener(EventListener * el)
{
	listeners.push_back(el);
}


EventManager::~EventManager()
{
}
