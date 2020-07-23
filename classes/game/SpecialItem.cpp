#include "SpecialItem.h"
#include "Cell.h"
#include "Level.h"
#include "Grid.h"
#include "Math.h"
#include "Extension.h"
#include "Mathf.h"
#include "FallManager.h"
#include "JellyManager.h"
#include "Score.h"
#include "ImageLibrary.h"
#include "ParticleLibrary.h"
#include "LevelBuilder.h"
#include "ScnLevelPlay.h"
#include "global/GameManager.h"
#include "Tween.h"
#include "Constants.h"
#include "ComFollow.h"


////////SpecialItem//////////////////////////////////////////////////////////////////////////////
void SpecialItem::set_CurrentCell(Cell* value) {
	SpriteBasedItem::set_CurrentCell(value);
	if(value != nullptr) {
		this->_lastCell = value;
	}
}


Tweener* SpecialItem::MoveToComboItem(Cell* targetCell) {
	SpriteBasedItem::StopOtherAnimations();

	//return this->_currentMoveToSpecialItemAnimation.MoveTo(this, targetCell);
	this->CurrentSpriteRenderer->runAction(cocos2d::Sequence::create(
		cocos2d::CallFunc::create([this]() {
		FallManager::getInstance()->IncreaseMechanicAnimation();
		FallManager::getInstance()->IncreaseWaitingFallBlocker();
	}),
		cocos2d::EaseBackIn::create(cocos2d::MoveTo::create(0.3f, targetCell->GetFrozenPosition())),
		cocos2d::CallFunc::create([this]() {
		FallManager::getInstance()->DecreaseMechanicAnimation();
		FallManager::getInstance()->DecreaseWaitingFallBlocker();
		this->RemoveSelf();
	}),
		nullptr));

	return nullptr;// this->_currentMoveToSpecialItemAnimation.MoveTo(this, targetCell);
}

void SpecialItem::OnBeforeRemove() {
	if(this->CurrentComboHintParticle != nullptr)
		this->DisplayComboHint(false);

	this->_lastCell = nullptr;
	SpriteBasedItem::OnBeforeRemove();
	//this->_currentMoveToSpecialItemAnimation.ResetMe();
}

void SpecialItem::AfterPoolInit() {
	SpriteBasedItem::AfterPoolInit();
	this->_lastCell = nullptr;
	this->CanNotJoinToCombo = false;
	this->SpecialItemCanOnlyExplodeSelf = false;
	this->_explodesCompleted = false;
	this->_jellyExploded = false;
	//this->CurrentSpriteRenderer.get_gameObject().SetActive(true);
	this->CurrentSpriteRenderer->setVisible(true);
}

bool SpecialItem::ExplodeBySpecialItem(Cell* cell) {
	if(cell->Exists && cell->get_HasItem() && cell->get_CurrentItem()->CanBeExplodedBySpecialItem()) {
		if(cell->get_CurrentItem()->GetItemType() == ItemType::Jelly) {
			this->_jellyExploded = true;
		}
		Item* currentItem = cell->get_CurrentItem();
		currentItem->PreventRaiseScore();
		Direction comingFrom = (!(this->_lastCell == nullptr)) ? this->_lastCell->GetDirectionTo(cell) : Direction::None;
		currentItem->InformToBeExplodedBySpecialItem(this, comingFrom);
		bool flag = cell->CurrentGrid->ExplodeCell(cell, nullptr);
		if(!flag) {
			currentItem->AllowRaiseScore();
		}
		return flag;
	}
	cell->ShakeBubble();
	return false;
}


void SpecialItem::PlaySpecialItemCreationAnimation() {
	//this->CurrentSpriteRenderer.get_gameObject().SetActive(false);
	//Sequence sequence = DOTween.Sequence();
	//TweenSettingsExtensions.AppendInterval(sequence, 0.3f);
	//TweenSettingsExtensions.AppendCallback(sequence, delegate
	//{
	//	this->CurrentSpriteRenderer.get_gameObject().SetActive(true);
	//	ParticlePool.Instance.PlayParticle(ParticlePool.Instance.SpecialItemCreationParticle, this, true);
	//});
	this->CurrentSpriteRenderer->runAction(Sequence::create(
		DelayTime::create(0.3f),
		CallFunc::create([this]() {PTCLLIB->createSpecialItem(this->get_CurrentCell()->GetFrozenPosition()); }),
		nullptr
		));
}


/*IEnumerator*/void SpecialItem::StartAutoExplode(float blockerTween) {
	Vector<FiniteTimeAction*> seq;
	this->CurrentLevel->JellyItemManager->WaitSpecialItem();
	//TapListener.Instance.IncreaseBlockRequests();
	if(this->ShouldBlockFalls())
		FallManager::IncreaseWaitingFallBlocker();
	FallManager::IncreaseMechanicAnimation();
	//if(this.blockerTween != null) {
	//	this.$current = this.blockerTween.WaitForCompletion();
	//	if(!this.$disposing) {
	//		this.$PC = 1;
	//	}
	//	goto Label_017E;
	//}
	//break;
	seq.pushBack(DelayTime::create(blockerTween));
	//-------next step
	seq.pushBack(CallFunc::create([this]() {
		this->OnExplodeSelf();
		if(/*(this.get_gameObject() != null) &&*/ (this->get_CurrentCell() != nullptr))
			this->ExplodeBySpecialItem(this->get_CurrentCell());
	}));

	//while(!this.$this._explodesCompleted) {
	//	this.$current = null;
	//	if(!this.$disposing) {
	//		this.$PC = 2;
	//	}
	//	goto Label_017E;
	//}
	//if(this.$this.CurrentLevel != null) {
	//	this.$this.CurrentLevel.JellyItemManager.SpecialItemEnded(this.$this._jellyExploded);
	//	this.$this.CurrentLevel.ExplodeEnded();
	//	TapListener.Instance.DecreaseBlockRequests();
	//	if(this.$this.ShouldBlockFalls()) {
	//		FallManager.DecreaseWaitingFallBlocker();
	//	}
	//	FallManager.DecreaseMechanicAnimation();
	//	this.$PC = -1;
	//}
	CurrentSpriteRenderer->runAction(Sequence::create(seq));
}

void SpecialItem::_onExplodesCompleted() {
	this->_explodesCompleted = true;
	if(this->CurrentLevel != nullptr) {
		this->CurrentLevel->JellyItemManager->SpecialItemEnded(this->_jellyExploded);
		this->CurrentLevel->ExplodeEnded();
		//TapListener.Instance.DecreaseBlockRequests();
		if(this->ShouldBlockFalls()) {
			FallManager::DecreaseWaitingFallBlocker();
		}
		FallManager::DecreaseMechanicAnimation();
		//	this.$PC = -1;
	}
}

