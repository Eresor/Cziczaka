#pragma once
#include <SDL.h>
typedef unsigned int uint;

struct Color
{
	union 
	{
		struct
		{
			Uint8 r;
			Uint8 g;
			Uint8 b;
			Uint8 a;
		};

		Uint32 color;
	};

	static const Color COLOR_BLACK;
	static const Color COLOR_WHITE;
};

template <typename T> class Vec2
{
public:

	union
	{
		struct 
		{
			T x;
			T y;
		};

		T _v[2];
	};


	Vec2(T xx, T yy)
		:x(xx), y(yy)
	{
	};

	Vec2()
		:x(0.0), y(0.0)
	{

	}
	
	~Vec2()
	{
	};
};