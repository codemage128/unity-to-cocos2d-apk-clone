#include "Score.h"
#include "Level.h"
#include "Item.h"
#include "LevelBuilder.h"
#include "ImageLibrary.h"
#include "Extension.h"

#include "ScnLevelPlay.h"

///////////////Score////////////////////////////
//void Score::StartAnimation() {
//	/*
//	Sequence sequence = DOTween.Sequence();
//	TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMoveY(base.get_transform(), base.get_transform().get_position().y + 1f, 1f, false), 6));
//	int i = 0;
//	int num = this.Digits.Length;
//	while(i < num) {
//		SpriteRenderer spriteRenderer = this.Digits[i];
//		if(spriteRenderer.get_enabled()) {
//			spriteRenderer.set_color(Color.get_white());
//			TweenSettingsExtensions.Insert(sequence, 0.5f, ShortcutExtensions43.DOFade(spriteRenderer, 0f, 0.5f));
//		}
//		i++;
//	}
//	TweenSettingsExtensions.OnComplete<Sequence>(sequence, new TweenCallback(base.get_gameObject().Recycle));
//	TweenSettingsExtensions.SetEase<Sequence>(sequence, 1);
//	*/
//}

///////////////ScoreManager////////////////////////////
ScoreManager* ScoreManager::_instance = nullptr;


void ScoreManager::set_CurrentScore(int value) {
	this->_currentScore = value;
	//ScoreManager.Instance.CurrentTopPanel.UpdateScoreBar(this._currentScore);
	CurrentLevel->CurrentLevelBuilder->LevelScene->updateScorebar(this->_currentScore);
}

//void ScoreManager::Awake() {
//	//this.ScorePrefab.CreatePool(50);
//	this->_matchOrderOfDigits = {
//		this->YellowDigits,
//		this->RedDigits,
//		this->BlueDigits,
//		this->GreenDigits,
//		this->PurpleDigits,
//		this->OrangeDigits,
//		this->WhiteDigits
//	};
//}

void ScoreManager::RaiseScore(int score, cocos2d::Vec2 pos, MatchType mType/* = MatchType::None*/) {
	//if(ScoreManager.Instance.CurrentLevel == null) {
	//	if(ScoreManager.Instance == null) {
	//		return;
	//	}
	//	CaravanTopPanel currentTopPanel = ScoreManager.Instance.CurrentTopPanel;
	//	if(currentTopPanel == null) {
	//		return;
	//	}
	//	LevelBuilder currentlLevelBuilder = currentTopPanel.CurrentlLevelBuilder;
	//	if(currentlLevelBuilder == null) {
	//		return;
	//	}
	//	ScoreManager.Instance.CurrentLevel = currentlLevelBuilder.CurrentLevel;
	//	if(ScoreManager.Instance.CurrentLevel == null) {
	//		return;
	//	}
	//}
	if(ScoreManager::getInstance() == nullptr || score == 0 || ScoreManager::getInstance()->CurrentLevel->Cancelled) {
		return;
	}
	//Score* component = nullptr;// ScoreManager.Instance.ScorePrefab.Spawn(pos).GetComponent<Score>();
	ScoreManager::getInstance()->set_CurrentScore(ScoreManager::getInstance()->get_CurrentScore() + score);
	//int num = (int)((mType != MatchType::None) ? mType : ((MatchType)6));
	//ScoreManager::PopulateSharedArray(score);
	//int num2 = 0;
	//for(int i = 0; i < 5; i++) {
	//	int num3 = ScoreManager::SharedArray[i];
	//	if(num3 < 0) {
	//		component->Digits[i]->setVisible(false);
	//		num2++;
	//	}
	//	else {
	//		cocos2d::Sprite* spriteRenderer = component->Digits[i];
	//		spriteRenderer->setVisible(true);
	//		ImageLibrary::CopySprite(spriteRenderer, ScoreManager::getInstance()->_matchOrderOfDigits[num][num3]);
	//	}
	//}
	//cocos2d::Vec2 zero = cocos2d::Vec2::ZERO;
	//zero.x = (float)num2 * -0.15f;
	//component.SpritesContainer.set_localPosition(zero);
	//component.StartAnimation();

	// create score label
	std::string fontnames[7] = {"fonts/numberyellow.fnt", "fonts/numberred.fnt", "fonts/numberblue.fnt", "fonts/numbergreen.fnt", "fonts/numberpurple.fnt", "fonts/numberorange.fnt", "fonts/numberwhite.fnt"};
	std::string font = fontnames[(int)((mType != MatchType::None) ? mType : ((MatchType)6))];

	cocos2d::Label* scorelbl = cocos2d::Label::createWithBMFont(font, Ext_itos(score), TextHAlignment::CENTER);
	cocos2d::Node* addtarget = ScoreManager::getInstance()->CurrentLevel->CurrentLevelBuilder->CellContainer;
	scorelbl->setPosition(addtarget->getParent()->convertToNodeSpace(addtarget->convertToWorldSpace(pos)));
	scorelbl->setScale(1.2f*addtarget->getScale());
	addtarget->getParent()->addChild(scorelbl, SCORE_ZORDER_ONSCENEROOT);


	// run fly up animation
	Vec2 delta(0, ITEM_SPRITE_SIZE_X);
	scorelbl->runAction(Sequence::create(
		EaseQuarticActionOut::create(MoveBy::create(1.0f, delta)),
		RemoveSelf::create(),
		nullptr
		));
	// run fade out animation
	scorelbl->runAction(EaseQuarticActionIn::create(FadeOut::create(1.0f)));
}

void ScoreManager::RaiseSudden(int score) {
		ScoreManager::getInstance()->_currentScore += score;
}

void ScoreManager::cleanUp() {
	if(_instance != nullptr)
		delete _instance;
	_instance = nullptr;
}

//void ScoreManager::PopulateSharedArray(int value) {
//	for(int i = 4; i >= 0; i--) {
//		if(value == 0) {
//			if(i == 4) {
//				ScoreManager::SharedArray[4] = 0;
//			}
//			else {
//				ScoreManager::SharedArray[i] = -1;
//			}
//		}
//		else {
//			ScoreManager::SharedArray[i] = value % 10;
//			value /= 10;
//		}
//	}
//}

void ScoreManager::SceneReloadedSetups(Level* level) {
	this->CurrentLevel = level;
	this->_currentScore = 0;
}