void SpecialItem::DisplayComboHint(bool canGenerateCombo) {
	if(canGenerateCombo) {
		if(this->CurrentComboHintParticle == nullptr) {
			this->CurrentComboHintParticle = PTCLLIB->showComboHint(CurrentSpriteRenderer->getPosition());
			ComFollow* follow = ComFollow::create();
			follow->setTarget(this->CurrentSpriteRenderer);
			this->CurrentComboHintParticle->addComponent(follow);
		}
	}
	else if(this->CurrentComboHintParticle != nullptr) {
		this->CurrentComboHintParticle->removeFromParentAndCleanup(false);
		this->CurrentComboHintParticle = nullptr;
	}
}


void SpecialItem::StartExplode() {
	SpriteBasedItem::StopOtherAnimations();
	if(this->SpecialItemCanOnlyExplodeSelf) {
		//Object.Destroy(base.get_gameObject());
		this->RemoveSelf();
	}
}


bool SpecialItem::TryExplode() {
	if(this->LatestExplode == (long)Ext_getCurrentFrame()) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	if(!this->SpecialItemCanOnlyExplodeSelf) {
		Cell* cellReference = this->get_CurrentCell();
		JellyManager* currentLevelJellyItemManager = this->CurrentLevel->JellyItemManager;
		currentLevelJellyItemManager->WaitSpecialItem();
		if(this->ShouldRejectFallInside()) {
			cellReference->RejectsFallInside();
		}
		FallManager::IncreaseMechanicAnimation();
		//Task task = new Task(this->ExplodeCells());
		this->ExplodeCells();
		//task.Finished += delegate(bool A_1, Task A_2) {
		this->afterExplodeCells = [this,cellReference,currentLevelJellyItemManager]() {
			//this->_explodesCompleted = true;
			this->_onExplodesCompleted();
			currentLevelJellyItemManager->SpecialItemEnded(this->_jellyExploded);
			if(this->CurrentLevel != nullptr) {
				this->CurrentLevel->ExplodeEnded();
			}
			FallManager::DecreaseMechanicAnimation();
			if(this->ShouldRejectFallInside()) {
				cellReference->AcceptsFallInside();
			}
		};
	}
	else {
		//this->_explodesCompleted = true;
		this->_onExplodesCompleted();
	}
	this->DisplayComboHint(false);
	return true;
}

int SpecialItem::GetScoreForSpecialItem(Item* ci, Cell* c) {
	return (!ci->IsSpecialItem()) ? (ci->GetScore() + c->GetBubbleScoreIfPossible()) : 0;
}



////////////////HorizontalRocketItem///////////////////////////////////////////////
float HorizontalRocketItem::ExplodeTime = 0.07f;
float HorizontalRocketItem::Offset = 0.8f;

void HorizontalRocketItem::SetupItem() {
	ImageLibrary::CopySprite(CurrentSpriteRenderer, IMGLIB->horizontalRocket);
	cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	newrect.origin.y -= 20.0f; newrect.size.height += 20.0f;
	CurrentSpriteRenderer->setTextureRect(newrect);

	(Head1 = Sprite::create())->setVisible(false);
	ImageLibrary::CopySprite(Head1, IMGLIB->leftRocket);
	CurrentSpriteRenderer->addChild(Head1);
	Head1->setPosition(0, 36);
	(Head2 = Sprite::create())->setVisible(false);
	ImageLibrary::CopySprite(Head2, IMGLIB->rightRocket);
	CurrentSpriteRenderer->addChild(Head2);
	Head2->setPosition(0, 36);

	Head1TrailParticle = ParticleSystemQuad::create("particle/rocketFire.plist");
	Head1TrailParticle->stopSystem();
	Head1TrailParticle->setVisible(false);
	Head1TrailParticle->setPosition(110, 36);
	Head1->addChild(Head1TrailParticle);
	auto starparticle1 = ParticleSystemQuad::create("particle/lineOfStars1.plist");
	Head1TrailParticle->addChild(starparticle1);
	starparticle1->stopSystem();
	
	Head2TrailParticle = ParticleSystemQuad::create("particle/rocketFire.plist");
	Head2TrailParticle->stopSystem();
	Head2TrailParticle->setVisible(false);
	Head2TrailParticle->setPosition(-40, 36);
	Head2->addChild(Head2TrailParticle);
	auto starparticle2 = ParticleSystemQuad::create("particle/lineOfStars1.plist");
	Head2TrailParticle->addChild(starparticle2);
	starparticle2->stopSystem();
}

void HorizontalRocketItem::OnBeforeRemove() {
	SpecialItem::OnBeforeRemove();
	//this->Head1TrailParticle.Stop();
	//this->Head2TrailParticle.Stop();
	//this->RelativeContainer.SetActive(true);
	//this->ExplodeAnimation.SetActive(false);
	//this->Head1.get_gameObject().SetActive(false);
	this->Head1->removeFromParentAndCleanup(true);
	//this->Head2.get_gameObject().SetActive(false);
	this->Head2->removeFromParentAndCleanup(true);
}

void HorizontalRocketItem::AfterPoolInit() {
	if(!this->_isPositionsUpdated) {
		this->_isPositionsUpdated = true;
		this->Head1Position = this->Head1->getPosition();
		this->Head2Position = this->Head2->getPosition();
	}
	SpecialItem::AfterPoolInit();
	this->grid = nullptr;
	this->Height = 0;
	this->ScoreGained = this->GetScore();
	this->ScreenDown = 0.0f;
	this->ScreenLeft = 0.0f;
	this->ScreenRight = 0.0f;
	this->ScreenUp = 0.0f;
	this->StartDuration = 0.0f;
	this->Sx = 0;
	this->Sy = 0;
	this->Width = 0;
	this->WaitLastRocketExit = true;
	this->RejectFallsInside = true;
	this->ExitTime = 0.0f;
	this->Head1->setPosition(this->Head1Position);
	this->Head2->setPosition(this->Head2Position);
}

void HorizontalRocketItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void HorizontalRocketItem::SwitchToUseMode(bool head1Active/* = true*/, bool head2Active/* = true*/, bool playExplosionParticle/* = true*/, bool playParticle1/* = true*/, bool playParticle2/* = true*/) {
	//this->RelativeContainer.SetActive(false);
	if(head1Active || head2Active) CurrentSpriteRenderer->setOpacity(0);
	//this->ExplodeAnimation.SetActive(true);
	this->Head1->setVisible(head1Active);
	this->Head2->setVisible(head2Active);
	if(playParticle1) {
		//this->Head1TrailParticle.Play();
		this->Head1TrailParticle->setVisible(true);
		this->Head1TrailParticle->resetSystem();
		dynamic_cast<ParticleSystemQuad*>(this->Head1TrailParticle->getChildren().at(0))->resetSystem();
	}
	if(playParticle2) {
		//this->Head2TrailParticle.Play();
		this->Head2TrailParticle->setVisible(true);
		this->Head2TrailParticle->resetSystem();
		dynamic_cast<ParticleSystemQuad*>(this->Head2TrailParticle->getChildren().at(0))->resetSystem();
	}
}

