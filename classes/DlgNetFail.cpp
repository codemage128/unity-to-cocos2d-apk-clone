#include "DlgNetFail.h"
#include "common\Util.h"

USING_NS_CC;

using namespace cocostudio::timeline;


DlgNetFail* DlgNetFail::createDlg(Node* parent, const closedCallback& callback, int zorder) {
	DlgNetFail *pRet = new(std::nothrow) DlgNetFail();
	if(pRet && pRet->init(parent, callback, zorder)) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = nullptr;
		return nullptr;

	}
}
  
bool DlgNetFail::init(Node* parent, const closedCallback& callback, int zorder) {
	if(!Layer::init()) {
		return false;
	}
	rootNode = CSLoader::createNode("dlgNetFail.csb");

	action = CSLoader::createTimeline("dlgNetFail.csb");
	action->play("FlyIn", false);
	rootNode->runAction(action);
	 
	
	btnExit = Util::getChildNode<ui::Button*>(rootNode, "root/btn_close", CC_CALLBACK_1(DlgNetFail::onClick, this));
	btnAgain = Util::getChildNode<ui::Button*>(rootNode, "root/btn_again", CC_CALLBACK_1(DlgNetFail::onClick, this));
	 

	addChild(rootNode);

	_closedFunc = callback;
	if(parent != nullptr)
		parent->addChild(this, zorder);

	//add keyEventListener 
	auto keyboardListner = EventListenerKeyboard::create();
	keyboardListner->onKeyPressed = CC_CALLBACK_2(DlgNetFail::onKey, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListner, this);
	
	return true;
}

void DlgNetFail::onstart(Frame* frame) {
	EventFrame* evnt = dynamic_cast<EventFrame*>(frame);
	if(!evnt)
		return;
	std::string str = evnt->getEvent();
	if(str == "evt_finished") {
		//TODO Net fail
		this->removeFromParentAndCleanup(true);
	}
}

void DlgNetFail::onKey(EventKeyboard::KeyCode keycode, Event* _event) {
	if(keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		_event->stopPropagation();
		onExit();
	}
}
void DlgNetFail::onClick(Ref* ref) {
	ui::Button* btn = dynamic_cast<ui::Button*>(ref);
	int btnTag = btn->getTag();
	
	switch(btnTag) {
	case 320:
		onContinue();
		break;
	case 321:
		onExit();
		break;
	default:
		break;
	}

}

void DlgNetFail::onContinue() {
	//TODO RYR
}

void DlgNetFail::onExit() {
	if(action->isPlaying())
		return;
	action->play("FlyOut", false);
	rootNode->runAction(action);
}