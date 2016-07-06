#pragma once
#include "RenderableObject.h"
#include "SceneBase.h"

class SceneObject : RenderableObject
{
public:
	SceneObject(SceneBase * sc);
	
	~SceneObject();

	virtual void Update()=0;

private:

	SceneBase * parentScene;
};

