#include "DlgAddItem.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "common\Util.h"

USING_NS_CC;

using namespace cocostudio::timeline;

DlgAddItem* DlgAddItem::createDlg(ItemType item, Node* parent, const closedCallback& callback, int zOrder) {
	DlgAddItem *pRet = new(std::nothrow) DlgAddItem();
	if(pRet && pRet->init(item, parent, callback, zOrder)) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool DlgAddItem::init(ItemType item, Node* parent, const closedCallback& callback, int zOrder) {
	if(!Layer::init()) {
		return false;
	}

	rootNode = CSLoader::createNode("dlgAddItem.csb");
	action = CSLoader::createTimeline("dlgAddItem.csb");
	rootNode->runAction(action);
	action->play("FlyIn", false);
	addChild(rootNode);

	char string[10] = { 0 };
	cocos2d::Node* itemNode;
	switch(item) {
	case DlgAddItem::ItemType::HAMMER:
		itemNode = Util::getChildNode<Node*>(rootNode, "root/HammerNode");
		sprintf(string, "200");
		break;
	case DlgAddItem::ItemType::BOXINGGLOVE:
		itemNode = Util::getChildNode<Node*>(rootNode, "root/BoxingGloveNode");
		sprintf(string, "400");
		break;
	case DlgAddItem::ItemType::ANVIL:
		itemNode = Util::getChildNode<Node*>(rootNode, "root/AnvilNode");
		sprintf(string, "400");
		break;
	case DlgAddItem::ItemType::DICE:
		itemNode = Util::getChildNode<Node*>(rootNode, "root/DiceNode");
		sprintf(string, "100");
		break;
	}

	itemNode->setVisible(true);
	
	_closeEventFunc = callback; itemType = item;

	addChild(rootNode);
	rootNode->runAction(action);
	action->setFrameEventCallFunc(CC_CALLBACK_1(DlgAddItem::onFrameEvent, this));

	cocos2d::ui::Text* btnCoinText = Util::getChildNode<ui::Text*>(rootNode, "root/btn_buy/Text");
	btnCoinText->setString(string);

	if(parent != nullptr)
		parent->addChild(this, zOrder);

	ui::Button* btnQuit = Util::getChildNode<ui::Button*>(rootNode, "root/btn_close", CC_CALLBACK_1(DlgAddItem::onClick, this));
	Util::applyDefaultButtonPressFx(btnQuit);
	ui::Button* btnBuy = Util::getChildNode<ui::Button*>(rootNode, "root/btn_buy", CC_CALLBACK_1(DlgAddItem::onClick, this));
	Util::applyDefaultButtonPressFx(btnBuy);

	// add keyboard event listner
	auto keyboardListner = EventListenerKeyboard::create();
	keyboardListner->onKeyReleased = CC_CALLBACK_2(DlgAddItem::onKeyReleasedEvent, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListner, this);

	return true;
}

void DlgAddItem::onClick(Ref* ref) {
	ui::Button* btn = dynamic_cast<ui::Button*>(ref);
	int btnTag = btn->getTag();

	switch (btnTag) {
	case 320:
		msgResult = Result::YES;
		break;
	case 321:
		break;
		msgResult = Result::NO;
	default:
		break;
	}

	closeDlg();
}

void DlgAddItem::onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) {
	if(keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		event->stopPropagation();
		closeDlg();
	}
}

void DlgAddItem::onFrameEvent(cocostudio::timeline::Frame* frame) {
	EventFrame* evnt = dynamic_cast<EventFrame*>(frame);
	if(!evnt)
		return;

	std::string str = evnt->getEvent();

	if(str == "evt_finished") {
		if(_closeEventFunc != nullptr)
			_closeEventFunc(itemType, msgResult);

		this->removeFromParentAndCleanup(true);
	}
}

void DlgAddItem::closeDlg() {
	if(action->isPlaying())
		return;
	action->play("FlyOut", false);
	rootNode->runAction(action);
}