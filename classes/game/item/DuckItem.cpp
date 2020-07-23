#include "DuckItem.h"
#include "../Animation.h"
#include "../Score.h"
#include "../Level.h"
#include "../Cell.h"
#include "../Grid.h"
#include "../Extension.h"
#include "../FallManager.h"
#include "../ImageLibrary.h"

#include "global/SoundManager.h"

USING_NS_CC;

int DuckItem::_delayerCount = 0;
float DuckItem::_lastActionTime = 0.0f;

DuckItem::DuckItem() {
}

DuckItem::~DuckItem() {
}

CollectAnimation DuckItem::GetCollectItem() {
	//CollectAnimation component = this->CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(base.get_transform().get_position()).GetComponent<CollectAnimation>();
	//component.Prepare(this->CurrentLevel, this->GetItemType(), zorder, this->CurrentSpriteRenderer.get_sprite(), this->CurrentCell);

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
	//return component;
	return CollectAnimation::Duck;
}

void DuckItem::Update(float) {
	if (this->_inExplodeState || /*SlowCheckTime.ShouldPass() ||*/ this->IsFalling)
		return;

	if (this->get_CurrentCell() == nullptr || !this->get_CurrentCell()->IsFloor)
		return;

	this->CurrentLevel->PreCheckDecreaseGoal(ItemType::Duck);
	this->_inExplodeState = true;
	if (!this->_statIncreased) {
		this->_statIncreased = true;
		FallManager::getInstance()->IncreaseStatAnimation();
	}

	this->PlayDuckRescue();
}

void DuckItem::SetupItem(TiledEditorId tiledId) {
	int num = -1;
	switch (tiledId) {
	case TiledEditorId::Duck1: num = 0; break;
	case TiledEditorId::Duck2: num = 1; break;
	case TiledEditorId::Duck3: num = 2; break;
	case TiledEditorId::Duck4: num = 3; break;
	case TiledEditorId::Duck5: num = 4; break;
	}
	if(num >= 0) {
		ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->DuckSprites[num]);
		cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
		newrect.origin.y -= 22.0f; newrect.size.height += 22.0f;
		CurrentSpriteRenderer->setTextureRect(newrect);
	}
	CurrentSpriteRenderer->schedule(CC_CALLBACK_1(DuckItem::Update, this),"update");
}

void DuckItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->unschedule("update");
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

//protected:
int DuckItem::GetDelayerCount() {
	float time = Ext_getCurrentTime(); //Time.get_time();
	if (time - DuckItem::_lastActionTime > 0.1f) {
		DuckItem::_delayerCount = 0;
		DuckItem::_lastActionTime = time;
		return DuckItem::_delayerCount;
	}
	DuckItem::_delayerCount++;
	DuckItem::_lastActionTime = time;
	return DuckItem::_delayerCount;
}

void DuckItem::PlayDuckRescue() {
	Vector<FiniteTimeAction*> seq;
//case 0:
//	ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DuckRescueParticle, this.$this.get_transform().get_position(), true);
//	AudioManager.Play(AudioTag.Duck, PlayMode.Frame, null, 1f);
//	this.<seq>__0 = DOTween.Sequence();
//	this.$this.Squash(this.<seq>__0, this.$this.get_transform(), 0.8f, 0.1f, 0f, Ease.OutQuad);
//	this.$this.Squash(this.<seq>__0, this.$this.get_transform(), 1.1f, 0.08f, 0f, Ease.InQuad);
//	this.$this.Squash(this.<seq>__0, this.$this.get_transform(), 1f, 0.03f, 0f, Ease.OutQuad);
//public void Squash(Sequence seq, Transform rt, float yScale, float time, float jumpEffect, [Optional, DefaultParameterValue(1)] Ease e){
//	TweenSettingsExtensions.Append(seq, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOScale(rt, new Vector3(1f / yScale, yScale), time), e));
//	float num = (1f * (yScale - 1f)) / 2f;
//	num += jumpEffect;
//	TweenSettingsExtensions.Join(seq, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(rt, rt.get_localPosition().y + num, time, false), e));
//}
	seq.pushBack(Sequence::create(
		EaseQuarticActionOut::create(ScaleTo::create(0.1f, 1 / 0.8f, 0.8f)),
		EaseQuarticActionOut::create(ScaleTo::create(0.08f, 1 / 1.1f, 1.1f)),
		EaseQuarticActionOut::create(ScaleTo::create(0.03f, 1 / 1.0f, 1.0f)),
		nullptr));

	float curY = this->CurrentSpriteRenderer->getPositionY();
	this->CurrentSpriteRenderer->runAction(Sequence::create(
		EaseQuarticActionOut::create(MoveBy::create(0.1f, Vec2(0, curY + ((1.0f*(0.8f - 1.0f)) / 2.0f + 0)*ITEM_SPRITE_SIZE_X))),
		EaseQuarticActionOut::create(MoveBy::create(0.08f, Vec2(0, curY + ((1.0f*(1.1f - 1.0f)) / 2.0f + 0)*ITEM_SPRITE_SIZE_X))),
		EaseQuarticActionOut::create(MoveBy::create(0.03f, Vec2(0, curY + ((1.0f*(1.0f - 1.0f)) / 2.0f + 0)*ITEM_SPRITE_SIZE_X))),
		nullptr));
//	this.$current = new WaitForSeconds(0.41f + (0.1f * DuckItem.GetDelayerCount()));
	seq.pushBack(DelayTime::create(0.41 + 0.1f*DuckItem::GetDelayerCount()));
//	if(!this.$disposing) {
//		this.$PC = 1;
//	}
//	return true;
//
//case 1:
	seq.pushBack(CallFunc::create([this]() {
		if(this->_statIncreased) {
			FallManager::DecreaseStatAnimation();
			this->_statIncreased = false;
		}
		if(this->get_CurrentCell() != nullptr) {
			this->get_CurrentCell()->CurrentGrid->ExplodeCell(this->get_CurrentCell(), nullptr);
		}
	}));
	this->CurrentSpriteRenderer->runAction(Sequence::create(seq));
}