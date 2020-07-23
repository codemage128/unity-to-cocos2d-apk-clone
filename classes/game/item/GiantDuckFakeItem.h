#ifndef __ENGINE_GIANTDUCKFAKEITEM_H__
#define __ENGINE_GIANTDUCKFAKEITEM_H__

#include "../Item.h"

class GiantDuckItem;


class GiantDuckFakeItem: public Item {
public:
	GiantDuckFakeItem();
	virtual ~GiantDuckFakeItem();

	bool IsBottomRight = false;
	GiantDuckItem* MasterDuck = nullptr;

	ItemType GetItemType() override { return ItemType::GiantDuck; }
	int GetScore() override { return 0; }
	bool CanBeExplodedBySpecialItem() override { return false; }
	bool CanBeTapped() override { return false; }
	bool CanBeExplodedByBooster() override { return false; }
	bool BoosterAnvilCanBeUsed() override { return true; }
	bool BoosterBoxingGloveCanBeUsed() override { return true; }
	bool BoosterHammerCanBeUsed() override { return false; }
	void PlayWrongMove() override;
	bool CanFall() override { return false; }
	bool CanCastShadow() override { return this->IsBottomRight; }
};


#endif //__ENGINE_GIANTDUCKFAKEITEM_H__
