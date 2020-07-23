#ifndef __ENGINe_SHUFFLE_H_
#define __ENGINe_SHUFFLE_H_

class Item;
class Cell;
class Grid;

#include <vector>
#include <map>

struct ShuffleItem {
public:
	Item* CurrentItem = nullptr;
	Cell* OldReference = nullptr;
	ShuffleItem(Item* i, Cell* c) {
		this->CurrentItem = i;
		this->OldReference = c;
	}
};

class ShuffleManager {
private:
	static ShuffleManager* _instance;

public:
	static ShuffleManager* getInstance() { if(_instance == nullptr) _instance = new ShuffleManager; return _instance; }
	static void ResetSelf() { if(_instance != nullptr) delete _instance; _instance = nullptr; }
	bool Shuffle(Grid* grid);

	static bool TryShuffle(Grid* grid) { return ShuffleManager::getInstance()->Shuffle(grid); }
};

#endif //__ENGINe_SHUFFLE_H_