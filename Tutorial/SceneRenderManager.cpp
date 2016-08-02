#include "SceneRenderManager.h"



SceneRenderManager::SceneRenderManager(Renderer& render, Vec2<int> windowSize)
	:renderer(render),mainCamera(windowSize)
{

}


SceneRenderManager::~SceneRenderManager()
{
}

void SceneRenderManager::render()
{
	collect();
	renderer.Render(collected);
	collected.clear();
	return;
}

void SceneRenderManager::registerObject(SceneRenderableObject* obj)
{
	renderableObjects.push_back(obj);
}

Camera & SceneRenderManager::getCamera()
{
	return mainCamera;
}

void SceneRenderManager::collect()
{
	mainCamera.collect(renderableObjects, collected);
}
