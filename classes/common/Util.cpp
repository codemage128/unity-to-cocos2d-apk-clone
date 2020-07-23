#include "common/Util.h"
#include "../global/SoundManager.h"

///////////////////
int Util::random_range(int min, int max) {
	int span = max - min + 1;
	return rand() % span + min;
}

std::string Util::my_sprintf(const char *szFmt, ...)
{
	char szPrint[200] = "";
	va_list args;
	va_start(args, szFmt);
	vsnprintf(szPrint, 200, szFmt, args);
	va_end(args);

	std::string sRet = szPrint;
	return sRet;
}

std::vector<std::string> Util::my_split(std::string sInput, std::string sSpliter) {
	std::vector<std::string> ret;
	std::string sItem;
	unsigned int iStart = 0;
	unsigned int nPos = 0;
	unsigned int idxSpliter = 0;
	while (nPos < sInput.length()) {
		char chInput = sInput[nPos++];
		for (idxSpliter = 0; idxSpliter < sSpliter.length(); idxSpliter++) {
			char chSpliter = sSpliter[idxSpliter];
			if (chInput == chSpliter) {
				if (!sItem.empty()) {
					ret.push_back(sItem);
					sItem.clear();
				}
				break;
			}
		}

		if (idxSpliter == sSpliter.length()) //if not spliter charactor.
			sItem += chInput;
	}

	if (!sItem.empty()) {
		ret.push_back(sItem);
		sItem.clear();
	}
	return ret;
}

ui::CheckBox* Util::getChildCheckBox(Node* rootNode, std::string path, const ui::CheckBox::ccCheckBoxCallback& cbCheckBox, const ui::Widget::ccWidgetTouchCallback& cbTouch, float zoomScale) {
	ui::CheckBox* chkBox = getChildNode<ui::CheckBox*>(rootNode, path, nullptr, cbTouch, zoomScale);
	if (chkBox != nullptr)
		chkBox->addEventListener(cbCheckBox);
	return chkBox;
}

/////////////////
void Util::applyDefaultButtonPressFx(ui::Widget* btn) {
	btn->addTouchEventListener([](cocos2d::Ref* ref, ui::Widget::TouchEventType type) {
		// show button zoom fx
		ui::Widget* widget = dynamic_cast<ui::Widget*>(ref);
		switch(type) {
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			widget->setScale(0.92f);
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			widget->setScale(1.0f);
			SoundManager::playEffectSound(SFX::buttonClick);
			break;
		}
	});
}


void Util::loadCCSScene(std::string csbname, Node*& rootnode, ActionTimeline*& timeline, Node* parent, int zorder) {
	rootnode = CSLoader::createNode(csbname);
	timeline = CSLoader::createTimeline(csbname);
	if(parent != nullptr && rootnode != nullptr)
		parent->addChild(rootnode, zorder);
}

Node* Util::loadCCSScene(std::string csbname, Node* parent, int zorder) {
	Node* rootnode = CSLoader::createNode(csbname);
	if(parent != nullptr && rootnode != nullptr)
		parent->addChild(rootnode, zorder);
	return rootnode;
}