#include "common/Util.h"
#include "global/SoundManager.h"
#include "cocostudio/CocoStudio.h"
#include "ScnLevelSelectNode.h"
#include "ScnLevelSelect.h"
#include "SbMap.h"
#include "ScnLoading.h"
#include "DlgDailyBonus.h"
#include "DlgDailyChallenge.h"
#include "DlgSetting.h"
#include "DlgBuyCoin.h"
#include "DlgAppQuit.h"
#include "DlgLvlStart.h"
#include "DlgLifeRefill.h"
#include "game/Extension.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocostudio;

enum { kZNormal, kZPopup, };
enum { kZWorld, kZUI, };

LevelSelectScene* LevelSelectScene::_instance = nullptr;

Scene * LevelSelectScene::createScene() {
	auto scene = Scene::create();
	auto layer = new LevelSelectScene();
	layer->autorelease();
	scene->addChild(layer);
	return scene;
}

LevelSelectScene::~LevelSelectScene() {
	_instance = nullptr;
	for(int i = 0; i < _bgSegments.getCount(); i++)
		delete _bgSegments[i];
}

#define BG_SEG_COUNT	4

LevelSelectScene::LevelSelectScene() {
	_instance = this;
	_prevOffsetY = 0;
	_chargeTime = GM->getLifeChargeTime();
	_updateTime = 0;

	SoundManager::playBgMusic(SoundManager::MusicKind::mainbg);

#pragma region Level UI

	auto root = CSLoader::createNode("scnLevelSelectUI.csb");
	auto ui = root->getChildByName("ui");
	ui->removeFromParent();
	addChild(ui, kZUI);

	auto life_bar = ui->getChildByName("energy_bar");
	dynamic_cast<Button*>(life_bar->getChildByName("button"))->addClickEventListener(CC_CALLBACK_1(LevelSelectScene::onPlusLife, this));
	dynamic_cast<Button*>(life_bar->getChildByName("button+"))->addClickEventListener(CC_CALLBACK_1(LevelSelectScene::onPlusLife, this));
	Util::applyDefaultButtonPressFx(dynamic_cast<Button*>(life_bar->getChildByName("button+")));

	_lblLife = dynamic_cast<Text*>(life_bar->getChildByName("lbl_energy"));
	_lblLife->setString(String::createWithFormat("%d/%d", GM->getLife(), GM->getMaxLife())->getCString());
	_lblLifeTime = dynamic_cast<Text*>(life_bar->getChildByName("lbl_time"));

	auto coin_bar = ui->getChildByName("coin_bar");
	dynamic_cast<Button*>(coin_bar->getChildByName("button"))->addClickEventListener(CC_CALLBACK_1(LevelSelectScene::onPlusCoin, this));
	dynamic_cast<Button*>(coin_bar->getChildByName("button+"))->addClickEventListener(CC_CALLBACK_1(LevelSelectScene::onPlusCoin, this));
	Util::applyDefaultButtonPressFx(dynamic_cast<Button*>(coin_bar->getChildByName("button+")));

	_lblCoin = dynamic_cast<Text*>(coin_bar->getChildByName("lbl_coin"));
	_lblCoin->setString(Ext_itos(GM->getCoin()));
	
	Button* btnOption = dynamic_cast<Button*>(ui->getChildByName("btn_option"));
	btnOption->addClickEventListener(CC_CALLBACK_1(LevelSelectScene::onSettingClick, this));
	Util::applyDefaultButtonPressFx(btnOption);

	_lblOption = dynamic_cast<Text*>(btnOption->getChildByName("label"));

	Button* btnMap = dynamic_cast<Button*>(ui->getChildByName("btn_map"));
	btnMap->addClickEventListener(CC_CALLBACK_1(LevelSelectScene::onMapClick, this));
	Util::applyDefaultButtonPressFx(btnMap);
	_lblMapStar = dynamic_cast<Text*>(btnMap->getChildByName("count"));
	dynamic_cast<Text*>(btnMap->getChildByName("total"))->setString(String::createWithFormat("/ %d", GM->getLevelCount() * GM->getMaxLevelStar())->getCString());

	_lblDailyBonusTime = dynamic_cast<Text*>(ui->getChildByName("dailybonus")->getChildByName("counter"));
	dynamic_cast<Button*>(ui->getChildByName("dailybonus"))->addClickEventListener(CC_CALLBACK_1(LevelSelectScene::onDailyBonusClick, this));
	Util::applyDefaultButtonPressFx(dynamic_cast<Button*>(ui->getChildByName("dailybonus")));
	dynamic_cast<Button*>(ui->getChildByName("dailychallenge"))->addClickEventListener(CC_CALLBACK_1(LevelSelectScene::onDailyChallengeClick, this));
	Util::applyDefaultButtonPressFx(dynamic_cast<Button*>(ui->getChildByName("dailychallenge")));
	_lblDailyChallengeTime = dynamic_cast<Text*>(ui->getChildByName("dailychallenge")->getChildByName("counter"));

	// set timer for every second
	schedule(CC_CALLBACK_1(LevelSelectScene::onSecond, this), 1.0f, "onsecond");


#pragma endregion



#pragma region Level Map

	//create worldmap
	//create scrollview
	_scrollView = cocos2d::extension::ScrollView::create();
	_scrollView->setDelegate(this);
	_scrollView->setViewSize(Size(SCREEN_WIDTH, SCREEN_HEIGHT));
	_scrollView->setDirection(cocos2d::extension::ScrollView::Direction::VERTICAL);
	_scrollView->setClippingToBounds(true);
	addChild(_scrollView, kZWorld);

	//make segments
	auto map = CSLoader::createNode("scnLevelSelectView.csb");// root->getChildByName("map");//
	auto bg0 = map->getChildByName("seg0");
	bg0->removeFromParent();
	bg0->setPosition(SCREEN_WIDTH / 2, bg0->getContentSize().height / 2);
	_scrollView->addChild(bg0);

	_bottomHeight = bg0->getContentSize().height;
	_hSum = _bottomHeight;
	_nSum = 0;
	int i = 0;
	for(i = 1; i <= BG_SEG_COUNT; i++) {
		auto seg = map->getChildByName(String::createWithFormat("seg%d", i)->getCString());

		auto bgSeg = new BgSegment(i - 1, seg);
		bgSeg->setStartLevel(_nSum + 1);
		_bgSegments.add(bgSeg);

		seg->removeFromParent();
		seg->setPosition(SCREEN_WIDTH / 2, _hSum + bgSeg->getHeight() / 2);
		_scrollView->addChild(seg);

		_hSum += bgSeg->getHeight();
		_nSum += bgSeg->getLevelCount();
	}
	_hSum -= _bottomHeight;
	_prevOffsetY = -_hSum / 3;

	_maplock = (Sprite*)map->getChildByName("maplock");
	_maplock->removeFromParent();
	_scrollView->addChild(_maplock);
	_maplock->setLocalZOrder(2001);


	mHeader = Sprite::create("image/mapui/mapuilvlcur.png");
	mHeader->setAnchorPoint(Point(0.5f, 0));
	mHeader->setScale(0.5f);
	_scrollView->addChild(mHeader);

#pragma endregion



	//calc scroll size
	//int hmax = getOffsetForLevel(_levelManager->getLevelCount());
	//_scrollView->setContentSize(Size(SCREEN_X, hmax + SCREEN_Y / 3 * 2));

	onLanguageChanged();
	refresh();
}

