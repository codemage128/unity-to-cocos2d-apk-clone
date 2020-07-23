#ifndef __ENGINE_MATH_H__
#define __ENGINE_MATH_H__

#include "cocos2d.h"

namespace Mathf {
	static int Max(int a, int b) { return a > b ? a : b; }
	static int Min(int a, int b) { return a < b ? a : b; }
	static float Max(float a, float b) { return a > b ? a : b; }
	static float Min(float a, float b) { return a < b ? a : b; }
	static float Clamp(float value, float min, float max) { if(value < min) value = min; if(value>max) value = max; return value; }
	static float Clamp01(float value) { return Clamp(value, 0.0f, 1.0f); }
	static int Clamp(int value, int min, int max) { if(value < min) value = min; if(value>max) value = max; return value; }
	static float Abs(float a) { if(a >= 0.0f) return a; return -a; }
	static int Abs(int a) { if(a >= 0) return a; return -a; }

	class Random {
	public:
		static int Range(int a/*inclusive*/, int b/*exclusive*/);
		static float Range(float a/*inclusive*/, float b/*inclusive*/);
		static void Init();
	};
}

#endif //__ENGINE_MATH_H__