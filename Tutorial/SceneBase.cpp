#include "SceneBase.h"
#include "SceneObject.h"


SceneBase::SceneBase(Renderer rendererArg)
	:renderer(rendererArg)
{
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

	bool finish = false;
	while (!finish)
	{
		// process input
		// process logic
		// render
		renderer.Render(collect());
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
}
