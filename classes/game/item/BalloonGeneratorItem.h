#ifndef __ENGINE_BALLOONGENERATORITEM_H__
#define __ENGINE_BALLOONGENERATORITEM_H__

#include "GeneratorBasedItem.h"
#include "cocostudio/CocoStudio.h"

class Level;

class BalloonGeneratorItem: public GeneratorBasedItem {
public:
	//	Animator CurrentAnimator;
	//	Transform Container;
	//std::vector<cocos2d::Sprite*> SpriteRenderers;
	cocos2d::Sprite* Renderer = nullptr;

private:
	int _throwHash = 0;
	int _sleepHash = 0;
	int _direction = 0;
	bool _isSleeping = false;

	cocos2d::Node* _sprite = nullptr;
	cocostudio::timeline::ActionTimeline* _animation = nullptr;

public:
	BalloonGeneratorItem();
	~BalloonGeneratorItem();

	void SetupItem();
	virtual void RemoveSelf();

	void Start();
	void OnItemCreated(Level* currentLevel) override;
	ItemType GetItemType() override { return ItemType::BalloonGenerator; }
	bool CanFall() override { return false; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	int GetScore() override { return 0; }
	bool TryExplode() override;
	void Sleep() override;
	Cell* GetRandomCell() override;
	void PlayThrowAnimation(std::vector<Cell*>* targetCells) override;

private:
	/*IEnumerator*/void ThrowCompleted();

public:
	void SetDirection(int direction);
};

#endif //__ENGINE_BALLOONGENERATORITEM_H__
