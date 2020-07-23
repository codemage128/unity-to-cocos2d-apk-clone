#include "Math.h"
#include <math.h>

USING_NS_CC;

// trigonometric

const float Math::PI = 3.14159265358979323846f;

float Math::getRotation(const Vec2& dir)
{
	float angle = atan2(dir.x, dir.y);
	return angle * 180 / PI;
}

float Math::getRotation(const Point& from, const Point& to)
{
	Point dir = to - from;
	float angle = atan2(dir.x, dir.y);
	return angle * 180 / PI;
}

Vec2 Math::getVector(float rotation)
{
	return Vec2::forAngle((90 - rotation) * PI / 180);
}

// random

void Math::randomize()
{
	srand(time(nullptr));
}

bool Math::random()
{
	return rand() % 2 == 0;
}

int Math::random(int max)
{
	return random(0, max);
}

int Math::random(int min, int max)
{
	if (min >= max)
		return min;
	return min + rand() % (max - min);
}

float Math::random(float min, float max)
{
	return min + (max - min) * (rand() % 4096) / 4095;
}

//array

int Math::getMinIndex(float values[], int count, std::function<bool(float)> condition)
{
	int index = -1;
	float min = FLT_MAX;
	for (int i = 0; i < count; i++)
	{
		float& value = values[i];
		if (condition(value) && value < min)
		{
			index = i;
			min = value;
		}
	}
	return index;
}

// line

float Line::distanceFrom(const Vec2& point, float* pS) const
{
	Vec2 D(point.x + A.y - B.y, point.y + B.x - A.x);
	float s;
	if (Vec2::isLineIntersect(A, B, point, D, &s))
	{
		if (pS)
			*pS = s;
		Vec2 P;
		getPoint(s, P);
		P -= point;
		return P.length();
	}
	return 0;
}

bool Line::intersectWithLine(const Line& other, float* s, float* t) const
{
	return Vec2::isLineIntersect(this->A, this->B, other.A, other.B, s, t);
}

bool Line::intersectWithLine(const Line& other, Vec2* P) const
{
	float s;
	bool ret = Vec2::isLineIntersect(this->A, this->B, other.A, other.B, &s);
	if (ret && P)
		this->getPoint(s, *P);
	return ret;
}

bool Line::intersectWithCircle(const Vec2& center, float radius, float* t1, float* t2) const
{
	Vec2 v = this->B - this->A;//directional vector
	float v2 = v.lengthSquared();//length squared of directional vector
	Vec2 q = this->A - center;

	float D = v2 * radius * radius - pow(v.x * q.y - v.y * q.x, 2);

	if (D < 0)
		return false;

	if (t1) *t1 = (-(v.x * q.x + v.y * q.y) - sqrt(D)) / v2;
	if (t2) *t2 = (-(v.x * q.x + v.y * q.y) + sqrt(D)) / v2;

	return true;
}

bool Line::intersectWithCircle(const Vec2& center, float radius, Vec2* P, Vec2* Q) const
{
	float t1, t2;
	bool ret = intersectWithCircle(center, radius, &t1, &t2);
	if (ret)
	{
		if (P) this->getPoint(t1, *P);
		if (Q) this->getPoint(t2, *Q);
	}
	return ret;
}
