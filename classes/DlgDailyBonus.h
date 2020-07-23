#ifndef __DLG_DAILYBONUS_H__
#define __DLG_DAILYBONUS_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "cocostudio\CocoStudio.h"

class DlgDailyBonus : public cocos2d::Layer
{
public:
	typedef std::function<void()> closedCallback;
	static DlgDailyBonus* createDlg(Node* parent = nullptr, const closedCallback& callback = nullptr, int zOrder = 0);

protected:
	virtual bool init(Node* parent = nullptr, const closedCallback& callback = nullptr, int zOrder = 0);
	void onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onStep(float delta);

	void onTimeLine_evtOut();
	void onBtnClose(Ref*);
	void onBtnCollect(Ref*);

public:
	// get the current the daily bonus reward time...
	static std::string getDailyBonusTime();

protected:
	// daily bonus time init infomation set
	void initTimeInfo();

	// show the current the daily bonus reward time... if 'isCheckedDay' is true, process when press 'Collect' or 'Close' button for day check.
	void showDailyBonus(bool isCheckedDay = false, bool isCollect = false);													
	void getCheckedItem(int checkedIndex);

private:
	cocos2d::Node* _rootNode = nullptr;
	cocostudio::timeline::ActionTimeline* _timeline = nullptr;
	closedCallback _closeEventFunc;

	// if you press 'Collect' button for get Item, '_isCollect' is true
	// else if you press 'Close' button for day check without getting Item, false
	bool	_isCollect = false;												

};


#endif //__DLG_DAILYBONUS_H__
