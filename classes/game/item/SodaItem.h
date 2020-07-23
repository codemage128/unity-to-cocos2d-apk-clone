#ifndef __ENGINE_SODAITEM_H__
#define __ENGINE_SODAITEM_H__

#include "../Item.h"

class SodaFakeItem;
class SodaBottle;
enum class MatchType;

class SodaItem: public Item {
public:
	SodaItem();
	~SodaItem();

public:
	SodaFakeItem* BottomRight = nullptr;
	SodaFakeItem* TopLeft = nullptr;
	SodaFakeItem* TopRight = nullptr;
	//	Animator CurrentAnimator;
	cocos2d::Sprite* BackSpriteRenderer = nullptr;
	//	Transform ExplodePosition;
	std::vector<SodaBottle*> SodaBottles;

private:
	std::map<MatchType, SodaBottle*> _availableBottles;
	std::vector<int> _animations;
	int _sodaCount = 0;
	bool _isExploded = false;
	MatchType _removedType = (MatchType)100;//::None;
	float _explodedByNonSpecialItem = 0.0f;
	std::map<MatchType, cocos2d::Vec2> SodaBottlePositions5;
	std::map<MatchType, cocos2d::Vec2> SodaBottlePositions4;
	bool _explodedBySpecialItem = false;
	float _explodeTime = 0.0f;
	std::map <SpecialItem*, float> _explodedBySpecialItemTime;
	bool _shouldSkipExplode = false;

public:
	Cell* get_CurrentCell() override;
	void set_CurrentCell(Cell* value) override;
	void Start();
	void Init(int sodaCount);
	void InformToBeExplodedBySpecialItem(SpecialItem* specialItem, Direction comingFrom) override;
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override;
	bool TryExplode() override;
	bool ExplodeBy(Item* item);

private:
	void PlayExplodeAnimation(MatchType removed);

public:
	ItemType GetItemType() override { return ItemType::Soda; }
	void PlayExplodeAudio() override;
	bool CanFall() override { return false; }
	int GetScore() override { return 1000; }
	void StartCollect() override;
	void PlayOnExplodeStartedAnimation() override;
	void RemoveSelf() override;
	bool CanGenerateScoreOnEachTryExplode() override { return true; }
};


#endif // __ENGINE_SODAITEM_H__