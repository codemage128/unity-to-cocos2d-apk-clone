#ifndef __ENGINE_METADATASERIALIZER_H__
#define __ENGINE_METADATASERIALIZER_H__

#include <string>
#include <vector>

class MapFieldEntry {
public:
	std::string key;
	std::string value;
};

class TiledObjectMetaData {
public:
	int Id;
	int Ratio;
	std::vector<MapFieldEntry> Properties;
};


class TutorialMetaData {
public:
	int Level;
	std::vector<int> Highlights;
	std::string Text;
};

class CellMetaData {
public:
	TiledObjectMetaData TiledObject;
	int BubbleCount;
};

class GoalMetaData {
public:
	std::string Name;
	int Count;
};

class GroupMetaData {
public:
	std::string Name;
	int Ratio;
	bool ConditionAndIsUsed;
	int GeneratePerTurn;
	std::vector<TiledObjectMetaData> Items;
	std::vector<MapFieldEntry> Conditions;
	int DropInterval = 0;
	std::vector<int> DropPosList;
	int UseForDrop = 0;
	std::string BarrelWeights;
};

class LevelMetaData {
public:
	std::string Name;
	int Width;
	int Height;
	int MoveCount;
	std::vector<GoalMetaData> GoalList;
	std::vector<CellMetaData> CellList;
	std::vector<GroupMetaData> GroupList;
	std::vector<int> Stars;
	TutorialMetaData Tutorial;
	std::vector<int> PotionColorData;
};

class LevelDataMetaSerializer {
public:
	static LevelMetaData* DeserializeLevelData(int LevelNo);
};



#endif //__ENGINE_SERIALIZER_H__