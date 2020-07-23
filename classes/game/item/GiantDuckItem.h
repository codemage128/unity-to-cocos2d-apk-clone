#ifndef __ENGINE_GIANTDUCKITEM_H__
#define __ENGINE_GIANTDUCKITEM_H__

#include "../ItemImpl.h"

class GiantDuckFakeItem;

class GiantDuckItem : public SpriteBasedItem
{
public:
	GiantDuckItem();
	virtual ~GiantDuckItem();

	void SetupItem();
	virtual void RemoveSelf() override;

	GiantDuckFakeItem* BottomRight = nullptr;
	GiantDuckFakeItem* TopLeft = nullptr;
	GiantDuckFakeItem* TopRight = nullptr;

	Cell* get_CurrentCell() override { return SpriteBasedItem::get_CurrentCell(); }
	void set_CurrentCell(Cell* value) override;
	CollectAnimation GetCollectItem() override;
	void OnFallEnded() override;
	ItemType GetItemType() override { return ItemType::GiantDuck; }
	int GetScore() override { return 10000; }
	bool CanCastShadow() override { return true; }
	bool CanBeExplodedBySpecialItem() override  { return false; }
	bool CanBeTapped() override { return false; }
	bool CanBeExplodedByBooster() override { return false; }
	bool BoosterAnvilCanBeUsed() override { return true; }
	bool BoosterBoxingGloveCanBeUsed() override { return true; }
	bool BoosterHammerCanBeUsed() override { return false; }
	bool CanFall() override;

	//void Squash(/*Sequence seq,*/ cocos2d::Node* rt, /*Transform rt,*/ float yScale, float time, float jumpEffect/*, Ease e = 1*/);	
	void Update(float);

protected:
	void PlayOnExplodeStartedAnimation() override {	}

private:
	/*[DebuggerHidden]*/
	/*IEnumerator*/ void PlayGiantDuckRescue();

	bool _inExplodeState = false;
	bool _statIncreased = false;
};


#endif //__ENGINE_GIANTDUCKITEM_H__
