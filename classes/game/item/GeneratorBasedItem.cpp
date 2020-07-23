#include "GeneratorBasedItem.h"
#include "../Cell.h"
#include "../Level.h"
#include "../FallManager.h"
#include "../Mathf.h"
#include "../ItemGeneratorController.h"

void GeneratorBasedItem::StartGeneratingItems() {
	this->GenerateItems();
}

/*IEnumerator*/void GeneratorBasedItem::GenerateItems() {
	bool shouldPlayThrowAnimation = false;
//case 0:
	if(!this->_waiting) {
		this->_waiting = true;
		FallManager::IncreaseWaitingFallBlocker();
		shouldPlayThrowAnimation = false;
//		this->$current = null;
//		if(!this->$disposing) {
//			this->$PC = 1;
//		}
//		goto nextframe;
	}
	else
		return;
//	goto end;
//
//case 1:
	int availableCountOnBoard = this->CurrentLevel->CanGenerateCount(this->GenerateItemType);
	int availableCount = Mathf::Min(availableCountOnBoard, this->GenerateCount);
	if(availableCount > 0) {
		if(availableCountOnBoard <= 1) {
			ItemGeneratorController::getInstance()->SleepGenerators(this->GenerateItemType);
		}
		this->IntervalCounter++;
		if((this->IntervalCounter % this->GenerateInverval) == 0) {
			this->IntervalCounter = 0;
			this->_targetCellList.clear();
			for(int i = 0; i < availableCount; i++) {
				Cell* randomCell = this->GetRandomCell();
				if(randomCell == nullptr) {
					break;
				}
				this->_targetCellList.push_back(randomCell);
				this->CurrentLevel->IncreaseItemCount(this->GenerateItemType);
				randomCell->ReserveForItem(this->GenerateItemType);
				shouldPlayThrowAnimation = true;
			}
		}
//		break;
// [breakTo]

		if(shouldPlayThrowAnimation && (this->_targetCellList.size() > 0)) {
			this->PlayThrowAnimation(&this->_targetCellList);
		}
		this->_waiting = false;
		FallManager::DecreaseWaitingFallBlocker();
		//this->$current = null;
		//if(!this->$disposing) {
		//	this->$PC = 2;
		//}
		//goto nextframe;
	}
	else
		FallManager::DecreaseWaitingFallBlocker();
//	goto end;
//
//case 2:
//	this->$PC = -1;
//	goto end;
//
//default:
//	goto end;
//}
//end:
//return false;
//nextframe:
//return true;
}

void GeneratorBasedItem::OnThrowAnimationComplete(Cell* targetCell) {
	if (targetCell != nullptr) {
		targetCell->ApplyReservedItem();
	}
	this->CurrentLevel->DecreaseItemCount(this->GenerateItemType);
}
