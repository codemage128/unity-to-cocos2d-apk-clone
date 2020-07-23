#ifndef __ENGINE_FISHITEM_H__
#define __ENGINE_FISHITEM_H__

#include "../Item.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

class Level;
class Cell;

class FishItem: public Item {
public:
	//	Animator CurrentAnimator;
	//	Transform Container;
	//std::vector<cocos2d::Sprite*> SpriteRenderers;
	//	ParticleSystem ThrowParticle;

	cocos2d::Sprite* Renderer = nullptr;

private:
	int _generatedBubbleCount = 1;
	int _generateBubbleInterval = 1;
	int _counter = 0;
	int _throwHash = 0;
	int _sleepHash = 0;
	int _direction = 0;
	bool _isSleeping = false;
	bool _isPlayingAnimation = false;

	cocos2d::Node* _sprite = nullptr;
	cocostudio::timeline::ActionTimeline* _animation = nullptr;
	cocos2d::Sprite* _bubble = nullptr;
public:
	FishItem();
	~FishItem();

	void SetupItem();
	virtual void RemoveSelf() override;

	void Start();
	ItemType GetItemType() override { return ItemType::Fish; }
	bool CanFall() override { return false; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	int GetScore() override { return 0; }
	void OnItemCreated(Level* currentLevel) override;
	bool TryExplode() override;
	/*IEnumerator*/void GenerateBubbles();
	void Sleep();
	void SetDirection(int direction);

private:
	void OnThrowAnimationComplete();
	void onThrow(Cell* from, Cell* to, int direction);
};

#endif //__ENGINE_FISHITEM_H__
