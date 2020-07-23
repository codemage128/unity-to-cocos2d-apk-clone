#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include "cocos2d.h"

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 1280

#define GM GameManager::getInstance()

#include <vector>

class GameManager {
private:
	static GameManager* _instance;

	// serialized fields
	int _coin = 200;
	int _curLevel = 1;
	int _topLevel = 1;
	int _life = 5;
	time_t _lastLifeGotTime = 0;

	int _dailyCheckedTime = 0;
	int _dailyCheckedCount = 0;

	enum class BoosterUseable { Hammer = 1, Boxing = 2, Anvil = 4, Shuffle = 8 };
	int _boosterUseabel = 0x0;

	std::vector<char> _levelStar;

	int _inventoryRocketCount = 0;
	int _inventoryBombCount = 0;
	int _inventoryDiscoCount = 0;

	int _boosterHammerCount = 0;
	int _boosterBoxingCount = 0;
	int _boosterAnvilCount = 0;
	int _boosterShuffleCount = 0;


	// unserialized fields
	enum class LevelStartupItem { Rocket = 1, Bomb = 2, Disco = 4 };
	int _levelStartupItem = 0;

public:
	static GameManager* getInstance() { if(_instance == nullptr) _instance = new GameManager(); return _instance; }
	GameManager();

	void save();
	void load();

	// constants
	int getLevelCount() { return 1350; }
	float getLifeChargeTime() {return 30 * 60.0f; }
	int getMaxLife() { return 5; }
	int getMaxLevelStar() { return 3; }

	// states
	int getTopLevel() { return _topLevel; }
	int setTopLevel(int toplevel) { _topLevel = toplevel; return _topLevel; }
	int getCurrentLevel() { return _curLevel; }
	int setCurrentLevel(int level) { _curLevel = level; return level; }
	int getTotalStar();
	int getStarCount() { return getMaxLevelStar()*getLevelCount(); }
	int getLevelStar(int level) { return _levelStar[level]; }

	int getLife() { return _life; }
	int plusLife(int delta) { _life += delta; if(_life < 0) _life = 0; if(_life>getMaxLife()) _life = getMaxLife(); return _life; }

	int getDailyCheckedCount() { return _dailyCheckedCount; }
	void setDailyCheckedCount(int count) { _dailyCheckedCount = count; }

	int getDailyCheckedTime() { return _dailyCheckedTime; }
	void setDailyCheckedTime(int time) { _dailyCheckedTime = time; }

	int getCoin() { return _coin; }
	int updateCoin(int delta) { _coin += delta; if(_coin < 0) _coin = 0; return _coin; }

	void setLastLifeTime(time_t t) { _lastLifeGotTime = t; }
	time_t getLastLifeTime() { return _lastLifeGotTime; }

	int getInvRocketCount() { return _inventoryRocketCount; }
	int getInvBombCount() { return _inventoryBombCount; }
	int getInvDiscoCount() { return _inventoryDiscoCount; }
	int updateInvRocketCount(int delta) { if((_inventoryRocketCount += delta) < 0) _inventoryRocketCount = 0; return _inventoryRocketCount; }
	int updateInvBombCount(int delta) { if((_inventoryBombCount += delta) < 0) _inventoryBombCount = 0; return _inventoryBombCount; }
	int updateInvDiscoCount(int delta) { if((_inventoryDiscoCount += delta) < 0) _inventoryDiscoCount = 0; return _inventoryDiscoCount; }

	void setBoosterHammerUseable() { _boosterUseabel |= (int)BoosterUseable::Hammer; }
	void setBoosterBoxingUseable() { _boosterUseabel |= (int)BoosterUseable::Boxing; }
	void setBoosterAnvilUseable() { _boosterUseabel |= (int)BoosterUseable::Anvil; }
	void setBoosterShuffleUseable() { _boosterUseabel |= (int)BoosterUseable::Shuffle; }

	bool getBoosterHammerUseable() { return (_boosterUseabel&(int)BoosterUseable::Hammer) != 0; }
	bool getBoosterBoxingUseable() { return (_boosterUseabel&(int)BoosterUseable::Boxing) != 0; }
	bool getBoosterAnvilUseable() { return (_boosterUseabel&(int)BoosterUseable::Anvil) != 0; }
	bool getBoosterShuffleUseable() { return (_boosterUseabel&(int)BoosterUseable::Shuffle) != 0; }

	int getBoosterHammerCount() { return _boosterHammerCount; }
	int getBoosterBoxingCount() { return _boosterBoxingCount; }
	int getBoosterAnvilCount() { return _boosterAnvilCount; }
	int getBoosterShuffleCount() { return _boosterShuffleCount; }

	int updateBoosterHammerCount(int delta) { _boosterHammerCount += delta; if(_boosterHammerCount < 0) _boosterHammerCount = 0; return _boosterHammerCount; }
	int updateBoosterBoxingCount(int delta) { _boosterBoxingCount += delta; if(_boosterBoxingCount < 0) _boosterBoxingCount = 0; return _boosterBoxingCount; }
	int updateBoosterAnvilCount(int delta) { _boosterAnvilCount += delta; if(_boosterAnvilCount < 0) _boosterAnvilCount = 0; return _boosterAnvilCount; }
	int updateBoosterShuffleCount(int delta) { _boosterShuffleCount += delta; if(_boosterShuffleCount < 0) _boosterShuffleCount = 0; return _boosterShuffleCount; }

	// interconnection
	void setLevelStartupItem(bool rocket, bool bomb, bool disco) {
		_levelStartupItem = 0;
		if(rocket) _levelStartupItem |= (int)LevelStartupItem::Rocket;
		if(bomb) _levelStartupItem |= (int)LevelStartupItem::Bomb;
		if(disco) _levelStartupItem |= (int)LevelStartupItem::Disco;
	}
	bool getLevelStartupItemHasRocket() { return (_levelStartupItem&(int)LevelStartupItem::Rocket) != 0; }
	bool getLevelStartupItemHasBomb() { return (_levelStartupItem&(int)LevelStartupItem::Bomb) != 0; }
	bool getLevelStartupItemHasDisco() { return (_levelStartupItem&(int)LevelStartupItem::Disco) != 0; }};

#endif //__GAMEMANAGER_H__