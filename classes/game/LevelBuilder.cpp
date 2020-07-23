#include "LevelBuilder.h"
#include "BorderBuilder.h"
#include "Level.h"
#include "Item.h"
#include "ItemFeature.h"
#include "ItemImpl.h"
#include "item/ItemImpl2.h"
#include "SpecialItem.h"
#include "Cell.h"
#include "Match.h"
#include "Mathf.h"
#include "Score.h"
#include "Group.h"
#include "Goal.h"
#include "Grid.h"
#include "Booster.h"
#include "Extension.h"
#include "MetaDataSerializer.h"
#include "Entity.h"
#include "HintManager.h"
#include "FallManager.h"
#include "BubbleController.h"
#include "ItemGeneratorController.h"
#include "ImageLibrary.h"
#include "global/GameManager.h"
#include "ScnLevelPlay.h"


int LevelBuilder::CurrentLevelNo = 0;
std::string LevelBuilder::CurrentLevelPath = "";
Level* LevelBuilder::ActiveLevel = nullptr;
bool LevelBuilder::MovedToNextLevel = false;
bool LevelBuilder::BackgroundAssetsLoaded = false;
bool LevelBuilder::ShouldRemoveBackgroundImagesOnDestroy = true;
std::string LevelBuilder::LevelStartType = "";
bool LevelBuilder::UserPlayedALevel = false;


int GetMapIdForLevel(int level) {
	float ret = 0.0f;
	if(level < 201)
		ret = ((level - 1.0f) / 20.0f) + 1.0f;
	else if(level < 321)
		ret = ((level - 201.0f) / 40.0f) + 11.0f;
	else if(level < 351)
		ret = 14.0f;
	else
		ret = ((level - 401.0f) / 50.0f) + 16.0f;
	return (int)Mathf::Clamp(ret, 1.0f, 19.0f);
}

std::string GetBackgroundImagePathForLevel(int level) {
	int mapIdForLevel = GetMapIdForLevel(level);
	//if(ChampionsLeagueHelper.Instance.IsInChampionsLeague) {
	//	mapIdForLevel = 0;
	//}
	char retpath[64];
	sprintf(retpath, "image/levelbg/%03d.jpg", mapIdForLevel);
	return retpath;
}


void LevelBuilder::buildLevel() {
	// mark level played
	LevelBuilder::UserPlayedALevel = true;

	this->initLevelData();

	// load background image
	//std::string backgroundImagePathForLevel = GetBackgroundImagePathForLevel(LevelBuilder::CurrentLevelNo);
	//this->NewMapBackgroundImage = cocos2d::Sprite::create(backgroundImagePathForLevel);
	//this->NewMapBackgroundImage->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->NewMapBackgroundImage =dynamic_cast<Sprite*>( SceneContainer->getChildByName("bg"));
	this->NewMapBackgroundImage->setTexture(Director::getInstance()->getTextureCache()->addImage(GetBackgroundImagePathForLevel(CurrentLevelNo)));
	this->NewMapBackgroundImage->setScaleX(SCREEN_WIDTH / this->NewMapBackgroundImage->getTextureRect().size.width);
	this->NewMapBackgroundImage->setScaleY(SCREEN_HEIGHT / this->NewMapBackgroundImage->getTextureRect().size.height);
	this->NewMapBackgroundImage->setColor(cocos2d::Color3B(220,220,220));
	//this->NewMapBackgroundImage->retain(); /*TODO add to scene and release this*/
	this->BackgroundAssetsLoaded = true;

	this->SceneReloadedSetups();
}

void LevelBuilder::cleanUp() {
	//LevelBuilder::ActiveLevel = nullptr;
	//AudioManager.StopSong(nullptr, false);
	HintManager::getInstance()->cleanUp();
	FallManager::getInstance()->cleanUp();
	ScoreManager::getInstance()->cleanUp();
	BoosterManager::getInstance()->cleanUp();
}

//void LevelBuilder::PlayTutorial(TutorialBase* tutorial) {
	//GameObject gameObject = Object.Instantiate<GameObject>(this->TutorialManagerPrefab, this->CellContainer);
	//gameObject.get_transform().set_localPosition(Vector3.get_zero());
	//TutorialManager component = gameObject.GetComponent<TutorialManager>();
	//component.Init(this, tutorial);
//}

void LevelBuilder::initLevelData() {
	//this->JellyAnimatorPrefab.CreatePool(4);
	//this->GenericCollectItem.CreatePool(80);
	//this->SolidColorItemPrefab.CreatePool(165);
	//this->VerticalRockItemPrefab.CreatePool(10);
	//this->HorizantalRockItemPrefab.CreatePool(10);
	//this->DiscoBallItemPrefab.CreatePool(2);
	//this->BombItemPrefab.CreatePool(10);
	//this->BubbleAnimationItem.CreatePool(5);
	//this->BalloonGeneratorThrowAnimation.CreatePool(5);
	this->_currentLevelMetaData = LevelDataMetaSerializer::DeserializeLevelData(LevelBuilder::CurrentLevelNo);
}

void LevelBuilder::SceneCreatedNewLevel(int levelNo) {
	LevelBuilder::CurrentLevelNo = levelNo;
	this->initLevelData();
}

void LevelBuilder::SceneReloadedSetups() {
	this->_musicStarted = false;
	LevelBuilder::ActiveLevel = nullptr;
	this->CurrentLevel = nullptr;
	BubbleController::getInstance()->ResetBubbleCount();
	BubbleController::getInstance()->ClearBubbleGenerators();
	ItemGeneratorController::getInstance()->ResetGenerators();

	// remove previous CellContainer and recreate it
	//		Transform parent = this->CellContainer.get_parent();
	//		Vector3 localPosition = this->CellContainer.get_transform().get_localPosition();
	//		Object.Destroy(this->CellContainer.get_gameObject());
	//		GameObject gameObject = new GameObject();
	//		gameObject.set_name("CellContainer");
	//		GameObject gameObject2 = gameObject;
	//		gameObject2.get_transform().SetParent(parent);
	//		gameObject2.get_transform().set_localPosition(localPosition);
	// recreate ItemContainer in CellContainer
	//		gameObject = new GameObject();
	//		gameObject.set_name("ItemContainer");
	//		GameObject gameObject3 = gameObject;
	//		gameObject3.get_transform().SetParent(gameObject2.get_transform());
	//		gameObject3.get_transform().set_localPosition(Vector3.get_zero());
	//this->CellContainer = nullptr; // gameObject2.get_transform();
	//this->ItemContainer = nullptr; // gameObject3.get_transform();
	//	this->SolidColorItemPrefab.RecycleAll();
	//	this->VerticalRockItemPrefab.RecycleAll();
	//	this->HorizantalRockItemPrefab.RecycleAll();
	//	this->DiscoBallItemPrefab.RecycleAll();
	//	this->BombItemPrefab.RecycleAll();
	//	this->BubbleAnimationItem.RecycleAll();
	//	this->BalloonGeneratorThrowAnimation.RecycleAll();
	//	this->SolidColorItemPrefab.DoActionInPool(new Action<GameObject>(this->ReInitItems));
	//	this->VerticalRockItemPrefab.DoActionInPool(new Action<GameObject>(this->ReInitItems));
	//	this->HorizantalRockItemPrefab.DoActionInPool(new Action<GameObject>(this->ReInitItems));
	//	this->DiscoBallItemPrefab.DoActionInPool(new Action<GameObject>(this->ReInitItems));
	//	this->BombItemPrefab.DoActionInPool(new Action<GameObject>(this->ReInitItems));
	this->CreateAndSetCurrentLevel();
	this->CurrentLevel->CurrentLevelBuilder = this;
	//this->CurrentLevel->CurrentTopPanel = this->CurrentTopPanel;
	if(!LevelBuilder::AreThereAvailableMatches(this->CurrentLevel)) {
		//LogManager.Debug(LogTags.LevelBuilder, "!! There is no match at the grid. Trying to create one", new object[0]);
		this->TryCreateAMatch(this->CurrentLevel);
	}

	// init top bar
	//		GameObject gameObject4 = DialogManager.Instance.ShowDialog(DialogLibrary.Instance.GoalsBannerDialog, false, true, false, null, true);
	//		GoalsBannerDialog component = gameObject4.GetComponent<GoalsBannerDialog>();
	//		component.PrepareGoals(this->CurrentLevel.Goals.ToArray());
	//		this->CurrentTopPanel.SceneReloadedSetups();
	//		this->CurrentTopPanel.InitStars(this->CurrentLevel.Stars);
	LevelScene->PrepareGoals(this->CurrentLevel->Goals);
	LevelScene->setMovesLeft(this->CurrentLevel->get_MovesLeft());
	LevelScene->InitStars(this->CurrentLevel->Stars);
	
	// play background music
	//		this->_musicStarted = false;
	//		base.StartCoroutine(this->PlayIntroMusic());
	//		component.AfterExit(delegate
	//		{
	//			this->PlayMusic();
	//			TutorialBase tutorialForLevel = TutorialManager.GetTutorialForLevel(LevelBuilder.CurrentLevelNo);
	//			if(TutorialManager.ForceShowTutorials || (!this->CurrentLevel.HasWonBefore && tutorialForLevel != null)) {
	//				this->PlayTutorial(tutorialForLevel);
	//			}
	//			this->PopulateSelectedPreLevelItems((tutorialForLevel != null) ? tutorialForLevel.HighlightCells : null);
	this->PopulateSelectedPreLevelItems(nullptr);
	//		});

	// init touches
	//		TapListener.Instance.ResetCount();
	//		BoosterTapListener.Instance.ResetCount();
	//		BoosterTapListener.Instance.get_gameObject().SetActive(false);
	BoosterManager::getInstance()->init(LevelScene);

	HintManager::getInstance()->CurrentLevelBuilder = this;
	HintManager::getInstance()->SceneReloadedSetups();

	FallManager::getInstance()->CurrentLevelBuilder = this;
	FallManager::getInstance()->CurrentHintManager = HintManager::getInstance();
	FallManager::getInstance()->SceneReloadedSetups();
	
	ScoreManager::getInstance()->SceneReloadedSetups(this->CurrentLevel);

	// init bottom panel
	//SettingsPanel.Instance.EnableBottomPanel();
}

