#include "PenguinItem.h"
#include "../Extension.h"

bool PenguinItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame()) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	if (this->_currentState > 5) {
		return false;
	}
	this->StartTransform();
	return this->_currentState == 5;
}

void PenguinItem::StartTransform() {
	this->_currentState++;
/*	ItemResources resources = ItemResourcesManager.Instance.GetResources(this->GetItemType());
	Sprite sprite = SharedImageLibrary.Instance.PenguinSprites[0];
	if (this->_currentState == 2) {
		sprite = SharedImageLibrary.Instance.PenguinSprites[1];
		ParticlePool.Instance.PlayParticle(resources.Particles[0], this, true);
		AudioManager.PlayAudioProps(resources.AudioClips[0], PlayMode.Frame, null, 1f);
	}
	else if (this->_currentState == 3) {
		sprite = SharedImageLibrary.Instance.PenguinSprites[2];
		ParticlePool.Instance.PlayParticle(resources.Particles[1], this, true);
		AudioManager.PlayAudioProps(resources.AudioClips[1], PlayMode.Frame, null, 1f);
	}
	else if (this->_currentState == 4) {
		sprite = SharedImageLibrary.Instance.PenguinSprites[3];
		ParticlePool.Instance.PlayParticle(resources.Particles[2], this, true);
		AudioManager.PlayAudioProps(resources.AudioClips[1], PlayMode.Frame, null, 1f);
	}
	this->CurrentSpriteRenderer.set_sprite(sprite);*/
}

void PenguinItem::PlayExplodeAudio() {
//	AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this->GetItemType()).AudioClips[2], PlayMode.Frame, null, 1f);
}

void PenguinItem::PlayOnExplodeStartedAnimation() {
//	ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this->GetItemType()).Particles[3], base.get_transform().get_position(), true);
}

void PenguinItem::ExplodeByBlasterItem() {
	this->RemoveAllLayers();
//	SpriteBasedItem::ExplodeByBlasterItem();
}

CollectAnimation PenguinItem::GetCollectItem() {
	CollectAnimation component;// = ItemResourcesManager.Instance.GetResources(this->GetItemType()).Animators[0].Spawn(base.get_transform().get_position()).GetComponent<CollectAnimation>();
//	component.Prepare(this->CurrentLevel, this->GetItemType(), this->GetSorting(), null, this->CurrentCell);
	return component;
}

