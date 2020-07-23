#include "DlgLvlComplete.h"
#include "common/Util.h"

USING_NS_CC;

using namespace cocostudio::timeline;


DlgLvlComplete* DlgLvlComplete::createDlg(Node* parent, const closedCallback& callback, int zorther) {
	DlgLvlComplete *pRet = new(std::nothrow) DlgLvlComplete();
	if(pRet && pRet->init(parent, callback, zorther)) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = nullptr;
		return nullptr;

	}
}
  
bool DlgLvlComplete::init(Node* parent, const closedCallback& callback, int zorther) {
	if(!Layer::init()) {
		return false;
	}

	Util::loadCCSScene("dlgLevelComplete.csb", rootNode, action, this);

	_closedFunc = callback;
	if(parent != nullptr)
		parent->addChild(this, zorther);

	
	action->play("play", false);
	action->setFrameEventCallFunc(CC_CALLBACK_1(DlgLvlComplete::onFrame, this));
	rootNode->runAction(action);

	auto bear = rootNode->getChildByName("bear");
	auto bear_timeline = CSLoader::createTimeline("charactor/bear.csb");
	bear_timeline->play("Play", true);
	bear->runAction(bear_timeline);

	auto cat = rootNode->getChildByName("cat");
	auto cat_timeline = CSLoader::createTimeline("charactor/cat.csb");
	cat_timeline->play("Play", true);
	cat->runAction(cat_timeline);

	auto wolf = rootNode->getChildByName("wolf");
	auto wolf_timeline = CSLoader::createTimeline("charactor/wolf.csb");
	wolf_timeline->play("Play", true);
	wolf->runAction(wolf_timeline);


	spark = dynamic_cast<ParticleSystemQuad*>(rootNode->getChildByName("spark"));
	spark1 = dynamic_cast<ParticleSystemQuad*>(rootNode->getChildByName("spark_1"));
	spark2 = dynamic_cast<ParticleSystemQuad*>(rootNode->getChildByName("spark_2"));
	spark_line = dynamic_cast<ParticleSystemQuad*>(rootNode->getChildByName("spark_line"));
	spark_line1 = dynamic_cast<ParticleSystemQuad*>(rootNode->getChildByName("spark_line_1"));
	spark_line2 = dynamic_cast<ParticleSystemQuad*>(rootNode->getChildByName("spark_line_2"));

	spark->stopSystem();
	spark1->stopSystem();
	spark2->stopSystem();


	
	addChild(rootNode);

	return true;
}
void DlgLvlComplete::onFrame(Frame* frame) {
	EventFrame* evnt = dynamic_cast<EventFrame*>(frame);
	if(!evnt)
		return;
	std::string str = evnt->getEvent();

	if(str == "a") {
		spark->resetSystem();
		spark_line->stopSystem();
	}
	if(str == "b") {
		spark1->resetSystem();
		spark_line1->stopSystem();
	}
	if(str == "c") {
		spark2->resetSystem();
		spark_line2->stopSystem();
	}

	if(str == "frameEvtEnd") {
		if(_closedFunc != nullptr)
			_closedFunc();
		this->removeFromParentAndCleanup(true);
	}
}

void DlgLvlComplete::onKey(EventKeyboard::KeyCode keycode, Event* _event) {
	if(keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		_event->stopPropagation();
		//onExit();
	}
}