void LevelSelectScene::updateCoinLifeBar() {
	_lblCoin->setString(Ext_itos(GM->getCoin()));
	_lblLife->setString(String::createWithFormat("%d/%d", GM->getLife(), GM->getMaxLife())->getCString());
}

float LevelSelectScene::getOffsetForLevel(int index, int* pBgSegNo) {
	float y = _hSum * (index / _nSum);
	index = index % _nSum;
	if(index == 0) {
		if(pBgSegNo != nullptr)
			*pBgSegNo = _bgSegments.getCount() - 1;


		int i = _bgSegments.find([](BgSegment* b) { return b->getId() == 0; }, nullptr);

		float ypos = _bgSegments[i]->getHeight() - \
			_bgSegments[i]->getButtonPosY(_bgSegments[i]->getLevelCount() - 1);

		y -= ypos;

	}
	else {
		int i = _bgSegments.find([](BgSegment* b) { return b->getId() == 0; }, nullptr);
		for(; index > 0; i++) {
			if(i >= _bgSegments.getCount())
				i -= _bgSegments.getCount();
			if(index > _bgSegments[i]->getLevelCount()) {
				y += _bgSegments[i]->getHeight();
				index -= _bgSegments[i]->getLevelCount();
			}
			else {
				y += _bgSegments[i]->getButtonPosY(index - 1);
				index = 0;
				if(pBgSegNo != nullptr)
					*pBgSegNo = i;
			}
		}
	}
	return y;
}

