#ifndef __COCOUTIL_H__
#define __COCOUTIL_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include <vector>

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocostudio;

class Util
{
public:
	// position
	static Vec2 getWorldPosition(const Node* node) {
		const Node* parent = node->getParent();
		if(parent == nullptr)
			return node->getPosition();
		return parent->convertToWorldSpace(node->getPosition());
	}

	static Vec2 getWorldPosition(const Node* parent, const Vec2& localPos) {
		return parent->convertToWorldSpace(localPos);
	}

	static Vec2 getLocalPosition(const Node* parent, const Vec2& worldPos) {
		return parent->convertToNodeSpace(worldPos);
	}

	static void swapPosition(Node* node1, Node* node2) {
		Vec2 pos1 = node1->getPosition();
		Vec2 pos2 = node2->getPosition();
		node1->setPosition(pos2);
		node2->setPosition(pos1);
	}

	// size
	static Size getSize(const Node* node) {
		auto sz = node->getContentSize();
		return Size(sz.width * node->getScaleX(), sz.height * node->getScaleY());
	}

	// string
	static const char* getString(int n) {
		return __String::createWithFormat("%d", n)->getCString();
	}
	static const char* getTimeString(int seconds) {
		int m = seconds / 60;
		seconds = seconds % 60;
		return __String::createWithFormat("%02d:%02d", m, seconds)->getCString();
	}


	/////// KCS Add ////////////
	//Generates random value (min ~ max)
	static int random_range(int min = 0, int max = 100);

	//sprintf  returns std::string.
	static std::string my_sprintf(const char *szFmt, ...);

	// Splits String by ",;/..."
	static std::vector<std::string> my_split(std::string sInput, std::string sSpliter);

	// 
	template<class T>
	static T getChildNode(Node* rootNode, std::string path, const ui::Widget::ccWidgetClickCallback& cbClick = nullptr, const ui::Widget::ccWidgetTouchCallback& cbTouch = nullptr, float zoomScale = 0.0f) {
		T result = nullptr;

		std::vector<std::string> names = my_split(path, "/");
		Node* node = rootNode;
		unsigned int level = 0;
		while ((node != nullptr) && (level < names.size())) {
			std::string sChild = names.at(level);
			node = node->getChildByName(sChild.c_str());
			if (node == nullptr) {
				std::string sErrMsg = "!!! ERROR:getChildNode: " + sChild;
				CCASSERT(false, sErrMsg.c_str());
				break;
			}
			level++;
		}

		auto widget = dynamic_cast<ui::Widget*>(node);
		if (widget && cbClick != nullptr)
			widget->addClickEventListener(cbClick);

		if (widget && cbTouch != nullptr)
			widget->addTouchEventListener(cbTouch);

		{
			auto button = dynamic_cast<ui::Button*>(node);
			if (button != nullptr)
				button->setZoomScale(zoomScale);

			auto chkBox = dynamic_cast<ui::AbstractCheckButton*>(node);
			if (chkBox != nullptr)
				chkBox->setZoomScale(zoomScale);
		}

		result = dynamic_cast<T>(node);

		return result;
	}

	static ui::CheckBox* getChildCheckBox(Node* rootNode, std::string path, const ui::CheckBox::ccCheckBoxCallback& cbCheckBox = nullptr, const ui::Widget::ccWidgetTouchCallback& cbTouch = nullptr, float zoomScale = 0.0f);


	// [FOR RYR]=============================================

	// apply button press fx to zoom in/out
	static void applyDefaultButtonPressFx(ui::Widget* btn);

	// load csb file and get scene root node and main timeline action, and add it to 'parent' node as child node
	static void loadCCSScene(std::string csbname, Node*& rootnode, ActionTimeline*& timeline, Node* parent = nullptr, int zorder = 0);

	// load csb file and add it to 'parent' node as child node
	// return loaded root node
	static Node* loadCCSScene(std::string csbname, Node* parent = nullptr, int zorder = 0);
};


#endif //__COCOUTIL_H__