#ifndef __ENGINE_GRID_H__
#define __ENGINE_GRID_H__

#include <vector>
#include <list>

class MatchFinder;
class MatchGroup;
class Cell;
class Level;
class Item;
enum class Direction;

class Grid {
private:
	std::vector<std::vector<Cell*>> _cellGrid;
	MatchFinder* _matchFinder = nullptr;
	std::list<Cell*> _existingCells;

public:
	int Height = 0;
	int Width = 0;
	Level* CurrentLevel = nullptr;
	int LongestSideLength = 0;

	Grid(std::vector<std::vector<Cell*>>& cellGrid);
	Cell*& cell(int x, int y) { return _cellGrid[x][y]; }

	void DisableHighlights();
	MatchGroup* GetMatch(Cell* cell);
	void PopulateAllMatchesIntoList(std::vector<MatchGroup*>& container);
	Cell* GetCellWithDirection(Cell* source, Direction direction);
	void UserPerfomedTouchOnCell(Cell* theCell);
	bool ExplodeCell(Cell* currentCell, MatchGroup* mgroup = nullptr);

	std::vector<Cell*>/*IEnumerable*/ WalkOnAll();
	std::vector<Cell*>/*IEnumerable*/ WalkOnExistings();

private:
	void AdminClickTool(Item* item, Cell* cell);
	static void CreateSubItem(Item* subItem, Cell* currentCell);
};

#endif //__ENGINE_GRID_H__