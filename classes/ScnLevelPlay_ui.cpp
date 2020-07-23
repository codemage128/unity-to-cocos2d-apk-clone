#include "ScnLevelPlay.h"
#include "ScnLoading.h"
#include "cocostudio/CocoStudio.h"
#include "global/GameManager.h"
#include "global/SoundManager.h"
#include "common/Util.h"
#include "DlgLevelQuit.h"
#include "DlgLvlClear.h"
#include "DlgLvlFail.h"
#include "DlgLvlComplete.h"
#include "game/LevelBuilder.h"
#include "game/ImageLibrary.h"
#include "game/particleLibrary.h"
#include "game/Level.h"
#include "game/Grid.h"
#include "game/Cell.h"
#include "game/ItemImpl.h"
#include "game/Score.h"
#include "game/Booster.h"

USING_NS_CC;
using namespace cocostudio;

Scene* ScnLevelPlay::createScene() {
    auto scene = Scene::create();
	ScnLevelPlay *layer = ScnLevelPlay::create();
    scene->addChild(layer);

	return scene;
}

bool ScnLevelPlay::init() {
	if(!Layer::init())
		return false;


	// load cocos studio scene
	Util::loadCCSScene("scnLevelPlay.csb", _rootNode, _sceneAction, this);
	_sceneAction->play("normal", false);
	_sceneAction->setFrameEventCallFunc(CC_CALLBACK_1(ScnLevelPlay::onFrameEvent, this));
	_rootNode->runAction(_sceneAction);

	// load widgets
	_menuCover = Util::getChildNode<ui::Widget*>(_rootNode, "menucover", CC_CALLBACK_1(ScnLevelPlay::onPauseCancelled, this)); _menuCover->setLocalZOrder(MENUCOVER_ZORDER);
	Util::applyDefaultButtonPressFx(Util::getChildNode<ui::Button*>(_rootNode, "pausebtn/btn", CC_CALLBACK_1(ScnLevelPlay::onPauseClicked, this))); Util::getChildNode<Node*>(_rootNode, "pausebtn")->setLocalZOrder(MENUCOVER_ZORDER);
	Util::applyDefaultButtonPressFx(Util::getChildNode<ui::Button*>(_rootNode, "quitbtn/btn", CC_CALLBACK_1(ScnLevelPlay::onQuitClick, this))); Util::getChildNode<Node*>(_rootNode, "quitbtn")->setLocalZOrder(MENUCOVER_ZORDER);
	Util::applyDefaultButtonPressFx(Util::getChildCheckBox(_rootNode, "musicbtn/chk", CC_CALLBACK_2(ScnLevelPlay::onMusicToggled, this))); Util::getChildNode<Node*>(_rootNode, "musicbtn")->setLocalZOrder(MENUCOVER_ZORDER);
	Util::applyDefaultButtonPressFx(Util::getChildCheckBox(_rootNode, "soundbtn/chk", CC_CALLBACK_2(ScnLevelPlay::onSoundToggled, this))); Util::getChildNode<Node*>(_rootNode, "soundbtn")->setLocalZOrder(MENUCOVER_ZORDER);

	// load top panel
	initTopPanel();
	// load bottom panel
	initBottomPanel();

	// attack touch listner
	auto touchListner = EventListenerTouchOneByOne::create();
	touchListner->setSwallowTouches(true);
	touchListner->onTouchBegan = CC_CALLBACK_2(ScnLevelPlay::onTouchBegan, this);
	touchListner->onTouchMoved = CC_CALLBACK_2(ScnLevelPlay::onTouchMoved, this);
	touchListner->onTouchEnded = CC_CALLBACK_2(ScnLevelPlay::onTouchEnded, this);
	touchListner->onTouchCancelled = CC_CALLBACK_2(ScnLevelPlay::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListner, this);
	// attach keyboard listner
	auto keyboardListner = EventListenerKeyboard::create();
	keyboardListner->onKeyReleased = CC_CALLBACK_2(ScnLevelPlay::onKeyReleasedEvent, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListner, this);
	// disable all events
	setTouchInputWorking(false);

	// build level
	IMGLIB->init();
	PTCLLIB->init();
	LevelBuilder::CurrentLevelNo = GM->getCurrentLevel();
	LevelBuilder* builder = new LevelBuilder();
	builder->LevelScene = this;
	builder->CellContainer = dynamic_cast<Node*>(_rootNode->getChildByName("board"));
	builder->ItemContainer = dynamic_cast<Node*>(_rootNode->getChildByName("board"));
	builder->SceneContainer = dynamic_cast<Node*>(_rootNode);
	builder->buildLevel();

	// start logic
	schedule(CC_CALLBACK_1(ScnLevelPlay::onFrame, this), 0.0f/*every frame*/, CC_REPEAT_FOREVER, 0.0f/*at first frame*/, "onframe");
	setLogicWorking(true);

	// load level objective animation
	Util::loadCCSScene("fxLevelStartLogo.csb", _fxLvlObjective, _fxLvlObjectiveAction, this, FXANIMATION_ZORDER);
	Util::getChildNode<Node*>(_fxLvlObjective, "root/goal")->addChild(Util::getChildNode<ui::Widget*>(_rootNode, "goals")->clone());// set goals on level objective animation
	Util::getChildNode<Node*>(_fxLvlObjective, "root/goal")->enumerateChildren("//[[:alnum:]]+", [](Node* childnode)->bool {childnode->setCascadeOpacityEnabled(true); return false; });
	Util::getChildNode<Node*>(_fxLvlObjective, "root/goal/goals")->setPosition(Vec2(0, 15));
	_fxLvlObjective->runAction(_fxLvlObjectiveAction);// init animation
	_fxLvlObjectiveAction->gotoFrameAndPause(0);

	/*TEST*/
	/*END TEST*/

	return true;
}

