#include "ScnLevelPlay.h"
#include "cocostudio/CocoStudio.h"
#include "global/GameManager.h"
#include "global/SoundManager.h"
#include "common/Util.h"
#include "DlgLevelQuit.h"
#include "DlgLvlClear.h"
#include "DlgLvlFail.h"
#include "game/LevelBuilder.h"
#include "game/Level.h"
#include "game/ImageLibrary.h"
#include "game/Goal.h"
#include "game/Extension.h"
#include "game/Mathf.h"
#include "game/Animation.h"

void ScnLevelPlay::initTopPanel() {
	_lblMoveCount = Util::getChildNode<ui::Text*>(_rootNode, "move_count");
	_barScore = Util::getChildNode<ui::LoadingBar*>(_rootNode, "scorebar");
	
	_sprScoreStarSlot[0] = Util::getChildNode<Sprite*>(_rootNode, "scorestarslot1");
	_sprScoreStarSlot[1] = Util::getChildNode<Sprite*>(_rootNode, "scorestarslot2");
	_sprScoreStarSlot[2] = Util::getChildNode<Sprite*>(_rootNode, "scorestarslot3");
	(_sprScoreStar[0] = Util::getChildNode<Sprite*>(_rootNode, "scorestarslot1/star"))->setVisible(false);
	(_sprScoreStar[1] = Util::getChildNode<Sprite*>(_rootNode, "scorestarslot2/star"))->setVisible(false);
	(_sprScoreStar[2] = Util::getChildNode<Sprite*>(_rootNode, "scorestarslot3/star"))->setVisible(false);
	_goalStarAction = CSLoader::createTimeline("particle/goalStar.csb");
	_goalStarAction->retain();
	(_particleScoreStar[0] = Util::getChildNode<Node*>(_rootNode, "scorestarslot1/particle"))->setVisible(false);
	(_particleScoreStar[1] = Util::getChildNode<Node*>(_rootNode, "scorestarslot2/particle"))->setVisible(false);
	(_particleScoreStar[2] = Util::getChildNode<Node*>(_rootNode, "scorestarslot3/particle"))->setVisible(false);

	(_particleGoal[0] = Util::getChildNode<Node*>(_rootNode, "goals/particle1"))->setVisible(false);
	(_particleGoal[1] = Util::getChildNode<Node*>(_rootNode, "goals/particle2"))->setVisible(false);
	(_particleGoal[2] = Util::getChildNode<Node*>(_rootNode, "goals/particle3"))->setVisible(false);
	(_imgGoalIcon[0] = Util::getChildNode<ui::ImageView*>(_rootNode, "goals/icon1"))->setVisible(false);
	(_imgGoalIcon[1] = Util::getChildNode<ui::ImageView*>(_rootNode, "goals/icon2"))->setVisible(false);
	(_imgGoalIcon[2] = Util::getChildNode<ui::ImageView*>(_rootNode, "goals/icon3"))->setVisible(false);
	(_lblGoalCounter[0] = Util::getChildNode<ui::Text*>(_rootNode, "goals/icon1/count"));
	(_lblGoalCounter[1] = Util::getChildNode<ui::Text*>(_rootNode, "goals/icon2/count"));
	(_lblGoalCounter[2] = Util::getChildNode<ui::Text*>(_rootNode, "goals/icon3/count"));
	(_spGoalComplete[0] = Util::getChildNode<ui::ImageView*>(_rootNode, "goals/icon1/complete"))->setVisible(false);
	(_spGoalComplete[1] = Util::getChildNode<ui::ImageView*>(_rootNode, "goals/icon2/complete"))->setVisible(false);
	(_spGoalComplete[2] = Util::getChildNode<ui::ImageView*>(_rootNode, "goals/icon3/complete"))->setVisible(false);


	// play bear head character
	_bearHead = _rootNode->getChildByName("bear");
	_bearHeadAction = CSLoader::createTimeline("charactor/bearhead.csb");
	_bearHeadAction->play("inplay", true);
	_bearHead->runAction(_bearHeadAction);

}

