#ifndef __ENGINE_METALCRATEITEM_H__
#define __ENGINE_METALCRATEITEM_H__

#include "../ItemImpl.h"

class MetalCrateItem: public SpriteBasedItem {
public:
	void SetupItem();
	virtual void RemoveSelf() override;

	ItemType GetItemType() override {return ItemType::MetalCrate;}
	int GetScore() override  {return 1000;}
	bool CanCastShadow() override  {return false;}
	bool CanShadowDrop() override  {return true;}
	bool CanFall() override  {return false;}

	void PlayExplodeAudio() override;

protected:
	void PlayOnExplodeStartedAnimation() override;
};

#endif //__ENGINE_METALCRATEITEM_H__