#ifndef __ENGINE_DOUBLEDISCOBALLITEM_H__
#define __ENGINE_DOUBLEDISCOBALLITEM_H__

#include "../SpecialItem.h"

class DoubleDiscoBallItem: public SpecialItem, public IComboItem {
public:
	cocos2d::ParticleSystem* ExplodeParticle;	// ParticleSystem
	cocos2d::ParticleSystem* RingParticle;		// ParticleSystem
	cocos2d::Node* ExplodeContainer;	// GameObject
	cocos2d::Node* AnimationContainer;	// GameObject
	cocos2d::Sprite* BackgroundSprite;

private:
	//	Material _gradientMaterial;

protected:
	MatchGroup* ComboMatchGroup = nullptr;
	int ComboMergeScores = 0;

	cocos2d::Vec2 originPos;
	Grid* __currentGrid = nullptr;
	std::map<int, std::set<Cell*>> __circle;
	int __score = 0;

public:
	void SetComboGroup(MatchGroup* mgroup) override { this->ComboMatchGroup = mgroup; }
	bool CanBeCapturedByJelly() override { return false; }
	void AddScore(int v) override { this->ComboMergeScores += v; }
	ItemType GetItemType() override { return ItemType::DoubleDiscoBall; }
	int GetScore() { return 8000 + this->ComboMergeScores; }

protected:
	/*IEnumerator*/void ExplodeCells() override;

private:
	/*IEnumerator*/void WaitForAnimationComplete();

	std::map<int, std::set<Cell*>> GetCircles(Grid* grid, Cell* centerPoint);
};

#endif //__ENGINE_DOUBLEDISCOBALLITEM_H__