void HorizontalRocketItem::ExplodeCells() {
	isExploded = true;
	//AudioManager.Play(AudioTag.ItemSpecialRocket, PlayMode.Frame, null, 1f);
	this->grid = this->get_CurrentCell()->CurrentGrid;
	this->Width = this->grid->Width;
	this->Sx = this->get_CurrentCell()->X;
	this->Sy = this->get_CurrentCell()->Y;
	this->ScreenLeft = CurrentLevel->CurrentLevelBuilder->ItemContainer->convertToNodeSpace(Vec2::ZERO).x;// CameraHelper.Left.x - 2f;
	this->ScreenRight = CurrentLevel->CurrentLevelBuilder->ItemContainer->convertToNodeSpace(Vec2::ONE*SCREEN_WIDTH).x;//CameraHelper.Right.x + 2f;
	this->StartDuration = this->Head2->getPosition().x/ITEM_SPRITE_SIZE_X * HorizontalRocketItem::ExplodeTime;
	this->SwitchToUseMode(true, true, true, true, true);
	for(int i = 0; i < this->Width; i++)
		this->grid->cell(i, this->Sy)->RejectsFallInside();

	//this.<rocketSeq>__0 = DOTween.Sequence();
	Vector<FiniteTimeAction*> seq;
	//this.<rocketSeq>__0.AppendCallback(this->ExplodeLater(this->Grid, this->Sx, this->Sy));
	seq.pushBack(CallFunc::create([this]() {this->ExplodeLater(this->grid, this->Sx, this->Sy); }));
	//this.<step>__0 = 1;
	int __step = 1;
	//this.<rowCompleted>__0 = false;
	bool __rowcompleted = false;
	//while(!this.<rowCompleted>__0) {
	while(!__rowcompleted) {
	//	int num3 = this->Sx + this.<step>__0;
		int __right = this->Sx + __step;
	//	int num4 = this->Sx - this.<step>__0;
		int __left = this->Sx - __step;
	//	this.<rowCompleted>__0 = (num4 < 0) && (num3 >= this->Width);
		__rowcompleted = __left < 0 && __right >= this->Width;
	//	if(num4 >= -1) {
	//		this->StepRocket(this->Head1, this.<step>__0, -1, this.<rocketSeq>__0);
	//	}
		if(__left >= -1)
			this->StepRocket(this->Head1, __step, -1);
	//	if(num3 <= this->Width) {
	//		this->StepRocket(this->Head2, this.<step>__0, 1, this.<rocketSeq>__0);
	//	}
		if(__right <= this->Width)
			this->StepRocket(this->Head2, __step, 1);
	//	this.<step>__0++;
		__step++;
	}
	int __leftmoveamount = this->Sx - (-3); float __leftmovetime = HorizontalRocketItem::ExplodeTime*__leftmoveamount;
	int __rightmoveamount = 12 - this->Sx; float __rightmovetime = HorizontalRocketItem::ExplodeTime*__rightmoveamount;
	Head1->runAction(MoveBy::create(__leftmovetime, -Vec2::UNIT_X*ITEM_SPRITE_SIZE_X*__leftmoveamount));
	Head2->runAction(MoveBy::create(__rightmovetime, Vec2::UNIT_X*ITEM_SPRITE_SIZE_X*__rightmoveamount));

	seq.pushBack(DelayTime::create(Mathf::Max(__leftmovetime, __rightmovetime)));
	//this.<rocketSeq>__0.InsertCallback(this->ExitTime, new TweenCallback(this->AcceptFallsInCurrentRow));
	seq.pushBack(CallFunc::create([this]() {this->AcceptFallsInCurrentRow(); }));

	seq.pushBack(CallFunc::create([this]() {this->afterExplodeCells(); }));
	CurrentSpriteRenderer->runAction(Sequence::create(seq));
}

void HorizontalRocketItem::ExplodeLater(Grid* currentGrid, int x, int y) {
	if(((x >= 0) && (x < currentGrid->Width)) && ((y >= 0) && (y < currentGrid->Height))) {
		Cell* cell = currentGrid->cell(x, y);
		Item* currentItem = cell->get_CurrentItem();
		int score = 0;
		bool flag = false;
		if(currentItem != nullptr) {
			score = currentItem->GetScore();
			flag = currentItem->CanGenerateScoreWithoutExplode();
		}
		if(this->ExplodeBySpecialItem(cell)) {
			this->ScoreGained += SpecialItem::GetScoreForSpecialItem(currentItem, cell);
		}
		else if((cell->get_HasItem() && cell->get_CurrentItem()->CanGenerateScoreOnEachTryExplode()) && cell->get_CurrentItem()->CanGenerateScoreThisTurn()) {
			this->ScoreGained += currentItem->GetScore();
		}
		else if((!cell->get_HasItem() && flag) && (score > 0)) {
			this->ScoreGained += score;
		}
	}
}

void HorizontalRocketItem::Die() {
	this->CurrentSpriteRenderer->scheduleOnce([this](float) {this->RemoveSelf(); }, 0.0f, "dieDelay");
}

void HorizontalRocketItem::StepRocket(cocos2d::Node* rocket, int step, int direction/*, Vector<cocos2d::FiniteTimeAction*>& seq*/) {
	int tgtX = this->Sx + step * direction;
	bool isInside = tgtX >= 0 && tgtX < this->Width;
	if(isInside)
		rocket->runAction(Sequence::createWithTwoActions(
			DelayTime::create(Mathf::Abs(step)*HorizontalRocketItem::ExplodeTime),
			CallFunc::create([this,tgtX]() {this->ExplodeLater(this->grid, tgtX, this->Sy); })));
	return;

	//int tgtNextX = tgtX + direction;
	//float num3 = (step != 1) ? HorizontalRocketItem::ExplodeTime : this->StartDuration;
	//float num4 = (step != 1) ? (HorizontalRocketItem::ExplodeTime * (float)(step - 2) + this->StartDuration) : 0.0f;
	//float num5 = rocket->getPositionX() + ((float)step - HorizontalRocketItem::Offset) * (float)direction;
	////TweenSettingsExtensions.Insert(seq, num4, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMoveX(rocket, num5, num3, false), 1));
	//seq.pushBack(MoveTo::create(num3, Vec2(num5, rocket->getPositionY())));
	//if(isInside) {
	//	//TweenSettingsExtensions.InsertCallback(seq, num4 + num3, this->ExplodeLater(this->Grid, tgtX, this->Sy));
	//	seq.pushBack(Sequence::createWithTwoActions(DelayTime::create(num4 + num3), CallFunc::create([this, tgtX]() {this->ExplodeLater(this->grid, tgtX, this->Sy); })));
	//}
	//if(tgtNextX >= this->Width) {
	//	float num6 = (this->ScreenRight - num5) * HorizontalRocketItem::ExplodeTime;
	//	float num7 = num4 + num3;
	//	this->ExitTime = Mathf::Max(num7, this->ExitTime);
	//	//TweenSettingsExtensions.Insert(seq, num7, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMoveX(rocket, this->ScreenRight, num6, false), 1));
	//	seq.pushBack(MoveTo::create(num7, Vec2(num5, rocket->getPositionY())));
	//}
	//else if(tgtNextX < 0) {
	//	float num8 = -(this->ScreenLeft - num5) * HorizontalRocketItem::ExplodeTime;
	//	float num9 = num4 + num3;
	//	this->ExitTime = Mathf::Max(num9, this->ExitTime);
	//	//TweenSettingsExtensions.Insert(seq, num9, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMoveX(rocket, this->ScreenLeft, num8, false), 1));
	//}
}