void LevelBuilder::ReInitItems(cocos2d::Node* obj) {
	Item* component = nullptr;//*TODO*/ obj.GetComponent<Item>();
	component->OnBeforeRemove();
	//component.get_gameObject().get_transform().SetParent(this->ItemContainer);
	component->OnBeforeNewLevel();
}


void LevelBuilder::PlayIntroMusic() {
}

void LevelBuilder::PlayMusic() {
	if(this->_musicStarted) {
		return;
	}
	this->_musicStarted = true;
	//AudioManager.IncreaseSongCounter();
	//AudioManager.PlaySong();
}

void LevelBuilder::CreateAndSetCurrentLevel() {
	std::map<GroupId, ItemGroup*>* itemGroups = LevelBuilder::CreateItemGroups(this->_currentLevelMetaData);
	int __movecount = this->_currentLevelMetaData->MoveCount;
	//if(ChampionsLeagueHelper.Instance.IsInChampionsLeague) {
	//	__movecount += ChampionsLeagueHelper.Instance.MoveCount;
	//}

	Level* level = new Level();
	{
		level->LevelNo = LevelBuilder::CurrentLevelNo;
		level->CurrentItemGroups = *itemGroups;
		level->MaximumMovesAllowed = __movecount;
		level->LevelMoves = this->_currentLevelMetaData->MoveCount;
		level->Stars = this->_currentLevelMetaData->Stars;
		level->Name = this->_currentLevelMetaData->Name;
		level->CurrentLevelBuilder = this;
	}

	this->CurrentLevel = level;
	LevelBuilder::ActiveLevel = this->CurrentLevel;

	this->CurrentLevel->HasWonBefore = GM->getTopLevel() > LevelBuilder::CurrentLevelNo;// (levelEntity != null && levelEntity.Score > 0);

	level->CurrentGrid = this->BuildGrid(this->_currentLevelMetaData->Width, this->_currentLevelMetaData->Height, itemGroups);
	level->CurrentGrid->CurrentLevel = level;

	std::map<int, Cell*> _fillCells;
	for(Cell* _cell : level->CurrentGrid->WalkOnExistings()) {
		Cell* cellWithDirection = level->CurrentGrid->GetCellWithDirection(_cell, Direction::Up);
		if(cellWithDirection == nullptr || !cellWithDirection->Exists) {
			if(_fillCells.find(_cell->X) != _fillCells.end()) {
				if(_fillCells[_cell->X]->Y < _cell->Y) {
					_fillCells[_cell->X] = _cell;
				}
			}
			else {
				_fillCells[_cell->X] = _cell;
			}
		}
		_cell->FirstExistingBottomCell = LevelBuilder::FindFirstExistingBottomCell(_cell);
		if(_cell->Y > 0) {
			Cell* cell = _cell->CurrentGrid->cell(_cell->X, _cell->Y - 1);
			if(cell->Exists) {
				_cell->JustBelowCell = cell;
			}
		}
		if(_cell->Y + 1 < _cell->CurrentGrid->Height) {
			Cell* cell2 = _cell->CurrentGrid->cell(_cell->X, _cell->Y + 1);
			if(cell2->Exists) {
				_cell->JustAboveCell = cell2;
			}
		}
		_cell->IsFloor = (_cell->FirstExistingBottomCell == nullptr);
		if(_cell->get_HasItem()) {
			Cell* justBelowCell = _cell->JustBelowCell;
			if(justBelowCell == nullptr || !justBelowCell->get_HasItem()) {
				if(_cell->get_CurrentItem()->CanCastShadow()) {
					_cell->get_CurrentItem()->GetShadowCaster()->HideShadow();
				}
			}
			else if(_cell->get_CurrentItem()->CanCastShadow()) {
				if(justBelowCell->get_CurrentItem()->CanShadowDrop()) {
					_cell->get_CurrentItem()->GetShadowCaster()->CastShadow();
				}
				else {
					_cell->get_CurrentItem()->GetShadowCaster()->HideShadow();
				}
			}
		}
	}
	for(Cell* _cell : level->CurrentGrid->WalkOnAll()) {
		_cell->FreezePosition();
		if(_cell->Exists && _cell->get_HasItem()) {
			BillboardItem* billboardItem = dynamic_cast<BillboardItem*>(_cell->get_CurrentItem());
			if(billboardItem != nullptr && billboardItem->MasterItem == nullptr) {
				billboardItem->LinkNeighbours(_cell);
			}
		}
	}
	for(GoalMetaData& _goal : this->_currentLevelMetaData->GoalList) {
		Goal* goal = new Goal(_goal.Name, _goal.Count);
		if(goal->Type != ItemType::None) {
			level->Goals.push_back(goal);
		}
	}
	std::sort(level->Goals.begin(), level->Goals.end(), [](Goal* x, Goal* y)->int {return x->Order >= y->Order ? 1 : -1; });
	LevelBuilder::UpdateFillLayerGroups(level, _fillCells);
}

