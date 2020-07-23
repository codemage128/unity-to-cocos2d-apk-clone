#ifndef __ENGINE_CANTOSSFAKEITEM_H__
#define __ENGINE_CANTOSSFAKEITEM_H__

#include "../Item.h"

class CanTossItem;
enum class MatchType;

class CanTossFakeItem: public Item, public ICanExplodeAtLeast2 {
public:
	CanTossFakeItem();
	virtual ~CanTossFakeItem();

	CanTossItem* MasterCanToss = nullptr;

	ItemType GetItemType() override { return ItemType::CanToss; }
	int GetScore() override { return 250; }
	bool CanBeExplodedBySpecialItem() override { return true; }
	bool CanBeTapped() override { return true; }
	bool CanBeExplodedByBooster() override { return true; }
	bool CanGenerateScoreOnEachTryExplode() override { return true; }
	bool CanFall() override { return false; }
	bool CanCastShadow() override { return false; }
	void PlayWrongMove() override;
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	void StartCollect() override;
	bool TryExplode() override;
	void StartExplode() override;

	/// non override
	void CheckIfExtraExplodeNeeded();
	void MarkShouldExplodeAtLeast2();
};

#endif //__ENGINE_CANTOSSFAKEITEM_H__