void HorizontalRocketItem::AcceptFallsInCurrentRow() {
	ScoreManager::RaiseScore(this->ScoreGained, this->grid ->cell(this->Sx, this->Sy)->GetFrozenPosition(), MatchType::None);
	for(int i = 0; i < this->Width; i++) {
		this->grid->cell(i, this->Sy)->AcceptsFallInside();
	}
	this->WaitLastRocketExit = false;
	if(SpecialItem::CurrentSpriteRenderer->isVisible()) { //if(base.get_gameObject().get_activeSelf()) {
		//	base.StartCoroutine(this->Die());
		this->Die();
	}
	else {
		this->RemoveSelf();
	}
}

////////////////verticalRocketItem///////////////////////////////////////////////
void VerticalRocketItem::SetupItem() {
	ImageLibrary::CopySprite(CurrentSpriteRenderer, IMGLIB->verticalRocket);
	cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	newrect.origin.y -= 20.0f; newrect.size.height += 20.0f;
	CurrentSpriteRenderer->setTextureRect(newrect);

	(Head1 = Sprite::create())->setVisible(false);
	ImageLibrary::CopySprite(Head1, IMGLIB->bottomRocket);
	CurrentSpriteRenderer->addChild(Head1);
	Head1->setPosition(37, 0);
	(Head2 = Sprite::create())->setVisible(false);
	ImageLibrary::CopySprite(Head2, IMGLIB->topRocket);
	CurrentSpriteRenderer->addChild(Head2);
	Head2->setPosition(37, 0);

	Head1TrailParticle = ParticleSystemQuad::create("particle/rocketFire.plist");
	Head1TrailParticle->stopSystem();
	Head1TrailParticle->setVisible(false);
	Head1TrailParticle->setPosition(35, 110);
	Head1->addChild(Head1TrailParticle);
	auto starparticle1 = ParticleSystemQuad::create("particle/lineOfStars1.plist");
	Head1TrailParticle->addChild(starparticle1);
	starparticle1->stopSystem();

	Head2TrailParticle = ParticleSystemQuad::create("particle/rocketFire.plist");
	Head2TrailParticle->stopSystem();
	Head2TrailParticle->setVisible(false);
	Head2TrailParticle->setPosition(35, -40);
	Head2->addChild(Head2TrailParticle);
	auto starparticle2 = ParticleSystemQuad::create("particle/lineOfStars1.plist");
	Head2TrailParticle->addChild(starparticle2);
	starparticle2->stopSystem();
}

void VerticalRocketItem::ExplodeCells() {
	isExploded = true;
	// AudioManager.Play(AudioTag.ItemSpecialRocket, PlayMode.Frame, null, 1f);
	this->grid = this->get_CurrentCell()->CurrentGrid;
	this->Height = this->grid->Height;
	this->Sx = this->get_CurrentCell()->X;
	this->Sy = this->get_CurrentCell()->Y;
	this->ScreenDown = CurrentLevel->CurrentLevelBuilder->ItemContainer->convertToNodeSpace(Vec2::ZERO).y;//CameraHelper.Top.y + 2f;
	this->ScreenUp = CurrentLevel->CurrentLevelBuilder->ItemContainer->convertToNodeSpace(Vec2::ONE*SCREEN_HEIGHT).y;//CameraHelper.Bottom.y - 2f;
	this->StartDuration = this->Head2->getPosition().y / ITEM_SPRITE_SIZE_X * HorizontalRocketItem::ExplodeTime;
	this->SwitchToUseMode(true, true, true, true, true);
	for(int i = 0; i < this->Height; i++)
		this->grid->cell(this->Sx, i)->RejectsFallInside();

	//this-><rocketSeq>__0 = DOTween.Sequence();
	Vector<FiniteTimeAction*> seq;
	//this-><rocketSeq>__0.AppendCallback(this->ExplodeLater(this->Grid, this->Sx, this->Sy));
	seq.pushBack(CallFunc::create([this]() {this->ExplodeLater(this->grid, this->Sx, this->Sy); }));
	//this-><step>__0 = 1;
	int __step = 1;
	//this-><columnCompleted>__0 = false;
	bool __colcompleted = false;
	//while (!this-><columnCompleted>__0) {
	while(!__colcompleted) {
		//	int num3 = this->Sy + this-><step>__0;
		int __top = this->Sy + __step;
		//	int num4 = this->Sy - this-><step>__0;
		int __bottom = this->Sy - __step;
		//	this-><columnCompleted>__0 = (num3 > this->Height) && (num4 < 0);
		__colcompleted = (__top>this->Height) && (__bottom < 0);
		//	if (num3 <= this->Height)
		//	{
		//		this->StepRocket(this->Head2, this-><step>__0, 1, this-><rocketSeq>__0);
		//	}
		if(__top <= this->Height)
			this->StepRocket(this->Head2, __step, 1);
		//	if (num4 >= -1)
		//	{
		//		this->StepRocket(this->Head1, this-><step>__0, -1, this-><rocketSeq>__0);
		//	}
		if(__bottom >= -1)
			this->StepRocket(this->Head1, __step, -1);
		//	this-><step>__0++;
		__step++;
	}
	int __bottommoveamount = this->Sy - (-5); float __bottommovetime = HorizontalRocketItem::ExplodeTime*__bottommoveamount;
	int __topmoveamount = 14 - this->Sy; float __topmovetime = HorizontalRocketItem::ExplodeTime*__topmoveamount;
	Head1->runAction(MoveBy::create(__bottommovetime, -Vec2::UNIT_Y*ITEM_SPRITE_SIZE_X*__bottommoveamount));
	Head2->runAction(MoveBy::create(__topmovetime, Vec2::UNIT_Y*ITEM_SPRITE_SIZE_X*__topmoveamount));

	seq.pushBack(DelayTime::create(Mathf::Max(__bottommovetime, __topmovetime)));
	//this-><rocketSeq>__0.InsertCallback(this->ExitTime, new TweenCallback(this->AcceptFallsInCurrentColoumn));
	seq.pushBack(CallFunc::create([this]() {this->AcceptFallsInCurrentColoumn(); }));

	seq.pushBack(CallFunc::create([this]() {this->afterExplodeCells(); }));
	CurrentSpriteRenderer->runAction(Sequence::create(seq));
}

