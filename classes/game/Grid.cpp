#include "Grid.h"
#include "Match.h"
#include "Cell.h"
#include "Level.h"
#include "LevelBuilder.h"
#include "Item.h"
#include "ItemFeature.h"
#include "SpecialItem.h"
#include "Mathf.h"
#include "Extension.h"
#include "Score.h"
#include "HintManager.h"
#include "JellyManager.h"
#include "ItemImpl.h"

Grid::Grid(std::vector<std::vector<Cell*>>& cellGrid) {
	this->Width = (int)cellGrid.size();
	this->Height = (int)cellGrid[0].size();
	this->LongestSideLength = Mathf::Max(this->Width, this->Height);
	this->_cellGrid = cellGrid;
	this->_matchFinder = new MatchFinder(this);
	for(int i = 0; i < this->Width; i++) {
		for(int j = 0; j < this->Height; j++) {
			Cell* cell = this->_cellGrid[i][j];
			if(cell->Exists) {
				this->_existingCells.push_back(cell);
			}
		}
	}
}

void Grid::DisableHighlights() {
	for(Cell* current : this->WalkOnExistings()) {
		if(current->get_HasItem()) {
			if(current->get_CurrentItem()->CanShowCurrentlyUnderTap()) {
				((ICanShowCurrentlyUnderTap*)current->get_CurrentItem())->HideCurrentlyUnderTap();
			}
		}
	}
}

MatchGroup* Grid::GetMatch(Cell* cell) {
	if(cell == nullptr || !cell->get_HasItem()) {
		return nullptr;
	}
	return (!cell->get_CurrentItem()->IsSpecialItem()) ? this->_matchFinder->GetSingleMatch(cell) : this->_matchFinder->GetComboMatch(cell);
}

void Grid::PopulateAllMatchesIntoList(std::vector<MatchGroup*>& container) {
	this->_matchFinder->PopulateAllMatches(container);
}

Cell* Grid::GetCellWithDirection(Cell* source, Direction direction) {
	if(source == nullptr)
		return nullptr;
	
	int x = source->X;
	int y = source->Y;
	if(direction == Direction::Left && x - 1 >= 0)										return this->cell(x - 1, y);	
	if(direction == Direction::LeftUp && x - 1 >= 0 && y + 1 < this->Height)			return this->cell(x - 1, y + 1);	
	if(direction == Direction::Up && y + 1 < this->Height)								return this->cell(x, y + 1);	
	if(direction == Direction::RightUp && x + 1 < this->Width && y + 1 < this->Height)	return this->cell(x + 1, y + 1);	
	if(direction == Direction::Right && x + 1 < this->Width)							return this->cell(x + 1, y);	
	if(direction == Direction::RightDown && x + 1 < this->Width && y - 1 >= 0)			return this->cell(x + 1, y - 1);	
	if(direction == Direction::Down && y - 1 >= 0)										return this->cell(x, y - 1);	
	if(direction == Direction::LeftDown && x - 1 >= 0 && y - 1 >= 0)					return this->cell(x - 1, y - 1);
	
	return nullptr;
}

