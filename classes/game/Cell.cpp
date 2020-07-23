#include "Cell.h"
#include "Group.h"
#include "Item.h"
#include "Grid.h"
#include "Match.h"
#include "Level.h"
#include "LevelBuilder.h"
#include "ItemFeature.h"
#include "Mathf.h"
#include "Extension.h"
#include "BubbleController.h"
#include "ItemGeneratorController.h"
#include "Animation.h"
#include "FallManager.h"
#include "ImageLibrary.h"
#include "ParticleLibrary.h"

#include "ScnLevelPlay.h"

Cell::Cell() {
	for(int i = 0; i < 10; i++) {
		Borders.push_back(cocos2d::Sprite::create());
		Borders[i]->retain();
		Borders[i]->setVisible(false);
	}
	BubbleSpriteRenderer = cocos2d::Sprite::create();
	BubbleSpriteRenderer->retain();
}
Cell::~Cell() {
	for(int i = 0; i < (int)Borders.size(); i++)
		Borders[i]->release();
	Borders.clear();
	BubbleSpriteRenderer->release();
}

void Cell::initRenderer(cocos2d::Node* parent, cocos2d::Vec2 pos) {
	for(int i = 0; i < (int)Borders.size(); i++) {
		parent->addChild(Borders[i], ITEM_BORDER_ZORDER);
		cocos2d::Vec2 offset, ar;
		switch(i) {
		case 0: break;
		case 1: ar.set(1.0f, 1.0f); offset.set(-25.0f, -25.0f);	break;
		case 2: ar.set(0.5f, 1.0f); offset.set(  0.0f, -25.0f);	break;
		case 3: ar.set(0.0f, 1.0f); offset.set( 25.0f, -25.0f);	break;
		case 4: ar.set(1.0f, 0.5f); offset.set(-25.0f,   0.0f);	break;
		case 5: ar.set(0.5f, 0.5f); offset.set(  0.0f,   0.0f);	break;
		case 6: ar.set(0.0f, 0.5f); offset.set( 25.0f,   0.0f);	break;
		case 7: ar.set(1.0f, 0.0f); offset.set(-25.0f,  25.0f);	break;
		case 8: ar.set(0.5f, 0.0f); offset.set(  0.0f,  25.0f);	break;
		case 9: ar.set(0.0f, 0.0f); offset.set( 25.0f,  25.0f);	break;
		}
		Borders[i]->setAnchorPoint(ar);
		Borders[i]->setPosition(pos + offset);
	}
	parent->addChild(BubbleSpriteRenderer, ITEM_BUBBLE_ZORDER_BASE);
	BubbleSpriteRenderer->setPosition(pos);
}

bool Cell::get_HasItem() {
	return this->_currentItem != nullptr && !this->_currentItem->ReCycled;
}

void Cell::set_CurrentItem(Item* value) {
	if(this->_currentItem == value)
		return;
	
	Item* currentItem = this->_currentItem;
	this->_currentItem = value;
	if(currentItem != nullptr && currentItem->get_CurrentCell() == this) {
		currentItem->set_CurrentCell(nullptr);
	}
	if(value != nullptr) {
		value->set_CurrentCell(this);
	}
}

int Cell::GetBubbleScoreIfPossible() {
	return (this->LastBubbleRemoved != cocos2d::Director::getInstance()->getTotalFrames()) ? 0 : 500;
}

void Cell::ShowHighlight() {
	if(!this->Exists || !this->get_HasItem()) {
		return;
	}
	MatchGroup* match = this->CurrentGrid->GetMatch(this);
	if(match == nullptr || !match->CanMatchExplode) {
		return;
	}
	for(Cell* current : match->AllCells) {
		if(current->get_CurrentItem()->CanShowCurrentlyUnderTap()) {
			((ICanShowCurrentlyUnderTap*)current->get_CurrentItem())->ShowCurrentlyUnderTap();
		}
	}
}

bool Cell::CanItemFallFromThisCell() {
	return this->get_CurrentItem() == nullptr || this->get_CurrentItem()->CanFall();
}

std::string Cell::ToString() {
	char retstr[64];
	sprintf(retstr, "[Cell: X=%d, Y=%d]", this->X, this->Y);
	return retstr;
}

void Cell::RejectsFallInside() {
	this->_canItemsFallInside++;
}

