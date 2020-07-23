#ifndef __ENGINE_ANIMATION_H__
#define __ENGINE_ANIMATION_H__

#define ANIMATION_WRONG_TAG1 0x100
#define ANIMATION_WRONG_TAG2 0x101
#define ANIMATION_CELL 0x102
#define ANIMATION_HINT_TAG 0x105
#define ANIMATION_BUBBLE 0x107
#define ANIMATION_SCOREBAR_TAG 0x110
#define ANIMATION_GOAL_ICON 0x111

#include <list>
#include "cocos2d.h"

class Item;
class Cell;

enum class CollectAnimation {None, Instant, SolidColor, Duck, Carrot};

class FallListener {
public:
	virtual void StartFall() = 0;
	virtual void EndFall(float crashSpeed) = 0;
};

class FallAnimation {
public:
	enum FallState {
		NotStarted,
		StartFalling,
		Falling,
		Completed,
		Destroyed
	};
	const float MaxCrashSpeed = 30.0f;
	const float Acceleration = 40.0f;

private:
	std::list<cocos2d::Vec2> _routes;
	float _currentSpeed = 6.0f;
	cocos2d::Vec2 _currentTarget;
	FallListener* _fallListener = nullptr;
	bool _fallMessageSend = false;
	Item* _item = nullptr;
	bool _maxReached = false;
	Item* _linkedItem = nullptr;
	bool _enabled = false;

public:
	static FallAnimation* create(Item* linkedItem);

	FallState State;
	void AppendFallTo(Cell* target, FallListener* fallListener);
	void Update();
	void Fall();
	bool IsFalling();
	void Cancel();
private:
	void CleanMe();
};

#endif //__ENGINE_ANIMATION_H__