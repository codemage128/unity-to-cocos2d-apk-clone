#ifndef __ENGINE_STONEITEM_H__
#define __ENGINE_STONEITEM_H__

#include "../ItemImpl.h"
#include "cocos2d.h"

class StoneItemOder;

class StoneItem : public SpriteBasedItem
{
public:
	cocos2d::ParticleSystemQuad* AnimationParticle = nullptr;
	cocos2d::Node* EffectsContainer = nullptr;	// Transform
	std::vector<cocos2d::Sprite*> Tiles;
	std::vector<cocos2d::Sprite*> Effects;
//	Animator CurrentAnimator;
	StoneItem* MasterItem = nullptr;
	bool IsMasterItem = false;
	int StoneId = 0;
	int ExplosionOrder = 1000;

private:
	static int _globalStoneId;
	std::vector<StoneItem*> _children;
	int _layer = 5;
	std::vector<int> _cornerSortingOffsets;// = new int[4];
//	ItemResources _resources;
	const int Sprite_None = 0;
	const int Sprite_Bottom_1 = 1;
	const int Sprite_Bottom_2 = 2;
	const int Sprite_Bottom_3 = 3;
	const int Sprite_BottomCorner = 4;
	const int Sprite_Corner_A = 5;
	const int Sprite_Corner_B = 6;
	const int Sprite_Mid = 7;
	const int Sprite_Side_1 = 8;
	const int Sprite_Side_2 = 9;
	const int Sprite_Side_3 = 10;
	const int Sprite_Top_1 = 11;
	const int Sprite_Top_2 = 18;
	const int Sprite_TopCorner_Left = 12;
	const int Sprite_TopCorner_Right = 13;
	const int Sprite_Mid_70 = 14;
	const int Sprite_Side_1_70 = 15;
	const int Sprite_Side_2_70 = 16;
	const int Sprite_Side_3_70 = 17;
	const int Sprite_Effects_Count = 5;
	const int Sprite_Effects_Start_Index = 19;
	const int Sprite_State_1 = 29;
	const int Sprite_State_2 = 30;
	const int Sprite_State_3 = 31;
	const int Sprite_State_4 = 32;
	static std::vector<int> topSprites;
	static std::vector<int> bottomSprites;
	static std::vector<int> sideSprites;
	static std::vector<int> side70Sprites;
	static std::vector<int> stateSprites;
	int _animationStage2To1Hash = 0;// Animator.StringToHash("StoneItemAnimation2_1");
	bool _isExploded = false;

public:
	ItemType GetItemType() override { return ItemType::Stone; }
	int GetScore() override { return 500; }
	bool CanRaiseScore() override { return true; }
	bool CanFall() { return false; }
	bool CanShadowDrop() override { return true; }
	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	bool CanBeTapped() override { return false; }
	bool CanGenerateScoreWithoutExplode() override { return true; } 
	bool CanBeInsideBubble()/* override*/ { return false; }
	void PlayWrongMove() override { }

private:
	void UpdateSprites();
	void SetSprite(cocos2d::Sprite* spriteRenderer, bool x, bool y, Direction checkDirection, bool right, bool down);
	cocos2d::Sprite* SelectSprite(std::vector<int> spriteIndexes);
	void SetEffect();
	bool GetStoneItem(Cell* cell);
	void LinkNeighbours(Cell* cell);
	
public:
	void PlayExplodeAudio() override {}
	void PlayOnExplodeStartedAnimation() override;
	bool TryExplode() override;
	
private:
	void PrepareExplosionOrder(Cell* cell, int order);
	bool TransformToNextLayer();
	void PlayItemParticle(int particleIndex);
	void NotifyItemCollected();
	/*IEnumerator*/void StartExplosionChain(std::vector<StoneItemOder*> children);

public:
	void StartExplode() override;
	void RemoveSelf() override;

private:
	/*IEnumerator*/void Remove();
};

#endif // __ENGINE_STONEITEM_H__
