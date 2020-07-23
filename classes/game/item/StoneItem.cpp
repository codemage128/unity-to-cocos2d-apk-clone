#include "StoneItem.h"
#include "StoneItemOder.h"
#include "../Cell.h"
#include "../Grid.h"
#include "../Extension.h"
#include "../Mathf.h"
#include "../Match.h"
#include "../Score.h"
#include "../ImageLibrary.h"
#include "../Level.h"

int StoneItem::_globalStoneId = 0;
std::vector<int> StoneItem::topSprites = { 11, 18 };
std::vector<int> StoneItem::bottomSprites = { 3, 3, 3, 2, 1 };
std::vector<int> StoneItem::sideSprites = { 8, 9, 10 };
std::vector<int> StoneItem::side70Sprites = { 15, 16, 17 };
std::vector<int> StoneItem::stateSprites = { 29, 30, 31, 32 };

void StoneItem::UpdateSprites() {
	Grid* currentGrid = this->get_CurrentCell()->CurrentGrid;
	bool stoneItem = this->GetStoneItem(currentGrid->GetCellWithDirection(this->get_CurrentCell(), Direction::Up));
	bool stoneItem2 = this->GetStoneItem(currentGrid->GetCellWithDirection(this->get_CurrentCell(), Direction::Down));
	bool stoneItem3 = this->GetStoneItem(currentGrid->GetCellWithDirection(this->get_CurrentCell(), Direction::Left));
	bool stoneItem4 = this->GetStoneItem(currentGrid->GetCellWithDirection(this->get_CurrentCell(), Direction::Right));
	this->SetSprite(this->Tiles[0], stoneItem3, stoneItem, Direction::LeftUp, false, false);
	this->SetSprite(this->Tiles[1], stoneItem4, stoneItem, Direction::RightUp, true, false);
	this->SetSprite(this->Tiles[2], stoneItem4, stoneItem2, Direction::RightDown, true, true);
	this->SetSprite(this->Tiles[3], stoneItem3, stoneItem2, Direction::LeftDown, false, true);
	this->SetEffect();
}

void StoneItem::SetSprite(cocos2d::Sprite* spriteRenderer, bool x, bool y, Direction checkDirection, bool right, bool down) {
//	if (this->_resources == nullptr) {
//		this->_resources = ItemResourcesManager.Instance.GetResources(this->GetItemType());
//	}
	cocos2d::Sprite* sprite;
	if (x && y) {
		bool stoneItem = this->GetStoneItem(this->get_CurrentCell()->CurrentGrid->GetCellWithDirection(this->get_CurrentCell(), checkDirection));
		if (stoneItem) {
//			sprite = ((!down) ? this->_resources.Sprites[14] : this->_resources.Sprites[7]);
		}
		else {
//			sprite = ((!down) ? this->_resources.Sprites[5] : this->_resources.Sprites[6]);
			spriteRenderer->setPosition(cocos2d::Vec2((!right) ? -0.5f : 0.5f, (!down) ? 0.4f : -0.6f));
			Direction direction = (!down) ? Direction::Up : ((!right) ? Direction::Left : Direction::Right);
			Cell* cellWithDirection = this->get_CurrentCell()->CurrentGrid->GetCellWithDirection(this->get_CurrentCell(), direction);
			if (cellWithDirection != nullptr && cellWithDirection->get_HasItem()) {
				StoneItem* component = nullptr;// cellWithDirection->get_CurrentItem()->GetComponent<StoneItem>();
				cocos2d::Sprite* spriteRenderer2 = (!right) ? component->Tiles[(!down) ? 3 : 2] : component->Tiles[(!down) ? 2 : 3];
				if (spriteRenderer2->isVisible()) {
					spriteRenderer2->setVisible(false);
				}
			}
			if (down) {
				this->_cornerSortingOffsets[(!right) ? 3 : 2] = -80;
			}
			else {
				this->_cornerSortingOffsets[(!right) ? 0 : 1] = 1;
			}
		}
	}
	else if (x)	{
		sprite = ((!down) ? this->SelectSprite(StoneItem::topSprites) : this->SelectSprite(StoneItem::bottomSprites));
	}
	else if (y)	{
		sprite = ((!down) ? this->SelectSprite(StoneItem::side70Sprites) : this->SelectSprite(StoneItem::sideSprites));
	}
	else if (down) {
//		sprite = this->_resources.Sprites[4];
	}
	else if (right) {
//		sprite = this->_resources.Sprites[13];
		right = false;
	}
	else {
//		sprite = this->_resources.Sprites[12];
	}
//	spriteRenderer.set_sprite(sprite);
	spriteRenderer->setFlipX(right);
}

cocos2d::Sprite* StoneItem::SelectSprite(std::vector<int> spriteIndexes) {
	ListExt_Shuffle<int>(spriteIndexes);
	return nullptr;// this->_resources.Sprites[spriteIndexes[0]];
}

