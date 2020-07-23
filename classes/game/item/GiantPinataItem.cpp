#include "GiantPinataItem.h"
#include "GiantPinataFakeItem.h"
#include "../Grid.h"
#include "../Cell.h"
#include "../Animation.h"
#include "../ItemFeature.h"
#include "../Extension.h"
#include "../ImageLibrary.h"
#include "../ParticleLibrary.h"
#include "../Level.h"
#include "../FallManager.h"

GiantPinataItem::GiantPinataItem() {
	TopLeft = new GiantPinataFakeItem(); TopLeft->MasterPinataItem = this;
	TopRight = new GiantPinataFakeItem(); TopRight->MasterPinataItem = this;
	BottomRight = new GiantPinataFakeItem(); BottomRight->MasterPinataItem = this;

	BaseImage = cocos2d::Sprite::create(); BaseImage->retain();
	//RopeMesh = cocos2d::Sprite::create(); BaseImage->addChild(RopeMesh);
	//DonkeyMesh = cocos2d::Sprite::create(); RopeMesh->addChild(DonkeyMesh);
}

GiantPinataItem::~GiantPinataItem() {
	BaseImage->release();
	delete TopLeft;
	delete TopRight;
	delete BottomRight;
}

void GiantPinataItem::SetupItem() {
	//ImageLibrary::CopySprite(BaseImage, IMGLIB->GiantPinataPanel);
	//cocos2d::Rect newrect = BaseImage->getTextureRect();
	//newrect.origin.x -= 100.0f; newrect.size.width += 100.0f;
	//newrect.origin.y += 0.0f; newrect.size.height += 280.0f;
	//BaseImage->setTextureRect(newrect);
	//
	//ImageLibrary::CopySprite(RopeMesh, IMGLIB->GiantPinataRope);
	//RopeMesh->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_TOP);
	//RopeMesh->setPosition(200, 280);
	//ImageLibrary::CopySprite(DonkeyMesh, IMGLIB->GiantPinata[0]);
	//DonkeyMesh->setPosition(3, 32);
	_giantNode = ParticleLibrary::cloneNodeForParticleModel(PTCLLIB->getGiantPinataNode(0));
	_giantNode->setPosition(50, 30);
	_giantAnim = PTCLLIB->getGiantPinataAnim(0)->clone();
	_giantNode->runAction(_giantAnim);
	_giantAnim->play("idle", false);
	_giantNode->enumerateChildren("//[[:alnum:]]+", [this](cocos2d::Node* _node)->bool {
		cocos2d::ParticleSystemQuad* p = dynamic_cast<cocos2d::ParticleSystemQuad*>(_node);
		if(p != nullptr) p->stopSystem();
		return false;
	});
	BaseImage->addChild(_giantNode);
}

void GiantPinataItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->BaseImage->removeFromParentAndCleanup(true);
	//delete this;
	set_CurrentCell(nullptr);
}

Cell* GiantPinataItem::get_CurrentCell(){
	return Item::get_CurrentCell();
}

void GiantPinataItem::set_CurrentCell(Cell* newCell) {
	Item::set_CurrentCell(newCell);
	if(this->get_CurrentCell() != nullptr) {
		this->TopLeft->set_CurrentCell(this->get_CurrentCell()->CurrentGrid->cell(this->get_CurrentCell()->X, this->get_CurrentCell()->Y + 1));
		this->TopRight->set_CurrentCell(this->get_CurrentCell()->CurrentGrid->cell(this->get_CurrentCell()->X + 1, this->get_CurrentCell()->Y + 1));
		this->BottomRight->set_CurrentCell(this->get_CurrentCell()->CurrentGrid->cell(this->get_CurrentCell()->X + 1, this->get_CurrentCell()->Y));
	}
	else {
		this->TopLeft->set_CurrentCell(nullptr);
		this->TopRight->set_CurrentCell(nullptr);
		this->BottomRight->set_CurrentCell(nullptr);
	}
}


void GiantPinataItem::OnFallEnded() {
	Item::OnFallEnded();
	Cell* currentCell = this->BottomRight->get_CurrentCell();
	if (currentCell != nullptr) {
		CanCastShadowComponent::CastShadowIfPossible(currentCell);
	}
}

void GiantPinataItem::InformToBeExplodedBySpecialItem(SpecialItem* specialItem, Direction comingFrom) {
	Item::InformToBeExplodedBySpecialItem(specialItem, comingFrom);
	this->_lastDirection = comingFrom;
	if (specialItem == nullptr) {
		this->justExploded = (Ext_getCurrentTime() < this->explodedByNonSpecialItem + 0.2f);
		this->explodedByNonSpecialItem = Ext_getCurrentTime();
		return;
	}
	//float num;
	if (this->_explodedBySpecialItemTime.find(specialItem) != this->_explodedBySpecialItemTime.end()) {
		this->justExploded = (Ext_getCurrentTime() < this->_explodedBySpecialItemTime[specialItem] + 1.0f);
	}
	else {
		this->justExploded = false;
	}
	this->_explodedBySpecialItemTime[specialItem] = Ext_getCurrentTime();
}

