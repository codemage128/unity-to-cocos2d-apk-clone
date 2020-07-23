#include "PinataItem.h"
#include "../Animation.h"
#include "../ParticleLibrary.h"
#include "../ImageLibrary.h"
#include "global/SoundManager.h"


void PinataItem::SetupItem() {
	ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->Pinata);
	cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	newrect.origin.y -= 20.0f; newrect.size.height += 20.0f;
	CurrentSpriteRenderer->setTextureRect(newrect);
}

void PinataItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void PinataItem::PlayExplodeAudio() {
	//AudioManager.Play(AudioTag.PinataExplode, PlayMode.Frame, null, 1f);
}

void PinataItem::PlayOnExplodeStartedAnimation() {
	//if(ParticlePool.Instance != null) {
	//	ParticlePool.Instance.PlayParticle(ParticlePool.Instance.PinataExplosionParticle, base.get_transform().get_position(), true);
	//}
	PTCLLIB->explodePinata(this->CurrentSpriteRenderer->getPosition());
}