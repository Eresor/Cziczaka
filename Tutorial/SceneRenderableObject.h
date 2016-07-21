#pragma once
#include "RenderableObject.h"
#include "SceneObject.h"

class SceneRenderableObject : public SceneObject
{
public:

	SceneRenderableObject(RenderableObject*&& obj);
	
	SceneRenderableObject(const SceneRenderableObject&);

	SceneRenderableObject& operator=(const SceneRenderableObject&);

	~SceneRenderableObject();

	RenderableObject * getRenderableObject();

	void setScale(Vec2<float> scale);

	Vec2<float> getScale();

protected:

	RenderableObject * renderableObject;

	Vec2<float> scale;
};

