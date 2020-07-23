#include "Level.h"
#include "Item.h"
#include "Group.h"
#include "LevelBuilder.h"
#include "Extension.h"
#include "Goal.h"
#include "HintManager.h"
#include "FallManager.h"
#include "BubbleController.h"
#include "IExplodeAware.h"
#include "JellyManager.h"

#include "ScnLevelPlay.h"

int Level::ExtraMoveCountABValue = 5;

Level::Level() {
	ItemCounts.resize((int)ItemType::__COUNT__, 0); // = new int[Enum.GetNames(typeof(ItemType)).Length];
	ToGoalToItemCounts.resize((int)ItemType::__COUNT__, 0); // = new int[Enum.GetNames(typeof(ItemType)).Length];
	//this->GameId = Guid.NewGuid().ToString();
	this->JellyItemManager = new JellyManager(this);
}

void Level::cleanUp() {
	CurrentLevelBuilder->cleanUp();
	delete this->JellyItemManager;
}

void Level::SetPredefinedFills(std::map<int, std::list<ItemDescription*>*>& fills) {
	this->IsPredefinedLevel = true;
	this->PreDefinedFills = fills;
}

void Level::IncreaseTurnNo() {
	this->_turnNo++;
}

Item* Level::GetItemByGroupId(GroupId groupId) {
	if(groupId == GroupId::None) {
		return nullptr;
	}
	if(this->CurrentItemGroups.find(groupId) == this->CurrentItemGroups.end())
		return nullptr;
	ItemGroup* itemGroup=this->CurrentItemGroups[groupId];
	if(!itemGroup->HasAvailableItemTypes()) {
		return nullptr;
	}
	ItemDescription* itemDescription = itemGroup->GetItemDescription();
	return (!itemDescription->ready) ? nullptr : this->CurrentLevelBuilder->CreateItemFromItemGroupEntry(itemDescription);
}

void Level::StopGenerationForItemType(ItemType itemType) {
	for(std::pair<GroupId, ItemGroup*> current : this->CurrentItemGroups) {
		current.second->StopItemGeneration(itemType);
	}
}

void Level::IncreaseMoveCount() {
	if(this->_startTime == 0.0f) {
		this->_startTime = Ext_getCurrentTime();
	}
	this->MovesUserPerformed++;
	this->IncreaseTurnNo();
	//this->CurrentTopPanel.MovesLeftText.text = this->MovesLeft.FormatInt();
	this->CurrentLevelBuilder->LevelScene->setMovesLeft(this->get_MovesLeft());
	if(this->get_MovesLeft() != 0)
		return;
	
	//SettingsPanel.Instance.DisableBottomPanel();
	//TapListener.Instance.IncreaseBlockRequests();
}

void Level::IncreaseItemCount(ItemType itemType) {
	this->ItemCounts[(int)itemType]++;
}

void Level::DecreaseItemCount(ItemType itemType) {
	this->ItemCounts[(int)itemType]--;
}

int Level::CanGenerateCount(ItemType itemType) {
	bool flag = false;
	int num = 0;
	int num2 = this->ItemCounts[(int)itemType];
	for(int i = 0; i < (int)this->Goals.size(); i++) {
		Goal* goal = this->Goals[i];
		if(goal->Type == itemType) {
			flag = true;
			num = goal->Count - 0/*this->CurrentTopPanel.GetActiveCollectAnimationsCount(i)*/;
		}
	}
	return (!flag) ? -1 : (num - num2);
}

bool Level::CanBeCollected(ItemType currentItem) {
	if(this->Cancelled) {
		return false;
	}
	for(int i = 0; i < (int)this->Goals.size(); i++) {
		Goal* goal = this->Goals[i];
		if(goal->Type == currentItem && goal->Count > 0) {
			return true;
		}
	}
	return false;
}

void Level::PreCheckDecreaseGoal(ItemType goalType) {
	for(int i = 0; i < (int)this->Goals.size(); i++) {
		Goal* goal = this->Goals[i];
		if(goal->Type == goalType) {
			if(goal->Count > 0/*this->CurrentTopPanel.GetActiveCollectAnimationsCount(i) + 1*/) {
				return;
			}
		}
		else if(goal->Count > 0) {
			return;
		}
	}
	this->JellyItemManager->Disable();
	//TapListener.Instance.IncreaseBlockRequests();
}

void Level::IncreaseGoal(ItemType goalType) {
	for(int i = 0; i < (int)this->Goals.size(); i++) {
		Goal* goal = this->Goals[i];
		if(goal->Type == goalType) {
			goal->Increase(1);

			//this->CurrentTopPanel.UpdateGoalCount(i, goal.Count);
			int goalidx = CurrentLevelBuilder->LevelScene->getGoalIdx(goalType);
			if(goalidx >= 0)
				this->CurrentLevelBuilder->LevelScene->updateGoalCount(goalidx, goal->Count);
		}
	}
}

