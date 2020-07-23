#ifndef __DLG_LEVEL_FAIL_H__
#define __DLG_LEVEL_FAIL_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocostudio::timeline;

class DlgLvlFail:public cocos2d::Layer {

public:
	typedef std::function<void()> closedCallback;
	static DlgLvlFail* createDlg(int lvl, cocos2d::Node* parent = nullptr, const closedCallback& callback = nullptr, int zorther = 0);
	virtual bool init(int lvl, cocos2d::Node* parent, const closedCallback& callback, int zorther);
private:
	cocos2d::Node* rootNode;
	cocos2d::ui::Text* txtLevel;
	cocos2d::ui::Button* btnAgain;
	cocos2d::ui::Button* btnExit;
	ActionTimeline* action;

	void onAgain();
	void onExit();

	void onstart(Frame* frame);
	void onKey(cocos2d::EventKeyboard::KeyCode, cocos2d::Event* _event);
	void onClick(cocos2d::Ref* ref);

	closedCallback _closedFunc;

};

#endif //__DLG_LEVEL_FAIL_H__