#pragma once

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>

namespace Random
{
static unsigned long seed = 0;
static	inline void Feed()
	{
		srand(unsigned (std::time(0) + seed));
		seed++;
	}
	inline int RandInt()
	{
		Feed();
		return int(rand());
	}

	inline int RandInt(unsigned i)
	{
		Feed();
		return int(rand() %(i+1) );
	}
	inline int RandInt(int s, int e)
	{
		Feed();
		return int((rand() % (abs(e-s)+1))+std::min(s, e));
	}
	inline float RandFloat()
	{
		Feed();
		return (float(rand())/(float)std::numeric_limits<int>::max());
	}
	inline float RandFloat(float fl)
	{
		Feed();
		return (float(rand())/(float)std::numeric_limits<int>::max())*fl;
	}
	inline float RandFloat(float st, float en)
	{
		Feed();
		return (float(rand())/(float)std::numeric_limits<int>::max())*std::abs(en-st)+std::min(st, en);
	}
}