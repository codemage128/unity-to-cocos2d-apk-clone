#include "DlgLifeRefill.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "common/Util.h"
#include "game/Extension.h"
#include "global/SoundManager.h"
#include "global/GameManager.h"

USING_NS_CC;

using namespace cocostudio::timeline;

DlgLifeRefill* DlgLifeRefill::createDlg(Node* parent, const closedCallback& callback, int zOrder) {
	DlgLifeRefill *pRet = new(std::nothrow) DlgLifeRefill();
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

bool DlgLifeRefill::init(Node* parent, const closedCallback& callback, int zOrder) {
	if(!Layer::init()) {
		return false;
	}

	rootNode = CSLoader::createNode("dlgRefill.csb");
	action = CSLoader::createTimeline("dlgRefill.csb");
	rootNode->runAction(action);
	action->play("flyIn", false);
	addChild(rootNode);

	action->setFrameEventCallFunc(CC_CALLBACK_1(DlgLifeRefill::onFrameEvent, this));

	if(parent != nullptr)
		parent->addChild(this, zOrder);
	_closeEventFunc = callback;

	ui::Button* btnRefill = Util::getChildNode<ui::Button*>(rootNode, "root/btn_refill", CC_CALLBACK_1(DlgLifeRefill::onClick, this)); Util::applyDefaultButtonPressFx(btnRefill);
	ui::Button* btnClose = Util::getChildNode<ui::Button*>(rootNode, "root/btn_close", CC_CALLBACK_1(DlgLifeRefill::onClick, this)); Util::applyDefaultButtonPressFx(btnClose);

	_lifeCount = Util::getChildNode<ui::Text*>(rootNode, "root/heart_count");
	_chargeTime = Util::getChildNode<ui::Text*>(rootNode, "root/time_count");
	_chargeFull = Util::getChildNode<ui::Text*>(rootNode, "root/time_count_1");

	auto keyboardListner = EventListenerKeyboard::create();
	keyboardListner->onKeyReleased = CC_CALLBACK_2(DlgLifeRefill::onKeyReleasedEvent, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListner, this);

	onSecond(0);
	schedule(CC_CALLBACK_1(DlgLifeRefill::onSecond, this), 1.0f, "onsecond");

	return true;
}

void DlgLifeRefill::onClick(Ref* ref) {
	ui::Button* btn = dynamic_cast<ui::Button*>(ref);

	if(btn->getName() == "btn_refill") messageResult = Result::YES;
	if(btn->getName()=="btn_close") messageResult = Result::NO;
	
	if(btn->getName() == "btn_refill") {
		if(GM->getLife() >= GM->getMaxLife()) return; // for this case dialog isn't closed
		if(GM->getCoin() < 100) return; // for this case dialog isn't closed
		GM->updateCoin(-100);
		GM->plusLife(GM->getMaxLife());
	}

	closeDlg();
}

void DlgLifeRefill::onSecond(float dt) {
	ui::Text* _levelselectscene_charge= Util::getChildNode<ui::Text*>(getParent(), "ui/energy_bar/lbl_time");
	_chargeTime->setVisible(GM->getLife() < GM->getMaxLife());
	_chargeFull->setVisible(GM->getLife() >= GM->getMaxLife());
	_lifeCount->setString(Ext_itos(GM->getLife()));
	_chargeTime->setString(_levelselectscene_charge->getString());
}

void DlgLifeRefill::onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) {
	if(keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		event->stopPropagation();
		messageResult = Result::NO;
		closeDlg();
	}
}

void DlgLifeRefill::onFrameEvent(cocostudio::timeline::Frame* frame) {
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

void DlgLifeRefill::closeDlg() {
	if(action->isPlaying())
		return;

	unschedule("onsecond");
	action->play("flyOut", false);
	rootNode->runAction(action);
}
