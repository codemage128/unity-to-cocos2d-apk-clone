#include "PotionItem.h"
#include "../Level.h"
#include "../Extension.h"
#include "../ImageLibrary.h"
#include "../Mathf.h"

const std::vector<cocos2d::Color3B> PotionItem::SurfaceColors = {
	cocos2d::Color3B(255*0.996078432f,	255*0.9647059f,		255*0.7647059f),
	cocos2d::Color3B(255*0.9882353f,	255*0.6431373f,		255*0.6f),
	cocos2d::Color3B(255*0.6666667f,	255*0.8980392f,		255*0.992156863f),
	cocos2d::Color3B(255*0.8627451f,	255*0.992156863f,	255*0.7294118f),
	cocos2d::Color3B(255*0.8980392f,	255*0.698039234f,	255*0.9882353f),
	cocos2d::Color3B(255*0.992156863f,	255*0.8235294f,		255*0.6039216f)
};

void PotionItem::OnItemCreated(Level* currentLevel) {
	Item::OnItemCreated(currentLevel);
	this->CurrentLevel->ExplodeAwareItem.push_back(this);
	this->_dropAnimations.clear();
//	this->_dropAnimations.push_back(Animator.StringToHash("Base Layer.PotionDropAnimation1"));
//	this->_dropAnimations.push_back(Animator.StringToHash("Base Layer.PotionDropAnimation2"));
//	this->_dropAnimations.push_back(Animator.StringToHash("Base Layer.PotionDropAnimation3"));
	this->UpdateView();
}

bool PotionItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame()) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	this->_isDestroyed = true;
	return true;
}

void PotionItem::PlayExplodeAudio() {
//	AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this->GetItemType()).AudioClips[3], PlayMode.Frame, null, 1f);
}

void PotionItem::PlayOnExplodeStartedAnimation() {
//	ItemResources resources = ItemResourcesManager.Instance.GetResources(this->GetItemType());
//	if (ParticlePool.Instance != nullptr && resources != nullptr) {
//		PotionParticlePlayer component = ParticlePool.Instance.PlayParticle(resources.Particles[1], Item::get_transform().get_position(), true).GetComponent<PotionParticlePlayer>();
//		component.SetColor(this->_matchType);
//	}
}

int PotionItem::TransformToColorByMatchType(MatchType matchType, bool instantColor) {
	int num;
	switch (matchType) {
	case MatchType::Yellow: num = 0; break;
	case MatchType::Red: num = 1; break;
	case MatchType::Blue: num = 2; break;
	case MatchType::Green: num = 3; break;
	case MatchType::Purple: num = 4; break;
	case MatchType::Orange: num = 5; break;
	default: num = -1; break;
	}
	if (num == -1) {
//		this->InnerSpriteRenderer.set_sprite(null);
		return num;
	}
	if (instantColor) {
//		ItemResources resources = ItemResourcesManager.Instance.GetResources(this->GetItemType());
//		this->InnerSpriteRenderer.set_sprite(resources.Sprites[num]);
		this->SurfaceSpriteRenderer->setColor(PotionItem::SurfaceColors[num]);
	}
	return num;
}

void PotionItem::PlayTransformAnimation(int nextIndex) {
	if (nextIndex == -1) {
		return;
	}
/*	this->_transformSequence = DOTween.Sequence();
	ItemResources resources = ItemResourcesManager.Instance.GetResources(this->GetItemType());
	this->InnerNextSpriteRenderer.set_sprite(resources.Sprites[nextIndex]);
	this->InnerNextSpriteRenderer.set_color(this->_zeroAlpha);
	Color surfaceNextColor = PotionItem.SurfaceColors[nextIndex];
	surfaceNextColor.a = 0f;
	this->SurfaceNextSpriteRenderer.set_color(surfaceNextColor);
	TweenSettingsExtensions.Insert(this->_transformSequence, 0f, ShortcutExtensions43.DOFade(this->InnerSpriteRenderer, 0.8f, 0.5f));
	TweenSettingsExtensions.Insert(this->_transformSequence, 0f, ShortcutExtensions43.DOFade(this->InnerNextSpriteRenderer, 1f, 0.5f));
	TweenSettingsExtensions.Insert(this->_transformSequence, 0f, ShortcutExtensions43.DOFade(this->SurfaceSpriteRenderer, 0.8f, 0.5f));
	TweenSettingsExtensions.Insert(this->_transformSequence, 0f, ShortcutExtensions43.DOFade(this->SurfaceNextSpriteRenderer, 1f, 0.5f));
	if (ParticlePool.Instance != null && resources != null)
	{
		PotionParticlePlayer component = ParticlePool.Instance.PlayParticle(resources.Particles[0], this, true).GetComponent<PotionParticlePlayer>();
		component.SetColor(this->_matchType);
		ItemResources.AudioProps audioProps = resources.AudioClips[Random.Range(0, 3)];
		AudioManager.PlayAudioProps(audioProps, PlayMode.Frame, null, 1f);
	}
	TweenSettingsExtensions.OnComplete<Sequence>(this->_transformSequence, delegate
	{
		this->InnerSpriteRenderer.set_sprite(this->InnerNextSpriteRenderer.get_sprite());
		this->InnerSpriteRenderer.set_color(this->_fullAlpha);
		this->InnerNextSpriteRenderer.set_color(this->_zeroAlpha);
		surfaceNextColor.a = 1f;
		this->SurfaceSpriteRenderer.set_color(surfaceNextColor);
		surfaceNextColor.a = 0f;
		this->SurfaceNextSpriteRenderer.set_color(surfaceNextColor);
	});*/
}

void PotionItem::ExplosionOccured(int moveCount) {
	if (this->_isDestroyed) {
		return;
	}
//	this->_matchType = this->CurrentLevel->GetNextMatchType(this->_currentIndex);
//	TweenExtensions.Kill(this->_transformSequence, false);
//	this->PlayTransformAnimation(this->TransformToColorByMatchType(this->_matchType, false));
}

void PotionItem::OnFallEnded() {
	Item::OnFallEnded();
//	this->CurrentAnimator.Play(this->_dropAnimations[Mathf::Random::Range(0, 3)], 0, 0.0f);
}

void PotionItem::UpdateView() {
//	this->_currentIndex = this->CurrentLevel->GetPotionMatchTypeIndex(this->_matchType);
	if (this->_currentIndex == -1) {
//		this->_matchType = this->CurrentLevel->GetRandomMatchType(this->_currentIndex);
	}
	this->TransformToColorByMatchType(this->_matchType, true);
}
