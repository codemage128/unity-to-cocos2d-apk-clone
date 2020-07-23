#ifndef __ENGINE_WATERMELONITEM_H__
#define __ENGINE_WATERMELONITEM_H__

#include "../ItemImpl.h"

class WatermelonItem : public Item
{
public:
	int LayerCount = 3;
	//Animator CurrentAnimator;

private:
//	int _state3To2 = Animator.StringToHash("Base Layer.Watermelon3-2");
//	int _state2To1 = Animator.StringToHash("Base Layer.Watermelon2-1");

public:
	std::vector<cocos2d::Sprite*> Renderers;
	cocos2d::Sprite* RendererRoot = nullptr;

public:
	WatermelonItem();
	~WatermelonItem();
	void SetupItem();
	virtual void RemoveSelf() override;

	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override { return true; }
	void RemoveAllLayers() override { this->LayerCount = 1; }
	int GetScore() override { return 500; }
	bool CanCastShadow() override { return true; }
	void PlayExplodeAudio() override;
	bool TryExplode() override;
	CollectAnimation GetCollectItem() override;
	ItemType GetItemType() override { return ItemType::WaterMelon; }

private:
	void StartTranformationToLayer();
//	/*IEnumerator*/void PlayDelayedParticle(GameObject particle);
	
protected:
	void PlayOnExplodeStartedAnimation() override;
};


#endif //__ENGINE_WATERMELONITEM_H__
