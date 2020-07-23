#include "BillboardItem.h"
#include "../Cell.h"
#include "../Extension.h"
#include "../Level.h"
#include "../Score.h"
#include "../Grid.h"
#include "../Score.h"
#include "../LevelBuilder.h"
#include "../ImageLibrary.h"
#include "../ParticleLibrary.h"
#include "../../ScnLevelPlay.h"
#include "../ComFollow.h"

USING_NS_CC;

int BillboardItem::GlobalBillboardId = 0;


void BillboardItem::SetupItem() {
	Vec2 offset(0, -11);
	/*lu*/this->BillboardSpriteRenderers.push_back(Sprite::create()); this->BillboardSpriteRenderers[0]->setAnchorPoint(Vec2(1, 0));
	/*ru*/this->BillboardSpriteRenderers.push_back(Sprite::create()); this->BillboardSpriteRenderers[1]->setAnchorPoint(Vec2(0, 0));
	/*rd*/this->BillboardSpriteRenderers.push_back(Sprite::create()); this->BillboardSpriteRenderers[2]->setAnchorPoint(Vec2(0, 1));
	/*ld*/this->BillboardSpriteRenderers.push_back(Sprite::create()); this->BillboardSpriteRenderers[3]->setAnchorPoint(Vec2(1, 1));

	for(int i = 0; i < 4; i++) {
		this->CurrentSpriteRenderer->addChild(this->BillboardSpriteRenderers[i]);
		this->BillboardSpriteRenderers[i]->setPosition(offset);
	}

	this->PlugSpriteRenderer = Sprite::create();
	IMGLIB->CopySprite(this->PlugSpriteRenderer, IMGLIB->BillboardOff);
	this->CurrentSpriteRenderer->getParent()->addChild(this->PlugSpriteRenderer,this->CurrentSpriteRenderer->getLocalZOrder() + 12);
	ComFollow* follow = ComFollow::create();
	follow->setTarget(this->CurrentSpriteRenderer,offset);
	this->PlugSpriteRenderer->addComponent(follow);

	this->GlowSpriteRenderer = Sprite::create();
	IMGLIB->CopySprite(this->GlowSpriteRenderer, IMGLIB->BillboardOn);
	this->CurrentSpriteRenderer->getParent()->addChild(this->GlowSpriteRenderer,this->CurrentSpriteRenderer->getLocalZOrder() + 13);
	ComFollow* follow2 = ComFollow::create();
	follow2->setTarget(this->CurrentSpriteRenderer,offset);
	this->GlowSpriteRenderer->addComponent(follow2);

	//ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->CrateLayerSprites[LayerCount - 1]);
	//cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	//newrect.origin.y -= 15.0f; newrect.size.height += 15.0f;
	//CurrentSpriteRenderer->setTextureRect(newrect);
}

void BillboardItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	this->GlowSpriteRenderer->removeFromParentAndCleanup(true);
	this->PlugSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void BillboardItem::PlayExplodeAudio() {
//	AudioManager.Play(AudioTag.ItemDiamond2, PlayMode.Frame, nullptr, 1f);
}

void BillboardItem::PlayOnExplodeStartedAnimation() {
	PTCLLIB->explodeBillboard(this->CurrentSpriteRenderer->getPosition());
//	if (ParticlePool.Instance != nullptr) {
//		ParticlePool.Instance.PlayParticle(ParticlePool.Instance.BillboardExplodeParticle, base.get_transform().get_position(), true);
//	}
}

