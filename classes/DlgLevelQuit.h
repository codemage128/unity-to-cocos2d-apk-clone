#ifndef __Dlg_LEVEL_Quit_H__
#define __Dlg_LEVEL_Quit_H__

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "ui/CocosGUI.h"

class DlgLevelQuit: public cocos2d::Layer {

public:

	enum class Result { YES, NO };

	typedef std::function<void(Result)> closedCallback;
	static DlgLevelQuit* createDlg(Node* parent = nullptr, const closedCallback& callback = nullptr, int zOrder = 0);

protected:
	virtual bool init(Node* parent = nullptr, const closedCallback& callback = nullptr, int zOrder = 0);
	void closeDlg();

private:
	cocos2d::Node* rootNode;
	cocostudio::timeline::ActionTimeline* action;
	Result messageResult;
	void onFrameEvent(cocostudio::timeline::Frame* frame);
	void onTouch(Ref* ref, cocos2d::ui::Widget::TouchEventType touchevent);
	void onClick(Ref* ref);
	void onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);

	closedCallback _closeEventFunc;
};

#endif //__Dlg_LEVEL_Quit_H__