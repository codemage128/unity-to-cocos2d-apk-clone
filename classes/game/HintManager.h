#ifndef __ENGINE_HINTMANAGER_H__
#define __ENGINE_HINTMANAGER_H__

#include <vector>

#include "cocos2d.h"

class Level;
class LevelBuilder;
class MatchGroup;
enum class MatchType;

typedef cocos2d::Action SharedShinyHintAnimation;
//class SharedShinyHintAnimation {
//public:
//	void StopAnimation() {}
//};

class HintManager {
private:
	static HintManager* _instance;
public:
	static HintManager* getInstance() { if(_instance == nullptr) _instance = new HintManager(); return _instance; }
	//static void ResetSelf() { if(_instance != nullptr) delete _instance; _instance = nullptr; }

	LevelBuilder* CurrentLevelBuilder = nullptr;

private:
	std::vector<SharedShinyHintAnimation*> _hintAnimations;
	std::vector<MatchGroup*> _allMatches;
	std::vector<MatchGroup*> _candidateHints;
	Level* _currentLevel = nullptr;
	bool _enabled = true;
	float _lastTimeHintDisplayed = 0.0f;
	bool _comboHintDisplayerEnabed = true;
	int _lastLostCheck = 0;
	bool _showGoalSpecificHints = false;
	std::vector<MatchType> GoalTypes;

public:
	void cleanUp();

	void SceneReloadedSetups();
	void UpdateGoalHints();
	void AddActiveHint(SharedShinyHintAnimation* sharedShinyHintAnimation);
	void RemoveActiveHint(SharedShinyHintAnimation* sharedShinyHintAnimation);
	void DisableHints() { this->_enabled = false; }
	void EnableHints() { this->_enabled = true; }
	void StopHintAnimations();
	void Update();

	void createHintAnimation(cocos2d::Sprite* spriteRenderer);
private:
	MatchGroup* FindANeededHint(int index, MatchGroup* randomGroup);
	bool ContainsCheck(MatchGroup* randomGroup);
public:
	void DisableComboHints();
	void StopSpecialItemMarks();
};

#endif //__ENGINE_HINTMANAGER_H__