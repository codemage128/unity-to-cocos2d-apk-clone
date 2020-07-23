#include "ActionEx.h"
#include "Math.h"

tweenfunc::TweenType reverseTweenType(tweenfunc::TweenType tween)
{
	switch (tween)
	{
	case tweenfunc::Sine_EaseIn:	return tweenfunc::Sine_EaseOut;
	case tweenfunc::Sine_EaseOut:	return tweenfunc::Sine_EaseIn;
	case tweenfunc::Quad_EaseIn:	return tweenfunc::Quad_EaseOut;
	case tweenfunc::Quad_EaseOut:	return tweenfunc::Quad_EaseIn;
	case tweenfunc::Cubic_EaseIn:	return tweenfunc::Cubic_EaseOut;
	case tweenfunc::Cubic_EaseOut:	return tweenfunc::Cubic_EaseIn;
	case tweenfunc::Quart_EaseIn:	return tweenfunc::Quart_EaseOut;
	case tweenfunc::Quart_EaseOut:	return tweenfunc::Quart_EaseIn;
	case tweenfunc::Quint_EaseIn:	return tweenfunc::Quint_EaseOut;
	case tweenfunc::Quint_EaseOut:	return tweenfunc::Quint_EaseIn;
	case tweenfunc::Expo_EaseIn:	return tweenfunc::Expo_EaseOut;
	case tweenfunc::Expo_EaseOut:	return tweenfunc::Expo_EaseIn;
	case tweenfunc::Circ_EaseIn:	return tweenfunc::Circ_EaseOut;
	case tweenfunc::Circ_EaseOut:	return tweenfunc::Circ_EaseIn;
	case tweenfunc::Elastic_EaseIn:	return tweenfunc::Elastic_EaseOut;
	case tweenfunc::Elastic_EaseOut:return tweenfunc::Elastic_EaseIn;
	case tweenfunc::Back_EaseIn:	return tweenfunc::Back_EaseOut;
	case tweenfunc::Back_EaseOut:	return tweenfunc::Back_EaseIn;
	case tweenfunc::Bounce_EaseIn:	return tweenfunc::Bounce_EaseOut;
	case tweenfunc::Bounce_EaseOut:	return tweenfunc::Bounce_EaseIn;
	}
	return tween;
}

/*===========================================================================================
 Implementation of ParabolicSpline1To
 */

