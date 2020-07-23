#include "DlgAppQuit.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "common/Util.h"
#include "global/SoundManager.h"

USING_NS_CC;

using namespace cocostudio::timeline;

DlgAppQuit* DlgAppQuit::createDlg(Node* parent, const closedCallback& callback, int zOrder) {
	DlgAppQuit *pRet = new(std::nothrow) DlgAppQuit();
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

bool DlgAppQuit::init(Node* parent, const closedCallback& callback, int zOrder) {
	if(!Layer::init()) {
		return false;
	}

	rootNode = CSLoader::createNode("dlgAppQuit.csb");
	action = CSLoader::createTimeline("dlgAppQuit.csb");
	rootNode->runAction(action);
	action->play("FlyIn", false);
	addChild(rootNode);

	action->setFrameEventCallFunc(CC_CALLBACK_1(DlgAppQuit::onFrameEvent, this));

	if(parent != nullptr)
		parent->addChild(this, zOrder);
	_closeEventFunc = callback;

	ui::Button* btnQuit = Util::getChildNode<ui::Button*>(rootNode, "root/btn_quit", CC_CALLBACK_1(DlgAppQuit::onClick, this)); Util::applyDefaultButtonPressFx(btnQuit);
	ui::Button* btnClose = Util::getChildNode<ui::Button*>(rootNode, "root/btn_close", CC_CALLBACK_1(DlgAppQuit::onClick, this)); Util::applyDefaultButtonPressFx(btnClose);

	auto keyboardListner = EventListenerKeyboard::create();
	keyboardListner->onKeyReleased = CC_CALLBACK_2(DlgAppQuit::onKeyReleasedEvent, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListner, this);

	return true;
}

void DlgAppQuit::onClick(Ref* ref) {
	ui::Button* btn = dynamic_cast<ui::Button*>(ref);

	if(btn->getName() == "btn_quit") messageResult = Result::YES;
	if(btn->getName()=="btn_close") messageResult = Result::NO;

	closeDlg();
}

void DlgAppQuit::onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) {
	if(keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		event->stopPropagation();
		messageResult = Result::NO;
		closeDlg();
	}
}

void DlgAppQuit::onFrameEvent(cocostudio::timeline::Frame* frame) {
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

void DlgAppQuit::closeDlg() {
	if(action->isPlaying())
		return;
	action->play("FlyOut", false);
	rootNode->runAction(action);
}
