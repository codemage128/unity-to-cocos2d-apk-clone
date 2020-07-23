#ifndef __DLG_OUTOFMOVE_H__
#define __DLG_OUTOFMOVE_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "cocostudio\CocoStudio.h"

class DlgOutOfMove : public cocos2d::Layer
{
public:
	typedef std::function<void()> closedCallback;
	static DlgOutOfMove* createDlg(Node* parent = nullptr, const closedCallback& callback = nullptr, int zOrder = 0);

protected:
	virtual bool init(Node* parent = nullptr, const closedCallback& callback = nullptr, int zOrder = 0);
	void onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);

	void onBtnClose(Ref*);
	void onTimeLine_evtOut();

	void onBtnPlayOn(Ref*);
	void onDlgBuyCoinEnd();

private:
	cocos2d::Node* _rootNode;
	cocostudio::timeline::ActionTimeline* _timeline;
	closedCallback _closeEventFunc;
};


#endif //__DLG_OUTOFMOVE_H__
