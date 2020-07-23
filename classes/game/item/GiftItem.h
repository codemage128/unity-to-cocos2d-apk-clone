#ifndef __ENGINE_GIFTITEM_H__
#define __ENGINE_GIFTITEM_H__

#include "../Item.h"
#include "cocos2d.h"

class GiftItem : public Item
{
public:
//	GameObject SnowGlobeContainer;
//	Animator CurrentAnimator;
//	SnowParticlePlayer CurrentSnowParticlePlayer;
	std::vector<cocos2d::Sprite*> Renderers;

private:
	int _snowGlobeShakeAnimationHash = 0;
	int _stateId = 0;
	static std::vector<int> _bounceAnimationHashes;
	static int _transformAnimationHash;
	static int _bounceAnimationCount;
	bool _canFall = false;

public:
	bool CanFall() override { return this->_canFall; }
	void OnFallEnded() override;
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	int GetScore() override { return 500; }
	ItemType GetItemType() { return ItemType::Gift; }
	void PlayWrongMove() override;
	void ExplodeByBlasterItem()/* override*/;
	bool TryExplode() override;

private:
	void TransformToSnowGlobe();
	
public:
	void PlayExplodeAudio() override;

protected:
	void PlayOnExplodeStartedAnimation() override;
};

#endif // __ENGINE_GIFTITEM_H__