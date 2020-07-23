#ifndef __ENGINE_MOLEITEM_H__
#define __ENGINE_MOLEITEM_H__

#include "../Item.h"
#include "../IExplodeAware.h"
#include "cocos2d.h"

class MoleItem : public Item, public IExplodeAware
{
public:
//	Animator CurrentAnimator;
//	SortingGroup MoleSortingGroup;
	cocos2d::Sprite* BoardBackSpriteRenderer = nullptr;
	cocos2d::Sprite* BoardFrontSpriteRenderer = nullptr;

private:
	int _upAnimationHash = 0;
	int _downAnimationHash = 0;
//	Sorting _sorting;
	int _latestTriggeredMove = -1;
	int _state = 0;
	bool _isDestroyed = false;

	void Awake();

public:
	void OnItemCreated(Level* currentLevel) override;
	ItemType GetItemType() override { return ItemType::Mole; }
	int GetScore() override { return 500; }
	bool CanCastShadow() override { return false; }
	bool CanFall() override { return false; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	bool CanBeCollectedWithAnimation()/* override*/ { return false; }
	void ExplodeByBlasterItem() /*override*/;
	bool TryExplode() override;

protected:
	void PlayOnExplodeStartedAnimation() override;

public:
	void PlayExplodeAudio() override;
	void ExplosionOccured(int moveCount);

private:
	void MoveToState(int i);
};

#endif //__ENGINE_MOLEITEM_H__