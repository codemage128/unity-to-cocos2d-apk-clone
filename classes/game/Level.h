#ifndef __ENGINE_LEVEL_H__
#define __ENGINE_LEVEL_H__

#include <string>
#include <vector>
#include <map>
#include <list>

class Grid;
class LevelBuilder;
class Goal;
class JellyManager;
class Item;
class ItemGroup;
struct ItemDescription;
class IExplodeAware;
enum class GroupId;
enum class ItemType;

class Level {
public:
	static int ExtraMoveCountABValue;

	std::string Name;
	std::string GameId;
	Grid* CurrentGrid = nullptr;
	std::map<GroupId, ItemGroup*> CurrentItemGroups;
	std::map<int, std::list<ItemDescription*>*> PreDefinedFills;
	bool IsPredefinedLevel = false;
	LevelBuilder* CurrentLevelBuilder = nullptr;
	std::vector<Goal*> Goals;
	bool HasIntervalGroups = false;
	std::vector<int> ItemCounts;// = new int[Enum.GetNames(typeof(ItemType)).Length];
	std::vector<int> ToGoalToItemCounts;// = new int[Enum.GetNames(typeof(ItemType)).Length];
	int LevelNo = 0;
	bool LevelWon = false;
	int MaximumMovesAllowed = 0;
	int LevelMoves = 0;
	int MovesLeftBeforeWin = 0;
	std::vector<int> Stars;
	int TotalExplodedItemCount = 0;
	bool Cancelled = false;
	bool HasWonBefore = false;
	JellyManager* JellyItemManager = nullptr;
private:
	int _blockWinRequest = 0;
	float _startTime = 0.0f;
	bool _duckCountLimitReached = false;
	int _turnNo = 0;
public:
	std::vector<IExplodeAware*> ExplodeAwareItem;
	float StartTime = 0.0f;
	int TurnNo = 0;
	int MovesUserPerformed = 0;
	int get_MovesLeft() { return this->MaximumMovesAllowed - this->MovesUserPerformed; }
	int EgoDialogIndex = 0;

public:
	Level();
	void cleanUp();

	void SetPredefinedFills(std::map<int, std::list<ItemDescription*>*>& fills);
	void IncreaseTurnNo();
	Item* GetItemByGroupId(GroupId groupId);
	void IncreaseMoveCount();
	void IncreaseItemCount(ItemType itemType);
	void DecreaseItemCount(ItemType itemType);
	int CanGenerateCount(ItemType itemType);
	bool CanBeCollected(ItemType currentItem);
	void PreCheckDecreaseGoal(ItemType goalType);
	void IncreaseGoal(ItemType goalType);
	void DecreaseGoal(ItemType goalType, bool collectCOunterIsManagedByCaller);
	void StopRefillIfNeeded(ItemType goalType);
	void StopRefillIfNeeded(ItemType goalType, Goal* goal);
	bool CanGenerateGoalItem(ItemType type);
	int LeftBubbleCount();
	Goal* GetGoalFromItemType(ItemType type);
	void IncreaseBlockWin();
	void DecreaseBlockWin();
	void ResetSelf();
	/*IEnumerator*/void WaitForFallingItems();
	void ContinueWinAfterMovesLeft();
	void LostLevel();
	void LostLevelWithoutExtraMoves();
	void ContinueLevelAfterDelay(float delay);
	void ContinueLevel();
	GroupId GetIntervalCompletedGroups(std::vector<GroupId>& intervalGroupIds);
	void ExplodeEnded();
private:
	void StopGenerationForItemType(ItemType itemType);
	/*IEnumerator*/void ContinueLevelDelayed(float delay);
	/*IEnumerator*/void ShowEgo();

public:
	void onFrame(float delta);
};

#endif //__ENGINE_LEVEL_H__