#include "DlgDailyBonus.h"
#include "Common/Util.h"
#include "global/GameManager.h"
#include <time.h>

USING_NS_CC;
using namespace cocostudio::timeline;


DlgDailyBonus* DlgDailyBonus::createDlg(Node* parent, const closedCallback& callback, int zOrder) {
	DlgDailyBonus *pRet = new(std::nothrow) DlgDailyBonus();
	if (pRet && pRet->init(parent, callback, zOrder)) {
		pRet->autorelease();
	} else {
		delete pRet;
		pRet = nullptr;
	}

	return pRet;
}

bool DlgDailyBonus::init(Node* parent, const closedCallback& callback, int zOrder) {
	if (!Layer::init()) {
		return false;
	}

	_closeEventFunc = callback;
	_rootNode = CSLoader::createNode("dlgDailyBonus.csb");
	addChild(_rootNode);

	_timeline = CSLoader::createTimeline("dlgDailyBonus.csb");
	_timeline->setAnimationEndCallFunc("evtOut", CC_CALLBACK_0(DlgDailyBonus::onTimeLine_evtOut, this));
	_timeline->play("evtIn", false);

	cocostudio::timeline::ActionTimeline* timeline = CSLoader::createTimeline("fxShine.csb");
	_timeline->setAnimationEndCallFunc("evtOut", CC_CALLBACK_0(DlgDailyBonus::onTimeLine_evtOut, this));
	_timeline->play("evtIn", false);

	_rootNode->runAction(_timeline);

	auto btnClose = Util::getChildNode<ui::Button*>(_rootNode, "root/btnClose", CC_CALLBACK_1(DlgDailyBonus::onBtnClose, this), nullptr);
	auto btnCollect = Util::getChildNode<ui::Button*>(_rootNode, "root/btnCollect", CC_CALLBACK_1(DlgDailyBonus::onBtnCollect, this), nullptr);
	Util::applyDefaultButtonPressFx(btnClose);
	Util::applyDefaultButtonPressFx(btnCollect);

	if (parent != nullptr)
		parent->addChild(this, zOrder);

	// add keyboard event listner
	auto keyboardListner = EventListenerKeyboard::create();
	keyboardListner->onKeyReleased = CC_CALLBACK_2(DlgDailyBonus::onKeyReleasedEvent, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListner, this);

	initTimeInfo();

	return true;
}

void DlgDailyBonus::initTimeInfo() {

	_isCollect = false;
	showDailyBonus();
	schedule(CC_CALLBACK_1(DlgDailyBonus::onStep, this), 0.1f, CC_REPEAT_FOREVER, 0, "step_key");
}

std::string DlgDailyBonus::getDailyBonusTime() {

	time_t t;
	time(&t);
	tm* stt = localtime(&t);
	int curTime = (int)t;

	int checkedTime = GM->getDailyCheckedTime();

	if (checkedTime == 0) { // init
		checkedTime = curTime;
		GM->setDailyCheckedTime(checkedTime);
	}

	int ellapsed = curTime - checkedTime;

	if (ellapsed > 48 * 3600) {
		GM->setDailyCheckedTime(curTime);
		GM->setDailyCheckedCount(0);
		ellapsed = 0;
	}

	ellapsed = 24 * 3600 - ellapsed;

	if (ellapsed <= 0)
		return "";

	char string[20];
	sprintf(string, "%02d:%02d:%02d", ellapsed / 3600, (ellapsed % 3600) / 60, (ellapsed % 3600) % 60);
	return string;
}

