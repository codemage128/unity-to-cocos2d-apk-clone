#include "OysterItem.h"
#include "../Level.h"
#include "../Animation.h"
#include "../Extension.h"
#include "../Level.h"
#include "../LevelBuilder.h"
#include "../Cell.h"
#include "../ImageLibrary.h"
#include "../ParticleLibrary.h"
#include "../FallManager.h"

void OysterItem::SetupItem() {
	auto _sprite = ParticleLibrary::cloneNodeForNodeModel(PTCLLIB->getOysterNode());
	CurrentSpriteRenderer->addChild(_sprite);
	_animation = PTCLLIB->getOysterAnim()->clone();
	_sprite->runAction(_animation);
	_animation->play("idle", true);
	_sprite->setPosition(0, -8);
}

void OysterItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void OysterItem::Awake() {
//	this->_openAnimationHash = Animator.StringToHash("Base Layer.OysterOpenAnimation");
//	this->_closeAnimationHash = Animator.StringToHash("Base Layer.OysterCloseAnimation");
}

void OysterItem::OnItemCreated(Level* currentLevel) {
	SpriteBasedItem::OnItemCreated(currentLevel);
	this->CurrentLevel->ExplodeAwareItem.push_back(this);
}


bool OysterItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame()) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	int latestTriggeredCount = this->_latestTriggeredCount;
	this->_latestTriggeredCount = this->CurrentLevel->get_MovesLeft();
	if (this->_state == 0) {
		this->MoveToState(1);
		return false;
	}
	this->_isDestroyed = (latestTriggeredCount - this->_latestTriggeredCount <= 1);
	if (this->_isDestroyed) {
//		AudioManager.Play(AudioTag.OysterExplode, PlayMode.Frame, nullptr, 1f);
		//this->CurrentLevel->ExplodeAwareItem.Renmove(this);
		this->CurrentLevel->ExplodeAwareItem.erase(std::find(this->CurrentLevel->ExplodeAwareItem.begin(), this->CurrentLevel->ExplodeAwareItem.end(), this));
	}
	return this->_isDestroyed;
}

CollectAnimation OysterItem::GetCollectItem() {
//	CollectAnimation* component = this->CurrentLevel->CurrentLevelBuilder->GenericCollectItem->Spawn(this->CurrentSpriteRenderer->get_transform().get_position()).GetComponent<CollectAnimation>();
//	component.Prepare(this->CurrentLevel, this->GetItemType(), currentSo rting, ImageLibrary.Instance.Pearl, this->CurrentCell);

	//CollectAnimation Prepare(Level currentLevel, ItemType goalType, S orting s, Sprite sprite, Cell currentCell) {
	//	this.CurrentLevel = currentLevel;
	//	currentLevel.PreCheckDecreaseGoal(goalType);
	CurrentLevel->PreCheckDecreaseGoal(GetItemType());
	//	if(this._increaseRequested) {
	//		return this;
	//	}
	//	currentLevel.StopRefillIfNeeded(goalType);
	CurrentLevel->StopRefillIfNeeded(GetItemType());
	//	this.ReferencedCell = currentCell;
	//	this._increaseRequested = true;
	//	this.GoalType = goalType;
	//	this.TopPanel = this.CurrentLevel.CurrentLevelBuilder.CurrentTopPanel;
	//	this.TopPanelGoalId = this.TopPanel.FindGoalIndex(this.GoalType);
	//	this._targetTransform = this.TopPanel.GoalUIList[this.TopPanelGoalId].GoalImage.get_transform();
	//	this.TargetPosition = this._targetTransform.get_position();
	//	FallManager.IncreaseStatAnimation();
	FallManager::getInstance()->IncreaseStatAnimation();
	//	if(sprite == null) {
	//		sprite = ImageLibrary.Instance.GetGoalSpriteByItemType(goalType);
	//	}
	//	this.GoalImageScale = this._targetTransform.get_parent().get_localScale().x * ImageLibrary.Instance.GoalImageScale(goalType);
	//	base.get_transform().set_localScale(Vector3.get_one());
	//	this.CollectSpriteRenderer.set_sprite(sprite);
	//	this.CollectSpriteRenderer.set_so rtingOrder(s.Order);
	//	this.CollectSpriteRenderer.set_so rtingLayerID(s.LayerId);
	//	CollectManager.Instance.Register(this);
	//	return this;
	//}

//	return component;
	return CollectAnimation::Instant;
}

void OysterItem::PlayOnExplodeStartedAnimation() {
//	if (ParticlePool.Instance != nullptr) {
//		ParticlePool.Instance.PlayParticle(ParticlePool.Instance.OysterExplosionParticle, base.get_transform().get_position(), true);
//	}
	PTCLLIB->explodeOyster(this->CurrentSpriteRenderer->getPosition());
}

void OysterItem::ExplosionOccured(int moveCount) {
	if (moveCount != this->_latestTriggeredCount) {
		this->MoveToState(0);
	}
}

void OysterItem::MoveToState(int i) {
	if (this->_isDestroyed || this->CurrentSpriteRenderer == nullptr || this->_state == i) {
		return;
	}
	this->_state = i;
	if (i != 0) {
		if (i == 1) {
//			this->CurrentAnimator.Play(this->_openAnimationHash, 0, 0f);
//			if (ParticlePool.Instance != nullptr) {
//				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.OysterOpenParticle, this, true);
//			}
//			AudioManager.Play(AudioTag.OysterOpen, PlayMode.Frame, nullptr, 1f);
			_animation->play("open", false);
		}
	}
	else {
//		this->CurrentAnimator.Play(this->_closeAnimationHash, 0, 0f);
//		if (ParticlePool.Instance != nullptr) {
//			ParticlePool.Instance.PlayParticle(ParticlePool.Instance.OysterCloseParticle, this, true);
//		}
		_animation->play("close", false);
	}
}

void OysterItem::BringToFront() {
	int order = 1300;
	if(this->get_CurrentCell() != nullptr) {
		order = 1300 + (10 - this->get_CurrentCell()->Y * 10);
	}
	this->_animationIsPlaying = true;
}

void OysterItem::SendToBack() {
	this->_animationIsPlaying = false;
	this->OnCellChanged();
}
