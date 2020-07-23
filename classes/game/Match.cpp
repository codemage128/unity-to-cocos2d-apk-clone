#include "Match.h"
#include "Cell.h"
#include "Item.h"
#include "SpecialItem.h"
#include "Cell.h"
#include "Grid.h"

///////MatchGroup//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::stack<MatchGroup*> MatchGroup::PooledItems;

MatchGroup* MatchGroup::Get(Cell* cell) {
	MatchGroup* matchGroup = nullptr;
	if(MatchGroup::PooledItems.size() <= 0)
		matchGroup = new MatchGroup();
	else {
		matchGroup = MatchGroup::PooledItems.top();
		MatchGroup::PooledItems.pop();
	}
	matchGroup->Init(cell);
	return matchGroup;
}

void MatchGroup::Put(MatchGroup* usedItem) {
	if(MatchGroup::PooledItems.size() > Capacity) {
		return;
	}
	usedItem->Clear();
	MatchGroup::PooledItems.push(usedItem);
}

void MatchGroup::Clear() {
	this->AllCells.clear();
	this->CanGenerateCombo = false;
	this->CanGenerateSpecialItem = false;
	this->CanMatchExplode = false;
	this->ClickedCell = nullptr;
	this->ComboType = ItemType::None;
	this->matchType = MatchType::None;
	this->Score = 0;
	this->Size = 0;
	this->SpecialItemType = ItemType::None;
	this->AtLeastOneFalling = false;
}

void MatchGroup::Summarize() {
	short num = 0;
	short num2 = 0;
	short num3 = 0;
	int i = 0;
	int count = (int)this->AllCells.size();
	while(i < count) {
		Cell* cell = this->AllCells[i];
		if(cell->get_HasItem()) {
			Item* currentItem = cell->get_CurrentItem();
			if(!this->AtLeastOneFalling && (currentItem->IsFalling || currentItem->FilledNewly)) {
				this->AtLeastOneFalling = true;
			}
			this->Score += currentItem->GetScore();
			ItemType itemType = currentItem->GetItemType();
			if(itemType != ItemType::Rocket) {
				if(itemType != ItemType::Bomb) {
					if(itemType == ItemType::DiscoBall) {
						num3 += 1;
					}
				}
				else {
					num2 += 1;
				}
			}
			else {
				num += 1;
			}
		}
		i++;
	}
	this->Size = this->AllCells.size();
	this->CanGenerateSpecialItem = (this->AllCells.size() >= 5);
	this->CanMatchExplode = (this->AllCells.size() >= 2);
	if(this->Size > 3 && this->Size < 7) {
		this->SpecialItemType = ItemType::Rocket;
	}
	if(this->Size >= 7 && this->Size < 9) {
		this->SpecialItemType = ItemType::Bomb;
	}
	if(this->Size >= 9) {
		this->SpecialItemType = ItemType::DiscoBall;
	}
	this->CanGenerateCombo = (num + num2 + num3 > 1);
	if(num3 > 1) {
		this->ComboType = ItemType::DoubleDiscoBall;
	}
	else if(num3 == 1) {
		if(num2 > 0) {
			this->ComboType = ItemType::DiscoBallAndBomb;
		}
		else if(num > 0) {
			this->ComboType = ItemType::DiscoBallAndRocket;
		}
	}
	else if(num2 > 1) {
		this->ComboType = ItemType::DoubleBomb;
	}
	else if(num2 == 1 && num > 0) {
		this->ComboType = ItemType::RocketAndBomb;
	}
	else if(num > 1) {
		this->ComboType = ItemType::DoubleRocket;
	}
}

DiscoBallItem* MatchGroup::GetFirstDiscoBall() {
	int i = 0;
	int count = this->AllCells.size();
	while(i < count) {
		Cell* cell = this->AllCells[i];
		if(cell->get_HasItem() && cell->get_CurrentItem()->GetItemType() == ItemType::DiscoBall) {
			return (DiscoBallItem*)cell->get_CurrentItem();
		}
		i++;
	}
	return nullptr;
}

std::string MatchGroup::ToString() {
	char retstr[128];
	sprintf(retstr, "[MatchGroup: ClickedCell=%s, Size=%d, MatchType=%d, CanExplode=%d]",
			this->ClickedCell->ToString().c_str(),
			this->Size,
			(int)this->matchType,
			(int)this->CanMatchExplode);
	return retstr;
}

void MatchGroup::Init(Cell* cell) {
	this->Clear();
	this->ClickedCell = cell;
	if(this->ClickedCell->get_HasItem()) {
		this->matchType = this->ClickedCell->get_CurrentItem()->GetMatchType();
	}
}

///////MatchFinder//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MatchFinder::MatchFinder(Grid* grid) {
	this->_grid = grid;
	for(int i = 0; i < grid->Width; i++) {
		for(int j = 0; j < grid->Height; j++) {
			Cell* cell = this->_grid->cell(i, j);
			if(cell->Exists) {
				this->_existingCells.push_back(cell);
			}
		}
	}
	this->_width = this->_grid->Width;
	this->_height = this->_grid->Height;
	this->_visited.resize(this->_grid->Width);
	for(int i = 0; i<this->_grid->Width; i++)
		this->_visited[i].resize(this->_grid->Height);
	_visitedForSingleMatch.resize(9);
	for(int i = 0; i < 9; i++)
		_visitedForSingleMatch[i].resize(9);
}

