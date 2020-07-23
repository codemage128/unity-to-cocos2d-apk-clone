#ifndef __ENGINE_ITEMFEATURE_H__
#define __ENGINE_ITEMFEATURE_H__

#include "cocos2d.h"

class Cell;

class CanCastShadowComponent {
public:
	//Renderer ShadowBehindReference;
	cocos2d::Sprite* ShadowSpriteRenderer = nullptr;

	void CastShadow();
	void HideShadow();
	static void HideShadowIfPossible(Cell* currentCell);
	static void CastShadowIfPossible(Cell* cell);
};

enum class MatchType;

class ICanBePaint {
public:
	virtual void Paint(MatchType mType) = 0;
};
class ICanShowCurrentlyUnderTap {
public:
	virtual void ShowCurrentlyUnderTap() = 0;
	virtual void HideCurrentlyUnderTap() = 0;
};
class ICanShowMatchHint {
public:
	virtual void ShowMatchHint() = 0;
};


#endif //__ENGINE_ITEMFEATURE_H__