#include "BubbleController.h"
#include "Grid.h"
#include "Cell.h"
#include "Item.h"
#include "Extension.h"
#include "item/FishItem.h"

#include "cocos2d.h"

BubbleController* BubbleController::_instance = nullptr;

Cell* BubbleController::GetRandomCell() {
	if(Ext_getCurrentFrame() != this->_latestFrame) {
		this->_latestFrame = Ext_getCurrentFrame();
		this->_availableCellList.clear();
		for(Cell* cell : this->_grid->WalkOnExistings()) {
			if(!cell->HasBubble && !cell->ReservedForBubble) {
				if(cell->get_HasItem()) {
					switch(cell->get_CurrentItem()->GetItemType()) {
					case ItemType::CanToss:
					case ItemType::GiantPinata:
					case ItemType::GiantDuck:
					case ItemType::Soda:
					case ItemType::ColoredSoda:
					case ItemType::MagicHat:
					case ItemType::Billboard:
					case ItemType::Fish:
					case ItemType::Frame:
					case ItemType::BalloonGenerator:
					{
						continue;
					}
					}
				}
				this->_availableCellList.push_back(cell);
			}
		}
		ListExt_Shuffle<Cell*>(this->_availableCellList);
	}
	int index = (int)this->_availableCellList.size() - 1;
	if(index < 0) {
		return nullptr;
	}
	Cell* cell2 = this->_availableCellList[index];
	this->_availableCellList.erase(this->_availableCellList.begin() + index);
	return cell2;
}

void BubbleController::TrySleepGenerators() {
	for(FishItem* item : this->_bubbleGenerators) {
		if(item != nullptr) {
			item->Sleep();
		}
	}
}