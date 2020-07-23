#include "WallItem.h"
#include "CollectorItemsController.h"
#include "../ImageLibrary.h"
#include "../Cell.h"
#include "../Grid.h"
#include "../Level.h"
#include "../Mathf.h"
#include "../Extension.h"

int WallItem::ExplodeAnimationHash = 0; // Animator.StringToHash("WallItemExplode");

void WallItem::set_InnerItem(Item* value) {
	this->_innerItem = value;
	if (this->_innerItem == nullptr) {
		return;
	}
//	this->_innerItem->get_gameObject().SetActive(false);
}

void WallItem::Prepare(ItemProperties properties) {
	this->_capacity = properties.capacity;
	this->_dynamiteOffset = properties.offset;
	this->_dynamiteScale = properties.scale;
//	this->_resources = ItemResourcesManager.Instance.GetResources(this->GetItemType());
	this->Group = properties.wallGroup;
	this->Order = properties.order;
	this->matchType = properties.matchType;
/*	this->CurrentBitmapNumberDisplay.Sprites = new Sprite[]
	{
		this->_resources.Sprites[20],
		this->_resources.Sprites[21],
		this->_resources.Sprites[22],
		this->_resources.Sprites[23],
		this->_resources.Sprites[24],
		this->_resources.Sprites[25],
		this->_resources.Sprites[26],
		this->_resources.Sprites[27],
		this->_resources.Sprites[28],
		this->_resources.Sprites[29]
	};*/
	this->UpdateCollectTargetCount();
	this->UpdateCollectTargetColor();
}

void WallItem::UpdateCollectTargetColor() {
	std::vector<cocos2d::Sprite*> sprites; // = this->_resources.Sprites;
	switch (this->matchType) {
	case MatchType::Yellow:
		ImageLibrary::CopySprite(this->DynamiteRibbonSpriteRenderer, sprites[8]); //this->DynamiteRibbonSpriteRenderer.set_sprite(sprites[8]);
		ImageLibrary::CopySprite(this->DynamiteDialSpriteRenderer, sprites[14]); //this->DynamiteDialSpriteRenderer.set_sprite(sprites[14]);
		break;
	case MatchType::Red:
		ImageLibrary::CopySprite(this->DynamiteRibbonSpriteRenderer, sprites[9]); //this->DynamiteRibbonSpriteRenderer.set_sprite(sprites[9]);
		ImageLibrary::CopySprite(this->DynamiteDialSpriteRenderer, sprites[15]); //this->DynamiteDialSpriteRenderer.set_sprite(sprites[15]);
		break;
	case MatchType::Blue:
		ImageLibrary::CopySprite(this->DynamiteRibbonSpriteRenderer, sprites[10]); //this->DynamiteRibbonSpriteRenderer.set_sprite(sprites[10]);
		ImageLibrary::CopySprite(this->DynamiteDialSpriteRenderer, sprites[16]); //this->DynamiteDialSpriteRenderer.set_sprite(sprites[16]);
		break;
	case MatchType::Green:
		ImageLibrary::CopySprite(this->DynamiteRibbonSpriteRenderer, sprites[11]); //this->DynamiteRibbonSpriteRenderer.set_sprite(sprites[11]);
		ImageLibrary::CopySprite(this->DynamiteDialSpriteRenderer, sprites[17]); //this->DynamiteDialSpriteRenderer.set_sprite(sprites[17]);
		break;
	case MatchType::Purple:
		ImageLibrary::CopySprite(this->DynamiteRibbonSpriteRenderer, sprites[12]); //this->DynamiteRibbonSpriteRenderer.set_sprite(sprites[12]);
		ImageLibrary::CopySprite(this->DynamiteDialSpriteRenderer, sprites[18]); //this->DynamiteDialSpriteRenderer.set_sprite(sprites[18]);
		break;
	case MatchType::Orange:
		ImageLibrary::CopySprite(this->DynamiteRibbonSpriteRenderer, sprites[13]); //this->DynamiteRibbonSpriteRenderer.set_sprite(sprites[13]);
		ImageLibrary::CopySprite(this->DynamiteDialSpriteRenderer, sprites[19]); //this->DynamiteDialSpriteRenderer.set_sprite(sprites[19]);
		break;
	}
}

