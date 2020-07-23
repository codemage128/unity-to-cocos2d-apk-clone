#ifndef __ENGINE_DIAMONDITEM_H__
#define __ENGINE_DIAMONDITEM_H__

#include "../ItemImpl.h"
#include "../IExplodeAware.h"

#include "cocostudio/CocoStudio.h"

class Level;

class DiamondItem: public SpriteBasedItem, public IExplodeAware {
public:
	//	Animator CurrentAnimator;
	cocos2d::Sprite* OpenSpriteRenderer = nullptr;
	cocos2d::Sprite* DiamondSpriteRenderer = nullptr;
	cocos2d::Sprite* DoorSpriteRenderer = nullptr;
	cocos2d::Sprite* DoorSpriteRenderer1 = nullptr;
	cocos2d::Sprite* DoorSpriteRenderer2 = nullptr;

private:
	bool _canBeExploded = false;
	bool _isDestroyed = false;
	int _transformToOpenHash = 0;
	int _transformToCloseHash = 0;

	cocostudio::timeline::ActionTimeline* _animation = nullptr;

public:
	void SetupItem();
	virtual void RemoveSelf() override;

	void SwitchState();
	void UpdateView(bool isOn, bool playParticle = true);
	bool CanShadowDrop() override { return true; }
	void OnItemCreated(Level* currentLevel) override;
	ItemType GetItemType() override { return ItemType::Diamond; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	bool TryExplode() override;
	int GetScore() override { return 500; }
	void PlayExplodeAudio() override;
	void ExplosionOccured(int moveCount);

private:
	/*IEnumerator*/void WaitAndStartAnimation(bool canBeExploded, bool playInstant);
	void Awake();

protected:
	void PlayOnExplodeStartedAnimation() override;

};

#endif //__ENGINE_DIAMONDITEM_H__