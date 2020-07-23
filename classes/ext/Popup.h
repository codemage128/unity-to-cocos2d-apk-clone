#ifndef __POPUP_H__
#define __POPUP_H__

#include "cocos2d.h"

class Popup : public cocos2d::Layer
{
public:
	Popup();
	virtual ~Popup();
	bool initWithMask(bool maskVisible = false, cocos2d::Color4B maskColor = cocos2d::Color4B(0,0,0,180));

	static Popup* create();
	static Popup* createWithMask(bool maskVisible = false, cocos2d::Color4B maskColor = cocos2d::Color4B(0,0,0,180));

	bool isMaskVisible() { return _mask != nullptr && _mask->isVisible(); }
	void setMaskVisible(bool value) { if (_mask != nullptr) _mask->setVisible(value); }

	bool isCloseByBackKey() { return _closeByBackKey; }
	void setCloseByBackKey(bool closeByBackKey) { _closeByBackKey = closeByBackKey; }
	bool isCloseByOuterClick() { return _closeByOuterClick; }
	void setCloseByOuterClick(bool closeByOuterClick) { _closeByOuterClick = closeByOuterClick; }

	std::function<void(void)> getOnShowHandler() { return _onShowHandler; }
	void setOnShowHandler(std::function<void(void)> onShowHandler) { _onShowHandler = onShowHandler; }
	std::function<void(void)> getOnCloseHandler() { return _onCloseHandler; }
	void setOnCloseHandler(std::function<void(void)> onCloseHandler) { _onCloseHandler = onCloseHandler; }

	void setHole(cocos2d::Rect rc) { _hasHole = true; _hole = rc; }
	void setOnClickHoleHandler(std::function<void(void)> handler) { _onClickHoleHandler = handler; }

	void show(cocos2d::Node* parent, int zOrder, cocos2d::FiniteTimeAction* action = nullptr);
	void close(cocos2d::FiniteTimeAction* action = nullptr);

	virtual void onShow();
	virtual void onClose();
	virtual void onBeforeShow();
	virtual cocos2d::FiniteTimeAction* getDefaultShowAction();
	virtual cocos2d::FiniteTimeAction* getDefaultCloseAction();

protected:
	void onEnterTransitionDidFinish();
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);

private:
	cocos2d::LayerColor* _mask;

private:
	bool _closeByBackKey;
	bool _closeByOuterClick;
	std::function<void(void)> _onShowHandler;
	std::function<void(void)> _onCloseHandler;

	bool _hasHole;
	cocos2d::Rect _hole;
	std::function<void(void)> _onClickHoleHandler;
};

#endif //__POPUP_H__