#include "Item.h"
#include "Match.h"
#include "Group.h"
#include "Mathf.h"
#include "Extension.h"

ItemType TiledEditorIdAsItemType(TiledEditorId id) {
	switch(id) {
	case TiledEditorId::Pinata:
		return ItemType::Pinata;

	case TiledEditorId::Balloon:
		return ItemType::Balloon;

	case TiledEditorId::LightBulb:
		return ItemType::LightBulb;

	case TiledEditorId::Crate:
	case TiledEditorId::CrateLayer1:
	case TiledEditorId::CrateLayer2:
	case TiledEditorId::CrateLayer3:
		return ItemType::Crate;

	case TiledEditorId::CanToss:
		return ItemType::CanToss;

	case TiledEditorId::EasterEgg:
		return ItemType::EasterEgg;

	case TiledEditorId::GiantPinata:
		return ItemType::GiantPinata;

	case TiledEditorId::BalloonGenerator1:
	case TiledEditorId::BalloonGenerator2:
		return ItemType::BalloonGenerator;

	case TiledEditorId::RocketHorizantal:
	case TiledEditorId::RocketVertical:
		return ItemType::Rocket;

	case TiledEditorId::Bomb:
		return ItemType::Bomb;

	case TiledEditorId::DiscoBallColor1:
	case TiledEditorId::DiscoBallColor2:
	case TiledEditorId::DiscoBallColor3:
	case TiledEditorId::DiscoBallColor4:
	case TiledEditorId::DiscoBallColor5:
	case TiledEditorId::DiscoBallColor6:
		return ItemType::DiscoBall;

	case TiledEditorId::Oyster:
		return ItemType::Oyster;

	case TiledEditorId::WaterMelon:
		return ItemType::WaterMelon;

	case TiledEditorId::MetalCrate:
		return ItemType::MetalCrate;

	case TiledEditorId::Fish1:
	case TiledEditorId::Fish2:
		return ItemType::Fish;

	case TiledEditorId::Honey:
		return ItemType::Honey;

	case TiledEditorId::DiamondOpen:
	case TiledEditorId::DiamondClose:
		return ItemType::Diamond;

	case TiledEditorId::Billboard:
		return ItemType::Billboard;

	case TiledEditorId::MagicHat:
		return ItemType::MagicHat;

	case TiledEditorId::ColoredBallon1:
	case TiledEditorId::ColoredBallon2:
	case TiledEditorId::ColoredBallon3:
	case TiledEditorId::ColoredBallon4:
	case TiledEditorId::ColoredBallon5:
	case TiledEditorId::ColoredBallon6:
		return ItemType::ColoredBalloon;

	case TiledEditorId::ColorCrateYellow0:
	case TiledEditorId::ColorCrateYellow1:
	case TiledEditorId::ColorCrateYellow2:
	case TiledEditorId::ColorCrateRed0:
	case TiledEditorId::ColorCrateRed1:
	case TiledEditorId::ColorCrateRed2:
	case TiledEditorId::ColorCrateBlue0:
	case TiledEditorId::ColorCrateBlue1:
	case TiledEditorId::ColorCrateBlue2:
	case TiledEditorId::ColorCrateGreen0:
	case TiledEditorId::ColorCrateGreen1:
	case TiledEditorId::ColorCrateGreen2:
	case TiledEditorId::ColorCratePurple0:
	case TiledEditorId::ColorCratePurple1:
	case TiledEditorId::ColorCratePurple2:
	case TiledEditorId::ColorCrateOrange0:
	case TiledEditorId::ColorCrateOrange1:
	case TiledEditorId::ColorCrateOrange2:
		return ItemType::ColoredCrate;

	case TiledEditorId::GiantDuck:
		return ItemType::GiantDuck;

	case TiledEditorId::Jelly:
		return ItemType::Jelly;

	case TiledEditorId::Soda4:
	case TiledEditorId::Soda5:
		return ItemType::Soda;

	case TiledEditorId::ColoredSodaYellow:
	case TiledEditorId::ColoredSodaRed:
	case TiledEditorId::ColoredSodaBlue:
	case TiledEditorId::ColoredSodaGreen:
	case TiledEditorId::ColoredSodaPurple:
		return ItemType::ColoredSoda;

	case TiledEditorId::None:
	case TiledEditorId::Empty:
		return ItemType::None;

	case TiledEditorId::SolidColor1:
		return ItemType::SolidColor1;

	case TiledEditorId::SolidColor2:
		return ItemType::SolidColor2;

	case TiledEditorId::SolidColor3:
		return ItemType::SolidColor3;

	case TiledEditorId::SolidColor4:
		return ItemType::SolidColor4;

	case TiledEditorId::SolidColor5:
		return ItemType::SolidColor5;

	case TiledEditorId::SolidColor6:
		return ItemType::SolidColor6;

	case TiledEditorId::Duck1:
	case TiledEditorId::Duck2:
	case TiledEditorId::Duck3:
	case TiledEditorId::Duck4:
	case TiledEditorId::Duck5:
		return ItemType::Duck;

	case TiledEditorId::Frame:
		return ItemType::Frame;
	}
	//LogManager.Error(LogTags.TiledToItemType, "Don't know how to convert: " + id, new object[0]);
	return ItemType::None;
}