void VerticalRocketItem::StepRocket(cocos2d::Node* rocket, int step, int direction/*, std::vector<cocos2d::FiniteTimeAction*>& seq*/) {
	int tgtY = this->Sy + step * direction;
	bool isInside = tgtY >= 0 && tgtY < this->Height;
	if(isInside)
		rocket->runAction(Sequence::createWithTwoActions(
		DelayTime::create(Mathf::Abs(step)*HorizontalRocketItem::ExplodeTime),
		CallFunc::create([this, tgtY]() {this->ExplodeLater(this->grid, this->Sx, tgtY); })));
	return;

	//int num2 = tgtY + direction;
	//float num3 = (step != 1) ? HorizontalRocketItem::ExplodeTime : this->StartDuration;
	//float num4 = (step != 1) ? (HorizontalRocketItem::ExplodeTime * (float)(step - 2) + this->StartDuration) : 0.0f;
	//float num5 = rocket->getPositionY() + ((float)step - HorizontalRocketItem::Offset) * (float)direction;
	////TweenSettingsExtensions.Insert(seq, num4, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMoveY(rocket, num5, num3, false), 1));
	//if(isInside) {
	//	//TweenSettingsExtensions.InsertCallback(seq, num4 + num3, base.ExplodeLater(this->Grid, this->Sx, tgtY));
	//}
	//if(num2 >= this->Height) {
	//	float num6 = (this->ScreenUp - num5) * HorizontalRocketItem::ExplodeTime;
	//	float num7 = num4 + num3;
	//	this->ExitTime = Mathf::Max(num7, this->ExitTime);
	//	//TweenSettingsExtensions.Insert(seq, num7, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMoveY(rocket, this->ScreenUp, num6, false), 1));
	//}
	//else if(num2 < 0) {
	//	float num8 = -(this->ScreenDown - num5) * HorizontalRocketItem::ExplodeTime;
	//	float num9 = num4 + num3;
	//	this->ExitTime = Mathf::Max(num9, this->ExitTime);
	//	//TweenSettingsExtensions.Insert(seq, num9, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMoveY(rocket, this->ScreenDown, num8, false), 1));
	//}
}

void VerticalRocketItem::AcceptFallsInCurrentColoumn() {
	if(this->grid != nullptr) 
		ScoreManager::RaiseScore(this->ScoreGained, this->grid->cell(this->Sx, this->Sy)->GetFrozenPosition(), MatchType::None);
	
	for(int i = 0; i < this->Height; i++)
		if(this->grid != nullptr)
			this->grid->cell(this->Sx, i)->AcceptsFallInside();
	

	this->WaitLastRocketExit = false;
	if(SpecialItem::CurrentSpriteRenderer->isVisible()) { //if(base.get_gameObject().get_activeSelf()) {
		//base.StartCoroutine(base.Die());
		this->Die();
	}
	else {
		this->RemoveSelf();
	}
}

//////////////BombItem////////////////////////////////////////////////////////////////////////////////////
void BombItem::SetupItem() {
	ImageLibrary::CopySprite(CurrentSpriteRenderer, IMGLIB->Bomb);
	cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	newrect.origin.x -= 3.0f; newrect.size.width += 3.0f;
	newrect.origin.y -= 22.0f; newrect.size.height += 22.0f;
	CurrentSpriteRenderer->setTextureRect(newrect);

	_wickParticle = ParticleSystemQuad::create("particle/bombFuse1.plist");
	_wickParticle->addChild(ParticleSystemQuad::create("particle/bombFuse2.plist"));
	_wickParticle->setPosition(100.0f, 90.0f);
	CurrentSpriteRenderer->addChild(_wickParticle);
	
}

void BombItem::PlayExplodeParticle() {
	_wickParticle->removeFromParentAndCleanup(true);
	_wickParticle = nullptr;

	//ParticlePool.Instance.PlayParticle(ParticlePool.Instance.BombExplodeParticle, base.get_transform().get_position(), true);
	PTCLLIB->explodeBomb(CurrentSpriteRenderer->getPosition());
}

void BombItem::AfterPoolInit() {
	SpecialItem::AfterPoolInit();
	this->_explodeDelay = 0.0f;
	this->MoreEffectedItems.clear();
}

void BombItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();

	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void BombItem::ExplodeCells() {
	isExploded = true;
	Vector<FiniteTimeAction*> seq;
	// step1
	__neighbours = this->GetNeigbours(1);
	//AudioManager.Play(AudioTag.ItemSpecialBomb, PlayMode.Frame, null, 1f);
	__scorepos = this->get_CurrentCell()->GetFrozenPosition();
	seq.pushBack(DelayTime::create(this->_explodeDelay));
	// step2
	seq.pushBack(CallFunc::create([this]() {this->PlayExplodeParticle(); }));
	seq.pushBack(DelayTime::create(0.1f));
	// step3
	seq.pushBack(CallFunc::create([&]() {
		int __score = 0;
		for(int i = 0; i < (int)__neighbours.size(); i++) {
			Cell* cell = __neighbours[i];
			cell->RejectsFallInside();
			if(cell->get_HasItem()) {
				Item* currentItem = cell->get_CurrentItem();
				if(currentItem->GetItemType() == ItemType::Bomb) {
					dynamic_cast<BombItem*>(currentItem)->_explodeDelay = 0.1f;
				}
				int onescore = 0;
				bool flag = false;
				if(currentItem != nullptr) {
					onescore = currentItem->GetScore();
					flag = currentItem->CanGenerateScoreWithoutExplode();
				}
				if(this->ExplodeBySpecialItem(cell)) {
					__score += SpecialItem::GetScoreForSpecialItem(currentItem, cell);
				}
				else if((cell->get_HasItem() && cell->get_CurrentItem()->CanGenerateScoreOnEachTryExplode()) && cell->get_CurrentItem()->CanGenerateScoreThisTurn()) {
					__score += currentItem->GetScore();
				}
				else if((!cell->get_HasItem() && flag) && (__score > 0)) {
					__score += onescore;
				}
				this->MarkShouldExplodeAtLeast2(currentItem);
			}
		}
		this->ExplodeMoreIfNeeded();
		ScoreManager::RaiseScore(this->GetScore() + __score, __scorepos, MatchType::None);
	}));
	seq.pushBack(DelayTime::create(0.05f));
	// step4
	seq.pushBack(CallFunc::create([&]() {
		for(Cell* onecell : __neighbours)
			onecell->AcceptsFallInside();
		this->RemoveSelf();
	}));

	// ExplodeCells ended
	seq.pushBack(CallFunc::create([this]() {afterExplodeCells(); }));
	CurrentSpriteRenderer->runAction(Sequence::create(seq));
}

void BombItem::ExplodeMoreIfNeeded() {
	for(int i = 0; i < (int)this->MoreEffectedItems.size(); i++) {
		this->MoreEffectedItems[i]->CheckIfExtraExplodeNeeded();
	}
	this->MoreEffectedItems.clear();
}

