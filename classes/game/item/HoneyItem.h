#ifndef __ENGINE_HONEYITEM_H__
#define __ENGINE_HONEYITEM_H__

#include "../ItemImpl.h"

class HoneyItem: public SpriteBasedItem {
public:
	//	Animator CurrentItemAnimator;

private:
	bool _canFall = true;
	int _animationHash = 0;
	bool _animationIsPlaying = false;

public:
	void SetupItem();
	virtual void RemoveSelf() override;

	void Awake();
	bool CanFall() override { return this->_canFall; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	bool CanCastShadow() override { return true; }
	bool CanShadowDrop() override { return true; }
	bool TryExplode() override;
	void PlayExplodeAudio() override;

protected:
	void PlayOnExplodeStartedAnimation() override;

public:
	int GetScore() override { return 500; }
	ItemType GetItemType() override { return ItemType::Honey; }
	void BringToFront();
	void SendToBack();
};

#endif //__ENGINE_HONEYITEM_H__