ParabolicSpline1To* ParabolicSpline1To::create(float duration, const Point& startPoint, const Point& endPoint, float polarY)
{
    ParabolicSpline1To *ret = new ParabolicSpline1To();
    if (ret)
    {
		if (ret->initWithDuration(duration, startPoint, endPoint, polarY))
        {
            ret->autorelease();
        }
        else 
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

bool ParabolicSpline1To::initWithDuration(float duration, const Point& startPoint, const Point& endPoint, float polarY)
{
    if (ActionInterval::initWithDuration(duration))
    {
		this->_startPoint = startPoint;
		this->_endPoint = endPoint;

		float x1 = startPoint.x;
		float x2 = endPoint.x;
		float y1 = startPoint.y;
		float y2 = endPoint.y;
		float a, b, c;

		c = polarY;
		CCASSERT((y1 - c) * (y2 - c) > 0, "polarY must be max or min Y !!!");

		_isLine = x1 == x2;
		if (_isLine)
		{
			a = y1;
			b = y2;
		}
		else
		{
			float k = -sqrtf((y2 - c) / (y1 - c));
			b = (k * x1 - x2) / (k - 1);
			a = (y1 - c) / powf((x2 - x1) / (k - 1), 2);
		}

		this->_a = a;
		this->_b = b;
		this->_c = c;
        
        return true;
    }
    
    return false;
}

ParabolicSpline1To::~ParabolicSpline1To()
{
}

ParabolicSpline1To::ParabolicSpline1To()
{
	_a = _b = _c = 0;
	_isLine = false;
}

void ParabolicSpline1To::startWithTarget(Node *target)
{
    ActionInterval::startWithTarget(target);
}

void ParabolicSpline1To::update(float time)
{
	float x, y;
	if (time == 1)
	{
		x = _endPoint.x;
		y = _endPoint.y;
	}
	else if (_isLine)
	{
		x = _startPoint.x;
		float m = (2 * _c - _a - _b);
		float q = (_c - _a) / m;
		if (time < q)
			y = m * time + _a;
		else
			y = _c - m * (time - q);
	}
	else
	{
		x = _startPoint.x + (_endPoint.x - _startPoint.x) * time;
		y = _a * (x - _b) * (x - _b) + _c;
	}
	_target->setPosition(x, y);
}

ParabolicSpline1To* ParabolicSpline1To::clone() const
{
	return ParabolicSpline1To::create(_duration, _startPoint, _endPoint, _c);
}

ParabolicSpline1To* ParabolicSpline1To::reverse() const
{
	return ParabolicSpline1To::create(_duration, _endPoint, _startPoint, _c);
}

/*===========================================================================================
 Implementation of ParabolicSpline2To
 */

ParabolicSpline2To* ParabolicSpline2To::create(float duration, const Point& startPoint, const Point& endPoint, const Point& polarPoint)
{
    ParabolicSpline2To *ret = new ParabolicSpline2To();
    if (ret)
    {
		if (ret->initWithDuration(duration, startPoint, endPoint, polarPoint))
        {
            ret->autorelease();
        }
        else 
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

bool ParabolicSpline2To::initWithDuration(float duration, const Point& startPoint, const Point& endPoint, const Point& polarPoint)
{
    if (ActionInterval::initWithDuration(duration))
    {
		this->_startPoint = startPoint;
		this->_endPoint = endPoint;
		this->_polarPoint = polarPoint;

		bool _isLine1 = startPoint.x == polarPoint.x || startPoint.y == polarPoint.y;
		_a1 = _isLine1 ? 0 : ((startPoint.y - polarPoint.y) / (startPoint.x - polarPoint.x) / (startPoint.x - polarPoint.x));

		bool _isLine2 = endPoint.x == polarPoint.x || endPoint.y == polarPoint.y;
		_a2 = _isLine2 ? 0 : ((endPoint.y - polarPoint.y) / (endPoint.x - polarPoint.x) / (endPoint.x - polarPoint.x));

        return true;
    }
    
    return false;
}

ParabolicSpline2To::~ParabolicSpline2To()
{
}

ParabolicSpline2To::ParabolicSpline2To()
{
	_a1 = _a2 = 0;
}

void ParabolicSpline2To::startWithTarget(Node *target)
{
    ActionInterval::startWithTarget(target);
}
#define ParabolicSpline1At(x)	(_a * ((x) - _b) * ((x) - _b) + _c)

void ParabolicSpline2To::update(float time)
{
	float x, y;
	if (time == 1)
	{
		x = _endPoint.x;
		y = _endPoint.y;
	}
	else
	{
		if (time <= 0.5f)
		{
			x = _startPoint.x + (_polarPoint.x - _startPoint.x) * time;
			if (_a1 == 0)//line
				y = _startPoint.y + (_polarPoint.y - _startPoint.y) * time;
			else
				y = _a1 * (x - _polarPoint.x) * (x - _polarPoint.x) + _polarPoint.y;
		}
		else
		{
			time -= 0.5f;
			x = _polarPoint.x + (_endPoint.x - _polarPoint.x) * time;
			if (_a2 == 0)//line
				y = _polarPoint.y + (_endPoint.y - _polarPoint.y) * time;
			else
				y = _a2 * (x - _polarPoint.x) * (x - _polarPoint.x) + _polarPoint.y;
		}
	}
	_target->setPosition(x, y);
}

ParabolicSpline2To* ParabolicSpline2To::clone() const
{
	return ParabolicSpline2To::create(_duration, _startPoint, _endPoint, _polarPoint);
}

ParabolicSpline2To* ParabolicSpline2To::reverse() const
{
	return ParabolicSpline2To::create(_duration, _endPoint, _startPoint, _polarPoint);
}

/*===========================================================================================
Implementation of CircleTo
*/

CircleTo* CircleTo::create(float duration, const Vec2& center, float rotation)
{
	CircleTo *ret = new (std::nothrow) CircleTo();

	if (ret)
	{
		if (ret->initWithDuration(duration, center, rotation))
		{
			ret->autorelease();
		}
		else
		{
			delete ret;
			ret = nullptr;
		}
	}

	return ret;
}

bool CircleTo::initWithDuration(float duration, const Vec2& center, float rotation)
{
	bool ret = false;

	if (ActionInterval::initWithDuration(duration))
	{
		_center = center;
		_rotation = rotation;
		ret = true;
	}

	return ret;
}

CircleTo* CircleTo::clone() const
{
	// no copy constructor
	auto a = new (std::nothrow) CircleTo();
	a->initWithDuration(_duration, _center, _rotation);
	a->autorelease();
	return a;
}

CircleTo* CircleTo::reverse() const
{
	return CircleTo::create(_duration, _center, -_rotation);
}

void CircleTo::startWithTarget(Node *target)
{
	ActionInterval::startWithTarget(target);

	Vec2 startPosition = _target->getPosition();
	_radius = (startPosition - _center).length();
	_startAngle = Math::getRotation(_center, startPosition);
}

void CircleTo::update(float t)
{
	if (_target)
	{
		float a = _startAngle + _rotation * t;
		a = 90 - a;
		float x = _center.x + _radius * Math::cos_d(a);
		float y = _center.y + _radius * Math::sin_d(a);
		_target->setPosition(x, y);
	}
}
