#include "ItemFeature.h"
#include "Match.h"
#include "Cell.h"
#include "Item.h"

void CanCastShadowComponent::CastShadow() {
	//this->ShadowSpriteRenderer.set_so rtingOrder(this->ShadowBehindReference.get_sor tingOrder() - 1);
	//this->ShadowSpriteRenderer.set_so rtingLayerID(this->ShadowBehindReference.get_sor tingLayerID());
	//this->ShadowSpriteRenderer.get_gameObject().SetActive(true);
}
void CanCastShadowComponent::HideShadow() {
	//this->ShadowSpriteRenderer.get_gameObject().SetActive(false);
}

void CanCastShadowComponent::HideShadowIfPossible(Cell* currentCell) {
	if(currentCell == nullptr) {
		return;
	}
	Cell* justAboveCell = currentCell->JustAboveCell;
	if(justAboveCell == nullptr || !justAboveCell->get_HasItem()) {
		return;
	}
	if(justAboveCell->get_CurrentItem()->CanCastShadow()) {
		justAboveCell->get_CurrentItem()->GetShadowCaster()->HideShadow();
	}
}

void CanCastShadowComponent::CastShadowIfPossible(Cell* cell) {
	if(cell == nullptr || !cell->get_HasItem()) {
		return;
	}
	Item* currentItem = cell->get_CurrentItem();
	Cell* justBelowCell = cell->JustBelowCell;
	if(justBelowCell == nullptr || !justBelowCell->get_HasItem()) {
		return;
	}
	if(currentItem->CanCastShadow() && justBelowCell->get_CurrentItem()->CanShadowDrop()) {
		currentItem->GetShadowCaster()->CastShadow();
	}
}
