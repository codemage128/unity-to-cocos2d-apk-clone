#include "BarrelItem.h"
#include "../Extension.h"
#include "../Level.h"
#include "../LevelBuilder.h"
#include "../Match.h"
#include "../SpecialItem.h"

void BarrelItem::ExplodeByBlasterItem(){
	this->RemoveAllLayers();
//	Item::ExplodeByBlasterItem();
}

void BarrelItem::PlayExplodeAudio() {
//	if (ItemResourcesManager.Instance != nullptr) {
//		AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this->GetItemType()).AudioClips[1], PlayMode.Frame, nullptr, 1f);
//	}
}

bool BarrelItem::TryExplode(){
	if (this->LatestExplode == (long)Ext_getCurrentFrame())	{
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	if (this->LayerCount == 1) {
		return true;
	}
	this->LayerCount--;
//	if (ItemResourcesManager.Instance != nullptr) {
//		AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this->GetItemType()).AudioClips[0], PlayMode.Frame, nullptr, 1f);
//	}
	this->StartTranformationToLayer();
	return false;
}

Item* BarrelItem::ExtractSubItem() {
	std::map<GroupId, ItemGroup*>* currentItemGroups = &this->CurrentLevel->CurrentItemGroups;
	if (currentItemGroups != nullptr && currentItemGroups->find(this->_groupId) != currentItemGroups->end()) {
/*		ItemType randomBarrelItemType = (*currentItemGroups)[this->_groupId]->GetRandomBarrelItemType();
		this->_subItem = this->CurrentLevel->CurrentLevelBuilder->CreateSpecialItemWithoutCell(randomBarrelItemType, MatchType::None, this->CurrentSpriteRenderer->getPosition());
		this->_subItem.get_transform().set_localScale(Vector3.get_one() * 0.5f);
		Tweener tweener = ShortcutExtensions.DOScale(this->_subItem.get_transform(), 1f, 0.4f);
		TweenSettingsExtensions.SetEase<Tweener>(tweener, this->AnimCurve);
		dynamic_cast<SpecialItem*>(this->_subItem)->StartAnimations();
		return this->_subItem;*/
	}
	return nullptr;
}

void BarrelItem::StartTranformationToLayer() {
/*	if (ItemResourcesManager.Instance != nullptr) {
		ItemResources resources = ItemResourcesManager.Instance.GetResources(this->GetItemType());
		if (this->LayerCount == 2)
		{
			this->CurrentSpriteRenderer.set_sprite(resources.Sprites[1]);
			this->CurrentAnimator.Play(this->_animation2To1, 0, 0f);
			ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this->GetItemType()).Particles[0], base.get_transform().get_position(), true);
		}
		else if (this->LayerCount == 1)
		{
			this->CurrentSpriteRenderer.set_sprite(resources.Sprites[0]);
			this->CurrentAnimator.Play(this->_animation2To1, 0, 0f);
			ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this->GetItemType()).Particles[0], base.get_transform().get_position(), true);
		}
		AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this->GetItemType()).AudioClips[0], PlayMode.Frame, nullptr, 1f);
	}*/
}

void BarrelItem::PlayOnExplodeStartedAnimation() {
/*	if (ParticlePool.Instance != nullptr && ItemResourcesManager.Instance != nullptr) {
		ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this->GetItemType()).Particles[1], base.get_transform().get_position(), true);
	}*/
}
