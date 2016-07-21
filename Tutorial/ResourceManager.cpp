#include "ResourceManager.h"



void ResourceManager::regiesterResource(char * name, Resource * resource)
{
	iResources.insert(std::pair<char*, Resource *>(name, resource));
}

Resource * ResourceManager::getResourceWithName(char * name)
{
	return iResources.at(name);
}

ResourceManager::ResourceManager()
{
}

ResourceManager::ResourceManager(const ResourceManager &)
{
}

ResourceManager & ResourceManager::operator=(const ResourceManager &)
{
	return *this;
}


ResourceManager::~ResourceManager()
{
}
