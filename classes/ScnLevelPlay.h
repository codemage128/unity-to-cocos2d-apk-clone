#ifndef __SCENE_LEVEL_H_
#define __SCENE_LEVEL_H_

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "DlgLevelQuit.h"
#include "DlgLvlClear.h"

USING_NS_CC;

#define BOOSTERDESC_ZORDER 20
#define MENUCOVER_ZORDER 30
#define DLG_ZORDER 50
#define FXANIMATION_ZORDER 40

class Goal;
enum class ItemType;
enum class InventoryItemType;

class ScnLevelPlay : public cocos2d::Layer {

	// ui ==============================
public:
    static cocos2d::Scene* createScene();

private:
    virtual bool init() override;
	CREATE_FUNC(ScnLevelPlay);

protected:
	Node* _rootNode;
	cocostudio::timeline::ActionTimeline* _sceneAction;

	ui::Widget* _menuCover;

	void onPauseClicked(Ref* ref);
	void onPauseCancelled(Ref* ref);
	void onSoundToggled(Ref* ref, ui::CheckBox::EventType evtType);
	void onMusicToggled(Ref* ref, ui::CheckBox::EventType evtType);
	void onQuitClick(Ref* ref);
	void onQuitClosed(DlgLevelQuit::Result closeType);

	void onFrameEvent(cocostudio::timeline::Frame* frameEvt);
	void onKeyReleasedEvent(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* evt);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* evt);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* evt);

	virtual void onEnterTransitionDidFinish();
	virtual void onExitTransitionDidStart();

private:
	bool _isPaused = false;

	void pause();
	void pauseCancel();

	// level objective animation------------
private:
	Node* _fxLvlObjective = nullptr;
	cocostudio::timeline::ActionTimeline* _fxLvlObjectiveAction = nullptr;

	// level end----------------------------
private:
	Node* _fxLvlClearLogo = nullptr;
	cocostudio::timeline::ActionTimeline* _fxLvlClearLogoAnimation = nullptr;
private:
	void showLogoAnimation();
	void logoAnimationEnd();
	void charAnimationEnd();
	void onLevelClearDlgClosed(DlgLvlClear::CloseType closetype);
public:
	void levelComplete();
	void levelFail();

	// logic ==============================
private:
	bool _isLogicWorking = false;
	bool _isTouchWorking = false;
public:
	void setLogicWorking(bool enable = true);
	void setTouchInputWorking(bool enable = true);
private:
	void onFrame(float delta);



	// top panel ==============================
protected:
	Node* _bearHead;
	cocostudio::timeline::ActionTimeline* _bearHeadAction;
	ui::Text* _lblMoveCount;
	ui::LoadingBar* _barScore;
	cocos2d::Sprite* _sprScoreStarSlot[3];
	cocos2d::Sprite* _sprScoreStar[3];
	cocos2d::Node* _particleScoreStar[3];
	cocostudio::timeline::ActionTimeline* _goalStarAction;
	cocos2d::Node* _particleGoal[3];
	ui::ImageView* _imgGoalIcon[3];
	ui::Text* _lblGoalCounter[3];
	ui::ImageView* _spGoalComplete[3];
	int _currentScoreStar = 0;
public:
	void initTopPanel();
	void PrepareGoals(std::vector<Goal*>& goals);
	void setMovesLeft(int count);
	void InitStars(std::vector<int>& stars);
	void updateScorebar(int score);
	int getGoalIdx(ItemType goaltype);
	cocos2d::Vec2 getGoalIconPos(int idx);
	float getGoalIconScale(int idx);
	void playGoalFx(int idx);
	void updateGoalCount(int idx, int count);
private:
	void onScoreBarChange(float value);
	void showGoalStarAnimation();

	// bottom panel ==============================
protected:
	ui::Button* _btnBooster[4];
	ui::Text* _lblBoosterCount[4];
	cocos2d::Node* _boosterDesc = nullptr; cocostudio::timeline::ActionTimeline* _boosterDescAnim = nullptr;
public:
	void initBottomPanel();
	void updateBottomPanel();
	void hideBoosterDesc();
	void showBoosterDesc(InventoryItemType type);

	void onBoosterHammerClicked(cocos2d::Ref*);
	void onBoosterBoxingGloveClicked(cocos2d::Ref*);
	void onBoosterAnvilClicked(cocos2d::Ref*);
	void onBoosterDiceClicked(cocos2d::Ref*);
	void onBoosterPaintBrushClicked(cocos2d::Ref*);
};

#endif // __SCENE_LEVEL_H_
