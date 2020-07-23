#ifndef __ENGINE_GIANTPINATAFAKEITEM_H__
#define __ENGINE_GIANTPINATAFAKEITEM_H__

#include "../Item.h"

class GiantPinataItem;
enum class Direction;

class GiantPinataFakeItem: public Item {
public:
	GiantPinataItem* MasterPinataItem = nullptr;
	Direction PositionRelativeToMaster = (Direction)0;

public:
	ItemType GetItemType() override { return ItemType::GiantPinata; }
	int GetScore() override;
	bool CanBeExplodedBySpecialItem() override { return true; }
	bool CanBeTapped() override { return true; }
	bool CanBeExplodedByBooster() override { return true; }
	bool CanFall() override { return false; }
	bool CanCastShadow() override { return false; }
	void PlayWrongMove() override;
	void StartCollect() override;
	bool CanShadowDrop() override;
	void InformToBeExplodedBySpecialItem(SpecialItem* specialItem, Direction comingFrom) override;
	bool TryExplode() override;
	void StartExplode() override;
};

#endif // __ENGINE_GIANTPINATAFAKEITEM_H__
