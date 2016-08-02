#pragma once
#include "Utils.h"
#include "RenderableObject.h"
#include <vector>

class SceneRenderableObject;

class Camera
{
public:

	Camera(Vec2<int> cWindowSize);

	~Camera();

	void collect(std::vector<SceneRenderableObject*>& renderableObjects, std::vector<RenderableObject*>& collected);

	void setScale(float scale);

	void setPosition(Vec2<float> pos);

	Vec2<float> getPosition();

	float getScale();

protected:

	Vec2<int> sceneToCameraPosition(Vec2<float> position);

	Vec2<float> position;

	Vec2<int> cameraWindowSize;

	float scale;

	bool isInsideCameraBox(Vec2<int> position, Vec2<int> size);
};

