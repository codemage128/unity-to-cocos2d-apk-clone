#include "UfoItem.h"
#include "UfoController.h"
#include "../Grid.h"
#include "../Cell.h"
#include "../Mathf.h"
#include "../Level.h"
#include "../Extension.h"
#include "../FallManager.h"
#include "../Animation.h"

void UfoItem::ExplodeByBlasterItem() {
	if (this->get_CurrentCell()->HasBubble)	{
		this->get_CurrentCell()->RemoveBubble();
	}
}

void UfoItem::Start() {
//	this->CurrentAnimator.StopPlayback();
//	this->CurrentAnimator.Play(Animator.StringToHash("Base Layer.UfoItemIdleAnimation"), -1, Mathf::Random::Range(0.0f, 1.0f));
}

void UfoItem::OnItemCreated(Level* currentLevel) {
	Item::OnItemCreated(currentLevel);
	UfoController::get_Instance()->RegisterUfoItem(this);
//	this->CurrentLevel->TouchAwareItem.Add(this);
//	this->SwapAnimation.OnComplete = new Action(this->OnSwapAnimationCompleted);
	this->_lastTurnNo = this->CurrentLevel->TurnNo;
//	this->_swapAnimationHash = Animator.StringToHash("Base Layer.UfoItemSwapAnimation");
}

void UfoItem::TouchOccured() {
	this->_lastExplodeTime = Ext_getCurrentFrame();
	int turnNo = this->CurrentLevel->TurnNo;
	if (this->_lastTurnNo != turnNo) {
		this->_shouldMoveUp = true;
		this->_lastTurnNo = turnNo;
	}
}

void UfoItem::OnFallUpdated() {
//	Item::OnFallUpdated();
	this->_shouldMoveUp = false;
}

bool UfoItem::TrySwap() {
	if (this->_isSwapping || !this->_shouldMoveUp || this->_lastExplodeTime == Ext_getCurrentFrame() || this->get_CurrentCell() == nullptr ||
		this->get_CurrentCell()->IsFloor || FallManager::AreThereMechanicAnimations() || this->AreThereFallingItemsInMyColumn()) {
		return false;
	}
	this->_shouldMoveUp = false;
	this->StartSwap();
	return true;
}

bool UfoItem::AreThereFallingItemsInMyColumn() {
	Grid* currentGrid = this->CurrentLevel->CurrentGrid;
	int x = this->get_CurrentCell()->X;
	int y = this->get_CurrentCell()->Y;
	for (int i = y; i >= 0; i--) {
		Cell* cell = currentGrid->cell(x, i);
		if (cell->Exists && cell->get_HasItem() && cell->get_CurrentItem()->IsFalling) {
			return true;
		}
	}
	return false;
}

void UfoItem::TryFall() {
	if (this->_inExplodeState || this->IsFalling) {
		return;
	}
	if (this->get_CurrentCell() == nullptr || !this->get_CurrentCell()->IsFloor) {
		return;
	}
	this->CurrentLevel->PreCheckDecreaseGoal(ItemType::Ufo);
	this->_inExplodeState = true;
	if (!this->_statIncreased) {
		this->_statIncreased = true;
		FallManager::IncreaseStatAnimation();
	}
	this->PlayRescue();
}

void UfoItem::StartSwap() {
	Cell* cellWithDirection = this->get_CurrentCell()->CurrentGrid->GetCellWithDirection(this->get_CurrentCell(), Direction::Up);
	if (cellWithDirection == nullptr || !cellWithDirection->Exists || cellWithDirection->ReservedForGeneratorItem) {
		return;
	}
	if (!cellWithDirection->get_HasItem()) {
		Grid* currentGrid = this->CurrentLevel->CurrentGrid;
		int x = this->get_CurrentCell()->X;
		int y = this->get_CurrentCell()->Y;
		for (int i = y + 1; i < currentGrid->Height; i++)
		{
			Cell* cell = currentGrid->cell(x, i);
			if (cell->Exists && cell->get_HasItem()) {
				if (cell->get_CurrentItem()->CanFall()) {
					this->_shouldMoveUp = true;
				}
				return;
			}
		}
		this->_shouldMoveUp = true;
		return;
	}
	Item* currentItem = cellWithDirection->get_CurrentItem();
	ItemType itemType = currentItem->GetItemType();
	if (!currentItem->CanFall() || itemType == ItemType::GiantDuck || itemType == ItemType::Ufo) {
		return;
	}
	if (currentItem->IsFalling) {
		this->_shouldMoveUp = true;
		return;
	}
//	this->SwapAnimation.Swap(currentItem);
	this->_isSwapping = true;
}

void UfoItem::PlaySwapAnimation() {
//	AudioManager.PlayAudioProps(this->Resources.AudioClips[0], PlayMode.Frame, null, 1f);
//	this->CurrentAnimator.Play(this->_swapAnimationHash, -1, 0f);
}

CollectAnimation UfoItem::GetCollectItem() {
//	CollectAnimation component = Object.Instantiate<GameObject>(this->Resources.Animators[0], this->get_CurrentCell()->GetFrozenPosition(), Quaternion.get_identity()).GetComponent<CollectAnimation>();
//	component.Prepare(this->CurrentLevel, this->GetItemType(), this->GetSorting(), SharedImageLibrary.Instance.UfoGoal, this->CurrentCell);
//	return component;
	return CollectAnimation::None;
}

/*IEnumerator*/void UfoItem::PlayRescue() {
//	UfoItem.<PlayRescue>c__Iterator0 <PlayRescue>c__Iterator = new UfoItem.<PlayRescue>c__Iterator0();
//	<PlayRescue>c__Iterator.$this = this;
//	return <PlayRescue>c__Iterator;
}

