#ifndef __ENGINe_BOOSTER_H_
#define __ENGINe_BOOSTER_H_

#include "cocos2d.h"

enum class BoosterState {
	InHammer,
	InAnvil,
	InBoxingGlove,
	InShuffle,
	InPaintBrushState,
	Busy,
	InGamePlay
};

enum class InventoryItemType {
	Anvil = 3,
	Bomb = 6,
	BoxingGlove = 4,
	Coins = 1,
	Dice = 9,
	DiscoBall = 7,
	Extra5Moves = 8,
	Hammer = 2,
	Life = 12,
	None = 0,
	PaintBrush = 50,
	PiggyBank = 14,
	Rocket = 5,
	Stars = 11,
	UnlimitedLife = 13,
	UserType = 10
};

class Cell;


class BoosterManager {
private:
	static BoosterManager* _instance;
	BoosterState _currentState = BoosterState::InGamePlay;

	cocos2d::Sprite* _processor = nullptr;

public:
	static BoosterManager* getInstance() { if(_instance == nullptr) _instance = new BoosterManager(); return _instance; }
	void init(cocos2d::Node* scene);
	void cleanUp();

protected:

private:
	void ItemClicked(InventoryItemType itemType, BoosterState state);
	void UseBooster(Cell* cell);
	void UseAnvil(Cell* cell);
	void UseBoxingGlove(Cell* cell);
	void UseHammer(Cell* cell);
	void UsePaintBrush(Cell* cell);
	void UseShuffle(Cell* cell);
	void SwitchToGamePlay();
	void SwitchToBoosterState(InventoryItemType itemType, BoosterState state);
public:
	void AnvilClicked();
	void BoxingGloveClicked();
	void HammerClicked();
	void ShuffleClicked();
	void PaintBrushClicked();

	void CellTapped(Cell* cell);

	bool isInBoosterMode();

protected:
};


#endif //__ENGINe_BOOSTER_H_