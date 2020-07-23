#ifndef __ENGINE_ITEMGENERATORCONTROLLER_H_
#define __ENGINE_ITEMGENERATORCONTROLLER_H_

#include <vector>
#include <map>
#include <string>
#include <set>

class Cell;
class Grid;
class GeneratorBasedItem;
enum class ItemType;

class ItemGeneratorController {
private:
	static ItemGeneratorController* _instance;

	std::vector<Cell*> _availableCellList;
	std::vector<Cell*> _emptyCellList;
	std::vector<Cell*> _fillingCellList;
	std::map<ItemType, std::set<GeneratorBasedItem*>> _generators;
	Grid* _grid = nullptr;
	int _latestFrame = 0;

public:
	static ItemGeneratorController* getInstance() { if(_instance == nullptr) _instance = new ItemGeneratorController(); return _instance; }
	std::set<GeneratorBasedItem*>* GetGenerators(ItemType itemType) { return this->_generators.find(itemType) == this->_generators.end() ? nullptr : &(this->_generators[itemType]); }
	void ResetGenerators() { this->_generators.clear(); }
	void SetGrid(Grid* grid) { this->_grid = grid; }

	Cell* GetRandomCell();
	void RegisterGenerator(ItemType itemType, GeneratorBasedItem* item);
	void SleepGenerators(ItemType itemType);
};


#endif //__ENGINE_ITEMGENERATORCONTROLLER_H_