void BombItem::MarkShouldExplodeAtLeast2(Item* item) {
	if(item->GetItemType() != ItemType::CanToss) {
		return;
	}
	ICanExplodeAtLeast2* canExplodeAtLeast = dynamic_cast<ICanExplodeAtLeast2*>(item);
	canExplodeAtLeast->MarkShouldExplodeAtLeast2();
	this->MoreEffectedItems.push_back(canExplodeAtLeast);
}

std::vector<Cell*> BombItem::GetNeigbours(int size) {
	Grid* currentGrid = this->get_CurrentCell()->CurrentGrid;
	std::vector<Cell*> list;
	for(int i = this->get_CurrentCell()->X - size; i <= this->get_CurrentCell()->X + size; i++) {
		for(int j = this->get_CurrentCell()->Y - size; j <= this->get_CurrentCell()->Y + size; j++) {
			if(i >= 0 && i < currentGrid->Width && j >= 0 && j < currentGrid->Height) {
				list.push_back(currentGrid->cell(i, j));
			}
		}
	}
	return list;
}


//////////////DiscoBallItem////////////////////////////////////////////////////////////////////////////////////
Vec3 DiscoBallItem::HueYellow(302.0f, 2.0f, 1.52f);
Vec3 DiscoBallItem::HueRed(360.0f, 1.0f, 1.0f);
Vec3 DiscoBallItem::HueBlue(149.0f, 1.02f, 1.45f);
Vec3 DiscoBallItem::HueGreen(241.0f, 1.02f, 1.03f);
Vec3 DiscoBallItem::HuePurple(40.0f, 1.0f, 0.88f);
Vec3 DiscoBallItem::HueOrange(320.0f, 1.26f, 1.6f);

Vec2 DiscoBallItem::ParticleStartOffset(0.2f, -0.2f);
Vec2 DiscoBallItem::ParticleEndOffset(0.15f, -0.2f);

void DiscoBallItem::OnBeforeRemove() {
	SpecialItem::OnBeforeRemove();
	//if(this->StartAnimationParticle != nullptr && this->StartAnimationParticle->get_isPlaying()) {
	//	this->StartAnimationParticle->Stop();
	//}
	if(this->startAnimation != nullptr)
		this->startAnimation->removeFromParentAndCleanup(true);
	//if(this->StartExplodeParticle != nullptr && this->StartExplodeParticle->get_isPlaying()) {
	//	this->StartExplodeParticle->Stop();
	//}
	//this->currentGrid = nullptr;
	//if(this->ExplodeAnimator != nullptr) {
	//	this->ExplodeAnimator.get_gameObject().SetActive(false);
	//}
	//if(this->UseParticle != nullptr) {
	//	this->UseParticle.SetActive(false);
	//}
}

void DiscoBallItem::AfterPoolInit() {
	SpecialItem::AfterPoolInit();
	this->_raysEnded = false;
	this->Score = 0;
	this->CurrentSpriteRenderer->setVisible(true);
	//this->RelativeContainer.SetActive(true);
}

void DiscoBallItem::RemoveSelf() {
	this->OnBeforeRemove();
	//SpecialItem::get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void DiscoBallItem::SetTintColor(MatchType matchType) {
	//HueColor hueColor;
	switch(matchType) {
	case MatchType::Yellow:	ImageLibrary::CopySprite(CurrentSpriteRenderer, IMGLIB->DiscoBallSprites[0]); /*hueColor = DiscoBallItem::HueYellow;*/	break;
	case MatchType::Red:	ImageLibrary::CopySprite(CurrentSpriteRenderer, IMGLIB->DiscoBallSprites[1]); /*hueColor = DiscoBallItem::HueRed;*/		break;
	case MatchType::Blue:	ImageLibrary::CopySprite(CurrentSpriteRenderer, IMGLIB->DiscoBallSprites[2]); /*hueColor = DiscoBallItem::HueBlue;*/	break;
	case MatchType::Green:	ImageLibrary::CopySprite(CurrentSpriteRenderer, IMGLIB->DiscoBallSprites[3]); /*hueColor = DiscoBallItem::HueGreen;*/	break;
	case MatchType::Purple:	ImageLibrary::CopySprite(CurrentSpriteRenderer, IMGLIB->DiscoBallSprites[4]); /*hueColor = DiscoBallItem::HuePurple;*/	break;
	case MatchType::Orange:	ImageLibrary::CopySprite(CurrentSpriteRenderer, IMGLIB->DiscoBallSprites[5]); /*hueColor = DiscoBallItem::HueOrange;*/	break;
	}
	//if(this->AnimationSpriteColor != nullptr) {
	//	this->AnimationSpriteColor.HueShift = (float)hueColor.ChangeHue;
	//	this->AnimationSpriteColor.Saturation = hueColor.ColorSaturation;
	//	this->AnimationSpriteColor.ValueBrightness = hueColor.Brightness;
	//	this->AnimationSpriteColor.CallUpdate();
	//}
	//if(this->SpeedEffectColor == nullptr) {
	//	return;
	//}
	//this->SpeedEffectColor.HueShift = (float)hueColor.ChangeHue;
	//this->SpeedEffectColor.Saturation = 2f;
	//this->SpeedEffectColor.ValueBrightness = 2f;
	//this->SpeedEffectColor.CallUpdate();

	cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	newrect.origin.y -= 22.0f; newrect.size.height += 22.0f;
	CurrentSpriteRenderer->setTextureRect(newrect);
}

void DiscoBallItem::PlaySpecialItemCreationAnimation() {
	//Sequence sequence = DOTween.Sequence();
	//TweenSettingsExtensions.AppendInterval(sequence, 0.3f);
	//TweenSettingsExtensions.AppendCallback(sequence, delegate
	//{
	//	ParticlePool.Instance.PlayParticle(ParticlePool.Instance.SpecialItemCreationParticle, this, true);
	//});
	this->CurrentSpriteRenderer->runAction(Sequence::create(
		DelayTime::create(0.3f),
		CallFunc::create([this]() {PTCLLIB->createSpecialItem(this->get_CurrentCell()->GetFrozenPosition()); }),
		nullptr
		));
}

