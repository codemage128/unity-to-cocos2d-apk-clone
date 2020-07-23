#ifndef __ENGINE_UFOITEM_H__
#define __ENGINE_UFOITEM_H__

#include "../Item.h"
#include "ITouchAware.h"
#include "cocos2d.h"

class UfoItem : public Item, public ITouchAware
{
public:
//	SwapAnimation SwapAnimation;
//	Animator CurrentAnimator;
	std::vector<cocos2d::Sprite*> SpriteRenderers;

private:
	int _lastExplodeTime = 0;
	int _delayerCount = 0;
	int _lastTurnNo = 0;
	int _swapAnimationHash = 0;
	bool _shouldMoveUp = false;
	bool _isSwapping = false;
	bool _statIncreased = false;
	bool _inExplodeState = false;
	float _lastActionTime = 0.0f;

public:
	ItemType GetItemType() override { return ItemType::Ufo; }
	bool CanBeExplodedBySpecialItem() override { return false; }
	bool CanBeTapped() override { return false; }
	bool CanBeExplodedByBooster() override { return false; }
	bool BoosterAnvilCanBeUsed() override { return true; }
	bool BoosterBoxingGloveCanBeUsed() override { return true; }
	bool BoosterHammerCanBeUsed() { return false; }
	int GetScore() override { return 2500; }

protected:
	void PlayOnExplodeStartedAnimation() {}

public:
	void PlayExplodeAudio() override {}
	void ExplodeByBlasterItem()/* override*/;
	bool CanCastShadow() override { return true; }
	bool CanBeCollectedWithAnimation()/* override*/ { return true; }
	void Start();
	void OnItemCreated(Level* currentLevel);

private:
	void OnSwapAnimationCompleted() { this->_isSwapping = false; }

public:
	void TouchOccured();
	void OnFallUpdated() /*override*/;
	bool TrySwap();
	
private:
	bool AreThereFallingItemsInMyColumn();
	
public:
	void TryFall();	

private:
	void StartSwap();
	
public:
	void PlaySwapAnimation();
	CollectAnimation GetCollectItem() override;
	
private:
	/*IEnumerator*/void PlayRescue();
};

#endif // __ENGINE_UFOITEM_H__
