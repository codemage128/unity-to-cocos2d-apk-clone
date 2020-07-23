#include "Item.h"
#include "ItemFeature.h"
#include "ItemImpl.h"
#include "Animation.h"
#include "Match.h"
#include "MetaDataSerializer.h"
#include "Cell.h"
#include "Level.h"
#include "LevelBuilder.h"
#include "Constants.h"
#include "GroupCondition.h"
#include "Mathf.h"
#include "FallManager.h"
#include "Extension.h"
#include "ImageLibrary.h"
#include "ScnLevelPlay.h"

//////ItemProperties////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ItemProperties::ItemProperties(std::vector<MapFieldEntry>* properties/* = nullptr*/) {
	this->scale = 1.0f;
	if(properties == nullptr || properties->size() < 1) {
		return;
	}
	this->matchType = MatchType::None;
	this->direction = Direction::None;
	int count = (int)properties->size();
	for(int i = 0; i < count; i++) {
		MapFieldEntry& mapFieldEntry = properties->at(i);
		std::string key = Ext_strlwr(mapFieldEntry.key);
		std::string value = mapFieldEntry.value;
		if(key == "frame" && value == "1") {
			this->hasFrame = true;
		}
		else if(key=="capacity") {
			this->capacity = Ext_stoi(value);
		}
		else if(key=="order") {
			this->order = Ext_stoi(value);
		}
		else if(key=="direction") {
			this->direction = (Direction)Ext_stoi(value);
		}
		else if(key=="matchtype") {
			this->matchType = (MatchType)Ext_stoi(value);
		}
		else if(key=="wall") {
			this->wallGroup = value;
		}
		else if(key=="offset") {
			size_t splitpos = value.find(':');
			if(splitpos != std::string::npos) {
				std::string str1 = value.substr(0, splitpos);
				std::string str2 = value.substr(splitpos);
				this->offset.set(Ext_stof(str1, 0.0f), Ext_stof(str2, 0.0f));
			}
		}
		else if(key=="scale" && !value.empty()) {
			this->scale = Ext_stof(value, 1.0f);
		}
	}
}


//////ItemGroup////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ItemGroup::ItemGroup(GroupMetaData* groupData) {
	this->Ratio = groupData->Ratio;
	this->UseForDrop = (groupData->UseForDrop == 1);
	this->DropInterval = groupData->DropInterval;
	this->GeneratePerTurn = groupData->GeneratePerTurn;
	this->DropPosList = groupData->DropPosList;
	for(TiledObjectMetaData& __item : groupData->Items)
		this->_itemIds.push_back(__item.Id);

	_itemDescriptions.clear();
	_ratios.clear();
	_weights.clear();

	int __weight = 0;
	for(TiledObjectMetaData& __item : groupData->Items) {
		TiledEditorId id = (TiledEditorId)__item.Id;
		ItemType itemType = TiledEditorIdAsItemType(id);

		ItemDescription* item = new ItemDescription(itemType, id, new ItemProperties(&__item.Properties));
		_itemDescriptions.push_back(item);

		int __ratio = (__item.Ratio != 0) ? __item.Ratio : 1;
		__weight += __ratio;
		_weights.push_back(__weight);
		_ratios.push_back(__ratio);

		if(id == TiledEditorId::ColoredBallon1 || id == TiledEditorId::ColoredBallon2 || id == TiledEditorId::ColoredBallon3 || id == TiledEditorId::ColoredBallon4 || id == TiledEditorId::ColoredBallon5 || id == TiledEditorId::ColoredBallon6)
			this->_coloredBalloonEditorIds.push_back(id);

		if(id == TiledEditorId::Duck1 || id == TiledEditorId::Duck2 || id == TiledEditorId::Duck3 || id == TiledEditorId::Duck4 || id == TiledEditorId::Duck5)
			this->_duckEditorIds.push_back(id);
	}
	if(groupData->Conditions.size() > 0) {
		_conditions.clear();
		for(int i = 0; i < (int)groupData->Conditions.size(); i++)
			_conditions.push_back(this->CreateCondition(groupData->Conditions[i]));
	}
}

