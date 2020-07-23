#include "DlgBuyCoin.h"
#include "Common/Util.h"
#include "global/SoundManager.h"

USING_NS_CC;
using namespace cocostudio::timeline;


DlgBuyCoin* DlgBuyCoin::createDlg(Node* parent, const closedCallback& callback, int zOrder) {
	DlgBuyCoin *pRet = new(std::nothrow) DlgBuyCoin();
	if (pRet && pRet->init(parent, callback, zOrder)) {
		pRet->autorelease();
	} else {
		delete pRet;
		pRet = nullptr;
	}

	return pRet;
}

bool DlgBuyCoin::init(Node* parent, const closedCallback& callback, int zOrder) {
	if (!Layer::init()) {
		return false;
	}

	_closeEventFunc = callback;
	_rootNode = CSLoader::createNode("dlgBuyCoin.csb");
	addChild(_rootNode);
	if (parent != nullptr)
		parent->addChild(this, zOrder);

	_timeline = CSLoader::createTimeline("dlgBuyCoin.csb");
	_timeline->setAnimationEndCallFunc("evtOut", CC_CALLBACK_0(DlgBuyCoin::onTimeLine_evtOut, this));
	_timeline->play("evtIn", false);
	_rootNode->runAction(_timeline);

	auto btnClose = Util::getChildNode<ui::Button*>(_rootNode, "root/btnClose", CC_CALLBACK_1(DlgBuyCoin::onBtnClose, this), nullptr);
	auto btnCoin0 = Util::getChildNode<ui::Button*>(_rootNode, "root/imgMiddle/imgCoin0/btnCoin0", CC_CALLBACK_1(DlgBuyCoin::onBtnCoins, this), nullptr);
	auto btnCoin1 = Util::getChildNode<ui::Button*>(_rootNode, "root/imgMiddle/imgCoin1/btnCoin1", CC_CALLBACK_1(DlgBuyCoin::onBtnCoins, this), nullptr);
	auto btnCoin2 = Util::getChildNode<ui::Button*>(_rootNode, "root/imgMiddle/imgCoin2/btnCoin2", CC_CALLBACK_1(DlgBuyCoin::onBtnCoins, this), nullptr);
	auto btnCoin3 = Util::getChildNode<ui::Button*>(_rootNode, "root/imgMiddle/imgCoin3/btnCoin3", CC_CALLBACK_1(DlgBuyCoin::onBtnCoins, this), nullptr);
	auto btnCoin4 = Util::getChildNode<ui::Button*>(_rootNode, "root/imgMiddle/imgCoin4/btnCoin4", CC_CALLBACK_1(DlgBuyCoin::onBtnCoins, this), nullptr);
	auto btnCoin5 = Util::getChildNode<ui::Button*>(_rootNode, "root/imgMiddle/imgCoin5/btnCoin5", CC_CALLBACK_1(DlgBuyCoin::onBtnCoins, this), nullptr);
	
	Util::applyDefaultButtonPressFx(btnClose);
	Util::applyDefaultButtonPressFx(btnCoin0);
	Util::applyDefaultButtonPressFx(btnCoin1);
	Util::applyDefaultButtonPressFx(btnCoin2);
	Util::applyDefaultButtonPressFx(btnCoin3);
	Util::applyDefaultButtonPressFx(btnCoin4);
	Util::applyDefaultButtonPressFx(btnCoin5);

	// add keyboard event listner
	auto keyboardListner = EventListenerKeyboard::create();
	keyboardListner->onKeyReleased = CC_CALLBACK_2(DlgBuyCoin::onKeyReleasedEvent, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListner, this);

	return true;
}

void DlgBuyCoin::onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) {
	if (keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		event->stopPropagation();
		onBtnClose(nullptr);
	}
}

void DlgBuyCoin::onBtnClose(Ref*) {
	_timeline->play("evtOut", false);
}

void DlgBuyCoin::onTimeLine_evtOut() {
	if (_closeEventFunc != nullptr)
		_closeEventFunc();

	removeFromParentAndCleanup(true);
}

void DlgBuyCoin::onBtnCoins(Ref* sender) {
	auto btnCoin = dynamic_cast<ui::Button*>(sender);
	if (btnCoin == nullptr)
		return;

	int idx = atoi(&btnCoin->getName().back());
	CCLOG("### Coin Click: %d", idx);
	//TOTO
}