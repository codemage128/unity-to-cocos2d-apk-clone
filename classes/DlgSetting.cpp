#include "DlgSetting.h"
#include "Common/Util.h"
#include "global/SoundManager.h"

USING_NS_CC;
using namespace cocostudio::timeline;


DlgSetting* DlgSetting::createDlg(Node* parent, const closedCallback& callback, int zOrder) {
	DlgSetting *pRet = new(std::nothrow) DlgSetting();
	if (pRet && pRet->init(parent, callback, zOrder)) {
		pRet->autorelease();
	} else {
		delete pRet;
		pRet = nullptr;
	}

	return pRet;
}

bool DlgSetting::init(Node* parent, const closedCallback& callback, int zOrder) {
	if (!Layer::init()) {
		return false;
	}

	_closeEventFunc = callback;

	Util::loadCCSScene("dlgSetting.csb", _rootNode, _timeline, this);
	if (parent != nullptr)
		parent->addChild(this, zOrder);

	_timeline->setAnimationEndCallFunc("evtOut", CC_CALLBACK_0(DlgSetting::onTimeLine_evtOut, this));
	_timeline->play("evtIn", false);
	_rootNode->runAction(_timeline);

	auto btnClose = Util::getChildNode<ui::Button*>(_rootNode, "root/btnClose", CC_CALLBACK_1(DlgSetting::onBtnClose, this), nullptr);
	Util::applyDefaultButtonPressFx(btnClose);

	auto btnSupport = Util::getChildNode<ui::Button*>(_rootNode, "root/btnSupport", CC_CALLBACK_1(DlgSetting::onBtnSupport, this), nullptr);
	Util::applyDefaultButtonPressFx(btnSupport);

	ui::CheckBox* chkMusic = Util::getChildNode<ui::CheckBox*>(_rootNode, "root/spMusicSlot/chkMusic", CC_CALLBACK_1(DlgSetting::onChkMusic, this), nullptr);
	chkMusic->setSelected(!SoundManager::isBgMusicOn());
	ui::CheckBox* chkEffect = Util::getChildNode<ui::CheckBox*>(_rootNode, "root/spEffectSlot/chkEffect", CC_CALLBACK_1(DlgSetting::onChkEffect, this), nullptr);
	chkEffect->setSelected(!SoundManager::isEffectsOn());

	// add keyboard event listner
	auto keyboardListner = EventListenerKeyboard::create();
	keyboardListner->onKeyReleased = CC_CALLBACK_2(DlgSetting::onKeyReleasedEvent, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListner, this);

	return true;
}

void DlgSetting::onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) {
	if (keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		event->stopPropagation();
		onBtnClose(nullptr);
	}
}

void DlgSetting::onBtnClose(Ref*) {
	_timeline->play("evtOut", false);
}

void DlgSetting::onChkMusic(Ref*) {
	SoundManager::toggleBgMusicOn();
}

void DlgSetting::onChkEffect(Ref*) {
	SoundManager::toggleEffectsOn();
}

void DlgSetting::onTimeLine_evtOut() {
	if (_closeEventFunc != nullptr)
		_closeEventFunc();

	removeFromParentAndCleanup(true);
}

void DlgSetting::onBtnSupport(Ref*) {
	CCLOG("### DlgSetting::onBtnSupport");
}