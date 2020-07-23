#ifndef __ENGINE_OYSTERITEM_H__
#define __ENGINE_OYSTERITEM_H__

#include "../ItemImpl.h"
#include "../IExplodeAware.h"

#include "cocostudio/CocoStudio.h"

enum class MatchType;
class Level;
enum class CollectAnimation;

class OysterItem: public SpriteBasedItem, public IExplodeAware {
public:
	//	Animator CurrentAnimator;
	//	std::vector<cocos2d::Sprite*> SpriteRenderers;

private:
	int _latestTriggeredCount = -1;
	int _state = 0;
	int _latestFrame = 0;
	bool _isDestroyed = false;
	int _openAnimationHash = 0;
	int _closeAnimationHash = 0;
	bool _animationIsPlaying = false;

	cocostudio::timeline::ActionTimeline* _animation;

public:
	void SetupItem();
	virtual void RemoveSelf() override;

	void Awake();
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	void OnItemCreated(Level* currentLevel) override;
	bool TryExplode() override;
	ItemType GetItemType() override { return ItemType::Oyster; }
	int GetScore() override { return 500; }
	bool CanCastShadow() override { return true; }
	CollectAnimation GetCollectItem() override;
	void ExplosionOccured(int moveCount);

protected:
	void PlayOnExplodeStartedAnimation() override;
	void BringToFront();
	void SendToBack();

private:
	void MoveToState(int i);
};

#endif //__ENGINE_OYSTERITEM_H__
