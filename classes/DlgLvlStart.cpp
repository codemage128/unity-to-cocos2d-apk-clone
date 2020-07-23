#include "DlgLvlStart.h"
#include "common/Util.h"
#include "global/GameManager.h"

USING_NS_CC;

DlgLvlStart* DlgLvlStart::createDlg(int lvl, int starCount, Node* parent, const closedCallback& callback, int zorder) {
	DlgLvlStart *pRet = new(std::nothrow) DlgLvlStart();
	if(pRet && pRet->init(lvl, starCount, parent, callback, zorder)) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool DlgLvlStart::init(int lvl, int starCount, Node* parent, const closedCallback& callback, int zorder) {
	if(!Layer::init()) {
		return false;
	}
	rootNode = CSLoader::createNode("dlgLevelStart.csb");
	action = CSLoader::createTimeline("dlgLevelStart.csb");
	action->setFrameEventCallFunc(CC_CALLBACK_1(DlgLvlStart::onstart, this));

	action->play("FlyIn", false);
	rootNode->runAction(action);

	txtLevel = Util::getChildNode<ui::Text*>(rootNode, "root/txt_lvl", nullptr);
	txtItemMc = Util::getChildNode<ui::Text*>(rootNode, "root/boosterslot1/txt_itemMc");
	txtItemBc = Util::getChildNode<ui::Text*>(rootNode, "root/boosterslot2/txt_itemBc");
	txtItemEc = Util::getChildNode<ui::Text*>(rootNode, "root/boosterslot3/txt_itemEc");
	btnExit = Util::getChildNode<ui::Button*>(rootNode, "root/btn_close", CC_CALLBACK_1(DlgLvlStart::onClick, this));
	btnPlay = Util::getChildNode<ui::Button*>(rootNode, "root/btn_play", CC_CALLBACK_1(DlgLvlStart::onClick, this));
	Util::applyDefaultButtonPressFx(btnPlay);
	Util::applyDefaultButtonPressFx(btnExit);
	
	       
	imgItemM = Util::getChildNode<ui::ImageView*>(rootNode, "root/boosterslot1/img_itemM");
	imgItemB = Util::getChildNode<ui::ImageView*>(rootNode, "root/boosterslot2/img_itemB");
	imgItemE = Util::getChildNode<ui::ImageView*>(rootNode, "root/boosterslot3/img_itemE");

	boosterM = Util::getChildNode<ui::ImageView*>(rootNode, "root/boosterslot1/booster1");
	boosterB = Util::getChildNode<ui::ImageView*>(rootNode, "root/boosterslot2/booster2");
	boosterE = Util::getChildNode<ui::ImageView*>(rootNode, "root/boosterslot3/booster3");

	/*boosterslotM = Util::getChildNode<ui::CheckBox*>(rootNode, "root/boosterslot1", CC_CALLBACK_2(DlgLvlStart::onCheck, this), nullptr);
	boosterslotB = Util::getChildNode<ui::CheckBox*>(rootNode, "root/boosterslot2", CC_CALLBACK_2(DlgLvlStart::onCheck, this), nullptr);
	boosterslotE = Util::getChildNode<ui::CheckBox*>(rootNode, "root/boosterslot3", CC_CALLBACK_2(DlgLvlStart::onCheck, this), nullptr);*/

	boosterslotM = dynamic_cast<ui::CheckBox*>(rootNode->getChildByName("root")->getChildByName("boosterslot1"));
	boosterslotB = dynamic_cast<ui::CheckBox*>(rootNode->getChildByName("root")->getChildByName("boosterslot2"));
	boosterslotE = dynamic_cast<ui::CheckBox*>(rootNode->getChildByName("root")->getChildByName("boosterslot3"));

	starl = dynamic_cast<Sprite*>(rootNode->getChildByName("root")->getChildByName("starl"));
	starc = dynamic_cast<Sprite*>(rootNode->getChildByName("root")->getChildByName("starc"));
	starr = dynamic_cast<Sprite*>(rootNode->getChildByName("root")->getChildByName("starr"));
	
	char level[8];
	sprintf(level, "%d", lvl);
	txtLevel->setString(level);
	
	boosterslotM->addEventListener(CC_CALLBACK_2(DlgLvlStart::onCheck, this));
	boosterslotB->addEventListener(CC_CALLBACK_2(DlgLvlStart::onCheck, this));
	boosterslotE->addEventListener(CC_CALLBACK_2(DlgLvlStart::onCheck, this));
	
	switch(starCount) {
	case 3:
		starr->setVisible(true);
	case 2:
		starc->setVisible(true);
	case 1:
		starl->setVisible(true);
	}

	addChild(rootNode);

	_closedFunc = callback;
	if(parent != nullptr)
		parent->addChild(this, zorder);

	//add keyEventListener 
	auto keyboardListner = EventListenerKeyboard::create();
	keyboardListner->onKeyPressed = CC_CALLBACK_2(DlgLvlStart::onKey, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListner, this);

	//init booster count
	int cntM = GM->getInvRocketCount();
	int cntB = GM->getInvBombCount();
	int cntD = GM->getInvDiscoCount();
	
	if(cntM < 1) {
		boosterslotM->setEnabled(false);
		boosterM->loadTexture("image/booster/boosterslotempty.png", ui::Widget::TextureResType::LOCAL);
		
		txtItemMc->setVisible(false);
	}

	if(cntB < 1) {
		boosterslotB->setEnabled(false);
		boosterB->loadTexture("image/booster/boosterslotempty.png", ui::Widget::TextureResType::LOCAL);
		txtItemBc->setVisible(false);
	} 

	if(cntD < 1) {
		boosterslotE->setEnabled(false);
		//imgItemE->load
		boosterE->loadTexture("image/booster/boosterslotempty.png", ui::Widget::TextureResType::LOCAL);
		txtItemEc->setVisible(false);
	}
	
	char M[8];
	sprintf(M, "%d", cntM);
	txtItemMc->setString(M);

	char B[8];
	sprintf(B, "%d", cntB);
	txtItemBc->setString(B);

	char D[8];
	sprintf(D, "%d", cntD);
	txtItemEc->setString(D);

	return true;
}

void DlgLvlStart::onstart(Frame* frame) {
	EventFrame* evnt = dynamic_cast<EventFrame*>(frame);
	if(!evnt)
		return;
	std::string str = evnt->getEvent();
	if(str == "evt_finished") {
		if(_closedFunc != nullptr)
			_closedFunc(_retValue);
		this->removeFromParentAndCleanup(true);
	}
}

void DlgLvlStart::onKey(EventKeyboard::KeyCode keycode, Event* _event) {
	if(keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		_event->stopPropagation();
		onExit();
	}
}

void DlgLvlStart::onClick(Ref* ref) {
	ui::Button* btn = dynamic_cast<ui::Button*>(ref);
	int btnTag = btn->getTag();
	
	switch(btnTag) {
	case 320:
		onPlay();
		break;
	case 321:
		onExit();
		break;
	}

}
void DlgLvlStart::onCheck(Ref* ref, ui::CheckBox::EventType type) {
	ui::Widget* widget = dynamic_cast<ui::Widget*>(ref);
	switch(type) {
	case cocos2d::ui::CheckBox::EventType::SELECTED:
		if(widget->getName() == "boosterslot1") {
			txtItemMc->setVisible(false);
			imgItemM->setVisible(true);
		}
		if(widget->getName() == "boosterslot2") {
			txtItemBc->setVisible(false);
			imgItemB->setVisible(true);
		}
		if(widget->getName() == "boosterslot3") {
			txtItemEc->setVisible(false);
			imgItemE->setVisible(true);
		}
		break;
	case cocos2d::ui::CheckBox::EventType::UNSELECTED:
		if(widget->getName() == "boosterslot1") {
			txtItemMc->setVisible(true);
			imgItemM->setVisible(false);
		}
		if(widget->getName() == "boosterslot2") {
			txtItemBc->setVisible(true);
			imgItemB->setVisible(false);
		}
		if(widget->getName() == "boosterslot3") {
			txtItemEc->setVisible(true);
			imgItemE->setVisible(false);
		}
		break;
	default:
		break;
	}
}

void DlgLvlStart::onPlay() {
	// prevent re-animation
	if(action->isPlaying())
		return;
	// set startup items
	GM->setLevelStartupItem(boosterslotM->isSelected(), boosterslotB->isSelected(), boosterslotE->isSelected());
	// set return value to ok, and show quit fx
	_retValue = CloseType::Start;
	action->play("FlyOut", false);
	rootNode->runAction(action);
}

void DlgLvlStart::onExit() {
	// prevent re-animation
	if(action->isPlaying())
		return;
	// set return value to cancel, and show quit fx
	_retValue = CloseType::Cancel;
	action->play("FlyOut", false);
	rootNode->runAction(action);
}