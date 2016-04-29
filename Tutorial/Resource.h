#pragma once
#include <string>
#include "Utils.h"
#include "DebugLog.h"

class Resource
{
public:

	Resource();
	
	virtual bool good()=0;

	virtual bool Destroy() = 0;
	
	virtual ~Resource()=default;

protected:
	bool initialized;

	std::string directory;
};

