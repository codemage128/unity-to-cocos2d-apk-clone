#ifndef __ENGINE_HANOIITEM_H__
#define __ENGINE_HANOIITEM_H__

#include "../Item.h"
#include "cocos2d.h"

class HanoiItem : public Item
{
public:
//	Animator CurrentAnimator;
	std::vector<cocos2d::Sprite*> SpriteRenderers;

private:
	int _layerCount = 4;
	int _transformSequenceId = -1;
	std::vector<int> _transformAnimation43;
	std::vector<int> _transformAnimation32;
	std::vector<int> _transformAnimation21;

public:
	void OnItemCreated(Level* currentLevel) override;
	bool CanFall() override { return false; }
	bool CanBeTapped() override { return false; }
	bool CanShadowDrop() override { return true; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	int GetScore() override { return 500; }
	ItemType GetItemType() override { return ItemType::Hanoi; }
	void RemoveAllLayers() override { this->_layerCount = 1; }
	void ExplodeByBlasterItem() /*override*/;
	void PlayExplodeAudio() override;
	bool TryExplode() override;

protected:
	void PlayOnExplodeStartedAnimation() override;
	virtual void StartTranformationToNewLayer();
};

#endif // __ENGINE_HANOIITEM_H__