void StoneItem::SetEffect() {
	int num = 19 + Mathf::Random::Range(0, 5) * 2;
	cocos2d::Sprite* spriteRenderer = this->Effects[0];
	cocos2d::Sprite* spriteRenderer2 = this->Effects[1];
//	spriteRenderer.set_sprite(this->_resources.Sprites[num]);
//	spriteRenderer2.set_sprite(this->_resources.Sprites[num + 1]);
	spriteRenderer->setVisible(spriteRenderer/*->getSpriteFrame()*/ != nullptr && Mathf::Random::Range(0, 10) >= 6);
	spriteRenderer2->setVisible(spriteRenderer2/*->getSpriteFrame()*/ != nullptr && Mathf::Random::Range(0, 10) >= 6);
	if (Mathf::Random::Range(0, 10) >= 5) {
		this->EffectsContainer->setScaleX(-1.0f);
		this->EffectsContainer->setScaleY(1.0f);
		this->EffectsContainer->setScaleZ(1.0f);
	}
}

bool StoneItem::GetStoneItem(Cell* cell) {
	return cell != nullptr && cell->Exists && cell->get_HasItem() && dynamic_cast<StoneItem*>(cell->get_CurrentItem()) != nullptr &&
		dynamic_cast<StoneItem*>(cell->get_CurrentItem())->StoneId == this->StoneId;
}

void StoneItem::LinkNeighbours(Cell* cell) {
	if (!cell->Exists || !cell->get_HasItem()) {
		return;
	}
//	if (this->_resources == nullptr) {
//		this->_resources = ItemResourcesManager.Instance.GetResources(this->GetItemType());
//	}
	StoneItem* stoneItem = dynamic_cast<StoneItem*>(cell->get_CurrentItem());
	if (stoneItem == nullptr || stoneItem->MasterItem != nullptr || stoneItem->IsMasterItem) {
		stoneItem = nullptr;//(cell.CurrentItem.GetSubItem() as StoneItem);
		if (stoneItem == nullptr || stoneItem->MasterItem != nullptr || stoneItem->IsMasterItem) {
			return;
		}
	}
	if (stoneItem == this) {
		this->IsMasterItem = true;
		this->StoneId = StoneItem::_globalStoneId;
		StoneItem::_globalStoneId++;
//		if (this->_children == nullptr) {
			this->_children = std::vector<StoneItem*>();
//		}
	}
	else {
		stoneItem->StoneId = this->StoneId;
	}
	stoneItem->MasterItem = this;
	this->_children.push_back(stoneItem);
	Grid* currentGrid = cell->CurrentGrid;
	Cell* cellWithDirection = currentGrid->GetCellWithDirection(cell, Direction::Left);
	if (cellWithDirection != nullptr) {
		this->LinkNeighbours(cellWithDirection);
	}
	Cell* cellWithDirection2 = currentGrid->GetCellWithDirection(cell, Direction::Right);
	if (cellWithDirection2 != nullptr) {
		this->LinkNeighbours(cellWithDirection2);
	}
	Cell* cellWithDirection3 = currentGrid->GetCellWithDirection(cell, Direction::Up);
	if (cellWithDirection3 != nullptr) {
		this->LinkNeighbours(cellWithDirection3);
	}
	Cell* cellWithDirection4 = currentGrid->GetCellWithDirection(cell, Direction::Down);
	if (cellWithDirection4 != nullptr) {
		this->LinkNeighbours(cellWithDirection4);
	}
	stoneItem->UpdateSprites();
}

void StoneItem::PlayOnExplodeStartedAnimation() {
	this->PlayItemParticle(4);
}

bool StoneItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame())	{
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	bool flag = this->TransformToNextLayer();
	if (flag) {
		return false;
	}
	this->PrepareExplosionOrder(this->get_CurrentCell(), 0);
	this->MasterItem->NotifyItemCollected();
	if (this->ToBeExplodedBy == ExplodeReason::Anvil || this->ToBeExplodedBy == ExplodeReason::BoxingGlove || this->ToBeExplodedBy == ExplodeReason::Hammer) {
		ScoreManager::RaiseScore(this->GetScore(), this->CurrentSpriteRenderer->getPosition(), MatchType::None);
		this->ToBeExplodedBy = ExplodeReason::None;
	}
	return false;
}

