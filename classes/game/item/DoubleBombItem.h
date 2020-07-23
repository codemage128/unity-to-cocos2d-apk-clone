#ifndef __ENGINE_DOUBLEBOMBITEM_H__
#define __ENGINE_DOUBLEBOMBITEM_H__

#include "../SpecialItem.h"


class DoubleBombItem: public BombItem, public IComboItem {
private:
	std::vector<cocos2d::Node*>* _shakePanels;//	GameObject[] _shakePanels;

public:
	//	ParticleSystem[] CloseParticles;
	cocos2d::Sprite* GlowSprite=nullptr;
	//	Transform Shadow;
	//	GameObject MainContainer;
	//	ParticleSystem Sparks;
	//	ParticleSystem StarGlow;

protected:
	MatchGroup* ComboMatchGroup=nullptr;
	int ComboMergeScores=0;

	std::vector<Cell*> _neigbours;
	cocos2d::Vec2 _scorepos;
	int _score = 0;

public:
	void SetComboGroup(MatchGroup* mgroup) override { this->ComboMatchGroup = mgroup; }
	bool CanBeCapturedByJelly() override { return false; }
	void RemoveSelf() override;
	void AddScore(int v) override { this->ComboMergeScores += v; }
	ItemType GetItemType() override { return ItemType::DoubleBomb; }
	int GetScore() override { return 1000 + this->ComboMergeScores; }
	bool CanRaiseScore() override { return false; }

	void OnBeforeRemove() override;
	void AddShakeReferences(std::vector<cocos2d::Node*>* panels);

protected:
	void OnExplodeSelf() override;
	void PlayExplodeParticle() override;
	/*IEnumerator*/void ExplodeCells() override;

};

#endif //__ENGINE_DOUBLEBOMBITEM_H__