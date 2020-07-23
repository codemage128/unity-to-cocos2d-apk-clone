#include "LightBulbItem.h"

#include "../Animation.h"
#include "../Extension.h"
#include "../ParticleLibrary.h"
#include "../ImageLibrary.h"
#include "../Level.h"
#include "../FallManager.h"

void LightBulbItem::SetupItem() {
	ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->LightBulbOff);
	cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	newrect.origin.y -= 22.0f; newrect.size.height += 22.0f;
	CurrentSpriteRenderer->setTextureRect(newrect);

	LightOnBulb = cocos2d::Sprite::create();
	CurrentSpriteRenderer->addChild(LightOnBulb);
	ImageLibrary::CopySprite(this->LightOnBulb, IMGLIB->LightBulb);
	LightOnBulb->setPosition(44, 60);
	LightOnBulb->setVisible(false);
	LightOnBulb->setCascadeOpacityEnabled(false);
}

void LightBulbItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void LightBulbItem::PlayExplodeAudio() {
//	AudioManager.Play(AudioTag.ItemLightbulb2, PlayMode.Frame, null, 1f);
}

bool LightBulbItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame()) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	if (this->LayerCount == 1) {
		return true;
	}
	this->LayerCount--;
//	AudioManager.Play(AudioTag.ItemLightbulb1, PlayMode.Frame, null, 1f);
	this->StartTranformationToLayer1();
	return false;
}

CollectAnimation LightBulbItem::GetCollectItem() {
	//CollectAnimation* collectItem = SpriteBasedItem::GetCollectItem();
//	collectItem->get_transform().set_position(this->CurrentSpriteRenderer.get_transform().get_position());

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

void LightBulbItem::StartTranformationToLayer1() {
	if (this->LayerCount != 1) {
		return;
	}

	//base.CurrentSpriteRenderer.set_enabled(false);
	this->CurrentSpriteRenderer->setOpacity(0);
//	this->LightOnBulb.get_gameObject().SetActive(true);
	this->LightOnBulb->setVisible(true);
	PTCLLIB->turnonLightBulb(this->CurrentSpriteRenderer->getPosition());
//	So rtingParticlePlayer sor tingParticlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.LightBulbStateChange, this->RelativeContainer.get_transform().get_position(), true) as Sor tingParticlePlayer;
//	so rtingParticlePlayer.Sor t(this->CurrentSpriteRenderer.get_so rt ingOrder() + 1, 1);
//	so rtingParticlePlayer.get_transform().SetParent(base.get_gameObject().get_transform());
//	so rtingParticlePlayer.Play();
}

void LightBulbItem::PlayOnExplodeStartedAnimation() {
//	if (ParticlePool.Instance != null) {
//		ParticlePool.Instance.PlayParticle(ParticlePool.Instance.LightBulbExplosion, base.get_transform().get_position(), true);
//	}
	PTCLLIB->explodeLightBulb(this->CurrentSpriteRenderer->getPosition());
}
