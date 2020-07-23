#include "ScnLevelSelectNode.h"
#include "ScnLevelSelect.h"
#include "common/Util.h"
#include "global/GameManager.h"

USING_NS_CC;

// LevelButton

LevelButton::LevelButton(Node* csbNode)
{
	_btn = (ui::Button*)csbNode->getChildByName("button");
	_label = (ui::TextBMFont*)csbNode->getChildByName("label");
	_star = (ui::ImageView*)csbNode->getChildByName("star");
}

void LevelButton::setListener(const ui::Widget::ccWidgetClickCallback &callback)
{
	_btn->addClickEventListener(callback);
}

int LevelButton::getLevel()
{
	return _btn->getTag();
}

void LevelButton::setLevel(int level)
{

	if (level > 0 && level <= GM->getLevelCount())
	{

		_btn->getParent()->setVisible(true);
		_btn->stopAllActions();

		_btn->setTag(level);
		_label->setString(Util::getString(level)); 

		/*GameData* gameData = GameData::getInstance();
		int star = gameData->getLevelStar(level);
		Level::Mode mode = levelManager->getLevelMode(level);
		const char* str = String::createWithFormat("images/ui/level_%s_%d.png", mode == Level::Mode::Devil ? "devil" : "normal", star)->getCString();
		_btn->loadTextures(str, str, str, ui::Widget::TextureResType::PLIST);*/

		if(level <= GM->getTopLevel())
		{
			_btn->setEnabled(true);
			_label->setVisible(true);
			int star = GM->getLevelStar(level);

			if (star > 0) {
				auto str = __String::createWithFormat("image/mapui/star%d.png", star)->getCString();
				_star->loadTexture(str);
				_star->setVisible(true);
			}
			else {
				_star->setVisible(false);
			}

			if(level == GM->getTopLevel()) {
				float bscale = this->getInitScale();
				_btn->runAction(RepeatForever::create(Sequence::create(ScaleTo::create(1, bscale*1.2), ScaleTo::create(1, bscale), NULL)));
			}
		}
		else
		{
			_btn->setEnabled(false);
			//_label->setVisible(false);
			_star->setVisible(false);
		}
		/*if (level == GameData::getInstance()->getTopLevel()) {
			float bscale = this->getInitScale();
			_btn->runAction(RepeatForever::create(Sequence::create(ScaleTo::create(1, bscale*1.2), ScaleTo::create(1, bscale), NULL)));
		}*/
	}
	else
	{
		_btn->getParent()->setVisible(false);
	}
}

// BgSegment

BgSegment::~BgSegment()
{
	for (int i = 0; i < _buttons.getCount(); i++)
		delete _buttons[i];
	for (int i = 0; i < _objNodes.getCount(); i++)
		delete _objNodes[i];
}

BgSegment::BgSegment(int id, Node* csbNode)
{
	_id = id;
	_prevStartLevel = 0;
	_startLevel = 0;

	_bg = csbNode;

	auto levelRoot = csbNode->getChildByName("level");
	auto aniRoot = csbNode->getChildByName("ani");

	if (levelRoot) {
		for (int i = 0; i < levelRoot->getChildrenCount(); i++)
		{
			auto node = levelRoot->getChildren().at(i);

			auto btn = new LevelButton(node);
			btn->setScale(_bg->getScale());
			btn->setListener(CC_CALLBACK_1(LevelSelectScene::onSelectLevel, LevelSelectScene::getInstance()));
			_buttons.add(btn);

		}
		if (aniRoot) {
			for (int i = 0; i < aniRoot->getChildrenCount(); i++) {
				auto node = aniRoot->getChildren().at(i);
				_objNodes.add(new ExNode(node));

			}
		}
	}
	else {
		for (int i = 0; i < csbNode->getChildrenCount(); i++)
		{
			auto btn = new LevelButton(csbNode->getChildren().at(i));
			btn->setListener(CC_CALLBACK_1(LevelSelectScene::onSelectLevel, LevelSelectScene::getInstance()));
			_buttons.add(btn);
		}
	}
}

void BgSegment::refresh(bool reset)
{
	if (_startLevel > 0 && (_startLevel != _prevStartLevel || reset))
	{
		for (int i = 0; i < _buttons.getCount(); i++)
			_buttons[i]->setLevel(_startLevel + i);
		_prevStartLevel = _startLevel;
	}
	for (int i = 0; i < _objNodes.getCount(); i++) {
		auto node = _objNodes[i];
		node->runTimeLine();
	}
}
