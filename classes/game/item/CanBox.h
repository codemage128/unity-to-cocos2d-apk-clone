#ifndef __ENGINE_CANBOX_H__
#define __ENGINE_CANBOX_H__

#include "cocos2d.h"


class CanBox {
public:
	void SetupItem(cocos2d::Node* cantoss, cocos2d::Vec2 offset, int id);

	cocos2d::Sprite* CurrentSpriteRenderer = nullptr;
	//Animator CurrentAnimator;
	int Id = 0;

	void Awake();
	void PlayShakeAnimation(int totalCount = 8);
	void Remove();
	void OnDestroy();

private:
	bool			 _isRemoved = false;
	//std::vector<int> _upperAnimations;
	//std::vector<int> _belowAnimations;


	static cocos2d::Vec2 _positions[9];
};

#endif //__ENGINE_CANBOX_H__

