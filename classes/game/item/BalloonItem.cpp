#include "BalloonItem.h"
#include "../Animation.h"
#include "../ParticleLibrary.h"
#include "../ImageLibrary.h"
#include "global/SoundManager.h"


BalloonItem::BalloonItem() {
}


BalloonItem::~BalloonItem() {
}

void BalloonItem::SetupItem() {
	ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->Balloon);
	cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	newrect.origin.y -= 22.0f; newrect.size.height += 22.0f;
	CurrentSpriteRenderer->setTextureRect(newrect);
}
void BalloonItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void BalloonItem::BringToFront() {
}

void BalloonItem::ReactToUpperFall() {
	//SpriteBasedItem::GetFallListener()->EndFall(-1.0f);
}

void BalloonItem::PlayExplodeAudio() {
	//SoundManager::playEffectSound(SoundManager::SoundEffect::S6); //AudioManager::getInstance()->Play(AudioTag.ItemBalloon, PlayMode.Frame, null, 1f);
}

CollectAnimation BalloonItem::GetCollectItem() {
	SpriteBasedItem::GetCollectItem();
	//CollectAnimation collectItem = Item::GetCollectItem();
	//collectItem->setPosition(this->CurrentSpriteRenderer->getPosition());
	return CollectAnimation::Instant; //collectItem;
}

void BalloonItem::PlayOnExplodeStartedAnimation() {
	PTCLLIB->explodeBalloon(this->CurrentSpriteRenderer->getPosition()); /*ORG:
	if (ParticlePool.Instance != null) {
		BalloonParticlePlayer balloonParticlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.BalloonExplosionParticle, base.get_transform().get_position(), true) as BalloonParticlePlayer;
		balloonParticlePlayer.SetColor();
	}*/
}