void Grid::UserPerfomedTouchOnCell(Cell* theCell) {
	if(theCell == nullptr || !theCell->get_HasItem())
		return;
	
	Item* currentItem = theCell->get_CurrentItem();
	if(currentItem->LatestExplode == Ext_getCurrentFrame() || !currentItem->CanBeTapped()) {
		currentItem->PlayWrongMove();
		return;
	}
	MatchGroup* match = this->GetMatch(theCell);
	if(match == nullptr) {
		currentItem->PlayWrongMove();
		return;
	}
	HintManager::getInstance()->StopHintAnimations();
	if(currentItem->IsSpecialItem()) {
		this->CurrentLevel->IncreaseMoveCount();
		if(((SpecialItem*)currentItem)->CanRaiseScore()) {
			ScoreManager::RaiseScore(match->Score, theCell->GetFrozenPosition(), MatchType::None);
		}
		if(match->CanGenerateCombo) {
			SpecialItem* specialItem = this->CurrentLevel->CurrentLevelBuilder->CreateComboItem(match, theCell->GetFrozenPosition());
			//AudioManager.Play(AudioTag.ComboMerge, PlayMode.Frame, null, 1f);
			if(specialItem == nullptr) {
				//Debug.Log("Combo item is null");
				CCASSERT(false, "COMBO ITEM CREATION ERROR");
			}
			//Tweener* blockerTween = nullptr;
			int i = 0;
			int count = match->AllCells.size();
			while(i < count) {
				Cell* cell = match->AllCells[i];
				Item* currentItem2 = cell->get_CurrentItem();
				if(cell->get_HasItem())
					dynamic_cast<IComboItem*>(specialItem)->AddScore(cell->get_CurrentItem()->GetScore());
				cell->RemoveBubble();
				specialItem->DisplayComboHint(false);
				cell->set_CurrentItem(nullptr);
				cell->RejectsFallInside();
				/*blockerTween = */dynamic_cast<SpecialItem*>(currentItem2)->MoveToComboItem(match->ClickedCell);
				i++;
			}
			theCell->set_CurrentItem(specialItem);
			//new Task(specialItem.StartAutoExplode(blockerTween));
			specialItem->StartAutoExplode(0.3f);
		}
		else {
			this->ExplodeCell(theCell, nullptr);
		}
		this->CurrentLevel->JellyItemManager->Spread();
		this->CurrentLevel->ExplodeEnded();
	}
	else if(match->CanMatchExplode) {
		this->CurrentLevel->IncreaseMoveCount();
		for(Cell* current : match->AllCells)
			this->ExplodeCell(current, match);
		
		ScoreManager::RaiseScore(match->Score, theCell->GetFrozenPosition(), match->matchType);
		this->CurrentLevel->JellyItemManager->Spread();
		this->CurrentLevel->ExplodeEnded();
	}
	else {
		currentItem->PlayWrongMove();
	}
}

void Grid::AdminClickTool(Item* item, Cell* cell) {
	item->ToBeExplodedBy = ExplodeReason::Hammer;
	item->InformToBeExplodedBySpecialItem(nullptr, Direction::None);
	this->ExplodeCell(cell, nullptr);
}

