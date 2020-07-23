#ifndef __ENGINE_BLASTERITEM_H__
#define __ENGINE_BLASTERITEM_H__

#include "CollectorItem.h"
#include "cocos2d.h"
#include "../Cell.h"

class BlasterFakeItem;

class BlasterItem : public CollectorItem
{
public:
	cocos2d::Node* BlasterTransform = nullptr;
	cocos2d::Sprite* FillLayer = nullptr;
	cocos2d::ParticleSystemQuad* TrailParticles = nullptr;
//	Animator CurrentAnimator;
	cocos2d::Sprite* ShadowSpriteRenderer = nullptr;
	cocos2d::Sprite* FakeShadowSpriteRenderer = nullptr;
	cocos2d::ParticleSystemQuad* CollectParticle = nullptr;
	cocos2d::ParticleSystemQuad* CollectHitParticle = nullptr;
	cocos2d::Node* CollectTarget = nullptr;
	BlasterFakeItem* FakeItem = nullptr;
	std::vector<cocos2d::Sprite*> ColoredSpriteRenderers;
	std::vector<cocos2d::Sprite*> SpriteRenderers;

private:
	int _capacity = 0;
	int _count = 0;
	int _waitingCount = 0;
	Direction _direction = Direction::None;
	bool _blasterAnimationCompleted = false;
	float _offset = 0.0f;
	float _dt = 0.07f;
	std::vector<Cell*> _selectedCells;
	int _collectHash = 0;
	int _launchHash = 0;
	cocos2d::Vec2 _scorePosition = cocos2d::Vec2();
	cocos2d::Sequence* _fillSequence;
	bool _readyToLaunch = false;
	bool _shouldPlayCollectAudio = false;
	bool _fillAnimationEnded = false;
	const float ShakeDuration = 0.4f;
	const float ShakeX = 0.1f;
	const float ShakeY = 0.1f;
	const float ShakeWait = 0.12f;
	const float WaitAnimation = 0.4f;
	int ScoreGained = 0;

public:
	Cell* get_CurrentCell() override { return CollectorItem::get_CurrentCell(); }
	void set_CurrentCell(Cell* value) override;

private:
	void Start();

public:
	void BringToFront() override;
	void Prepare(Direction direction, int capacity, int order, MatchType matchType);

private:
	void ChangeColor(MatchType matchType);
	
public:
	void StartCollectingItem() override;
	void PlayCollectParticle();
	void OnItemCollectCompleted() override;
	
private:
	void ResetFill();
	void UpdateFill();	

public:
	bool IsAvailable() override { return this->_capacity - (this->_count + this->_waitingCount) > 0; }

private:
	/*IEnumerator*/void StartExplodeAnimation();
	void AcceptFalls();

public:
	void RemoveSelf() override;

private:
	void CreateAnimation();
	void ClearCells();
	void CreateRightAnimation();
	void CreateLeftAnimation();
	void CreateUpAnimation();
	void CreateDownAnimation();
	void ExplodeCell(Cell* c, cocos2d::Sequence* seq);
	
public:
	ItemType GetItemType() override { return ItemType::Blaster; }
	bool CanFall() override	{ return false; }
	bool CanBeEffectedByDiscoBall() override { return false; }
	bool CanBeExplodedBySpecialItem() override { return false; }
	bool CanBeExplodedByBooster() override  { return false; }
	bool BoosterAnvilCanBeUsed() override { return true; }
	bool BoosterBoxingGloveCanBeUsed() override { return true; }
	bool BoosterHammerCanBeUsed() override { return false; }
	void ExplodeByBlasterItem() /*override*/ { }
	bool CanCastShadow() override { return true; }
	int GetScore() override { return 0; }
	bool CanBeInsideBubble() /*override*/ { return false; }
};

#endif // __ENGINE_BLASTERITEM_H__
