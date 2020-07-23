#include "ScnSplash.h"
#include "ScnLoading.h"
#include "cocostudio/CocoStudio.h"
#include "common/Util.h"

USING_NS_CC;
using namespace cocostudio;
using namespace cocostudio::timeline;

Scene* ScnSplash::createScene() {
	return ScnSplash::create();
}

bool ScnSplash::init() {
	if (!Scene::init()) {
		return false;
	}

	Node* sceneNode = nullptr;
	ActionTimeline* action = nullptr;
	Util::loadCCSScene("scnSplash.csb", sceneNode, action, this);

	action->setAnimationEndCallFunc("show", [] {
		// show app loading scene
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, ScnLoading::createScene(ScnLoading::Type::App)));
	});
	sceneNode->runAction(action);
	action->gotoFrameAndPause(0);
	action->play("show", false);

	return true;
}