bool GiantPinataItem::TryExplode() {
	if (this->justExploded || this->LatestExplode == (long)Ext_getCurrentFrame()) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	if (this->_exploded) {
		return false;
	}
	this->_explodeNo++;
//	int num = this->GiantPinataAnimator.GetInteger("DIRECTION");
//	if (num == 0 || (this->GiantPinataAnimator.GetInteger("STATE") == 1 && this->_explodeNo == 2)) {
//		this->GiantPinataAnimator.SetInteger("STATE", this->_explodeNo);
//		switch (this->_lastDirection) {
//		case Direction::Up:
//			this->EnableAndPlay(this->ToDownParticle);
//			num = 3;
//			break;
//		case Direction::Down:
//			this->EnableAndPlay(this->ToUpParticle);
//			num = 1;
//			break;
//		case Direction::Left:
//			this->EnableAndPlay(this->ToRightParticle);
//			num = 2;
//			break;
//		default:
//			this->EnableAndPlay(this->ToLeftParticle);
//			num = 4;
//			break;
//		}
//		this->GiantPinataAnimator.SetInteger("DIRECTION", num);
//	}
	_giantAnim->play("explode", false);
	_giantNode->enumerateChildren("//[[:alnum:]]+", [this](cocos2d::Node* _node)->bool {
		cocos2d::ParticleSystemQuad* p = dynamic_cast<cocos2d::ParticleSystemQuad*>(_node);
		if(p != nullptr) p->resetSystem();
		return false;
	});

	if (this->_explodeNo < 3) {
//		AudioManager.Play(AudioTag.ItemGiantPinata_1_2, PlayMode.Frame, nullptr, 1f);
	}
//	Item::StartCoroutine(this->ChangeImage());
	if(this->_explodeNo<3)
		this->ChangeImage();

	if (this->_explodeNo != 3) {
		return false;
	}
	this->_exploded = true;

//	this->FinalParticle.get_gameObject().SetActive(true);
//	this->FinalParticle.PlayWithoutParent();
	return true;
}

//void GiantPinataItem::EnableAndPlay(ParticleSystem target) {
//	this->UpdateParticle(target, this->ToUpParticle);
//	this->UpdateParticle(target, this->ToDownParticle);
//	this->UpdateParticle(target, this->ToLeftParticle);
//	this->UpdateParticle(target, this->ToRightParticle);
//}

//void GiantPinataItem::UpdateParticle(Component target, ParticleSystem target2) {
//	GameObject gameObject = target2.get_gameObject();
//	if (target == target2) {
//		gameObject.SetActive(true);
//		target2.Play();
//	}
//	else if (gameObject.get_activeSelf()) {
//		gameObject.SetActive(false);
//	}
//}

CollectAnimation GiantPinataItem::GetCollectItem() {
//	CollectAnimation* component = this->CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(this->DonkeyImagePosition.get_position()).GetComponent<CollectAnimation>();
//	component->Prepare(this->CurrentLevel, this->GetItemType(), zorder, nullptr, this->get_CurrentCell());

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
//	return component;
	return CollectAnimation::Instant;
}

void GiantPinataItem::PlayExplodeAudio() {
//	AudioManager.Play(AudioTag.ItemGiantPinata_3, PlayMode.Frame, nullptr, 1f);
}

/*IEnumerator*/void GiantPinataItem::ChangeImage() {
//case 0:
//	this.$current = new WaitForSeconds(0.1f);
//	if(!this.$disposing) {
//		this.$PC = 1;
//	}
//	return true;
//
//case 1:
//	this.<n>__0 = this.$this._explodeNo;
//	if(this.<n>__0 > 2) {
//		this.<n>__0 = 2;
//	}
//	this.$this.DonkeyImage.sprite = ImageLibrary.Instance.GiantPinata[this.<n>__0];
//	this.$PC = -1;
//	break;
	BaseImage->runAction(cocos2d::Sequence::create(
		cocos2d::DelayTime::create(45 / 30.0f),
		cocos2d::CallFunc::create([this]() {
		_giantNode->removeFromParent();

		_giantNode = ParticleLibrary::cloneNodeForParticleModel(PTCLLIB->getGiantPinataNode(this->_explodeNo));
		_giantNode->setPosition(50, 30);
		_giantAnim = PTCLLIB->getGiantPinataAnim(this->_explodeNo)->clone();
		_giantNode->runAction(_giantAnim);
		_giantAnim->play("idle", false);
		_giantNode->enumerateChildren("//[[:alnum:]]+", [this](cocos2d::Node* _node)->bool {
			cocos2d::ParticleSystemQuad* p = dynamic_cast<cocos2d::ParticleSystemQuad*>(_node);
			if(p != nullptr) p->stopSystem();
			return false;
		});
		BaseImage->addChild(_giantNode);
		}),
		nullptr));
}

void GiantPinataItem::StartExplode() {
	if (this->_inExplode)
		return;

	this->_inExplode = true;
	Item::StartExplode();
}

