#ifndef __ENGINE_LIGHTBULBITEM_H__
#define __ENGINE_LIGHTBULBITEM_H__

#include "../ItemImpl.h"

#include "cocos2d.h"

class LightBulbItem : public SpriteBasedItem
{
public:
	void SetupItem();
	virtual void RemoveSelf() override;

	int LayerCount = 2;
	cocos2d::Sprite* LightOnBulb;
	cocos2d::Sprite* LightOnBase;

public:
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	void RemoveAllLayers() override { this->LayerCount = 1; }
	int GetScore() override { return 500; }
	bool CanCastShadow() override { return true; }
	void PlayExplodeAudio() override;
	bool TryExplode() override;
	CollectAnimation GetCollectItem() override;
	
private:
	void StartTranformationToLayer1();
	
public:
	ItemType GetItemType() override { return ItemType::LightBulb; }

protected:
	void PlayOnExplodeStartedAnimation() override;

};


#endif //__ENGINE_LIGHTBULBITEM_H__