void DiscoBallItem::ExplodeCells() {
	isExploded = true;
	Vector<FiniteTimeAction*> seq;
	// step 0:
	this->CurrentSpriteRenderer->setOpacity(0);
	//this->ExplodeAnimator.get_gameObject().SetActive(true);
	//__zorder = this->CurrentSpriteRenderer.zOrder() + 0x7d0;
	//this->ExplodeSpriteRenderer.setzOrder(__zorder);
	//for(int i = 0; i < this->ExplodeParticleRenderers.Length; i++) {
	//	if(i == 1) {
	//		this->ExplodeParticleRenderers[i].setzOrder(__zorder + 1);
	//	}
	//	else {
	//		this->ExplodeParticleRenderers[i].set_zOrder(__zorder - (i + 1));
	//	}
	//}
	//this->UseParticle.SetActive(true);
	//this->StartAnimationParticle.Play();
	startAnimation = PTCLLIB->showDiscoWhirl(this->EffectiveItemType, this->get_CurrentCell()->GetFrozenPosition());

	this->Score = this->GetScore();
	//this->ExplodeAnimator.SetBool("explode", true);
	this->currentGrid = this->get_CurrentCell()->CurrentGrid;
	this->originPos = this->get_CurrentCell()->GetFrozenPosition();
	if(this->ShouldBlockFalls())
		FallManager::IncreaseWaitingFallBlocker();
	
	FallManager::IncreaseMechanicAnimation();
	//this-><rayParticles>__0 = new List<ParticlePlayer>();
	rayParticles.clear();
	//this-><explodeCells>__0 = new List<Cell>(20);
	explodeCells.clear(); explodeCells.reserve(20);
	//if(<>f__am$cache0 == null) {
	//	<>f__am$cache0 = new Func<Cell, bool>(DiscoBallItem.<ExplodeCells>c__Iterator0.<>m__1);
	//}
	//this-><explodeCells>__0.AddRange(this->currentGrid.WalkOnExistings().Where<Cell>(new Func<Cell, bool>(this-><>m__0)).Where<Cell>(<>f__am$cache0));
	std::vector<Cell*> existingcells = this->currentGrid->WalkOnExistings();
	for(Cell* c : existingcells)
		if(((c->get_HasItem() && (c->get_CurrentItem()->GetMatchType() == this->EffectiveItemType)) && c->get_CurrentItem()->CanBeEffectedByDiscoBall()) && !c->ReservedForGeneratorItem)
			if(c->get_CurrentItem()->CanBeEffectedByDiscoBall())
				explodeCells.push_back(c);
	//this-><explodeCells>__0.Shuffle<Cell>();
	ListExt_Shuffle(this->explodeCells);
	//for(int j = 0; j < this-><explodeCells>__0.Count; j++) {
	//	Cell cell = this-><explodeCells>__0[j];
	//	cell.CurrentItem.ToBeExplodedBy = ExplodeReason.Disco;
	//}
	for(Cell* c : this->explodeCells)
		c->get_CurrentItem()->ToBeExplodedBy = ExplodeReason::Disco;

	//this->$current = new WaitForSeconds(0.1f);
	//if(!this->$disposing) {
	//	this->$PC = 1;
	//}
	seq.pushBack(DelayTime::create(0.1f));
	//goto Next;
	//
	//// step 1:
	//this-><audioSource>__0 = this->get_gameObject().AddComponent<AudioSource>();
	//this-><i>__1 = 0;
	//break;
	//
	//// step 2:
	//this-><i>__1++;
	//break;
	//
	//
	////1,2
	//if(this.<i>__1 < this.<explodeCells>__0.Count) {
	//	this.<cell>__2 = this.<explodeCells>__0[this.<i>__1];
	//	this.<p>__2 = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DiscoRayParticle, this.originPos + DiscoBallItem.ParticleStartOffset, false) as DiscoRayParticlePlayer;
	//	this.<p>__2.SetColor(this.$this.EffectiveItemType);
	//	this.$this.PlayRayParticle(this.<p>__2);
	//	AudioManager.Play(AudioTag.ItemSpecialDiscoRay, PlayMode.Multiple, this.<audioSource>__0, 1f);
	//	this.$this.MoveRay(this.<cell>__2, this.<p>__2);
	//	this.<rayParticles>__0.Add(this.<p>__2);
	//	this.$current = new WaitForSeconds(0.05f);
	//	if(!this.$disposing) {
	//		this.$PC = 2;
	//	}
	//}
	for(int i = 0; i < (int)this->explodeCells.size(); i++) {
		Cell* c = explodeCells[i];
		seq.pushBack(CallFunc::create([this, c]() {
			ParticleSystemQuad* p = ParticleLibrary::cloneParticle(PTCLLIB->discoRay);
			LevelBuilder::ActiveLevel->CurrentLevelBuilder->ItemContainer->addChild(p, PARTICLE_SOLID_ZORDER-1);
			p->setPosition(originPos);
			p->setScaleX(0.0f);
			//	this.<p>__2.SetColor(this.$this.EffectiveItemType);
			this->PlayRayParticle(p);
			//AudioManager.Play(AudioTag.ItemSpecialDiscoRay, PlayMode.Multiple, this.<audioSource>__0, 1f);
			this->MoveRay(c, p);
			this->rayParticles.push_back(p);
		}));
		seq.pushBack(DelayTime::create(0.05f));
	}
	//else {
	//	this.$current = new WaitForSeconds(0.5f);
	//	if(!this.$disposing) {
	//		this.$PC = 3;
	//	}
	//}
	//goto Label_0528;
	seq.pushBack(DelayTime::create(0.5f));
	//
	//// step 3:
	//this->StartExplodeParticle.Play();
	seq.pushBack(CallFunc::create([this]() {PTCLLIB->showDiscoSuction(this->originPos); }));
	//this->$current = new WaitForSeconds(0.65f);
	seq.pushBack(DelayTime::create(0.65f));
	//if(!this->$disposing) {
	//	this->$PC = 4;
	//}
	//goto Next;
	//
	//// step 4:
	//{
	//	this->StartExplodeParticle.Stop();
	//	int num4 = 0;
	//	int count = this-><rayParticles>__0.Count;
	//	while(num4 < count) {
	//		this-><rayParticles>__0[num4].HardStop();
	//		num4++;
	//	}
	//	this->_raysEnded = true;
	//	this-><explodeParticle>__0 = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DiscoExplodeParticle, this->get_transform().get_position(), false) as DiscoExplosionParticlePlayer;
	//	this-><explodeParticle>__0.SetColor(this->EffectiveItemType);
	//	this-><explodeParticle>__0.Play();
	//	this->$current = null;
	//	if(!this->$disposing) {
	//		this->$PC = 5;
	//	}
	//	goto Next;
	//}
	seq.pushBack(CallFunc::create([this]() {
		for(ParticleSystemQuad* p : this->rayParticles)
			p->removeFromParentAndCleanup(true);
		//this->_raysEnded = true;
		this->_onRaysEnded();
		PTCLLIB->explodeDisco(this->EffectiveItemType, this->originPos);
		PTCLLIB->showDiscoExplode(this->originPos);
		startAnimation->setVisible(false);
	}));
	//// step 5:
	//this-><audioSource>__0.Stop();
	//Object.Destroy(this-><audioSource>__0);
	//AudioManager.Play(AudioTag.ItemSpecialDiscoExplode, PlayMode.Frame, null, 1f);
	//this->RelativeContainer.SetActive(false);
	//this-><w>__0 = this->DoDiscoExpldoes(this-><explodeCells>__0);
	seq.pushBack(CallFunc::create([this]() {
		//AudioManager.Play(AudioTag.ItemSpecialDiscoExplode, PlayMode.Frame, null, 1f);
		//this->RelativeContainer.SetActive(false);
		this->DoDiscoExpldoes(this->explodeCells);
	}));
	//goto Label_0504;
	//
	//// step 6:
	//goto Label_0504;
	
	////5,6
	//if(this.<w>__0.MoveNext()) {
	//	this.$current = this.<w>__0.Current;
	//	if(!this.$disposing) {
	//		this.$PC = 6;
	//	}
	//	goto Label_0528;
	//}
	//this.$this.DoDie();
	seq.pushBack(CallFunc::create([this]() {this->DoDie(); }));
	
	// ExplodeCells ended
	seq.pushBack(CallFunc::create([this]() {afterExplodeCells(); }));
	CurrentSpriteRenderer->runAction(Sequence::create(seq));
}

