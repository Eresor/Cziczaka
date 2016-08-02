#pragma once
#include "Utils.h"

class EventManager;

class EventListener
{
public:

	EventListener();

	~EventListener();

	virtual void KeyDown(SDL_BUTTON_ID_TYPE);

	virtual void MouseDown(int button, Vec2<int> position);

	virtual void MouseUp(int button, Vec2<int> position);

	virtual void MouseScroll(int direction);

	virtual void MouseMove(Vec2<int> position);

};