void Cell::AcceptsFallInside() {
	this->_canItemsFallInside--;
	if(this->_canItemsFallInside < 0) {
		this->_canItemsFallInside = 0;
	}
}

bool Cell::CanItemsFallInside() {
	return this->_canItemsFallInside == 0;
}

void Cell::AddIntervalGroupId(GroupId id) {
	this->_intervalRefillGroupIds.push_back(id);
}

void Cell::AddFillGroupId(GroupId id, int ratio/* = 1*/) {
	ratio = Mathf::Max(0, Mathf::Min(100, ratio));
	int num = 0;
	if(this->_refillGroupWeights.size() > 0) {
		num = this->_refillGroupWeights[this->_refillGroupWeights.size() - 1];
	}
	num += ratio;
	this->_refillGroupWeights.push_back(num);
	this->_refillGroupIds.push_back(id);
}

Item* Cell::CreateRefillItem() {
	if(this->_refillGroupIds.size() <= 0) {
		return nullptr;
	}
	if(this->CurrentGrid->CurrentLevel->IsPredefinedLevel &&
	   this->CurrentGrid->CurrentLevel->PreDefinedFills.find(this->X) != this->CurrentGrid->CurrentLevel->PreDefinedFills.end() &&
	   this->CurrentGrid->CurrentLevel->PreDefinedFills[this->X]->size() != 0) {
		ItemDescription* itemDescription = this->CurrentGrid->CurrentLevel->PreDefinedFills[this->X]->front();
		this->CurrentGrid->CurrentLevel->PreDefinedFills[this->X]->pop_front();
		return this->CurrentGrid->CurrentLevel->CurrentLevelBuilder->CreateItem(itemDescription);
	}
	GroupId groupId = this->CurrentGrid->CurrentLevel->GetIntervalCompletedGroups(this->_intervalRefillGroupIds);
	if(groupId != GroupId::None) {
		return this->CurrentGrid->CurrentLevel->GetItemByGroupId(groupId);
	}
	int count = this->_refillGroupIds.size();
	int i = 0;
	int num = ListExt_GetRandomWeightedIndex(this->_refillGroupWeights);
	while(i < count) {
		GroupId groupId = this->_refillGroupIds[num];
		Item* itemByGroupId = this->CurrentGrid->CurrentLevel->GetItemByGroupId(groupId);
		if(itemByGroupId != nullptr) {
			return itemByGroupId;
		}
		i++;
		num = (num + 1) % count;
	}
	return nullptr;
}

//void Cell::Squash(/*Sequence seq,*/ cocos2d::Node* rt, float yScale, float time/*, Ease e = 1*/) {
//	TweenSettingsExtensions.Append(seq, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOScale(rt, new Vector3(1f / yScale, yScale), time), e));
//}

void Cell::ShakeBubble() {
	if(!this->HasBubble) {
		return;
	}
	//if(this->_seq != null) {
	//	TweenExtensions.Kill(this->_seq, false);
	//}
	//this->_seq = DOTween.Sequence();
	//Transform transform = this->BubbleSpriteRenderer.get_transform();
	//this->Squash(this->_seq, transform, 0.9f, 0.05f, 6);
	//this->Squash(this->_seq, transform, 1.06f, 0.08f, 6);
	//this->Squash(this->_seq, transform, 0.95f, 0.05f, 6);
	//this->Squash(this->_seq, transform, 1.03f, 0.04f, 6);
	//this->Squash(this->_seq, transform, 1f, 0.05f, 5);
	//TweenSettingsExtensions.OnComplete<Sequence>(this->_seq, delegate
	//{
	//	this->_seq = null;
	//});
	if(this->BubbleSpriteRenderer->getActionByTag(ANIMATION_BUBBLE) != nullptr)
		this->BubbleSpriteRenderer->stopActionByTag(ANIMATION_BUBBLE);
	cocos2d::Action* __animation = cocos2d::Sequence::create(
		cocos2d::ScaleTo::create(0.05f, 1 / 0.9f, 0.9f),
		cocos2d::ScaleTo::create(0.08f, 1 / 1.06f, 1.06f),
		cocos2d::ScaleTo::create(0.05f, 1 / 0.95f, 0.95f),
		cocos2d::ScaleTo::create(0.04f, 1 / 1.03f, 1.03f),
		cocos2d::ScaleTo::create(0.05f, 1 / 1.0f, 1.0f),
		nullptr
		);
	__animation->setTag(ANIMATION_BUBBLE);
	this->BubbleSpriteRenderer->runAction(__animation);
}

