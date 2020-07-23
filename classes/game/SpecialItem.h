#ifndef __ENGINe_SPECIALITEM_H_
#define __ENGINe_SPECIALITEM_H_

#include "ItemImpl.h"

#include "cocos2d.h"

class Cell;
class Grid;
class Tweener;

class SpecialItem: public SpriteBasedItem {
private:
	//MoveToSpecialItemAnimation _currentMoveToSpecialItemAnimation = new MoveToSpecialItemAnimation();
	Cell* _lastCell = nullptr;
	bool _explodesCompleted = false;
	void _onExplodesCompleted();
	bool _jellyExploded = false;

public:
	bool CanNotJoinToCombo = false;
	bool SpecialItemCanOnlyExplodeSelf = false;
	bool isExploded = false;

	cocos2d::Node* CurrentComboHintParticle = nullptr;

	Cell* get_CurrentCell() override { return SpriteBasedItem::get_CurrentCell(); }
	void set_CurrentCell(Cell* value) override;

	virtual bool ShouldBlockFalls() { return true; }
	virtual bool ShouldRejectFallInside() { return true; }
	bool CanBeCapturedByJelly() override { return true; }
	bool CanRaiseScore()  override { return false; }
	bool IsSpecialItem() override { return true; }
	Tweener* MoveToComboItem(Cell* targetCell);
	void OnBeforeRemove() override;
	void AfterPoolInit() override;
	virtual void PlaySpecialItemCreationAnimation();
	/*IEnumerator*/void StartAutoExplode(float blockerTween);
	void DisplayComboHint(bool canGenerateCombo);
	void StartExplode() override;
	bool TryExplode() override;

	static int GetScoreForSpecialItem(Item* ci, Cell* c);
protected:
	virtual/*IEnumerator*/void ExplodeCells() = 0;
	std::function<void()> afterExplodeCells = nullptr;
	virtual void OnExplodeSelf() {}
	virtual bool ExplodeBySpecialItem(Cell* cell);
};


class HorizontalRocketItem: public SpecialItem {
public:
	static float ExplodeTime;
	static float Offset;
protected:
	Grid* grid = nullptr;
	int Width = 0;
	int Height = 0;
	int ScoreGained = 0;
	float ScreenDown = 0.0f;
	float ScreenLeft = 0.0f;
	float ScreenRight = 0.0f;
	float ScreenUp = 0.0f;
	float StartDuration = 0.0f;
	int Sx = 0;
	int Sy = 0;
	bool WaitLastRocketExit = true;
	bool RejectFallsInside = true;
	float ExitTime = 0.0f;

public:
	//GameObject ExplodeAnimation;
	cocos2d::Sprite* Head1 = nullptr;
	cocos2d::ParticleSystemQuad* Head1TrailParticle = nullptr;
	cocos2d::Sprite* Head2 = nullptr;
	cocos2d::ParticleSystemQuad* Head2TrailParticle = nullptr;

private:
	bool _isPositionsUpdated = false;
	cocos2d::Vec2 Head1Position;
	cocos2d::Vec2 Head2Position;

public:
	void SetupItem();

	bool ShouldRejectFallInside() override { return false; }
	void AllowBlockFalls() { this->RejectFallsInside = false; }
	bool ShouldBlockFalls() override { return this->RejectFallsInside; }
	int GetScore() override { return 250; }
	virtual bool IsHorizantal() { return true; }
	ItemType GetItemType() override { return ItemType::Rocket; }

	void OnBeforeRemove() override;
	void AfterPoolInit() override;
	void RemoveSelf() override;
	void SwitchToUseMode(bool head1Active = true, bool head2Active = true, bool playExplosionParticle = true, bool playParticle1 = true, bool playParticle2 = true);
	/*IEnumerator*/void Die();

private:
	void StepRocket(cocos2d::Node* rocket, int step, int direction/*, cocos2d::Vector<cocos2d::FiniteTimeAction*>& seq*/);
	void AcceptFallsInCurrentRow();

protected:
	/*TweenCallback*/ void ExplodeLater(Grid* currentGrid, int x, int y);
	virtual /*IEnumerator*/void ExplodeCells() override;
};

