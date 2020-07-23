#include "SodaFakeItem.h"
#include "SodaItem.h"
#include "../Match.h"
#include "../SpecialItem.h"
#include "../Cell.h"

int SodaFakeItem::GetScore() {
	return this->MasterItem->GetScore();
}

bool SodaFakeItem::TryExplode() {
	return this->MasterItem->ExplodeBy(this);
}

void SodaFakeItem::PlayWrongMove() {
	this->MasterItem->PlayWrongMove();
}

void SodaFakeItem::StartCollect() {
	this->MasterItem->StartCollect();
}

void SodaFakeItem::StartExplode() {
	this->MasterItem->StartExplode();
}

bool SodaFakeItem::CanExplodeDueToExplodeInNeigbour(MatchType sourceType) {
	return this->MasterItem->CanExplodeDueToExplodeInNeigbour(sourceType);
}

void SodaFakeItem::InformToBeExplodedBySpecialItem(SpecialItem* specialItem, Direction comingFrom) {
	this->MasterItem->InformToBeExplodedBySpecialItem(specialItem, comingFrom);
}