void Cell::AddBubble(bool isReserved/* = false*/) {
	BubbleController::getInstance()->IncreaseBubbleCount();
	this->ReservedForBubble = isReserved;
	if(!isReserved) {
		this->HasBubble = true;
		this->ShowBubble(false);
	}
}

void Cell::ReserveForItem(ItemType itemType) {
	if(this->ReservedForGeneratorItem) {
		return;
	}
	this->RejectsFallInside();
	this->_reservedItemType = itemType;
	this->ReservedForGeneratorItem = true;
}

void Cell::ApplyReservedItem() {
	if(!this->ReservedForGeneratorItem) {
		return;
	}
	this->ReservedForGeneratorItem = false;
	if(this->_reservedItemType != ItemType::None) {
		if(this->get_CurrentItem() != nullptr) {
			this->get_CurrentItem()->RemoveSelf();
		}
		this->CurrentGrid->CurrentLevel->CurrentLevelBuilder->CreateItemAtCell(this->_reservedItemType, this);
		this->_reservedItemType = ItemType::None;
		this->AcceptsFallInside();
		if(this->get_CurrentItem()->CanCastShadow() && this->JustBelowCell != nullptr && this->JustBelowCell->Exists && this->JustBelowCell->get_HasItem() && this->JustBelowCell->get_CurrentItem()->CanShadowDrop() && this->get_CurrentItem()->GetShadowCaster() != nullptr) {
			this->get_CurrentItem()->GetShadowCaster()->CastShadow();
		}
		//if(this->_seq != null) {
		//	TweenExtensions.Kill(this->_seq, false);
		//}
		//this->_seq = DOTween.Sequence();
		//if(!(this->CurrentItem == null)) {
		//	this->CurrentItem.BringToFront();
		//	this->CurrentItem.get_transform().set_localScale(new Vector3(1f, 1f, 1f));
		//	TweenSettingsExtensions.SetEase<Sequence>(TweenSettingsExtensions.Append(this->_seq, ShortcutExtensions.DOScale(this->CurrentItem.get_transform(), new Vector3(0.85f, 0.85f, 1f), 0.1f)), 1);
		//	TweenSettingsExtensions.SetEase<Sequence>(TweenSettingsExtensions.Append(this->_seq, ShortcutExtensions.DOScale(this->CurrentItem.get_transform(), new Vector3(1.1f, 1.1f, 1f), 0.1f)), 1);
		//	TweenSettingsExtensions.SetEase<Sequence>(TweenSettingsExtensions.Append(this->_seq, ShortcutExtensions.DOScale(this->CurrentItem.get_transform(), new Vector3(0.95f, 0.95f, 1f), 0.1f)), 1);
		//	TweenSettingsExtensions.SetEase<Sequence>(TweenSettingsExtensions.Append(this->_seq, ShortcutExtensions.DOScale(this->CurrentItem.get_transform(), new Vector3(1.05f, 1.05f, 1f), 0.1f)), 1);
		//	TweenSettingsExtensions.SetEase<Sequence>(TweenSettingsExtensions.Append(this->_seq, ShortcutExtensions.DOScale(this->CurrentItem.get_transform(), Vector3.get_one(), 0.1f)), 1);
		//	TweenSettingsExtensions.OnComplete<Sequence>(this->_seq, delegate
		//	{
		//		this->_seq = null;
		//		if(this->CurrentItem != null) {
		//			this->CurrentItem.SendToBack();
		//		}
		//	});
		//}
		cocos2d::Sprite* __sprite = LevelBuilder::getItemSprite(get_CurrentItem());
		if(__sprite) {
			if(__sprite->getActionByTag(ANIMATION_CELL))
				__sprite->stopActionByTag(ANIMATION_CELL);
			cocos2d::Action* __animation = cocos2d::Sequence::create(
				cocos2d::ScaleTo::create(0.1f, 0.85f),
				cocos2d::ScaleTo::create(0.1f, 1.1f),
				cocos2d::ScaleTo::create(0.1f, 0.95f),
				cocos2d::ScaleTo::create(0.1f, 1.05f),
				cocos2d::ScaleTo::create(0.1f, 1.0f),
				nullptr
				);
			__animation->setTag(ANIMATION_CELL);
			__sprite->runAction(__animation);
		}
	}
}

