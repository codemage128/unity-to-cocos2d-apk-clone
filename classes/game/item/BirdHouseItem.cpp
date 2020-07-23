#include "BirdHouseItem.h"
#include "../Level.h"
#include "../Extension.h"
#include "../Score.h"
#include "../LevelBuilder.h"

std::vector<BirdHouseItem*> BirdHouseItem::BirdHouseItems;

void BirdHouseItem::Start() {
//	this->_throwHash = Animator.StringToHash("Base Layer.BirdHouseThrowAnimation");
}

void BirdHouseItem::OnItemCreated(Level* currentLevel) {
	SpriteBasedItem::OnItemCreated(currentLevel);
	BirdHouseItem::BirdHouseItems.push_back(this);
}

bool BirdHouseItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame()) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	if (!this->CurrentLevel->CanBeCollected(ItemType::Bird)) {
		return false;
	}
	this->StartCollect();
	if (this->CanRaiseScore()) {
		ScoreManager::RaiseScore(this->GetScore(), this->CurrentSpriteRenderer->getPosition(), MatchType::None);
	}
	return false;
}

void BirdHouseItem::StartCollect() {
	SpriteBasedItem::StopOtherAnimations();
	this->PlayCollectAnimation();
}

void BirdHouseItem::PlayCollectAnimation() {
//	this->CurrentAnimator.Play(this->_throwHash, 0, 0.0f);
//	CollectAnimation component = ItemResourcesManager.Instance.GetResources(this->GetItemType()).Animators[0].Spawn(this->CurrentSpriteRenderer->getPosition()).GetComponent<CollectAnimation>();
//	component.Prepare(this->CurrentLevel, ItemType::Bird, DefinedSorting.Collecting.GetSorting(), SharedImageLibrary.Instance.BirdSprite, this->CurrentCell).StartAnimation();
}

void BirdHouseItem::PlayExplodeAudio() {
//	AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this->GetItemType()).AudioClips[1], PlayMode.Frame, null, 1f);
}

void BirdHouseItem::PlayOnExplodeStartedAnimation() {
//	if (ParticlePool.Instance != null && ItemResourcesManager.Instance != null) {
//		ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this->GetItemType()).Particles[1], base.get_transform().get_position(), true);
//	}
}

void BirdHouseItem::ClearAllBirdHouses() {
	if (LevelBuilder::ActiveLevel == nullptr) {
		return;
	}
	int i = 0;
	int count = BirdHouseItem::BirdHouseItems.size();
	while (i < count) {
		BirdHouseItem* birdHouseItem = BirdHouseItem::BirdHouseItems[i];
		if (birdHouseItem != nullptr) {
			birdHouseItem->StartExplode();
		}
		i++;
	}
	BirdHouseItem::BirdHouseItems.clear();
}