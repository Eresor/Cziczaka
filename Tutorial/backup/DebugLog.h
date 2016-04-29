#pragma once
#include <vector>
#include <string>
#include <stdio.h>

#define DEBUG
#ifdef DEBUG
	#define DEBUG_LOG(text) DebugLog::getInstance().log(text); 
#else
	#define DEBUG_LOG(text)
#endif

class DebugLog
{
public:

	std::vector<std::string> logs;

	void log(char* text)
	{
		logs.push_back(std::string(text));
		printf(text);
	}

	static DebugLog& getInstance()
	{
		static DebugLog instance;
		return instance;
	}

private:
	DebugLog();

	DebugLog(const DebugLog&);

	DebugLog& operator=(const DebugLog &)
	{
		return *this;
	}

	~DebugLog();
};

