#pragma once 

#include <cmath>
#include<cstdlib>
#include<limits>

namespace oaa {
	
	class CSTD // standared library
	{
			protected:
			CSTD(unsigned s)
			{
				std::srand(s);
			}
			inline void seed(int s)
			{
				std::srand(s);
			}
			inline unsigned next()
			{
				return std::rand();
			}
	};
	
//class LCG // to do later
//{
//	protected:
//		LCG(unsigned s)
//			:last(s){}
//		inline unsigned next()
//		{
//			last = (a*last+c)%m;
//			return last;
//		}
//	private:
//		unsigned last;
//		unsigned m = 9;//std::pow(2, sizeof(unsigned)*8);
//		unsigned a = 2;
//		unsigned c = 0;
//};

	
	template<class PRNG>
	class Random: public PRNG
	{
		public:
			Random(int seed);
			inline void SetSeed(int seed);
			inline int GetRandom();
			float GetRandFloat(float s=0, float e=0);
			int GetRandInt(int s, int e);
	};

	template<class PRNG>
	float Random<PRNG>::GetRandFloat(float s, float e)
	{
float n = GetRandom()/(float)std::numeric_limits<int>::max();
		if(!(s||e))
		{
			return n;
		}
		if(e<s)
		{
			int w=s;
			s=e;
			e=w;
		}
	
		e-=s;
		
		return s+e*n;


	}
	template<class PRNG>
	int Random<PRNG>::GetRandInt(int s, int e)
	{
		if(e<s)
		{
			int w=s;
			s=e;
			e=w;
		}
	
		e-=s;
		
		return s+std::round(e*GetRandFloat());

	}
	
	template<class PRNG>
	Random<PRNG>::Random(int seed)
		:PRNG(seed)
	{
	}
	template<class PRNG>
	inline void Random<PRNG>::SetSeed(int seed)
	{
		PRNG::seed();
	}
	template<class PRNG>
	inline int Random<PRNG>::GetRandom()
	{
		return PRNG::next();
	}
}
