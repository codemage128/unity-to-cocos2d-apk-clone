#ifndef __ENGINE_ITEM_H__
#define __ENGINE_ITEM_H__

#include <string>
#include <list>
#include <set>
#include <vector>

#include "cocos2d.h"

#define ITEM_SPRITE_SIZE_X 100

#define ITEM_BORDER_ZORDER 0
#define ITEM_GLOW_ZORDER_BASE 5
#define ITEM_SPRITE_ZORDER_BASE 10
#define ITEM_MAGICHAT_ZORDER_BASE 50
#define ITEM_BUBBLE_ZORDER_BASE 200
#define ITEM_COMBOHINT_ZORDER 300
#define ITEM_SPECIAL_ZORDER_BASE 350

#define ITEM_GOAL_ANIMATION_ZORDER_ONSCENEROOT 10

enum class ItemType {
	None,
	Seperator,
	ColoredBalloon,
	RocketAndBomb,
	DiscoBallAndBomb,
	DiscoBallAndRocket,
	DoubleDiscoBall,
	DoubleBomb,
	DoubleRocket,
	Bomb,
	Rocket,
	DiscoBall,
	SolidColor1,
	SolidColor2,
	SolidColor3,
	SolidColor4,
	SolidColor5,
	SolidColor6,
	Duck,
	Balloon,
	Pinata,
	LightBulb,
	Crate,
	ColoredCrate,
	Bubble,
	GiantDuck,
	EasterEgg,
	MagicHat,
	Carrot,
	Jelly,
	CanToss,
	Frame,
	GiantPinata,
	Oyster,
	Soda,
	WaterMelon,
	MetalCrate,
	Fish,
	BalloonGenerator,
	Honey,
	Diamond,
	Billboard,
	ColoredSoda,
	Blaster,
	Soap,
	Mole,
	Penguin,
	BirdHouse,
	Bird,
	Potion,
	Barrel,
	Wall,
	Stone,
	Ufo,
	Hanoi,
	Gift,
	__COUNT__
};

enum class TiledEditorId {
	None,
	Empty = 9,
	Seperator,
	SolidColor1 = 1,
	SolidColor2,
	SolidColor3,
	SolidColor4,
	SolidColor5,
	SolidColor6,
	Group1 = 21,
	Group2,
	Group3,
	Group4,
	Group5,
	Group6,
	Group7,
	Group8,
	Group9,
	Group10,
	Group11,
	Duck1 = 41,
	Duck2,
	Duck3,
	Duck4,
	Duck5,
	GiantDuck = 121,
	GiantPinata = 72,
	Bubble = 61,
	Frame = 46,
	WallYellow = 221,
	WallRed,
	WallBlue,
	WallGreen,
	WallPurple,
	WallOrange,
	Balloon = 63,
	LightBulb,
	Crate,
	CrateLayer1,
	CrateLayer2,
	CrateLayer3,
	MagicHat = 103,
	Pinata = 62,
	Jelly = 123,
	CanToss = 69,
	EasterEgg = 71,
	Soap = 76,
	ColoredBallon1 = 104,
	ColoredBallon2,
	ColoredBallon3,
	ColoredBallon4,
	ColoredBallon5,
	ColoredBallon6,
	Oyster = 90,
	Soda4 = 136,
	Soda5 = 138,
	WaterMelon = 91,
	MetalCrate,
	ColorCrateYellow0 = 110,
	ColorCrateYellow1,
	ColorCrateYellow2,
	ColorCrateRed0,
	ColorCrateRed1,
	ColorCrateRed2,
	ColorCrateBlue0 = 124,
	ColorCrateBlue1,
	ColorCrateBlue2,
	ColorCrateGreen0,
	ColorCrateGreen1,
	ColorCrateGreen2,
	ColorCratePurple0,
	ColorCratePurple1,
	ColorCratePurple2,
	ColorCrateOrange0,
	ColorCrateOrange1,
	ColorCrateOrange2,
	RocketHorizantal = 81,
	RocketVertical,
	Bomb,
	DiscoBallColor1,
	DiscoBallColor2,
	DiscoBallColor3,
	DiscoBallColor4,
	DiscoBallColor5,
	DiscoBallColor6,
	BalloonGenerator1 = 74,
	BalloonGenerator2,
	Fish1 = 93,
	Fish2,
	Honey,
	DiamondOpen,
	DiamondClose,
	MoleItem = 77,
	BirdHouse = 54,
	PotionYellow,
	PotionRed,
	PotionBlue,
	PotionGreen,
	PotionPurple,
	PotionOrange,
	Billboard = 98,
	Stone,
	PenguinItem = 78,
	BarrelItem,
	UfoItem = 51,
	HanoiItem = 48,
	GiftItem = 47,
	ColoredSodaYellow = 161,
	ColoredSodaRed = 163,
	ColoredSodaBlue = 165,
	ColoredSodaGreen = 167,
	ColoredSodaPurple = 169,
	BlasterYellowUp = 171,
	BlasterYellowDown,
	BlasterYellowRight = 153,
	BlasterYellowLeft = 173,
	BlasterRedUp = 175,
	BlasterRedDown,
	BlasterRedRight = 157,
	BlasterRedLeft = 177,
	BlasterBlueUp = 201,
	BlasterBlueDown,
	BlasterBlueRight = 183,
	BlasterBlueLeft = 203,
	BlasterGreenUp = 205,
	BlasterGreenDown,
	BlasterGreenRight = 187,
	BlasterGreenLeft = 207,
	BlasterPurpleUp = 209,
	BlasterPurpleDown,
	BlasterPurpleRight = 191,
	BlasterPurpleLeft = 211,
	BlasterOrangeUp = 213,
	BlasterOrangeDown,
	BlasterOrangeRight = 195,
	BlasterOrangeLeft = 215
};