void ScnLevelPlay::PrepareGoals(std::vector<Goal*>& goals) {
	// hide all goals
	Vec2 poses[3];
	for(int i = 0; i < 3; i++) {
		// hide icon
		_imgGoalIcon[i]->setVisible(false);
		poses[i] = _imgGoalIcon[i]->getPosition();
		// hide particle
		_particleGoal[i]->setVisible(false);
		// unset type
		_imgGoalIcon[i]->setUserData((void*)-1);
	}
	// reposition goals
	if(goals.size() == 1) {
		_imgGoalIcon[0]->setPosition(poses[1]);
		_particleGoal[0]->setPosition(poses[1]);
	}
	else if(goals.size() == 2) {
		_imgGoalIcon[0]->setPosition(poses[0].lerp(poses[1], 0.3f));
		_imgGoalIcon[1]->setPosition(poses[2].lerp(poses[1], 0.3f));
		_particleGoal[0]->setPosition(poses[0].lerp(poses[1], 0.3f));
		_particleGoal[1]->setPosition(poses[2].lerp(poses[1], 0.3f));
	}
	// set goals
	for(int i = 0; i < (int)goals.size(); i++) {
		// show goal
		_imgGoalIcon[i]->setVisible(true);
		// set icon
		cocos2d::Texture2D* tex = IMGLIB->GetGoalSpriteByItemType(goals[i]->Type)->getTexture();
		_imgGoalIcon[i]->loadTexture(tex->getPath());
		// scale appropriately
		const float goaliconsize = 70.0f;
		cocos2d::Size newsize(tex->getPixelsWide()*goaliconsize / tex->getPixelsHigh(), goaliconsize);
		_imgGoalIcon[i]->setContentSize(newsize);
		// set count
		_lblGoalCounter[i]->setString(Ext_itos(goals[i]->Count));
		// set type
		_imgGoalIcon[i]->setUserData((void*)(int)goals[i]->Type);
	}
}

int ScnLevelPlay::getGoalIdx(ItemType goaltype) {
	int ret = -1;
	for(int i = 0; i < 3; i++)
		if((int)_imgGoalIcon[i]->getUserData() == (int)goaltype)
			ret = i;
	return ret;

}
cocos2d::Vec2 ScnLevelPlay::getGoalIconPos(int idx) {
	return _rootNode->convertToNodeSpace(_imgGoalIcon[idx]->convertToWorldSpaceAR(Vec2::ZERO));
}
float ScnLevelPlay::getGoalIconScale(int idx) {
	return (_rootNode->convertToNodeSpace(_imgGoalIcon[idx]->convertToWorldSpaceAR(Vec2::ONE*_imgGoalIcon[idx]->getContentSize().width / _imgGoalIcon[idx]->getVirtualRendererSize().width)) -
			_rootNode->convertToNodeSpace(_imgGoalIcon[idx]->convertToWorldSpaceAR(Vec2::ZERO))).x;
}
void ScnLevelPlay::playGoalFx(int idx) {
	// replay particles
	_particleGoal[idx]->setVisible(true);
	for(Node* subnode : _particleGoal[idx]->getChildren())
		dynamic_cast<ParticleSystemQuad*>(subnode)->resetSystem();
	// stop original aniamtion
	if(_imgGoalIcon[idx]->getActionByTag(ANIMATION_GOAL_ICON))
		_imgGoalIcon[idx]->stopActionByTag(ANIMATION_GOAL_ICON);
	// restore scale
	_imgGoalIcon[idx]->setScale(1);
	// run scale animation
	Action* goalact=Sequence::createWithTwoActions(
		EaseQuadraticActionOut::create(ScaleTo::create(0.2f,0.7f)),
		EaseQuadraticActionIn::create(ScaleTo::create(0.2f, 1.0f))
		);
	goalact->setTag(ANIMATION_GOAL_ICON);
	_imgGoalIcon[idx]->runAction(goalact);
}