#define LEVELNUM_PER_PAGE	15

void LevelSelectScene::refresh(bool reset) {
	_lblMapStar->setString(Util::getString(GM->getTotalStar()));

	//calc scroll size
	int topLevel = GM->getTopLevel();
	topLevel = ((topLevel - 1) / LEVELNUM_PER_PAGE) * LEVELNUM_PER_PAGE + (LEVELNUM_PER_PAGE);
	if(topLevel >= GM->getLevelCount()) {
		topLevel = GM->getLevelCount();
		//_maplock->setVisible(false);
	}
	else {
		//_maplock->setVisible(true);
	}
	if(topLevel > GM->getLevelCount() - LEVELNUM_PER_PAGE)
		_maplock->initWithFile("image/mapui/cloud_comingsoon.png");

	int hmax = getOffsetForLevel(topLevel) + _bottomHeight;
	_scrollView->setContentSize(Size(SCREEN_WIDTH, hmax + SCREEN_HEIGHT / 3 * 2));
	_maplock->setPosition(SCREEN_WIDTH / 2, hmax + SCREEN_HEIGHT / 3 * 2 - _maplock->getContentSize().height / 2 + 100);//

	//centerize current level and update stars
	int index = GM->getCurrentLevel();
	gotoLevel(index);

	//for (int i = 0; i < _bgSegments.getCount(); i++)
	//	_bgSegments[i]->refresh(reset);

	refreshLifeTime();
}

void LevelSelectScene::gotoLevel(int index) {
	float newOffset = getOffsetForLevel(index) + _bottomHeight;
	newOffset -= SCREEN_HEIGHT / 3;
	if(newOffset < 0)
		newOffset = 0;
	else if(newOffset > _scrollView->getContentSize().height - SCREEN_HEIGHT)
		newOffset = _scrollView->getContentSize().height - SCREEN_HEIGHT;

	float diff = _prevOffsetY + newOffset;
	if(diff > _hSum) {
		int r = (int)(diff / _hSum);
		float h = _hSum * r;
		int n = _nSum * r;
		for(int i = 0; i < _bgSegments.getCount(); i++) {
			auto seg = _bgSegments[i];
			seg->setPosY(seg->getPosY() + h);
			seg->setStartLevel(seg->getStartLevel() + n);
		}
		_prevOffsetY -= h;
	}

	_scrollView->setContentOffset(Vec2(0, -newOffset));

	for(int i = 0; i < _bgSegments.getCount(); i++)
		_bgSegments[i]->refresh(true);
}

