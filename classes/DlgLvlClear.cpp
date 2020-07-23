#include "DlgLvlClear.h"
#include "common/Util.h"
#include "game/Extension.h"
#include "game/LevelBuilder.h"
#include "game/Level.h"
#include "game/ImageLibrary.h"
#include "game/Goal.h"
#include "global/GameManager.h"

USING_NS_CC;

using namespace cocostudio::timeline;


DlgLvlClear* DlgLvlClear::createDlg(int lvl, int score, int starCount, ui::Widget* goalList, Node* parent, const closedCallback& callback, int zorder) {
	DlgLvlClear *pRet = new(std::nothrow) DlgLvlClear();
	if(pRet && pRet->init(lvl, score, starCount, goalList, parent, callback, zorder)) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = nullptr;
		return nullptr;

	}
}
  
bool DlgLvlClear::init(int lvl, int score, int starCount, ui::Widget* goalList, Node* parent, const closedCallback& callback, int zorder) {
	if(!Layer::init()) {
		return false;
	}

	// update inventory only first pass special level
	if(GM->getTopLevel() <= lvl) {
		if(lvl == 9) { GM->setBoosterHammerUseable(); GM->updateBoosterHammerCount(4); }
		if(lvl == 12) { GM->setBoosterBoxingUseable(); GM->updateBoosterBoxingCount(4); }
		if(lvl == 16) { GM->setBoosterAnvilUseable(); GM->updateBoosterAnvilCount(4); }
		if(lvl == 19) { GM->setBoosterShuffleUseable(); GM->updateBoosterShuffleCount(4); }
		if(lvl == 6) { GM->updateInvBombCount(3); GM->updateInvRocketCount(3); GM->updateInvDiscoCount(3); }
		GM->setTopLevel(lvl + 1);
	}

	rootNode = CSLoader::createNode("dlgLevelClear.csb");

	rootNodeAction = CSLoader::createTimeline("dlgLevelClear.csb");
	
	rootNodeAction->play("FlyIn", false);
	rootNodeAction->setAnimationEndCallFunc("FlyIn", [=]() { rootNodeAction->play("anim", false); });
	rootNodeAction->setFrameEventCallFunc(CC_CALLBACK_1(DlgLvlClear::on_Frame, this));
	rootNodeAction->setAnimationEndCallFunc("anim", [=]() { rootNodeAction->play("Idle", true); });
	rootNodeAction->setAnimationEndCallFunc("FlyOut", CC_CALLBACK_0(DlgLvlClear::onFlyOutEnd, this));
	
	rootNode->runAction(rootNodeAction);
	 
	txtLevel = Util::getChildNode<ui::Text*>(rootNode, "root/txt_lvl", nullptr);
	txtScore = Util::getChildNode<ui::Text*>(rootNode, "root/txt_score", nullptr);
	txtLevel->setString(Ext_itos(lvl));
	txtScore->setString(Ext_itos(score));
	 
	Util::applyDefaultButtonPressFx(Util::getChildNode<ui::Button*>(rootNode, "root/btn_continue", CC_CALLBACK_1(DlgLvlClear::onClick, this)));
	Util::applyDefaultButtonPressFx(Util::getChildNode<ui::Button*>(rootNode, "root/btn_close", CC_CALLBACK_1(DlgLvlClear::onClick, this)));
	
	starl = dynamic_cast<Node*>(rootNode->getChildByName("root")->getChildByName("starl")); starl->setVisible(false);
	starc = dynamic_cast<Node*>(rootNode->getChildByName("root")->getChildByName("starc")); starc->setVisible(false);
	starr = dynamic_cast<Node*>(rootNode->getChildByName("root")->getChildByName("starr")); starr->setVisible(false);
	
	starlslot = Util::getChildNode<Sprite*>(rootNode, "root/starl_slot");
	starcslot = Util::getChildNode<Sprite*>(rootNode, "root/starc_slot");
	starrslot = Util::getChildNode<Sprite*>(rootNode, "root/starr_slot");
	
	paticlel = Util::getChildNode<ParticleSystemQuad*>(rootNode, "root/Particlel");
	paticler = Util::getChildNode<ParticleSystemQuad*>(rootNode, "root/Particler");
	paticlec = Util::getChildNode<ParticleSystemQuad*>(rootNode, "root/Particlec");
	paticlel->stopSystem();
	paticler->stopSystem();
	paticlec->stopSystem();
	paticlel->setVisible(false);
	paticler->setVisible(false);
	paticlec->setVisible(false);
	
	switch(starCount) {
	case 3: starr->setVisible(true);
		paticler->setVisible(true);
	case 2: starc->setVisible(true);
		paticlec->setVisible(true);
	case 1: starl->setVisible(true);
		paticlel->setVisible(true);
		break;
	}
		
	ui::Widget* clonedgoals = goalList->clone();
	clonedgoals->setPosition(Vec2(0, 0));
	clonedgoals->setScale(1.6f);
	rootNode->getChildByName("root")->getChildByName("goal")->addChild(clonedgoals);

	addChild(rootNode);

	_closedFunc = callback;
	if(parent != nullptr)
		parent->addChild(this, zorder);

	//add keyEventListener 
	auto keyboardListner = EventListenerKeyboard::create();
	keyboardListner->onKeyPressed = CC_CALLBACK_2(DlgLvlClear::onKey, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListner, this);
		
	return true;
}

void DlgLvlClear::on_Frame(Frame* frame) {
	EventFrame* evt = dynamic_cast<EventFrame*>(frame);
	if(!evt)
		return;
	std::string str = evt->getEvent();

	if(str == "starl") {
		paticlel->resetSystem();
	}
	if(str == "starr") {
		paticler->resetSystem();
	}
	if(str == "starc") {
		paticlec->resetSystem();
	}
}

void DlgLvlClear::onFlyOutEnd() {
	if (_closedFunc != nullptr)
		_closedFunc(closetype);

	this->removeFromParentAndCleanup(true);
}

void DlgLvlClear::onKey(EventKeyboard::KeyCode keycode, Event* _event) {
	if(keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		_event->stopPropagation();
		onClose();
	}
}
void DlgLvlClear::onClick(Ref* ref) {
	ui::Button* btn = dynamic_cast<ui::Button*>(ref);
	int btnTag = btn->getTag();
	switch(btnTag) {
	case 320: closetype = DlgLvlClear::CloseType::Continue; break;
	case 321: closetype = DlgLvlClear::CloseType::Close; break;
	}
	onClose();
}

void DlgLvlClear::onClose() {
	// prevent reshow close animation
	if(rootNodeAction->isPlaying() && rootNodeAction->getCurrentFrame() >= rootNodeAction->getAnimationInfo("FlyOut").startIndex && rootNodeAction->getCurrentFrame() <= rootNodeAction->getAnimationInfo("FlyOut").endIndex)
		return;
	
	rootNodeAction->stop();
	rootNodeAction->play("FlyOut", false);
	rootNode->runAction(rootNodeAction);
}
