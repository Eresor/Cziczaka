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

	~SceneBase();

	void close();

	void start();

	void registerSceneObject(SceneObject *);

protected:

	bool markedForClose = false;

	std::vector<SceneObject*> * sceneObjects;
	
	void Update();

	bool run();

	EventManager * eventManager;

	SceneRenderManager * renderManager;

};

