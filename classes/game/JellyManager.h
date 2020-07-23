#ifndef __ENGINE_JELLYMANAGER_H__
#define __ENGINE_JELLYMANAGER_H__

#include <vector>
#include "cocos2d.h"

class Level;
struct CellPairs;
class JellyItem;

class JellyManager {
private:
	Level* _level = nullptr;
	std::vector<JellyItem*> _items;
	std::vector<CellPairs*> _candidateCells;
	std::vector<CellPairs*> _candidateCellsSecondary;
	int _jellyExplodedAtMovesLeft = 0;
	int _specialItemsInAction = 0;
	bool _jellyExplodedInSpecialItemChain = false;
	bool _disabled = false;

public:
	JellyManager(Level* level);
	void Spread();
	void Add(JellyItem* jellyItem);
	void Remove(JellyItem* jellyItem);
	void InformJellyExplode();
	void WaitSpecialItem() { this->_specialItemsInAction++; }
	bool AreThereSpecialItemsInAction() { return this->_specialItemsInAction > 0; }
	void SpecialItemEnded(bool jellyExploded);

private:
	void SpreadWithoutControl();

public:
	void ResetExplodeCounter() { this->_jellyExplodedAtMovesLeft = -100000; }
	void Disable() { this->_disabled = true; }
};

#endif //__ENGINE_JELLYMANAGER_H__