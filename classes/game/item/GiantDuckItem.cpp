#include "GiantDuckItem.h"
#include "GiantDuckFakeItem.h"

#include "../Cell.h"
#include "../Grid.h"
#include "../Level.h"
#include "../Animation.h"
#include "../FallManager.h"
#include "../ImageLibrary.h"

USING_NS_CC;

GiantDuckItem::GiantDuckItem() {
	TopLeft = new GiantDuckFakeItem(); TopLeft->MasterDuck = this;
	TopRight = new GiantDuckFakeItem(); TopRight->MasterDuck = this;
	BottomRight = new GiantDuckFakeItem(); BottomRight->MasterDuck = this; BottomRight->IsBottomRight = true;
}

GiantDuckItem::~GiantDuckItem() {
	delete TopLeft;
	delete TopRight;
	delete BottomRight;
}


void GiantDuckItem::SetupItem() {
	ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->GiantDuck);
	cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	newrect.origin.x -= 100.0f; newrect.size.width += 100.0f;
	newrect.origin.y += 0.0f; newrect.size.height += 80.0f;
	CurrentSpriteRenderer->setTextureRect(newrect);

	CurrentSpriteRenderer->schedule(CC_CALLBACK_1(GiantDuckItem::Update, this), "update");
}

void GiantDuckItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->unschedule("update");
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}
void GiantDuckItem::set_CurrentCell(Cell* value) {
	SpriteBasedItem::set_CurrentCell(value);
	if (value != nullptr) {
		this->TopLeft->set_CurrentCell (value->CurrentGrid->cell(value->X, value->Y + 1));
		this->TopRight->set_CurrentCell (value->CurrentGrid->cell(value->X + 1, value->Y + 1));
		this->BottomRight->set_CurrentCell (value->CurrentGrid->cell(value->X + 1, value->Y));
	}
	else {
		this->TopLeft->set_CurrentCell(nullptr);
		this->TopRight->set_CurrentCell(nullptr);
		this->BottomRight->set_CurrentCell(nullptr);
	}
}

CollectAnimation GiantDuckItem::GetCollectItem() {
	///*Vector3 position = base.get_transform().get_position();
	//position.x += 0.5f;
	//position.y += 0.4f;
	//CollectAnimation component = this->CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(position).GetComponent<CollectAnimation>();
	//component.Prepare(this->CurrentLevel, this->GetItemType(), this->zorder(), null, this->get_CurrentCell());
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

void GiantDuckItem::OnFallEnded() {
	SpriteBasedItem::OnFallEnded();
	Cell* currentCell = this->BottomRight->get_CurrentCell();
	if (currentCell != nullptr)
		CanCastShadowComponent::CastShadowIfPossible(currentCell);
}

bool GiantDuckItem::CanFall() {
	Cell* currentCell = this->BottomRight->get_CurrentCell();
	Cell* firstExistingBottomCell = currentCell->FirstExistingBottomCell;
	return !currentCell->Exists || (firstExistingBottomCell != nullptr && firstExistingBottomCell->Exists && !firstExistingBottomCell->get_HasItem() && firstExistingBottomCell->CanItemsFallInside());
}

//void GiantDuckItem::Squash(/*Sequence seq,*/ cocos2d::Node* rt, /*Transform rt,*/ float yScale, float time, float jumpEffect/*, Ease e = 1*/) {
	/*TweenSettingsExtensions.Append(seq, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOScale(rt, new Vector3(1f / yScale, yScale), time), e));
	float num = 1f * (yScale - 1f) / 2f;
	num += jumpEffect;
	TweenSettingsExtensions.Join(seq, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(rt, rt.get_localPosition().y + num, time, false), e));//*/
//}

void GiantDuckItem::Update(float) {
	if(this->_inExplodeState || /*SlowCheckTime.ShouldPass() ||*/ this->IsFalling)
		return;

	Cell* currentCell = this->BottomRight->get_CurrentCell();
	if((this->get_CurrentCell() == nullptr || !this->get_CurrentCell()->IsFloor) && (currentCell == nullptr || !currentCell->IsFloor))
		return;

	this->_inExplodeState = true;
	this->CurrentLevel->PreCheckDecreaseGoal(ItemType::Duck);
	if(!this->_statIncreased) {
		this->_statIncreased = true;
		FallManager::getInstance()->IncreaseStatAnimation();
	}

	this->PlayGiantDuckRescue();
}

/*IEnumerator*/ void GiantDuckItem::PlayGiantDuckRescue() {
	Vector<FiniteTimeAction*> seq;
//switch(num) {
//case 0:
//	AudioManager.Play(AudioTag.ItemGiantDuck, PlayMode.Frame, null, 1f);
//	this.<bubblePosition>__0 = this.$this.get_transform().get_position();
//	this.<bubblePosition>__0.y += 0.4f;
//	ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DuckRescueParticle, this.<bubblePosition>__0, true);
//	this.<seq>__0 = DOTween.Sequence();
//	this.$this.Squash(this.<seq>__0, this.$this.get_transform(), 0.8f, 0.1f, 0f, 6);
//	this.$this.Squash(this.<seq>__0, this.$this.get_transform(), 1.1f, 0.08f, 0f, 5);
//	this.$this.Squash(this.<seq>__0, this.$this.get_transform(), 1f, 0.03f, 0f, 6);
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

//	this.$current = new WaitForSeconds(0.51f);
	seq.pushBack(DelayTime::create(0.51f));
//	if(!this.$disposing) {
//		this.$PC = 1;
//	}
//	return true;
//
//case 1:
//	if(this.$this._statIncreased) {
//		FallManager.DecreaseStatAnimation();
//		this.$this._statIncreased = false;
//	}
//	if(this.$this.CurrentCell != null) {
//		this.$this.CurrentCell.CurrentGrid.ExplodeCell(this.$this.CurrentCell, null);
//	}
//	this.$PC = -1;
//	break;
//}
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