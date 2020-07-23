#include "MetaDataSerializer.h"

#include "cocos2d.h"
#include "cocostudio/DictionaryHelper.h"
#include "json/document.h"
#include <string>

USING_NS_CC;
using namespace cocostudio;

LevelMetaData* LevelDataMetaSerializer::DeserializeLevelData(int LevelNo) {

	char lvlnostr[16]; sprintf(lvlnostr, "level/%04d", LevelNo);
	std::string jsonpath = FileUtils::getInstance()->fullPathForFilename(lvlnostr);

	rapidjson::Document jsondoc;
	std::string contentStr = FileUtils::getInstance()->getStringFromFile(jsonpath);
	jsondoc.Parse<0>(contentStr.c_str());
	if(jsondoc.HasParseError())
		return nullptr;

	LevelMetaData& lvData = *(new LevelMetaData);
	lvData.Name = DICTOOL->getStringValue_json(jsondoc, "_Name", "Unnamed Level");
	lvData.Width = DICTOOL->getIntValue_json(jsondoc, "_Width", 0);
	lvData.Height = DICTOOL->getIntValue_json(jsondoc, "_Height", 0);
	lvData.MoveCount = DICTOOL->getIntValue_json(jsondoc, "_MoveCount", 0);

	int goalListSize = DICTOOL->getArrayCount_json(jsondoc, "_GoalList");
	std::vector<GoalMetaData>& goalList = lvData.GoalList;
	goalList.resize(goalListSize);
	for(int i = 0; i < goalListSize; i++) {
		const rapidjson::Value &goalData = DICTOOL->getSubDictionary_json(jsondoc, "_GoalList", i);
		if(!DICTOOL->checkObjectExist_json(goalData)) break;
		
		goalList[i].Name = DICTOOL->getStringValue_json(goalData, "_Name", "");
		goalList[i].Count = DICTOOL->getIntValue_json(goalData, "_Count", 0);
	}

	int cellListSize = DICTOOL->getArrayCount_json(jsondoc, "_CellList");
	std::vector<CellMetaData>& cellList = lvData.CellList;
	cellList.resize(cellListSize);
	for(int i = 0; i < cellListSize; i++) {
		const rapidjson::Value &cellData = DICTOOL->getSubDictionary_json(jsondoc, "_CellList", i);
		if(!DICTOOL->checkObjectExist_json(cellData)) break;
		
		const rapidjson::Value &tiledObjData = DICTOOL->getSubDictionary_json(cellData, "_TiledObject");
		cellList[i].TiledObject.Id = DICTOOL->getIntValue_json(tiledObjData, "_Id", 0);
		cellList[i].TiledObject.Ratio = DICTOOL->getIntValue_json(tiledObjData, "_Ratio", 0);
		
		int propertiesCount = DICTOOL->getArrayCount_json(tiledObjData, "_Properties");
		cellList[i].TiledObject.Properties.resize(propertiesCount);
		for(int j = 0; j < propertiesCount; j++) {
			const rapidjson::Value &propData = DICTOOL->getSubDictionary_json(tiledObjData, "_Properties", j);
			if(!DICTOOL->checkObjectExist_json(propData)) break;
			cellList[i].TiledObject.Properties[j].key = DICTOOL->getStringValue_json(propData, "_key", "");
			cellList[i].TiledObject.Properties[j].value = DICTOOL->getStringValue_json(propData, "_value", "");
		}

		cellList[i].BubbleCount = DICTOOL->getIntValue_json(cellData, "_BubbleCount", 0);
	}
	
	int groupListSize = DICTOOL->getArrayCount_json(jsondoc, "_GroupList");
	std::vector<GroupMetaData>& groupList = lvData.GroupList;
	groupList.resize(groupListSize);
	for(int i = 0; i < groupListSize; i++) {
		const rapidjson::Value &groupData = DICTOOL->getSubDictionary_json(jsondoc, "_GroupList", i);
		if(!DICTOOL->checkObjectExist_json(groupData)) break;

		groupList[i].Name = DICTOOL->getStringValue_json(groupData, "_Name", "");
		groupList[i].Ratio = DICTOOL->getIntValue_json(groupData, "_Ratio", 0);
		groupList[i].ConditionAndIsUsed = DICTOOL->getBooleanValue_json(groupData, "_ConditionAndIsUsed", false);
		groupList[i].GeneratePerTurn = DICTOOL->getIntValue_json(groupData, "_GeneratePerTurn", 0);

		int itemcount = DICTOOL->getArrayCount_json(groupData, "_Items");
		std::vector<TiledObjectMetaData>& items = groupList[i].Items;
		items.resize(itemcount);
		for(int j = 0; j < itemcount; j++) {
			const rapidjson::Value &itemdata = DICTOOL->getSubDictionary_json(groupData, "_Items", j);
			items[j].Id = DICTOOL->getIntValue_json(itemdata, "_Id", 0);
			items[j].Ratio = DICTOOL->getIntValue_json(itemdata, "_Ratio", 0);

			int propcount = DICTOOL->getArrayCount_json(itemdata, "_Properties");
			items[j].Properties.resize(propcount);
			for(int k = 0; k < propcount; k++) {
				const rapidjson::Value &propdata = DICTOOL->getSubDictionary_json(itemdata, "_Properties", k);
				items[j].Properties[k].key = DICTOOL->getStringValue_json(propdata, "_key", "");
				items[j].Properties[k].value = DICTOOL->getStringValue_json(propdata, "_value", "");
			}
		}
		
		int condcount = DICTOOL->getArrayCount_json(groupData, "_Conditions");
		std::vector<MapFieldEntry>& conds = groupList[i].Conditions;
		conds.resize(condcount);
		for(int j = 0; j < condcount; j++) {
			const rapidjson::Value &condData = DICTOOL->getSubDictionary_json(groupData, "_Conditions", j);
			conds[j].key = DICTOOL->getStringValue_json(condData, "_key", "");
			conds[j].value = DICTOOL->getStringValue_json(condData, "_value", "");
		}

		groupList[i].DropInterval = DICTOOL->getIntValue_json(groupData, "_DropInterval", 0);
		
		int dropposcount = DICTOOL->getArrayCount_json(groupData, "_DropPosList");
		std::vector<int>& dropposes = groupList[i].DropPosList;
		dropposes.resize(dropposcount);
		for(int j = 0; j < dropposcount; j++)
			dropposes[j] = DICTOOL->getIntValueFromArray_json(groupData, "_DropPosList", j);

		groupList[i].UseForDrop = DICTOOL->getIntValue_json(groupData, "_UseForDrop", 0);
	}

	int starSize = DICTOOL->getArrayCount_json(jsondoc, "_Stars");
	std::vector<int>& stars = lvData.Stars;
	stars.resize(starSize);
	for(int i = 0; i < starSize; i++) {
		stars[i] = DICTOOL->getIntValueFromArray_json(jsondoc, "_Stars", i);
	}

	TutorialMetaData& tutorial = lvData.Tutorial;
	const rapidjson::Value &tutData = DICTOOL->getSubDictionary_json(jsondoc, "_Tutorial");
	if(!DICTOOL->checkObjectExist_json(tutData)) return &lvData;
	tutorial.Level = DICTOOL->getIntValue_json(tutData, "_Level", 0);
	int highlightSize = DICTOOL->getArrayCount_json(tutData, "_Highlights");
	tutorial.Highlights.resize(highlightSize);
	for(int i = 0; i < highlightSize; i++)
		tutorial.Highlights[i] = DICTOOL->getIntValueFromArray_json(tutData, "_Highlights", i);
	tutorial.Text = DICTOOL->getStringValue_json(tutData, "_Text", "");

	return &lvData;
}