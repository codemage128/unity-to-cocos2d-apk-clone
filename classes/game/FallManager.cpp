#include "FallManager.h"
#include "LevelBuilder.h"
#include "Level.h"
#include "Cell.h"
#include "Grid.h"
#include "ItemImpl.h"
#include "Animation.h"
#include "HintManager.h"

FallManager* FallManager::_instance = nullptr;
cocos2d::Vec2 FallManager::FallReference = cocos2d::Vec2(0, 1100);

FallManager::FallManager() {
	this->_fallPointY = this->FallReference.y;
	this->_fallPointY2 = this->_fallPointY - 0.2f*ITEM_SPRITE_SIZE_X; 
}

void FallManager::cleanUp() {
	for(FallAnimation* anim : _fallanimations)
		delete anim;
	_fallanimations.clear();

	if (_instance != nullptr)
		delete _instance;
	_instance = nullptr;
}

void FallManager::SceneReloadedSetups() {
	this->_currentLevel = this->CurrentLevelBuilder->CurrentLevel;
	this->_currentGrid = this->_currentLevel->CurrentGrid;

	this->_started = false;
	this->_fallBlockerCounter = 0;
	this->_fallCount = 0;
	this->_statAnimation = 0;
	this->_mechanicAnimation = 0;

	this->_validCells.clear(); this->_validCells.reserve(90);
	this->_fillingCells.clear(); this->_fillingCells.reserve(45);
	for (Cell* current : this->_currentGrid->WalkOnExistings()) {
		this->_validCells.push_back(current);
		if (current->IsFilling)
			this->_fillingCells.push_back(current);
	}
}

void FallManager::Update() {
	// original body
	if(!this->_started || this->_currentLevel == nullptr || this->_fallBlockerCounter > 0) {
		return;
	}
	for(int i = 0; i < (int)this->_validCells.size(); i++) {
		Cell* cell = this->_validCells[i];
		if(cell->get_HasItem() && cell->CanItemFallFromThisCell()) {
			Cell* firstExistingBottomCell = cell->FirstExistingBottomCell;
			if(FallManager::IsExistingCell(firstExistingBottomCell) && !firstExistingBottomCell->get_HasItem() && firstExistingBottomCell->CanItemsFallInside()) {
				this->FallItemInCell(cell, firstExistingBottomCell);
			}
		}
	}
	for(int j = 0; j < (int)this->_fillingCells.size(); j++) {
		Cell* __fillingcell = this->_fillingCells[j];
		if(!__fillingcell->get_HasItem() && __fillingcell->CanItemFallFromThisCell() && __fillingcell->CanItemsFallInside()) {
			Item* __fillingcellitem = __fillingcell->CreateRefillItem();
			cocos2d::Sprite* __fillitemsprite = LevelBuilder::getItemSprite(__fillingcellitem);
			if(__fillitemsprite != nullptr) __fillitemsprite->setLocalZOrder((int)__fillitemsprite->getUserData()+ LevelBuilder::ActiveLevel->CurrentGrid->Height);
			if(__fillingcellitem != nullptr && !__fillingcellitem->ReCycled) {
				__fillingcell->set_CurrentItem(__fillingcellitem);
				__fillingcellitem->FilledNewly = true;
				cocos2d::Vec2 frozenPosition = __fillingcell->GetFrozenPosition();
				Cell* __1stbelowcell = __fillingcell->FirstExistingBottomCell;
				bool flag = true;
				if(__1stbelowcell != nullptr && __1stbelowcell->get_HasItem() && __1stbelowcell->get_CurrentItem()->IsFalling && __1stbelowcell->get_CurrentItem()->FilledNewly) {
					FallAnimation* currentFallAnimation = __1stbelowcell->get_CurrentItem()->CurrentFallAnimation;
					if(currentFallAnimation != nullptr) {
						cocos2d::Vec2 position;//= __1stbelowcell->get_CurrentItem().get_transform().get_position();
						cocos2d::Sprite* spBelowItem = LevelBuilder::getItemSprite(__1stbelowcell->get_CurrentItem());
						if(spBelowItem != nullptr)
							position = spBelowItem->getPosition();

						if(position.y > this->_fallPointY2) {
							flag = false;
							frozenPosition.y = position.y + ITEM_SPRITE_SIZE_X;// 1.0f;
							//__fillingcellitem->get_transform().set_position(frozenPosition);
							cocos2d::Sprite* spItem = LevelBuilder::getItemSprite(__fillingcellitem);
							if(spItem != nullptr)
								spItem->setPosition(frozenPosition);
							__fillingcellitem->AppendFallAnimation(__fillingcell);
						}
					}
				}
				if(flag) {
					frozenPosition.y = this->_fallPointY;
					//__fillingcellitem.get_transform().set_position(frozenPosition);
					cocos2d::Sprite* spItem = LevelBuilder::getItemSprite(__fillingcellitem);
					if(spItem != nullptr)
						spItem->setPosition(frozenPosition);

					__fillingcellitem->AppendFallAnimation(__fillingcell);
				}
			}
		}
	}

	// new update, for all individual animations
	for(FallAnimation* anim : _fallanimations)
		anim->Update();
}

