#ifndef __ENGINE_COLOREDSODAFAKEITEM_H__
#define __ENGINE_COLOREDSODAFAKEITEM_H__

#include "../Item.h"

class ColoredSodaItem;

class ColoredSodaFakeItem: public Item {
public:
	ColoredSodaItem* MasterItem = nullptr;

public:
	ItemType GetItemType() override { return ItemType::ColoredSoda; }
	int GetScore() override;
	bool TryExplode() override;
	bool CanBeExplodedBySpecialItem() override { return true; }
	bool CanBeTapped() override { return true; }
	bool CanBeExplodedByBooster() override { return true; }
	bool CanFall() override { return false; }
	bool CanCastShadow() override { return false; }
	void PlayWrongMove() override;
	void StartCollect() override;
	void StartExplode() override;
	bool CanGenerateScoreOnEachTryExplode() override { return true; }
	bool CanGenerateScoreThisTurn() override;
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override;
	void InformToBeExplodedBySpecialItem(SpecialItem* specialItem, Direction comingFrom) override;
};

#endif // __ENGINE_SODAITEM_H__