void WallItem::LinkNeighbours(Cell* cell) {
	if (!cell->Exists) {
		return;
	}
//	cell->HideBubble();
	if (!cell->get_HasItem()) {
		return;
	}
	WallItem* wallItem = dynamic_cast<WallItem*>(cell->get_CurrentItem());
	if (wallItem == nullptr || wallItem->MasterItem != nullptr || wallItem->IsMasterItem) {
		return;
	}
	if (wallItem->Group != this->Group) {
		return;
	}
	if (wallItem == this) {
		this->IsMasterItem = true;
//		if (this->_children == nullptr)	{
			this->_children = std::vector<WallItem*>();
//		}
		this->CollectorId = CollectorItemsController::get_Instance()->GetWalls().Register(this);
//		this->CollectTarget.get_gameObject().SetActive(true);
	}
	else {
		wallItem->MasterItem = this;
		wallItem->CollectorId = this->CollectorId;
		this->_children.push_back(wallItem);
	}
	cocos2d::Vec2 position = cocos2d::Vec2();//wallItem->get_transform().get_position();
	if (position.x < this->_leftBottom.x) {
		this->_leftBottom.x = position.x;
	}
	if (position.x > this->_rightTop.x) {
		this->_rightTop.x = position.x;
	}
	if (position.y < this->_leftBottom.y) {
		this->_leftBottom.y = position.y;
	}
	if (position.y > this->_rightTop.y) {
		this->_rightTop.y = position.y;
	}
	if (cell->Y > this->_upperSortingOrder) {
		this->_upperSortingOrder = cell->Y;
	}
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
	wallItem->UpdateSprites();
	if (this->IsMasterItem) {
		this->CollectTarget->setScale(this->_dynamiteScale);
		this->CollectTarget->setPosition(cocos2d::Vec2((this->_leftBottom.x + this->_rightTop.x) / 2.0f + this->_dynamiteOffset.x,
			(this->_leftBottom.y + this->_rightTop.y) / 2.0f + this->_dynamiteOffset.y));
		cocos2d::Vec2 localPosition = this->CollectTarget->getPosition();
		localPosition.x += -0.02f;
		localPosition.y += -0.123f;
		this->CollectTarget->setPosition(localPosition);
	}
}

void WallItem::UpdateSprites() {
	std::vector<cocos2d::Sprite*> sprites;// = ItemResourcesManager.Instance.GetResources(this->GetItemType()).Sprites;
	Grid* currentGrid = this->get_CurrentCell()->CurrentGrid;
	int i = 0;
/*	int num = this->WallEffects.Length;
	while (i < num)
	{
		WallEffect wallEffect = this->WallEffects[i];
		if (wallEffect != nullptr)
		{
			wallEffect.Init();
		}
		i++;
	}*/
	bool wallItem = this->GetWallItem(currentGrid->GetCellWithDirection(this->get_CurrentCell(), Direction::Down));
	bool wallItem2 = this->GetWallItem(currentGrid->GetCellWithDirection(this->get_CurrentCell(), Direction::Left));
	bool wallItem3 = this->GetWallItem(currentGrid->GetCellWithDirection(this->get_CurrentCell(), Direction::Right));
	int num2;
	if (!wallItem2)	{
		num2 = 0;
	}
	else if (!wallItem3) {
		num2 = 2;
	}
	else {
		num2 = 1;
	}
	ImageLibrary::CopySprite(this->WallSpriteRenderer, sprites[num2]);//this->WallSpriteRenderer.set_sprite(sprites[num2]);
	ImageLibrary::CopySprite(this->JointSpriteRenderer, ImageLibrary::getInstance()->NullImage);//this->JointSpriteRenderer.set_sprite(nullptr);
	ImageLibrary::CopySprite(this->JointCornerSpriteRenderer, ImageLibrary::getInstance()->NullImage);//this->JointCornerSpriteRenderer.set_sprite(nullptr);
	if (wallItem) {
		if (!wallItem2) {
			ImageLibrary::CopySprite(this->JointSpriteRenderer, sprites[3]);//this->JointSpriteRenderer.set_sprite(sprites[3]);
		}
		else if (!wallItem3) {
			ImageLibrary::CopySprite(this->JointSpriteRenderer, sprites[5]);//this->JointSpriteRenderer.set_sprite(sprites[5]);
		}
		else {
			bool wallItem4 = this->GetWallItem(currentGrid->GetCellWithDirection(this->get_CurrentCell(), Direction::LeftDown));
			bool wallItem5 = this->GetWallItem(currentGrid->GetCellWithDirection(this->get_CurrentCell(), Direction::RightDown));
			if (!wallItem4) {
				ImageLibrary::CopySprite(this->JointCornerSpriteRenderer, sprites[6]);//this->JointCornerSpriteRenderer.set_sprite(sprites[6]);
			}
			else if (!wallItem5) {
				ImageLibrary::CopySprite(this->JointCornerSpriteRenderer, sprites[7]);//this->JointCornerSpriteRenderer.set_sprite(sprites[7]);
			}
			else {
				ImageLibrary::CopySprite(this->JointCornerSpriteRenderer, sprites[4]);//this->JointCornerSpriteRenderer.set_sprite(sprites[4]);
			}
		}
	}
//	this->JointCornerSpriteRenderer->setVisible(this->JointCornerSpriteRenderer.get_sprite() != nullptr);
//	this->JointSpriteRenderer->setVisible(this->JointSpriteRenderer.get_sprite() != nullptr);
	if (Mathf::Random::Range(0, 10) < 5) {
//		this->WallEffects[num2]->ShowOverlays(6);
	}
}