void Level::DecreaseGoal(ItemType goalType, bool collectCOunterIsManagedByCaller) {
	bool flag = true;
	for(int i = 0; i < (int)this->Goals.size(); i++) {
		Goal* goal = this->Goals[i];
		if(goal->Type == goalType && !this->Cancelled) {
			goal->Decrease(1);
			this->StopRefillIfNeeded(goalType, goal);

			int goalidx = CurrentLevelBuilder->LevelScene->getGoalIdx(goalType);
			if(goalidx >= 0)
				this->CurrentLevelBuilder->LevelScene->updateGoalCount(goalidx, goal->Count);
			//this->CurrentTopPanel.UpdateGoalCount(i, goal.Count);
			if(!collectCOunterIsManagedByCaller) {
				//this->CurrentTopPanel.IncreaseActiveCollectAnimationtCount(i);
			}
			//this->CurrentTopPanel.PlayGoalCollectHit(i);
		}
		if(goal->Count != 0) {
			flag = false;
		}
	}
	if(this->LevelWon || !flag) {
		return;
	}
	this->LevelWon = true;
	this->JellyItemManager->Disable();
	this->MovesLeftBeforeWin = this->get_MovesLeft();
	//LifeStatusHelper.Instance.IncreaseLife();
	//TapListener.Instance.IncreaseBlockRequests();
	//BoosterTapListener.Instance.IncreaseBlockRequests();
	//SettingsPanel.Instance.DisableBottomPanel();
	HintManager* instance = HintManager::getInstance();
	instance->DisableHints();
	instance->StopHintAnimations();
	instance->StopSpecialItemMarks();
	//new Task(this->WaitForFallingItems());
	this->WaitForFallingItems();
}

void Level::StopRefillIfNeeded(ItemType goalType) {
	for(int i = 0; i < (int)this->Goals.size(); i++) {
		Goal* goal = this->Goals[i];
		if(goal->Type == goalType && !this->Cancelled) {
			this->StopRefillIfNeeded(goalType, goal);
		}
	}
}

void Level::StopRefillIfNeeded(ItemType goalType, Goal* goal) {
	int num = this->ItemCounts[(int)goalType] + this->ToGoalToItemCounts[(int)goalType];
	if(goal->Count - num <= 0 && goalType != ItemType::SolidColor1 && goalType != ItemType::SolidColor2 && goalType != ItemType::SolidColor3 && goalType != ItemType::SolidColor4 && goalType != ItemType::SolidColor5 && goalType != ItemType::SolidColor6) {
		this->StopGenerationForItemType(goalType);
	}
}

bool Level::CanGenerateGoalItem(ItemType type) {
	Goal* goalFromItemType = this->GetGoalFromItemType(type);
	if(goalFromItemType != nullptr) {
		int num = this->ItemCounts[(int)type] + this->ToGoalToItemCounts[(int)type];
		if(goalFromItemType->Count - num <= 0) {
			return false;
		}
	}
	return true;
}

int Level::LeftBubbleCount() {
	Goal* goalFromItemType = this->GetGoalFromItemType(ItemType::Bubble);
	if(goalFromItemType != nullptr) {
		return goalFromItemType->TotalCount - BubbleController::getInstance()->BubbleCount();
	}
	return 0;
}

Goal* Level::GetGoalFromItemType(ItemType type) {
	for(int i = 0; i < (int)this->Goals.size(); i++) {
		Goal* goal = this->Goals[i];
		if(goal->Type == type) {
			return goal;
		}
	}
	return nullptr;
}

void Level::IncreaseBlockWin() {
	this->_blockWinRequest++;
}

void Level::DecreaseBlockWin() {
	this->_blockWinRequest--;
	if(this->_blockWinRequest < 0) {
		this->_blockWinRequest = 0;
	}
}

void Level::ResetSelf() {
	this->_blockWinRequest = 0;
}


void Level::WaitForFallingItems() {
	//Level.<WaitForFallingItems>c__Iterator0 <WaitForFallingItems>c__Iterator = new Level.<WaitForFallingItems>c__Iterator0();
	//<WaitForFallingItems>c__Iterator.$this = this;
	//return <WaitForFallingItems>c__Iterator;

	/*public bool MoveNext() {
		uint num = (uint) this.$PC;
		this.$PC = -1;
		switch(num) {
		case 0:
		case 1:
			if(this.$this._blockWinRequest > 0) {
				if(this.$this.Cancelled) {
					LogManager.Debug(LogTags.Level, "Cancelling win animations!", new object[0]);
					goto Label_01AE;
				}
				this.$current = null;
				if(!this.$disposing) {
					this.$PC = 1;
				}
				goto Label_01B0;
			}
			break;

		case 2:
			break;

		case 3:
			if(this.$this.Cancelled) {
				LogManager.Debug(LogTags.Level, "Cancelling win animations!", new object[0]);
			}
			else {
				this.<ic>__0 = this.$this.CurrentGrid.CurrentLevel.ItemCounts;
				if(((this.$this.MovesLeft > 0) || (this.<ic>__0[9] > 0)) || ((this.<ic>__0[11] > 0) || (this.<ic>__0[10] > 0))) {
					this.$this.CurrentLevelBuilder.WinLogoAnimation.StartWinLogo(new Action(this.<>m__0));
				}
				else {
					this.$this.ContinueWinAfterMovesLeft();
				}
				this.$PC = -1;
			}
			goto Label_01AE;

		default:
			goto Label_01AE;
		}
		while(FallManager.AreThereActiveAnimations()) {
			if(this.$this.Cancelled) {
				LogManager.Debug(LogTags.Level, "Cancelling win animations!", new object[0]);
				goto Label_01AE;
			}
			this.$current = null;
			if(!this.$disposing) {
				this.$PC = 2;
			}
			goto Label_01B0;
		}
		this.$current = new WaitForSeconds(0.5f);
		if(!this.$disposing) {
			this.$PC = 3;
		}
		goto Label_01B0;
	Label_01AE:
		return false;
	Label_01B0:
		return true;
	}
	*/
	CurrentLevelBuilder->LevelScene->levelComplete();
}

