#ifndef __CHALLENGE_H__
#define __CHALLENGE_H__

#include "cocos2d.h"
#include <time.h>

USING_NS_CC;

#define DAILY_CHALLENGE_CNT 3
#define WEAKLY_CHALLENGE_CNT 5

enum class CHALLENGE_MODE {
	BLOCK,
	USEITEM,
	STAR,
};

enum class CHALLENGE_BONUS {
	HAMMER,
	ANVIL,
	BOXCLUB,
	DICE,
	ROCKET,
	BOMB,
	DISCO,
	/////////
	BONUS_COUNT
};

class Challenge {
public:
	Challenge();
	void serial(Configuration* config, std::string sPrefix, bool bLoad = true);

	bool notifyEvent(CHALLENGE_MODE action, int type, size_t count);

	//For DlgDailyChallenge, DlgWeaklyChallenge...
	const char* getChallengeIcon(); 
	const char* getChallengeString();

	const char* getBonusCount();
	const char* getBonusIcon();

	bool isSuccess();
	const char* getStateString();
	float getStatePercent();  // 0 ~ 1.0f

public:
	//condition
	CHALLENGE_MODE  _mode = CHALLENGE_MODE::BLOCK;
	int				_type = 0;
	size_t			_count = 10;

	//bonus 
	CHALLENGE_BONUS	_bonusType = CHALLENGE_BONUS::HAMMER;
	size_t			_bonusCnt = 0;

	//state
	bool			_active = true;
	size_t			_pos = 0;
};


class DailyChallenge {
public:
	void serial(Configuration* config, bool bLoad = true);

	void init();	// init challenges for today.

	void notifyEvent(CHALLENGE_MODE mode, int type, int count = 1);

	// Has Successed Challenge? if true, you can get Bonus from DlgDailyChallenge. 
	bool isOpend(); // called by ScnLevelSelect, DlgDailyChallenge

	// update time counter and check challenges.
	// return : remain Time as '00:00:00'
	std::string update(); 

	Challenge& getChallenge(int index);

private:
	int _startTime = 0;
	Challenge _challenges[DAILY_CHALLENGE_CNT];
};

class WeaklyChallenge {
public:
	void serial(Configuration* config, bool bLoad = true);
	void init();	// init challenges for this weak.
	void notifyEvent(CHALLENGE_MODE mode, int type, int count = 1);
	
	// Has Successed Challenge? if true, you can get Bonus from DlgWeaklyChallenge. 
	bool isOpend(); // called by ScnLevelSelect, DlgWeaklyChallenge

	// update time counter and check challenges.
	// return : remain Time as '00:00:00'
	std::string update(); 

private:
	int _startTime = 0;
	Challenge _challenges[WEAKLY_CHALLENGE_CNT];
};

typedef int  BLOCK_TYPE; //Assume 
typedef int  ITEM_TYPE;

class ChallengeManager {
public:
	static ChallengeManager* _instance;
	static ChallengeManager* getInstance() { if (_instance == nullptr) _instance = new ChallengeManager(); return _instance; }
	
	void serial(Configuration* config, bool bLoad = true);

	// Notify events form ScnPlay.
	void notifyBreak(BLOCK_TYPE type, int count = 1) { notifyEvent(CHALLENGE_MODE::BLOCK, (int)type, count); }
	void notifyUseItem(ITEM_TYPE type, int count = 1) { notifyEvent(CHALLENGE_MODE::USEITEM, (int)type, count); }
	void notifyStar(int count = 1) { notifyEvent(CHALLENGE_MODE::STAR, 0, count); }

public:
	DailyChallenge dailyChallenge;
	WeaklyChallenge weaklyChallenge;
private:
	// Notify events form ScnPlay, 
	void notifyEvent(CHALLENGE_MODE mode, int type, int count = 1);

	int _tmLastTriger = 0;
};

#define CHM ChallengeManager::getInstance() 

#endif //__CHALLENGE_H__
