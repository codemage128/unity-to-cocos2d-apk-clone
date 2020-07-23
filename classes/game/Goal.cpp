#include "Goal.h"
#include "Item.h"
#include <cctype>

Goal::Goal(std::string goalName, int count) {
	this->Order = 100;
	this->Count = count;
	this->TotalCount = count;
	this->InstantCount = count;
	this->Type = ItemType::None;
	for(int i = 0; i < (int)goalName.length(); i++)
		goalName[i] = std::tolower(goalName[i]);
	//goalName = std::tolower( _strlwr((char*)goalName.c_str());
	if(goalName == "yellowcubegoal") {
		this->Type = ItemType::SolidColor1;
	}
	if(goalName == "redcubegoal") {
		this->Type = ItemType::SolidColor2;
	}
	if(goalName == "bluecubegoal") {
		this->Type = ItemType::SolidColor3;
	}
	if(goalName == "greencubegoal") {
		this->Type = ItemType::SolidColor4;
	}
	if(goalName == "purplecubegoal") {
		this->Type = ItemType::SolidColor5;
	}
	if(goalName == "orangecubegoal") {
		this->Type = ItemType::SolidColor6;
	}
	if(goalName == "bubblegoal") {
		this->Type = ItemType::Bubble;
		this->Order = 10;
	}
	if(goalName == "crategoal") {
		this->Type = ItemType::Crate;
		this->Order = 56;
	}
	if(goalName == "framegoal") {
		this->Type = ItemType::Frame;
		this->Order = 56;
	}
	if(goalName == "coloredcrategoal" || goalName == "colorcrategoal") {
		this->Type = ItemType::ColoredCrate;
		this->Order = 55;
	}
	if(goalName == "balloongoal") {
		this->Type = ItemType::Balloon;
		this->Order = 50;
	}
	if(goalName == "pumpkingoal" || goalName == "watermelongoal") {
		this->Type = ItemType::WaterMelon;
		this->Order = 50;
	}
	if(goalName == "giantduckgoal") {
		this->Type = ItemType::GiantDuck;
		this->Order = 1;
	}
	if(goalName == "giantpinatagoal") {
		this->Type = ItemType::GiantPinata;
		this->Order = 1;
	}
	if(goalName == "carrotgoal") {
		this->Type = ItemType::Carrot;
		this->Order = 50;
	}
	if(goalName == "duckgoal") {
		this->Type = ItemType::Duck;
		this->Order = 5;
	}
	if(goalName == "coloredballoongoal" || goalName == "colorballoongoal") {
		this->Type = ItemType::ColoredBalloon;
		this->Order = 50;
	}
	if(goalName == "lightbulbgoal") {
		this->Type = ItemType::LightBulb;
		this->Order = 50;
	}
	if(goalName == "jellygoal") {
		this->Type = ItemType::Jelly;
		this->Order = 50;
	}
	if(goalName == "pinatagoal") {
		this->Type = ItemType::Pinata;
		this->Order = 50;
	}
	if(goalName == "cangoal") {
		this->Type = ItemType::CanToss;
		this->Order = 50;
	}
	if(goalName == "easteregggoal") {
		this->Type = ItemType::EasterEgg;
		this->Order = 50;
	}
	if(goalName == "oystergoal") {
		this->Type = ItemType::Oyster;
		this->Order = 50;
	}
	if(goalName == "sodagoal") {
		this->Type = ItemType::Soda;
		this->Order = 50;
	}
	if(goalName == "metalcrategoal") {
		this->Type = ItemType::MetalCrate;
		this->Order = 50;
	}
	if(goalName == "honeygoal") {
		this->Type = ItemType::Honey;
		this->Order = 50;
	}
	if(goalName == "diamondgoal") {
		this->Type = ItemType::Diamond;
		this->Order = 50;
	}
	if(goalName == "shelfgoal" || goalName == "billboardgoal") {
		this->Type = ItemType::Billboard;
		this->Order = 50;
	}
	if(goalName == "soapgoal") {
		this->Type = ItemType::Soap;
		this->Order = 50;
	}
	if(goalName == "molegoal") {
		this->Type = ItemType::Mole;
		this->Order = 50;
	}
	if(goalName == "penguingoal") {
		this->Type = ItemType::Penguin;
		this->Order = 50;
	}
	if(goalName == "toastergoal" || goalName == "birdgoal") {
		this->Type = ItemType::Bird;
		this->Order = 50;
	}
	if(goalName == "potiongoal") {
		this->Type = ItemType::Potion;
		this->Order = 50;
	}
	if(goalName == "stonegoal") {
		this->Type = ItemType::Stone;
		this->Order = 50;
	}
	if(goalName == "ufogoal") {
		this->Type = ItemType::Ufo;
		this->Order = 50;
	}
	if(goalName == "hanoigoal") {
		this->Type = ItemType::Hanoi;
		this->Order = 50;
	}
	if(goalName == "giftgoal") {
		this->Type = ItemType::Gift;
		this->Order = 50;
	}
}

Goal::Goal(ItemType goalType, int count) {
	this->Type = goalType;
	this->Count = count;
}

std::string Goal::ToString() {
	char ret[64];
	sprintf(ret, "[Goal: Type=%d, Count=%d]", (int)this->Type, this->Count);
	return ret;
}

void Goal::Decrease(int amount) {
	this->Count -= amount;
	if(this->Count < 0) {
		this->Count = 0;
	}
}

void Goal::DecreaseInstant(int amount) {
	this->InstantCount -= amount;
}

void Goal::Increase(int amount) {
	this->Count += amount;
}