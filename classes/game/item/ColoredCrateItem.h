#ifndef __ENGINE_COLOREDCRATEITEM_H__
#define __ENGINE_COLOREDCRATEITEM_H__

#include "CrateItem.h"

enum class CollectAnimation;
enum class MatchType;

//class Animator;
class ColoredCrateItem : public CrateItem
{
public:
	ColoredCrateItem();
	virtual ~ColoredCrateItem();

	ItemType GetItemType() override {return ItemType::ColoredCrate; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return sourceType == this->_matchType; }
	bool CanShadowDrop() override { return true; }
	CollectAnimation GetCollectItem() override;

	//non override
	void SetupItem(TiledEditorId tiledEditorId);
	virtual void RemoveSelf() override;

protected:
	void PlayOnExplodeStartedAnimation() override;
	void StartTranformationToNewLayer() override;

private:
	MatchType _matchType = (MatchType)100;
	std::vector<cocos2d::Sprite*>* _imageGroup = nullptr;
};

#endif //__ENGINE_COLOREDCRATEITEM_H__