GroupCondition* ItemGroup::CreateCondition(MapFieldEntry entry) {
	std::string text = Ext_strlwr(entry.key);
	std::string value = entry.value;
	if(!text.empty()) {
		if(text == "countofballoon") return new CountOfCondition(ItemType::Balloon, value);
		if(text == "countofwatermelon") return new CountOfCondition(ItemType::WaterMelon, value);
		if(text == "countofcoloredballoon") return new CountOfCondition(ItemType::ColoredBalloon, value);
		if(text == "countofgiantduck") return new CountOfCondition(ItemType::GiantDuck, value);
		if(text == "countofduck") return new CountOfCondition(ItemType::Duck, value);
		if(text == "countofjelly") return new CountOfCondition(ItemType::Jelly, value);
	}
	//LogManager.Error(LogTags.ItemGroup, "Cannot create condition. Unknown condition: {0}", new object[] {text});
	return nullptr;
}

bool ItemGroup::CanFall() {
	if(this->_itemDescriptions.size() == 0) {
		return false;
	}
	if(this->_currentTurn != this->_currentLevel->TurnNo) {
		this->_currentTurn = this->_currentLevel->TurnNo;
		this->_generatedItemCountThisTurn = 0;
	}
	if(this->_conditions.size() > 0) {
		int num = this->_conditions.size();
		for(int i = 0; i < num; i++) {
			if(!this->_conditions[i]->IsMet(this->_currentLevel)) {
				return false;
			}
		}
	}
	bool flag = this->GeneratePerTurn == 0 || this->_generatedItemCountThisTurn < this->GeneratePerTurn;
	return this->HasAvailableItemTypes() && flag;
}

ItemDescription* ItemGroup::GetItemDescription() {
	if(!this->CanFall()) {
		return Constants::NullItemDescription;
	}
	ItemDescription* randomItemDescription = this->GetRandomItemDescription();
	if(!randomItemDescription->ready) {
		return Constants::NullItemDescription;
	}
	TiledEditorId tiledEditorId = TiledEditorId::None;
	ItemType itemType = randomItemDescription->itemType;
	if(itemType != ItemType::Duck) {
		if(itemType == ItemType::ColoredBalloon) {
			tiledEditorId = this->GetRandomColoredBalloonEditorId();
		}
	}
	else {
		tiledEditorId = this->GetRandomDuckEditorId();
	}
	this->_generatedItemCountThisTurn++;
	return new ItemDescription(randomItemDescription->itemType, tiledEditorId, randomItemDescription->properties);
}

TiledEditorId ItemGroup::GetRandomDuckEditorId() {
	return (this->_duckEditorIds.size() > 0) ? this->_duckEditorIds[Mathf::Random::Range(0, this->_duckEditorIds.size())] : TiledEditorId::None;
}

TiledEditorId ItemGroup::GetRandomColoredBalloonEditorId() {
	return (this->_coloredBalloonEditorIds.size()>0) ? this->_coloredBalloonEditorIds[Mathf::Random::Range(0, this->_coloredBalloonEditorIds.size())] : TiledEditorId::None;
}

void ItemGroup::StopItemGeneration(ItemType i) {
	if(this->_stoppedItems.find((int)i)!=this->_stoppedItems.end()) {
		return;
	}
	this->_stoppedItems.insert((int)i);
	std::vector<ItemDescription*> list;
	std::vector<int> list2;
	std::vector<int> list3;
	int num = 0;
	for(int j = 0; j < (int)this->_itemDescriptions.size(); j++) {
		ItemType itemType = this->_itemDescriptions[j]->itemType;
		if(itemType != i) {
			int num2 = this->_ratios[j];
			num += num2;
			list.push_back(this->_itemDescriptions[j]);
			list2.push_back(num);
			list3.push_back(num2);
		}
	}
	this->_itemDescriptions = list;
	this->_weights = list2;
	this->_ratios = list3;
}