bool BillboardItem::TryExplode() {
	this->_scoreCount++;
	if (this->_scoreCount > 1) {
		this->_canGenerateScore = false;
	}
	if (this->LatestExplode == (long)Ext_getCurrentFrame())	{
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	if (this->_isCollected) {
		return false;
	}
	this->_isCollected = true;
	this->CurrentLevel->DecreaseGoal(ItemType::Billboard, false);

	ScnLevelPlay* toppanel = CurrentLevel->CurrentLevelBuilder->LevelScene;
	int goalidx = toppanel->getGoalIdx(ItemType::Billboard);
	if(goalidx >= 0)
		toppanel->playGoalFx(goalidx);

	//this->CurrentSpriteRenderer->setVisible(false);
	this->GlowSpriteRenderer->setVisible(false);

	PTCLLIB->explodeLightBulb(this->CurrentSpriteRenderer->getPosition());
//	if (ParticlePool.Instance != nullptr) {
//		ParticlePool.Instance.PlayParticle(ParticlePool.Instance.BillboardCollectParticle, base.get_transform().get_position(), true);
//	}
//	AudioManager.Play(AudioTag.ItemBillboardBreak, PlayMode.Frame, nullptr, 1f);
	if (this->MasterItem != nullptr) {
		this->MasterItem->NotifyItemCollected();
	}
	else {
		this->NotifyItemCollected();
	}
	if (this->ToBeExplodedBy == ExplodeReason::Anvil || this->ToBeExplodedBy == ExplodeReason::BoxingGlove || this->ToBeExplodedBy == ExplodeReason::Hammer) {
		ScoreManager::RaiseScore(this->GetScore(), CurrentSpriteRenderer->getPosition(), MatchType::None);
		this->ToBeExplodedBy = ExplodeReason::None;
	}
	return false;
}

void BillboardItem::NotifyItemCollected() {
	this->_collectCount--;
	if (this->_collectCount != 0) {
		return;
	}
	if (/*this->_children != nullptr && */this->_children.size() > 0) {
		int count = this->_children.size();
		for (int i = 0; i < count; i++) {
			this->_children[i]->StartExplode();
		}
		this->_children.clear();//this->_children = nullptr;
	}
	this->StartExplode();
//	AudioManager.Play(AudioTag.ItemBillboardExplode, PlayMode.Frame, nullptr, 1f);
}

void BillboardItem::UpdateView() {
	Grid* grid = this->get_CurrentCell()->CurrentGrid;
	bool up = this->GetBillboardItem(grid->GetCellWithDirection(this->get_CurrentCell(), Direction::Up));
	bool down = this->GetBillboardItem(grid->GetCellWithDirection(this->get_CurrentCell(), Direction::Down));
	bool left = this->GetBillboardItem(grid->GetCellWithDirection(this->get_CurrentCell(), Direction::Left));
	bool right = this->GetBillboardItem(grid->GetCellWithDirection(this->get_CurrentCell(), Direction::Right));
	this->SetSprite(this->BillboardSpriteRenderers[0], left, up, Direction::LeftUp, false, false);
	this->SetSprite(this->BillboardSpriteRenderers[1], right, up, Direction::RightUp, true, false);
	this->SetSprite(this->BillboardSpriteRenderers[2], right, down, Direction::RightDown, true, true);
	this->SetSprite(this->BillboardSpriteRenderers[3], left, down, Direction::LeftDown, false, true);
}

void BillboardItem::SetSprite(cocos2d::Sprite* spriteRenderer, bool x, bool y, Direction checkDirection, bool right, bool down) {
	cocos2d::Sprite* sprite = nullptr;
	if(x && y) {
		bool checkitem = this->GetBillboardItem(this->get_CurrentCell()->CurrentGrid->GetCellWithDirection(this->get_CurrentCell(), checkDirection));
		if(checkitem) {
			sprite = ((!down) ? IMGLIB->BillboardBorders[6]/*Billboard_D_Up*/ : IMGLIB->BillboardBorders[7] /*Billboard_D_Down*/);
		}
		else {
			sprite = ((!down) ? IMGLIB->BillboardBorders[4]/*Billboard_C_Up*/ : IMGLIB->BillboardBorders[5] /*Billboard_C_Down*/);
			//spriteRenderer.get_transform().set_localPosition(new Vector3((!right) ? -0.5f : 0.5f, (!down) ? 0.4f : -0.6f, 0f));
			//spriteRenderer->setPosition((!right) ? -25 : 25, (!down) ? 20 : -30);
			//this->CurrentSpriteRenderer.get_transform().set_localPosition((!down) ? new Vector3(0f, -0.03f, 0f) : new Vector3(0f, -0.15f, 0f));
			//CurrentSpriteRenderer->setPosition(0, (!down) ? -0.03f * 50 : -0.15f * 50);
			//this->PlugSpriteRenderer.get_transform().set_localPosition((!down) ? new Vector3(0f, -0.052f, 0f) : new Vector3(0f, -0.1f, 0f));
			//PlugSpriteRenderer->setPosition(0, (!down) ? -0.052f * 50 : -0.1f * 50);
			Direction direction = (!down) ? Direction::Up : ((!right) ? Direction::Left : Direction::Right);
			Cell* cellWithDirection = this->get_CurrentCell()->CurrentGrid->GetCellWithDirection(this->get_CurrentCell(), direction);
			if(cellWithDirection != nullptr && cellWithDirection->get_HasItem()) {
				BillboardItem* component = dynamic_cast<BillboardItem*>(cellWithDirection->get_CurrentItem());// ->GetComponent<BillboardItem>();
				cocos2d::Sprite* nextBillboard = (!right) ? component->BillboardSpriteRenderers[(!down) ? 3 : 2] : component->BillboardSpriteRenderers[(!down) ? 2 : 3];
				if(nextBillboard->isVisible()) {
					nextBillboard->setVisible(false);
				}
			}
			//if(down)
			//	this->_cornerSortingOffsets[(!right) ? 3 : 2] = -80;
			//else
			//	this->_cornerSortingOffsets[(!right) ? 0 : 1] = 1;
		}
	}
	else if(x) {
		sprite = ((!down) ? IMGLIB->BillboardBorders[2] /*Billboard_B_Up */ : IMGLIB->BillboardBorders[3] /*Billboard_B_Down*/);
	}
	else if(y) {
		sprite = ((!down) ? IMGLIB->BillboardBorders[8] /*Billboard_E_Up */ : IMGLIB->BillboardBorders[9] /*Billboard_E_Down*/);
	}
	else {
		sprite = ((!down) ? IMGLIB->BillboardBorders[0] /*Billboard_A_Up */ : IMGLIB->BillboardBorders[1] /*Billboard_A_Down*/);
	}
	ImageLibrary::CopySprite(spriteRenderer, sprite);
	spriteRenderer->setFlippedX(right);
}

bool BillboardItem::GetBillboardItem(Cell* cell) {
	return cell != nullptr && cell->Exists && cell->get_HasItem() && dynamic_cast<BillboardItem*>(cell->get_CurrentItem()) != nullptr
		&& dynamic_cast<BillboardItem*>(cell->get_CurrentItem())->BillboardId == this->BillboardId;
}

void BillboardItem::LinkNeighbours(Cell* cell) {
	if(!cell->Exists || !cell->get_HasItem()) {
		return;
	}
	BillboardItem* billboardItem = dynamic_cast<BillboardItem*>(cell->get_CurrentItem());
	if(billboardItem == nullptr || billboardItem->MasterItem != nullptr || billboardItem->IsMasterItem) {
		return;
	}
	if(billboardItem == this) {
		this->IsMasterItem = true;
		this->_collectCount = 1;
		this->BillboardId = BillboardItem::GlobalBillboardId;
		BillboardItem::GlobalBillboardId++;
		_children.clear();
		//if (this->_children == nullptr)	{
		//	this->_children = new List<BillboardItem>();
		//}
	}
	else {
		this->_collectCount++;
		billboardItem->MasterItem = this;
		billboardItem->BillboardId = this->BillboardId;
		this->_children.push_back(billboardItem);
	}
	Grid* currentGrid = cell->CurrentGrid;
	Cell* cellWithDirection = currentGrid->GetCellWithDirection(cell, Direction::Left);
	if(cellWithDirection != nullptr) {
		this->LinkNeighbours(cellWithDirection);
	}
	Cell* cellWithDirection2 = currentGrid->GetCellWithDirection(cell, Direction::Right);
	if(cellWithDirection2 != nullptr) {
		this->LinkNeighbours(cellWithDirection2);
	}
	Cell* cellWithDirection3 = currentGrid->GetCellWithDirection(cell, Direction::Up);
	if(cellWithDirection3 != nullptr) {
		this->LinkNeighbours(cellWithDirection3);
	}
	Cell* cellWithDirection4 = currentGrid->GetCellWithDirection(cell, Direction::Down);
	if(cellWithDirection4 != nullptr) {
		this->LinkNeighbours(cellWithDirection4);
	}
	billboardItem->UpdateView();
}

