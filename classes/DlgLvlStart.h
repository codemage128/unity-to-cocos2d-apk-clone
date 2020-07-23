#ifndef __DLG_LEVEL_START_H__
#define __DLG_LEVEL_START_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocostudio::timeline;

class DlgLvlStart:public cocos2d::Layer {
public:
	enum class CloseType {Start, Cancel};
	typedef std::function<void(CloseType)> closedCallback;

	static DlgLvlStart* createDlg(int lvl, int starCount,cocos2d::Node* parent = nullptr, const closedCallback& callback = nullptr, int zorder = 0);
	virtual bool init(int lvl, int starCount, cocos2d::Node* parent, const closedCallback& callback, int zorder);
private:
	cocos2d::Node* rootNode;
	cocos2d::ui::Text* txtLevel;
	cocos2d::ui::Button* btnPlay;
	cocos2d::ui::Button* btnExit;
	cocos2d::ui::Text* txtItemMc;
	cocos2d::ui::Text* txtItemBc;
	cocos2d::ui::Text* txtItemEc;
	cocos2d::ui::ImageView* imgItemM;
	cocos2d::ui::ImageView* imgItemB;
	cocos2d::ui::ImageView* imgItemE;
	cocos2d::ui::ImageView* boosterM;
	cocos2d::ui::ImageView* boosterB;
	cocos2d::ui::ImageView* boosterE;
	cocos2d::ui::CheckBox* boosterslotM;
	cocos2d::ui::CheckBox* boosterslotB;
	cocos2d::ui::CheckBox* boosterslotE;
	cocos2d::Sprite* starl;
	cocos2d::Sprite* starc;
	cocos2d::Sprite* starr;
	ActionTimeline* action;

	void onPlay();
	void onExit();
	void onHaveItem();

	void onstart(Frame* frame);
	void onKey(cocos2d::EventKeyboard::KeyCode, cocos2d::Event* _event);
	void onClick(cocos2d::Ref* ref);
	void onCheck(cocos2d::Ref* ref, cocos2d::ui::CheckBox::EventType type);

	CloseType _retValue;
	closedCallback _closedFunc;
};

#endif //__DLG_LEVEL_START_H__