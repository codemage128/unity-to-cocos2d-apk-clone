#include "Booster.h"
#include "Cell.h"
#include "Item.h"
#include "FallManager.h"
#include "HintManager.h"
#include "JellyManager.h"
#include "Grid.h"
#include "LevelBuilder.h"
#include "Level.h"
#include "ParticleLibrary.h"
#include "Shuffle.h"
#include "ScnLevelPlay.h"
#include "global/GameManager.h"

USING_NS_CC;

BoosterManager* BoosterManager::_instance = nullptr;

void BoosterManager::init(cocos2d::Node* scene) {
	_processor = Sprite::create();
	scene->addChild(_processor);
}

void BoosterManager::cleanUp() {
	_processor->removeFromParentAndCleanup(true);
	delete _instance;
	_instance = nullptr;
}

void BoosterManager::AnvilClicked() {
	this->ItemClicked(InventoryItemType::Anvil, BoosterState::InAnvil);
}
void BoosterManager::BoxingGloveClicked() {
	this->ItemClicked(InventoryItemType::BoxingGlove, BoosterState::InBoxingGlove);
}
void BoosterManager::HammerClicked() {
	this->ItemClicked(InventoryItemType::Hammer, BoosterState::InHammer);
}
void BoosterManager::ShuffleClicked() {
	this->ItemClicked(InventoryItemType::Dice, BoosterState::InShuffle);
}
void BoosterManager::PaintBrushClicked() {
}

int getBoosterItemCount(InventoryItemType itemType) {
	switch(itemType) {
	case InventoryItemType::Anvil: return GM->getBoosterAnvilCount();
	case InventoryItemType::BoxingGlove: return GM->getBoosterBoxingCount();
	case InventoryItemType::Hammer: return GM->getBoosterHammerCount();
	case InventoryItemType::Dice: return GM->getBoosterShuffleCount();
	}
	return 0;
}

bool useBoosterIfPossible(InventoryItemType itemType, int count) {
	if(getBoosterItemCount(itemType) < 1) return false;
	switch(itemType) {
	case InventoryItemType::Anvil: GM->updateBoosterAnvilCount(-count); return true;
	case InventoryItemType::BoxingGlove: GM->updateBoosterBoxingCount(-count); return true;
	case InventoryItemType::Hammer: GM->updateBoosterHammerCount(-count); return true;
	case InventoryItemType::Dice: GM->updateBoosterShuffleCount(-count); return true;
	}
	return false;
}

void BoosterManager::ItemClicked(InventoryItemType itemType, BoosterState state) {
	if((!FallManager::AreFallsBlocked() && !FallManager::AreThereFallingItems()) && !FallManager::AreThereMechanicAnimations()) {
		if((((LevelBuilder::ActiveLevel->get_MovesLeft() > 0) && !LevelBuilder::ActiveLevel->LevelWon) /*&& !this->CurrentLevelBuilder.CurrentLevel.IsGoalsCompleted()*/)/* && (CollectorItemsController.Instance.GetBlasters().WaitingToLaunchCount() <= 0)*/) {
			if(getBoosterItemCount(itemType) > 0) {
				if(this->_currentState != BoosterState::Busy) {
					if(this->_currentState == state) {
						this->SwitchToGamePlay();
						LevelBuilder::ActiveLevel->CurrentLevelBuilder->LevelScene->updateBottomPanel(); //this->UpdateBoosterButtonDisplay();
					}
					else {
						this->SwitchToBoosterState(itemType, state);
					}
				}
			}
			else {
				//this->CreateNotEnoughResourcesDialog(itemType);
			}
		}
	}
}

bool BoosterManager::isInBoosterMode() {
	return _currentState != BoosterState::InGamePlay || _processor->getNumberOfRunningActions()!=0;
}

void BoosterManager::CellTapped(Cell* cell) {
	if(((cell->Exists && cell->get_HasItem()) && !cell->get_CurrentItem()->IsSpecialItem()) && ((this->_currentState != BoosterState::InShuffle) || cell->get_CurrentItem()->CanShuffle()))
		this->UseBooster(cell);
}