ItemType ItemGroup::GetRandomItemType() {
	if(this->_itemDescriptions.size() == 0)
		return ItemType::None;
	
	int randomWeightedIndex = GetRandomWeightedIndex(this->_weights);
	return (randomWeightedIndex == -1) ? ItemType::None : this->_itemDescriptions[randomWeightedIndex]->itemType;
}

ItemDescription* ItemGroup::GetRandomItemDescription() {
	if(this->_itemDescriptions.size() == 0)
		return Constants::NullItemDescription;
	
	int randomWeightedIndex = GetRandomWeightedIndex(this->_weights);
	return (randomWeightedIndex == -1) ? Constants::NullItemDescription : this->_itemDescriptions[randomWeightedIndex];
}

int ItemGroup::GetRandomTiledId() {
	if(this->_itemIds.size() == 0)
		return 0;
	
	int randomWeightedIndex = GetRandomWeightedIndex(this->_weights);
	if(randomWeightedIndex != -1)
		return this->_itemIds[randomWeightedIndex];
	
	return 0;
}

bool ItemGroup::IsIntervalCompleted(int count) {
	if(count - this->_lastSuccessInterval <= this->DropInterval) 
		return false;
	
	this->_lastSuccessInterval = count;
	return true;
}



//////Item////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*event Action*/void Item::CleanUpResources() {
	/*add
	{
		Action action = this->CleanUpResources;
		Action action2;
		do {
			action2 = action;
			action = Interlocked.CompareExchange<Action>(ref this->CleanUpResources, (Action)Delegate.Combine(action2, value), action);
		} while(action != action2);
	}
		remove
	{
		Action action = this->CleanUpResources;
		Action action2;
		do {
			action2 = action;
			action = Interlocked.CompareExchange<Action>(ref this->CleanUpResources, (Action)Delegate.Remove(action2, value), action);
		} while(action != action2);
	}*/

	if(CurrentFallAnimation != nullptr) {
		CurrentFallAnimation->Cancel();
		FallManager::getInstance()->removeFallAnimation(CurrentFallAnimation);
		delete CurrentFallAnimation;
	}
}

void Item::set_CurrentCell(Cell* value) {
	if(this->_currentCell == value) 
		return;
	
	Cell* currentCell = this->_currentCell;
	this->_currentCell = value;
	if(currentCell != nullptr && currentCell->get_CurrentItem() == this) 
		currentCell->set_CurrentItem(nullptr);
	
	if(value != nullptr) 
		value->set_CurrentItem(this);
	
	this->OnCellChanged();
}

void Item::OnBeforeRemove() {
	//if(this->CleanUpResources != nullptr) {
		this->CleanUpResources();
		//this->CleanUpResources = nullptr;
	//}
	FallManager::StartRunning();
	if(!this->_createByFactory) 
		return;
	
	this->CurrentLevel->ItemCounts[(int)this->GetItemType()]--;
	this->_createByFactory = false;
	this->ReCycled = true;
}

void Item::AfterPoolInit() {
	this->ReCycled = false;
	this->FilledNewly = false;
	this->LatestExplode = 0L;
	this->MasterItemExplode = 0;
	this->IsFalling = false;
	this->_canRaiseScoreOnExplode = true;
}

void Item::OnItemCreated(Level* currentLevel) {
	this->CurrentLevel = currentLevel;
	this->CurrentLevel->ItemCounts[(int)this->GetItemType()]++;
	this->CurrentLevel->StopRefillIfNeeded(this->GetItemType());
	this->_createByFactory = true;
}

void Item::OnCellChanged() {
	if(this->get_CurrentCell() == nullptr) 
		return;
	
	CanCastShadowComponent* shadowCaster = this->GetShadowCaster();
	if(shadowCaster == nullptr) 
		return;
	
	cocos2d::Sprite* shadowSpriteRenderer = shadowCaster->ShadowSpriteRenderer;
}

