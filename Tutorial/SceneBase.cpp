#include "SceneBase.h"
#include "SceneRenderableObject.h"
#include "EventManager.h"
#include "SceneRenderManager.h"

SceneBase::SceneBase(Renderer& rendererArg, Vec2<uint> sceneWindowSize)
{
	eventManager = new EventManager(this);
	renderManager = new SceneRenderManager(rendererArg,sceneWindowSize );
}

void SceneBase::baseInit()
{
	sceneObjects = new std::vector<SceneObject*>();

	init();
}

bool SceneBase::run()
{
	const int TicksPerSecond = 25;
	const int SkipTicks = 1000 / TicksPerSecond;
	const int MaxFrameskip = 10;
	int loops;
	float interpolation;
	
	Uint32 nextTicks = SDL_GetTicks();

	while (!markedForClose)
	{
		loops = 0;
		//while (ticks < next_ticks && count<MAX)
			// process input
			// process logic
		//
		while (SDL_GetTicks() < nextTicks && loops < MaxFrameskip)
		{
			//Input
			eventManager->processSDLEvents();

			Update();
			nextTicks += SkipTicks;
			loops++;
		}
		interpolation = float(SDL_GetTicks() + SkipTicks - nextTicks) / float(SkipTicks);
		// render with interpolation
		renderManager->render();
	}
	return true;
}

void SceneBase::Update()
{
	for (auto obj : *sceneObjects)
	{
		obj->Update();
	}
}


SceneBase::~SceneBase()
{
	if (sceneObjects != nullptr)
	{
		for (std::vector<SceneObject*>::iterator iter = sceneObjects->begin(); iter < sceneObjects->end(); iter++)
		{
			if ((*iter) != nullptr)
			{
				delete *iter;
			}
		}
		delete sceneObjects;
	}
	if (eventManager != nullptr)
	{
		delete eventManager;
	}
	if (renderManager != nullptr)
	{
		delete renderManager;
	}
}

void SceneBase::close()
{
	markedForClose = true;
}

void SceneBase::registerSceneObject(SceneObject * obj)
{
	SceneRenderableObject * ren = dynamic_cast<SceneRenderableObject *>(obj);
	if (ren)
	{
		renderManager->registerObject(ren);
	}

	EventListener * el = dynamic_cast<EventListener *>(obj);
	if (el)
	{
		eventManager->regiesterListener(el);
	}

}