void BoosterManager::UseBooster(Cell* cell) {
	if(((cell->get_HasItem() && (this->_currentState != BoosterState::InHammer || cell->get_CurrentItem()->BoosterHammerCanBeUsed())) && (this->_currentState != BoosterState::InAnvil || cell->get_CurrentItem()->BoosterAnvilCanBeUsed())) && (this->_currentState != BoosterState::InBoxingGlove || cell->get_CurrentItem()->BoosterBoxingGloveCanBeUsed())) {
		LevelBuilder::ActiveLevel->CurrentLevelBuilder->LevelScene->hideBoosterDesc();//this->BoosterBackground.Hide();
		//this->BoosterUseParticle.Stop();
		//this->BoosterUseParticle.get_gameObject().SetActive(false);
		LevelBuilder::ActiveLevel->CurrentLevelBuilder->LevelScene->updateBottomPanel(); //this->UpdateBoosterButtonDisplay();
		switch(this->_currentState) {
		case BoosterState::InHammer: this->UseHammer(cell); break;
		case BoosterState::InAnvil: this->UseAnvil(cell); break;
		case BoosterState::InBoxingGlove: this->UseBoxingGlove(cell); break;
		case BoosterState::InShuffle: this->UseShuffle(cell); break;
		case BoosterState::InPaintBrushState: this->UsePaintBrush(cell); break;
		default: this->SwitchToGamePlay(); break;
		}
		FallManager::StartRunning();
	}
}

