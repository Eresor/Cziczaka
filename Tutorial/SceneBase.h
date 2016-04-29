#pragma once
#include <vector>
#include "Renderer.h"

class SceneObject;

class SceneBase
{

public:

	SceneBase(Renderer renderer);

	void baseInit();

	std::vector<RenderableObject*> collect();

	virtual void init()=0;

	bool run();

	~SceneBase();

private:

	std::vector<SceneObject*> * sceneObjects;

	Renderer renderer;
	
};