void ScnLevelPlay::updateGoalCount(int idx, int count) {
	_lblGoalCounter[idx]->setString(Ext_itos(count));
	if(count < 1) {
		_lblGoalCounter[idx]->setVisible(false);
		_spGoalComplete[idx]->setVisible(true);
	}
}

void ScnLevelPlay::InitStars(std::vector<int>& stars) {
	// reset progress
	_barScore->setPercent(0);
	// hide stars
	for(int i = 0; i < 3; i++)
		_sprScoreStar[i]->setVisible(false);
	// reposition 1st, 2nd star slots
	cocos2d::Vec2 poses[] = {{245, 1280-192}, _sprScoreStarSlot[0]->getPosition(), _sprScoreStarSlot[1]->getPosition(), _sprScoreStarSlot[2]->getPosition()};
	for(int i = 0; i < 2; i++) {
		float pos = (poses[3].x - poses[0].x)*((float)stars[i] / stars[2]) + poses[0].x;
		for(int j = 0; j < 3; j++)
			if(pos >= poses[j].x && pos <= poses[j + 1].x)
				_sprScoreStarSlot[i]->setPosition(poses[j].lerp(poses[j + 1], (pos - poses[j].x) / (poses[j + 1].x - poses[j].x)));
	}
}

void ScnLevelPlay::setMovesLeft(int count) {
	_lblMoveCount->setString(Ext_itos(count));
}

void ScnLevelPlay::updateScorebar(int score) {
	if(_barScore->getActionByTag(ANIMATION_SCOREBAR_TAG) != nullptr)
		_barScore->stopActionByTag(ANIMATION_SCOREBAR_TAG);

	float scorepercent = Mathf::Clamp(score * 100.0f / LevelBuilder::ActiveLevel->Stars[2], 0.0f, 100.0f);

	Action* act = ActionFloat::create(
		Mathf::Abs(scorepercent - _barScore->getPercent()) / 50, // speed is in proportion to change ration
		_barScore->getPercent(), // from current
		scorepercent, // to score
		CC_CALLBACK_1(ScnLevelPlay::onScoreBarChange, this)
		);
	act->setTag(ANIMATION_SCOREBAR_TAG);
	_barScore->runAction(act);
}

void ScnLevelPlay::onScoreBarChange(float value) {
	_barScore->setPercent(value);
	// check goal changed
	if(_currentScoreStar<3 && value>=LevelBuilder::ActiveLevel->Stars[_currentScoreStar] * 100.f / (float)LevelBuilder::ActiveLevel->Stars[2]) {
		// set initial style
		_sprScoreStar[_currentScoreStar]->setScale(0.35f / 2);
		_sprScoreStar[_currentScoreStar]->setOpacity(0);
		_sprScoreStar[_currentScoreStar]->setVisible(true);
		// run aniamtion
		_sprScoreStar[_currentScoreStar]->runAction(Sequence::create(
			EaseQuarticActionOut::create(ScaleTo::create(0.18f, 0.35f * 3)),
			EaseQuarticActionOut::create(ScaleTo::create(0.18f, 0.35f)),
			nullptr));
		_sprScoreStar[_currentScoreStar]->runAction(EaseQuarticActionOut::create(FadeIn::create(0.045f)));
		// run particle
		_sprScoreStar[_currentScoreStar]->runAction(Sequence::create(DelayTime::create(0.225f), CallFunc::create(CC_CALLBACK_0(ScnLevelPlay::showGoalStarAnimation, this)), nullptr));

		_currentScoreStar++;
		switch(_currentScoreStar) {
		case 1: break;
		case 2: break;
		case 3: break;
		}
	}
}

void ScnLevelPlay::showGoalStarAnimation() {
	_particleScoreStar[_currentScoreStar - 1]->setVisible(true);
	_particleScoreStar[_currentScoreStar - 1]->runAction(_goalStarAction);
	_goalStarAction->gotoFrameAndPlay(0, false);
	ParticleSystemQuad* particle = dynamic_cast<ParticleSystemQuad*>(_particleScoreStar[_currentScoreStar - 1]->getChildByName("particle"));
	particle->resetSystem();
}
