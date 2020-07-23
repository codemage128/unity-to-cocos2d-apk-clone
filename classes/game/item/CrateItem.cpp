#include "CrateItem.h"
#include "../Match.h"
#include "../Animation.h"
#include "../ImageLibrary.h"
#include "../ParticleLibrary.h"
#include "../Extension.h"
#include "global/SoundManager.h"


CrateItem::CrateItem() {
}

CrateItem::~CrateItem() {
}

void CrateItem::SetupItem() {
	ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->CrateLayerSprites[LayerCount-1]);
	//cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	//newrect.origin.y -= 15.0f; newrect.size.height += 15.0f;
	//CurrentSpriteRenderer->setTextureRect(newrect);
}

void CrateItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void CrateItem::PlayExplodeAudio() {
	//SoundManager::playEffectSound(SFX::S12); //AudioManager.Play(AudioTag.ItemCrate1, PlayMode.Frame, null, 1f);
}

bool CrateItem::TryExplode() {
	if (this->LatestExplode == Ext_getCurrentFrame())//(long)Time.get_frameCount())
		return false;

	this->LatestExplode = Ext_getCurrentFrame();//(long)Time.get_frameCount();
	if (this->LayerCount == 1)
		return true;

	this->LayerCount--;
	this->StartTranformationToNewLayer();
	return false;
}

///protected:
void CrateItem::PlayOnExplodeStartedAnimation() {
	/*if (ParticlePool.Instance != null) {
		ParticlePool.Instance.PlayParticle(ParticlePool.Instance.CrateExploded, base.get_transform().get_position(), true);
	}//*/
	PTCLLIB->explodeCrate(this->CurrentSpriteRenderer->getPosition());
}

void CrateItem::StartTranformationToNewLayer() {
	int layerCount = this->LayerCount;
	if (layerCount == 3 || layerCount == 2 || layerCount == 1) 	{
		//SoundManager::playEffectSound(SFX::S12); //AudioManager.Play(AudioTag.ItemCrate23, PlayMode.Frame, null, 1f);
		PTCLLIB->explodeCrate(this->CurrentSpriteRenderer->getPosition()); //ParticlePool.Instance.PlayParticle(ParticlePool.Instance.CrateLayer2Or3Exploded, base.get_transform().get_position(), true);
	}
	if(this->LayerCount - 1 < (int)IMGLIB->CrateLayerSprites.size())
		SetupItem();
}