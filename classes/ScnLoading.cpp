#include "ScnLoading.h"
#include "common/Util.h"
#include "ScnLevelSelect.h"
#include "ScnLevelPlay.h"
#include "global/GameManager.h"

USING_NS_CC;
using namespace cocostudio;
using namespace cocostudio::timeline;

Scene* ScnLoading::createScene(ScnLoading::Type type) {
    auto scene = Scene::create();
	ScnLoading *layer = ScnLoading::create(type);
    scene->addChild(layer);
    return scene;
}

ScnLoading* ScnLoading::create(ScnLoading::Type type) {
	ScnLoading *pRet = new(std::nothrow) ScnLoading();
	if (pRet && pRet->init(type)) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool ScnLoading::init(ScnLoading::Type type) {
    if ( !Layer::init() ) {
        return false;
    }

	if(type == ScnLoading::Type::App) {			// show app loading scene
		Node* sceneNode = nullptr;
		ActionTimeline* action = nullptr;
		Util::loadCCSScene("scnAppLoading.csb", sceneNode, action, this);

		sceneNode->runAction(action);
		action->play("show", false);
		//action->setAnimationEndCallFunc("show", [] {
		scheduleOnce([](float){
			// go to level select scene
			Director::getInstance()->replaceScene(TransitionFade::create(0.5f, LevelSelectScene::createScene()));
		},2.0,"apploading");
	}
	else if(type == ScnLoading::Type::Level) {	// show level loading scene
		Node* sceneNode = nullptr;
		ActionTimeline* action = nullptr;
		Util::loadCCSScene("scnLevelLoading.csb", sceneNode, action, this);

		sceneNode->runAction(action);
		action->play("show", false);
		//action->setAnimationEndCallFunc("show", [] {
		scheduleOnce([](float) {
			// go to game scene
			Director::getInstance()->replaceScene(TransitionFade::create(0.5f, ScnLevelPlay::createScene()));
		},0.6f,"levelloading");

		// set image as random
		int imgNumber = 0;
		int level = GM->getCurrentLevel();
		switch (level) {
		case 1: imgNumber = 1; break;
		case 2: 
		case 3: 
		case 4:
		case 5:
		case 6:
		case 7: imgNumber = level - 1; break;
		case 8: imgNumber = 6; break;
		default: imgNumber = 1 + rand() % 6; break;
		}
		char imgpath[32];
		sprintf(imgpath, "image/loading/levelloading%d.png", imgNumber);
		dynamic_cast<ui::ImageView*>(sceneNode->getChildByName("loading"))->loadTexture(imgpath);

	}
	else if(type == ScnLoading::Type::Lobby) {	// show lobby loading scene
		Node* sceneNode = nullptr;
		ActionTimeline* action = nullptr;
		Util::loadCCSScene("scnLevelLoading.csb", sceneNode, action, this);

		sceneNode->runAction(action);
		action->play("show", false);
		//action->setAnimationEndCallFunc("show", [] {
		scheduleOnce([](float) {
			// go to level select scene
			Director::getInstance()->replaceScene(TransitionFade::create(0.5f, LevelSelectScene::createScene()));
		},1.0f,"lobbyloading");

		// set image as random
		char imgpath[32];
		sprintf(imgpath, "image/loading/lobbyloading%d.png", (1 + rand() % 3));
		dynamic_cast<ui::ImageView*>(sceneNode->getChildByName("loading"))->loadTexture(imgpath);
	}

    return true;
}