void Item::PlayOnExplodeStartedAnimation() {
	//if(ParticlePool.Instance != null) {
	//	ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DefaultExplosion, base.get_transform().get_position(), true);
	//}
}

bool Item::TryExplode() {
	if(this->LatestExplode == (long)Ext_getCurrentFrame()) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	return true;
}

MatchType Item::GetMatchType() { 
	return MatchType::None;
}

CanCastShadowComponent* Item::GetShadowCaster() {
	if(!this->CanCastShadow()) {
		return nullptr;
	}
	if(this->_shadowCaster == nullptr) {
		//this->_shadowCaster = base.GetComponent<CanCastShadowComponent>();
	}
	return this->_shadowCaster;
}

void Item::DoShuffleAnimation(Cell* targetCell, Cell* oldReference) {
	this->set_CurrentCell(targetCell);
	//ShuffleAnimation componentOrAdd = base.get_gameObject().GetComponentOrAdd<ShuffleAnimation>();
	//componentOrAdd.SetSo rtingOrder(this, itemSo rting);
	//componentOrAdd.ShuffleWith(targetCell);
	//void ShuffleWith(Cell targetCell) {
	//	this._targetCell = targetCell;
	//	if(!this._increaseRequested) {
	//		this._increaseRequested = true;
	FallManager::IncreaseMechanicAnimation();
	FallManager::IncreaseWaitingFallBlocker();
	//	}
	//	Sequence sequence = DOTween.Sequence();
	//	Tweener tweener = TweenSettingsExtensions.OnComplete<Tweener>(TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMove(base.get_gameObject().get_transform(), this._targetCell.GetFrozenPosition(), 1f, false), 0x1c), new TweenCallback(this, (IntPtr) this.AnimationCompleted));
	//	tweener.easeOvershootOrAmplitude = 1.56f;
	//	TweenSettingsExtensions.AppendInterval(sequence, 0.3f);
	//	TweenSettingsExtensions.Append(sequence, tweener);
	//	if(<>f__am$cache0 == null) {
	//		<>f__am$cache0 = new TweenCallback(null, (IntPtr) <ShuffleWith>m__0); /*Audio Play*/
	//	}
	//	TweenSettingsExtensions.InsertCallback(sequence, 0.5f, <>f__am$cache0);
	//	if(this._currentItem != null) {
	//		TweenSettingsExtensions.InsertCallback(sequence, 0.5f, new TweenCallback(this, (IntPtr) this.<ShuffleWith>m__1));/*Change Sorting*/
	//	}
	//}
	Sprite* spItem = LevelBuilder::getItemSprite(this);
	if(spItem != nullptr) {
		EaseBackInOut* ease = EaseBackInOut::create(MoveTo::create(1.0f, targetCell->GetFrozenPosition()));
		ease->setAmplitudeRate(1.56f);
		spItem->runAction(Sequence::create(DelayTime::create(0.3f), ease,
			CallFunc::create([]() {
			FallManager::DecreaseMechanicAnimation();
			FallManager::DecreaseWaitingFallBlocker();
		}), nullptr));

		spItem->runAction(Sequence::createWithTwoActions(DelayTime::create(0.5f),
			CallFunc::create([this, spItem, targetCell]() {spItem->setLocalZOrder((int)spItem->getUserData()+targetCell->Y); })));
	}
}

void Item::StartExplode() {
	this->StopOtherAnimations();
	this->PlayExplodeAudio();
	this->PlayOnExplodeStartedAnimation();
	this->RemoveSelf();
}

void Item::RemoveSelf() {
	this->OnBeforeRemove();
	//Object.Destroy(base.get_gameObject());
	/*TODO, clear all resources*/
}

