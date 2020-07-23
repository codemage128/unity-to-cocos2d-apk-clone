#include "SodaBottle.h"
#include "../Mathf.h"
#include "../ImageLibrary.h"

USING_NS_CC;

void SodaBottle::SetupItem(cocos2d::Node* frame, int type) {
	this->BottleSpriteRenderer = Sprite::create();
	IMGLIB->CopySprite(this->BottleSpriteRenderer, IMGLIB->SodaBottles[type]);
	frame->addChild(this->BottleSpriteRenderer);

	auto neck = Sprite::create();
	IMGLIB->CopySprite(neck, IMGLIB->SodaBottleNeck);
	this->BottleSpriteRenderer->addChild(neck);
	neck->setPosition(23, 98);

	auto cap = Sprite::create();
	IMGLIB->CopySprite(cap, IMGLIB->SodaBottleCaps[type]);
	this->BottleSpriteRenderer->addChild(cap);
	cap->setPosition(23, 117);
}

void SodaBottle::Start() {
	//	this->_animations = new int[]
	//	{
	//		Animator.StringToHash("Base Layer.SodaBottleShakeAnimation1"),
	//		Animator.StringToHash("Base Layer.SodaBottleShakeAnimation2"),
	//		Animator.StringToHash("Base Layer.SodaBottleShakeAnimation3"),
	//		Animator.StringToHash("Base Layer.SodaBottleShakeAnimation4"),
	//		Animator.StringToHash("Base Layer.SodaBottleShakeAnimation5")
	//	};
}

void SodaBottle::PlayShakeAnimation() {
	if(this->_isRemoved) {
		return;
	}
	// int num = this->_animations[Mathf::Random::Range(0, this->_animations.size())];
	//	this->CurrentAnimator.Play(num, 0, 0.0f);
	//	if (this->ShakeParticle != nullptr) {
	//		this->ShakeParticle.Play();
	//	}

	const int SHAKEANIMTAG = 0x7269;
	if(this->BottleSpriteRenderer->getActionByTag(SHAKEANIMTAG) == nullptr) {
		Vec2 orgpos = this->BottleSpriteRenderer->getPosition();
		this->BottleSpriteRenderer->runAction(Sequence::create(
			MoveTo::create(0.26f, orgpos + Vec2(0, Mathf::Random::Range(2.0f, 20.0f))),
			MoveTo::create(0.2f, orgpos),
			nullptr));
		Action* shakeanim = Sequence::create(
			RotateTo::create(0.05f, Mathf::Random::Range(-15.0f, 15.0f)),
			RotateTo::create(0.09f, Mathf::Random::Range(-15.0f, 15.0f)),
			RotateTo::create(0.09f, Mathf::Random::Range(-15.0f, 15.0f)),
			RotateTo::create(0.09f, Mathf::Random::Range(-15.0f, 15.0f)),
			RotateTo::create(0.09f, Mathf::Random::Range(-15.0f, 15.0f)),
			RotateTo::create(0.05f, 0.0f),
			nullptr);
		shakeanim->setTag(SHAKEANIMTAG);
		this->BottleSpriteRenderer->runAction(shakeanim);
	}
}


void SodaBottle::Remove() {
	this->_isRemoved = true;
	//	this->CurrentAnimator.StopPlayback();

	this->BottleSpriteRenderer->removeFromParentAndCleanup(true);
}

void SodaBottle::OnDestroy() {
	this->Remove();
}