// import types
enum class MatchType;
enum class ExplodeReason;
enum class Direction;
enum class GroupId;
class CanCastShadowComponent;
class MapFieldEntry;
class FallListener;
class SpecialItem;
class FallAnimation;
class Cell;
enum class CollectAnimation;
class GroupCondition;
class GroupMetaData;
class TiledObjectMetaData;
class Level;


// convert functions
ItemType TiledEditorIdAsItemType(TiledEditorId id);
MatchType ItemTypeAsMatchType(ItemType i);
GroupId TiledEditorIdAsGroupId(TiledEditorId id);
GroupId GroupNameAsGroupId(std::string groupName);
void ConvertToWeightedArray(std::vector<int>& weights);
int GetRandomWeightedIndex(std::vector<int>& weights);

class ItemProperties {
public:
	bool hasFrame = false;
	int capacity = 0;
	int order = 0;
	Direction direction = (Direction)0;
	MatchType matchType = (MatchType)100;
	std::string wallGroup;
	cocos2d::Vec2 offset;
	float scale;

	ItemProperties(std::vector<MapFieldEntry>* properties = nullptr);
};

struct ItemDescription {
public:
	ItemType itemType = ItemType::None;
	TiledEditorId tiledEditorId = TiledEditorId::None;
	ItemProperties* properties = nullptr;
	bool ready = false;

	ItemDescription(ItemType itemType, TiledEditorId tiledEditorId = TiledEditorId::None, ItemProperties* properties = nullptr) {
		this->itemType = itemType;
		this->tiledEditorId = tiledEditorId;
		this->properties = properties;
		this->ready = true;
	}
};

class ItemGroup {
private:
	std::vector<GroupCondition*> _conditions;
	std::vector<TiledEditorId> _duckEditorIds;
	std::vector<TiledEditorId> _coloredBalloonEditorIds;

public:
	int Ratio = 0;
	bool UseForDrop = false;
	std::vector<int> DropPosList;
	int DropInterval = 0;
	int GeneratePerTurn = 0;
private:
	std::vector<int> _weights;
	std::vector<ItemDescription*> _itemDescriptions;
	std::vector<int> _ratios;
	Level* _currentLevel = nullptr;
	int _currentTurn = 0;
	int _generatedItemCountThisTurn = 0;
	int _lastSuccessInterval = 0;
	std::vector<int> _itemIds;
	std::set<int> _stoppedItems;

public:
	bool HasAvailableItemTypes() { return this->_itemDescriptions.size() > 0; }
	bool IsIntervalGroup() { return this->DropInterval > 0; }
	ItemGroup(GroupMetaData* groupData);
	bool CanFall();
	void SetCurrentLevel(Level* level) { this->_currentLevel = level; }
	ItemDescription* GetItemDescription();
	TiledEditorId GetRandomDuckEditorId();
	TiledEditorId GetRandomColoredBalloonEditorId();
	void StopItemGeneration(ItemType i);
	ItemType GetRandomItemType();
	ItemDescription* GetRandomItemDescription();
	int GetRandomTiledId();
	bool IsIntervalCompleted(int count);

private:
	GroupCondition* CreateCondition(MapFieldEntry entry);
};

