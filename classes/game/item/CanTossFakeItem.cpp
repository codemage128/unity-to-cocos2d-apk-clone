#include "CanTossFakeItem.h"
#include "CanTossItem.h"
#include "../Animation.h"
#include "global/SoundManager.h"


CanTossFakeItem::CanTossFakeItem() {
}

CanTossFakeItem::~CanTossFakeItem() {
}


void CanTossFakeItem::PlayWrongMove() {
	this->MasterCanToss->PlayWrongMove(); 
}

void CanTossFakeItem::StartCollect() {
	this->MasterCanToss->StartCollect();
}

bool CanTossFakeItem::TryExplode() {
	return this->MasterCanToss->ExplodeBy(this);
}

void CanTossFakeItem::StartExplode() {
	this->MasterCanToss->StartExplode();
}

/// non override
void CanTossFakeItem::CheckIfExtraExplodeNeeded() {
	this->MasterCanToss->CheckIfExtraExplodeNeeded();
}

void CanTossFakeItem::MarkShouldExplodeAtLeast2() {
	this->MasterCanToss->MarkShouldExplodeAtLeast2();
}