void BoosterManager::UseAnvil(Cell* cell) {
	Vector<FiniteTimeAction*> seq;
//{
//case 0:
	if (!cell->get_HasItem() || !cell->get_CurrentItem()->BoosterAnvilCanBeUsed()) {
//		goto end;
		return;
	}
	bool canSpend = useBoosterIfPossible(InventoryItemType::Anvil, 1);
	if(canSpend) {
		LevelBuilder::ActiveLevel->CurrentLevelBuilder->LevelScene->updateBottomPanel(); // this->UpdateBoosterCounts();
		LevelBuilder::ActiveLevel->IncreaseTurnNo();
//		this->CurrentBoosterTapListener.SetActive(false);
		this->_currentState = BoosterState::Busy;
		FallManager::IncreaseWaitingFallBlocker();
//		this->$current = null;
//		if (!this->$disposing)
//		{
//			this->$PC = 1;
//		}
//		goto nextframe;
	}
	else {
		this->SwitchToGamePlay();
//	goto end;
		return;
	}
//
//case 1:
//	this-><anvilStartPosition>__1 = cell->GetFrozenPosition();
//	this-><anvilStartPosition>__1.y = 7f;
//	this-><anvilStopPosition>__1 = this-><anvilStartPosition>__1;
//	this-><anvilStopPosition>__1.y = CameraHelper.Bottom.y;
//	this-><currentGrid>__1 = this->CurrentLevelBuilder.CurrentLevel.CurrentGrid;
//	this-><justAboveFirstCell>__1 = LevelBuilder::ActiveLevel->CurrentGrid->cell[cell->X, LevelBuilder::ActiveLevel->CurrentGrid->cell.Height - 1].GetFrozenPosition();
//	this-><justAboveFirstCell>__1.y += 1.6f;
//	this-><distance>__1 = this-><anvilStartPosition>__1.y - this-><justAboveFirstCell>__1.y;
//	this->Anvil.get_transform().set_position(this-><anvilStartPosition>__1);
//	this->Anvil.get_gameObject().SetActive(true);
//	AudioManager.Play(AudioTag.BoosterAnvil, PlayMode.Frame, null, 1f);
//	this->Anvil.TrailSmokeParticle.Play();
//	this->Anvil.AnvilSpriteRenderer.set_enabled(true);
	seq.pushBack(CallFunc::create([cell]() {PTCLLIB->showUseAnvil(Vec2(cell->GetFrozenPosition().x, 100.0f)); }));
	seq.pushBack(DelayTime::create(0.1f));
//	this-><fallOfAnvil>__1 = DOTween.Sequence();
//	TweenSettingsExtensions.SetEase<Sequence>(this-><fallOfAnvil>__1, 8);
//	TweenSettingsExtensions.Append(this-><fallOfAnvil>__1, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMoveY(this->Anvil.get_transform(), this-><justAboveFirstCell>__1.y, this-><distance>__1 * 0.1f, false), 1));
	for (int i = LevelBuilder::ActiveLevel->CurrentGrid->Height - 1; i >= 0; i--) {
		Cell* candidateCell = LevelBuilder::ActiveLevel->CurrentGrid->cell(cell->X, i);
		//TweenSettingsExtensions.Append(this-><fallOfAnvil>__1, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMoveY(this->Anvil.get_transform(), candidateCell.GetFrozenPosition().y + 0.6f, 0.1f, false), 1));
		if (candidateCell->get_HasItem() && candidateCell->get_CurrentItem()->CanBeExplodedByBooster()) {
			//TweenSettingsExtensions.AppendCallback(this-><fallOfAnvil>__1, this->ExplodeLater(candidateCell, Direction.Up, ExplodeReason.Anvil));
			seq.pushBack(CallFunc::create([this, candidateCell]() {
				Item* currentItem = nullptr;
				if(candidateCell->get_HasItem()) {
					currentItem = candidateCell->get_CurrentItem();
					currentItem->InformToBeExplodedBySpecialItem(nullptr, Direction::Up);
					currentItem->ToBeExplodedBy = ExplodeReason::Anvil;
				}
				Grid* currentGrid = LevelBuilder::ActiveLevel->CurrentGrid;
				currentGrid->ExplodeCell(candidateCell, nullptr);
				if(currentItem != nullptr) {
					currentItem->ToBeExplodedBy = ExplodeReason::None;
				}
				currentGrid->CurrentLevel->JellyItemManager->ResetExplodeCounter();
			}));
			seq.pushBack(DelayTime::create(10 / 40.0f / 4));
		}
	}
	seq.pushBack(DelayTime::create(0.4f));
	seq.pushBack(CallFunc::create([cell]() {PTCLLIB->showAnvilExplode(Vec2(cell->GetFrozenPosition().x, -250.0f)); }));

	Node* targetnode = LevelBuilder::ActiveLevel->CurrentLevelBuilder->SceneContainer;
	Vec2 tgtorgpos = targetnode->getPosition();
	seq.pushBack(TargetedAction::create(targetnode, Sequence::create(MoveTo::create(0.045f, tgtorgpos + Vec2(0, -40)), MoveTo::create(0.045f, tgtorgpos + Vec2(0, 20)), MoveTo::create(0.045f, tgtorgpos + Vec2(0, -20)), MoveTo::create(0.045f, tgtorgpos + Vec2(0, 10)), MoveTo::create(0.045f, tgtorgpos), nullptr)));
	seq.pushBack(DelayTime::create(0.5f));

//	this-><distanceToStop>__1 = LevelBuilder::ActiveLevel->CurrentGrid->cell[cell->X, 0].GetFrozenPosition().y - this-><anvilStopPosition>__1.y;
//	TweenSettingsExtensions.Append(this-><fallOfAnvil>__1, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMove(this->Anvil.get_transform(), this-><anvilStopPosition>__1, this-><distanceToStop>__1 * 0.1f, false), 1));
//	TweenExtensions.Goto(this-><fallOfAnvil>__1, 0.5f, true);
//	this->$current = TweenExtensions.WaitForCompletion(this-><fallOfAnvil>__1);
//	if (!this->$disposing)
//	{
//		this->$PC = 2;
//	}
//	goto nextframe;
//
//case 2:
//	this->Anvil.PlayHit();
//	this->Anvil.get_gameObject().SetActive(false);
//	this-><waiter>__1 = this->Anvil.GetWaiter();
//	break;
//
//case 3:
//	break;
//[break to]
//if (this-><waiter>__1.MoveNext())
//{
//this->$current = this-><waiter>__1.Current;
//if (!this->$disposing)
//{
//	this->$PC = 3;
//}
//}
//else
//{
//this->$current = new WaitForSeconds(0.1f);
//if (!this->$disposing)
//{
//	this->$PC = 4;
//}
//}
//goto nextframe;
//case 4:
	seq.pushBack(CallFunc::create([]() {FallManager::DecreaseWaitingFallBlocker(); }));
//	this->$current = null;
//	if (!this->$disposing)
//	{
//		this->$PC = 5;
//	}
//	goto nextframe;
//
//case 5:
//case 6:
//	while (FallManager.AreThereFallingItems())
//	{
//		this->$current = null;
//		if (!this->$disposing)
//		{
//			this->$PC = 6;
//		}
//		goto nextframe;
//	}
//	this->SwitchToGamePlay();
	seq.pushBack(CallFunc::create([this]() {this->SwitchToGamePlay(); }));
//	this->$current = null;
//	if (!this->$disposing)
//	{
//		this->$PC = 7;
//	}
//	goto nextframe;
//
//case 7:
//	goto end;
//
//case 8:
//	this->$PC = -1;
//	goto end;
//
//default:
//	goto end;
//}
//end:
//this->$current = null;
//if (!this->$disposing)
//{
//this->$PC = 8;
//}
//goto nextframe;
//end:
//return false;
//nextframe:
//return true;
	_processor->runAction(Sequence::create(seq));
}
void BoosterManager::UseBoxingGlove(Cell* cell) {
	Vector<FiniteTimeAction*> seq;
//case 0:
	if(!cell->get_HasItem() || !cell->get_CurrentItem()->BoosterBoxingGloveCanBeUsed()) {
//		break;
		return;
	}
	bool canSpend = useBoosterIfPossible(InventoryItemType::BoxingGlove, 1);
	if(canSpend) {
		LevelBuilder::ActiveLevel->CurrentLevelBuilder->LevelScene->updateBottomPanel(); //this.UpdateBoosterCounts();
		LevelBuilder::ActiveLevel->IncreaseTurnNo();
		//this.CurrentBoosterTapListener.SetActive(false);
		this->_currentState = BoosterState::Busy;
		FallManager::IncreaseWaitingFallBlocker();
//		this.$current = null;
//		if(!this.$disposing) {
//			this.$PC = 1;
//		}
//		goto next frame;
	}
	else {
		this->SwitchToGamePlay();
//	goto end;
		return;
	}
//
//case 1:
//	this.<gloveStartPosition>__1 = cell->GetFrozenPosition();
//	this.<boxingGloveStartPosition>__1 = this.<gloveStartPosition>__1;
//	this.<boxingGloveStartPosition>__1.x = -7f;
//	this.<currentGrid>__1 = this.CurrentLevelBuilder.CurrentLevel.CurrentGrid;
//	this.<justLeftOfFirstCell>__1 = this.<currentGrid>__1[0, cell->Y].GetFrozenPosition();
//	this.<justLeftOfFirstCell>__1.x -= 2.2f;
//	this.<distance>__1 = this.<justLeftOfFirstCell>__1.x - this.<boxingGloveStartPosition>__1.x;
//	this.BoxingGlove.get_transform().set_position(this.<boxingGloveStartPosition>__1);
//	this.BoxingGlove.get_gameObject().SetActive(true);
//	this.<speed>__1 = 0.04f;
//	this.<boxingGloveSeq>__1 = DOTween.Sequence();
	seq.pushBack(CallFunc::create([this, cell]() {PTCLLIB->showUseBoxingGlove(Vec2((LevelBuilder::ActiveLevel->CurrentGrid->Width-1.5f)*ITEM_SPRITE_SIZE_X / 2.0f, cell->GetFrozenPosition().y)); }));
//	TweenSettingsExtensions.SetEase<Sequence>(this.<boxingGloveSeq>__1, 1);
//	TweenSettingsExtensions.Append(this.<boxingGloveSeq>__1, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMove(this.BoxingGlove.get_transform(), this.<justLeftOfFirstCell>__1, this.<distance>__1 * this.<speed>__1, false), 1));
	for(int i = 0; i < LevelBuilder::ActiveLevel->CurrentGrid->Width; i++) {
		Cell* candidateCell = LevelBuilder::ActiveLevel->CurrentGrid->cell(i, cell->Y);
		Vec2 frozenPosition = candidateCell->GetFrozenPosition();
		//frozenPosition.x -= 1.2f;
		//TweenSettingsExtensions.Append(this.<boxingGloveSeq>__1, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMove(this.BoxingGlove.get_transform(), frozenPosition, this.<speed>__1, false), 1));
		if(candidateCell->get_HasItem() && candidateCell->get_CurrentItem()->CanBeExplodedByBooster()) {
			//TweenSettingsExtensions.AppendCallback(this.<boxingGloveSeq>__1, this.ExplodeLater(candidateCell, Direction.Left, ExplodeReason.BoxingGlove));
			seq.pushBack(CallFunc::create([this,candidateCell]() {
				Item* currentItem = nullptr;
				if(candidateCell->get_HasItem()) {
					currentItem = candidateCell->get_CurrentItem();
					currentItem->InformToBeExplodedBySpecialItem(nullptr, Direction::Left);
					currentItem->ToBeExplodedBy = ExplodeReason::BoxingGlove;
				}
				Grid* currentGrid = LevelBuilder::ActiveLevel->CurrentGrid;
				currentGrid->ExplodeCell(candidateCell, nullptr);
				if(currentItem != nullptr) {
					currentItem->ToBeExplodedBy = ExplodeReason::None;
				}
				currentGrid->CurrentLevel->JellyItemManager->ResetExplodeCounter();
			}));
			seq.pushBack(DelayTime::create(10 / 60.0f / 5));
		}
	}

	Node* targetnode = LevelBuilder::ActiveLevel->CurrentLevelBuilder->SceneContainer;
	Vec2 tgtorgpos = targetnode->getPosition();
	seq.pushBack(TargetedAction::create(targetnode, Sequence::create(MoveTo::create(0.05f, tgtorgpos + Vec2(45, 0)), MoveTo::create(0.04f, tgtorgpos + Vec2(60, 0)), MoveTo::create(0.07f, tgtorgpos), nullptr)));
	seq.pushBack(DelayTime::create(1.0f));

//	this.<hitAnim>__1 = ShortcutExtensions.DOMoveX(this.BoxingGlove.get_transform(), CameraHelper.Right.x - 1f, 0.4f, false);
//	TweenSettingsExtensions.SetEase<Tweener>(this.<hitAnim>__1, 0x18);
//	this.<hitAnim>__1.easeOvershootOrAmplitude = 1f;
//	TweenSettingsExtensions.Append(this.<boxingGloveSeq>__1, this.<hitAnim>__1);
//	TweenSettingsExtensions.InsertCallback(this.<boxingGloveSeq>__1, TweenExtensions.Duration(this.<boxingGloveSeq>__1, false) - 0.35f, new TweenCallback(this.BoxingGlove, (IntPtr) this.ShakeScreen));
//	TweenSettingsExtensions.AppendInterval(this.<boxingGloveSeq>__1, 0.1f);
//	TweenSettingsExtensions.AppendCallback(this.<boxingGloveSeq>__1, new TweenCallback(this.BoxingGlove, (IntPtr) this.PlayAnimationOut));
//	TweenSettingsExtensions.Append(this.<boxingGloveSeq>__1, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMove(this.BoxingGlove.get_transform(), new Vector3(CameraHelper.Left.x - 1f, this.<gloveStartPosition>__1.y, this.<gloveStartPosition>__1.z), 0.7f, false), 11));
//	if(BoosterManager.<>f__mg$cache0 == null) {
//		BoosterManager.<>f__mg$cache0 = new TweenCallback(null, (IntPtr)FallManager.DecreaseWaitingFallBlocker);
//	}
//	TweenSettingsExtensions.AppendCallback(this.<boxingGloveSeq>__1, BoosterManager.<>f__mg$cache0);
	seq.pushBack(CallFunc::create([this]() {FallManager::DecreaseWaitingFallBlocker(); }));
//	this.BoxingGlove.PlayAnimationIn((this.<speed>__1 * this.<currentGrid>__1.Width) + 0.2f);
//	this.$current = TweenExtensions.WaitForCompletion(this.<boxingGloveSeq>__1);
//	if(!this.$disposing) {
//		this.$PC = 2;
//	}
//	goto next frame;
//
//case 2:
//	this.BoxingGlove.get_gameObject().SetActive(false);
//	this.SwitchToGamePlay();
	seq.pushBack(CallFunc::create([this]() {this->SwitchToGamePlay(); }));
//	this.$current = null;
//	if(!this.$disposing) {
//		this.$PC = 3;
//	}
//	goto next frame;
//
//case 3:
//	break;
//
//case 4:
//	this.$PC = -1;
//	goto end;
//
//default:
//	goto end;
//
//	this.$current = null;
//	if(!this.$disposing) {
//		this.$PC = 4;
//	}
//	goto next frame;
//end:
//	return false;
//next frame:
//	return true;
	_processor->runAction(Sequence::create(seq));
}

