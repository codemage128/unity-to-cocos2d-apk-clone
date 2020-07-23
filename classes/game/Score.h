#ifndef __ENGINe_SCORE_H_
#define __ENGINe_SCORE_H_

#include "Match.h"

#include <vector>
#include "cocos2d.h"

#define SCORE_ZORDER_ONSCENEROOT 20

//class Score {
//public:
//	std::vector<cocos2d::Sprite*> Digits;
//
//	cocos2d::Node* SpritesContainer = nullptr;
//
//	void StartAnimation();
//};

class Level;

class ScoreManager {
private:
	int _currentScore = 0;
	//std::vector<std::vector<cocos2d::Sprite*>> _matchOrderOfDigits;
	Level* CurrentLevel = nullptr;
	static ScoreManager* _instance;

public:
	static ScoreManager* getInstance() { if(_instance == nullptr) _instance = new ScoreManager; return _instance; }
	void cleanUp();
	
	//CaravanTopPanel CurrentTopPanel;
	//cocos2d::Node* ScorePrefab = nullptr;

	//std::vector<cocos2d::Sprite*> BlueDigits;
	//std::vector<cocos2d::Sprite*> GreenDigits;
	//std::vector<cocos2d::Sprite*> OrangeDigits;
	//std::vector<cocos2d::Sprite*> PurpleDigits;
	//std::vector<cocos2d::Sprite*> RedDigits;
	//std::vector<cocos2d::Sprite*> YellowDigits;
	//std::vector<cocos2d::Sprite*> WhiteDigits;

	int get_CurrentScore() { return this->_currentScore; }
	void set_CurrentScore(int value);

	static int get_Score() { return ScoreManager::getInstance()->get_CurrentScore(); }

	//void Awake();
	static void RaiseScore(int score, cocos2d::Vec2 pos, MatchType mType = MatchType::None);
	static void RaiseSudden(int score);
	//static void PopulateSharedArray(int value);
	void SceneReloadedSetups(Level* level);
};

#endif //__ENGINe_SCORE_H_