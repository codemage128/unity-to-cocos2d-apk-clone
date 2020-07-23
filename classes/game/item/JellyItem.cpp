#include "JellyItem.h"
#include "JellyAnimatorWaiter.h"
#include "../Cell.h"
#include "../Level.h"
#include "../LevelBuilder.h"
#include "../Animation.h"
#include "../JellyManager.h"
#include "../ParticleLibrary.h"
#include "../ImageLibrary.h"

void JellyItem::SetupItem() {
	ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->Jelly);
}

void JellyItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void JellyItem::PlayExplodeAudio() {
//	AudioManager.Play(AudioTag.JellyBreak, PlayMode.Frame, nullptr, 1f);
}

void JellyItem::PlayJellySpread(Cell* cellSelected) {
	if (this->_creatingJelly || this->_destroyed || cellSelected == nullptr) {
		return;
	}
//	AudioManager.Play(AudioTag.JellySpread, PlayMode.Frame, nullptr, 1f);
	this->_jellyAnimatorWaiter = new JellyAnimatorWaiter();//this->CurrentLevel->CurrentLevelBuilder->JellyAnimatorPrefab.Spawn(this->JellyAnimationOwner.get_position()).GetComponent<JellyAnimatorWaiter>();
	this->_jellyAnimatorWaiter->MasterJelly = this;
	int num = 0;
//	cocos2d::Node* prefab = ParticlePool.Instance.JellyCreationSideParticle;
	if (cellSelected->Y == this->get_CurrentCell()->Y) {
		num = ((cellSelected->X >= this->get_CurrentCell()->X) ? 3 : 1);
		this->_jellyAnimatorWaiter->DisplaySortNo = this->CurrentSpriteRenderer->getLocalZOrder() + 5;
	}
	else if (cellSelected->X == this->get_CurrentCell()->X) {
		if (cellSelected->Y < this->get_CurrentCell()->Y) {
			num = 4;
//			prefab = ParticlePool.Instance.JellyCreationDownParticle;
			this->_jellyAnimatorWaiter->DisplaySortNo = this->CurrentSpriteRenderer->getLocalZOrder() - 1;
		}
		else {
			num = 2;
//			prefab = ParticlePool.Instance.JellyCreationUpParticle;
			this->_jellyAnimatorWaiter->DisplaySortNo = this->CurrentSpriteRenderer->getLocalZOrder() + 105;
		}
	}
	this->_jellyAnimatorWaiter->HideIt();
	if (num == 0) {
		this->_jellyAnimatorWaiter->MasterJelly = nullptr;
//		this->_jellyAnimatorWaiter->get_gameObject().Recycle();
		return;
	}
	this->_creatingJelly = true;
//	this->_jellyAnimatorWaiter->SpreadAnimator.SetInteger("DIRECTION", num);
	if (cellSelected->get_HasItem()) {
		Item* currentItem = cellSelected->get_CurrentItem();
		currentItem->set_CurrentCell(nullptr);
		this->_itemToBeDestoyedAtAnimationEnd =currentItem;//currentItem.get_gameObject();
	}
	this->_newJelly = dynamic_cast<JellyItem*>(this->CurrentLevel->CurrentLevelBuilder->CreateItem(new ItemDescription(ItemType::Jelly, TiledEditorId::Jelly, nullptr)));
//	this->_newJelly->get_transform().set_position(cellSelected->get_transform().get_position());
	LevelBuilder::ActiveLevel->CurrentLevelBuilder->setCellItemSpritePosition(cellSelected, this->_newJelly);
	this->_newJelly->set_CurrentCell(cellSelected);
//	this->_newJelly->RelativeContainer.SetActive(false);
	this->_newJelly->SpreadedBy = this;
//	ParticlePlayer particlePlayer = ParticlePool.Instance.PlayParticle(prefab, this->_newJelly->get_transform().get_position(), false);
//	particlePlayer.get_transform().set_localScale((num != 3) ? Vector3.get_one() : new Vector3(-1f, 1f, 1f));
//	particlePlayer.Play();

	this->_newJelly->CurrentSpriteRenderer->setScale(0);
	CurrentSpriteRenderer->runAction(cocos2d::Sequence::create(
		cocos2d::TargetedAction::create(this->_newJelly->CurrentSpriteRenderer,cocos2d::EaseBackOut::create(cocos2d::ScaleTo::create(0.5f,1.0f))),
		cocos2d::CallFunc::create([this]() {this->_jellyAnimatorWaiter->InformAnimationEnded(); }),
		nullptr));


	this->_jellyToBeEnabled = this->_newJelly;
}

void JellyItem::AnimationEnded() {
	if (this->_newJelly != nullptr) {
		this->_newJelly->SpreadedBy = nullptr;
		if (this->_newJelly->get_CurrentCell() != nullptr) {
//			this->_newJelly->get_transform().set_position(this->_newJelly->get_CurrentCell()->get_transform().get_position());
			this->_newJelly->CurrentSpriteRenderer->setPosition(this->_newJelly->get_CurrentCell()->GetFrozenPosition());
		}
	}
	if (this->_jellyAnimatorWaiter != nullptr) {
//		this->_jellyAnimatorWaiter->SpreadAnimator.SetInteger("DIRECTION", 5);
		this->_jellyAnimatorWaiter->MasterJelly = nullptr;
		this->_jellyAnimatorWaiter->HideIt();
//		this->_jellyAnimatorWaiter->get_gameObject().Recycle();
	}
	if (this->_itemToBeDestoyedAtAnimationEnd != nullptr) {
//		this->_itemToBeDestoyedAtAnimationEnd->GetComponent<Item>().RemoveSelf();
		this->_itemToBeDestoyedAtAnimationEnd->RemoveSelf();
	}
	if (this->_jellyToBeEnabled != nullptr) {
//		this->_jellyToBeEnabled->RelativeContainer.SetActive(true);
	}
	this->_jellyToBeEnabled = nullptr;
	this->_itemToBeDestoyedAtAnimationEnd = nullptr;
	this->_jellyAnimatorWaiter = nullptr;
	this->_creatingJelly = false;
}

void JellyItem::OnItemCreated(Level* currentLevel) {
	Item::OnItemCreated(currentLevel);
	this->CurrentLevel->JellyItemManager->Add(this);
}

void JellyItem::OnBeforeRemove() {
	if (this->SpreadedBy != nullptr) {
		this->SpreadedBy->AnimationEnded();
	}
	this->AnimationEnded();
	Item::OnBeforeRemove();
	this->CurrentLevel->JellyItemManager->Remove(this);
	this->_destroyed = true;
}

void JellyItem::AfterPoolInit() {
	Item::AfterPoolInit();
	this->_destroyed = false;
}

void JellyItem::ReactToUpperFall() {
	FallListener* fallListener = Item::GetFallListener();
	if(fallListener!=nullptr)
		fallListener->EndFall(-1.0f);
}

void JellyItem::PlayOnExplodeStartedAnimation() {
//	if (ParticlePool.Instance != nullptr)
//	{
//		ParticlePool.Instance.PlayParticle(ParticlePool.Instance.JellyExplodeParticle, Item::get_transform().get_position(), true);
//	}
	PTCLLIB->explodeJelly(CurrentSpriteRenderer->getPosition());
}

bool JellyItem::TryExplode() {
	bool flag = Item::TryExplode();
	if (flag) {
		this->CurrentLevel->JellyItemManager->InformJellyExplode();
	}
	return flag;
}
