#include "EventListener.h"
#include "EventManager.h"


EventListener::EventListener()
{
}


EventListener::~EventListener()
{
}

void EventListener::KeyDown(SDL_BUTTON_ID_TYPE)
{
}

void EventListener::MouseDown(int button, Vec2<int> position)
{
}

void EventListener::MouseUp(int button, Vec2<int> position)
{
}

void EventListener::MouseScroll(int direction)
{
}

void EventListener::MouseMove(Vec2<int> position)
{
}
