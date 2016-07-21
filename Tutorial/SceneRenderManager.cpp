#include "SceneRenderManager.h"



SceneRenderManager::SceneRenderManager(Renderer& render, Vec2<uint> windowSize)
	:renderer(render)
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

void SceneRenderManager::collect()
{
	mainCamera.collect(renderableObjects, collected);
}
