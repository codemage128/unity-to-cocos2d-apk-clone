#ifndef __ENGINE_PINATAITEM_H__
#define __ENGINE_PINATAITEM_H__

#include "../ItemImpl.h"

class PinataItem: public SpriteBasedItem {
public:
	void SetupItem();
	virtual void RemoveSelf() override;

	bool CanCastShadow() override {return true;}
	ItemType GetItemType() override {return ItemType::Pinata;}
	int GetScore() override {return 1000;}

	void PlayExplodeAudio() override;

protected:
	void PlayOnExplodeStartedAnimation() override;
};

#endif //__ENGINE_PINATAITEM_H__