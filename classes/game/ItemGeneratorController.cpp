#include "ItemGeneratorController.h"
#include "Cell.h"
#include "Grid.h"
#include "Item.h"
#include "Extension.h"
#include "item/GeneratorBasedItem.h"

#include "cocos2d.h"

ItemGeneratorController* ItemGeneratorController::_instance = nullptr;

Cell* ItemGeneratorController::GetRandomCell() {
	if((int)cocos2d::Director::getInstance()->getTotalFrames() > (this->_latestFrame + 10)) {
		this->_latestFrame = cocos2d::Director::getInstance()->getTotalFrames();
		this->_availableCellList.clear();
		this->_emptyCellList.clear();
		this->_fillingCellList.clear();
		for(Cell* cell : this->_grid->WalkOnExistings()) {
			if(!cell->ReservedForGeneratorItem) {
				if(!cell->get_HasItem()) {
					this->_emptyCellList.push_back(cell);
					continue;
				}
				if(cell->get_CurrentItem()->ToBeExplodedBy != ExplodeReason::Disco) {
					switch(cell->get_CurrentItem()->GetItemType()) {
					case ItemType::SolidColor1:
					case ItemType::SolidColor2:
					case ItemType::SolidColor3:
					case ItemType::SolidColor4:
					case ItemType::SolidColor5:{
						if((!cell->get_CurrentItem()->IsFalling && !cell->IsFilling) && !cell->get_CurrentItem()->FilledNewly) {
							this->_availableCellList.push_back(cell);
							continue;
						}
						this->_fillingCellList.push_back(cell);
						break;
					}
					}
				}
			}
		}
		ListExt_Shuffle<Cell*>(this->_availableCellList);
		ListExt_Shuffle<Cell*>(this->_emptyCellList);
		ListExt_Shuffle<Cell*>(this->_fillingCellList);
	}
	int index = (int)this->_availableCellList.size() - 1;
	if(index < 0) {
		int num2 = (int)this->_fillingCellList.size() - 1;
		if(num2 < 0) {
			int num3 = (int)this->_emptyCellList.size() - 1;
			if(num3 < 0) {
				return nullptr;
			}
			Cell* cell2 = this->_emptyCellList[num3];
			this->_emptyCellList.erase(this->_emptyCellList.begin() + num3);
			return cell2;
		}
		Cell* cell3 = this->_fillingCellList[num2];
		this->_fillingCellList.erase(this->_fillingCellList.begin() + num2);
		return cell3;
	}
	Cell* cell4 = this->_availableCellList[index];
	this->_availableCellList.erase(this->_availableCellList.begin() + index);
	return cell4;
}

void ItemGeneratorController::RegisterGenerator(ItemType itemType, GeneratorBasedItem* item) {
	if(this->_generators.find(itemType) == this->_generators.end()) {
		std::set<GeneratorBasedItem*> newset;
		this->_generators.insert({itemType, newset});
	}
	this->_generators[itemType].insert(item);
}

void ItemGeneratorController::SleepGenerators(ItemType itemType) {
	if(this->_generators.find(itemType) != this->_generators.end()) {
		for(GeneratorBasedItem* item : this->_generators[itemType]) {
			item->Sleep();
		}
		this->_generators.erase(itemType);
	}
}