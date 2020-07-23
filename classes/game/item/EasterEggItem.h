#ifndef __ENGINE_EASTEREGGITEM_H__
#define __ENGINE_EASTEREGGITEM_H__


#include "../ItemImpl.h"

enum class CollectAnimation;

typedef cocos2d::Color4F Color;
class EasterEggItem : public SpriteBasedItem
{
public:
	EasterEggItem();
	virtual ~EasterEggItem();

	void SetupItem();
	virtual void RemoveSelf() override;

	MatchType EffectiveType = (MatchType)100;

	//SpriteRenderer BlurSpriteRenderer;
	//SpriteRenderer EggLinesRenderer;
	//SpriteRenderer EggLinesRenderer2;
	//Animator TransformationAnimator;

	Color GreenMain = Color(0.07450981f, 0.933333337f, 0.329411775f, 1.0f);
	Color RedMain = Color(1.0f, 0.211764708f, 0.211764708f, 1.0f);
	Color BlueMain = Color(0.6431373f, 1.0f, 1.0f, 1.0f);
	Color YellowMain = Color(1.0f, 0.9098039f, 0.0235294122f, 1.0f);
	Color PurpleMain = Color(0.858823538f, 0.329411775f, 1.0f, 1.0f);
	Color OrangeMain = Color(1.0f, 0.6392157f, 0.02745098f, 1.0f);
	Color GreenParticle = Color(0.156862751f, 0.9254902f, 0.192156866f, 1.0f);
	Color RedParticle = Color(1.0f, 0.211764708f, 0.211764708f, 1.0f);
	Color BlueParticle = Color(0.141176477f, 0.6039216f, 1.0f, 1.0f);
	Color YellowParticle = Color(1.0f, 1.0f, 0.384313732f, 1.0f);
	Color PurpleParticle = Color(0.7372549f, 0.20784314f, 0.78039217f, 1.0f);
	Color OrangeParticle = Color(1.0f, 0.56078434f, 0.0f, 1.0f);

	bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) override;
	void TransformationEnded();

	bool TryExplode() override;
	int GetScore() override { return 500; }
	bool CanCastShadow() override { return true; }
	CollectAnimation GetCollectItem() override;
	void PlayExplodeAudio() override;
	ItemType GetItemType() override	{ return ItemType::EasterEgg; }

protected:
	void PlayOnExplodeStartedAnimation() override;

private:
	//[DebuggerHidden]
	/*static IEnumerator void ExplodeParticle(ParticlePlayer easterEggTransformParticle, float delay)
	{
		EasterEggItem.<ExplodeParticle>c__Iterator0 <ExplodeParticle>c__Iterator = new EasterEggItem.<ExplodeParticle>c__Iterator0();
		<ExplodeParticle>c__Iterator.delay = delay;
		<ExplodeParticle>c__Iterator.easterEggTransformParticle = easterEggTransformParticle;
		return <ExplodeParticle>c__Iterator;
	} //*/

	void PlayTransformationAnimation();

	bool _transformationApplied = false;
};


#endif //__ENGINE_EASTEREGGITEM_H__