void StoneItem::PrepareExplosionOrder(Cell* cell, int order) {
	if (!cell->Exists || !cell->get_HasItem()) {
		return;
	}
	StoneItem* stoneItem = dynamic_cast<StoneItem*>(cell->get_CurrentItem());
	if (stoneItem == nullptr)	{
		return;
	}
	if (stoneItem->ExplosionOrder <= order)	{
		return;
	}
	stoneItem->ExplosionOrder = order;
	int order2 = order + 1;
	Grid* currentGrid = cell->CurrentGrid;
	Cell* cellWithDirection = currentGrid->GetCellWithDirection(cell, Direction::Left);
	if (cellWithDirection != nullptr) {
		this->PrepareExplosionOrder(cellWithDirection, order2);
	}
	Cell* cellWithDirection2 = currentGrid->GetCellWithDirection(cell, Direction::Right);
	if (cellWithDirection2 != nullptr) {
		this->PrepareExplosionOrder(cellWithDirection2, order2);
	}
	Cell* cellWithDirection3 = currentGrid->GetCellWithDirection(cell, Direction::Up);
	if (cellWithDirection3 != nullptr) {
		this->PrepareExplosionOrder(cellWithDirection3, order2);
	}
	Cell* cellWithDirection4 = currentGrid->GetCellWithDirection(cell, Direction::Down);
	if (cellWithDirection4 != nullptr) {
		this->PrepareExplosionOrder(cellWithDirection4, order2);
	}
}

bool StoneItem::TransformToNextLayer() {
	this->_layer--;
	if (this->_layer > 0) {
//		ImageLibrary::CopySprite(this->CurrentSpriteRenderer, this->_resources.Sprites[StoneItem::stateSprites[this->_layer - 1]]);// this->CurrentSpriteRenderer->set_sprite(this->_resources.Sprites[StoneItem.stateSprites[this->_layer - 1]]);
//		this->CurrentSpriteRenderer.get_transform().set_localEulerAngles(Vector3.get_zero());
		switch (this->_layer) {
		case 1:
//			AudioManager.PlayAudioProps(this->_resources.AudioClips[1], PlayMode.Frame, nullptr, 1f);
			this->PlayItemParticle(3);
//			this->AnimationParticle.Play();
//			this->CurrentAnimator.Play(this->_animationStage2To1Hash);
			break;
		case 2:
//			AudioManager.PlayAudioProps(this->_resources.AudioClips[1], PlayMode.Frame, nullptr, 1f);
			this->PlayItemParticle(2);
			break;
		case 3:
//			AudioManager.PlayAudioProps(this->_resources.AudioClips[1], PlayMode.Frame, nullptr, 1f);
			this->PlayItemParticle(1);
			break;
		case 4:
//			AudioManager.PlayAudioProps(this->_resources.AudioClips[0], PlayMode.Frame, nullptr, 1f);
			this->PlayItemParticle(0);
//			this->CurrentSpriteRenderer.get_transform().set_localEulerAngles(Vector3.get_forward() * Mathf::Random::Range(-70f, 71f));
			break;
		}
		return true;
	}
	this->CurrentSpriteRenderer->setVisible(false);
	return false;
}

void StoneItem::PlayItemParticle(int particleIndex) {
//	if (ParticlePool.Instance != nullptr) {
//		ParticlePool.Instance.PlayParticle(this->_resources.Particles[particleIndex], base.get_transform().get_position(), true);
//	}
}

void StoneItem::NotifyItemCollected() {
/*	this->_children.Sort(delegate(StoneItem* a, StoneItem* b) {
		if (a->ExplosionOrder == b->ExplosionOrder) {
			return 0;
		}
		return (a.ExplosionOrder <= b.ExplosionOrder) ? -1 : 1;
	});*/
	std::vector<StoneItemOder*> list;
	for (int i = 0; i < this->_children.size(); i++) {
		StoneItemOder* stoneitemoder = new StoneItemOder();
		stoneitemoder->Item = this->_children[i];
		stoneitemoder->Order = this->_children[i]->ExplosionOrder;
		list.push_back(stoneitemoder);
	}
	this->StartExplosionChain(list);//new Task(this->StartExplosionChain(list));
}

/*IEnumerator*/void StoneItem::StartExplosionChain(std::vector<StoneItemOder*> children) {
//	StoneItem.<StartExplosionChain>c__Iterator0 <StartExplosionChain>c__Iterator = new StoneItem.<StartExplosionChain>c__Iterator0();
//	<StartExplosionChain>c__Iterator.children = children;
//	return <StartExplosionChain>c__Iterator;
}

void StoneItem::StartExplode() {
	if (this->_isExploded) {
		return;
	}
	this->_isExploded = true;
//	AudioManager.PlayAudioProps(this->_resources.AudioClips[2], PlayMode.Frame, nullptr, 1f);
	this->CurrentLevel->DecreaseGoal(ItemType::Stone, false);
	ScoreManager::RaiseScore(this->GetScore(), this->CurrentSpriteRenderer->getPosition(), MatchType::None);
	SpriteBasedItem::StartExplode();
}

void StoneItem::RemoveSelf() {
	this->Remove();// SpriteBasedItem::StartCoroutine(this->Remove());
}

/*IEnumerator*/void StoneItem::Remove() {
//	StoneItem.<Remove>c__Iterator1 <Remove>c__Iterator = new StoneItem.<Remove>c__Iterator1();
//	<Remove>c__Iterator.$this = this;
//	return <Remove>c__Iterator;
}
