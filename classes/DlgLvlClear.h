#ifndef __DLG_LEVEL_CLEAR_H__
#define __DLG_LEVEL_CLEAR_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocostudio::timeline;

class DlgLvlClear:public cocos2d::Layer {
public:
	enum class CloseType { Continue, Close };
	typedef std::function<void(CloseType)> closedCallback;
	static DlgLvlClear* createDlg(int lvl, int score, int starcount, cocos2d::ui::Widget* goalList, cocos2d::Node* parent = nullptr, const closedCallback& callback = nullptr, int zorther = 0);
	virtual bool init(int lvl, int score, int startCount, cocos2d::ui::Widget* goalList, cocos2d::Node* parent, const closedCallback& callback, int zorther);

private:
	cocos2d::Node* rootNode;
	cocostudio::timeline::ActionTimeline* rootNodeAction;
	cocos2d::ui::Text* txtLevel;
	cocos2d::ui::Text* txtScore;
	cocos2d::ui::Button* btnContinue;
	cocos2d::ui::Button* btnExit;
	cocos2d::ParticleSystemQuad* paticlel = nullptr;
	cocos2d::ParticleSystemQuad* paticler = nullptr;
	cocos2d::ParticleSystemQuad* paticlec = nullptr;
	cocos2d::Sprite* starlslot;
	cocos2d::Sprite* starrslot;
	cocos2d::Sprite* starcslot;
	cocos2d::Node* starl;
	cocos2d::Node* starr;
	cocos2d::Node* starc;

	CloseType closetype;

	void onClose();
	void onHaveItem();

	void onClick(cocos2d::Ref* ref);
	void onKey(cocos2d::EventKeyboard::KeyCode, cocos2d::Event* _event);
	void onFlyOutEnd();
	void on_Frame(Frame* frame);

	closedCallback _closedFunc;


};

#endif //__DLG_LEVEL_CLEAR_H__