void LevelSelectScene::scrollViewDidScroll(cocos2d::extension::ScrollView* view) {
	auto layout = view->getContainer();
	float currentY = layout->getPositionY();

	if(currentY > 0) {
		view->setContentOffset(Vec2(0, 0));
	}
	if(-currentY > layout->getContentSize().height - view->getViewSize().height) {
		//view->setContentOffset(Vec2(0, -layout->getContentSize().height + view->getViewSize().height));
		_maplock->stopAllActions();
		//_maplock->setOpacity(125);
		_maplock->runAction(FadeTo::create(0.3f, 125));
	}
	else {
		_maplock->stopAllActions();
		_maplock->setOpacity(255);
	}

	float offsetY = view->getContentOffset().y;
	float diff = _prevOffsetY - offsetY;

	float margin = _hSum / 3 - _bottomHeight;
	if(diff > 0)//scroll up
	{
		while(true) {
			if(diff < margin)
				break;
			auto first = _bgSegments[0];
			auto last = _bgSegments.getLast();
			_bgSegments.removeAt(0);
			_bgSegments.add(first);
			auto h = first->getHeight();
			first->setPosY(last->getTopY() + h / 2);
			first->setStartLevel(last->getLastLevel() + 1);
			first->refresh();
			diff -= h;
			_prevOffsetY -= h;
		}
	}
	else if(diff < 0)//scroll down
	{
		while(true) {
			if(-diff < margin)
				break;
			auto first = _bgSegments[0];
			if(first->getFirstLevel() == 1)
				break;
			auto last = _bgSegments.getLast();
			_bgSegments.removeLast();
			_bgSegments.insert(last, 0);
			auto h = last->getHeight();
			last->setPosY(first->getBottomY() - h / 2);
			last->setStartLevel(first->getFirstLevel() - last->getLevelCount());
			last->refresh();
			diff += h;
			_prevOffsetY += h;
		}
	}
}

void LevelSelectScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
	if(keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE || keyCode == EventKeyboard::KeyCode::KEY_ESCAPE) {
		event->stopPropagation();
		showExitDlg();
	}
}

void LevelSelectScene::onEnterTransitionDidFinish() {
	Layer::onEnterTransitionDidFinish();

	// keyboard
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyReleased = CC_CALLBACK_2(LevelSelectScene::onKeyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyListener, this);

	
	/*if (GameData::getInstance()->getTodayAvailableAds(3)>0)
	{
	DailyRewardDialog* dlg = DailyRewardDialog::create();
	dlg->show(this, kZPopup);

	GameData::getInstance()->setTodayAdsClick(3);
	}
	else {
		int topLevel = GameData::getInstance()->getTopLevel();
		auto absDays = GameData::getInstance()->getLastRateAbsDays();
		if(topLevel > 20 && absDays >= 7 && !GameData::getInstance()->isRateClickOk()) {
			auto dlg = RateDialog::create();
			dlg->btn_close->addClickEventListener([dlg](Ref*) {
				SoundManager::playEffectSound(SFX::Button);
				dlg->close();
			});
			dlg->btn_cancel->addClickEventListener([dlg](Ref*) {
				SoundManager::playEffectSound(SFX::Button);
				dlg->close();
			});
			dlg->btn_rate->addClickEventListener([dlg](Ref*) {
				SoundManager::playEffectSound(SFX::Button);
				dlg->close();
				GameData::getInstance()->clickRateOk();
				GGBridge::rateApp();
			});

			dlg->show(this, kZPopup);
			GameData::getInstance()->setRateAbsDays();
		}
	}*/
	if(GM->getCurrentLevel() > 0) {
		moveHeaderTo(GM->getTopLevel(), 1);
	}
	else {
		moveHeaderTo(GM->getTopLevel());
	}
}

void LevelSelectScene::showExitDlg() {
	DlgAppQuit::createDlg(this,
	[](DlgAppQuit::Result result) {
		if(result == DlgAppQuit::Result::YES) {
			GM->save();
			Director::getInstance()->end();
		}
	}, kZPopup);
}

void LevelSelectScene::onSelectLevel(Ref* pSender) {
	int index = ((Node*)pSender)->getTag();
	onSelectLevelIndex(index);
}