void DlgDailyBonus::showDailyBonus(bool isCheckedDay, bool isCollect) {

	time_t t;
	time(&t);
	tm* stt = localtime(&t);
	int curTime = (int)t;

	int checkedTime = GM->getDailyCheckedTime();

	if (checkedTime == 0) { // init
		checkedTime = curTime;
		GM->setDailyCheckedTime(checkedTime);
	}

	int checkedCount = GM->getDailyCheckedCount();

	int ellapsed = curTime - checkedTime;

	if (ellapsed > 48 * 3600) {

		checkedTime = curTime;
		GM->setDailyCheckedTime(checkedTime);

		checkedCount = 0;
		GM->setDailyCheckedCount(checkedCount);

		ellapsed = 0;
	}
	else if (ellapsed > 24 * 3600) {

		if (isCheckedDay) {

			if (isCollect)
				getCheckedItem(checkedCount);

			checkedTime = curTime;
			GM->setDailyCheckedTime(checkedTime);

			checkedCount++;
			if (checkedCount > 20)
				checkedCount = 1;
			GM->setDailyCheckedCount(checkedCount);
		}
	}

	ellapsed = 24 * 3600 - ellapsed;
	if (ellapsed < 0) ellapsed = 0;

	char string[20], string1[20];
	sprintf(string, "%02d:%02d:%02d", ellapsed / 3600, (ellapsed % 3600) / 60, (ellapsed % 3600) % 60);

	if (!isCheckedDay) {

		cocos2d::ui::Text* text_day_reward = (ui::Text*) _rootNode->getChildByName("root")->getChildByName("content")->getChildByName("text_next_reward");

		if (text_day_reward)
			text_day_reward->setString(string);

		cocos2d::ui::CheckBox* checkDay = nullptr;
		cocos2d::ui::Layout* checkItem = nullptr;

		for (int i = 0; i < 20; i++) {

			sprintf(string, "list%d", i / 5 + 1);
			sprintf(string1, "check_day%d", i + 1);

			checkDay = (ui::CheckBox*)_rootNode->getChildByName("root")->getChildByName("content")->getChildByName("list_daily")->getChildByName(string)->getChildByName(string1);

			if (checkDay) {
				sprintf(string1, "check_item%d", i + 1);
				checkItem = (ui::Layout*)checkDay->getChildByName(string1);
			}

			if (i < checkedCount) {
				if (checkDay) {
					if (!checkDay->isSelected())
						checkDay->setSelected(true);
					if (checkDay->isEnabled())
						checkDay->setEnabled(false);
					if (checkItem && checkItem->isVisible())
						checkItem->setVisible(false);
				}
			}
			else if (i == checkedCount && ellapsed == 0) {
				if (checkDay) {
					if (!checkDay->isSelected())
						checkDay->setSelected(true);
					if (!checkDay->isEnabled())
						checkDay->setEnabled(true);
					if (checkItem && !checkItem->isVisible())
						checkItem->setVisible(true);
				}
			}
			else {
				if (checkDay) {
					if (checkDay->isSelected())
						checkDay->setSelected(false);
					if (!checkDay->isEnabled())
						checkDay->setEnabled(true);
					if (checkItem && !checkItem->isVisible())
						checkItem->setVisible(true);
				}
			}

			checkDay = nullptr;
			checkItem = nullptr;
		}
	}
}

void DlgDailyBonus::getCheckedItem(int checkedIndex) {

	// get the given Item action

	if (checkedIndex <= 0)
		return;

	switch (checkedIndex)
	{
	case 1:
		GM->updateCoin(15);
		break;
	case 2:
		GM->updateCoin(20);
		break;
	case 3:
		GM->updateCoin(25);
		break;
	case 4:
		GM->updateCoin(30);
		break;
	case 5:
		GM->updateCoin(35);
		break;
	case 6:
		GM->updateCoin(40);
		break;
	case 7:
		GM->updateCoin(45);
		break;
	case 8:
		GM->updateInvRocketCount(1);
		break;
	case 9:
		GM->updateInvRocketCount(1);
		break;
	case 10:
		GM->updateInvRocketCount(2);
		break;
	case 11:
		GM->updateInvRocketCount(2);
		break;
	case 12:
		GM->updateInvRocketCount(3);
		break;
	case 13:
		GM->updateInvRocketCount(3);
		break;
	case 14:
		GM->updateInvBombCount(1);
		break;
	case 15:
		GM->updateInvBombCount(2);
		break;
	case 16:
		GM->updateInvBombCount(3);
		break;
	case 17:
		GM->updateBoosterHammerCount(1);
		break;
	case 18:
		GM->updateBoosterBoxingCount(1);
		break;
	case 19:
		GM->updateBoosterAnvilCount(1);
		break;
	case 20:
		GM->updateBoosterShuffleCount(1);
		break;
	default:
		break;
	}
}

void DlgDailyBonus::onStep(float delta) {

	showDailyBonus();
}

void DlgDailyBonus::onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) {
	if (keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		event->stopPropagation();
		onBtnClose(nullptr);
	}
}

void DlgDailyBonus::onTimeLine_evtOut() {
	if (_closeEventFunc != nullptr)
		_closeEventFunc();

	removeFromParentAndCleanup(true);
}

void DlgDailyBonus::onBtnCollect(Ref* sender) {
	auto btnCollect = dynamic_cast<ui::Button*>(sender);
	if (btnCollect == nullptr)
		return;

	_isCollect = true;
	showDailyBonus(true, true);
}

void DlgDailyBonus::onBtnClose(Ref*) {

	if (!_isCollect) {
		showDailyBonus(true, false);
		_isCollect = false;
	}

	_timeline->play("evtOut", false);
}
