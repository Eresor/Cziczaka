#pragma once
#include <vector>
#include "Utils.h"
#include "Renderer.h"

class EventManager;

class SceneObject;

class SceneRenderManager;

class SceneBase
{

public:

	SceneBase(Renderer& rendererArg, Vec2<int> sceneWindowSize);

	void baseInit();

	virtual void init()=0;

	bool run();

	~SceneBase();

	void close();

	void registerSceneObject(SceneObject *);

private:

	bool markedForClose = false;

	std::vector<SceneObject*> * sceneObjects;
	
	void Update();

	EventManager * eventManager;

	SceneRenderManager * renderManager;

};

