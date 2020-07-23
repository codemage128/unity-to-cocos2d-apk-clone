#include "Popup.h"

USING_NS_CC;

#define kZMask	-10000

Popup* Popup::create()
{
	return createWithMask();
}

Popup* Popup::createWithMask(bool maskVisible, Color4B maskColor)
{
    Popup *pRet = new Popup();
	if (pRet && pRet->initWithMask(maskVisible, maskColor))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

Popup::Popup()
{
	_closeByBackKey = false;
	_closeByOuterClick = false;
	_onShowHandler = nullptr;
	_onCloseHandler = nullptr;
	_hasHole = false;
	_hole = Rect(-1,-1,0,0);
	_onClickHoleHandler = nullptr;
	_mask = nullptr;
}

Popup::~Popup()
{
}

bool Popup::initWithMask(bool maskVisible, Color4B maskColor)
{
	Layer::init();

	_mask = LayerColor::create(maskColor);
	_mask->setPosition(Director::getInstance()->getWinSize() / 2);
	_mask->setScale(4);
	_mask->setVisible(maskVisible);
	addChild(_mask, kZMask);

	return true;
}

void Popup::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();

	// keyboard
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyReleased = CC_CALLBACK_2(Popup::onKeyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyListener, this);

	// touches
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(Popup::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void Popup::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (_closeByBackKey && (keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE || keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)) {
		close();
	}
	event->stopPropagation();
}

bool Popup::onTouchBegan(Touch *touch, Event *unused_event)
{
	if (_hasHole && _hole.containsPoint(touch->getLocation())) {
		if (_onClickHoleHandler)
			_onClickHoleHandler();
		return false;
	}
	if (_closeByOuterClick)
	{
		close();
		return false;
	}
	return true;
}

void Popup::show(Node* parent, int zOrder, FiniteTimeAction* action)
{
	onBeforeShow();

	if (action == nullptr)
		action = getDefaultShowAction();
	if (action == nullptr)
		action = Show::create();

	Director::getInstance()->getEventDispatcher()->pauseEventListenersForTarget(parent, true);
	parent->addChild(this, zOrder);
	runAction(Sequence::create(
		action,
		CallFunc::create([this]() {
			onShow();
		}),
		nullptr
	));
}

void Popup::onShow()
{
	if (_onShowHandler != nullptr)
		_onShowHandler();
}

void Popup::close(FiniteTimeAction* action)
{
	if (action == nullptr)
		action = getDefaultCloseAction();
	if (action == nullptr)
		action = Hide::create();

	runAction(Sequence::create(
		action,
		CallFunc::create([this]() {
			Director::getInstance()->getEventDispatcher()->resumeEventListenersForTarget(this->getParent(), true);
			removeFromParent();
			onClose();
		}),
		nullptr
	));
}

void Popup::onClose()
{
	if (_onCloseHandler != nullptr)
		_onCloseHandler();
}

void Popup::onBeforeShow()
{
	Size sz = Director::getInstance()->getWinSize();
	setPosition(0, sz.height);
}

FiniteTimeAction* Popup::getDefaultShowAction()
{
	Size sz = Director::getInstance()->getWinSize();
	return EaseBounceIn::create(MoveBy::create(0.15f, Point(0, -sz.height)));
}

FiniteTimeAction* Popup::getDefaultCloseAction()
{
	Size sz = Director::getInstance()->getWinSize();
	return EaseBounceOut::create(MoveBy::create(0.15f, Point(0, sz.height)));
}
