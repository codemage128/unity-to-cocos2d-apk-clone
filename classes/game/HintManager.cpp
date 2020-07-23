#include "HintManager.h"
#include "Level.h"
#include "Grid.h"
#include "Goal.h"
#include "Item.h"
#include "SpecialItem.h"
#include "Match.h"
#include "Cell.h"
#include "LevelBuilder.h"
#include "FallManager.h"
#include "Shuffle.h"
#include "ImageLibrary.h"
#include "Extension.h"
#include "Mathf.h"
#include "Animation.h"

#include "cocos2d.h"

HintManager* HintManager::_instance = nullptr;


void HintManager::cleanUp() {
	StopHintAnimations();
	if (_instance != nullptr)
		delete _instance;
	_instance = nullptr;
}

void HintManager::SceneReloadedSetups() {
	this->_hintAnimations.clear(); this->_hintAnimations.reserve(10);
	this->_allMatches.clear(); this->_allMatches.reserve(100);
	this->_candidateHints.clear(); this->_candidateHints.reserve(100);
	this->_currentLevel = this->CurrentLevelBuilder->CurrentLevel;
	this->_enabled = true;
	this->_lastTimeHintDisplayed = Ext_getCurrentTime() + 2.0f;
	this->_comboHintDisplayerEnabed = true;
	this->_lastLostCheck = 0;
	this->_showGoalSpecificHints = (this->_currentLevel->LevelNo <= 5);
	this->UpdateGoalHints();
}

void HintManager::UpdateGoalHints() {
	if(!this->_showGoalSpecificHints) {
		return;
	}
	int count = (int)this->_currentLevel->Goals.size();
	this->GoalTypes.clear(); this->GoalTypes.resize(count);
	for(int i = 0; i < count; i++) {
		Goal* goal = this->_currentLevel->Goals[i];
		if(goal->Count > 0) {
			this->GoalTypes.push_back(ItemTypeAsMatchType(goal->Type));
		}
	}
}

void HintManager::createHintAnimation(cocos2d::Sprite* spriteRenderer) {
	SharedShinyHintAnimation* hintanim = cocos2d::Sequence::createWithTwoActions(
		cocos2d::Repeat::create(
			cocos2d::Sequence::createWithTwoActions(
			cocos2d::TintTo::create(0.25f, cocos2d::Color3B(180,180,180)),
			cocos2d::TintTo::create(0.25f, cocos2d::Color3B(255,255,255))
			),
		5),
		cocos2d::CallFunc::create([this,spriteRenderer]() {this->RemoveActiveHint(spriteRenderer->getActionByTag(ANIMATION_HINT_TAG)); }));
	hintanim->setTag(ANIMATION_HINT_TAG);
	spriteRenderer->runAction(hintanim);
	AddActiveHint(hintanim);
}

void HintManager::AddActiveHint(SharedShinyHintAnimation* sharedShinyHintAnimation) {
	this->_hintAnimations.push_back(sharedShinyHintAnimation);
}

void HintManager::RemoveActiveHint(SharedShinyHintAnimation* sharedShinyHintAnimation) {
	std::vector<SharedShinyHintAnimation*>::iterator elem = std::find(_hintAnimations.begin(), _hintAnimations.end(), sharedShinyHintAnimation);
	this->_hintAnimations.erase(elem);
}

void HintManager::StopHintAnimations() {
	this->_lastTimeHintDisplayed = Ext_getCurrentTime();
	if(this->_hintAnimations.size() < 1)
		return;
	
	int i = 0;
	int count = this->_hintAnimations.size();
	while(i < count) {
		SharedShinyHintAnimation* hintanim = this->_hintAnimations[i];
		if(hintanim != nullptr /*TODO,this condition is inserted, check for removeable*/&& hintanim->getTarget()!=nullptr/*TODOEND*/) {
			/*TODO,this condition is inserted, check for removeable*/try {
				hintanim->getTarget()->setColor(cocos2d::Color3B::WHITE);
				hintanim->getTarget()->stopAction(hintanim);//StopAnimation();
			}
			catch(...){}
		}
		i++;
	}
	this->_hintAnimations.clear();
}