bool Grid::ExplodeCell(Cell* currentCell, MatchGroup* mgroup/* = nullptr*/) {
	if(currentCell == nullptr) {
		return false;
	}
	if(!currentCell->get_HasItem()) {
		currentCell->ShakeBubble();
		return false;
	}
	Item* currentItem = currentCell->get_CurrentItem();
	cocos2d::Sprite* currentSpItem = LevelBuilder::getItemSprite(currentItem);

	MatchType matchType = currentItem->GetMatchType();
	if(!currentItem->TryExplode()) {
		currentCell->ShakeBubble();
		return false;
	}
	Item* item = currentItem->ExtractSubItem();
	if(item != nullptr) {
		//item.get_transform().SetParent(currentItem.get_transform().get_parent());
		cocos2d::Sprite* subitemsp = LevelBuilder::getItemSprite(item);
		cocos2d::Sprite* parentitemsp = LevelBuilder::getItemSprite(currentItem);
		if(subitemsp != nullptr && parentitemsp!=nullptr) {
			subitemsp->removeFromParent();
			parentitemsp->getParent()->addChild(subitemsp);
			subitemsp->setLocalZOrder(parentitemsp->getLocalZOrder());
			subitemsp->setPosition(parentitemsp->getPosition());
		}
	}
	CanCastShadowComponent::HideShadowIfPossible(currentCell);
	this->CurrentLevel->TotalExplodedItemCount++;
	if(currentCell->HasBubble && (dynamic_cast<SolidColorItem*>(currentItem) != nullptr || currentItem->IsSpecialItem())) {
		currentCell->RemoveBubble();
	}
	else {
		currentCell->ShakeBubble();
	}
	bool flag = Ext_getCurrentFrame() == currentCell->LastBubbleRemoved;
	if(mgroup == nullptr && currentItem->CanRaiseScore()) {
		int num = currentItem->GetScore();
		if(flag) {
			num += 500;
		}
		//ScoreManager::RaiseScore(num, currentItem.get_transform().get_position(), currentItem->GetMatchType());
		if(currentSpItem!=nullptr)
			ScoreManager::RaiseScore(num, currentSpItem->getPosition(), currentItem->GetMatchType());
	}
	if(mgroup != nullptr && mgroup->CanGenerateSpecialItem) {
		this->CurrentLevel->DecreaseGoal(currentItem->GetItemType(), false);
		dynamic_cast<SolidColorItem*>(currentItem)->MoveToSpecialItem(mgroup->ClickedCell);
	}
	else if(this->CurrentLevel->CanBeCollected(currentItem->GetItemType())) {
		currentItem->StartCollect();
	}
	else {
		currentItem->StartExplode();
	}
	currentCell->set_CurrentItem(nullptr);
	if(mgroup == nullptr) {
		Grid::CreateSubItem(item, currentCell);
		return true;
	}
	if(flag) {
		mgroup->Score += 500;
	}
	if(mgroup->CanGenerateSpecialItem && mgroup->ClickedCell == currentCell) {
		SpecialItem* specialItem = this->CurrentLevel->CurrentLevelBuilder->CreateSpecialItem(mgroup->SpecialItemType, mgroup->matchType, currentCell->GetFrozenPosition(), currentCell);
		currentCell->set_CurrentItem(specialItem);
		CanCastShadowComponent::CastShadowIfPossible(currentCell);
		specialItem->PlaySpecialItemCreationAnimation();
		//AudioManager.Play(AudioTag.ItemSpecialCreate, PlayMode.Frame, null, 1f);
	}
	std::vector<Cell*> cachedNeigbours = currentCell->GetCachedNeigbours(false);
	int i = 0;
	int num2 = cachedNeigbours.size();
	while(i < num2) {
		Cell* cell = cachedNeigbours[i];
		if(cell->get_HasItem() && cell->get_CurrentItem()->CanExplodeDueToExplodeInNeigbour(matchType) && cell->get_CurrentItem()->MasterItemExplode != Ext_getCurrentFrame()) {
			if(std::find(mgroup->AllCells.begin(), mgroup->AllCells.end(), cell) == mgroup->AllCells.end()) {
				Item* currentItem2 = cell->get_CurrentItem();
				currentItem2->PreventRaiseScore();
				this->ExplodeCell(cell, nullptr);
				if(currentItem2->get_CurrentCell() == nullptr || (currentItem2->CanGenerateScoreOnEachTryExplode() && currentItem2->CanGenerateScoreThisTurn())) {
					mgroup->Score += currentItem2->GetScore();
				}
				currentItem2->AllowRaiseScore();
			}
		}
		i++;
	}
	Grid::CreateSubItem(item, currentCell);
	return true;
}

void Grid::CreateSubItem(Item* subItem, Cell* currentCell) {
	if(subItem == nullptr) {
		return;
	}
	subItem->set_CurrentCell(currentCell);
}

std::vector<Cell*>/*IEnumerable*/ Grid::WalkOnAll() {
	std::vector<Cell*> ret;
	for(int x = 0; x < this->Width; x++)
		for(int y = 0; y < this->Height; y++)
			ret.push_back(this->cell(x, y));
	return ret;
}
std::vector<Cell*>/*IEnumerable*/ Grid::WalkOnExistings() {
	std::vector<Cell*> ret;
	for(std::list<Cell*>::iterator iter = this->_existingCells.begin(); iter != this->_existingCells.end(); iter++)
		ret.push_back(*iter);
	return ret;
}