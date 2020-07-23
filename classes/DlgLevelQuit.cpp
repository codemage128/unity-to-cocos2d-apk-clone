#include "DlgLevelQuit.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "common\Util.h"

USING_NS_CC;

using namespace cocostudio::timeline;

DlgLevelQuit* DlgLevelQuit::createDlg(Node* parent, const closedCallback& callback, int zOrder) {
	DlgLevelQuit *pRet = new(std::nothrow) DlgLevelQuit();
	if(pRet && pRet->init(parent, callback, zOrder)) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool DlgLevelQuit::init(Node* parent, const closedCallback& callback, int zOrder) {
	if(!Layer::init()) {
		return false;
	}

	rootNode = CSLoader::createNode("dlgLevelQuit.csb");
	action = CSLoader::createTimeline("dlgLevelQuit.csb");
	rootNode->runAction(action);
	action->play("FlyIn", false);

	_closeEventFunc = callback;
	addChild(rootNode);

	action->setFrameEventCallFunc(CC_CALLBACK_1(DlgLevelQuit::onFrameEvent, this));

	if(parent != nullptr)
		parent->addChild(this, zOrder);

	ui::Button* btnQuit = Util::getChildNode<ui::Button*>(rootNode, "root/btn_quit", CC_CALLBACK_1(DlgLevelQuit::onClick, this), CC_CALLBACK_2(DlgLevelQuit::onTouch, this));
	ui::Button* btnClose = Util::getChildNode<ui::Button*>(rootNode, "root/btn_close", CC_CALLBACK_1(DlgLevelQuit::onClick, this), CC_CALLBACK_2(DlgLevelQuit::onTouch, this));

	auto keyboardListner = EventListenerKeyboard::create();
	keyboardListner->onKeyReleased = CC_CALLBACK_2(DlgLevelQuit::onKeyReleasedEvent, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListner, this);

	return true;
}

void DlgLevelQuit::onTouch(Ref* ref, cocos2d::ui::Widget::TouchEventType touchevent) {
	ui::Widget* _Ref = dynamic_cast<ui::Widget*>(ref);

	switch(touchevent) {
	case ui::Widget::TouchEventType::BEGAN:
		_Ref->setScale(0.95f);
		break;
	case ui::Widget::TouchEventType::ENDED:
	case ui::Widget::TouchEventType::CANCELED:
		_Ref->setScale(1.0f);
		break;
	default:
		break;
	}
}

void DlgLevelQuit::onClick(Ref* ref) {
	ui::Button* btn = dynamic_cast<ui::Button*>(ref);
	int btnTag = btn->getTag();

	switch(btnTag) {
	case 320:
		messageResult = Result::YES;
		break;
	case 321:
		break;
		messageResult = Result::NO;
	default:
		break;
	}

	closeDlg();
}

void DlgLevelQuit::onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) {
	if(keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		event->stopPropagation();

		messageResult = Result::NO;
		closeDlg();
	}
}

void DlgLevelQuit::onFrameEvent(cocostudio::timeline::Frame* frame) {
	EventFrame* evnt = dynamic_cast<EventFrame*>(frame);
	if(!evnt)
		return;

	std::string str = evnt->getEvent();

	if(str == "evt_finished") {
		if(_closeEventFunc != nullptr)
			_closeEventFunc(messageResult);

		this->removeFromParentAndCleanup(true);
	}
}

void DlgLevelQuit::closeDlg() {
	if(action->isPlaying())
		return;
	action->play("FlyOut", false);
	rootNode->runAction(action);
}