void HintManager::Update() {
	if(!this->_enabled/* || SlowCheckTime.ShouldPass() || TutorialManager.TutorialActive*/) {
		return;
	}
	int num = 0;
	bool flag = Ext_getCurrentTime() - this->_lastTimeHintDisplayed > 5.0f;

	this->CurrentLevelBuilder->CurrentLevel->CurrentGrid->PopulateAllMatchesIntoList(this->_allMatches);
	int count = (int)this->_allMatches.size();
	for(int i = 0; i < count; i++) {
		MatchGroup* matchGroup = this->_allMatches[i];
		if(matchGroup->CanMatchExplode || (/*TODO, this is inserted, do confirm to remove this*/matchGroup->ClickedCell!=nullptr && /*ENDTODO*/matchGroup->ClickedCell->get_HasItem() && matchGroup->ClickedCell->get_CurrentItem()->IsSpecialItem())) {
			num++;
			if(flag && (!matchGroup->ClickedCell->get_HasItem() || !matchGroup->ClickedCell->get_CurrentItem()->IsSpecialItem())) {
				this->_candidateHints.push_back(matchGroup);
			}
		}
		std::vector<Cell*> allCells = matchGroup->AllCells;
		int j = 0;
		int count2 = allCells.size();
		while(j < count2) {
			Cell* cell = allCells[j];
			if(cell->get_HasItem()) {
				if(this->_comboHintDisplayerEnabed && cell->get_CurrentItem()->IsSpecialItem() && !cell->get_CurrentItem()->IsFalling) {
					dynamic_cast<SpecialItem*>(cell->get_CurrentItem())->DisplayComboHint(matchGroup->CanGenerateCombo);
				}
				if(cell->get_CurrentItem()->CanBeMatchable()) {
					SolidColorItem* solidColorItem = dynamic_cast<SolidColorItem*>(cell->get_CurrentItem());
					if(!(solidColorItem == nullptr)) {
						if(matchGroup->CanGenerateSpecialItem) {
							if(!matchGroup->AtLeastOneFalling) {
								ItemType specialItemType = matchGroup->SpecialItemType;
								if(specialItemType == ItemType::Rocket)
									ImageLibrary::CopySprite(solidColorItem->CurrentSpriteRenderer, IMGLIB->SolidColorHintRocketSprites[(int)solidColorItem->GetMatchType()]);
								if(specialItemType == ItemType::Bomb)
									ImageLibrary::CopySprite(solidColorItem->CurrentSpriteRenderer, IMGLIB->SolidColorHintBombSprites[(int)solidColorItem->GetMatchType()]);
								if(specialItemType == ItemType::DiscoBall)
									ImageLibrary::CopySprite(solidColorItem->CurrentSpriteRenderer, IMGLIB->SolidColorHintDiscoSprites[(int)solidColorItem->GetMatchType()]);
							}
						}
						else {
							ImageLibrary::CopySprite(solidColorItem->CurrentSpriteRenderer, IMGLIB->SolidColorSprites[(int)solidColorItem->GetMatchType()]);
						}
					}
				}
			}
			j++;
		}
		if(!flag) {
			MatchGroup::Put(matchGroup);
		}
	}
	if(!this->_currentLevel->LevelWon && !FallManager::AreThereActiveAnimations() && !FallManager::AreFallsBlocked()) {
		if(num == 0) {
			bool flag2 = true;
			for(Cell* current : this->_currentLevel->CurrentGrid->WalkOnExistings()) {
				if(!current->CanItemsFallInside()) {
					flag2 = false;
					break;
				}
			}
			if(flag2) {
				this->DisableHints();
				if(!ShuffleManager::TryShuffle(this->_currentLevel->CurrentGrid)) {
					this->_currentLevel->LostLevelWithoutExtraMoves();
				}
				return;
			}
		}
		else if(this->_currentLevel->get_MovesLeft() <= 0) {
			if(true/*this->_lastLostCheck == Ext_getCurrentFrame() - 1*/) {
				this->DisableHints();
				this->_currentLevel->LostLevel();
				return;
			}
			this->_lastLostCheck = Ext_getCurrentFrame();
			return;
		}
	}
	if(flag) {
		if(this->_candidateHints.size() > 0/* && !DialogManager.Instance.AreThereActiveDialogs*/) {
			int index = Mathf::Random::Range(0, this->_candidateHints.size());
			MatchGroup* matchGroup2 = this->_candidateHints[index];
			if(this->_showGoalSpecificHints) {
				matchGroup2 = this->FindANeededHint(index, matchGroup2);
			}
			int k = 0;
			int count3 = matchGroup2->AllCells.size();
			while(k < count3) {
				Cell* cell2 = matchGroup2->AllCells[k];
				if(cell2->get_CurrentItem()->CanShowMatchHint()) {
					dynamic_cast<ICanShowMatchHint*>(cell2->get_CurrentItem())->ShowMatchHint();
				}
				k++;
			}
		}
		this->_lastTimeHintDisplayed = Ext_getCurrentTime();
		this->_candidateHints.clear();
		for(int l = 0; l < count; l++) {
			MatchGroup* usedItem = this->_allMatches[l];
			MatchGroup::Put(usedItem);
		}
	}

	this->_allMatches.clear();
	if(flag) {
		this->_candidateHints.clear();
	}
}

MatchGroup* HintManager::FindANeededHint(int index, MatchGroup* randomGroup) {
	int count = this->_candidateHints.size();
	int num = index;
	while(!randomGroup->CanMatchExplode || !this->ContainsCheck(randomGroup)) {
		index++;
		if(index == count) {
			index = 0;
		}
		if(index == num) {
			break;
		}
		randomGroup = this->_candidateHints[index];
	}
	return randomGroup;
}

bool HintManager::ContainsCheck(MatchGroup* randomGroup) {
	int count = this->GoalTypes.size();
	for(int i = 0; i < count; i++) {
		MatchType matchType = this->GoalTypes[i];
		if(matchType == randomGroup->matchType) {
			return true;
		}
	}
	return false;
}

void HintManager::DisableComboHints() {
	this->_comboHintDisplayerEnabed = false;
	for(Cell* current : this->_currentLevel->CurrentGrid->WalkOnExistings()) {
		if(current->get_HasItem() && current->get_CurrentItem()->IsSpecialItem()) {
			dynamic_cast<SpecialItem*>(current->get_CurrentItem())->DisplayComboHint(false);
		}
	}
}

void HintManager::StopSpecialItemMarks() {
	for(Cell* current : this->_currentLevel->CurrentGrid->WalkOnExistings()) {
		if(current->get_HasItem()) {
			SolidColorItem* solidColorItem = dynamic_cast<SolidColorItem*>(current->get_CurrentItem());
			if(!(solidColorItem == nullptr)) {
				ImageLibrary::CopySprite(solidColorItem->CurrentSpriteRenderer, IMGLIB->SolidColorSprites[(int)solidColorItem->GetMatchType()]);
			}
		}
	}
}