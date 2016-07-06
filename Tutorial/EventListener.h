#pragma once
#include "Utils.h"

class EventManager;

class EventListener
{
public:

	EventListener(EventManager * em);

	~EventListener();

	virtual void KeyDown(SDL_BUTTON_ID_TYPE)=0;

};

