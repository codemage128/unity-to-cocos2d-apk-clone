#include "GiantPinataFakeItem.h"
#include "GiantPinataItem.h"
#include "../Cell.h"


int GiantPinataFakeItem::GetScore() {
	return this->MasterPinataItem->GetScore();
}

void GiantPinataFakeItem::PlayWrongMove() {
	this->MasterPinataItem->PlayWrongMove();
}

void GiantPinataFakeItem::StartCollect() {
	this->MasterPinataItem->StartCollect();
}

void GiantPinataFakeItem::InformToBeExplodedBySpecialItem(SpecialItem* specialItem, Direction comingFrom) {
	if (comingFrom == Direction::None && this->get_CurrentCell() != nullptr) {
		comingFrom = this->get_CurrentCell()->GetDirectionTo(this->MasterPinataItem->get_CurrentCell());
	}
	this->MasterPinataItem->InformToBeExplodedBySpecialItem(specialItem, comingFrom);
}

bool GiantPinataFakeItem::TryExplode() {
	return this->MasterPinataItem->TryExplode();
}

void GiantPinataFakeItem::StartExplode() {
	this->MasterPinataItem->StartExplode();
}


bool GiantPinataFakeItem::CanShadowDrop() {
	return this->PositionRelativeToMaster == Direction::Up || this->PositionRelativeToMaster == Direction::RightUp;
}