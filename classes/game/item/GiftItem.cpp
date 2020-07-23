#include "GiftItem.h"
#include "../Extension.h"
#include "../Cell.h"

std::vector<int> GiftItem::_bounceAnimationHashes = std::vector<int>();
int GiftItem::_transformAnimationHash = 0;
int GiftItem::_bounceAnimationCount = 0;

void GiftItem::OnFallEnded() {
	Item::OnFallEnded();
	if (GiftItem::_bounceAnimationHashes.size() == 0) { //(GiftItem::_bounceAnimationHashes == nullptr)
//		GiftItem::_bounceAnimationHashes.push_back(Animator.StringToHash("Base Layer.SnowGlobeBounceAnimation1"));
//		GiftItem::_bounceAnimationHashes.push_back(Animator.StringToHash("Base Layer.SnowGlobeBounceAnimation2"));
//		GiftItem::_bounceAnimationHashes.push_back(Animator.StringToHash("Base Layer.SnowGlobeBounceAnimation3"));
//		GiftItem::_bounceAnimationHashes.push_back(Animator.StringToHash("Base Layer.SnowGlobeBounceAnimation4"));
//		GiftItem::_bounceAnimationHashes.push_back(Animator.StringToHash("Base Layer.SnowGlobeBounceAnimation5"));
	}
	GiftItem::_bounceAnimationCount++;
//	this->CurrentAnimator.Play(GiftItem::_bounceAnimationHashes[GiftItem::_bounceAnimationCount % 5], -1, 0f);
//	this->CurrentSnowParticlePlayer.Shake();
}

void GiftItem::PlayWrongMove() {
	Item::PlayWrongMove();
	if (this->_stateId == 1) {
//		this->CurrentSnowParticlePlayer.Shake();
	}
}

void GiftItem::ExplodeByBlasterItem() {
	this->_canFall = true;
	this->_stateId = 1;
//	Item::ExplodeByBlasterItem();
}

bool GiftItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame()) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	if (this->_stateId == 0) {
		this->_stateId = 1;
		this->TransformToSnowGlobe();
		return false;
	}
	return true;
}

void GiftItem::TransformToSnowGlobe() {
/*	if (ParticlePool.Instance != nullptr) {
		ParticlePool.Instance.PlayParticle(this->Resources.Particles[0], this->get_CurrentCell()->GetFrozenPosition(), true);
	}
	AudioManager.PlayAudioProps(this->Resources.AudioClips[0], PlayMode.Frame, nullptr, 1.0f);
	if (GiftItem::_transformAnimationHash == 0) {
		GiftItem::_transformAnimationHash = Animator.StringToHash("Base Layer.SnowGlobeTransitionAnimation");
	}
	this->CurrentAnimator.Play(GiftItem::_transformAnimationHash, -1, 0.0f);
	this->SnowGlobeContainer.SetActive(true);
	this->Renderers[4]->setVisible(false);
	this->CurrentSnowParticlePlayer.get_gameObject().SetActive(true);
	this->CurrentSnowParticlePlayer.Init();
	Sorting currentSorting = this->_currentSorting;
	currentSorting.Order += 15;
	this->CurrentSnowParticlePlayer.UpdateSorting(currentSorting);
	this->_canFall = true;
	this->CurrentSnowParticlePlayer.Shake();*/
}

void GiftItem::PlayExplodeAudio() {
//	AudioManager.PlayAudioProps(this->Resources.AudioClips[1], PlayMode.Frame, nullptr, 1f);
}

void GiftItem::PlayOnExplodeStartedAnimation() {
//	if (ParticlePool.Instance != nullptr) {
//		ParticlePool.Instance.PlayParticle(this->Resources.Particles[1], base.get_transform().get_position(), true);
//	}
}

