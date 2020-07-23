#ifndef __ENGINE_PENGUINITEM_H__
#define __ENGINE_PENGUINITEM_H__

#include "../ItemImpl.h"

class PenguinItem : public SpriteBasedItem
{
private:
	int _currentState = 1;

public:
	ItemType GetItemType() override { return ItemType::Penguin; }
	bool CanFall() override { return true; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	bool TryExplode() override;

private:
	void StartTransform();
	
public:
	int GetScore() override { return 500; }
	void PlayExplodeAudio() override;
	
protected:
	void PlayOnExplodeStartedAnimation() override;

public:
	void RemoveAllLayers() override { this->_currentState = 4; }
	void ExplodeByBlasterItem() /*override*/;
	bool CanBeCollectedWithAnimation() /*override*/ { return true; }
	CollectAnimation GetCollectItem() override;
};

#endif // __ENGINE_PENGUINITEM_H__
