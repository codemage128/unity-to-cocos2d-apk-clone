#ifndef __ENGINE_ITEMIMPL_H__
#define __ENGINE_ITEMIMPL_H__

#include "Item.h"
#include "ItemFeature.h"

#include "cocos2d.h"


class Tweener;
enum class MatchType;

class SpriteBasedItem: public Item {
public:
	cocos2d::Sprite* CurrentSpriteRenderer = nullptr;

	SpriteBasedItem();
	virtual ~SpriteBasedItem();
};

class SolidColorItem: public SpriteBasedItem, public ICanShowMatchHint, public ICanShowCurrentlyUnderTap, public ICanBePaint {
private:
	MatchType _currentMatchType = (MatchType)100/*NONE*/;
	//MoveToSpecialItemAnimation _currentMoveToSpecialItemAnimation = new MoveToSpecialItemAnimation();
	//Tween _highlightTween;
	ItemType _itemType = (ItemType)0;
public:
	cocos2d::Sprite* GlowSpriteRenderer = nullptr;
	cocos2d::Color3B HighlightColor;

	// Methods
public:
	SolidColorItem();
	~SolidColorItem();

	bool CanBeCapturedByJelly() override { return true; }
	bool CanBeMatchable() override { return true; }
	bool CanBePaint() override { return true; }
	bool CanBeReplacedByPreLevelBooster() override { return true; }
	bool CanShadowDrop() override { return true; }
	bool CanShowCurrentlyUnderTap() override { return true; }
	bool CanShowMatchHint() override { return true; }
	bool CanShuffle() override { return true; }
	ItemType GetItemType() override { return this->_itemType; }
	MatchType GetMatchType() override { return this->_currentMatchType; }
	int GetScore() override { return 10; }

	void HideCurrentlyUnderTap();
	Tweener* MoveToSpecialItem(Cell* targetCell);
	void OnBeforeRemove() override;
	void Paint(MatchType mType);
	void RemoveSelf() override;
	void SetupItem(ItemType type);
	virtual void ShowCurrentlyUnderTap() override;
	virtual void ShowMatchHint() override;

	CollectAnimation GetCollectItem() override;

protected:
	virtual void PlayOnExplodeStartedAnimation() override;
private:
	void RemoveHighlightTween();
	void ResetAfterPool();
};

class FrameItem: public SpriteBasedItem {
private:
	Item* _innerItem = nullptr;
	cocos2d::Vec2 _innerItemOriginalScale;

	cocos2d::Sprite* _frameSprite = nullptr;
public:
	void SetupItem();
	virtual void RemoveSelf() override;

	bool CanFall() override { return false; }
	bool CanBeTapped() override { return false; }
	bool CanShadowDrop() override { return true; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	int GetScore() override { return 0; }
	ItemType GetItemType() override { return ItemType::Frame; }

	Item* get_InnerItem() { return this->_innerItem; }
	void set_InnerItem(Item* value);
	Item* ExtractSubItem() override;
	void PlayExplodeAudio() override;

protected:
	void PlayOnExplodeStartedAnimation() override;
};


enum class ColoredBalloonType {
	None,
	Balloon1,
	Balloon2,
	Balloon3,
	Balloon4,
	Balloon5,
	Balloon6
};

#endif //__ENGINE_ITEMIMPL_H__