#ifndef __COMMON_MATH_H__
#define __COMMON_MATH_H__

#include "cocos2d.h"

USING_NS_CC;

class Math
{
public:
	// trigonometric
	static const float PI;
	static float deg2rad(float a) { return a * PI / 180; }
	static float sin_d(float a) { return sin(a * PI / 180); }
	static float cos_d(float a) { return cos(a * PI / 180); }
	static float tan_d(float a) { return tan(a * PI / 180); }

	static float getRotation(const Vec2& dir);
	static float getRotation(const Vec2& from, const Vec2& to);
	static Vec2 getVector(float rotation);

	// random
	static void randomize();
	static bool random();
	static int random(int max);
	static int random(int min, int max);
	static float random(float min, float max);

	//array
	static int getMinIndex(float values[], int count, std::function<bool(float)> condition);
};

//line
struct Line
{
public:
	Vec2 A;
	Vec2 B;

public:
	Line() : A(0, 0), B(0, 1) {}
	Line(const Vec2& A, const Vec2& B)
	{
		CCASSERT(A != B, "not line!");
		this->A = A;
		this->B = B;
	}
	Line(const Vec2& A, float rotation)
	{
		this->A = A;
		this->B = A + Vec2::forAngle(Math::deg2rad(90 - rotation));
	}

	void set(const Vec2& A, const Vec2& B)
	{
		CCASSERT(A != B, "not line!");
		this->A = A;
		this->B = B;
	}
	void set(const Vec2& A, float rotation)
	{
		this->A = A;
		this->B = A + Vec2::forAngle(Math::deg2rad(90 - rotation));
	}

	static Line fromTwoPoints(const Vec2& point1, const Vec2& point2)
	{
		return Line(point1, point2);
	}
	static Line fromOnePointAndRotation(const Vec2& point, float rotation)
	{
		return Line(point, rotation);
	}

	Vec2 getDir() const { return B - A; }

	float getRotation() const { return Math::getRotation(A, B); }

	void getPoint(float t, Vec2& P) const { P.x = A.x + (B.x - A.x) * t; P.y = A.y + (B.y - A.y) * t; }

	Vec2 getPoint(float t) const { return Vec2(A.x + (B.x - A.x) * t, A.y + (B.y - A.y) * t); }

	float getT(float dist) const { return dist / (B - A).length(); }

	float getT(const Vec2& P) const { return (P.x - A.x) / (B.x - A.x); }

	float distanceFrom(const Vec2& point, float* pS = nullptr) const;

	bool intersectWithLine(const Line& other, float* s = nullptr, float* t = nullptr) const;

	bool intersectWithLine(const Line& other, Vec2* P = nullptr) const;

	bool intersectWithCircle(const Vec2& center, float radius, float* t1 = nullptr, float* t2 = nullptr) const;

	bool intersectWithCircle(const Vec2& center, float radius, Vec2* P = nullptr, Vec2* Q = nullptr) const;
};

#endif //__COMMON_MATH_H__