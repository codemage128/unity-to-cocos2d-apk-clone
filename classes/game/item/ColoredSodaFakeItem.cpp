#include "ColoredSodaFakeItem.h"
#include "ColoredSodaItem.h"

int ColoredSodaFakeItem::GetScore() { return this->MasterItem->GetScore(); }

bool ColoredSodaFakeItem::TryExplode() {
	return this->MasterItem->ExplodeBy(this);
}

void ColoredSodaFakeItem::PlayWrongMove() {
	this->MasterItem->PlayWrongMove();
}

void ColoredSodaFakeItem::StartCollect() {
	this->MasterItem->StartCollect();
}

void ColoredSodaFakeItem::StartExplode() {
	this->MasterItem->StartExplode();
}

bool ColoredSodaFakeItem::CanGenerateScoreThisTurn() {
	return this->MasterItem->CanGenerateScoreThisTurn();
}

bool ColoredSodaFakeItem::CanExplodeDueToExplodeInNeigbour(MatchType sourceType) {
	return this->MasterItem->CanExplodeDueToExplodeInNeigbour(sourceType);
}

void ColoredSodaFakeItem::InformToBeExplodedBySpecialItem(SpecialItem* specialItem, Direction comingFrom) {
	this->MasterItem->InformToBeExplodedBySpecialItem(specialItem, comingFrom);
}


