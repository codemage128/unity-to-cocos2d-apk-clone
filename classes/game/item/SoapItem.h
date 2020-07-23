#ifndef __ENGINE_SOAPITEM_H__
#define __ENGINE_SOAPITEM_H__

#include "../Item.h"
#include "cocos2d.h"

class SoapItem : public Item
{
public:
	std::vector<cocos2d::Sprite*> SpriteRenderers;

private:
	bool _isDestroyed = false;
	bool _canGenerateScore = true;
	cocos2d::Vec2 LastPosition;
public:
	cocos2d::Vec2 get_LastPosition() { return LastPosition; };
	void set_LastPosition(cocos2d::Vec2 value) { LastPosition = value; };
	ItemType GetItemType() override { return ItemType::Soap; }
	bool CanBeTapped() override { return true; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	bool CanGenerateScoreOnEachTryExplode() override { return this->_canGenerateScore; }
	bool TryExplode() override; 

private:
	/*IEnumerator*/void ExplodeNextFrame();
	void PlayBubbleAnimation(std::vector<Cell*> cells);
	
protected:
	void PlayOnExplodeStartedAnimation() override;

public:
	int GetScore() override { return 500; }
	bool CanCastShadow() override { return true; }
};

#endif // __ENGINE_SOAPITEM_H__