void Cell::ApplyReservedBubble() {
	if(!this->ReservedForBubble) {
		return;
	}
	this->ReservedForBubble = false;
	this->HasBubble = true;
	this->ShowBubble(true);
}

void Cell::RemoveBubble() {
	if(!this->HasBubble) {
		return;
	}
	//if(this->_seq != null) {
	//	TweenExtensions.Kill(this->_seq, false);
	//}
	if(this->BubbleSpriteRenderer->getActionByTag(ANIMATION_BUBBLE) != nullptr)
		this->BubbleSpriteRenderer->stopActionByTag(ANIMATION_BUBBLE);

	this->HasBubble = false;
	this->LastBubbleRemoved = Ext_getCurrentFrame();
	Level* currentLevel = this->CurrentGrid->CurrentLevel;
	this->BubbleSpriteRenderer->setVisible(false);

	//GameObject gameObject = currentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(this->BubbleSpriteRenderer.get_transform().get_position());
	//ParticlePool.Instance.PlayParticle(ParticlePool.Instance.BubbleExplodeParticle, this->GetFrozenPosition(), true);
	PTCLLIB->explodeBubble(BubbleSpriteRenderer->getPosition());
	//AudioManager.Play(AudioTag.Bubble, PlayMode.Frame, null, 1f);
	//gameObject.GetComponent<CollectAnimation>().Prepare(currentLevel, ItemType.Bubble, DefinedSo rting.Collecting.GetSo rting(), null, this->).StartAnimation();
	//CollectAnimation Prepare(Level currentLevel, ItemType goalType, S orting s, Sprite sprite, Cell currentCell) {
	//	...
		currentLevel->PreCheckDecreaseGoal(ItemType::Bubble);
	//	...
		currentLevel->StopRefillIfNeeded(ItemType::Bubble);
	//	...
		FallManager::getInstance()->IncreaseStatAnimation();
	//	...
	//}
	//->StartAnimation();
	int goalidx = currentLevel->CurrentLevelBuilder->LevelScene->getGoalIdx(ItemType::Bubble);
	if(goalidx >= 0) {
		currentLevel->CurrentLevelBuilder->LevelScene->playGoalFx(goalidx);
		currentLevel->DecreaseGoal(ItemType::Bubble, true);
	}
}

void Cell::ShowBubble(bool animated/* = false*/) {
	if(this->HasBubble) {
		ImageLibrary::CopySprite(this->BubbleSpriteRenderer, IMGLIB->Bubble);
		this->BubbleSpriteRenderer->setVisible(true);
		this->BubbleSpriteRenderer->setLocalZOrder(this->BubbleSpriteRenderer->getLocalZOrder() + BubbleController::getInstance()->BubbleCount());
		if(animated) {
			//if(this->_seq != null) {
			//	TweenExtensions.Kill(this->_seq, false);
			//}
			//this->_seq = DOTween.Sequence();
			//AudioManager.Play(AudioTag.ItemBubblePlace, PlayMode.Frame, null, 1f);
			//this->BubbleSpriteRenderer.get_transform().set_localScale(new Vector3(0.9f, 0.9f, 1f));
			//TweenSettingsExtensions.SetEase<Sequence>(TweenSettingsExtensions.Append(this->_seq, ShortcutExtensions.DOScale(this->BubbleSpriteRenderer.get_transform(), new Vector3(1.2f, 0.9f, 1f), 0.1f)), 1);
			//TweenSettingsExtensions.SetEase<Sequence>(TweenSettingsExtensions.Append(this->_seq, ShortcutExtensions.DOScale(this->BubbleSpriteRenderer.get_transform(), new Vector3(1f, 1.2f, 1f), 0.1f)), 1);
			//TweenSettingsExtensions.SetEase<Sequence>(TweenSettingsExtensions.Append(this->_seq, ShortcutExtensions.DOScale(this->BubbleSpriteRenderer.get_transform(), Vector3.get_one(), 0.1f)), 1);
			//TweenSettingsExtensions.OnComplete<Sequence>(this->_seq, delegate
			//{
			//	this->_seq = null;
			//});

			if(this->BubbleSpriteRenderer->getActionByTag(ANIMATION_BUBBLE) != nullptr)
				this->BubbleSpriteRenderer->stopActionByTag(ANIMATION_BUBBLE);
			//AudioManager.Play(AudioTag.ItemBubblePlace, PlayMode.Frame, null, 1f);
			BubbleSpriteRenderer->setScale(0.9f, 0.9f);
			cocos2d::Action* __animation = cocos2d::Sequence::create(
				cocos2d::ScaleTo::create(0.1f, 1.2f, 0.9f),
				cocos2d::ScaleTo::create(0.1f, 1.0f, 1.2f),
				cocos2d::ScaleTo::create(0.1f, 1.0f, 1.0f),
				nullptr
				);
			__animation->setTag(ANIMATION_BUBBLE);
			this->BubbleSpriteRenderer->runAction(__animation);
		}
	}
}

