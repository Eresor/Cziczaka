#pragma once
#include <vector>
#include "Renderer.h"

class EventManager;

class SceneObject;

class SceneBase
{

public:

	SceneBase(Renderer& renderer);

	void baseInit();

	std::vector<RenderableObject*> collect();

	virtual void init()=0;

	bool run();

	~SceneBase();

	void addObject(SceneObject * obj);

	void close();

private:

	bool markedForClose = false;

	std::vector<SceneObject*> * sceneObjects;

	Renderer& renderer;
	
	void Update();

	EventManager * eventManager;

};

