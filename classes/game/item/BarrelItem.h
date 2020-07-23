#ifndef __ENGINE_BARRELITEM_H__
#define __ENGINE_BARRELITEM_H__

#include "../Item.h"
#include "../Group.h"
#include "cocos2d.h"

class BarrelItem : public Item
{
public:
	cocos2d::Sprite* CurrentSpriteRenderer = nullptr;
	//Animator CurrentAnimator;
	//AnimationCurve AnimCurve;
	int LayerCount = 3;

private:
	GroupId _groupId = GroupId::None;
	//const int _animation2To1 = Animator.StringToHash("Base Layer.Barrel2-1");
	Item* _subItem = nullptr;

public:
	void Init(GroupId groupId) { this->_groupId = groupId; }
	ItemType GetItemType() override { return ItemType::Barrel; }
	int GetScore() override { return 0; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	void RemoveAllLayers() override { this->LayerCount = 1; }
	bool CanCastShadow() override { return true; }
	void ExplodeByBlasterItem() /*override*/;
	void PlayExplodeAudio() override;
	bool TryExplode() override;
	Item* ExtractSubItem() override;

private:
	void StartTranformationToLayer();
	
protected:
	void PlayOnExplodeStartedAnimation() override;
};

#endif // __ENGINE_BARRELITEM_H__