void LevelSelectScene::onSelectLevelIndex(int index) {
	if(GM->setCurrentLevel(index)) {
		DlgLvlStart::createDlg(GM->getCurrentLevel(), GM->getLevelStar(GM->getCurrentLevel()), this, CC_CALLBACK_1(LevelSelectScene::onLvlStartDlgClosed, this), kZPopup);
	}
}

void LevelSelectScene::onLvlStartDlgClosed(DlgLvlStart::CloseType closeType) {
	if(closeType == DlgLvlStart::CloseType::Start) {
		//if (_levelManager->setCurrentLevel(index))
		{
			int life = GM->getLife();
			if(life > 0) {
				//GM->plusLife(-1);
				if(life == GM->getMaxLife()) {
					_chargeTime = GM->getLifeChargeTime() + 1;
					onTick();
					_updateTime = 0;
					scheduleUpdate();
					GM->setLastLifeTime(time(NULL));
				}

				Director::getInstance()->replaceScene(TransitionFade::create(0.5f, ScnLoading::createScene(ScnLoading::Type::Level)));
			}
			else {
				//LifeShopDialog* dlg = LifeShopDialog::create();
				//dlg->show(this, kZPopup);
				onPlusLife(nullptr);
			}
		}
	}
}

void LevelSelectScene::onLanguageChanged() {
	Localization* localization = Localization::getInstance();
	if(GM->getLife() >= GM->getMaxLife())
		_lblLifeTime->setString(localization->getString("HeartMax"));
	_lblOption->setString(localization->getString("BtnOption"));
}

void LevelSelectScene::onPlusLife(Ref* pSender) {
	DlgLifeRefill::createDlg(this, [this](DlgLifeRefill::Result) { this->updateCoinLifeBar(); }, kZPopup);
}

void LevelSelectScene::onPlusCoin(Ref* pSender) {
	DlgBuyCoin::createDlg(this, [this]() { this->updateCoinLifeBar(); }, kZPopup);
}

void LevelSelectScene::onDailyBonusClick(Ref* ref) {
	DlgDailyBonus::createDlg(this, nullptr, kZPopup);
}

void LevelSelectScene::onDailyChallengeClick(Ref* ref) {
	DlgDailyChallenge::createDlg(this, nullptr, kZPopup);
}

void LevelSelectScene::onSettingClick(Ref* ref) {
	DlgSetting::createDlg(this, nullptr, kZPopup);
}

void LevelSelectScene::onMapClick(Ref* ref) {
	MapDialog::create()->show(this, kZPopup);
}

void LevelSelectScene::updateLifeTime() {
	_lblLife->setString(String::createWithFormat("%d/%d", GM->getLife(), GM->getMaxLife())->getCString());
	if(GM->getLife() < GM->getMaxLife()) {
		_lblLifeTime->setString(Util::getTimeString(_chargeTime));
		//if (_lifeShop)
		//	_lifeShop->updateLifeChargeTime(_chargeTime);
	}
	else
		_lblLifeTime->setString(Localization::getInstance()->getString("HeartMax"));
}

Vec2 LevelSelectScene::getPositionForLevel(int index, int * pBgSegNo) {
	float y = _hSum * (index / _nSum);
	index = index % _nSum;
	float x = 0;
	if(index == 0) {
		//	if (pBgSegNo != nullptr)
		//		*pBgSegNo = _bgSegments.getCount() - 1;

		int i = _bgSegments.find([](BgSegment* b) { return b->getId() == 0; }, nullptr);

		x = _bgSegments[i - 1]->getButtonPosX(_bgSegments[i - 1]->getLevelCount() - 1);

		float ypos = _bgSegments[i - 1]->getHeight() - \
			_bgSegments[i - 1]->getButtonPosY(_bgSegments[i - 1]->getLevelCount() - 1);

		y -= ypos;

	}
	else {
		int i = _bgSegments.find([](BgSegment* b) { return b->getId() == 0; }, nullptr);
		for(; index > 0; i++) {
			if(i >= _bgSegments.getCount())
				i -= _bgSegments.getCount();
			if(index > _bgSegments[i]->getLevelCount()) {
				int yy = _bgSegments[i]->getHeight();
				y += yy;
				index -= _bgSegments[i]->getLevelCount();
			}
			else {
				int yy = _bgSegments[i]->getButtonPosY(index - 1);
				x = _bgSegments[i]->getButtonPosX(index - 1);
				y += yy;

				index = 0;
				if(pBgSegNo != nullptr)
					*pBgSegNo = i;
			}
		}
	}
	return Vec2(x, y);
}

