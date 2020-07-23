#ifndef __ENGINE_SODABOTTLE_H__
#define __ENGINE_SODABOTTLE_H__

#include "cocos2d.h"

class SodaBottle {
public:
	void SetupItem(cocos2d::Node* frame, int type);
	//	Animator CurrentAnimator;
	//std::vector<cocos2d::Sprite*> BottleSpriteRenderers;
	//cocos2d::Sprite* ShadowSpriteRenderer = nullptr;
	//ParticleSystemQuad* ShakeParticle;
	//ParticleSystemRenderer ShakeParticleSystemRenderer;
	cocos2d::Sprite* BottleSpriteRenderer = nullptr;
	//PeakFxColorChange CapColor;
	//PeakFxColorChange TopColor;

private:
	bool _isRemoved = false;
	//std::vector<int> _animations;

private:
	void Start();

public:
	void PlayShakeAnimation();
	void Remove();
	void OnDestroy();
};


#endif // __ENGINE_SODABOTTLE_H__