CollectAnimation Item::GetCollectItem() {
	//CollectAnimation component = this->CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(base.get_transform().get_position()).GetComponent<CollectAnimation>();
	//component.Prepare(this->CurrentLevel, this->GetItemType(), this->GetSor ting(), null, this->CurrentCell);

	//CollectAnimation Prepare(Level currentLevel, ItemType goalType, S orting s, Sprite sprite, Cell currentCell) {
	//	this.CurrentLevel = currentLevel;
	//	currentLevel.PreCheckDecreaseGoal(goalType);
		CurrentLevel->PreCheckDecreaseGoal(GetItemType());
	//	if(this._increaseRequested) {
	//		return this;
	//	}
	//	currentLevel.StopRefillIfNeeded(goalType);
		CurrentLevel->StopRefillIfNeeded(GetItemType());
	//	this.ReferencedCell = currentCell;
	//	this._increaseRequested = true;
	//	this.GoalType = goalType;
	//	this.TopPanel = this.CurrentLevel.CurrentLevelBuilder.CurrentTopPanel;
	//	this.TopPanelGoalId = this.TopPanel.FindGoalIndex(this.GoalType);
	//	this._targetTransform = this.TopPanel.GoalUIList[this.TopPanelGoalId].GoalImage.get_transform();
	//	this.TargetPosition = this._targetTransform.get_position();
	//	FallManager.IncreaseStatAnimation();
		FallManager::getInstance()->IncreaseStatAnimation();
	//	if(sprite == null) {
	//		sprite = ImageLibrary.Instance.GetGoalSpriteByItemType(goalType);
	//	}
	//	this.GoalImageScale = this._targetTransform.get_parent().get_localScale().x * ImageLibrary.Instance.GoalImageScale(goalType);
	//	base.get_transform().set_localScale(Vector3.get_one());
	//	this.CollectSpriteRenderer.set_sprite(sprite);
	//	this.CollectSpriteRenderer.set_so rtingOrder(s.Order);
	//	this.CollectSpriteRenderer.set_so rtingLayerID(s.LayerId);
	//	CollectManager.Instance.Register(this);
	//	return this;
	//}

	return CollectAnimation::Instant;// component;
}

