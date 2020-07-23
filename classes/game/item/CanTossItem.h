#ifndef __ENGINE_CANTOSSITEM_H__
#define __ENGINE_CANTOSSITEM_H__

#include "../ItemImpl.h"

enum class CollectAnimation;
class CanBox;
class CanTossFakeItem;
class Level;

class CanTossItem: public SpriteBasedItem, public ICanExplodeAtLeast2 {
public:
	CanTossItem();
	virtual ~CanTossItem();

	void SetupItem();
	virtual void RemoveSelf() override;

	CanTossFakeItem* BottomRight = nullptr;
	CanTossFakeItem* TopLeft = nullptr;
	CanTossFakeItem* TopRight = nullptr;
	std::vector<CanBox*> Cans;
	cocos2d::Vec2 ExplodePosition;
	//Animator CanTossAnimation;

	int BombExplodeCount = 0;

	Cell* get_CurrentCell() override { return SpriteBasedItem::get_CurrentCell(); }
	void set_CurrentCell(Cell* value) override;
	ItemType GetItemType() override { return ItemType::CanToss; }
	int GetScore() override { return 250; }
	bool CanBeExplodedBySpecialItem() override { return true; }
	bool CanBeExplodedByBooster() override { return true; }
	bool CanFall() override { return false; }
	bool CanGenerateScoreOnEachTryExplode() override { return true; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	void StartCollect() override;
	bool TryExplode() override { return this->ExplodeBy(this); }
	void PlayExplodeAudio() override;

	//////// non override
	void Awake();
	bool ExplodeBy(Item* item);
	void CheckIfExtraExplodeNeeded();
	void MarkShouldExplodeAtLeast2() { this->BombExplodeCount++; }

protected:
	void PlayOnExplodeStartedAnimation() override;

private:
	int _canCount = 9;
	bool _isAnimationPlaying = false;
	bool _isExploded = false;
	int _canTossAnimationId = 0;

	/////////////////////
	/*static IEnumerator*/ void WaitAndAllowWin(Level* level);

	//SFX ChoseAudioTag() { return tags[audioTag++ % 3]; }
	void PlayShakeAnimation();
};


#endif //__ENGINE_CANTOSSITEM_H__