MatchGroup* MatchFinder::GetSingleMatch(Cell* cell) {
	MatchGroup* matchGroup = MatchGroup::Get(cell);
	MatchGroup* result = nullptr;
		if(!cell->Exists || !cell->get_HasItem() || !cell->get_CurrentItem()->CanBeMatchable() || cell->get_CurrentItem()->IsFalling) {
			result = matchGroup;
		}
		else {
			for(int i = 0; i < this->_grid->Width; i++) {
				for(int j = 0; j < this->_grid->Height; j++) {
					this->_visitedForSingleMatch[i][j] = false;
				}
			}
			matchGroup->AllCells.push_back(cell);
			this->_visitedForSingleMatch[cell->X][cell->Y] = true;
			std::vector<Cell*> neigb = cell->GetCachedNeigbours(false);
			MatchFinder::FindSingleMatch(&this->_visitedForSingleMatch, cell->get_CurrentItem()->GetMatchType(), &neigb, &matchGroup->AllCells);
			result = matchGroup;
		}
	matchGroup->Summarize();
	return result;
}

void MatchFinder::FindSingleMatch(std::vector<std::vector<bool>>* visited, MatchType matchType, std::vector<Cell*>* roots, std::vector<Cell*>* allCells) {
	if(roots == nullptr) {
		return;
	}
	int i = 0;
	int num = roots->size();
	while(i < num) {
		Cell* cell = (*roots)[i];
		if(!(*visited)[cell->X][cell->Y]) {
			(*visited)[cell->X][cell->Y] = true;
			if(cell->Exists && cell->get_HasItem()) {
				Item* currentItem = cell->get_CurrentItem();
				if(currentItem->CanBeMatchable() && currentItem->GetMatchType() == matchType && !currentItem->IsFalling) {
					allCells->push_back(cell);
					std::vector<Cell*> neigb = cell->GetCachedNeigbours(false);
					MatchFinder::FindSingleMatch(visited, matchType, &neigb, allCells);
				}
			}
		}
		i++;
	}
}

MatchGroup* MatchFinder::GetComboMatch(Cell* cell) {
	MatchGroup* matchGroup = MatchGroup::Get(cell);
	MatchGroup* result;
	if(!cell->Exists || !cell->get_HasItem() || !cell->get_CurrentItem()->IsSpecialItem()) {
		result = matchGroup;
	}
	else {
		std::vector<std::vector<bool>> arr; arr.resize(_grid->Width);
		for(std::vector<bool>& _sb : arr) _sb.resize(_grid->Height);
		matchGroup->AllCells.push_back(cell);
		arr[cell->X][cell->Y] = true;
		std::vector<Cell*> neigb = cell->GetCachedNeigbours(false);
		MatchFinder::FindComboMatch(&arr, &neigb, &matchGroup->AllCells);
		result = matchGroup;
	}

	matchGroup->Summarize();
	return result;
}

void MatchFinder::FindComboMatch(std::vector<std::vector<bool>>* visited, std::vector<Cell*>* roots, std::vector<Cell*>* allCells) {
	if(roots == nullptr) {
		return;
	}
	int i = 0;
	int num = roots->size();
	while(i < num) {
		Cell* cell = (*roots)[i];
		if(!(* visited)[cell->X][cell->Y]) {
			(*visited)[cell->X][cell->Y] = true;
			if(cell->Exists && cell->get_HasItem() && cell->get_CurrentItem()->IsSpecialItem()) {
				allCells->push_back(cell);
				std::vector<Cell*> neigb = cell->GetCachedNeigbours(false);
				MatchFinder::FindComboMatch(visited, &neigb, allCells);
			}
		}
		i++;
	}
}

void MatchFinder::PopulateAllMatches(std::vector<MatchGroup*>& container) {
	std::list<Cell*>::iterator iter = this->_existingCells.begin();
	for(int i = 0; i < this->_width; i++) {
		for(int j = 0; j < this->_height; j++) {
			this->_visited[i][j] = false;
		}
	}
	while(iter != this->_existingCells.end()) {
		Cell* value = *iter;
		if(!this->_visited[value->X][value->Y]) {
			container.push_back(this->GetMatch(value));
		}
		iter++;
	}
}

MatchGroup* MatchFinder::GetMatch(Cell* cell) {
	this->_visited[cell->X][cell->Y] = true;
	MatchGroup* matchGroup = MatchGroup::Get(cell);
	MatchGroup* result;
	matchGroup->AllCells.push_back(cell);
	if(!cell->Exists || !cell->get_HasItem() || (!cell->get_CurrentItem()->CanBeMatchable() && (!cell->get_CurrentItem()->IsSpecialItem() || ((SpecialItem*)cell->get_CurrentItem())->CanNotJoinToCombo))) {
		result = matchGroup;
	}
	else {
		std::vector<Cell*> neigb = cell->GetCachedNeigbours(false);
		this->FindMatch(cell->get_CurrentItem()->GetMatchType(), &neigb, &matchGroup->AllCells);
		result = matchGroup;
	}
	matchGroup->Summarize();
	return result;
}

void MatchFinder::FindMatch(MatchType matchType, std::vector<Cell*>* roots, std::vector<Cell*>* allCells) {
	if(roots == nullptr) {
		return;
	}
	int i = 0;
	int num = (*roots).size();
	while(i < num) {
		Cell* cell = (*roots)[i];
		if(!this->_visited[cell->X][cell->Y]) {
			if(!cell->Exists || !cell->get_HasItem() || (!cell->get_CurrentItem()->CanBeMatchable() && (!cell->get_CurrentItem()->IsSpecialItem() || ((SpecialItem*)cell->get_CurrentItem())->CanNotJoinToCombo))) {
				this->_visited[cell->X][cell->Y] = true;
			}
			else if(cell->get_CurrentItem()->GetMatchType() == matchType) {
				this->_visited[cell->X][cell->Y] = true;
				allCells->push_back(cell);
				std::vector<Cell*> neigb = cell->GetCachedNeigbours(false);
				this->FindMatch(matchType, &neigb, allCells);
			}
		}
		i++;
	}
}