void BoosterManager::UseHammer(Cell* cell) {
	Vector<FiniteTimeAction*> seq;
//switch (num)
//{
//	case 0:
//		this.$locvar0 = new <UseHammer>c__AnonStorey5();
//		this.$locvar0.cell = this.cell;
		if (!cell->get_HasItem() || !cell->get_CurrentItem()->BoosterHammerCanBeUsed()) {
//			goto end;
			return;
		}
//		this.$locvar1 = new <UseHammer>c__AnonStorey6();
//		this.$locvar1.<>f__ref$1 = this;
//		this.$locvar1.<>f__ref$5 = this.$locvar0;
		bool canSpend = useBoosterIfPossible(InventoryItemType::Hammer, 1);
		if (canSpend) {
			LevelBuilder::ActiveLevel->CurrentLevelBuilder->LevelScene->updateBottomPanel();//this.$this.UpdateBoosterCounts();
			LevelBuilder::ActiveLevel->IncreaseTurnNo();
//			this.$this.CurrentBoosterTapListener.SetActive(false);
			this->_currentState = BoosterState::Busy;
			FallManager::IncreaseWaitingFallBlocker();
//			this.$current = null;
//			if (!this.$disposing)
//			{
//				this.$PC = 1;
//			}
//			goto next frame;
		}
		else {
			this->SwitchToGamePlay();
//		goto end;
			return;
		}
//
//	case 1:
//		this.$this.Hammer2D.get_transform().set_position(this.$this.HammerStartPosition.get_position());
//		if (this.$this._hideAnimation != null)
//		{
//			TweenExtensions.Kill(this.$this._hideAnimation, false);
//		}
//		this.$this.Hammer2D.get_gameObject().SetActive(true);
//		this.$this.Hammer2D.HitAnimator.get_gameObject().SetActive(true);
//		this.$locvar1.currentGrid = this.$this.CurrentLevelBuilder.CurrentLevel.CurrentGrid;
//		this.<hammerAnim>__1 = this.$this.Hammer2D.PlayIn(this.$locvar0.cell.GetFrozenPosition(), new Action(this.$locvar1.<>m__0));
//		break;
		seq.pushBack(CallFunc::create([this, cell]() {PTCLLIB->showUseHammer(cell->GetFrozenPosition()); }));;
		seq.pushBack(DelayTime::create(1.333f));
		seq.pushBack(CallFunc::create([this, cell](){
			if(cell->get_HasItem()) {
				cell->get_CurrentItem()->ToBeExplodedBy = ExplodeReason::Hammer;
				cell->get_CurrentItem()->InformToBeExplodedBySpecialItem(nullptr, Direction::None);
			}
			LevelBuilder::ActiveLevel->CurrentGrid->ExplodeCell(cell, nullptr);
		}));
		seq.pushBack(CallFunc::create([this, cell]() {PTCLLIB->showHammerExplode(cell->GetFrozenPosition()); }));;
//	case 2:
//		break;
//[break to]
//while (this.<hammerAnim>__1.MoveNext())
//{
//	this.$current = this.<hammerAnim>__1.Current;
//	if (!this.$disposing)
//	{
//		this.$PC = 2;
//	}
//	goto next frame;
//}
//this.$locvar1.currentGrid.CurrentLevel.JellyItemManager.ResetExplodeCounter();
		seq.pushBack(CallFunc::create([]() {LevelBuilder::ActiveLevel->JellyItemManager->ResetExplodeCounter(); }));
//this.$current = new WaitForSeconds(0.400333f);
//if (!this.$disposing)
//{
//	this.$PC = 3;
//}//
//	case 3:
//		AudioManager.Play(AudioTag.BoosterHammerExit, PlayMode.Frame, null, 1f);
//		this.$this._hideAnimation = DOTween.Sequence();
//		if (<>f__am$cache0 == null)
//		{
//			<>f__am$cache0 = new TweenCallback(null, (IntPtr) <>m__0);
//		}
//		TweenSettingsExtensions.AppendCallback(this.$this._hideAnimation, <>f__am$cache0);
//		this.<endPoint>__1 = this.$this.HammerStartPosition.get_position();
//		this.<endPoint>__1.x -= 1.23f;
//		this.<endPoint>__1.y -= 0.7401493f;
//		TweenSettingsExtensions.Append(this.$this._hideAnimation, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMove(this.$this.Hammer2D.get_transform(), this.<endPoint>__1, 0.5f, false), 0x1a));
//		TweenSettingsExtensions.AppendCallback(this.$this._hideAnimation, new TweenCallback(this.$locvar1, (IntPtr) this.<>m__1));
//		TweenSettingsExtensions.AppendInterval(this.$this._hideAnimation, 1f);
//		TweenSettingsExtensions.AppendCallback(this.$this._hideAnimation, new TweenCallback(this.$locvar1, (IntPtr) this.<>m__2));
		Node* targetnode = LevelBuilder::ActiveLevel->CurrentLevelBuilder->CellContainer;
		Vec2 tgtorgpos = targetnode->getPosition();
		seq.pushBack(TargetedAction::create(targetnode, Sequence::create(MoveTo::create(0.03f, tgtorgpos + Vec2(30, -30)), MoveTo::create(0.02f, tgtorgpos + Vec2(40, -30)), MoveTo::create(0.05f, tgtorgpos), nullptr)));
		seq.pushBack(DelayTime::create(0.9f)); // wait until lift down the hammer
//		this.$this.SwitchToGamePlay();
		seq.pushBack(CallFunc::create([this]() {this->SwitchToGamePlay(); }));
//		this.$current = null;
//		if (!this.$disposing)
//		{
//			this.$PC = 4;
//		}
//		goto next frame;
//
//	case 4:
//		FallManager.DecreaseWaitingFallBlocker();
		seq.pushBack(CallFunc::create([this]() {FallManager::DecreaseWaitingFallBlocker(); }));
//		goto end;
//
//	case 5:
//		this.$PC = -1;
//		goto end;
//
//	default:
//		goto end;
//}
//goto next frame;
//end:
//this.$current = null;
//if (!this.$disposing)
//{
//	this.$PC = 5;
//}
//goto next frame;
//end:
//return false;
//next frame:
//return true;
	_processor->runAction(Sequence::create(seq));
}
void BoosterManager::UsePaintBrush(Cell* cell) {

}
void BoosterManager::UseShuffle(Cell* cell) {
	Vector<FiniteTimeAction*> seq;
//case 0:
	bool shufflePossible = cell->get_HasItem() && cell->get_CurrentItem()->CanShuffle();
	if(shufflePossible) {
		bool canSpend = ShuffleManager::TryShuffle(LevelBuilder::ActiveLevel->CurrentGrid) && useBoosterIfPossible(InventoryItemType::Dice, 1);
		if(!canSpend) {
			this->SwitchToGamePlay();
		}
		else {
			LevelBuilder::ActiveLevel->CurrentLevelBuilder->LevelScene->updateBottomPanel(); //this->UpdateBoosterCounts();
			LevelBuilder::ActiveLevel->IncreaseTurnNo();
			//this.CurrentBoosterTapListener.SetActive(false);
			this->_currentState = BoosterState::Busy;
			FallManager::IncreaseWaitingFallBlocker();
			seq.pushBack(DelayTime::create(1.1f));
			//this.$current = new WaitForSeconds(0.9f);
			//seq.pu
//			if(!this.$disposing) {
//				this.$PC = 1;
//			}
//			goto Label_0149;
		}
//		break;
	}

//	break;
//
//case 1:
//	this.SwitchToGamePlay();
//	FallManager.DecreaseWaitingFallBlocker();
//	this.$current = null;
//	if(!this.$disposing) {
//		this.$PC = 2;
//	}
//	goto Label_0149;
	seq.pushBack(CallFunc::create([this]() {
		this->SwitchToGamePlay();
		FallManager::DecreaseWaitingFallBlocker();
	}));
//
//case 2:
//	this.$PC = -1;
//	break;
	_processor->runAction(Sequence::create(seq));
}