void LevelBuilder::TryCreateAMatch(Level* level) {
	int width = level->CurrentGrid->Width;
	int height = level->CurrentGrid->Height;
	int height2 = this->_currentLevelMetaData->Height;
	for(int i = 0; i < width; i++) {
		for(int j = 0; j < height; j++) {
			Cell* cell = level->CurrentGrid->cell(i, j);
			if(cell->Exists && cell->get_HasItem()) {
				ItemType itemType = cell->get_CurrentItem()->GetItemType();
				if(itemType == ItemType::SolidColor1 || itemType == ItemType::SolidColor2 || itemType == ItemType::SolidColor3 || itemType == ItemType::SolidColor4 || itemType == ItemType::SolidColor5 || itemType == ItemType::SolidColor6) {
					CellMetaData& cellMetaData = this->_currentLevelMetaData->CellList[LevelBuilder::CalculateOrderNo(i, j, width, height2)];
					GroupId groupId = TiledEditorIdAsGroupId((TiledEditorId)cellMetaData.TiledObject.Id);
					if(groupId != GroupId::None) {
						if(i + 1 < width && this->TryToChangeGroupItem(level, groupId, itemType, i + 1, j, width, height2)) {
							return;
						}
						if(j + 1 < height) {
							if(this->TryToChangeGroupItem(level, groupId, itemType, i, j + 1, width, height2)) {
								return;
							}
						}
					}
				}
			}
		}
	}
}

bool LevelBuilder::TryToChangeGroupItem(Level* level, GroupId groupId, ItemType itemType, int x, int y, int w, int h) {
	CellMetaData& cellMetaData = this->_currentLevelMetaData->CellList[LevelBuilder::CalculateOrderNo(x, y, w, h)];
	GroupId groupId2 = TiledEditorIdAsGroupId((TiledEditorId)cellMetaData.TiledObject.Id);
	if(groupId2 != groupId) {
		return false;
	}
	Cell* cell = level->CurrentGrid->cell(x, y);
	if(!cell->Exists || !cell->get_HasItem()) {
		return false;
	}
	cell->get_CurrentItem()->RemoveSelf();
	cell->set_CurrentItem(this->CreateItem(new ItemDescription(itemType, TiledEditorId::None, nullptr)));
	//*TODO*/cell->get_CurrentItem.get_transform().set_position(cell.GetFrozenPosition());
	return true;
}

bool LevelBuilder::AreThereAvailableMatches(Level* level) {
	std::vector<MatchGroup*> list; list.reserve(100);
	level->CurrentGrid->PopulateAllMatchesIntoList(list);
	int count = (int)list.size();
	for(int i = 0; i < count; i++) {
		MatchGroup* matchGroup = list[i];
		if(matchGroup->CanMatchExplode || (matchGroup->ClickedCell->get_HasItem() && matchGroup->ClickedCell->get_CurrentItem()->IsSpecialItem())) {
			return true;
		}
	}
	return false;
}

std::map<GroupId, ItemGroup*>* LevelBuilder::CreateItemGroups(LevelMetaData* levelData) {
	std::map<GroupId, ItemGroup*>* dictionary = new std::map < GroupId, ItemGroup* >();
	if(levelData == nullptr || levelData->GroupList.empty()) {
		return dictionary;
	}
	for(int i = 0; i < (int)levelData->GroupList.size(); i++) {
		GroupId key = GroupNameAsGroupId(levelData->GroupList[i].Name);
		(*dictionary)[key] = new ItemGroup(&levelData->GroupList[i]);
	}
	return dictionary;
}

Grid* LevelBuilder::BuildGrid(int width, int height, std::map<GroupId, ItemGroup*>* itemGroups) {
	int __totalheight = height;

	// get board height
	bool __heightmodified = false;
	for(int i = 0; i < height; i++) {
		CellMetaData& cellMetaData = this->_currentLevelMetaData->CellList[LevelBuilder::CalculateOrderNo(0, i, width, height)];
		if(cellMetaData.TiledObject.Id == 10/*SEPERATOR*/) {
			__heightmodified = true;
			height = i;
			break;
		}
	}
	// init out of visible board cells
	if(__heightmodified) {
		std::map<int, std::list<ItemDescription*>*> __boardoutcells;
		for(int x = 0; x < width; x++) {
			__boardoutcells[x] = new std::list<ItemDescription*>();
			for(int y = height + 1; y < __totalheight; y++) {
				CellMetaData& __cellMeta = this->_currentLevelMetaData->CellList[LevelBuilder::CalculateOrderNo(x, y, width, __totalheight)];
				TiledEditorId tiledEditorId = (TiledEditorId)__cellMeta.TiledObject.Id;
				GroupId groupId = TiledEditorIdAsGroupId(tiledEditorId);
				if(groupId != GroupId::None && itemGroups->find(groupId) != itemGroups->end())
					tiledEditorId = (TiledEditorId)itemGroups->at(groupId)->GetRandomTiledId();
				ItemType itemType = TiledEditorIdAsItemType(tiledEditorId);
				if(itemType != ItemType::None)
					__boardoutcells[x]->push_back(new ItemDescription(itemType, tiledEditorId, new ItemProperties(&__cellMeta.TiledObject.Properties)));
			}
		}
		this->CurrentLevel->SetPredefinedFills(__boardoutcells);
	}

	// create in of visible board cells
	std::vector<std::vector<Cell*>> cellarray; cellarray.resize(width);
	for(int x = 0; x < width; x++) {
		cellarray[x].resize(height, nullptr);
		for(int y = 0; y < height; y++) {
			//GameObject gameObject = Object.Instantiate<GameObject>(this->CellPrefab);
			//if(!(gameObject == null)) {
			//	gameObject.get_transform().SetParent(this->CellContainer);
			//	gameObject.get_transform().set_localPosition(new Vector3((float)x, (float)y, 0f));
			Cell* __cell = new Cell(); // gameObject.GetComponent<Cell>();
			__cell->X = x;
			__cell->Y = y;
			__cell->initRenderer(CellContainer, cocos2d::Vec2((float)x*ITEM_SPRITE_SIZE_X, (float)y*ITEM_SPRITE_SIZE_X));
			//	__cell.get_gameObject().set_name(string.Format("Cell_X{0}_Y{1}", x, y));
			CellMetaData& cellData = this->_currentLevelMetaData->CellList[LevelBuilder::CalculateOrderNo(x, y, width, __totalheight)];
			this->UpdateCellFromMetaData(__cell, &cellData);
			cellarray[x][y] = __cell;
			//}
		}
	}
	// create grid and set items
	Grid* grid = new Grid(cellarray);
	for(int x = 0; x < width; x++) {
		for(int y = 0; y < height; y++) {
			Cell* __cell = grid->cell(x, y);
			__cell->CurrentGrid = grid;
			CellMetaData& cellMetaData3 = this->_currentLevelMetaData->CellList[LevelBuilder::CalculateOrderNo(x, y, width, __totalheight)];
			CellData* __celldata = new CellData(); {
				__celldata->TiledObjectId = cellMetaData3.TiledObject.Id;
			}
			std::vector<MapFieldEntry>& properties = cellMetaData3.TiledObject.Properties;
			this->UpdateItemFromMetaData(__cell, __celldata, itemGroups, &properties);
		}
	}

	BubbleController::getInstance()->SetGrid(grid);
	ItemGeneratorController::getInstance()->SetGrid(grid);

	BorderBuilder bb(grid, IMGLIB->BorderImages);
	bb.Build();

	this->CellContainer->setScale(0.77f);
	cocos2d::Vec2 boardPos = this->CellContainer->getPosition() - cocos2d::Vec2(grid->Width - 1.0f, grid->Height - 1.0f)*ITEM_SPRITE_SIZE_X / 2 * this->CellContainer->getScale();
	this->CellContainer->setPosition(boardPos); //.set_localPosition(new Vector3((float)(-(float)grid.Width) / 2f + 0.5f, (float)(-(float)grid.Height) / 2f + 0.5f, 0f));

	return grid;
}

