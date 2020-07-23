#ifndef __ENGINE_ITEM_COLOREDBALLOON_H__
#define __ENGINE_ITEM_COLOREDBALLOON_H__

#include "../ItemImpl.h"
#include "../ItemFeature.h"

enum class CollectAnimation;
enum class ColoredBalloonType;

class ColoredBalloonItem : public SpriteBasedItem, public ICanBePaint
{
public:
	ColoredBalloonItem();
	virtual ~ColoredBalloonItem();

	void SetupItem(ColoredBalloonType type);
	void Paint(MatchType mType);
	virtual void RemoveSelf() override;

	int GetScore() override	{ return 500; }
	void PlayExplodeAudio() override;
	CollectAnimation GetCollectItem() override;
	bool CanBeTapped() override	{ return false; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return sourceType == GetMatchType(); }
	bool CanBeEffectedByDiscoBall() override { return false; }
	MatchType GetMatchType()  override { return this->_currentMatchType; }
	ItemType GetItemType() override { return ItemType::ColoredBalloon; }
	bool CanBePaint() override { return true; }
	bool CanCastShadow() override { return true; }

protected:
	void PlayOnExplodeStartedAnimation() override;

private:
	MatchType _currentMatchType = (MatchType)0;
	ColoredBalloonType _type = ColoredBalloonType::None;
};

#endif //__ENGINE_ITEM_COLOREDBALLOON_H__