void FallManager::addFallAnimation(FallAnimation * anim) {
	_fallanimations.push_back(anim);
}

void FallManager::removeFallAnimation(FallAnimation * anim) {
	std::vector<FallAnimation*>::iterator elem = std::find(_fallanimations.begin(), _fallanimations.end(), anim);
	if (elem != _fallanimations.end())
		_fallanimations.erase(elem);
}

void FallManager::FallItemInCell(Cell* sourceCell, Cell* targetCell) {
	sourceCell->get_CurrentItem()->IsFalling = true;
	sourceCell->get_CurrentItem()->AppendFallAnimation(targetCell);
	targetCell->set_CurrentItem(sourceCell->get_CurrentItem());
	this->CurrentHintManager->StopHintAnimations();

	/*EXTRA: resorting*/
	cocos2d::Sprite* __sprite = LevelBuilder::getItemSprite(targetCell->get_CurrentItem());
	if(__sprite != nullptr)
		__sprite->setLocalZOrder((int)__sprite->getUserData() + targetCell->Y);
}

bool FallManager::IsExistingCell(Cell* theCell) {
	return theCell != nullptr && theCell->Exists;
}

bool FallManager::AreThereFallingItems() {
	return FallManager::getInstance()->_fallCount > 0;
}

bool FallManager::AreThereMechanicAnimations() {
	return FallManager::getInstance()->_mechanicAnimation > 0;
}

bool FallManager::AreThereActiveAnimations() {
	return (FallManager::getInstance()->_fallCount > 0 || FallManager::getInstance()->_mechanicAnimation > 0 || FallManager::getInstance()->_statAnimation > 0);
}

void FallManager::DecreaseMechanicAnimation() {
	FallManager::getInstance()->_mechanicAnimation--;
}

void FallManager::IncreaseMechanicAnimation() {
	FallManager::getInstance()->_mechanicAnimation++;
}

void FallManager::DecreaseStatAnimation() {
	FallManager::getInstance()->_statAnimation--;
}

void FallManager::IncreaseStatAnimation() {
	FallManager::getInstance()->_statAnimation++;
}

void FallManager::AddOneFall() {
	FallManager::getInstance()->_fallCount++;
}

void FallManager::RemoveOneFall() {
	FallManager::getInstance()->_fallCount--;
	if(FallManager::getInstance()->_fallCount < 0) {
		FallManager::getInstance()->_fallCount = 0;
	}
}

void FallManager::IncreaseWaitingFallBlocker() {
	FallManager::getInstance()->_fallBlockerCounter++;
}

void FallManager::DecreaseWaitingFallBlocker() {
	FallManager::getInstance()->_fallBlockerCounter--;
	if(FallManager::getInstance()->_fallBlockerCounter < 0) {
		FallManager::getInstance()->_fallBlockerCounter = 0;
	}
}

void FallManager::StartRunning() {
	FallManager::getInstance()->_started = true;
}