#include "SceneBase.h"
#include "SceneObject.h"
#include "EventManager.h"

SceneBase::SceneBase(Renderer& rendererArg)
	:renderer(rendererArg)
{
	eventManager = new EventManager(this);
}

void SceneBase::baseInit()
{
	sceneObjects = new std::vector<SceneObject*>();

	init();
}

std::vector<RenderableObject *> SceneBase::collect()
{
	std::vector<RenderableObject *> ret;
	//process position into screen position
	for (auto obj : *sceneObjects)
	{
		ret.push_back((RenderableObject *)obj);
	}
	return ret;
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
		renderer.Render(collect());
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
}

void SceneBase::addObject(SceneObject * obj)
{
	sceneObjects->push_back(obj);
}

void SceneBase::close()
{
	markedForClose = true;
}