class Item {
private:
	bool _createByFactory = false;
	Cell* _currentCell = nullptr;

	CanCastShadowComponent* _shadowCaster = nullptr;
	bool _canRaiseScoreOnExplode = true;

	//Sequence* _wrongAnimation;
protected:
	Level* CurrentLevel = nullptr;
public:
	int MasterItemExplode = 0;
	ExplodeReason ToBeExplodedBy = (ExplodeReason)0;
	bool FilledNewly = false;
	long LatestExplode = 0;
	bool IsFalling = false;

	FallListener* _fallListener = nullptr;
	FallAnimation* CurrentFallAnimation = nullptr;
	cocos2d::Node* RelativeContainer = nullptr;

	bool ReCycled = false;

public:
	void CleanUpResources();

	virtual Cell* get_CurrentCell() { return this->_currentCell; }
	virtual void set_CurrentCell(Cell* value);
	virtual void OnBeforeRemove();
	virtual void AfterPoolInit();
	virtual void OnItemCreated(Level* currentLevel);

	virtual Item* ExtractSubItem() { return nullptr; }
	virtual void OnFallEnded() {}
	virtual bool CanFall() { return true; }
	virtual bool CanBeEffectedByDiscoBall() { return true; }
	virtual bool IsSpecialItem() { return false; }
	virtual bool CanBeCapturedByJelly() { return false; }
	virtual bool CanBeTapped() { return true; }
	virtual bool CanBeMatchable() { return false; }
	virtual bool CanGenerateScoreOnEachTryExplode() { return false; }
	virtual bool CanGenerateScoreWithoutExplode() { return false; }
	virtual bool CanGenerateScoreThisTurn() { return true; }
	virtual bool CanBeExplodedBySpecialItem() { return true; }
	virtual bool CanBeExplodedByBooster() { return true; }
	virtual bool BoosterAnvilCanBeUsed() { return true; }
	virtual bool BoosterBoxingGloveCanBeUsed() { return true; }
	virtual bool BoosterHammerCanBeUsed() { return true; }
	virtual MatchType GetMatchType();
	virtual ItemType GetItemType() = 0;
	virtual bool CanShuffle() { return false; }
	virtual bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType) { return false; }
	virtual bool TryExplode();
	virtual void RemoveAllLayers() {}
	virtual bool CanBeReplacedByPreLevelBooster() { return false; }
	virtual bool CanBePaint() { return false; }
	virtual bool CanCastShadow() { return false; }
	CanCastShadowComponent* GetShadowCaster();
	virtual bool CanShadowDrop() { return false; }
	virtual int GetScore() { return 10; }
	virtual bool CanRaiseScore() { return this->_canRaiseScoreOnExplode; }
	void PreventRaiseScore() { this->_canRaiseScoreOnExplode = false; }
	void AllowRaiseScore() { this->_canRaiseScoreOnExplode = true; }
	void DoShuffleAnimation(Cell* targetCell, Cell* oldReference);
	virtual void StartExplode();

	virtual void RemoveSelf();
	virtual void OnBeforeNewLevel() { this->CurrentLevel = nullptr; }
	virtual CollectAnimation GetCollectItem();
	virtual void StartCollect();
	virtual void PlayExplodeAudio();
	virtual void PlayWrongMove();

	virtual void ReactToUpperFall() {}
	void AppendFallAnimation(Cell* targetCell);
	virtual bool CanShowMatchHint() { return false; }
	virtual bool CanShowCurrentlyUnderTap() { return false; }
	virtual void InformToBeExplodedBySpecialItem(SpecialItem* specialItem, Direction comingFrom) {}
	virtual void BringToFront() {}
	virtual void SendToBack() {}

private:
	void RemoveWrongAnimation();

protected:
	void StopOtherAnimations();
	FallListener* GetFallListener() { return this->_fallListener; }
	virtual void PlayOnExplodeStartedAnimation();
	virtual void OnCellChanged();
};


class ICanExplodeAtLeast2 {
public:
	virtual void CheckIfExtraExplodeNeeded() = 0;
	virtual void MarkShouldExplodeAtLeast2() = 0;
};


#endif //__ENGINE_ITEM_H__