void Level::ContinueWinAfterMovesLeft() {
	//this->CurrentLevelBuilder.WinCharsAnimation.StartWinChars(delegate
	//{
	//	if(this->Cancelled) {
	//		LogManager.Debug(LogTags.Level, "Cancelling win animations!", new object[0]);
	//		return;
	//	}
	//	GameObject gameObject = DialogManager.Instance.ShowDialog((!ChampionsLeagueHelper.Instance.IsInChampionsLeague) ? DialogLibrary.Instance.WinDialog : DialogLibrary.Instance.CLWinDialog, false, false, false, null, true);
	//	WinDialog component = gameObject.GetComponent<WinDialog>();
	//	component.Win(this);
	//	AudioManager.PlayStinger(Stingers.StingerLevelComplete, false);
	//});
}

void Level::LostLevel() {
	//Time.set_timeScale(1f);
	//TapListener.Instance.IncreaseBlockRequests();
	//BoosterTapListener.Instance.IncreaseBlockRequests();
	//new Task(this->ShowEgo());
	CurrentLevelBuilder->LevelScene->levelFail();
}


void Level::ShowEgo() {
	//Level.<ShowEgo>c__Iterator1 <ShowEgo>c__Iterator = new Level.<ShowEgo>c__Iterator1();
	//<ShowEgo>c__Iterator.$this = this;
	//return <ShowEgo>c__Iterator;
}

void Level::LostLevelWithoutExtraMoves() {
	//GameObject gameObject = DialogManager.Instance.ShowDialog((!ChampionsLeagueHelper.Instance.IsInChampionsLeague) ? DialogLibrary.Instance.LostDialog : DialogLibrary.Instance.CLLostDialog, true, false, false, null, true);
	//LostDialog component = gameObject.GetComponent<LostDialog>();
	//component.PrepareGoals(this, false);
	//CurrentLevelBuilder->LevelScene->levelFail();
}

void Level::ContinueLevelAfterDelay(float delay) {
	//new Task(this->ContinueLevelDelayed(delay));
}


void Level::ContinueLevelDelayed(float delay) {
	//Level.<ContinueLevelDelayed>c__Iterator2 <ContinueLevelDelayed>c__Iterator = new Level.<ContinueLevelDelayed>c__Iterator2();
	//<ContinueLevelDelayed>c__Iterator.delay = delay;
	//<ContinueLevelDelayed>c__Iterator.$this = this;
	//return <ContinueLevelDelayed>c__Iterator;
}

void Level::ContinueLevel() {
	//TapListener.Instance.DecreaseBlockRequests();
	//BoosterTapListener.Instance.DecreaseBlockRequests();
	this->MaximumMovesAllowed += Level::ExtraMoveCountABValue;
	//SettingsPanel.Instance.EnableBottomPanel();
	//this->CurrentTopPanel.MovesLeftText.text = this->MovesLeft.FormatInt();
	this->CurrentLevelBuilder->CurrentHintManager->EnableHints();
	this->CurrentLevelBuilder->PopulateEgoItems();
}

GroupId Level::GetIntervalCompletedGroups(std::vector<GroupId>& intervalGroupIds) {
	if(!this->HasIntervalGroups) {
		return GroupId::None;
	}
	for(GroupId current : intervalGroupIds) {
		if(this->CurrentItemGroups.find(current) != this->CurrentItemGroups.end() && this->CurrentItemGroups[current]->IsIntervalCompleted(this->TotalExplodedItemCount)) {
			return current;
		}
	}
	return GroupId::None;
}

void Level::ExplodeEnded() {
	if(this->JellyItemManager->AreThereSpecialItemsInAction()) {
		return;
	}
	//LogManager.Debug(LogTags.Level, "Turn ended {0}", new object[] {
	//	this->MovesLeft
	//});
	for(int i = 0; i < (int)this->ExplodeAwareItem.size(); i++) {
		if(this->ExplodeAwareItem[i] != nullptr) {
			this->ExplodeAwareItem[i]->ExplosionOccured(this->get_MovesLeft());
		}
	}
}

void Level::onFrame(float delta) {
	HintManager::getInstance()->Update();
	FallManager::getInstance()->Update();
}