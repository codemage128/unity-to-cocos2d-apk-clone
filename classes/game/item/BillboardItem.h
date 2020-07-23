#ifndef __ENGINE_BILLBOARDITEM_H__
#define __ENGINE_BILLBOARDITEM_H__

#include "../ItemImpl.h"

class Cell;

class BillboardItem: public SpriteBasedItem {
private:
	static int GlobalBillboardId;

	std::vector<BillboardItem*> _children;
	int _collectCount = 0;
	bool _isCollected = false;
	bool _canGenerateScore = true;
	int _scoreCount = 0;
	std::vector<int> _cornerSortingOffsets;

public:
	std::vector<cocos2d::Sprite*> BillboardSpriteRenderers;
	cocos2d::Sprite* PlugSpriteRenderer = nullptr;
	cocos2d::Sprite* GlowSpriteRenderer = nullptr;
	BillboardItem* MasterItem = nullptr;
	bool IsMasterItem = false;
	int BillboardId = 0;

public:
	void SetupItem();
	virtual void RemoveSelf() override;

	bool CanRaiseScore() override { return true; }
	int GetScore() override { return 500; }
	bool CanFall() override { return false; }
	bool CanShadowDrop() override { return true; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	bool CanGenerateScoreOnEachTryExplode() override { return this->_canGenerateScore; }
	bool CanBeTapped() override { return false; }
	ItemType GetItemType() override { return ItemType::Billboard; }
	void PlayExplodeAudio() override;
	bool CanGenerateScoreWithoutExplode() override { return true; }
	void PlayWrongMove() override {}
	bool TryExplode() override;
	void NotifyItemCollected();
	void LinkNeighbours(Cell* cell);

private:
	void UpdateView();
	void SetSprite(cocos2d::Sprite* spriteRenderer, bool x, bool y, Direction checkDirection, bool right, bool down);
	bool GetBillboardItem(Cell* cell);

protected:
	void PlayOnExplodeStartedAnimation() override;

};

#endif //__ENGINE_BILLBOARDITEM_H__