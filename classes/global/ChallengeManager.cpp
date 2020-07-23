
#include "ChallengeManager.h"
#include "common/Util.h"
#include "cocos2d.h"

USING_NS_CC;

std::string g_bonusIcons[] = {
	"image/playui/hammer.png", //HAMMER
	"image/playui/anvil.png", //ANVIL
	"image/playui/boxclub.png", //BOXCLUB
	"image/playui/dice.png", //DICE
	"image/play/rocketv.png", //ROCKET
	"image/play/bomb.png", //BOMB
	"image/play/discoblue.png", //DISCO
// Notify events form ScnPlay.
};

ChallengeManager* ChallengeManager::_instance = nullptr;

//////////////////////////////////  Challenge ///////////////////
Challenge::Challenge()
{

}

void Challenge::serial(Configuration* config, std::string sPrefix, bool bLoad) {
	if (bLoad) {
		_mode = (CHALLENGE_MODE)config->getValue(sPrefix + "_mode", Value(0)).asInt();
		_type = config->getValue(sPrefix + "_type", Value(0)).asInt();
		_count = config->getValue(sPrefix + "_count", Value(10)).asInt();

		_bonusType = (CHALLENGE_BONUS) config->getValue(sPrefix + "_bonusType", Value(0)).asInt();
		_bonusCnt = config->getValue(sPrefix + "_bonusCnt", Value(0)).asInt();

		_active = config->getValue(sPrefix + "_active", Value(_active)).asBool();
		_pos = config->getValue(sPrefix + "_pos", Value(0)).asInt();
	}
	else {
		config->setValue(sPrefix + "_mode", Value((int)_mode));
		config->setValue(sPrefix + "_type", Value((int)_type));
		config->setValue(sPrefix + "_count", Value((int)_count));

		config->setValue(sPrefix + "_bonusType", Value((int)_bonusType));
		config->setValue(sPrefix + "_bonusCnt", Value((int)_bonusCnt));

		config->setValue(sPrefix + "_active", Value(_active));
		config->setValue(sPrefix + "_pos", Value((int)_pos));
	}
}

bool Challenge::notifyEvent(CHALLENGE_MODE mode, int type, size_t count) {
	if (!_active)
		return false;

	if (_mode == mode && _type == type) {
		_pos += count;
		if (_pos >= _count) {
			_pos = _count;
			return true;
		}
	}

	return false;
}

//For DlgDailyChallenge, DlgWeaklyChallenge...
const char* Challenge::getChallengeIcon() {
	if (_mode == CHALLENGE_MODE::BLOCK) { //for test
		if (_type == 0) return "image/play/balloonblue.png";
		else if (_type == 1) return "image/play/bomb.png";
		else if (_type == 2) return "image/play/boxnormal.png";
		else return "image/play/duck.png";
	}
	else if (_mode == CHALLENGE_MODE::USEITEM) { //for test
		if (_type == 0) return "image/playui/hammer.png";
		else if (_type == 1) return "image/playui/anvil.png";
		else if (_type == 2) return "image/playui/boxclub.png";
		else return "image/playui/dice.png";
	} 
	
	return "image/common/scorestar.png";
}

const char* Challenge::getChallengeString() {
	return "Get 10 Star.";
}

const char* Challenge::getBonusCount() {
	return __String::createWithFormat("x%d", _bonusCnt)->getCString();
}

const char* Challenge::getBonusIcon() {
	return g_bonusIcons[(size_t)_bonusType].c_str();
}

bool Challenge::isSuccess() {
	return (_active && _pos >= _count);
}

const char* Challenge::getStateString() {
	if (!_active)
		return "Closed";

	return __String::createWithFormat("%d/%d", _pos, _count)->getCString();
}

float Challenge::getStatePercent() {
	return ((float)_pos / _count);
}

/////////// DailyChallenge  ////////////
void DailyChallenge::serial(Configuration* config, bool bLoad) {
	std::string sPrefix = "DailyChallenge";
	if (bLoad) {
		_startTime = config->getValue(sPrefix + "_startTime", Value(0)).asInt();
	}
	else {
		config->setValue(sPrefix + "_startTime", Value(_startTime));
	}

	for (int nn = 0; nn < DAILY_CHALLENGE_CNT; nn++) {
		_challenges[nn].serial(config, Util::my_sprintf("%s%d", sPrefix.c_str(), nn), bLoad);
	}
}

