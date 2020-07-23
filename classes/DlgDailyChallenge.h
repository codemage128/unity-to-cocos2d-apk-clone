#ifndef __DLG_DAILYCHALLENGE_H__
#define __DLG_DAILYCHALLENGE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

#include "global/ChallengeManager.h"

class DailyChallengeButtonController
{
public:

};

class DlgDailyChallenge : public cocos2d::Layer
{
public:
	typedef std::function<void()> closedCallback;
	static DlgDailyChallenge* createDlg(Node* parent = nullptr, const closedCallback& callback = nullptr, int zOrder = 0);

protected:
	virtual bool init(Node* parent = nullptr, const closedCallback& callback = nullptr, int zOrder = 0);
	void onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);

	void onBtnClose(Ref*);
	void onTimeLine_evtOut();

	void onBtnChallenges(Ref*);

	void onStep(float dt);
	
private:
	cocos2d::Node* _rootNode;
	cocostudio::timeline::ActionTimeline* _timeline;
	closedCallback _closeEventFunc;

	//for ui control
	ui::Text*			_txtTime;
	ui::Button*			_btnChallenge[DAILY_CHALLENGE_CNT];

	ui::ImageView*		_imgCondIcon[DAILY_CHALLENGE_CNT];
	ui::Text*			_txtCond[DAILY_CHALLENGE_CNT];

	ui::ImageView*		_imgBonusIcon[DAILY_CHALLENGE_CNT];
	ParticleSystemQuad*	_patricleBonus[DAILY_CHALLENGE_CNT];
	ui::Text*			_txtBonusCnt[DAILY_CHALLENGE_CNT];

	ui::Text*			_txtProgress[DAILY_CHALLENGE_CNT];
	ui::LoadingBar*		_progress[DAILY_CHALLENGE_CNT];
};


#endif //__DLG_DAILYCHALLENGE_H__
