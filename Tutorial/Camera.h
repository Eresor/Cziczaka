#pragma once
#include "Utils.h"
#include "RenderableObject.h"
#include <vector>

class SceneRenderableObject;

class Camera
{
public:

	Camera();

	~Camera();

	void collect(std::vector<SceneRenderableObject*>& renderableObjects, std::vector<RenderableObject*> collected);

protected:

	Vec2<uint> sceneToCameraPosition(Vec2<float> position);

	Vec2<float> position;

	float scale;

	bool isInsideCameraBox(Vec2<float> position, Vec2<float> size);
};