void DailyChallenge::init() {
	CCLOG("### create new daily challenges.");

	_startTime = time(0);

	for (int nn = 0; nn < DAILY_CHALLENGE_CNT; nn++) {
		_challenges[nn]._mode = (CHALLENGE_MODE)(rand() % 3);
		_challenges[nn]._type = rand() % 4;
		_challenges[nn]._count = 10 + 5 * rand() % 5;

		_challenges[nn]._bonusType = (CHALLENGE_BONUS)(rand() % (int)CHALLENGE_BONUS::BONUS_COUNT);
		_challenges[nn]._bonusCnt = 1 + rand() % 3;

		_challenges[nn]._active = true;
	}
}

void DailyChallenge::notifyEvent(CHALLENGE_MODE mode, int type, int count) {
	for (int nn = 0; nn < DAILY_CHALLENGE_CNT; nn++)
		_challenges[nn].notifyEvent(mode, type, count);
}

bool DailyChallenge::isOpend() {
	for (int nn = 0; nn < DAILY_CHALLENGE_CNT; nn++)
		if (_challenges[nn].isSuccess())
			return true;
	return false;
}

std::string DailyChallenge::update() {
	time_t now = time(NULL);
	//tm* stt = localtime(&now);
	int currentTime = (int)now;

	int remainTime = (_startTime + 24 * 3600) - currentTime;
	if (remainTime < 0) {
		init(); 
		currentTime = _startTime;
		remainTime = (_startTime + 24 * 3600) - currentTime;
	}
	
	char szTime[50] = "";
	sprintf(szTime, "%02d:%02d:%02d", remainTime / 3600, (remainTime % 3600) / 60, (remainTime % 3600) % 60);
	std::string sRet = szTime;
	return sRet;
}

Challenge& DailyChallenge::getChallenge(int index) {
	CCASSERT(index >= 0 && index < DAILY_CHALLENGE_CNT, "Out of DailyChallenge index!!!");
	return _challenges[index];
}

/////////// WeaklyChallenge /////////////
void WeaklyChallenge::serial(Configuration* config, bool bLoad) {
	std::string sPrefix = "WeaklyChallenge";
	if (bLoad) {
		_startTime = config->getValue(sPrefix + "_startTime", Value(0)).asInt();
	}
	else {
		config->setValue(sPrefix + "_startTime", Value(_startTime));
	}

	for (int nn = 0; nn < WEAKLY_CHALLENGE_CNT; nn++) {
		_challenges[nn].serial(config, Util::my_sprintf("%s%d", sPrefix.c_str(), nn), bLoad);
	}
}

void WeaklyChallenge::init() {
	CCLOG("### create new Weakly Challenge!!!");
	_startTime = time(0);

	for (int nn = 0; nn < WEAKLY_CHALLENGE_CNT; nn++) {
		_challenges[nn]._mode = (CHALLENGE_MODE)(rand() % 3);
		_challenges[nn]._type = rand() % 4;
		_challenges[nn]._count = 5 + 5 * rand() % 5;
	}
}

void WeaklyChallenge::notifyEvent(CHALLENGE_MODE mode, int type, int count) {
	for (int nn = 0; nn < WEAKLY_CHALLENGE_CNT; nn++)
		_challenges[nn].notifyEvent(mode, type, count);
}

bool WeaklyChallenge::isOpend() {
	for (int nn = 0; nn < WEAKLY_CHALLENGE_CNT; nn++)
		if (_challenges[nn].isSuccess())
			return true;
	return false;
}

std::string WeaklyChallenge::update() {
	time_t now = time(NULL);
	//tm* stt = localtime(&now);
	int currentTime = (int)now;

	int remainTime = (_startTime + 24 * 3600) - currentTime;
	if (remainTime < 0) {
		init();
		currentTime = _startTime;
		remainTime = (_startTime + 24 * 3600) - currentTime;
	}

	char szTime[50] = "";
	sprintf(szTime, "%02d:%02d:%02d", remainTime / 3600, (remainTime % 3600) / 60, (remainTime % 3600) % 60);
	std::string sRet = szTime;
	return sRet;
}


/////////// ChallengeManager /////////////
void ChallengeManager::serial(Configuration* config, bool bLoad) {
	std::string sPrefix = "WeaklyChallenge";
	if (bLoad) {
		_tmLastTriger = config->getValue(sPrefix + "_tmLastTriger", Value(0)).asInt();
	}
	else {
		config->setValue(sPrefix + "_tmLastTriger", Value(_tmLastTriger));
	}

	dailyChallenge.serial(config, bLoad);
	weaklyChallenge.serial(config, bLoad);
}

void ChallengeManager::notifyEvent(CHALLENGE_MODE mode, int type, int count) {
	dailyChallenge.notifyEvent(mode, type, count);
	weaklyChallenge.notifyEvent(mode, type, count);
}