MatchType ItemTypeAsMatchType(ItemType i) {
	switch(i) {
	case ItemType::SolidColor1:
		return MatchType::Yellow;

	case ItemType::SolidColor2:
		return MatchType::Red;

	case ItemType::SolidColor3:
		return MatchType::Blue;

	case ItemType::SolidColor4:
		return MatchType::Green;

	case ItemType::SolidColor5:
		return MatchType::Purple;

	case ItemType::SolidColor6:
		return MatchType::Orange;
	}
	return MatchType::None;
}


GroupId TiledEditorIdAsGroupId(TiledEditorId id) {
	switch(id) {
	case TiledEditorId::Group1:
		return GroupId::Group1;
	case TiledEditorId::Group2:
		return GroupId::Group2;
	case TiledEditorId::Group3:
		return GroupId::Group3;
	case TiledEditorId::Group4:
		return GroupId::Group4;
	case TiledEditorId::Group5:
		return GroupId::Group5;
	case TiledEditorId::Group6:
		return GroupId::Group6;
	case TiledEditorId::Group7:
		return GroupId::Group7;
	case TiledEditorId::Group8:
		return GroupId::Group8;
	case TiledEditorId::Group9:
		return GroupId::Group9;
	case TiledEditorId::Group10:
		return GroupId::Group10;
	default:
		return GroupId::None;
	}
}

GroupId GroupNameAsGroupId(std::string groupName) {
	std::string numstr = groupName.substr(std::string("group").length());
	int num = Ext_stoi(numstr);
	GroupId result = GroupId::None;
	switch(num) {
	case 1:
		result = GroupId::Group1;
		break;
	case 2:
		result = GroupId::Group2;
		break;
	case 3:
		result = GroupId::Group3;
		break;
	case 4:
		result = GroupId::Group4;
		break;
	case 5:
		result = GroupId::Group5;
		break;
	case 6:
		result = GroupId::Group6;
		break;
	case 7:
		result = GroupId::Group7;
		break;
	case 8:
		result = GroupId::Group8;
		break;
	case 9:
		result = GroupId::Group9;
		break;
	case 10:
		result = GroupId::Group10;
		break;
	case 11:
		result = GroupId::Group11;
		break;
	}
	return result;
}


void ConvertToWeightedArray(std::vector<int>& weights) {
	for(int i = 1; i < (int)weights.size(); i++) {
		weights[i] += weights[i - 1];
	}
}


int GetRandomWeightedIndex(std::vector<int>& weights) {
	if(weights.size() == 1) {
		return 0;
	}
	int num = Mathf::Random::Range(0, weights[weights.size() - 1]);
	for(int i = 0; i < (int)weights.size(); i++) {
		if(num < weights[i]) {
			return i;
		}
	}
	return -1;
}
