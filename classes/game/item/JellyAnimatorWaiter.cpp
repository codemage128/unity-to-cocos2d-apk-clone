#include "cocos2d.h"
#include "JellyAnimatorWaiter.h"
#include "JellyItem.h"


void JellyAnimatorWaiter::InformAnimationEnded() {
	//this->SpreadAnimator.SetInteger("DIRECTION", 5);
	if (this->MasterJelly != nullptr) {
		this->MasterJelly->AnimationEnded();
	}
}

void JellyAnimatorWaiter::DisplayAtFront() {
}

void JellyAnimatorWaiter::HideIt() {
}