void Item::StartCollect() {
	this->StopOtherAnimations();
	CollectAnimation animtype = this->GetCollectItem();
	//collectItem->StartAnimation();
	Sprite* spItem = LevelBuilder::getItemSprite(this);
	if(spItem!=nullptr)	{
		// cloning current item's sprite renderer
		cocos2d::Sprite* clonesprite = cocos2d::Sprite::create();
		if(animtype == CollectAnimation::SolidColor || animtype== CollectAnimation::Duck) {
			cocos2d::Node* targetContainer = CurrentLevel->CurrentLevelBuilder->SceneContainer;
			targetContainer->addChild(clonesprite, ITEM_GOAL_ANIMATION_ZORDER_ONSCENEROOT);
			ImageLibrary::CopySprite(clonesprite, spItem);
			clonesprite->setPosition(targetContainer->convertToNodeSpace(spItem->convertToWorldSpaceAR(cocos2d::Vec2::ZERO)));
			clonesprite->setScale((targetContainer->convertToNodeSpace(spItem->convertToWorldSpaceAR(cocos2d::Vec2::ONE)) -
				targetContainer->convertToNodeSpace(spItem->convertToWorldSpaceAR(cocos2d::Vec2::ZERO))).x);
		}
		// apply collect animation
		ScnLevelPlay* toppanel = CurrentLevel->CurrentLevelBuilder->LevelScene;
		int goalidx = toppanel->getGoalIdx(GetItemType());
		if(goalidx >= 0) {
			ItemType thistype = GetItemType();
			Level* curlvl = CurrentLevel;
			// move item's sprite to goal position
			if(animtype == CollectAnimation::SolidColor) {
				cocos2d::Vec2 tgtpos = toppanel->getGoalIconPos(goalidx);
				float tgtscale = toppanel->getGoalIconScale(goalidx);
				float duration = 0.4f + (7.3f - get_CurrentCell()->Y)*0.05f + Mathf::Abs(3.3f - get_CurrentCell()->X)*0.1f;
				clonesprite->runAction(cocos2d::EaseBackIn::create(cocos2d::ActionFloat::create(duration, clonesprite->getPositionY(), tgtpos.y, [clonesprite](float y) {clonesprite->setPositionY(y); })));
				clonesprite->runAction(cocos2d::ActionFloat::create(duration, clonesprite->getPositionX(), tgtpos.x, [clonesprite](float x) {clonesprite->setPositionX(x); }));
				clonesprite->runAction(cocos2d::EaseQuarticActionIn::create(cocos2d::ScaleTo::create(duration, tgtscale)));
				// apply goal fx on top panel
				clonesprite->runAction(cocos2d::Sequence::create(
					cocos2d::DelayTime::create(duration),
					cocos2d::RemoveSelf::create(),
					cocos2d::CallFunc::create([toppanel, goalidx]() {toppanel->playGoalFx(goalidx); }),
					cocos2d::CallFunc::create([curlvl, thistype]() {curlvl->DecreaseGoal(thistype, true); }),
					nullptr));
			}
			// move duck sprite to goal position
			else if(animtype == CollectAnimation::Duck) {
				cocos2d::Vec2 tgtpos = toppanel->getGoalIconPos(goalidx);
				float tgtscale = toppanel->getGoalIconScale(goalidx);
				float duration = clonesprite->getPosition().distance(tgtpos) / ITEM_SPRITE_SIZE_X*0.07f;
				clonesprite->runAction(cocos2d::EaseSineOut::create(cocos2d::MoveTo::create(duration, tgtpos)));
				float interscale = clonesprite->getTextureRect().size.width > ITEM_SPRITE_SIZE_X*1.5f ? 1.3f : 2.0f;
				clonesprite->runAction(cocos2d::Sequence::create(cocos2d::ScaleTo::create(duration * 3 / 10, interscale), cocos2d::DelayTime::create(duration * 5 / 10), cocos2d::ScaleTo::create(duration * 2 / 10, tgtscale), nullptr));
				// apply goal fx on top panel
				clonesprite->runAction(cocos2d::Sequence::create(
					cocos2d::DelayTime::create(duration),
					cocos2d::RemoveSelf::create(),
					cocos2d::CallFunc::create([toppanel, goalidx]() {toppanel->playGoalFx(goalidx); }),
					cocos2d::CallFunc::create([curlvl, thistype]() {curlvl->DecreaseGoal(thistype, true); }),
					nullptr));
			}
			// apply goal fx instantly
			else if(animtype == CollectAnimation::Instant) {
				toppanel->playGoalFx(goalidx);
				curlvl->DecreaseGoal(thistype, true);
			}
		}
	}
	this->PlayExplodeAudio();
	this->PlayOnExplodeStartedAnimation();
	this->RemoveSelf();
}

void Item::PlayExplodeAudio() {
	//AudioManager.Play(AudioTag.ClassicExplode, PlayMode.Frame, null, 1f);
}

