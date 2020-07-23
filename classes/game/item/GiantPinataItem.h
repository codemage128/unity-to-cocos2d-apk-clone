#ifndef __ENGINE_GIANTPINATAITEM_H__
#define __ENGINE_GIANTPINATAITEM_H__

#include "../Item.h"
#include "cocostudio/CocoStudio.h"

class GiantPinataFakeItem;
class SpecialItem;

class GiantPinataItem: public Item {
private:
	Direction _lastDirection = (Direction)0; //None

	int _explodeNo = 0;
	bool _exploded = false;
	std::map<SpecialItem*, float> _explodedBySpecialItemTime;
	float explodedByNonSpecialItem = 0;
	bool justExploded = false;
	bool _inExplode = false;

public:
	//	Animator GiantPinataAnimator;
	GiantPinataFakeItem* BottomRight = nullptr;
	GiantPinataFakeItem* TopLeft = nullptr;
	GiantPinataFakeItem* TopRight = nullptr;
	cocos2d::Sprite* BaseImage = nullptr;
	//cocos2d::Sprite* DonkeyMesh = nullptr;
	//cocos2d::Sprite* RopeMesh = nullptr;
	//	ParticleSystemQuad ToDownParticle;
	//	ParticleSystemQuad ToLeftParticle;
	//	ParticleSystemQuad ToRightParticle;
	//	ParticleSystemQuad ToUpParticle;
	//	ParticleSystemQuad FinalParticle;
	//	SpriteDeformerAnimation DonkeyImage;
	//	Transform DonkeyImagePosition;
	//	SpriteDeformerAnimation RopeImage;
	cocos2d::Node* _giantNode = nullptr;
	cocostudio::timeline::ActionTimeline* _giantAnim = nullptr;

public:
	GiantPinataItem();
	~GiantPinataItem();

	void SetupItem();
	virtual void RemoveSelf() override;

	Cell* get_CurrentCell() override;
	void set_CurrentCell(Cell* value) override;
	void SetLastDirection(Direction direction) { this->_lastDirection = direction; }
	int GetScore() override { return 5000; }
	void OnFallEnded() override;
	bool CanFall() override { return false; }
	ItemType GetItemType() override { return ItemType::GiantPinata; }
	void InformToBeExplodedBySpecialItem(SpecialItem* specialItem, Direction comingFrom) override;
	bool TryExplode() override;
	void StartExplode() override;
	CollectAnimation GetCollectItem() override;
	void PlayExplodeAudio() override;

private:
	//void EnableAndPlay(ParticleSystemQuad target);
	//void UpdateParticle(Component target, ParticleSystem target2);
	/*IEnumerator*/void ChangeImage();
};

#endif // __ENGINE_GIANTPINATAITEM_H__
