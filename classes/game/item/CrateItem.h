#ifndef __ENGINE_ITEM_CRATE_H__
#define __ENGINE_ITEM_CRATE_H__

#include "../ItemImpl.h"

class CrateItem : public SpriteBasedItem
{
public:
	CrateItem();
	virtual ~CrateItem();

	void SetupItem();
	virtual void RemoveSelf() override;

	int LayerCount = 0;

	bool CanFall() override { return false; }
	bool CanBeTapped() override { return false; }
	bool CanShadowDrop() override { return true; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	int GetScore() override { return 500; }
	ItemType GetItemType() override { return ItemType::Crate; }
	void RemoveAllLayers() override { this->LayerCount = 1; }
	void PlayExplodeAudio() override;
	bool TryExplode() override;

protected:
	void PlayOnExplodeStartedAnimation() override;
	virtual void StartTranformationToNewLayer();
};

#endif //__ENGINE_ITEM_CRATE_H__

