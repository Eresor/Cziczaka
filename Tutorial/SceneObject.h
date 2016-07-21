#pragma once
#include "RenderableObject.h"
#include "SceneBase.h"

class SceneObject
{
public:
	SceneObject();
	
	~SceneObject();

	virtual void Update();

	Vec2<float> getPosition();

	void setPosition(Vec2<float>);

protected:


	Vec2<float> position;
};