void ScnLevelPlay::onEnterTransitionDidFinish() {
	// play level objective animation
	_fxLvlObjectiveAction->gotoFrameAndPlay(0, false);
	_fxLvlObjectiveAction->setLastFrameCallFunc([this]() {
		// kill level objective animation
		this->_fxLvlObjective->removeFromParentAndCleanup(true); 
		// reset members
		this->_fxLvlObjective = nullptr;
		this->_fxLvlObjectiveAction = nullptr;
		// enable logic
		setLogicWorking(true);
		// enable events
		setTouchInputWorking(true);
	});

	SoundManager::playBgMusic(SoundManager::MusicKind::gamebg1);
}

void ScnLevelPlay::onExitTransitionDidStart() {
	// disable logic
	setLogicWorking(false);
	unschedule("onframe");
	setTouchInputWorking(false);
	// cleanup resources
	IMGLIB->cleanup();
	PTCLLIB->cleanUp();
	LevelBuilder::ActiveLevel->cleanUp();
}

void ScnLevelPlay::onFrameEvent(cocostudio::timeline::Frame* frameEvt) {

}

bool ScnLevelPlay::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* evt) {
	return true;
}
void ScnLevelPlay::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* evt) {

}
void ScnLevelPlay::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* evt) {
	// only working when flag is set
	if(!_isLogicWorking || !_isTouchWorking) return;

	if(LevelBuilder::ActiveLevel != nullptr) {
		// find clicked cell
		std::vector<Cell*> allcells = LevelBuilder::ActiveLevel->CurrentGrid->WalkOnAll();
		for(Cell* __cell : allcells)
			if(__cell != nullptr && __cell->Exists && __cell->get_HasItem()) {
				bool cellTouched = cocos2d::Rect((__cell->X - 0.5f)*ITEM_SPRITE_SIZE_X, (__cell->Y - 0.5f)*ITEM_SPRITE_SIZE_X, ITEM_SPRITE_SIZE_X, ITEM_SPRITE_SIZE_X).containsPoint(LevelBuilder::ActiveLevel->CurrentLevelBuilder->CellContainer->convertTouchToNodeSpace(touch));
				if(BoosterManager::getInstance()->isInBoosterMode()) {
					if(cellTouched) {
						BoosterManager::getInstance()->CellTapped(__cell);
						break;
					}
				}
				else {
					// check this cell is touched
					Sprite* spItem = LevelBuilder::getItemSprite(__cell->get_CurrentItem());
					if(spItem != nullptr && cellTouched/*cocos2d::Rect(0, 0, ITEM_SPRITE_SIZE_X, ITEM_SPRITE_SIZE_X).containsPoint(spItem->CurrentSpriteRenderer->convertTouchToNodeSpace(touch))*/) {
						// process touch
						LevelBuilder::ActiveLevel->CurrentGrid->UserPerfomedTouchOnCell(__cell);
						break;
					}
				}
			}
	}
}

void ScnLevelPlay::onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) {
	if(keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACK) {
		event->stopPropagation();
		onPauseClicked(nullptr);
	}
}

