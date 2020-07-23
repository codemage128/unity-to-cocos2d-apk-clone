#include "DlgLvlFail.h"
#include "common/Util.h"

USING_NS_CC;

using namespace cocostudio::timeline;


DlgLvlFail* DlgLvlFail::createDlg(int lvl, Node* parent, const closedCallback& callback, int zorther) {
	DlgLvlFail *pRet = new(std::nothrow) DlgLvlFail();
	if(pRet && pRet->init(lvl, parent, callback, zorther)) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = nullptr;
		return nullptr;

	}
}
  
bool DlgLvlFail::init(int lvl, Node* parent, const closedCallback& callback, int zorther) {
	if(!Layer::init()) {
		return false;
	}
	rootNode = CSLoader::createNode("dlgLevelFail.csb");

	action = CSLoader::createTimeline("dlgLevelFail.csb");
	action->play("FlyIn", false);
	rootNode->runAction(action);
	 
	txtLevel = Util::getChildNode<ui::Text*>(rootNode, "root/txt_lvl", nullptr);
	

	btnExit = Util::getChildNode<ui::Button*>(rootNode, "root/btn_close", CC_CALLBACK_1(DlgLvlFail::onClick, this));
	btnAgain = Util::getChildNode<ui::Button*>(rootNode, "root/btn_again", CC_CALLBACK_1(DlgLvlFail::onClick, this));
	 
	Util::applyDefaultButtonPressFx(btnAgain);
	Util::applyDefaultButtonPressFx(btnExit);
	
	char level[8];
	sprintf(level, "%d", lvl);
	txtLevel->setString(level);

	addChild(rootNode);


	_closedFunc = callback;
	if(parent != nullptr)
		parent->addChild(this, zorther);

	//add keyEventListener 
	auto keyboardListner = EventListenerKeyboard::create();
	keyboardListner->onKeyPressed = CC_CALLBACK_2(DlgLvlFail::onKey, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListner, this);

	return true;
}
void DlgLvlFail::onstart(Frame* frame) {
	EventFrame* evnt = dynamic_cast<EventFrame*>(frame);
	if(!evnt)
		return;
	std::string str = evnt->getEvent();
	if(str == "evt_finished") {
		//TODO level start 
		this->removeFromParentAndCleanup(true);
	}
}

void DlgLvlFail::onKey(EventKeyboard::KeyCode keycode, Event* _event) {
	if(keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		_event->stopPropagation();
		onExit();
	}
}
void DlgLvlFail::onClick(Ref* ref) {
	ui::Button* btn = dynamic_cast<ui::Button*>(ref);
	int btnTag = btn->getTag();

	switch(btnTag) {
	case 320:
		onAgain();
		break;
	case 321://Button exit
		onExit();
		break;
	default:
		break;
	}

}

void DlgLvlFail::onAgain() {
	//TODO Fail operation
}

void DlgLvlFail::onExit() {
	if(action->isPlaying())
		return;
	action->play("FlyOut", false);
	rootNode->runAction(action);
}