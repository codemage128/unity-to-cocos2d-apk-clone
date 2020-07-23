#ifndef __ENGINE_BLASTERFAKEITEM_H__
#define __ENGINE_BLASTERFAKEITEM_H__

#include "../Item.h"
#include "BlasterItem.h"

class BlasterFakeItem : public Item
{
public:
	BlasterItem* MasterItem = nullptr;

public:
	ItemType GetItemType() override { return ItemType::Blaster; }
	bool CanFall() override { return this->MasterItem->CanFall(); }
	bool CanBeEffectedByDiscoBall() override { return this->MasterItem->CanBeEffectedByDiscoBall(); }
	bool CanBeExplodedBySpecialItem() override { return this->MasterItem->CanBeExplodedBySpecialItem(); }
	bool CanBeExplodedByBooster() override { return this->MasterItem->CanBeExplodedByBooster(); }
	bool BoosterAnvilCanBeUsed() override  { return this->MasterItem->BoosterAnvilCanBeUsed(); }
	bool BoosterBoxingGloveCanBeUsed() override { return this->MasterItem->BoosterBoxingGloveCanBeUsed(); }
	bool BoosterHammerCanBeUsed() override { return this->MasterItem->BoosterHammerCanBeUsed(); }
	void PlayWrongMove() override;
	void ExplodeByBlasterItem() /*override*/ { }
	bool CanCastShadow() override { return true; }
	bool CanBeInsideBubble() /*override*/ { return this->MasterItem->CanBeInsideBubble(); }
};


#endif //__ENGINE_BLASTERFAKEITEM_H__