class VerticalRocketItem: public HorizontalRocketItem {
public:
	void SetupItem();

	bool IsHorizantal() override { return false; }
	bool CanCastShadow() override { return true; }

protected:
	virtual/*IEnumerator*/void ExplodeCells() override;
private:
	void StepRocket(cocos2d::Node* rocket, int step, int direction/*, cocos::Vector<cocos2d::FiniteTimeAction*>& seq*/);
	void AcceptFallsInCurrentColoumn();
};


class BombItem: public SpecialItem {
public:
	cocos2d::ParticleSystemQuad* _wickParticle = nullptr;
	//ParticleSystemRenderer Particle1;
	//ParticleSystemRenderer Particle2;
	//ParticleSystemRenderer Particle3;

private:
	float _explodeDelay = 0.1f;

	// ExplodeCells internal usages
	std::vector<Cell*> __neighbours;
	cocos2d::Vec2 __scorepos;

protected:
	std::vector<ICanExplodeAtLeast2*> MoreEffectedItems;

public:
	void SetupItem();

	virtual void PlayExplodeParticle();

	ItemType GetItemType() override { return ItemType::Bomb;}
	bool CanCastShadow() override { return true;}
	int GetScore() override {return 500;}

	void AfterPoolInit() override;
	void RemoveSelf() override;

protected:
	/*IEnumerator*/void ExplodeCells() override;
	void ExplodeMoreIfNeeded();
	void MarkShouldExplodeAtLeast2(Item* item);
	std::vector<Cell*> GetNeigbours(int size);
};

class DiscoBallItem: public SpecialItem {
public:
	static cocos2d::Vec3 HueYellow;
	static cocos2d::Vec3 HueRed;
	static cocos2d::Vec3 HueBlue;
	static cocos2d::Vec3 HueGreen;
	static cocos2d::Vec3 HuePurple;
	static cocos2d::Vec3 HueOrange;

	MatchType EffectiveItemType = (MatchType)0;
	//ParticleSystemRenderer[] ExplodeParticleRenderers;
	//GameObject UseParticle;
	//PeakFxColorChange AnimationSpriteColor;
	//PeakFxColorChange SpeedEffectColor;
	//Animator ExplodeAnimator;
	//SpriteRenderer ExplodeSpriteRenderer;
	//ParticleSystem StartAnimationParticle;
	cocos2d::Node* startAnimation=nullptr;
	//ParticleSystem StartExplodeParticle;

protected:
	static cocos2d::Vec2 ParticleStartOffset;

	bool _raysEnded = false;
	virtual void _onRaysEnded();
	int Score = 0;

	Grid* currentGrid;
	cocos2d::Vec2 originPos;
	std::vector<cocos2d::ParticleSystemQuad*> rayParticles;
	std::vector<Cell*> explodeCells;
private:
	static cocos2d::Vec2 ParticleEndOffset;

public:
	ItemType GetItemType() override { return ItemType::DiscoBall; }
	int GetScore() override { return 1000; }
	bool CanCastShadow() override { return true; }

	void OnBeforeRemove() override;
	void AfterPoolInit() override;
	void RemoveSelf() override;
	void SetTintColor(MatchType matchType);
	void PlaySpecialItemCreationAnimation() override;

protected:
	/*IEnumerator*/void ExplodeCells() override;
	virtual void DoDie();
	virtual void PlayRayParticle(/*DiscoRayParticlePlayer*/cocos2d::ParticleSystemQuad* p);
	virtual /*IEnumerator*/void DoDiscoExpldoes(std::vector<Cell*>& explodeCells);
	virtual /*IEnumerator*/void OnRayReached(Cell* cell, Item* i, cocos2d::FiniteTimeAction* tweener, cocos2d::ParticleSystemQuad* p);

private:
	/*IEnumerator*/void Die();
	void MoveRay(Cell* cell, cocos2d::ParticleSystemQuad* p);
};

class MatchGroup;

class IComboItem {
public:
	virtual void AddScore(int v) = 0;
	virtual void SetComboGroup(MatchGroup* mgroup) = 0;
};

#endif //__ENGINe_SPECIALITEM_H_