void Item::PlayWrongMove() {
	cocos2d::Sprite* itemSprite = LevelBuilder::getItemSprite(this);
	if(itemSprite == nullptr) return;

	//if(this->_wrongAnimation != null) {
	//	TweenExtensions.Kill(this->_wrongAnimation, true);
	//}
	RemoveWrongAnimation();

	//AudioManager.Play(AudioTag.InvalidTap, PlayMode.Frame, null, 1f);

	cocos2d::Action* wrongaction1=cocos2d::Sequence::create(
		cocos2d::RotateTo::create(0.035f, 15.0f),
		cocos2d::RotateTo::create(0.07f, -15.0f),
		cocos2d::RotateTo::create(0.035f, 0.0f),
		cocos2d::RotateTo::create(0.035f, 15.0f),
		cocos2d::RotateTo::create(0.07f, -15.0f),
		cocos2d::RotateTo::create(0.035f, 0.0f),
		nullptr);
	wrongaction1->setTag(ANIMATION_WRONG_TAG1);
	itemSprite->runAction(wrongaction1);

	cocos2d::Action* wrongaction2=cocos2d::Sequence::create(
		cocos2d::ScaleTo::create(0.035f, 0.93f),
		cocos2d::DelayTime::create(0.07f),
		cocos2d::DelayTime::create(0.035f),
		cocos2d::DelayTime::create(0.035f),
		cocos2d::DelayTime::create(0.07f),
		cocos2d::ScaleTo::create(0.035f,1.0f),
		nullptr);
	wrongaction2->setTag(ANIMATION_WRONG_TAG2);
	itemSprite->runAction(wrongaction2);
	//this->_wrongAnimation = DOTween.Sequence();
	//TweenSettingsExtensions.Append(this->_wrongAnimation, ShortcutExtensions.DOLocalRotate(this->RelativeContainer.get_transform(), new Vector3(0f, 0f, 15f), 0.035f, 0));
	//TweenSettingsExtensions.Join(this->_wrongAnimation, ShortcutExtensions.DOScale(this->RelativeContainer.get_transform(), 0.93f, 0.035f));
	//TweenSettingsExtensions.Append(this->_wrongAnimation, ShortcutExtensions.DOLocalRotate(this->RelativeContainer.get_transform(), new Vector3(0f, 0f, -15f), 0.07f, 0));
	//TweenSettingsExtensions.Append(this->_wrongAnimation, ShortcutExtensions.DOLocalRotate(this->RelativeContainer.get_transform(), new Vector3(0f, 0f, 0f), 0.035f, 0));
	//TweenSettingsExtensions.Append(this->_wrongAnimation, ShortcutExtensions.DOLocalRotate(this->RelativeContainer.get_transform(), new Vector3(0f, 0f, 15f), 0.035f, 0));
	//TweenSettingsExtensions.Append(this->_wrongAnimation, ShortcutExtensions.DOLocalRotate(this->RelativeContainer.get_transform(), new Vector3(0f, 0f, -15f), 0.07f, 0));
	//TweenSettingsExtensions.Append(this->_wrongAnimation, ShortcutExtensions.DOLocalRotate(this->RelativeContainer.get_transform(), new Vector3(0f, 0f, 0f), 0.035f, 0));
	//TweenSettingsExtensions.Join(this->_wrongAnimation, ShortcutExtensions.DOScale(this->RelativeContainer.get_transform(), 1f, 0.035f));
	//TweenSettingsExtensions.OnComplete<Sequence>(this->_wrongAnimation, new TweenCallback(this->RemoveWrongAnimation));
}

void Item::RemoveWrongAnimation() {
	Sprite* itemSprite = LevelBuilder::getItemSprite(this);
	if(itemSprite == nullptr) return;

	if(itemSprite->getNumberOfRunningActions() > 0) {
		if(itemSprite->getActionByTag(ANIMATION_WRONG_TAG1) != nullptr)
			itemSprite->stopActionByTag(ANIMATION_WRONG_TAG1);
		if(itemSprite->getActionByTag(ANIMATION_WRONG_TAG2) != nullptr)
			itemSprite->stopActionByTag(ANIMATION_WRONG_TAG2);
	}
}

void Item::AppendFallAnimation(Cell* targetCell) {
	//if(this->_wrongAnimation != null) {
	//	TweenExtensions.Kill(this->_wrongAnimation, true);
	//	this->_wrongAnimation = null;
	//}
	RemoveWrongAnimation();

	if(this->CurrentFallAnimation == nullptr) {
		this->CurrentFallAnimation = FallAnimation::create(this);
		//this->CurrentFallAnimation = base.get_gameObject().AddComponent<FallAnimation>();
	}
	this->CurrentFallAnimation->AppendFallTo(targetCell, this->GetFallListener());
}

void Item::StopOtherAnimations() {
	RemoveWrongAnimation();
	if(this->CurrentFallAnimation != nullptr) {
		this->CurrentFallAnimation->Cancel();
	}
}

void PlayOnExplodeStartedAnimation() {
	//if(ParticlePool.Instance != null) {
	//	ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DefaultExplosion, base.get_transform().get_position(), true);
	//}
}