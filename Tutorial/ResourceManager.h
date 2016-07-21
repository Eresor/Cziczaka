#pragma once
#include "Resource.h"
#include <unordered_map>

class ResourceManager
{
public:
	
	static ResourceManager& getInstance()
	{
		static ResourceManager instance;
		return instance;
	}

	void regiesterResource(char* name, Resource * resource);

	Resource * getResourceWithName(char* name);

private:

	ResourceManager();

	ResourceManager(const ResourceManager&);

	ResourceManager& operator=(const ResourceManager &);

	~ResourceManager();

	std::unordered_map<char*, Resource *> iResources;


};

