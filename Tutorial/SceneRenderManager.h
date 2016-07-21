#pragma once
#include <vector>
#include "Renderer.h"
#include "Camera.h"
#include "SceneRenderableObject.h"

class SceneRenderManager
{
public:

	SceneRenderManager(Renderer& render, Vec2<uint> windowSize);
	
	~SceneRenderManager();

	void render();

	void registerObject(SceneRenderableObject* obj);

private:

	Renderer& renderer;

	std::vector<SceneRenderableObject *> renderableObjects;

	std::vector<RenderableObject*> collected;

	Camera mainCamera;

	void collect();
};

