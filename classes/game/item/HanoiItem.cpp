#include "HanoiItem.h"
#include "../Extension.h"
#include "../Cell.h"

void HanoiItem::OnItemCreated(Level* currentLevel) {
	Item::OnItemCreated(currentLevel);
/*	this->_transformAnimation43.push_back(Animator.StringToHash("Base Layer.HanoiTransform4-3"));
	this->_transformAnimation43.push_back(Animator.StringToHash("Base Layer.HanoiTransform4-3vers2"));
	this->_transformAnimation43.push_back(Animator.StringToHash("Base Layer.HanoiTransform4-3vers3"));
	this->_transformAnimation32.push_back(Animator.StringToHash("Base Layer.HanoiTransform3-2"));
	this->_transformAnimation32.push_back(Animator.StringToHash("Base Layer.HanoiTransform3-2vers2"));
	this->_transformAnimation32.push_back(Animator.StringToHash("Base Layer.HanoiTransform3-2vers3"));
	this->_transformAnimation21.push_back(Animator.StringToHash("Base Layer.HanoiTransform2-1"));
	this->_transformAnimation21.push_back(Animator.StringToHash("Base Layer.HanoiTransform2-1vers2"));
	this->_transformAnimation21.push_back(Animator.StringToHash("Base Layer.HanoiTransform2-1vers3"));*/
}

void HanoiItem::ExplodeByBlasterItem() {
	this->RemoveAllLayers();
//	Item::ExplodeByBlasterItem();
}

void HanoiItem::PlayExplodeAudio() {
//	AudioManager.PlayAudioProps(this->Resources.AudioClips[1], PlayMode.Frame, null, 1f);
}

bool HanoiItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame()) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	if (this->_layerCount == 1) {
		return true;
	}
	this->_layerCount--;
	this->StartTranformationToNewLayer();
	return false;
}

void HanoiItem::PlayOnExplodeStartedAnimation() {
//	ParticlePool.Instance.PlayParticle(this->Resources.Particles[3], Item::get_transform().get_position(), true);
}

void HanoiItem::StartTranformationToNewLayer() {
	if (this->_transformSequenceId == -1) {
		this->_transformSequenceId = this->get_CurrentCell()->X + this->get_CurrentCell()->Y;
	}
	int layerCount = this->_layerCount;
	if (layerCount != 3) {
		if (layerCount != 2) {
			if (layerCount == 1) {
//				this->CurrentAnimator.Play(this->_transformAnimation21[this->_transformSequenceId % 3], -1, 0f);
			}
		}
		else {
//			this->CurrentAnimator.Play(this->_transformAnimation32[this->_transformSequenceId % 3], -1, 0f);
		}
	}
	else {
//		this->CurrentAnimator.Play(this->_transformAnimation43[this->_transformSequenceId % 3], -1, 0f);
	}
	int num = 3 - this->_layerCount;
//	AudioManager.PlayAudioProps(this->Resources.AudioClips[0], PlayMode.Frame, null, 1f);
//	AudioManager.FilterQueue(AudioTag.ClassicExplode);
//	ParticlePlayer particlePlayer = ParticlePool.Instance.PlayParticle(this->Resources.Particles[num], Item::get_transform().get_position(), true);
//	Quaternion identity = Quaternion.get_identity();
//	identity.set_eulerAngles((Random.Range(0, 10) <= 5) ? new Vector3(0f, 0f, 0f) : new Vector3(0f, 180f, 0f));
//	particlePlayer.MainParticle.get_transform().set_rotation(identity);
}