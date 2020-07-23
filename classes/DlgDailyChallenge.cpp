#include "DlgDailyChallenge.h"
#include "Common/Util.h"
#include "global/SoundManager.h"

USING_NS_CC;
using namespace cocostudio::timeline;


DlgDailyChallenge* DlgDailyChallenge::createDlg(Node* parent, const closedCallback& callback, int zOrder) {
	DlgDailyChallenge *pRet = new(std::nothrow) DlgDailyChallenge();
	if (pRet && pRet->init(parent, callback, zOrder)) {
		pRet->autorelease();
	} else {
		delete pRet;
		pRet = nullptr;
	}

	return pRet;
}

bool DlgDailyChallenge::init(Node* parent, const closedCallback& callback, int zOrder) {
	if (!Layer::init()) {
		return false;
	}

	_closeEventFunc = callback;
	_rootNode = CSLoader::createNode("dlgDailyChallenge.csb");
	addChild(_rootNode);
	if (parent != nullptr)
		parent->addChild(this, zOrder);

	_timeline = CSLoader::createTimeline("dlgDailyChallenge.csb");
	_timeline->setAnimationEndCallFunc("evtOut", CC_CALLBACK_0(DlgDailyChallenge::onTimeLine_evtOut, this));
	_timeline->play("evtIn", false);
	_rootNode->runAction(_timeline);

	auto btnClose = Util::getChildNode<ui::Button*>(_rootNode, "root/btnClose", CC_CALLBACK_1(DlgDailyChallenge::onBtnClose, this), nullptr);
	auto btnContinue = Util::getChildNode<ui::Button*>(_rootNode, "root/btnContinue", CC_CALLBACK_1(DlgDailyChallenge::onBtnClose, this), nullptr);
	Util::applyDefaultButtonPressFx(btnClose);
	Util::applyDefaultButtonPressFx(btnContinue);

	_txtTime = Util::getChildNode<ui::Text*>(_rootNode, "root/imgMiddle/panelTime/txtTime");

	for (int nn = 0; nn < DAILY_CHALLENGE_CNT; nn++) {
		_btnChallenge[nn] = Util::getChildNode<ui::Button*>(_rootNode, Util::my_sprintf("root/imgMiddle/btnChallenge%d", nn), CC_CALLBACK_1(DlgDailyChallenge::onBtnChallenges, this));
		Util::applyDefaultButtonPressFx(_btnChallenge[nn]);

		_imgCondIcon[nn] = Util::getChildNode<ui::ImageView*>(_rootNode, Util::my_sprintf("root/imgMiddle/btnChallenge%d/iconChallenge", nn));
		_txtCond[nn] = Util::getChildNode<ui::Text*>(_rootNode, Util::my_sprintf("root/imgMiddle/btnChallenge%d/panelTop/txtChallenge", nn));
		
		_imgBonusIcon[nn] = Util::getChildNode<ui::ImageView*>(_rootNode, Util::my_sprintf("root/imgMiddle/btnChallenge%d/panelBottom/iconBonus", nn));
		_patricleBonus[nn] = dynamic_cast<ParticleSystemQuad*>(_imgBonusIcon[nn]->getChildByName("particleBonus"));
		_txtBonusCnt[nn] = Util::getChildNode<ui::Text*>(_rootNode, Util::my_sprintf("root/imgMiddle/btnChallenge%d/panelBottom/panelBonusMul/txtBonusMul", nn));

		_txtProgress[nn] = Util::getChildNode<ui::Text*>(_rootNode, Util::my_sprintf("root/imgMiddle/btnChallenge%d/panelBottom/panelProgress/txtProgress", nn));
		_progress[nn] = Util::getChildNode<ui::LoadingBar*>(_rootNode, Util::my_sprintf("root/imgMiddle/btnChallenge%d/panelBottom/panelProgress/progress", nn));
	}

	
	// add keyboard event listner
	auto keyboardListner = EventListenerKeyboard::create();
	keyboardListner->onKeyReleased = CC_CALLBACK_2(DlgDailyChallenge::onKeyReleasedEvent, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListner, this);

	schedule(CC_CALLBACK_1(DlgDailyChallenge::onStep, this), 1.0f, "DlgDailyChallenge_onStep");
	onStep(0.0f);

	return true;
}

void DlgDailyChallenge::onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) {
	if (keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		event->stopPropagation();
		onBtnClose(nullptr);
	}
}

void DlgDailyChallenge::onBtnClose(Ref*) {
	_timeline->play("evtOut", false);
}

void DlgDailyChallenge::onTimeLine_evtOut() {
	unschedule("DlgDailyChallenge_onStep");

	if (_closeEventFunc != nullptr)
		_closeEventFunc();

	removeFromParentAndCleanup(true);
}

void DlgDailyChallenge::onBtnChallenges(Ref* sender) {
	auto btnCoin = dynamic_cast<ui::Button*>(sender);
	if (btnCoin == nullptr)
		return;

	int idx = atoi(&btnCoin->getName().back());
	CCLOG("### onBtnChallenges: %d", idx);
	//TOTO
}

void DlgDailyChallenge::onStep(float dt) {
	_txtTime->setString(CHM->dailyChallenge.update());

	for (int nn = 0; nn < DAILY_CHALLENGE_CNT; nn++) {
		Challenge& challenge = CHM->dailyChallenge.getChallenge(nn);
		_imgCondIcon[nn]->loadTexture(challenge.getChallengeIcon());
		_txtCond[nn]->setString(challenge.getChallengeString());

		_imgBonusIcon[nn]->loadTexture(challenge.getBonusIcon());
		_txtBonusCnt[nn]->setString(challenge.getBonusCount());

		_txtProgress[nn]->setString(challenge.getStateString());
		_progress[nn]->setPercent(challenge.getStatePercent());

		if ( challenge.isSuccess()) {
			_btnChallenge[nn]->setEnabled(true);
			_patricleBonus[nn]->setVisible(true);
		}
		else {
			_btnChallenge[nn]->setEnabled(false);
			_patricleBonus[nn]->setVisible(false);
		}
	}
}