void LevelBuilder::UpdateFillLayerGroups(Level* level, std::map<int, Cell*>& fillCells) {
	if(!fillCells.empty() && fillCells.size() > 0 && level->CurrentItemGroups.size() > 0) {
		for(std::pair<GroupId, ItemGroup*> current : level->CurrentItemGroups) {
			GroupId key = current.first;
			ItemGroup* value = current.second;
			if(value->UseForDrop) {
				value->SetCurrentLevel(level);
				if(value->IsIntervalGroup() && !level->HasIntervalGroups) {
					level->HasIntervalGroups = true;
				}
				bool flag = value->DropPosList.size() == 0;
				for(std::pair<int, Cell*> current2 : fillCells) {
					current2.second->IsFilling = true;
					bool flag2 = false;
					if(flag) {
						flag2 = true;
					}
					else {
						for(int i = 0; i < (int)value->DropPosList.size(); i++) {
							int num = value->DropPosList[i];
							if(num == current2.second->X) {
								flag2 = true;
							}
						}
					}
					if(flag2) {
						if(value->IsIntervalGroup()) {
							current2.second->AddIntervalGroupId(key);
						}
						else {
							current2.second->AddFillGroupId(key, value->Ratio);
						}
					}
				}
			}
		}
	}
	else {
		//LogManager.Error(LogTags.LevelBuilder, "Cannot update fill layers!", new object[0]);
	}
}

void LevelBuilder::UpdateItemFromMetaData(Cell* cell, CellData* cellData, std::map<GroupId, ItemGroup*>* itemGroups, std::vector<MapFieldEntry>* Properties/* = nullptr*/) {
	// instancing group item
	GroupId groupId = TiledEditorIdAsGroupId((TiledEditorId)cellData->TiledObjectId);
	if(groupId != GroupId::None && itemGroups->find(groupId) != itemGroups->end())
		cellData->TiledObjectId = (*itemGroups)[groupId]->GetRandomTiledId();

	if(!cell->Exists || cellData->TiledObjectId == 9/*EMPTY*/)
		return;

	Item* item = this->CreateItemFromMetaData(cellData, Properties);
	if(item == nullptr)
		return;

	cell->set_CurrentItem(item);

	//item.get_transform().set_position(cell.get_transform().get_position());
	setCellItemSpritePosition(cell, item);

}
cocos2d::Sprite* LevelBuilder::getItemSprite(Item* item) {
	GiantPinataItem* gpItem = dynamic_cast<GiantPinataItem*>(item);				if(gpItem != nullptr) return gpItem->BaseImage;
	SodaItem* sdItem = dynamic_cast<SodaItem*>(item);							if(sdItem != nullptr) return sdItem->BackSpriteRenderer;
	ColoredSodaItem* csItem = dynamic_cast<ColoredSodaItem*>(item);				if(csItem != nullptr) return csItem->BackSpriteRenderer;
	WatermelonItem* wmItem = dynamic_cast<WatermelonItem*>(item);				if(wmItem != nullptr) return wmItem->RendererRoot;
	FishItem* fsItem = dynamic_cast<FishItem*>(item);							if(fsItem != nullptr) return fsItem->Renderer;
	BalloonGeneratorItem* bgItem = dynamic_cast<BalloonGeneratorItem*>(item);	if(bgItem != nullptr) return bgItem->Renderer;
	SpriteBasedItem* spItem = dynamic_cast<SpriteBasedItem*>(item);				if(spItem != nullptr) return spItem->CurrentSpriteRenderer;

	return nullptr;
}

void LevelBuilder::setCellItemSpritePosition(Cell* cell, Item* item) {
	cocos2d::Sprite* __sprite = getItemSprite(item);
	if(__sprite == nullptr) return;

	__sprite->setPosition((float)cell->X*ITEM_SPRITE_SIZE_X, (float)cell->Y*ITEM_SPRITE_SIZE_X);
	__sprite->setLocalZOrder((int)__sprite->getUserData() + cell->Y);

}

void LevelBuilder::UpdateCellFromMetaData(Cell* cell, CellMetaData* cellData) {
	if(cellData->BubbleCount > 0)
		cell->AddBubble(false);

	cell->Exists = (cellData->TiledObject.Id != 0);
	if(!cell->Exists)
		return;

	//cell.Collider.set_enabled(true);
}

int LevelBuilder::CalculateOrderNo(int x, int y, int w, int h) {
	return x + (h - 1 - y) * w;
}

Item* LevelBuilder::CreateItemFromItemGroupEntry(ItemDescription* itemDescription) {
	return this->CreateItem(itemDescription);
}

Item* LevelBuilder::CreateItemFromMetaData(CellData* cellMetaData, std::vector<MapFieldEntry>* properties/* = nullptr*/) {
	TiledEditorId tiledObjectId = (TiledEditorId)cellMetaData->TiledObjectId;
	ItemDescription* itemDescription = new ItemDescription(TiledEditorIdAsItemType(tiledObjectId), tiledObjectId, new ItemProperties(properties));
	return this->CreateItem(itemDescription);
}

Item* LevelBuilder::CreateItem(ItemDescription* itemDescription) {
	Item* item = this->CreateItemInternal(itemDescription);
	if(item == nullptr)
		return item;

	item->AfterPoolInit();
	item->OnItemCreated(this->CurrentLevel);
	if(itemDescription->properties != nullptr && itemDescription->properties->hasFrame) {
		FrameItem* frameItem = (FrameItem*)this->CreateItemInternal(new ItemDescription(ItemType::Frame, TiledEditorId::None, nullptr));
		frameItem->set_InnerItem(item);
		frameItem->AfterPoolInit();
		frameItem->OnItemCreated(this->CurrentLevel);
		//item.get_gameObject().get_transform().SetParent(frameItem.RelativeContainer.get_transform());
		//item.get_gameObject().get_transform().set_localPosition(Vector3.get_zero());
		Sprite* spinneritem = LevelBuilder::getItemSprite(item);
		if(spinneritem != nullptr) {
			spinneritem->removeFromParent();
			frameItem->CurrentSpriteRenderer->addChild(spinneritem);
			//spinneritem->CurrentSpriteRenderer->setPosition(Vec2(frameItem->CurrentSpriteRenderer->getTextureRect().getMidX(), frameItem->CurrentSpriteRenderer->getTextureRect().getMidY()));
			spinneritem->setPosition(0, 0);
			//spinneritem->CurrentSpriteRenderer->set(0.5f);
		}
		item = frameItem;
	}
	return item;
}

bool LevelBuilder::CreateItemAtCell(ItemType itemType, Cell* cell) {
	ItemDescription* itemDescription = new ItemDescription(itemType, TiledEditorId::None, nullptr);
	Item* item = this->CreateItemInternal(itemDescription);
	if(item == nullptr) {
		return false;
	}
	item->AfterPoolInit();
	item->OnItemCreated(this->CurrentLevel);
	cell->set_CurrentItem(item);
	//item->get_transform().set_position(cell.get_transform().get_position());
	setCellItemSpritePosition(cell, item);

	return true;
}

