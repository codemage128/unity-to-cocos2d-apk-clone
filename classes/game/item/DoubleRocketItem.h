#ifndef __ENGINE_DOUBLEROCKETITEM_H__
#define __ENGINE_DOUBLEROCKETITEM_H__

#include "../SpecialItem.h"

class Grid;

class DoubleRocketItem: public SpecialItem, public IComboItem {
private:
	Grid* _grid = nullptr;
	int _height = 0;
	float _screenDown = 0;
	float _screenLeft = 0;
	float _screenRight = 0;
	float _screenUp = 0;
	float _startDurationH = 0;
	float _startDurationV = 0;
	int _sx = 0;
	int _sy = 0;
	int _width = 0;
	int _score = 0;
	float _exitTime = 0;
	bool _waitLastRocketExit = true;

public:
	cocos2d::Sprite* HeadDown = nullptr;	// Transform
	cocos2d::Sprite* HeadLeft = nullptr;	// Transform
	cocos2d::Sprite* HeadRight = nullptr;	// Transform
	cocos2d::Sprite* HeadUp = nullptr;		// Transform
	//cocos2d::Node* HorizontalAnimation = nullptr;	// GameObject
	//cocos2d::Node* VerticalAnimation = nullptr;	// GameObject
	cocos2d::ParticleSystemQuad* TrailParticleDown = nullptr;		// ParticleSystem
	cocos2d::ParticleSystemQuad* TrailParticleLeft = nullptr;		// ParticleSystem
	cocos2d::ParticleSystemQuad* TrailParticleRight = nullptr;	// ParticleSystem
	cocos2d::ParticleSystemQuad* TrailParticleUp = nullptr;		// ParticleSystem

protected:
	MatchGroup* ComboMatchGroup = nullptr;
	int ComboMergeScores = 0;

public:
	void SetupItem();

	void SetComboGroup(MatchGroup* mgroup) override { this->ComboMatchGroup = mgroup; }
	void AddScore(int v) override { this->ComboMergeScores += v; }
	ItemType GetItemType() override { return ItemType::DoubleRocket; }
	bool CanBeCapturedByJelly() override { return false; }
	bool ShouldRejectFallInside() override { return false; }
	int GetScore() override { return 500 + this->ComboMergeScores; }

protected:
	void OnExplodeSelf() override;
	/*IEnumerator*/void ExplodeCells() override;
	/*TweenCallback*/void ExplodeLater(Grid* currentGrid, int x, int y);

private:
	void StepRocketH(/*Transform*/cocos2d::Node* rocket, int step, int direction/*, cocos2d::Vector<cocos2d::FiniteTimeAction*>& seq*/);
	void StepRocketV(/*Transform*/cocos2d::Node* rocket, int step, int direction/*, cocos2d::Vector<cocos2d::FiniteTimeAction*>& seq*/);
	void AllowFalls();
	/*IEnumerator*/void Die();
};

#endif //__ENGINE_DOUBLEROCKETITEM_H__
