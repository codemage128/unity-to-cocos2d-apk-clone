#include "UfoController.h"
#include "UfoItem.h"

UfoController* UfoController::_instance = nullptr;

void UfoController::Update()
{
//	if (SlowCheckTime.ShouldPass()) {
//		return;
//	}
	int i = 0;
	int count = this->_ufoItemList.size();
	while (i < count) {
		UfoItem* ufoItem = this->_ufoItemList[i];
		if (!(ufoItem == nullptr) && !ufoItem->TrySwap()) {
			ufoItem->TryFall();
		}
		i++;
	}
}
