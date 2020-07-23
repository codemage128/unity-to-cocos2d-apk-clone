#include "HoneyItem.h"
#include "../Extension.h"
#include "../ImageLibrary.h"
#include "../ParticleLibrary.h"
#include "../Cell.h"

USING_NS_CC;

void HoneyItem::SetupItem() {
	ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->HoneyPot);
	cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	newrect.origin.y -= 10.0f; newrect.size.height += 10.0f;
	CurrentSpriteRenderer->setTextureRect(newrect);
}

void HoneyItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void HoneyItem::Awake() {
//	this->_animationHash = Animator.StringToHash("Base Layer.HoneyItemAnimation");
}

bool HoneyItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame()) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	if (this->_canFall) {
		this->_canFall = false;
		ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->HoneyCube);
		cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
		newrect.origin.y -= 7.0f; newrect.size.height += 7.0f;
		CurrentSpriteRenderer->setTextureRect(newrect);
		
		PTCLLIB->explodeHoneyJar(this->get_CurrentCell()->GetFrozenPosition());
//		ParticlePool.Instance.PlayParticle(ParticlePool.Instance.HoneyTransformParticle, this->CurrentCell.GetFrozenPosition(), true);
//		this->CurrentItemAnimator.Play(this->_animationHash, 0, 0f);

		int orgz = CurrentSpriteRenderer->getLocalZOrder();
		CurrentSpriteRenderer->setLocalZOrder(orgz + 2);
		CurrentSpriteRenderer->runAction(Sequence::create(
			ScaleTo::create(0.1f, 1.3f),
			ScaleTo::create(0.15f, 1.0f),
			CallFunc::create([this, orgz]() {this->CurrentSpriteRenderer->setLocalZOrder(orgz); }),
			nullptr));

//		AudioManager.Play(AudioTag.ItemHoneyBreak, PlayMode.Frame, nullptr, 1f);
		return false;
	}
	return true;
}

void HoneyItem::PlayExplodeAudio() {
//	AudioManager.Play(AudioTag.ItemHoneyExplode, PlayMode.Frame, nullptr, 1f);
}

void HoneyItem::PlayOnExplodeStartedAnimation() {
	PTCLLIB->explodeHoney(this->CurrentSpriteRenderer->getPosition());
//	if (ParticlePool.Instance != nullptr) {
//		ParticlePool.Instance.PlayParticle(ParticlePool.Instance.HoneyExplodeParticle, base.get_transform().get_position(), true);
//	}
}

void HoneyItem::BringToFront() {
	int order = 1300;
	if (this->get_CurrentCell()!= nullptr) {
		order = 1300 + (10 - this->get_CurrentCell()->Y * 10);
	}
	this->_animationIsPlaying = true;
}

void HoneyItem::SendToBack() {
	this->_animationIsPlaying = false;
	this->OnCellChanged();
}

