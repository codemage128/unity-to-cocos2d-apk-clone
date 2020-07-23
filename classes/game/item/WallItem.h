#ifndef __ENGINE_WALLITEM_H__
#define __ENGINE_WALLITEM_H__

#include "CollectorItem.h"
#include "cocos2d.h"

class WallItem : public CollectorItem
{
public:
	cocos2d::Sprite* WallSpriteRenderer = nullptr;
	cocos2d::Sprite* JointSpriteRenderer = nullptr;
	cocos2d::Sprite* JointCornerSpriteRenderer = nullptr;
//	Animator CollectAnimator;
	cocos2d::Node* CollectTarget = nullptr;	//Transform
	cocos2d::Sprite* DynamiteSpriteRenderer = nullptr;
	cocos2d::Sprite* DynamiteRibbonSpriteRenderer = nullptr;
	cocos2d::Sprite* DynamiteDialSpriteRenderer = nullptr;
	cocos2d::Sprite* DynamiteDialGlowSpriteRenderer = nullptr;
	cocos2d::Sprite* DynamiteShadowSpriteRenderer = nullptr;
//	BitmapNumberDisplay CurrentBitmapNumberDisplay;
//	WallEffect[] WallEffects;
//	GameObject[] SparksBig;
//	GameObject[] SparksSmall;
	std::vector<cocos2d::Sprite*> FuseSpriteRenderers;
	std::vector<cocos2d::Sprite*> DialSprites;
	cocos2d::ParticleSystemQuad* HitParticle = nullptr;
	WallItem* MasterItem = nullptr;
	bool IsMasterItem = false;
	std::string Group;

private:
	std::vector < WallItem*> _children;
	Item* _innerItem = nullptr;
	int _capacity = 0;
	int _count = 0;
	float _dynamiteScale = 0.0f;
	cocos2d::Vec2 _dynamiteOffset;
	int _waitingCount = 0;
	bool _readyToLaunch = false;
	cocos2d::Vec2 _leftBottom = cocos2d::Vec2(999999, 999999);
	cocos2d::Vec2 _rightTop = cocos2d::Vec2(-999999, -999999);
//	ItemResources _resources;
	Cell* _upperCell = nullptr;
	int _upperSortingOrder = 0;
	bool _didScoreScaled = false;
	const float _shakeDuration = 0.4f;
	static int ExplodeAnimationHash; //= Animator.StringToHash("WallItemExplode");

public:
	Item* get_InnerItem() { return this->_innerItem; }
	void set_InnerItem(Item* value);
	void Prepare(ItemProperties properties);	

private:
	void UpdateCollectTargetColor();
	
public:
	void LinkNeighbours(Cell* cell);
	
private:
	void UpdateSprites();
	bool GetWallItem(Cell* cell);

public:
	void ExplodeByBlasterItem() /*override */{ }
	bool CanFall() override { return false; }
	bool CanBeTapped() override { return false; }
	Item* ExtractSubItem() override;
	bool CanShadowDrop() override { return true; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return false; }
	int GetScore() override { return 0; }
	ItemType GetItemType() override { return ItemType::Wall; }
	bool CanBeInsideBubble() /*override */{ return false; }
	Item* GetSubItem() /*override */{ return this->get_InnerItem(); }
	bool CanBeExplodedBySpecialItem() override { return false; }
	bool CanBeExplodedByBooster() override { return false; }
	void PlayWrongMove() override { }
	bool BoosterHammerCanBeUsed() override { return false; }
	bool BoosterAnvilCanBeUsed() override { return false; }
	bool BoosterBoxingGloveCanBeUsed() override { return false; }
	void PlayExplodeAudio() override;
	void PlayOnExplodeStartedAnimation() override;

private:
	void UpdateCollectTargetCount();
	
public:
	bool IsAvailable() override { return this->_capacity - (this->_count + this->_waitingCount) > 0; }
	void StartCollectingItem() override;
	void OnItemCollectCompleted() override;

private:
	/*IEnumerator*/void WaitCollectAnimation();
	/*IEnumerator*/void ExplodeWall();
};

#endif // __ENGINE_WALLITEM_H__
