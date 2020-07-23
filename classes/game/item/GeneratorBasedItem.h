#ifndef __ENGINE_GENERATORBASEDITEM_H__
#define __ENGINE_GENERATORBASEDITEM_H__

#include "../Item.h"

class Cell;

class GeneratorBasedItem: public Item {
protected:
	ItemType GenerateItemType = ItemType::None;
	int GenerateCount = 1;
	int GenerateInverval = 1;
	int IntervalCounter = 0;

private:
	std::vector<Cell*> _targetCellList;
	bool _waiting = false;

public:
	ItemType GetItemType() override { throw; };
	virtual void Sleep() = 0;
	virtual Cell* GetRandomCell() = 0;
	virtual void PlayThrowAnimation(std::vector<Cell*>* targetCells) = 0;

protected:
	void StartGeneratingItems();

private:
	/*IEnumerator*/void GenerateItems();

protected:
	virtual void OnThrowAnimationComplete(Cell* targetCell);
};


#endif //__ENGINE_GENERATORBASEDITEM_H__
