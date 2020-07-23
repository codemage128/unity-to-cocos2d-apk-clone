#ifndef __ENGINE_BIRDHOUSEITEM_H__
#define __ENGINE_BIRDHOUSEITEM_H__

#include "../ItemImpl.h"
#include "cocos2d.h"

class BirdHouseItem : public SpriteBasedItem
{
public:
//	Animator CurrentAnimator;
	std::vector<cocos2d::Sprite*> SortingLayers;
	static std::vector<BirdHouseItem*> BirdHouseItems;

private:
	int _throwHash = 0;

public:
	void Start();
	ItemType GetItemType() override { return ItemType::BirdHouse; }
	int GetScore() override { return 500; }
	bool CanFall() { return false; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	bool CanGenerateScoreOnEachTryExplode() { return true; }
	bool CanBeInsideBubble() /*override*/ { return false; }
	bool CanCastShadow() override { return true; }
	void OnItemCreated(Level* currentLevel) override;
	bool TryExplode() override;
	void StartCollect() override;

private:
	void PlayCollectAnimation();

public:
	void PlayExplodeAudio() override;

protected:
	void PlayOnExplodeStartedAnimation() override;

public:
	static void ClearAllBirdHouses();
};

#endif //__ENGINE_BIRDHOUSEITEM_H__