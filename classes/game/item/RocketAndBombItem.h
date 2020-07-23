#ifndef __ENGINE_ROCKETANDBOMBITEM_H__
#define __ENGINE_ROCKETANDBOMBITEM_H__

#include "../SpecialItem.h"

class Grid;

class RocketAndBombItem : public SpecialItem, public IComboItem
{
public:
	cocos2d::Node* InUseObjects=nullptr;
//	ParticleSystem RocketAndBombParticle1;
//	ParticleSystem RocketAndBombParticle2;
	cocos2d::Node* InUseAnimation=nullptr;
//	Animator TheAnimator;

protected:
	MatchGroup* ComboMatchGroup=nullptr;
	int ComboMergeScores=0;

private:
	int _score;
	const float RocketSpeed = 0.1f;//0.07f;

	//---used by IEnumerator
	cocos2d::Vec2 __originPos;
	Grid* __currentGrid = nullptr;
	int __width = 0;
	int __height = 0;
	int __yAtExplodeTime = 0;
	int __xAtExplodeTime = 0;
	HorizontalRocketItem* hrockets[6];
	VerticalRocketItem* vrockets[6];
	
public:
	void SetComboGroup(MatchGroup* mgroup) override { this->ComboMatchGroup = mgroup; }
	bool CanBeCapturedByJelly() override { return false; }
	void AddScore(int v) override { this->ComboMergeScores += v; }
	ItemType GetItemType() override { return ItemType::RocketAndBomb; }
	int GetScore() override { return 750 + this->ComboMergeScores; }

private:
	int Explode(Grid* currentGrid, int x, int y);
	/*IEnumerator*/void DoHorizantalMove(HorizontalRocketItem* horizontalRocketItem, cocos2d::Vec2 position, int height, int xAtExplodeTime, Grid* currentGrid, int y, int width, int direction);
	/*IEnumerator*/void DoVerticalMove(VerticalRocketItem* verticalrocketItem, cocos2d::Vec2 position, int height, int yAtExplodeTime, Grid* currentGrid, int x, int width, int direction);
	
protected:
	/*IEnumerator*/void ExplodeCells() override;
	void OnExplodeSelf() override {};
};

#endif //__ENGINE_ROCKETANDBOMBITEM_H__