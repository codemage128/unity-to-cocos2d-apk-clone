#ifndef __ENGINE_BALLOONITEM_H__
#define __ENGINE_BALLOONITEM_H__

#include "../ItemImpl.h"

enum class MatchType;
enum class CollectAnimation;

class BalloonItem : public SpriteBasedItem
{
public:
	BalloonItem();
	virtual ~BalloonItem();
	void SetupItem();
	virtual void RemoveSelf() override;

	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	void BringToFront() override;
	void SendToBack() override { this->OnCellChanged(); }
	ItemType GetItemType() override { return ItemType::Balloon; }
	int GetScore() override { return 500; }
	bool CanCastShadow() override { return true; }
	void ReactToUpperFall() override;
	void PlayExplodeAudio() override;
	CollectAnimation GetCollectItem() override;

protected:
	void PlayOnExplodeStartedAnimation() override;
};

#endif //__ENGINE_BALLOONITEM_H__