#ifndef __LEVELSCENECOMPONENTS_H__
#define __LEVELSCENECOMPONENTS_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "ext/List.h"

USING_NS_CC;

class LevelButton
{
public:
	LevelButton(cocos2d::Node* csbNode);

	void setListener(const cocos2d::ui::Widget::ccWidgetClickCallback &callback);
	int getLevel();
	void setLevel(int level);
	float getPositionY() { return _btn->getParent()->getPositionY(); }
	float getPositionX() { return _btn->getParent()->getPositionX(); }
	void setScale(float s) {
		_btn->setScale(_btn->getScale()*s);
		_label->setScale(_label->getScale()*s);
		_star->setScale(_star->getScale()*s);

		_initscale = _btn->getScale();
	};
	float getInitScale() { return _initscale; }

protected:
	float _initscale;
	cocos2d::ui::Button* _btn;
	cocos2d::ui::TextBMFont* _label;
	cocos2d::ui::ImageView* _star;
};
class ExNode {
protected:
	cocos2d::Node* _node;
	cocostudio::timeline::ActionTimeline* _action;

public:
	ExNode(Node *node) {
		_node = node;
		_action = dynamic_cast<cocostudio::timeline::ActionTimeline*>(node->getActionByTag(node->getTag()));
	}
	void runTimeLine() {
		if (_action && _node->getActionManager()->getNumberOfRunningActionsInTarget(_node) == 0) {
			_action->gotoFrameAndPlay(0, true);
			_node->runAction(_action);
		}
	}
};
class BgSegment
{
public:
	BgSegment(int id, cocos2d::Node* csbNode);
	~BgSegment();

	int getId() { return _id; }

	float getPosY() { return _bg->getPositionY(); }
	void setPosY(float y) { _bg->setPositionY(y); }

	float getTopY() { return _bg->getPositionY() + getHeight() / 2; }
	float getBottomY() { return _bg->getPositionY() - getHeight() / 2; }

	float getHeight() { return _bg->getContentSize().height * _bg->getScaleY(); }
	float getButtonPosY(int i) { return _buttons[i]->getPositionY() * _bg->getScaleY(); }
	float getButtonPosX(int i) { return _buttons[i]->getPositionX()* _bg->getScaleX(); }

	int getLevelCount() { return _buttons.getCount(); }
	int getFirstLevel() { return _startLevel; }
	int getLastLevel() { return _startLevel == 0 ? 0 : _startLevel + _buttons.getCount() - 1; }

	int getStartLevel() { return _startLevel; }
	void setStartLevel(int startLevel) { _startLevel = startLevel; }

	void refresh(bool reset = false);

protected:
	int _id;
	int _prevStartLevel;
	int _startLevel;
	cocos2d::Node* _bg;
	List<LevelButton*> _buttons;
	List<ExNode*> _objNodes;
};

#endif //__LEVELSCENECOMPONENTS_H__