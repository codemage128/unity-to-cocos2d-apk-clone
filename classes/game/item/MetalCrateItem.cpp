#include "MetalCrateItem.h"
#include "../Animation.h"
#include "../ParticleLibrary.h"
#include "../ImageLibrary.h"
#include "global/SoundManager.h"

void MetalCrateItem::SetupItem() {
	ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->MetalCrate);
}

void MetalCrateItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void MetalCrateItem::PlayExplodeAudio() {
	//AudioManager.Play(AudioTag.MetalCrate, PlayMode.Frame, null, 1f);
}


void MetalCrateItem::PlayOnExplodeStartedAnimation() {
	//if(ParticlePool.Instance != null) {
	//	ParticlePool.Instance.PlayParticle(ParticlePool.Instance.MetalCrateParticle, base.get_transform().get_position(), true);
	//}
	PTCLLIB->explodeMetalCrate(CurrentSpriteRenderer->getPosition());
}