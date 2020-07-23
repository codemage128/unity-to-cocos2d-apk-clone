#ifndef __ENGINE_MAGICHATITEM_H__
#define __ENGINE_MAGICHATITEM_H__

#include "../ItemImpl.h"
#include "cocostudio/CocoStudio.h"

class MagicHatItem : public SpriteBasedItem
{
public:
//	GameObject CarrotParticle;
//	Animator CurrentAnimator;
	void SetupItem();
	virtual void RemoveSelf() override;

private:
	int _throwHash=0;

	cocos2d::Node* _hatNode = nullptr;
	cocostudio::timeline::ActionTimeline* _hatAnim = nullptr;

public:
	ItemType GetItemType() override { return ItemType::MagicHat; }
	bool CanFall() override { return false; }
	bool CanBeTapped() override { return false; }
	bool CanBeMatchable() override { return false; }
	int GetScore() override { return 500; }
	bool CanBeExplodedBySpecialItem() override { return true; }
	bool CanBeExplodedByBooster() override { return true; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	bool CanCastShadow() override { return true; }
	void Start();
	void StartCollect() override;

private:
	/*IEnumerator*/void PlayCollectAnimation();

public:
	bool CanGenerateScoreOnEachTryExplode() override { return true; }
	bool TryExplode() override;
	
};

#endif //__ENGINE_MAGICHATITEM_H__