#include "Camera.h"
#include "SceneRenderableObject.h"


Camera::Camera(Vec2<int> cWindowSize)
	:cameraWindowSize(cWindowSize),scale(1.0f)
{
}


Camera::~Camera()
{
}

void Camera::collect(std::vector<SceneRenderableObject*>& renderableObjects, std::vector<RenderableObject*>& collected)
{
	for (auto obj : renderableObjects)
	{
		RenderableObject * curr = obj->getRenderableObject();
		curr->setPosition(sceneToCameraPosition(obj->getPosition()));
		curr->setScale(Vec2<float>(scale*obj->getScale().x,scale*obj->getScale().y));
		if (isInsideCameraBox(curr->getPosition(),curr->getSize()))
		{
			collected.push_back(curr);
		}
	}
}

void Camera::setScale(float scale)
{
	this->scale = scale;
}

void Camera::setPosition(Vec2<float> pos)
{
	this->position = pos;
}

Vec2<float> Camera::getPosition()
{
	return position;
}

float Camera::getScale()
{
	return scale;
}

Vec2<int> Camera::sceneToCameraPosition(Vec2<float> objectPosition)
{
	return Vec2<int>(scale*(objectPosition.x-position.x),(-1)*scale*(objectPosition.y-position.y));
}

bool Camera::isInsideCameraBox(Vec2<int> position, Vec2<int> size)
{
	return position.x+size.x > 0 && position.x < cameraWindowSize.x && 
		position.y + size.y > 0 && position.y < cameraWindowSize.y;
}
