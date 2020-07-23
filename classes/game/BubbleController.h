#ifndef __ENGINE_BUBBLECONTROLLER_H__
#define __ENGINE_BUBBLECONTROLLER_H__

#include <vector>
#include <set>

class Cell;
class FishItem;
class Grid;

class BubbleController {
private:
	static BubbleController* _instance;
	std::vector<Cell*> _availableCellList;
	int _bubbleCount = 0;
	std::set<FishItem*> _bubbleGenerators;
	Grid* _grid = nullptr;
	int _latestFrame = 0;

public:
	static BubbleController* getInstance() { if(_instance == nullptr) _instance = new BubbleController(); return _instance; }
	int BubbleCount() { return this->_bubbleCount; }
	void IncreaseBubbleCount() { this->_bubbleCount++; }
	void ResetBubbleCount() { this->_bubbleCount = 0; }
	void SetGrid(Grid* grid) { this->_grid = grid; }
	void AddBubbleGeneratorItem(FishItem* fishItem) { this->_bubbleGenerators.insert(fishItem); }
	void ClearBubbleGenerators() { this->_bubbleGenerators.clear(); }

	Cell* GetRandomCell();
	void TrySleepGenerators();
};

#endif //__ENGINE_BUBBLECONTROLLER_H__