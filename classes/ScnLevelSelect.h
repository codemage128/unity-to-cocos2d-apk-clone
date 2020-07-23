#ifndef __LEVELSELECTSCENE_H__
#define __LEVELSELECTSCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"
#include "global/Localization.h"
#include "ext/List.h"
#include "ext/IntVec2.h"

#include "DlgLvlStart.h"

class BgSegment;

USING_NS_CC;

class LevelSelectScene : public cocos2d::Layer, public cocos2d::extension::ScrollViewDelegate, ILocalized
{
public:
	static cocos2d::Scene *createScene();
	static LevelSelectScene* getInstance() { return _instance; }

	LevelSelectScene();
	~LevelSelectScene();

	void onEnterTransitionDidFinish();
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void showExitDlg();
	//void showResultDlg();

	void refresh(bool reset = false);

	virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view);
	void gotoLevel(int index);

	void onSelectLevel(cocos2d::Ref* pSender);
	void onSelectLevelIndex(int index);

	void onLanguageChanged();


protected:
	float getOffsetForLevel(int index) { int p; return getOffsetForLevel(index, &p); }
	float getOffsetForLevel(int index, int* pBgSegNo);

	Vec2 getPositionForLevel(int index) { int p; return getPositionForLevel(index, &p); }
	Vec2 getPositionForLevel(int index, int* pBgSegNo);

	void onPlusLife(cocos2d::Ref* pSender);
	void onPlusCoin(cocos2d::Ref* pSender);
	void onDailyBonusClick(Ref* ref);
	void onDailyChallengeClick(Ref* ref);
	void onSettingClick(Ref* ref);
	void onMapClick(Ref* ref);

	void updateCoinLifeBar();

	void onLvlStartDlgClosed(DlgLvlStart::CloseType closeType);

	//life
	void refreshLifeTime();
	void onTick();
	void update(float dt);
	void updateLifeTime();

	//bonustime
	void onSecond(float);
	
	void moveHeaderTo(int level, int beforelevel = 0);
	Sprite* mHeader;

protected:
	static LevelSelectScene* _instance;
	cocos2d::extension::ScrollView* _scrollView;
	List<BgSegment*> _bgSegments;
	float _prevOffsetY;
	float _hSum;
	int _nSum;
	float _bottomHeight;

	float _updateTime;
	float _chargeTime;
	cocos2d::Sprite* _maplock;

	//ui
	cocos2d::ui::Text* _lblLife;
	cocos2d::ui::Text* _lblLifeTime;
	cocos2d::ui::Text* _lblCoin;
	cocos2d::ui::Text* _lblOption;
	cocos2d::ui::Text* _lblMapStar;
	cocos2d::ui::Text* _lblDailyBonusTime;
	cocos2d::ui::Text* _lblDailyChallengeTime;
};

#endif //__LEVELSELECTSCENE_H__