void LevelSelectScene::moveHeaderTo(int index, int beforelevel) {
	if(beforelevel == 0) {
		Vec2 pos = getPositionForLevel(index);
		pos.y = pos.y + _bottomHeight + 38;
		//pos.x = pos.x + origin.x;
		mHeader->stopAllActions();
		mHeader->setPosition(pos);
		auto act = EaseSineInOut::create(MoveTo::create(0.8f, Vec2(mHeader->getPosition().x, mHeader->getPosition().y + 5)));
		auto act1 = EaseSineInOut::create(MoveTo::create(0.8f, Vec2(mHeader->getPosition().x, mHeader->getPosition().y)));
		mHeader->runAction(RepeatForever::create(Sequence::create(act, act1, NULL)));
	}
	else {
		Vec2 pos = getPositionForLevel(index);
		pos.y = pos.y + _bottomHeight + 38;
		//pos.x = pos.x + origin.x;

		/*Vec2 oldpos = getPositionForLevel(beforelevel);
		oldpos.y = oldpos.y + _bottomHeight + 38;
		oldpos.x = oldpos.x + origin.x;*/

		mHeader->stopAllActions();
		auto move = MoveTo::create(1, pos);

		mHeader->runAction(Sequence::create(move,
			CallFunc::create([&]() {
			//g_trans_scene = 0;
		}),
			DelayTime::create(0.1f),
			CallFunc::create([&]() {
			auto act = EaseSineInOut::create(MoveTo::create(0.8f, Vec2(mHeader->getPosition().x, mHeader->getPosition().y + 5)));
			auto act1 = EaseSineInOut::create(MoveTo::create(0.8f, Vec2(mHeader->getPosition().x, mHeader->getPosition().y)));
			mHeader->runAction(RepeatForever::create(Sequence::create(act, act1, NULL)));
		}),
			NULL));

	}
}

void LevelSelectScene::refreshLifeTime() {
	if(GM->getLife() < GM->getMaxLife()) {
		time_t past = GM->getLastLifeTime();
		if(past != 0) {
			time_t now = time(NULL);
			time_t passed = now - past;
			int n = (int)(passed / GM->getLifeChargeTime());
			if(n > 0) {
				GM->plusLife(n);
				GM->setLastLifeTime(now);
			}
			if(GM->getLife() < GM->getMaxLife()) {
				n = (int)(passed % (int)GM->getLifeChargeTime());
				_chargeTime = GM->getLifeChargeTime() - n;
			}
		}

		if(GM->getLife() < GM->getMaxLife()) {
			_updateTime = 0;
			scheduleUpdate();
		}
	}
	updateLifeTime();
}

void LevelSelectScene::onTick() {
	_chargeTime--;
	if(_chargeTime == 0) {
		GM->plusLife(1);
		GM->setLastLifeTime(time(NULL));
		if(GM->getLife() < GM->getMaxLife())
			_chargeTime = GM->getLifeChargeTime();
		else
			unscheduleUpdate();
		//if (_lifeShop)
		//	_lifeShop->refresh();
	}
	updateLifeTime();
}

void LevelSelectScene::update(float dt) {
	_updateTime += dt;
	if(_updateTime >= 1) {
		_updateTime -= 1;
		onTick();
	}
}

void LevelSelectScene::onSecond(float) {
	_lblDailyBonusTime->setString(DlgDailyBonus::getDailyBonusTime());
	//*TODO*/_lblDailyChallengeTime->setString("");
}