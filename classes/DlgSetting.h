#ifndef __DLG_SETTING_H__
#define __DLG_SETTING_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "cocostudio\CocoStudio.h"

class DlgSetting : public cocos2d::Layer
{
public:
	typedef std::function<void()> closedCallback;
	static DlgSetting* createDlg(Node* parent = nullptr, const closedCallback& callback = nullptr, int zOrder = 0);

protected:
	virtual bool init(Node* parent = nullptr, const closedCallback& callback = nullptr, int zOrder = 0);
	void onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	
	void onBtnClose(Ref*);
	void onTimeLine_evtOut();

	void onChkMusic(Ref*);
	void onChkEffect(Ref*);

	void onBtnSupport(Ref*);

private:
	cocos2d::Node* _rootNode;
	cocostudio::timeline::ActionTimeline* _timeline;
	closedCallback _closeEventFunc;
};


#endif //__DLG_SETTING_H__
