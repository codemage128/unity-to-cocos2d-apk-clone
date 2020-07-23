#ifndef __ENGINE_LEVELBUILDER_H__
#define __ENGINE_LEVELBUILDER_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include <set>

class LevelDataMetaSerializer;
class LevelMetaData;
class Level;
class ItemGroup;
struct ItemDescription;
class MapFieldEntry;
class CellData;
class CellMetaData;
class Cell;
class Grid;
class Item;
class HintManager;
class MatchGroup;
enum class MatchType;
enum class GroupId;
enum class ItemType;

class HorizontalRocketItem;
class VerticalRocketItem;
class SpecialItem;

class ScnLevelPlay;
//class WinLogoAnimation;
//class WinCharsAnimation;
//class TutorialBase;

class LevelBuilder {
private:
	LevelMetaData* _currentLevelMetaData = nullptr;
	bool _musicStarted = false;
public:
	LevelBuilder() {}

	static int CurrentLevelNo;
	static std::string CurrentLevelPath;
	static Level* ActiveLevel;
	static bool MovedToNextLevel;
	static bool BackgroundAssetsLoaded;
	static bool ShouldRemoveBackgroundImagesOnDestroy;// = true;
	static std::string LevelStartType;
	static bool UserPlayedALevel;

	const std::string LevelStart_Map;// = "Map";
	const std::string LevelStart_TryAgain;// = "TryAgain";
	const std::string LevelStart_Auto;// = "Automatic";
	cocos2d::Sprite* NewMapBackgroundImage = nullptr;

	Level* CurrentLevel = nullptr;
	ScnLevelPlay *LevelScene = nullptr;
	cocos2d::Node *TutorialBearPanel = nullptr;
	HintManager *CurrentHintManager = nullptr;

	cocos2d::Node *CellContainer = nullptr;
	cocos2d::Node* SceneContainer = nullptr;
	cocos2d::Node *ItemContainer = nullptr;

	std::vector<cocos2d::Node*> ShakePanels;

	//WinLogoAnimation* WinLogoAnimation;
	//WinCharsAnimation *WinCharsAnimation;

	cocos2d::Node* BoosterPanel = nullptr;
	cocos2d::Node* GenericCollectItem = nullptr;
	cocos2d::Node* BubbleAnimationItem = nullptr;
	cocos2d::Node* BalloonGeneratorThrowAnimation = nullptr;

	static void Reset();
	
	void buildLevel();
	void cleanUp();

	void SceneCreatedNewLevel(int levelNo);
	void SceneReloadedSetups();

private:
	static bool AreThereAvailableMatches(Level* level);
	static std::map<GroupId, ItemGroup*>* CreateItemGroups(LevelMetaData* levelData);
	static void UpdateFillLayerGroups(Level* level, std::map<int, Cell*>& fillCells);
	static int CalculateOrderNo(int x, int y, int w, int h);
	static Cell* FindFirstExistingBottomCell(Cell* cell);

	//void PlayTutorial(TutorialBase* tutorial);
	void initLevelData();
	void ReInitItems(cocos2d::Node* obj);
	/*IEnumerator*/void PlayIntroMusic();
	void PlayMusic();
	void CreateAndSetCurrentLevel();
	void TryCreateAMatch(Level* level);
	bool TryToChangeGroupItem(Level* level, GroupId groupId, ItemType itemType, int x, int y, int w, int h);
	Grid* BuildGrid(int width, int height, std::map<GroupId, ItemGroup*>* itemGroups);
	void UpdateItemFromMetaData(Cell* cell, CellData* cellData, std::map<GroupId, ItemGroup*>* itemGroups, std::vector<MapFieldEntry>* Properties = nullptr);
	void UpdateCellFromMetaData(Cell* cell, CellMetaData* cellData);
	Item* CreateItemInternal(ItemDescription* itemDescription);
	void PopulateSelectedPreLevelItems(std::vector<Cell*>* cellsNotAvailable);
	void CreateSelectedSpecialItems(std::vector<ItemType>& selectedItems, bool spendFromInventory = true, bool playCreationParticle = false, std::set<Cell*>* cellsNotAvailable = nullptr);

public:
	Item* CreateItemFromItemGroupEntry(ItemDescription* itemDescription);
	Item* CreateItemFromMetaData(CellData* cellMetaData, std::vector<MapFieldEntry>* properties = nullptr);
	Item* CreateItem(ItemDescription* itemDescription);
	bool CreateItemAtCell(ItemType itemType, Cell* cell);
	HorizontalRocketItem* CreateRandomRocket(cocos2d::Vec2 position);
	HorizontalRocketItem* CreateHorizantalRocket(cocos2d::Vec2 position);
	VerticalRocketItem* CreateVerticallRocket(cocos2d::Vec2 position);
	SpecialItem* CreateSpecialItem(ItemType type, MatchType m, cocos2d::Vec2 position, Cell* cell);
	SpecialItem* CreateComboItem(MatchGroup* mgroup, cocos2d::Vec2 position);
	void PopulateEgoItems();

	void setCellItemSpritePosition(Cell* cell, Item* item);
	static cocos2d::Sprite* getItemSprite(Item* item);
};

#endif //__ENGINE_LEVELBUILDER_H__