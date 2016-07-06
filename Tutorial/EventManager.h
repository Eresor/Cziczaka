#pragma once
#include "SceneBase.h"
#include "EventListener.h"
#include "Utils.h"

class EventManager
{
public:

	EventManager(SceneBase * scene);
	
	~EventManager();

	void processSDLEvents();

	void regiesterListener(EventListener * el);

private:

	SceneBase * scene;

	void sendKeyDownMessage(SDL_BUTTON_ID_TYPE key);

	std::vector<EventListener * > listeners;

};