bool WallItem::GetWallItem(Cell* cell) {
	return cell != nullptr && cell->Exists && cell->get_HasItem() && dynamic_cast<WallItem*>(cell->get_CurrentItem()) != nullptr &&
		dynamic_cast<WallItem*>(cell->get_CurrentItem())->Group == this->Group;
}

Item* WallItem::ExtractSubItem()
{
	if (this->_innerItem == nullptr) {
		return this->get_InnerItem();
	}
//	this->_innerItem->get_gameObject().SetActive(true);
	this->get_InnerItem()->MasterItemExplode = Ext_getCurrentFrame();
	return this->get_InnerItem();
}

void WallItem::PlayExplodeAudio() {
//	AudioManager.PlayAudioProps(this->_resources.AudioClips[2], PlayMode.Frame, nullptr, 1f);
}

void WallItem::PlayOnExplodeStartedAnimation() {
//	if (ParticlePool.Instance != nullptr && ItemResourcesManager.Instance != nullptr) {
//		ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this->GetItemType()).Particles[0], base.get_transform().get_position(), true);
//	}
}

void WallItem::UpdateCollectTargetCount() {
/*	int num = this->_capacity - this->_count;
	if (num < 0)
	{
		return;
	}
	if (num < 6 && !this->SparksSmall[0].get_activeSelf())
	{
		for (int i = 0; i < 3; i++)
		{
			this->SparksSmall[i].SetActive(true);
		}
	}
	if (num < 10 && !this->_didScoreScaled)
	{
		this->_didScoreScaled = true;
		this->CurrentBitmapNumberDisplay.get_transform().set_localScale(Vector3.get_one() * 0.8f);
		this->CurrentBitmapNumberDisplay.get_transform().set_localPosition(new Vector3(0.076f, 0.004f, 0f));
	}
	this->CurrentBitmapNumberDisplay.Show(num);*/
}

void WallItem::StartCollectingItem() {
	this->_waitingCount++;
	if (!this->_readyToLaunch && this->_waitingCount + this->_count >= this->_capacity) {
		this->_readyToLaunch = true;
//		TapListener.Instance.IncreaseBlockRequests();
	}
}

void WallItem::OnItemCollectCompleted() {
	this->_count++;
	this->_waitingCount--;
//	AudioManager.PlayAudioProps(this->_resources.AudioClips[0], PlayMode.Frame, nullptr, 1f);
//	this->HitParticle.Play();
	this->UpdateCollectTargetCount();
	if (this->_waitingCount == 0) {
//		this->CollectAnimator.SetBool("single_collect", true);
//		this->CollectAnimator.SetBool("collect", false);
		this->WaitCollectAnimation(); //base.StartCoroutine(this->WaitCollectAnimation());
	}
	else {
//		this->CollectAnimator.SetBool("collect", true);
	}
	if (this->_waitingCount == 0 && this->_capacity - this->_count <= 0) {
//		CollectorItemsController.Instance.GetWalls().UnRegister(this);
		this->ExplodeWall();//new Task(this->ExplodeWall(), true, LifeTime.Scene);
	}
}

/*IEnumerator*/void WallItem::WaitCollectAnimation()
{
//	WallItem.<WaitCollectAnimation>c__Iterator0 <WaitCollectAnimation>c__Iterator = new WallItem.<WaitCollectAnimation>c__Iterator0();
//	<WaitCollectAnimation>c__Iterator.$this = this;
//	return <WaitCollectAnimation>c__Iterator;
}

/*IEnumerator*/void WallItem::ExplodeWall()
{
//	WallItem.<ExplodeWall>c__Iterator1 <ExplodeWall>c__Iterator = new WallItem.<ExplodeWall>c__Iterator1();
//	<ExplodeWall>c__Iterator.$this = this;
//	return <ExplodeWall>c__Iterator;
}

