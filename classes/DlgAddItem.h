#ifndef __DLG_ADD_ITEM_H__
#define __DLG_ADD_ITEM_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "cocostudio\CocoStudio.h"

class DlgAddItem: public cocos2d::Layer {
public:

	enum class ItemType { HAMMER, BOXINGGLOVE, ANVIL, DICE };
	enum class Result{YES, NO};

	typedef std::function<void(ItemType, Result)> closedCallback;
	static DlgAddItem* createDlg(ItemType item, Node* parent = nullptr, const closedCallback& callback = nullptr, int zOrder = 0);

protected:
	virtual bool init(ItemType item, Node* parent = nullptr, const closedCallback& callback = nullptr, int zOrder = 0);
	void closeDlg();

private:
	ItemType itemType;
	Result msgResult;

	void onClick(Ref* ref);
	void onFrameEvent(cocostudio::timeline::Frame* frame);
	void onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	cocos2d::Node* rootNode;
	cocostudio::timeline::ActionTimeline* action;

	closedCallback _closeEventFunc;

};

#endif // __DLG_ADD_ITEM_H__
