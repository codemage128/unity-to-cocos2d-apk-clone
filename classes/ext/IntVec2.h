#ifndef __COMMON_INTVEC2_H__
#define __COMMON_INTVEC2_H__

#include <math.h>

struct IntVec2
{
public:
	int i;
	int j;

	IntVec2()						{ i = j = 0; }
	IntVec2(int i, int j)			{ this->i = i; this->j = j; }
	IntVec2(const int* array)		{ this->i = array[0]; this->j = array[1]; }
	IntVec2(const IntVec2& copy)	{ i = copy.i; j = copy.j; }

	~IntVec2() {}

	void set(int i, int j)			{ this->i = i; this->j = j; }
	void set(const int* array)		{ this->i = array[0]; this->j = array[1]; }
	void set(const IntVec2& copy)	{ i = copy.i; j = copy.j; }
	void setZero()					{ i = j = 0; }

	void add(int s)							{ i += s; j += s; }
	void add(const IntVec2& v)				{ i += v.i; j += v.j; }
	void multiply(int s)					{ i *= s; j *= s; }
	void multiply(const IntVec2& v)			{ i *= v.i; j *= v.j; }
	void subtract(int s)					{ i -= s; j -= s; }
	void subtract(const IntVec2& v)			{ i -= v.i; j -= v.j; }

	void negate()							{ i = -i; j = -j; }
	IntVec2 getNegate() const				{ return IntVec2(-i, -j); }
	void abs()								{ if (i < 0) i = -i; if (j < 0) j = -j; }
	IntVec2 getAbs() const					{ return IntVec2(i >= 0 ? i : -i, j >= 0 ? j : -j); }
	int sum() const							{ return i + j; }

	const IntVec2 operator+(const IntVec2& v) const		{ return IntVec2(i + v.i, j + v.j); }
	IntVec2& operator+=(const IntVec2& v)				{ i += v.i; j += v.j; return *this; }
	IntVec2& operator+=(int s)							{ i += s; j += s; return *this; }
	const IntVec2 operator-(const IntVec2& v) const		{ return IntVec2(i - v.i, j - v.j); }
	IntVec2& operator-=(const IntVec2& v)				{ i -= v.i; j -= v.j; return *this; }
	IntVec2& operator-=(int s)							{ i -= s; j -= s; return *this; }
	const IntVec2 operator-() const						{ return IntVec2(-i, -j); }
	const IntVec2 operator*(int s) const				{ return IntVec2(i * s, j * s); }
	const IntVec2 operator*(const IntVec2& v) const		{ return IntVec2(i * v.i, j * v.j); }
	IntVec2& operator*=(int s)							{ i *= s; j *= s; return *this; }
	IntVec2& operator*=(const IntVec2& v)				{ i *= v.i; j *= v.j; return *this; }
	const IntVec2 operator/(int s) const				{ return IntVec2(i / s, j / s); }
	const IntVec2 operator/(const IntVec2& v) const		{ return IntVec2(i / v.i, j / v.j); }
	IntVec2& operator/=(int s)							{ i /= s; j /= s; return *this; }
	IntVec2& operator/=(const IntVec2& v)				{ i /= v.i; j /= v.j; return *this; }
	const IntVec2 operator%(int s) const				{ return IntVec2(i % s, j % s); }
	const IntVec2 operator%(const IntVec2& v) const		{ return IntVec2(i % v.i, j % v.j); }
	IntVec2& operator%=(int s)							{ i %= s; j %= s; return *this; }
	IntVec2& operator%=(const IntVec2& v)				{ i %= v.i; j %= v.j; return *this; }

	bool operator<(const IntVec2& v) const		{ return i < v.i && j < v.j; }
	bool operator<(int s) const					{ return i < s && j < s; }
	bool operator<=(const IntVec2& v) const		{ return i <= v.i && j <= v.j; }
	bool operator<=(int s) const				{ return i <= s && j <= s; }
	bool operator>(const IntVec2& v) const		{ return i > v.i && j > v.j; }
	bool operator>(int s) const					{ return i > s && j > s; }
	bool operator>=(const IntVec2& v) const		{ return i >= v.i && j >= v.j; }
	bool operator>=(int s) const				{ return i >= s && j >= s; }
	bool operator==(const IntVec2& v) const		{ return i == v.i && j == v.j; }
	bool operator==(int s) const				{ return i == s && j == s; }
	bool operator!=(const IntVec2& v) const		{ return i != v.i || j != v.j; }
	bool operator!=(int s) const				{ return i != s || j != s; }

	bool isInside(int iMin, int iMax, int jMin, int jMax) const { return i >= iMin && i < iMax && j >= jMin && j < jMax; }
	bool isInside(int iMax, int jMax) const { return isInside(0, iMax, 0, jMax); }


	/** equals to IntVec2(0,0) */
	static const IntVec2 ZERO;
	/** equals to IntVec2(1,1) */
	static const IntVec2 ONE;
	/** equals to IntVec2(-1,-1) */
	static const IntVec2 MINUS_ONE;

	static int distance(IntVec2 v1, IntVec2 v2)	{ v2 -= v1; v2.abs(); return v2.sum(); }
};

#endif //__COMMON_INTVEC2_H__