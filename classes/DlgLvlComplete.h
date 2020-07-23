#ifndef __DLG_LEVEL_COMPLETE_H__
#define __DLG_LEVEL_COMPLETE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocostudio::timeline;

class DlgLvlComplete:public cocos2d::Layer {

public:
	typedef std::function<void()> closedCallback;
	static DlgLvlComplete* createDlg(cocos2d::Node* parent = nullptr, const closedCallback& callback = nullptr, int zorther = 0);
	virtual bool init(cocos2d::Node* parent, const closedCallback& callback, int zorther);
private:
	cocos2d::Node* rootNode;
	ActionTimeline* action;
	cocos2d::ParticleSystemQuad* spark;
	cocos2d::ParticleSystemQuad* spark1;
	cocos2d::ParticleSystemQuad* spark2;
	cocos2d::ParticleSystemQuad* spark_line;
	cocos2d::ParticleSystemQuad* spark_line1;
	cocos2d::ParticleSystemQuad* spark_line2;
	

	void onFrame(Frame* frame);
	void onKey(cocos2d::EventKeyboard::KeyCode, cocos2d::Event* _event);
	
	closedCallback _closedFunc;

};

#endif //__DLG_LEVEL_COMPLETE_H__