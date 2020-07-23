#ifndef __ENGINE_SODAFAKEITEM_H__
#define __ENGINE_SODAFAKEITEM_H__

#include "../Item.h"

enum class Direction;
enum class MatchType;
class SodaItem;

class SodaFakeItem: public Item {
public:
	SodaItem* MasterItem = nullptr;

public:
	ItemType GetItemType() override { return ItemType::Soda; }
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
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override;
	void InformToBeExplodedBySpecialItem(SpecialItem* specialItem, Direction comingFrom) override;
};

#endif // __ENGINE_SODAFAKEITEM_H__