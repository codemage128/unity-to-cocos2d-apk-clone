#include "SbMap.h"
#include "cocostudio/CocoStudio.h"
#include "global/SoundManager.h"
#include "ScnLevelSelect.h"
#include "common/Util.h"

using namespace cocostudio;


#define STAGE_NUM			25
static const int gStageLevelCounts[STAGE_NUM] = {
	30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
	30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
	30, 30, 30, 30, 30
}; //750
#define STAGE_IMAGE_NUM		8

MapDialog::MapDialog() {}

bool MapDialog::init() {
	Popup::initWithMask(true);
	Popup::setCloseByBackKey(true);
	Popup::setCloseByOuterClick(true);

	auto dlg = CSLoader::createNode("sbMap.csb");
	addChild(dlg);

	Button* btnClose = (Button*)dlg->getChildByName("btn_close");
	btnClose->addClickEventListener([this, btnClose](Ref*) {
		SoundManager::playEffectSound(SoundManager::SoundEffect::buttonClick);
		//Util::doButtonClick(btnClose, [this]() { this->close(); });
	});


	ScrollView* scroll = (ScrollView*)dlg->getChildByName("scroll");

	int totalLevel = GM->getLevelCount();

	int topLevel = GM->getTopLevel();
	int firstLevel = 1;


	float groupHeight = 220.f;
	float groupWidth = 450.f;
	int stageNum = 15;
	int totalBg = (int)ceil(totalLevel / (float)stageNum * (groupHeight / 124.f));
	totalBg += 3;
	int totalGroup = (int)ceil(totalLevel / (float)stageNum);


	scroll->setContentSize(Size(groupWidth, SCREEN_HEIGHT));
	scroll->setInnerContainerSize(Size(groupWidth, groupHeight*(totalGroup + 1.f)));

	auto rootContent = Node::create();
	rootContent->setContentSize(Size(groupWidth, groupHeight*(totalGroup + 1.f)));
	scroll->addChild(rootContent);



	float vp = (ceil(topLevel / (float)stageNum) - 1) / (totalGroup + 1.f);


	//log("pos=%f,totalGroup=%d,vp=%f", topLevel / (float)stageNum,totalGroup,vp);

	for(int i = 0; i < totalBg; i++) {
		auto bg = Sprite::create("image/mapui/slide_scene_slice.png");
		bg->setPosition(Vec2(80, 124 * i));
		rootContent->addChild(bg);
	}

	for(int i = 0; i < totalGroup; i++) {
		auto line = Sprite::create("image/mapui/map_line.png");
		line->setScaleX(1.7f);
		line->setPosition(Vec2(80, groupHeight * (i + 1)));
		rootContent->addChild(line);

		auto nMapNav = CSLoader::createNode("sbMapNode.csb");
		nMapNav->setPosition(Vec2(-10, i*groupHeight + groupHeight / 2));
		rootContent->addChild(nMapNav, 1);


		auto lblimgLevel = Sprite::create("image/mapui/map_level.png");
		lblimgLevel->setPosition(Vec2(170, groupHeight * (i + 1)));
		if(i % 2 == 1)
			lblimgLevel->setPositionX(250);
		rootContent->addChild(lblimgLevel, 1);

		auto lblLevel = Label::createWithBMFont("fonts/mapuilvlnum.fnt", __String::createWithFormat("%d", i)->getCString());
		lblLevel->setPosition(Vec2(lblimgLevel->getContentSize().width / 2, lblimgLevel->getContentSize().height / 2));
		lblimgLevel->addChild(lblLevel);
		int endLevel = firstLevel + stageNum - 1;
		if(endLevel > totalLevel)
			endLevel = totalLevel;
		lblLevel->setString(Util::getString(endLevel));
		if(endLevel >= 100)
			lblLevel->setScale(0.9f);

		auto btnMapNav = (cocos2d::ui::Button*)nMapNav->getChildByName("btn_mapnav");
		btnMapNav->loadTextureNormal(__String::createWithFormat("image/mapui/BC_landmark_symbol_%d.png", (i % 5 + 1))->getCString(), TextureResType::PLIST);


		Sprite* road;
		if(topLevel >= firstLevel) {
			road = Sprite::create(__String::createWithFormat("image/mapui/map_road_1%c.png", (i % 2 == 0 ? 'a' : 'b'))->getCString());
		}
		else {
			road = Sprite::create(__String::createWithFormat("image/mapui/map_road_0%c.png", (i % 2 == 0 ? 'a' : 'b'))->getCString());
		}

		road->setPosition(Vec2(200, groupHeight * i));
		road->setAnchorPoint(Vec2(0.5, 0));
		rootContent->addChild(road);

		auto lblStar = (cocos2d::ui::Text*)nMapNav->getChildByName("label_star")->getChildByName("lbl_starnumber");


		int n = stageNum;
		if(firstLevel + stageNum > totalLevel) {
			n = totalLevel - (firstLevel)+1;
		}

		if(topLevel >= firstLevel) {
			btnMapNav->setEnabled(true);
			btnMapNav->addClickEventListener([this, btnMapNav, firstLevel](Ref*) {
				SoundManager::playEffectSound(SoundManager::SoundEffect::buttonClick);
				//Util::doButtonClick(btnMapNav, [this, firstLevel]()
				{
					this->close();
					LevelSelectScene::getInstance()->refresh();
					GM->setCurrentLevel(firstLevel);
					LevelSelectScene::getInstance()->gotoLevel(firstLevel);
				}//);
			});

			int star = 0;
			for(int j = 0; j < n; j++)
				star += GM->getLevelStar(firstLevel + j);

			lblStar->setString(__String::createWithFormat("%d / %d", star, n*GM->getMaxLevelStar())->getCString());

		}
		else {
			btnMapNav->setEnabled(false);
			lblStar->setString(__String::createWithFormat("%d / %d", 0, n*GM->getMaxLevelStar())->getCString());
		}
		firstLevel += n;
	}
	//scroll->jumpToBottom();
	scroll->jumpToPercentVertical(100 - vp * 100);

	return true;



	int i, j;

	for(i = 0; i < STAGE_NUM; i++) {
		Node* stage = scroll->getChildByName(String::createWithFormat("stage%d", i + 1)->getCString());
		Button* btn = (Button*)stage->getChildByName("button");
		Text* count = (Text*)stage->getChildByName("count");
		Text* total = (Text*)stage->getChildByName("total");

		j = i % STAGE_IMAGE_NUM + 1;
		btn->loadTextures(
			String::createWithFormat("image/mapui/map_stage%d.png", j)->getCString(),
			String::createWithFormat("image/mapui/map_stage%d.png", j)->getCString(),
			String::createWithFormat("image/mapui/map_stage%d_.png", j)->getCString(),
			TextureResType::PLIST);

		int n = gStageLevelCounts[i];
		total->setString(String::createWithFormat("/ %d", n * GM->getMaxLife())->getCString());

		if(topLevel >= firstLevel) {
			btn->setEnabled(true);
			btn->addClickEventListener([this, btn, firstLevel](Ref*) {
				SoundManager::playEffectSound(SoundManager::SoundEffect::buttonClick);
				//Util::doButtonClick(btn, [this, firstLevel]()
				{
					this->close();
					LevelSelectScene::getInstance()->gotoLevel(firstLevel);
				}//);
			});

			int star = 0;
			for(j = 0; j < n; j++)
				star += GM->getLevelStar(firstLevel + j);
			if(star == n * GM->getMaxLevelStar())
				count->setTextColor(total->getTextColor());
			count->setString(Util::getString(star));
		}
		else {
			btn->setEnabled(false);
			count->setString("0");
		}
		firstLevel += n;
	}
	scroll->jumpToBottom();

	return true;
}

void MapDialog::onBeforeShow() {
	Size sz = Director::getInstance()->getWinSize();
	setPosition(sz.width, 0);
}

FiniteTimeAction* MapDialog::getDefaultShowAction() {
	Size sz = Director::getInstance()->getWinSize();
	return EaseBounceIn::create(MoveBy::create(0.15f, Point(-sz.width, 0)));
}

FiniteTimeAction* MapDialog::getDefaultCloseAction() {
	Size sz = Director::getInstance()->getWinSize();
	return EaseBounceOut::create(MoveBy::create(0.15f, Point(sz.width, 0)));
}