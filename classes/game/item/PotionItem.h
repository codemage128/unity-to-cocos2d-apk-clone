#ifndef __ENGINE_POTIONITEM_H__
#define __ENGINE_POTIONITEM_H__

#include "../Item.h"
#include "../IExplodeAware.h"
#include "../Match.h"
#include "cocos2d.h"

class PotionItem : public Item, public IExplodeAware
{
public:
//	Animator CurrentAnimator;
	std::vector<cocos2d::Sprite*> SortingSprites;
	cocos2d::Sprite* SurfaceSpriteRenderer = nullptr;
	cocos2d::Sprite* SurfaceNextSpriteRenderer = nullptr;
	cocos2d::Sprite* InnerSpriteRenderer = nullptr;
	cocos2d::Sprite* InnerNextSpriteRenderer = nullptr;

private:
	static const std::vector<cocos2d::Color3B> SurfaceColors;

	cocos2d::Color4F _zeroAlpha = cocos2d::Color4F(1.0f, 1.0f, 1.0f, 0.0f);
	cocos2d::Color4F _fullAlpha = cocos2d::Color4F(1.0f, 1.0f, 1.0f, 1.0f);
	MatchType _matchType = MatchType::None;
	int _currentIndex = 0;
	bool _isDestroyed = false;
	std::vector<int> _dropAnimations;
	cocos2d::Sequence* _transformSequence = nullptr;

public:
	void OnItemCreated(Level* currentLevel) override;
	void Init(MatchType matchType) { this->_matchType = matchType; }
	ItemType GetItemType() override { return ItemType::Potion; }
	int GetScore() override { return 500; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return this->_matchType == sourceType; }
	bool CanBeInsideBubble() /*override*/ { return true; }
	bool CanCastShadow() override { return true; }
	bool TryExplode() override;
	void PlayExplodeAudio() override;

protected:
	void PlayOnExplodeStartedAnimation() override;

private:
	int TransformToColorByMatchType(MatchType matchType, bool instantColor = true);
	void PlayTransformAnimation(int nextIndex);
	
public:
	void ExplosionOccured(int moveCount);
	void OnFallEnded() override;
	void UpdateView()/* override*/;
};

#endif // __ENGINE_POTIONITEM_H__