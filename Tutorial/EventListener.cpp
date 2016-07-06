#include "EventListener.h"
#include "EventManager.h"


EventListener::EventListener(EventManager * em)
{
	em->regiesterListener(this);
}


EventListener::~EventListener()
{
}
