#include "JellyManager.h"
#include "Level.h"
#include "Item.h"
#include "item/ItemImpl2.h"
#include "Cell.h"
#include "Mathf.h"

JellyManager::JellyManager(Level* level) {
	this->_level = level;
	this->_candidateCells.reserve(16);
	this->_candidateCellsSecondary.reserve(16);
}

void JellyManager::Spread() {
	if (this->_disabled || this->_specialItemsInAction > 0 || this->_level->get_MovesLeft() == this->_jellyExplodedAtMovesLeft) {
		return;
	}
	this->SpreadWithoutControl();
}

void JellyManager::Add(JellyItem* jellyItem) {
	this->_items.push_back(jellyItem);
	this->_level->IncreaseGoal(ItemType::Jelly);
}

void JellyManager::Remove(JellyItem* jellyItem) {
	this->_items.erase(std::find(this->_items.begin(), this->_items.end(), jellyItem));
}

void JellyManager::InformJellyExplode() {
	if (this->_specialItemsInAction == 0) {
		this->_jellyExplodedAtMovesLeft = this->_level->get_MovesLeft();
	}
}

void JellyManager::SpecialItemEnded(bool jellyExploded) {
	this->_specialItemsInAction--;
	if (!this->_jellyExplodedInSpecialItemChain && jellyExploded) {
		this->_jellyExplodedInSpecialItemChain = true;
	}
	if (this->_specialItemsInAction > 0) {
		return;
	}
	if (!this->_jellyExplodedInSpecialItemChain && !this->_disabled) {
		this->SpreadWithoutControl();
		this->_jellyExplodedAtMovesLeft = this->_level->get_MovesLeft();
	}
	this->_specialItemsInAction = 0;
	this->_jellyExplodedInSpecialItemChain = false;
}

void JellyManager::SpreadWithoutControl()
{
	int count = this->_items.size();
	if (count <= 0) {
		return;
	}
	this->_candidateCells.clear();
	this->_candidateCellsSecondary.clear();
	for (int i = 0; i < count; i++) {
		JellyItem* jellyItem = this->_items[i];
		Cell* currentCell = jellyItem->get_CurrentCell();
		if (!(currentCell == nullptr)) {
			for (int j = 0; j < (int)currentCell->GetCachedNeigbours(false).size(); j++) {
				Cell* cell = currentCell->GetCachedNeigbours(false)[j];
				if (!cell->get_HasItem()) {
					this->_candidateCells.push_back(new CellPairs(currentCell, cell));
				}
				else if (cell->get_CurrentItem()->CanBeCapturedByJelly()) {
					if (cell->get_CurrentItem()->IsSpecialItem()) {
						this->_candidateCellsSecondary.push_back(new CellPairs(currentCell, cell));
					}
					else {
						this->_candidateCells.push_back(new CellPairs(currentCell, cell));
					}
				}
			}
		}
	}
	CellPairs* cellPairs = nullptr;
	if (this->_candidateCells.size() > 0) {
		cellPairs = this->_candidateCells[Mathf::Random::Range(0, this->_candidateCells.size())];
	}
	else if (this->_candidateCellsSecondary.size() > 0) {
		cellPairs = this->_candidateCellsSecondary[Mathf::Random::Range(0, this->_candidateCellsSecondary.size())];
	}
	if (cellPairs == nullptr) {
		return;
	}
	JellyItem* jellyItem2 = dynamic_cast<JellyItem*>(cellPairs->FromCell->get_CurrentItem());
	if (jellyItem2 != nullptr) {
		jellyItem2->PlayJellySpread(cellPairs->ToCell);
	}
}
