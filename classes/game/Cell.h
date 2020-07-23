#ifndef __ENGINE_CELL_H__
#define __ENGINE_CELL_H__

#include <vector>
#include <string>

#include "cocos2d.h"

enum class GroupId;
enum class ItemType;
class Item;
class Grid;

enum class Direction {
	None,
	Up,
	Down,
	LeftUp,
	Left,
	LeftDown,
	RightUp,
	Right,
	RightDown
};

enum class ExplodeReason {
	None,
	Anvil,
	BoxingGlove,
	Hammer,
	Disco
};

class CellData {
public:
	int TiledObjectId;
};

class Cell;
struct CellPairs {
public:
	Cell* FromCell = nullptr;
	Cell* ToCell = nullptr;

	CellPairs(Cell* fr, Cell* to) {
		this->FromCell = fr;
		this->ToCell = to;
	}
};

class Cell {
private:
	std::vector<Cell*> _cachedNeigboursWithCorners;
	std::vector<Cell*> _cachedNeigboursWithoutCorners;
	int _canItemsFallInside = 0;
	Item* _currentItem = nullptr;
	std::vector<GroupId> _intervalRefillGroupIds;
	std::vector<GroupId> _refillGroupIds;
	std::vector<int> _refillGroupWeights;

	ItemType _reservedItemType = (ItemType)0;

	//private: Sequence _seq;

	cocos2d::Vec2 _frozenPosition;
public:
	bool HasBubble = false;
	Grid* CurrentGrid = nullptr;
	bool Exists = false;
	Cell* FirstExistingBottomCell = nullptr;
	Cell* JustAboveCell = nullptr;
	Cell* JustBelowCell = nullptr;
	int LastBubbleRemoved = 0;

	int X = -1;
	int Y = -1;

	std::vector< cocos2d::Sprite*> Borders;
	cocos2d::Sprite* BubbleSpriteRenderer = nullptr;
	bool IsFloor = false;
	bool IsFilling = false;
	//BoxCollider2D Collider;
	bool ReservedForBubble=false;
	bool ReservedForGeneratorItem=false;

public:
	Cell();
	~Cell();
	void initRenderer(cocos2d::Node* parent, cocos2d::Vec2 pos);
	Item* get_CurrentItem() { return this->_currentItem; }
	void set_CurrentItem(Item* value);
	bool get_HasItem();
	int GetBubbleScoreIfPossible();
	void ShowHighlight();
	bool CanItemFallFromThisCell();
	std::string ToString();
	void RejectsFallInside();
	void AcceptsFallInside();
	bool CanItemsFallInside();
	void AddIntervalGroupId(GroupId id);
	void AddFillGroupId(GroupId id, int ratio = 1);
	Item* CreateRefillItem();
	//void Squash(/*Sequence seq,*/ cocos2d::Node* rt, float yScale, float time/*, Ease e = 1*/);
	void ShakeBubble();
	void AddBubble(bool isReserved = false);
	void ReserveForItem(ItemType itemType);
	void ApplyReservedItem();
	void ApplyReservedBubble();
	void RemoveBubble();
	void ShowBubble(bool animated = false);
	std::vector<Cell*> GetCachedNeigbours(bool includeCorners);

	void FreezePosition();
	cocos2d::Vec2 GetFrozenPosition();
	Direction GetDirectionTo(Cell* cell);
private:
	std::vector<Cell*> CalculateNeigbours(bool includeCorners);
	static void AddIfExists(std::vector<Cell*>& cells, Cell* cell);

};

#endif //__ENGINE_CELL_H__