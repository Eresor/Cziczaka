#include "Camera.h"
#include "SceneRenderableObject.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::collect(std::vector<SceneRenderableObject*>& renderableObjects, std::vector<RenderableObject*> collected)
{
	for (auto obj : renderableObjects)
	{
		RenderableObject * curr = obj->getRenderableObject();
		curr->setPosition(sceneToCameraPosition(obj->getPosition()));
		curr->setScale(Vec2<float>(scale*obj->getScale().x,scale*obj->getScale().y));
		if (isInsideCameraBox())
		{
			collected.push_back(curr);
		}
	}
}

Vec2<uint> Camera::sceneToCameraPosition(Vec2<float> objectPosition)
{
	return Vec2<uint>(scale*(objectPosition.x-position.x),scale*(objectPosition.y-position.y));
}

bool Camera::isInsideCameraBox(Vec2<float> position, Vec2<float> size)
{
	return false;
}
