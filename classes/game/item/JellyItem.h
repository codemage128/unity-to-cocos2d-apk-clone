#ifndef __ENGINE_JELLYITEM_H__
#define __ENGINE_JELLYITEM_H__

#include "../ItemImpl.h"

class JellyAnimatorWaiter;

class JellyItem: public SpriteBasedItem {
private:
	Item* _itemToBeDestoyedAtAnimationEnd = nullptr;
	bool _creatingJelly = false;
	bool _destroyed = false;

	JellyItem* _newJelly = nullptr;

	JellyItem* _jellyToBeEnabled = nullptr;

	JellyAnimatorWaiter* _jellyAnimatorWaiter = nullptr;

public:
	cocos2d::Node* JellyAnimationOwner = nullptr;
	JellyItem* SpreadedBy = nullptr;

public:
	void SetupItem();
	virtual void RemoveSelf() override;

	int GetScore() override { return 500; }
	void PlayExplodeAudio() override;
	void PlayJellySpread(Cell* cellSelected);
	bool CanShadowDrop() override { return true; }
	void AnimationEnded();
	void OnItemCreated(Level* currentLevel) override;
	void OnBeforeRemove() override;
	void AfterPoolInit() override;
	void ReactToUpperFall() override;

protected:
	void PlayOnExplodeStartedAnimation() override;
public:
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	bool CanFall() override { return false; }
	bool TryExplode() override;
	ItemType GetItemType() override { return ItemType::Jelly; }
};

#endif //__ENGINE_JELLYITEM_H__