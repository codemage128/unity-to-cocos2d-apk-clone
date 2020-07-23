#ifndef __ENGINE_FALLMANAGER_H__
#define __ENGINE_FALLMANAGER_H__

#include <vector>
#include "cocos2d.h"

class HintManager;
class LevelBuilder;
class Grid;
class Level;
class Cell;

class FallAnimation;

class FallManager {
private:
	static FallManager* _instance;
public:
	LevelBuilder* CurrentLevelBuilder = nullptr;
	HintManager* CurrentHintManager = nullptr;

	FallManager();

	static cocos2d::Vec2 FallReference;
	static FallManager* getInstance() { if(_instance == nullptr) _instance = new FallManager(); return _instance; }
	//static void ResetSelf() { if(_instance != nullptr) delete _instance; _instance = nullptr; }
	static bool AreFallsBlocked() { return FallManager::getInstance()->_fallBlockerCounter > 0; }

private:
	Grid* _currentGrid = nullptr;
	Level* _currentLevel = nullptr;
	std::vector<Cell*> _fillingCells;
	std::vector<Cell*> _validCells;
	int _mechanicAnimation = 0;
	int _statAnimation = 0;
	int _fallCount = 0;
	int _fallBlockerCounter = 0;
	bool _started = false;
	float _fallPointY = 0.0f;
	float _fallPointY2 = 0.0f;

	std::vector<FallAnimation*> _fallanimations;

public:
	void cleanUp();
	void SceneReloadedSetups();
	void Update();

	void addFallAnimation(FallAnimation* anim);
	void removeFallAnimation(FallAnimation* anim);

private:
	void FallItemInCell(Cell* sourceCell, Cell* targetCell);
	static bool IsExistingCell(Cell* theCell);
public:
	static bool AreThereFallingItems();
	static bool AreThereMechanicAnimations();
	static bool AreThereActiveAnimations();
	static void DecreaseMechanicAnimation();
	static void IncreaseMechanicAnimation();
	static void DecreaseStatAnimation();
	static void IncreaseStatAnimation();
	static void AddOneFall();
	static void RemoveOneFall();
	static void IncreaseWaitingFallBlocker();
	static void DecreaseWaitingFallBlocker();
	static void StartRunning();
};

#endif //__ENGINE_FALLMANAGER_H__