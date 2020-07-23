#ifndef __Dlg_LIFE_REFILL_H__
#define __Dlg_LIFE_REFILL_H__

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "ui/CocosGUI.h"

class DlgLifeRefill: public cocos2d::Layer {

public:
	enum class Result { YES, NO };

	typedef std::function<void(Result)> closedCallback;
	static DlgLifeRefill* createDlg(Node* parent = nullptr, const closedCallback& callback = nullptr, int zOrder = 0);

protected:
	virtual bool init(Node* parent = nullptr, const closedCallback& callback = nullptr, int zOrder = 0);
	void closeDlg();

private:
	cocos2d::Node* rootNode = nullptr;
	cocostudio::timeline::ActionTimeline* action = nullptr;
	Result messageResult=Result::NO;
	void onFrameEvent(cocostudio::timeline::Frame* frame);
	void onClick(Ref* ref);
	void onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);

	void onSecond(float dt);

	closedCallback _closeEventFunc = nullptr;

	cocos2d::ui::Text* _lifeCount = nullptr;
	cocos2d::ui::Text* _chargeTime = nullptr;
	cocos2d::ui::Text* _chargeFull = nullptr;
};

#endif //__Dlg_LIFE_REFILL_H__