Item* LevelBuilder::CreateItemInternal(ItemDescription* itemDescription) {
	switch(itemDescription->itemType) {
	case ItemType::ColoredBalloon:
	{
		//ColoredBalloonItem component = Object.Instantiate<GameObject>(this->ColoredBalloonItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<ColoredBalloonItem>();
		ColoredBalloonItem* __coloredballonItem = new ColoredBalloonItem();
		ItemContainer->addChild(__coloredballonItem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __coloredballonItem->CurrentSpriteRenderer->setUserData((void*)__coloredballonItem->CurrentSpriteRenderer->getLocalZOrder());

		ColoredBalloonType type = ColoredBalloonType::None;
		switch(itemDescription->tiledEditorId) {
		case TiledEditorId::ColoredBallon1: type = ColoredBalloonType::Balloon1; break;
		case TiledEditorId::ColoredBallon2: type = ColoredBalloonType::Balloon2; break;
		case TiledEditorId::ColoredBallon3: type = ColoredBalloonType::Balloon3; break;
		case TiledEditorId::ColoredBallon4: type = ColoredBalloonType::Balloon4; break;
		case TiledEditorId::ColoredBallon5: type = ColoredBalloonType::Balloon5; break;
		case TiledEditorId::ColoredBallon6: type = ColoredBalloonType::Balloon6; break;
		}
		__coloredballonItem->SetupItem(type);
		return __coloredballonItem;// component;
	}
	case ItemType::RocketAndBomb:
	{
		RocketAndBombItem* __rocketbombitem = new RocketAndBombItem();
		ItemContainer->addChild(__rocketbombitem->CurrentSpriteRenderer, ITEM_SPECIAL_ZORDER_BASE); __rocketbombitem->CurrentSpriteRenderer->setUserData((void*)__rocketbombitem->CurrentSpriteRenderer->getLocalZOrder());
		return __rocketbombitem;// Object.Instantiate<GameObject>(this->RocketAndBombItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<RocketAndBombItem>();
	}
	case ItemType::DiscoBallAndBomb:
	{
		DiscoBallAndBombItem* __discobombitem = new DiscoBallAndBombItem();
		ItemContainer->addChild(__discobombitem->CurrentSpriteRenderer, ITEM_SPECIAL_ZORDER_BASE); __discobombitem->CurrentSpriteRenderer->setUserData((void*)__discobombitem->CurrentSpriteRenderer->getLocalZOrder());
		return __discobombitem;// Object.Instantiate<GameObject>(this->DiscoBallAndBombItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<DiscoBallAndBombItem>();
	}
	case ItemType::DiscoBallAndRocket:
	{
		DiscoBallAndRocketItem* __discorocketitem = new DiscoBallAndRocketItem();
		ItemContainer->addChild(__discorocketitem->CurrentSpriteRenderer, ITEM_SPECIAL_ZORDER_BASE); __discorocketitem->CurrentSpriteRenderer->setUserData((void*)__discorocketitem->CurrentSpriteRenderer->getLocalZOrder());
		return __discorocketitem;// Object.Instantiate<GameObject>(this->DiscoBallAndRocketItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<DiscoBallAndRocketItem>();
	}
	case ItemType::DoubleDiscoBall:
	{
		DoubleDiscoBallItem* __doublediscoitem = new DoubleDiscoBallItem();
		ItemContainer->addChild(__doublediscoitem->CurrentSpriteRenderer, ITEM_SPECIAL_ZORDER_BASE); __doublediscoitem->CurrentSpriteRenderer->setUserData((void*)__doublediscoitem->CurrentSpriteRenderer->getLocalZOrder());
		return __doublediscoitem;// Object.Instantiate<GameObject>(this->DoubleDiscoBallItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<DoubleDiscoBallItem>();
	}
	case ItemType::DoubleBomb:
	{
		//DoubleBombItem component2 = Object.Instantiate<GameObject>(this->DoubleBombItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<DoubleBombItem>();
		//component2.AddShakeReferences(this->ShakePanels);
		DoubleBombItem* __doublebombitem = new DoubleBombItem();
		ItemContainer->addChild(__doublebombitem->CurrentSpriteRenderer, ITEM_SPECIAL_ZORDER_BASE); __doublebombitem->CurrentSpriteRenderer->setUserData((void*)__doublebombitem->CurrentSpriteRenderer->getLocalZOrder());
		return __doublebombitem;// component2;
	}
	case ItemType::DoubleRocket:
	{
		DoubleRocketItem* __doublerocketitem = new DoubleRocketItem();
		__doublerocketitem->SetupItem();
		ItemContainer->addChild(__doublerocketitem->CurrentSpriteRenderer, ITEM_SPECIAL_ZORDER_BASE); __doublerocketitem->CurrentSpriteRenderer->setUserData((void*)__doublerocketitem->CurrentSpriteRenderer->getLocalZOrder());
		return __doublerocketitem;// Object.Instantiate<GameObject>(this->DoubleRocketItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<DoubleRocketItem>();
	}
	case ItemType::Bomb:
	{
		BombItem* __bomb = new BombItem();
		ItemContainer->addChild(__bomb->CurrentSpriteRenderer, ITEM_SPECIAL_ZORDER_BASE); __bomb->CurrentSpriteRenderer->setUserData((void*)__bomb->CurrentSpriteRenderer->getLocalZOrder());
		__bomb->SetupItem();
		return __bomb; // this->BombItemPrefab.Spawn().GetComponent<BombItem>();
	}
	case ItemType::Rocket:
	{
		TiledEditorId tiledEditorId = itemDescription->tiledEditorId;
		if(tiledEditorId == TiledEditorId::RocketHorizantal) {
			HorizontalRocketItem* __hrocket = new HorizontalRocketItem();
			ItemContainer->addChild(__hrocket->CurrentSpriteRenderer, ITEM_SPECIAL_ZORDER_BASE); __hrocket->CurrentSpriteRenderer->setUserData((void*)__hrocket->CurrentSpriteRenderer->getLocalZOrder());
			__hrocket->SetupItem();
			return __hrocket;// this->HorizantalRockItemPrefab.Spawn().GetComponent<HorizontalRocketItem>();
		}
		if(tiledEditorId == TiledEditorId::RocketVertical) {
			VerticalRocketItem* __vrocket = new VerticalRocketItem();
			ItemContainer->addChild(__vrocket->CurrentSpriteRenderer, ITEM_SPECIAL_ZORDER_BASE); __vrocket->CurrentSpriteRenderer->setUserData((void*)__vrocket->CurrentSpriteRenderer->getLocalZOrder());
			__vrocket->SetupItem();
			return __vrocket;// this->VerticalRockItemPrefab.Spawn().GetComponent<VerticalRocketItem>();
		}
	}
	case ItemType::DiscoBall:
	{
		//DiscoBallItem component3 = this->DiscoBallItemPrefab.Spawn().GetComponent<DiscoBallItem>();
		//component3.get_transform().SetParent(this->ItemContainer.get_transform());
		DiscoBallItem* __discoball = new DiscoBallItem();
		ItemContainer->addChild(__discoball->CurrentSpriteRenderer, ITEM_SPECIAL_ZORDER_BASE); __discoball->CurrentSpriteRenderer->setUserData((void*)__discoball->CurrentSpriteRenderer->getLocalZOrder());
		MatchType matchType = MatchType::None;
		switch(itemDescription->tiledEditorId) {
		case TiledEditorId::DiscoBallColor1:
			matchType = MatchType::Yellow;
			break;
		case TiledEditorId::DiscoBallColor2:
			matchType = MatchType::Red;
			break;
		case TiledEditorId::DiscoBallColor3:
			matchType = MatchType::Blue;
			break;
		case TiledEditorId::DiscoBallColor4:
			matchType = MatchType::Green;
			break;
		case TiledEditorId::DiscoBallColor5:
			matchType = MatchType::Purple;
			break;
		case TiledEditorId::DiscoBallColor6:
			matchType = MatchType::Orange;
			break;
		}
		//component3.EffectiveItemType = matchType;
		__discoball->EffectiveItemType = matchType;
		__discoball->SetTintColor(matchType);
		//component3.SetTintColor(matchType);
		return __discoball;// component3;
	}
	case ItemType::SolidColor1:
	case ItemType::SolidColor2:
	case ItemType::SolidColor3:
	case ItemType::SolidColor4:
	case ItemType::SolidColor5:
	case ItemType::SolidColor6:
	{
		SolidColorItem* __solidcoloritem = new SolidColorItem();// this->SolidColorItemPrefab.Spawn().GetComponent<SolidColorItem>();
		ItemContainer->addChild(__solidcoloritem->GlowSpriteRenderer, ITEM_GLOW_ZORDER_BASE);
		ItemContainer->addChild(__solidcoloritem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __solidcoloritem->CurrentSpriteRenderer->setUserData((void*)__solidcoloritem->CurrentSpriteRenderer->getLocalZOrder());
		__solidcoloritem->SetupItem(itemDescription->itemType);
		return __solidcoloritem;
	}
	case ItemType::Duck:
	{
		//DuckItem component5 = Object.Instantiate<GameObject>(this->DuckItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<DuckItem>();
		//component5.SetupItem(itemDescription.TiledEditorId);
		DuckItem* __duckitem = new DuckItem();
		ItemContainer->addChild(__duckitem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __duckitem->CurrentSpriteRenderer->setUserData((void*)__duckitem->CurrentSpriteRenderer->getLocalZOrder());
		__duckitem->SetupItem(itemDescription->tiledEditorId);
		return __duckitem;// component5;
	}
	case ItemType::Balloon: {
		BalloonItem* __balloonitem = new BalloonItem();
		ItemContainer->addChild(__balloonitem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __balloonitem->CurrentSpriteRenderer->setUserData((void*)__balloonitem->CurrentSpriteRenderer->getLocalZOrder());
		__balloonitem->SetupItem();
		return __balloonitem;// Object.Instantiate<GameObject>(this->BalloonItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<BalloonItem>();
	}
	case ItemType::Pinata:
	{
		PinataItem* __pinataitem = new PinataItem();
		ItemContainer->addChild(__pinataitem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __pinataitem->CurrentSpriteRenderer->setUserData((void*)__pinataitem->CurrentSpriteRenderer->getLocalZOrder());
		__pinataitem->SetupItem();
		return __pinataitem;// Object.Instantiate<GameObject>(this->PinataItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<PinataItem>();
	}
	case ItemType::LightBulb:
	{
		LightBulbItem* __lightbulbitem = new LightBulbItem();
		ItemContainer->addChild(__lightbulbitem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __lightbulbitem->CurrentSpriteRenderer->setUserData((void*)__lightbulbitem->CurrentSpriteRenderer->getLocalZOrder());
		__lightbulbitem->SetupItem();
		return __lightbulbitem;// Object.Instantiate<GameObject>(this->LightBulbItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<LightBulbItem>();
	}
	case ItemType::Crate:
	{
		//CrateItem component6 = Object.Instantiate<GameObject>(this->CrateItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<CrateItem>();
		CrateItem* __crateitem = new CrateItem();
		ItemContainer->addChild(__crateitem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __crateitem->CurrentSpriteRenderer->setUserData((void*)__crateitem->CurrentSpriteRenderer->getLocalZOrder());
		switch(itemDescription->tiledEditorId) {
		case TiledEditorId::Crate:		 __crateitem->LayerCount = 1; break;
		case TiledEditorId::CrateLayer1: __crateitem->LayerCount = 2; break;
		case TiledEditorId::CrateLayer2: __crateitem->LayerCount = 3; break;
		case TiledEditorId::CrateLayer3: __crateitem->LayerCount = 4; break;
		}
		//component6.CurrentSpriteRenderer.set_sprite(ImageLibrary.Instance.CrateLayerSprites[component6.LayerCount - 1]);
		__crateitem->SetupItem();
		return __crateitem; //component6;
	}
	case ItemType::ColoredCrate:
	{
		//ColoredCrateItem component7 = Object.Instantiate<GameObject>(this->ColoredCrateItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<ColoredCrateItem>();
		ColoredCrateItem* __coloredcrateitem = new ColoredCrateItem();
		ItemContainer->addChild(__coloredcrateitem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __coloredcrateitem->CurrentSpriteRenderer->setUserData((void*)__coloredcrateitem->CurrentSpriteRenderer->getLocalZOrder());
		//component7.SetupItem(itemDescription.TiledEditorId);
		__coloredcrateitem->SetupItem(itemDescription->tiledEditorId);
		return __coloredcrateitem;// component7;
	}
	case ItemType::GiantDuck:
	{
		GiantDuckItem* __giantduckItem = new GiantDuckItem();
		ItemContainer->addChild(__giantduckItem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __giantduckItem->CurrentSpriteRenderer->setUserData((void*)__giantduckItem->CurrentSpriteRenderer->getLocalZOrder());
		__giantduckItem->SetupItem();
		return __giantduckItem;// Object.Instantiate<GameObject>(this->GiantDuckItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<GiantDuckItem>();
	}
	case ItemType::EasterEgg:
	{
		EasterEggItem* __eastereggitem = new EasterEggItem();
		ItemContainer->addChild(__eastereggitem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __eastereggitem->CurrentSpriteRenderer->setUserData((void*)__eastereggitem->CurrentSpriteRenderer->getLocalZOrder());
		__eastereggitem->SetupItem();
		return __eastereggitem;// Object.Instantiate<GameObject>(this->EasterEggItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<EasterEggItem>();
	}
	case ItemType::MagicHat:
	{
		MagicHatItem* __magichatitem = new MagicHatItem();
		ItemContainer->addChild(__magichatitem->CurrentSpriteRenderer, ITEM_MAGICHAT_ZORDER_BASE); __magichatitem->CurrentSpriteRenderer->setUserData((void*)__magichatitem->CurrentSpriteRenderer->getLocalZOrder());
		__magichatitem->SetupItem();
		return __magichatitem;// Object.Instantiate<GameObject>(this->MagicHatItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<MagicHatItem>();
	}
	case ItemType::Jelly:
	{
		JellyItem* __jellyitem = new JellyItem();
		ItemContainer->addChild(__jellyitem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __jellyitem->CurrentSpriteRenderer->setUserData((void*)__jellyitem->CurrentSpriteRenderer->getLocalZOrder());
		__jellyitem->SetupItem();
		return __jellyitem;// Object.Instantiate<GameObject>(this->JellyItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<JellyItem>();
	}
	case ItemType::CanToss:
	{
		CanTossItem* __cantossitem = new CanTossItem();
		ItemContainer->addChild(__cantossitem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __cantossitem->CurrentSpriteRenderer->setUserData((void*)__cantossitem->CurrentSpriteRenderer->getLocalZOrder());
		__cantossitem->SetupItem();
		return __cantossitem;// Object.Instantiate<GameObject>(this->CanTossItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<CanTossItem>();
	}
	case ItemType::Frame:
	{
		FrameItem* __frameitem = new FrameItem();
		ItemContainer->addChild(__frameitem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __frameitem->CurrentSpriteRenderer->setUserData((void*)__frameitem->CurrentSpriteRenderer->getLocalZOrder());
		__frameitem->SetupItem();
		return __frameitem;// Object.Instantiate<GameObject>(this->FrameItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<FrameItem>();
	}
	case ItemType::GiantPinata:
	{
		GiantPinataItem* __giantpinata = new GiantPinataItem();
		ItemContainer->addChild(__giantpinata->BaseImage, ITEM_SPRITE_ZORDER_BASE); __giantpinata->BaseImage->setUserData((void*)__giantpinata->BaseImage->getLocalZOrder());
		__giantpinata->SetupItem();
		return __giantpinata; //Object.Instantiate<GameObject>(this->GiantPinataItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<GiantPinataItem>();
	}
	case ItemType::Oyster:
	{
		OysterItem* __oysteritem = new OysterItem();
		ItemContainer->addChild(__oysteritem->CurrentSpriteRenderer, ITEM_MAGICHAT_ZORDER_BASE); __oysteritem->CurrentSpriteRenderer->setUserData((void*)__oysteritem->CurrentSpriteRenderer->getLocalZOrder());
		__oysteritem->SetupItem();
		return __oysteritem;// Object.Instantiate<GameObject>(this->OysterItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<OysterItem>();
	}
	case ItemType::Soda:
	{
		//SodaItem component8 = Object.Instantiate<GameObject>(this->SodaItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<SodaItem>();
		//component8.Init((itemDescription.TiledEditorId != TiledEditorId.Soda4) ? 5 : 4);
		SodaItem* __sodaitem = new SodaItem();
		ItemContainer->addChild(__sodaitem->BackSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __sodaitem->BackSpriteRenderer->setUserData((void*)__sodaitem->BackSpriteRenderer->getLocalZOrder());
		__sodaitem->Init((itemDescription->tiledEditorId != TiledEditorId::Soda4) ? 5 : 4);
		return __sodaitem;// component8;
	}
	case ItemType::WaterMelon:
	{
		WatermelonItem* __watermelonitem = new WatermelonItem();
		ItemContainer->addChild(__watermelonitem->RendererRoot, ITEM_SPRITE_ZORDER_BASE); __watermelonitem->RendererRoot->setUserData((void*)__watermelonitem->RendererRoot->getLocalZOrder());
		__watermelonitem->SetupItem();
		return __watermelonitem;// Object.Instantiate<GameObject>(this->PupmkinItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<WatermelonItem>();
	}
	case ItemType::MetalCrate:
	{
		MetalCrateItem* __metalcrateitem = new MetalCrateItem();
		ItemContainer->addChild(__metalcrateitem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __metalcrateitem->CurrentSpriteRenderer->setUserData((void*)__metalcrateitem->CurrentSpriteRenderer->getLocalZOrder());
		__metalcrateitem->SetupItem();
		return __metalcrateitem;// Object.Instantiate<GameObject>(this->MetalCratePrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<MetalCrateItem>();
	}
	case ItemType::Fish:
	{
		//FishItem* component9 = new FishItem();// Object.Instantiate<GameObject>(this->FishItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<FishItem>();
		FishItem* __fishitem = new FishItem();
		ItemContainer->addChild(__fishitem->Renderer, ITEM_MAGICHAT_ZORDER_BASE); __fishitem->Renderer->setUserData((void*)__fishitem->Renderer->getLocalZOrder());
		__fishitem->SetupItem();
		int direction = (itemDescription->tiledEditorId != TiledEditorId::Fish1) ? 1 : 0;
		//component9.SetDirection(direction);
		__fishitem->SetDirection(direction);
		return __fishitem;// component9;
	}
	case ItemType::BalloonGenerator:
	{
		//BalloonGeneratorItem component10 = Object.Instantiate<GameObject>(this->GeneratorItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<BalloonGeneratorItem>();
		BalloonGeneratorItem* __balloongeneratoritem = new BalloonGeneratorItem();
		ItemContainer->addChild(__balloongeneratoritem->Renderer, ITEM_MAGICHAT_ZORDER_BASE); __balloongeneratoritem->Renderer->setUserData((void*)__balloongeneratoritem->Renderer->getLocalZOrder());
		__balloongeneratoritem->SetupItem();
		int __dir = (itemDescription->tiledEditorId != TiledEditorId::BalloonGenerator1) ? 1 : 0;
		__balloongeneratoritem->SetDirection(__dir);
		return __balloongeneratoritem;// component10;
	}
	case ItemType::Honey:
	{
		HoneyItem* __honeyitem = new HoneyItem();
		ItemContainer->addChild(__honeyitem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __honeyitem->CurrentSpriteRenderer->setUserData((void*)__honeyitem->CurrentSpriteRenderer->getLocalZOrder());
		__honeyitem->SetupItem();
		return __honeyitem;// Object.Instantiate<GameObject>(this->HoneyItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<HoneyItem>();
	}
	case ItemType::Diamond:
	{
		//DiamondItem component11 = Object.Instantiate<GameObject>(this->DiamondItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<DiamondItem>();
		DiamondItem* __diamonditem = new DiamondItem();
		ItemContainer->addChild(__diamonditem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __diamonditem->CurrentSpriteRenderer->setUserData((void*)__diamonditem->CurrentSpriteRenderer->getLocalZOrder());
		__diamonditem->SetupItem();
		__diamonditem->UpdateView(itemDescription->tiledEditorId== TiledEditorId::DiamondOpen, false);
		return __diamonditem; //component11;
	}
	case ItemType::Billboard:
	{
		BillboardItem* __billboarditem = new BillboardItem();
		ItemContainer->addChild(__billboarditem->CurrentSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __billboarditem->CurrentSpriteRenderer->setUserData((void*)__billboarditem->CurrentSpriteRenderer->getLocalZOrder());
		__billboarditem->SetupItem();
		return __billboarditem;// Object.Instantiate<GameObject>(this->BillboardItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<BillboardItem>();
	}
	case ItemType::ColoredSoda:
	{
		//ColoredSodaItem component12 = Object.Instantiate<GameObject>(this->ColoredSodaItemPrefab, Vector3.get_zero(), Quaternion.get_identity(), this->ItemContainer.get_transform()).GetComponent<ColoredSodaItem>();
		ColoredSodaItem* __coloredsodaitem = new ColoredSodaItem();
		ItemContainer->addChild(__coloredsodaitem->BackSpriteRenderer, ITEM_SPRITE_ZORDER_BASE); __coloredsodaitem->BackSpriteRenderer->setUserData((void*)__coloredsodaitem->BackSpriteRenderer->getLocalZOrder());
		MatchType __type = MatchType::None;
		switch(itemDescription->tiledEditorId) {
		case TiledEditorId::ColoredSodaYellow: __type = MatchType::Yellow; break;
		case TiledEditorId::ColoredSodaRed: __type = MatchType::Red; break;
		case TiledEditorId::ColoredSodaBlue: __type = MatchType::Blue; break;
		case TiledEditorId::ColoredSodaGreen: __type = MatchType::Green; break;
		case TiledEditorId::ColoredSodaPurple: __type = MatchType::Purple; break;
		}
		__coloredsodaitem->Init(__type);
		return __coloredsodaitem;// component12;
	}
	}
	//LogManager.Error(LogTags.LevelBuilder, "Unexpected type: {0}:", new object[] {
	//	itemDescription.ItemType
	//});
	return nullptr;
}

HorizontalRocketItem* LevelBuilder::CreateRandomRocket(cocos2d::Vec2 position) {
	return (Mathf::Random::Range(0, 10) >= 5) ? (HorizontalRocketItem*)this->CreateVerticallRocket(position) : this->CreateHorizantalRocket(position);
}

HorizontalRocketItem* LevelBuilder::CreateHorizantalRocket(cocos2d::Vec2 position) {
	HorizontalRocketItem* horizontalRocketItem = dynamic_cast<HorizontalRocketItem*>(this->CreateItem(new ItemDescription(ItemType::Rocket, TiledEditorId::RocketHorizantal, nullptr)));
	//horizontalRocketItem.get_transform().set_position(position);
	horizontalRocketItem->CurrentSpriteRenderer->setPosition(position);
	return horizontalRocketItem;
}

VerticalRocketItem* LevelBuilder::CreateVerticallRocket(cocos2d::Vec2 position) {
	VerticalRocketItem* verticalRocketItem = dynamic_cast<VerticalRocketItem*>(this->CreateItem(new ItemDescription(ItemType::Rocket, TiledEditorId::RocketVertical, nullptr)));
	//verticalRocketItem.get_transform().set_position(position);
	verticalRocketItem->CurrentSpriteRenderer->setPosition(position);
	return verticalRocketItem;
}

SpecialItem* LevelBuilder::CreateSpecialItem(ItemType type, MatchType m, cocos2d::Vec2 position, Cell* cell) {
	SpecialItem* specialItem;
	if(this->CurrentLevel->LevelNo == 2 && type == ItemType::Rocket) {
		if(cell->Y > 3 && cell->X < 2)
			specialItem = dynamic_cast<SpecialItem*>(this->CreateVerticallRocket(position));
		else if(cell->X > 1 && cell->X < 5 && cell->Y > 2 && cell->Y < 7)
			specialItem = dynamic_cast<SpecialItem*>(this->CreateVerticallRocket(position));
		else if(cell->X > 4 && cell->Y < 3)
			specialItem = dynamic_cast<SpecialItem*>(this->CreateHorizantalRocket(position));
		else
			specialItem = dynamic_cast<SpecialItem*>(this->CreateRandomRocket(position));
		
		return specialItem;
	}
	if(this->CurrentLevel->LevelNo == 11 && type == ItemType::Rocket) {
		for(int i = 0; i < (int)this->CurrentLevel->Goals.size(); i++) {
			Goal* goal = this->CurrentLevel->Goals[i];
			if(goal->Type == ItemType::GiantDuck) {
				if(goal->Count > 0) {
					return dynamic_cast<SpecialItem*>(this->CreateVerticallRocket(position));
				}
			}
		}
	}
	switch(type) {
	case ItemType::Bomb:
		specialItem = dynamic_cast<SpecialItem*>(this->CreateItem(new ItemDescription(ItemType::Bomb, TiledEditorId::None, nullptr)));
		//specialItem.get_transform().set_position(position);
		specialItem->CurrentSpriteRenderer->setPosition(position);
		break;
	case ItemType::Rocket:
		specialItem = dynamic_cast<SpecialItem*>(this->CreateRandomRocket(position));
		break;
	case ItemType::DiscoBall:
	{
		if(m == MatchType::None) {
			m = MatchType::Yellow;
		}
		DiscoBallItem* discoBallItem = dynamic_cast<DiscoBallItem*>(this->CreateItem(new ItemDescription(ItemType::DiscoBall, (TiledEditorId)((int)TiledEditorId::DiscoBallColor1 + (int)m), nullptr)));
		discoBallItem->EffectiveItemType = m;
		discoBallItem->SetTintColor(m);
		specialItem = discoBallItem;
		//specialItem.get_transform().set_position(position);
		specialItem->CurrentSpriteRenderer->setPosition(position);
		break;
	}
	default:
		//LogManager.Error(LogTags.LevelBuilder, "Can not build special item. Unknown type:{0}", new object[] {
		//	type
		//});
		return nullptr;
	}
	return specialItem;
}

SpecialItem* LevelBuilder::CreateComboItem(MatchGroup* mgroup, cocos2d::Vec2 position) {
	SpecialItem* specialItem = (SpecialItem*)this->CreateItem(new ItemDescription(mgroup->ComboType, TiledEditorId::None, nullptr));
	if(mgroup->ComboType == ItemType::DiscoBallAndBomb || mgroup->ComboType == ItemType::DiscoBallAndRocket) {
		DiscoBallItem* discoBallItem = dynamic_cast<DiscoBallItem*>(specialItem);
		discoBallItem->EffectiveItemType = mgroup->GetFirstDiscoBall()->EffectiveItemType;
		discoBallItem->SetTintColor(discoBallItem->EffectiveItemType);
	}
	//specialItem.get_transform().set_position(position);
	specialItem->CurrentSpriteRenderer->setPosition(position);
	dynamic_cast<IComboItem*>(specialItem)->SetComboGroup(mgroup);
	return specialItem;
}

Cell* LevelBuilder::FindFirstExistingBottomCell(Cell* cell) {
	Grid* currentGrid = cell->CurrentGrid;
	if(cell->Y == 0) {
		return nullptr;
	}
	for(int i = cell->Y - 1; i >= 0; i--) {
		Cell* cell2 = currentGrid->cell(cell->X, i);
		if(cell2->Exists) {
			return cell2;
		}
	}
	return nullptr;
}

void LevelBuilder::PopulateEgoItems() {
	//if(EgoDialog.EGOItems == null || EgoDialog.EGOItems.Count == 0) {
	//	return;
	//}
	//std::vector<ItemType> eGOItems = EgoDialog.EGOItems;
	//EgoDialog.EGOItems = null;
	//this->CreateSelectedSpecialItems(eGOItems, false, true, null);
}

void LevelBuilder::PopulateSelectedPreLevelItems(std::vector<Cell*>* cellsNotAvailable) {
	std::vector<ItemType> latestSelectedItems;// = PrelevelDialog.LatestSelectedItems;
	if(GM->getLevelStartupItemHasRocket()) latestSelectedItems.push_back(ItemType::Rocket);
	if(GM->getLevelStartupItemHasBomb()) latestSelectedItems.push_back(ItemType::Bomb);
	if(GM->getLevelStartupItemHasDisco()) latestSelectedItems.push_back(ItemType::DiscoBall);

	if(latestSelectedItems.size() == 0) {
		return;
	}
	std::set<Cell*> hashSet;// = (cellsNotAvailable != null) ? new HashSet<Cell>(cellsNotAvailable) : new HashSet<Cell>();
	if(cellsNotAvailable != nullptr)
		for(Cell* _c : *cellsNotAvailable)
			hashSet.insert(_c);
	if(LevelBuilder::CurrentLevelNo == 10) {
		hashSet.insert(this->CurrentLevel->CurrentGrid->cell(4, 0));
	}
	this->CreateSelectedSpecialItems(latestSelectedItems, true, true, &hashSet);
}

void LevelBuilder::CreateSelectedSpecialItems(std::vector<ItemType>& selectedItems, bool spendFromInventory/* = true*/, bool playCreationParticle/* = false*/, std::set<Cell*>* cellsNotAvailable/* = nullptr*/) {
	std::vector<Cell*> list; list.reserve(91);
	for(Cell* current : this->CurrentLevel->CurrentGrid->WalkOnExistings()) {
		if(current->get_HasItem() && current->get_CurrentItem()->CanBeReplacedByPreLevelBooster() && (cellsNotAvailable == nullptr || cellsNotAvailable->find(current) == cellsNotAvailable->end())) {
			list.push_back(current);
		}
	}
	ListExt_Shuffle<Cell*>(list);
	int i = 0;
	int num = Mathf::Min((int)list.size(), (int)selectedItems.size());
	while(i < num) {
		ItemType itemType = selectedItems[i];
		Cell* cell = list[i];
		MatchType matchType = cell->get_CurrentItem()->GetMatchType();
		if(matchType == MatchType::None) {
			matchType = (MatchType)Mathf::Random::Range(0, 6);
		}
		Item* currentItem = (Item*)this->CreateSpecialItem(itemType, matchType, cell->GetFrozenPosition(), cell);
		if(playCreationParticle) {
			//ParticlePool.Instance.PlayParticle(ParticlePool.Instance.SpecialItemCreationParticle, cell.GetFrozenPosition(), true);
		}
		Item* currentItem2 = cell->get_CurrentItem();
		cell->set_CurrentItem(currentItem);
		CanCastShadowComponent::CastShadowIfPossible(cell);
		if(currentItem2 != nullptr) {
			currentItem2->RemoveSelf();
		}
		if(spendFromInventory) {
			if(itemType != ItemType::Rocket)
				GM->updateInvRocketCount(-1);
			if(itemType != ItemType::Bomb)
				GM->updateInvBombCount(-1);
			if(itemType == ItemType::DiscoBall)
				GM->updateInvDiscoCount(-1);

		}
		i++;
	}
}

void LevelBuilder::Reset() {
	LevelBuilder::CurrentLevelNo = GM->getTopLevel();//LevelHelper.Instance.GetHighestLevelUserWon();
}