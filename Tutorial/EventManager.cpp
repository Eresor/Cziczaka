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

		case SDL_MOUSEBUTTONDOWN:
			sendMouseDownMessage(event.button.button, Vec2<int>(event.button.x, event.button.y));
			break;

		case SDL_MOUSEBUTTONUP:
			sendMouseUpMessage(event.button.button, Vec2<int>(event.button.x, event.button.y));
			break;

		case SDL_MOUSEWHEEL:
			sendMouseScrollMessage(event.wheel.y);
			break;

		case SDL_MOUSEMOTION:
			sendMouseMoveMessage(Vec2<int>(event.motion.x, event.motion.y));
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

void EventManager::sendMouseDownMessage(int button, Vec2<int> position)
{
	for (auto obj : listeners)
	{
		obj->MouseDown(button, position);
	}
}

void EventManager::sendMouseUpMessage(int button, Vec2<int> position)
{
	for (auto obj : listeners)
	{
		obj->MouseUp(button, position);
	}
}

void EventManager::sendMouseScrollMessage(int direction)
{
	for (auto obj : listeners)
	{
		obj->MouseScroll(direction);
	}
}

void EventManager::sendMouseMoveMessage(Vec2<int> position)
{
	for (auto obj : listeners)
	{
		obj->MouseMove(position);
	}
}

void EventManager::regiesterListener(EventListener * el)
{
	listeners.push_back(el);
}


EventManager::~EventManager()
{
}
