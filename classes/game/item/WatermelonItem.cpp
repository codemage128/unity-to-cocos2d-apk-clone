#include "WatermelonItem.h"
#include "../Extension.h"
#include "../Animation.h"
#include "../ImageLibrary.h"
#include "../ParticleLibrary.h"
#include "../Level.h"
#include "../FallManager.h"

WatermelonItem::WatermelonItem() {
	RendererRoot = cocos2d::Sprite::create();
	RendererRoot->retain();

	Renderers.resize(3, nullptr);
	Renderers[0] = cocos2d::Sprite::create(); RendererRoot->addChild(Renderers[0]);
	Renderers[1] = cocos2d::Sprite::create(); RendererRoot->addChild(Renderers[1]);
	Renderers[2] = cocos2d::Sprite::create(); RendererRoot->addChild(Renderers[2]);
}

WatermelonItem::~WatermelonItem() {
	RendererRoot->release();
}

void WatermelonItem::SetupItem() {
	for(int i = 0; i < 3; i++) {
		ImageLibrary::CopySprite(Renderers[i], IMGLIB->WaterMelonSprites[i]); RendererRoot->addChild(Renderers[i]);
		Renderers[i]->setLocalZOrder(-i);
		Renderers[i]->setPosition(0, -10);
	}
}


void WatermelonItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->RendererRoot->removeFromParentAndCleanup(true);
	//delete this;
}

void WatermelonItem::PlayExplodeAudio() {
//	AudioManager.Play(AudioTag.ItemWaterMelon2, PlayMode.Frame, null, 1f);
}

bool WatermelonItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame()) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	if (this->LayerCount == 1) {
		return true;
	}
	this->LayerCount--;
//	AudioManager.Play(AudioTag.ItemWaterMelon1, PlayMode.Frame, null, 1f);
	this->StartTranformationToLayer();
	return false;
}

CollectAnimation  WatermelonItem::GetCollectItem() {
	//CollectAnimation* collectItem = Item::GetCollectItem();
//	collectItem->get_transform().set_position(this->Renderers[0]->get_transform().get_position());

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

	return CollectAnimation::Instant;
}

void WatermelonItem::StartTranformationToLayer() {
	if (this->LayerCount == 2) {
//		Item::StartCoroutine(this->PlayDelayedParticle(ParticlePool.Instance.WaterMelonStateParticle1));
//		this->CurrentAnimator.Play(this->_state3To2, 0, 0f);
		PTCLLIB->explodeWatermelon1(this->RendererRoot->getPosition());
		Renderers[0]->setVisible(false);
	}
	else if (this->LayerCount == 1) {
//		Item::StartCoroutine(this->PlayDelayedParticle(ParticlePool.Instance.WaterMelonStateParticle2));
//		this->CurrentAnimator.Play(this->_state2To1, 0, 0f);
		PTCLLIB->explodeWatermelon1(this->RendererRoot->getPosition());
		Renderers[1]->setVisible(false);
	}
//	AudioManager.Play(AudioTag.ItemWaterMelon1, PlayMode.Frame, null, 1f);
}

///*IEnumerator*/void WatermelonItem::PlayDelayedParticle(GameObject particle) {
//case 0:
//	this.$current = new WaitForSeconds(0.04f);
//	if(!this.$disposing) {
//		this.$PC = 1;
//	}
//	return true;
//
//case 1:
//	if(ParticlePool.Instance != null) {
//		ParticlePool.Instance.PlayParticle(this.particle, this.$this.get_transform().get_position(), true);
//	}
//	this.$PC = -1;
//	break;
//}

void WatermelonItem::PlayOnExplodeStartedAnimation() {
//	if (ParticlePool.Instance != null) {
//		ParticlePool.Instance.PlayParticle(ParticlePool.Instance.WaterMelonExplosionParticle, base.get_transform().get_position(), true);
//	}
	PTCLLIB->explodeWatermelon2(this->RendererRoot->getPosition());
}