std::vector<Cell*> Cell::GetCachedNeigbours(bool includeCorners) {
	if(includeCorners) {
		if(this->_cachedNeigboursWithCorners.empty()) {
			this->_cachedNeigboursWithCorners = this->CalculateNeigbours(true);
		}
		return this->_cachedNeigboursWithCorners;
	}

	if(this->_cachedNeigboursWithoutCorners.empty()) {
		this->_cachedNeigboursWithoutCorners = this->CalculateNeigbours(false);
	}
	return this->_cachedNeigboursWithoutCorners;
}

std::vector<Cell*> Cell::CalculateNeigbours(bool includeCorners) {
	int height = this->CurrentGrid->Height;
	int width = this->CurrentGrid->Width;

	std::vector<Cell*> list;
	list.reserve((!includeCorners) ? 4 : 8);

	if(this->X - 1 >= 0)												Cell::AddIfExists(list, this->CurrentGrid->cell(this->X - 1, this->Y));	
	if(includeCorners && this->X - 1 >= 0 && this->Y + 1 < height)		Cell::AddIfExists(list, this->CurrentGrid->cell(this->X - 1, this->Y + 1));	
	if(this->Y + 1 < height)											Cell::AddIfExists(list, this->CurrentGrid->cell(this->X, this->Y + 1));	
	if(includeCorners && this->X + 1 < width && this->Y + 1 < height)	Cell::AddIfExists(list, this->CurrentGrid->cell(this->X + 1, this->Y + 1));	
	if(this->X + 1 < width)												Cell::AddIfExists(list, this->CurrentGrid->cell(this->X + 1, this->Y));	
	if(includeCorners && this->X + 1 < width && this->Y - 1 >= 0)		Cell::AddIfExists(list, this->CurrentGrid->cell(this->X + 1, this->Y - 1));	
	if(this->Y - 1 >= 0)												Cell::AddIfExists(list, this->CurrentGrid->cell(this->X, this->Y - 1));	
	if(includeCorners && this->X - 1 >= 0 && this->Y - 1 >= 0)			Cell::AddIfExists(list, this->CurrentGrid->cell(this->X - 1, this->Y - 1));

	return list;
}

void Cell::AddIfExists(std::vector<Cell*>& cells, Cell* cell) {
	if(cell->Exists) {
		cells.push_back(cell);
	}
}

void Cell::FreezePosition() {
	cocos2d::Vec2 cellpos(this->X*ITEM_SPRITE_SIZE_X, this->Y*ITEM_SPRITE_SIZE_X);
	//this->_frozenPosition = this->CurrentGrid->CurrentLevel->CurrentLevelBuilder->CellContainer->convertToWorldSpace(cellpos);//base.get_transform().get_position();
	this->_frozenPosition = cellpos;
}

cocos2d::Vec2 Cell::GetFrozenPosition() {
	return this->_frozenPosition;
}

Direction Cell::GetDirectionTo(Cell* cell) {
	if(cell == nullptr) 
		return Direction::None;
	
	int __x = this->X - cell->X;
	int __y = this->Y - cell->Y;

	if(__x == 0 && __y == 0) return Direction::None;	
	if(__x == 0) return (__y <= 0) ? Direction::Down : Direction::Up;	
	if(__y == 0) return (__x <= 0) ? Direction::Left : Direction::Right;	
	if(__x > 0) return (__y <= 0) ? Direction::RightDown : Direction::RightUp;	
	return (__y <= 0) ? Direction::LeftDown : Direction::LeftUp;
}