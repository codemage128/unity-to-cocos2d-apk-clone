#include "DiamondItem.h"
#include "../Extension.h"
#include "../ParticleLibrary.h"
#include "../Level.h"
#include "../Cell.h"
#include "../ParticleLibrary.h"

USING_NS_CC;


void DiamondItem::SetupItem() {
	auto _sprite = PTCLLIB->cloneNodeForNodeModel(PTCLLIB->getDiamondNode());
	CurrentSpriteRenderer->addChild(_sprite);
	_sprite->setPosition(0, -1);
	_animation = PTCLLIB->getDiamondAnim()->clone();
	_sprite->runAction(_animation);
	_animation->play("idle", false);
}

void DiamondItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void DiamondItem::Awake() {
//	this->_transformToOpenHash = Animator.StringToHash("Base Layer.DiamondOpenAnimation");
//	this->_transformToCloseHash = Animator.StringToHash("Base Layer.DiamondCloseAnimation");
}

void DiamondItem::SwitchState() {
	if (this->get_CurrentCell() == nullptr || this->MasterItemExplode == Ext_getCurrentFrame()) {
		return;
	}
	this->_canBeExploded = !this->_canBeExploded;
	this->UpdateView(this->_canBeExploded, true);
}

void DiamondItem::UpdateView(bool isOn, bool playParticle/* = true*/) {
	this->_canBeExploded = isOn;
//	if (playParticle && ParticlePool.Instance != nullptr) {
//		ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DiamondTransformParticle, base.get_transform().get_position(), true);
//		AudioManager.Play(AudioTag.ItemDiamond1, PlayMode.Frame, nullptr, 1.0f);
//	}
//	SpriteBasedItem::StopAllCoroutines();
	this->WaitAndStartAnimation(this->_canBeExploded, playParticle);
}

/*IEnumerator*/ void DiamondItem::WaitAndStartAnimation(bool canBeExploded, bool playInstant) {
//case 0:
//	if(this.playInstant) {
//	}
//	this.$this.CurrentAnimator.Play(!this.canBeExploded ? this.$this._transformToCloseHash : this.$this._transformToOpenHash, 0, !this.playInstant ? ((float)1) : ((float)0));
	_animation->play(!this->_canBeExploded ? "close" : "open", false);
//	this.$current = null;
//	if(!this.$disposing) {
//		this.$PC = 1;
//	}
//	return true;
//
//case 1:
//	this.$PC = -1;
//	break;
}

void DiamondItem::PlayOnExplodeStartedAnimation() {
	PTCLLIB->explodeDiamond(this->CurrentSpriteRenderer->getPosition());
//	if (ParticlePool.Instance != nullptr) {
//		ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DiamondExplosionParticle, base.get_transform().get_position(), true);
//	}
}

void DiamondItem::OnItemCreated(Level* currentLevel) {
	SpriteBasedItem::OnItemCreated(currentLevel);
	this->CurrentLevel->ExplodeAwareItem.push_back(this);
}

bool DiamondItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame() || this->_isDestroyed) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	if (this->ToBeExplodedBy == ExplodeReason::Anvil || this->ToBeExplodedBy == ExplodeReason::BoxingGlove || this->ToBeExplodedBy == ExplodeReason::Hammer) {
		this->_isDestroyed = true;
		this->ToBeExplodedBy = ExplodeReason::None;
		return true;
	}
	if (this->_canBeExploded) {
		this->_isDestroyed = true;
		return true;
	}
	return false;
}

void DiamondItem::PlayExplodeAudio() {
//	AudioManager.Play(AudioTag.ItemDiamond2, PlayMode.Frame, nullptr, 1f);
}

void DiamondItem::ExplosionOccured(int moveCount) {
	if (this->_isDestroyed) {
		return;
	}
	this->SwitchState();
}

