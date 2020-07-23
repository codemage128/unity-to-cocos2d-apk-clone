#include "global/GameManager.h"
#include "global/SoundManager.h"

#include "cocos2d.h"

USING_NS_CC;

#define CFG UserDefault::getInstance()

GameManager* GameManager::_instance = nullptr;

GameManager::GameManager() {
	_levelStar.clear();
	_levelStar.resize(getLevelCount(), 0);
}

int GameManager::getTotalStar() {
	int sum = 0;
	for(int _i : _levelStar)
		sum += _i;
	return sum;
}

void GameManager::save() {
	CFG->setIntegerForKey("Coin", _coin);
	CFG->setIntegerForKey("CurrentLevel", _curLevel);
	CFG->setIntegerForKey("TopLevel", _topLevel);
	CFG->setIntegerForKey("Life", _life);
	CFG->setIntegerForKey("LastLifeGotTime", (int)_lastLifeGotTime);

	CFG->setIntegerForKey("DailyCheckTime", _dailyCheckedTime);
	CFG->setIntegerForKey("DailyCheckCount", _dailyCheckedCount);

	CFG->setIntegerForKey("BoosterUseable", _boosterUseabel);

	Data data; data.copy((const unsigned char*)&_levelStar[0], _levelStar.size());
	CFG->setDataForKey("LevelStars", data);

	CFG->setIntegerForKey("InvRocket", _inventoryRocketCount);
	CFG->setIntegerForKey("InvBomb", _inventoryBombCount);
	CFG->setIntegerForKey("InvDisco", _inventoryDiscoCount);

	CFG->setIntegerForKey("BoosterHammer", _boosterHammerCount);
	CFG->setIntegerForKey("BoosterBoxing", _boosterBoxingCount);
	CFG->setIntegerForKey("BoosterAnvil", _boosterAnvilCount);
	CFG->setIntegerForKey("BoosterShuffle", _boosterShuffleCount);

	SoundManager::saveSettings();
}

void GameManager::load() {
	_coin = CFG->getIntegerForKey("Coin", 200);
	_curLevel = CFG->getIntegerForKey("CurrentLevel", 1);
	_topLevel = CFG->getIntegerForKey("TopLevel", 1);
	_life = CFG->getIntegerForKey("Life", 5);
	_lastLifeGotTime = (time_t)CFG->getIntegerForKey("LastLifeGotTime", 0);

	_dailyCheckedTime = CFG->getIntegerForKey("DailyCheckTime", 0);
	_dailyCheckedCount = CFG->getIntegerForKey("DailyCheckCount", 0);

	_boosterUseabel = CFG->getIntegerForKey("BoosterUseable", 0xFF);

	Data data = CFG->getDataForKey("LevelStars");
	if(data.getSize() == getLevelCount()) {
		_levelStar.clear(); _levelStar.resize(data.getSize());
		memcpy(&_levelStar[0], data.getBytes(), data.getSize());
	}
	else {
		_levelStar.clear(); _levelStar.resize(getLevelCount(), 0);
	}

	_inventoryRocketCount = CFG->getIntegerForKey("InvRocket", 99);
	_inventoryBombCount = CFG->getIntegerForKey("InvBomb", 99);
	_inventoryDiscoCount = CFG->getIntegerForKey("InvDisco", 99);

	_boosterHammerCount = CFG->getIntegerForKey("BoosterHammer", 99);
	_boosterBoxingCount = CFG->getIntegerForKey("BoosterBoxing", 99);
	_boosterAnvilCount = CFG->getIntegerForKey("BoosterAnvil", 99);
	_boosterShuffleCount = CFG->getIntegerForKey("BoosterShuffle", 99);

	SoundManager::readSettings();
}