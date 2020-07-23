#ifndef __ENGINE_MATCH_H__
#define __ENGINE_MATCH_H__

#include <vector>
#include <stack>
#include <list>
#include <string>

enum class MatchType {
	Yellow,
	Red,
	Blue,
	Green,
	Purple,
	Orange,
	None = 100
};

class MatchTypeComparer {
public:
	bool Equals(MatchType x, MatchType y) {
		return x == y;
	}

	int GetHashCode(MatchType obj) {
		return (int)obj;
	}
};


class Cell;
class Grid;
class DiscoBallItem;
enum class ItemType;

class MatchGroup {
private:
	MatchGroup() {}
public:
	static const int Capacity = 100;
	static std::stack<MatchGroup*> PooledItems;

	std::vector<Cell*> AllCells;
	Cell* ClickedCell = nullptr;
	MatchType matchType = MatchType::None;
	int Size = 0;
	bool CanGenerateSpecialItem = false;
	bool CanMatchExplode = false;
	int Score = 0;
	bool CanGenerateCombo = false;
	ItemType ComboType = (ItemType)0;
	ItemType SpecialItemType = (ItemType)0;
	bool AtLeastOneFalling = false;

public:
	static MatchGroup* Get(Cell* cell);
	static void Put(MatchGroup* usedItem);
	void Clear();
	void Summarize();
	DiscoBallItem* GetFirstDiscoBall();
	std::string ToString();
	void Init(Cell* cell);
};

class MatchFinder {
private:
	std::list<Cell*> _existingCells;
	Grid* _grid = nullptr;
	int _height = 0;
	int _width = 0;
	std::vector<std::vector< bool>> _visited;
	std::vector<std::vector< bool>> _visitedForSingleMatch;// = new bool[9, 9];

public:
	MatchFinder(Grid* grid);
	MatchGroup* GetSingleMatch(Cell* cell);
	MatchGroup* GetComboMatch(Cell* cell);
	void PopulateAllMatches(std::vector<MatchGroup*>& container);

private:
	static void FindSingleMatch(std::vector<std::vector<bool>>* visited, MatchType matchType, std::vector<Cell*>* roots, std::vector<Cell*>* allCells);
	static void FindComboMatch(std::vector<std::vector<bool>>* visited, std::vector<Cell*>* roots, std::vector<Cell*>* allCells);
	MatchGroup* GetMatch(Cell* cell);
	void FindMatch(MatchType matchType, std::vector<Cell*>* roots, std::vector<Cell*>* allCells);
};

#endif //__ENGINE_MATCH_H__