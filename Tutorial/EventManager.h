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

	void sendMouseDownMessage(int button, Vec2<int> position);

	void sendMouseUpMessage(int button, Vec2<int> position);

	void sendMouseScrollMessage(int dir);

	void sendMouseMoveMessage(Vec2<int> position);

	std::vector<EventListener * > listeners;

};

