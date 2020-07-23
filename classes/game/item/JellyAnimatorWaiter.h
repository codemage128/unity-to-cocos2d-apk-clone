#ifndef __ENGINE_JELLYANIMATORWAITER_H__
#define __ENGINE_JELLYANIMATORWAITER_H__

#include "cocos2d.h"

class JellyItem;

class JellyAnimatorWaiter {
public:
	JellyItem* MasterJelly = nullptr;
	//Animator SpreadAnimator;

	cocos2d::Sprite* SpreadingSprite = nullptr;

	int DisplaySortNo = 0;

public:
	void InformAnimationEnded();
	void DisplayAtFront();
	void HideIt();
};

#endif //__ENGINE_JELLYANIMATORWAITER_H__