void ScnLevelPlay::onPauseClicked(Ref* ref) {
	// hold until animation playing
	if(_sceneAction->isPlaying())
		return;
	// pause toggle
	if(_isPaused)
		pauseCancel();
	else
		pause();
}
void ScnLevelPlay::onPauseCancelled(Ref* ref) {
	// hold until animation playing
	if(_sceneAction->isPlaying())
		return;
	// cancel paused state
	if(_isPaused)
		pauseCancel();
}
void ScnLevelPlay::onQuitClick(Ref* ref) {
	// disable logic
	setLogicWorking(false);

	// force un-pause
	pauseCancel();
	// show quit dialog
	DlgLevelQuit::createDlg(this, CC_CALLBACK_1(ScnLevelPlay::onQuitClosed, this), DLG_ZORDER);
}
void ScnLevelPlay::onQuitClosed(DlgLevelQuit::Result closeType) {
	if(closeType == DlgLevelQuit::Result::YES) {
		// discount 1 life
		GM->plusLife(-1);
		// go to level select scene
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, ScnLoading::createScene(ScnLoading::Type::Lobby)));
	}
}

void ScnLevelPlay::pause() {
	// set state
	_isPaused = true;
	// show fx
	_sceneAction->play("menuEnter", false);
	_rootNode->runAction(_sceneAction);
	// set cover
	_menuCover->setTouchEnabled(true);
}
void ScnLevelPlay::pauseCancel() {
	// set state
	_isPaused = false;
	// show fx
	_sceneAction->play("menuExit", false);
	_rootNode->runAction(_sceneAction);
	// unset cover
	_menuCover->setTouchEnabled(false);
}

void ScnLevelPlay::onSoundToggled(Ref* ref, ui::CheckBox::EventType evtType) {
}

void ScnLevelPlay::onMusicToggled(Ref* ref, ui::CheckBox::EventType evtType) {
}

void ScnLevelPlay::onFrame(float delta) {
	// only working when flag is set
	if(!_isLogicWorking) return;

	// pass control to level
	LevelBuilder::ActiveLevel->onFrame(delta);
}

void ScnLevelPlay::setLogicWorking(bool enable/*= true*/) {
	_isLogicWorking = enable;
}

void ScnLevelPlay::setTouchInputWorking(bool enable/*=true*/) {
	_isTouchWorking = enable;
}

void ScnLevelPlay::levelComplete() {
	setTouchInputWorking(false);

	scheduleOnce([this](float) {
	setLogicWorking(false);
		showLogoAnimation(); 
	}, 2.0f, "completeDlgDelay");
}

void ScnLevelPlay::showLogoAnimation() {
	// show level clear logo
	Util::loadCCSScene("fxLevelClearLogo.csb", _fxLvlClearLogo, _fxLvlClearLogoAnimation, this, FXANIMATION_ZORDER);
	_fxLvlClearLogo->runAction(_fxLvlClearLogoAnimation);
	_fxLvlClearLogoAnimation->gotoFrameAndPlay(0, false);
	_fxLvlClearLogoAnimation->setLastFrameCallFunc(CC_CALLBACK_0(ScnLevelPlay::logoAnimationEnd, this));
}

void ScnLevelPlay::logoAnimationEnd() {
	_fxLvlClearLogo->removeFromParentAndCleanup(true);
	_fxLvlClearLogo = nullptr;
	_fxLvlClearLogoAnimation = nullptr;

	scheduleOnce([this](float) {DlgLvlComplete::createDlg(this, CC_CALLBACK_0(ScnLevelPlay::charAnimationEnd, this), FXANIMATION_ZORDER); }, 1.0f, "charAnimationDelay");
}

void ScnLevelPlay::charAnimationEnd() {
	scheduleOnce([this](float) {
		DlgLvlClear::createDlg(GM->getCurrentLevel(), ScoreManager::get_Score(), this->_currentScoreStar, dynamic_cast<ui::Widget*>(_rootNode->getChildByName("goals")) , this, CC_CALLBACK_1(ScnLevelPlay::onLevelClearDlgClosed, this), DLG_ZORDER);
	}, 1.0f, "completeDlgDelay");
}

void ScnLevelPlay::onLevelClearDlgClosed(DlgLvlClear::CloseType closetype) {
	if(closetype == DlgLvlClear::CloseType::Continue) {
		// go to next level scene
		if(GM->getCurrentLevel() < GM->getLevelCount()) {
			GM->setCurrentLevel(GM->getCurrentLevel() + 1);
			if(GM->getTopLevel() < GM->getCurrentLevel())
				GM->setTopLevel(GM->getCurrentLevel());
			Director::getInstance()->replaceScene(TransitionFade::create(0.5f, ScnLoading::createScene(ScnLoading::Type::Level)));
		}
	}
	else {
		// go to level select scene
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, ScnLoading::createScene(ScnLoading::Type::Lobby)));
	}
}

void ScnLevelPlay::levelFail() {
	setTouchInputWorking(false);

	scheduleOnce([this](float) {
		setLogicWorking(false);
		DlgLvlFail::createDlg(GM->getCurrentLevel(), this, nullptr, DLG_ZORDER);
	}, 2.0f, "failDlgDelay");
}