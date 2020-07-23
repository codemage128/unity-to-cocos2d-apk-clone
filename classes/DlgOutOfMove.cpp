#include "DlgOutOfMove.h"
#include "DlgBuyCoin.h"

#include "Common/Util.h"
#include "global/SoundManager.h"
#include "global/GameManager.h"

USING_NS_CC;
using namespace cocostudio::timeline;


DlgOutOfMove* DlgOutOfMove::createDlg(Node* parent, const closedCallback& callback, int zOrder) {
	DlgOutOfMove *pRet = new(std::nothrow) DlgOutOfMove();
	if (pRet && pRet->init(parent, callback, zOrder)) {
		pRet->autorelease();
	} else {
		delete pRet;
		pRet = nullptr;
	}

	return pRet;
}

bool DlgOutOfMove::init(Node* parent, const closedCallback& callback, int zOrder) {
	if (!Layer::init()) {
		return false;
	}

	_closeEventFunc = callback;
	_rootNode = CSLoader::createNode("dlgOutOfMove.csb");
	addChild(_rootNode);
	if (parent != nullptr)
		parent->addChild(this, zOrder);

	_timeline = CSLoader::createTimeline("dlgOutOfMove.csb");
	_timeline->setAnimationEndCallFunc("evtOut", CC_CALLBACK_0(DlgOutOfMove::onTimeLine_evtOut, this));
	_timeline->play("evtIn", false);
	_rootNode->runAction(_timeline);

	auto btnClose = Util::getChildNode<ui::Button*>(_rootNode, "root/btnClose", CC_CALLBACK_1(DlgOutOfMove::onBtnClose, this), nullptr);
	auto btnPlayOn = Util::getChildNode<ui::Button*>(_rootNode, "root/btnPlayOn", CC_CALLBACK_1(DlgOutOfMove::onBtnPlayOn, this), nullptr);
	Util::applyDefaultButtonPressFx(btnClose);
	Util::applyDefaultButtonPressFx(btnPlayOn);

	// add keyboard event listner
	auto keyboardListner = EventListenerKeyboard::create();
	keyboardListner->onKeyReleased = CC_CALLBACK_2(DlgOutOfMove::onKeyReleasedEvent, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListner, this);

	return true;
}

void DlgOutOfMove::onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) {
	if (keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		event->stopPropagation();
		onBtnClose(nullptr);
	}
}

void DlgOutOfMove::onBtnClose(Ref*) {
	_timeline->play("evtOut", false);
}

void DlgOutOfMove::onTimeLine_evtOut() {
	if (_closeEventFunc != nullptr)
		_closeEventFunc();

	removeFromParentAndCleanup(true);
}

void DlgOutOfMove::onBtnPlayOn(Ref*) {
	//TODO : 
	/*if (money > 100) {
		money -= 100;
		GM->plusLife(5);
	}
	else */ {
		DlgBuyCoin::createDlg(this->getParent(), CC_CALLBACK_0(DlgOutOfMove::onDlgBuyCoinEnd, this), 0);
		this->setVisible(false);
	}
}

void DlgOutOfMove::onDlgBuyCoinEnd() {
	this->setVisible(true);

	onTimeLine_evtOut();
}