void DiscoBallItem::DoDie() {
	explodeCells.clear();

	ScoreManager::RaiseScore(this->Score, CurrentSpriteRenderer->getPosition(), MatchType::None);
	if(CurrentSpriteRenderer->isVisible()) {
		//SpecialItem::StartCoroutine(this->Die());
		this->Die();
	}
	else {
		this->RemoveSelf();
	}
}

void DiscoBallItem::PlayRayParticle(ParticleSystemQuad* p) {
	p->setVisible(true);
	p->resetSystem();
}


void DiscoBallItem::DoDiscoExpldoes(std::vector<Cell*>& explodeCells) {
	for(Cell* onecell : explodeCells) {
		Item* currentItem = onecell->get_CurrentItem();
		if(this->ExplodeBySpecialItem(onecell)) {
			this->Score += SpecialItem::GetScoreForSpecialItem(currentItem, onecell);
		}
		else if((onecell->get_HasItem() && onecell->get_CurrentItem()->CanGenerateScoreOnEachTryExplode()) && onecell->get_CurrentItem()->CanGenerateScoreThisTurn()) {
			this->Score += currentItem->GetScore();
		}
	}
}


void DiscoBallItem::OnRayReached(Cell* cell, Item* i, FiniteTimeAction* tweener, ParticleSystemQuad* p) {
	cocos2d::Sprite* _tgtsprite = LevelBuilder::getItemSprite(i);

	Vector<FiniteTimeAction*> seq;
	//switch(num) {
	//case 0:
	seq.pushBack(DelayTime::create(0));
	//case 1:
	// delay until tweener is disactivated
	//	if(this.tweener.IsActive() && this.tweener.IsPlaying()) {
	//		this.$current = null;
	//		if(!this.$disposing) {
	//			this.$PC = 1;
	//		}
	//		goto yield next;;
	//	}
	seq.pushBack(DelayTime::create(tweener->getDuration()));
	seq.pushBack(CallFunc::create([this, cell, i, p, _tgtsprite]() {
		//	if((this.i != null) && !this.i.ReCycled) {
		//		this.<itemParticle>__0 = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DiscoRayReachedParticle, this.cell.GetFrozenPosition() + DiscoBallItem.ParticleStartOffset, false);
		//		this.<itemParticle>__0.Play();
		//		this.<t>__0 = DOTween.Sequence();
		//		this.<t>__0.Append(this.i.get_transform().DOLocalRotate(new Vector3(0f, 0f, 7f), 0.05f, RotateMode.Fast));
		//		this.<t>__0.Append(this.i.get_transform().DOLocalRotate(new Vector3(0f, 0f, -7f), 0.1f, RotateMode.Fast));
		//		this.<t>__0.Append(this.i.get_transform().DOLocalRotate(new Vector3(0f, 0f, 0f), 0.05f, RotateMode.Fast));
		//		this.<t>__0.SetLoops<Sequence>(-1);
		//		break;
		//	}
		ParticleSystemQuad* ptp = ParticleLibrary::cloneParticle(PTCLLIB->discoPoint);
		LevelBuilder::ActiveLevel->CurrentLevelBuilder->ItemContainer->addChild(ptp, PARTICLE_SOLID_ZORDER);
		ptp->setPosition(cell->GetFrozenPosition());
		this->PlayRayParticle(ptp);
		this->rayParticles.push_back(ptp);

		if(_tgtsprite != nullptr) {
			_tgtsprite->runAction(RepeatForever::create(Sequence::create(
				RotateTo::create(0.05f,7.0f),
				RotateTo::create(0.1f, -7.0f),
				RotateTo::create(0.05f, 0.0f),
				nullptr
				)));
		}
		//	this.p.HardStop();
	}));
	//	goto yield break;;
	//
	//case 2:
	//	break;
	//
	//default:
	//	goto yield break;;
	//}
	//while(!this.$this._raysEnded) {
	//	this.$current = null;
	//	if(!this.$disposing) {
	//		this.$PC = 2;
	//	}
	//	goto yield next;;
	//}
	//if(this.i != null) {
	//	this.i.get_transform().set_rotation(Quaternion.get_identity());
	//}

	//this.<t>__0.Kill(false);
	//this.<itemParticle>__0.Recycle<ParticlePlayer>();

	this->CurrentSpriteRenderer->runAction(Sequence::create(seq));
}

void DiscoBallItem::_onRaysEnded() {
	_raysEnded = true;
}

void DiscoBallItem::Die() {
	Vector<FiniteTimeAction*> seq;
	seq.pushBack(DelayTime::create(0.4f));
	seq.pushBack(CallFunc::create([this]() {
		if(this->ShouldBlockFalls())
			FallManager::DecreaseWaitingFallBlocker();
		FallManager::DecreaseMechanicAnimation();
	}));
	seq.pushBack(DelayTime::create(2.6f));
	seq.pushBack(CallFunc::create([this]() {this->RemoveSelf(); }));
	this->CurrentSpriteRenderer->runAction(Sequence::create(seq));
}

void DiscoBallItem::MoveRay(Cell* cell, ParticleSystemQuad* p) {
	if(!cell->get_HasItem()) {
		return;
	}
	Item* currentItem = cell->get_CurrentItem();
	//new Task(this->OnRayReached(cell, currentItem, ShortcutExtensions.DOMove(p.get_transform(), currentItem.get_transform().get_position() + Constants.LocalCenterOfCube + DiscoBallItem.ParticleEndOffset, 0.2f, false), p));
	FiniteTimeAction* moveaction = MoveTo::create(0.2f, (p->getPosition()+currentItem->get_CurrentCell()->GetFrozenPosition())/2);
	static_cast<Node*>(p)->setRotation(-CC_RADIANS_TO_DEGREES((p->getPosition() - currentItem->get_CurrentCell()->GetFrozenPosition()).getAngle()));
	static_cast<Node*>(p)->setScaleX(0.0f);
	p->runAction(ScaleTo::create(0.2f, (p->getPosition() - currentItem->get_CurrentCell()->GetFrozenPosition()).length() / 230.0f, p->getScaleY()));
	p->runAction(moveaction);
	this->OnRayReached(cell, currentItem,
					   //ShortcutExtensions.DOMove(p.get_transform(), currentItem.get_transform().get_position() + Constants.LocalCenterOfCube + DiscoBallItem.ParticleEndOffset, 0.2f, false),
					   moveaction,
					   p);
}