void BoosterManager::SwitchToGamePlay() {
	//SettingsPanel.Instance.EnableSettings();
	this->_currentState = BoosterState::InGamePlay;
	//this->CurrentBoosterTapListener.SetActive(false);
	//this->CurrentTapListener.SetActive(true);
	HintManager::getInstance()->EnableHints();
	LevelBuilder::ActiveLevel->CurrentLevelBuilder->LevelScene->hideBoosterDesc();//this->BoosterBackground.Hide();
	//this->BoosterUseParticle.Stop();
	//this->BoosterUseParticle.get_gameObject().SetActive(false);
	//for(int i = 0; i < this->BoosterButtonColliders.Length; i++) {
	//	this->BoosterButtonColliders[i].set_enabled(true);
	//}
}


void BoosterManager::SwitchToBoosterState(InventoryItemType itemType, BoosterState state) {
	//SettingsPanel.Instance.DisableSettings();
	this->_currentState = state;
	//this->CurrentBoosterTapListener.SetActive(true);
	//this->CurrentTapListener.SetActive(false);
	HintManager::getInstance()->DisableHints();
	LevelBuilder::ActiveLevel->CurrentLevelBuilder->LevelScene->showBoosterDesc(itemType);//this->BoosterBackground.Show(itemType);
	int index = 0;
	switch(itemType) {
	case InventoryItemType::Hammer: index = 0; break;
	case InventoryItemType::Anvil: index = 1; break;
	case InventoryItemType::BoxingGlove: index = 2; break;
	case InventoryItemType::Dice: index = 3; break;
	default:
		if(itemType == InventoryItemType::PaintBrush) index = 4;	break;
	}
	//if((index < this->BoosterImages.Length) && (this->BoosterImages[index] != null)) {
	//	this->BoosterButtons[index].set_sortingOrder(this->BaseSortingOrder + 0x12d);
	//	this->BoosterImages[index].set_sortingOrder(this->BaseSortingOrder + 0x12e);
	//	Vector3 vector = this->BoosterButtons[index].get_transform().get_parent().get_localPosition();
	//	vector.x -= 0.025f;
	//	vector.y = 0.43f;
	//	this->BoosterUseParticle.get_gameObject().SetActive(true);
	//	this->BoosterUseParticle.get_transform().set_localPosition(vector);
	//	this->BoosterUseParticle.Play();
	//	for(int i = 0; i < this->BoosterButtonColliders.Length; i++) {
	//		if(i != index) {
	//			this->BoosterButtonColliders[i].set_enabled(false);
	//		}
	//	}
	//}
}
