#include "GiantDuckFakeItem.h"
#include "GiantDuckItem.h"

GiantDuckFakeItem::GiantDuckFakeItem() {

}

GiantDuckFakeItem::~GiantDuckFakeItem() {
}

void GiantDuckFakeItem::PlayWrongMove() {
	this->MasterDuck->PlayWrongMove();
}
