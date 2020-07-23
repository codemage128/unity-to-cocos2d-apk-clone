#include "CanBox.h"
#include "../Animation.h"
#include "../Extension.h"
#include "../ImageLibrary.h"
#include "global/SoundManager.h"

USING_NS_CC;

Vec2 CanBox::_positions[9] ={ Vec2(82, 141), Vec2(125, 141), Vec2(59, 95), Vec2(147, 95), Vec2(103, 95), Vec2(36, 51), Vec2(166, 51), Vec2(80, 51), Vec2(123, 51)};

void CanBox::SetupItem(cocos2d::Node* cantoss, cocos2d::Vec2 offset, int id) {
	this->CurrentSpriteRenderer = Sprite::create();
	IMGLIB->CopySprite(this->CurrentSpriteRenderer, IMGLIB->Can);
	cantoss->addChild(this->CurrentSpriteRenderer);
	this->CurrentSpriteRenderer->setPosition(_positions[id]+offset);
	this->CurrentSpriteRenderer->setScale(0.6f);
}

void CanBox::Awake() {
	/*this->_upperAnimations = new int[]
	{
		Animator.StringToHash("Base Layer.CanItemShakeUp1"),
			Animator.StringToHash("Base Layer.CanItemShakeUp2"),
			Animator.StringToHash("Base Layer.CanItemShakeUp3")
	};
	this->_belowAnimations = new int[]
	{
		Animator.StringToHash("Base Layer.CanItemShakeDown1"),
			Animator.StringToHash("Base Layer.CanItemShakeDown2"),
			Animator.StringToHash("Base Layer.CanItemShakeDown3"),
			Animator.StringToHash("Base Layer.CanItemShakeDown4"),
			Animator.StringToHash("Base Layer.CanItemShakeDown5")
	};//*/
}

void CanBox::PlayShakeAnimation(int totalCount)
{
	if (this->_isRemoved)
		return;

	//int num;
	//if (this->Id < 3)
	//	num = this->_upperAnimations[Mathf::Random::Range(0, this->_upperAnimations.size())];
	//else if (this->Id < 6 && totalCount < 8)
	//	num = this->_upperAnimations[Mathf::Random::Range(0, this->_upperAnimations.size())];
	//else if (this->Id < 9 && totalCount < 5)
	//	num = this->_upperAnimations[Mathf::Random::Range(0, this->_upperAnimations.size())];
	//else
	//	num = this->_belowAnimations[Mathf::Random::Range(0, this->_belowAnimations.size())];
	//this->CurrentAnimator.Play(num, 0, 0f);

	const int SHAKEANIMTAG = 0x4184;
	if(this->CurrentSpriteRenderer->getActionByTag(SHAKEANIMTAG) == nullptr) {
		Vec2 orgpos = this->CurrentSpriteRenderer->getPosition();
		this->CurrentSpriteRenderer->runAction(Sequence::create(MoveTo::create(0.12f, orgpos + Vec2(0, Mathf::Random::Range(2.0f, 20.0f))), MoveTo::create(0.12f, orgpos), nullptr));
		Action* shakeanim = Sequence::create(RotateTo::create(0.06f, Mathf::Random::Range(-30.0f, 30.0f)), RotateTo::create(0.12f, Mathf::Random::Range(-30.0f, 30.0f)), RotateTo::create(0.06f, 0.0f), nullptr);
		shakeanim->setTag(SHAKEANIMTAG);
		this->CurrentSpriteRenderer->runAction(shakeanim);
	}
}

void CanBox::Remove() {
	this->_isRemoved = true;
	//this->CurrentSpriteRenderer.set_enabled(false);
	//this->CurrentAnimator.StopPlayback();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
}

void CanBox::OnDestroy() {
	this->Remove();
}