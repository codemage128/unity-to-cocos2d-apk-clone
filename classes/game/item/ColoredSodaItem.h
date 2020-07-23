#ifndef __ENGINE_COLOREDSODAITEM_H__
#define __ENGINE_COLOREDSODAITEM_H__

#include "../Item.h"

class ColoredSodaFakeItem;
class SodaBottle;

class ColoredSodaItem: public Item {
public:
	ColoredSodaFakeItem* BottomRight = nullptr;
	ColoredSodaFakeItem* TopLeft = nullptr;
	ColoredSodaFakeItem* TopRight = nullptr;
	//	Animator CurrentAnimator;
	cocos2d::Sprite* BackSpriteRenderer = nullptr;
	//	Transform ExplodePosition;
	std::vector<SodaBottle*> SodaBottles;

private:
	std::vector<SodaBottle*> _availableBottles;
	MatchType _matchType = (MatchType)100;/*None*/
	std::vector<int> _animations;
	bool _isExploded = false;
	float _explodedByNonSpecialItem = 0.0f;
	bool _explodedBySpecialItem = false;
	float _explodeTime = 0.0f;
	std::map<SpecialItem*, float> _explodedBySpecialItemTime;
	bool _shouldSkipExplode = false;
	bool _canGenerateScoreThisTurn = true;

public:
	ColoredSodaItem();
	~ColoredSodaItem();

	//void Start();
	void RemoveSelf() override;
	bool CanGenerateScoreOnEachTryExplode() override { return true; }
	void Init(MatchType matchType);
	Cell* get_CurrentCell() override;
	void set_CurrentCell(Cell* value) override;
	void InformToBeExplodedBySpecialItem(SpecialItem* specialItem, Direction comingFrom) override;
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override;
	bool TryExplode() override;
	bool CanGenerateScoreThisTurn() override { return this->_canGenerateScoreThisTurn; }
	bool ExplodeBy(Item* item);
	ItemType GetItemType() override { return ItemType::Soda; }
	void PlayExplodeAudio() override;
	bool CanFall() override { return false; }
	int GetScore() override { return 1000; }
	void StartCollect() override;

private:
	void PlayExplodeAnimation();
	void ChangeBottleColors(MatchType matchType);


protected:
	void PlayOnExplodeStartedAnimation() override;

};

#endif // __ENGINE_COLOREDSODAITEM_H__
