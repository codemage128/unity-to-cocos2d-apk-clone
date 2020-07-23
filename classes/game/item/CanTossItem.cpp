#include "CanBox.h"
#include "CanTossItem.h"
#include "CanTossFakeItem.h"
#include "../Animation.h"
#include "../Score.h"
#include "../Level.h"
#include "../Grid.h"
#include "../Cell.h"
#include "../ParticleLibrary.h"
#include "../ImageLibrary.h"
#include "../LevelBuilder.h"
#include "../../ScnLevelPlay.h"

#include "global/SoundManager.h"
#include "global/GameManager.h"

USING_NS_CC;


CanTossItem::CanTossItem() {
	TopLeft = new CanTossFakeItem(); TopLeft->MasterCanToss = this;
	TopRight = new CanTossFakeItem(); TopRight->MasterCanToss = this;
	BottomRight = new CanTossFakeItem(); BottomRight->MasterCanToss = this;
}

CanTossItem::~CanTossItem() {
	delete TopLeft; TopLeft = nullptr;
	delete TopRight; TopRight = nullptr;
	delete BottomRight; BottomRight = nullptr;
}

void CanTossItem::SetupItem() {
	ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->CanToss);
	cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	newrect.origin.x -= 100.0f; newrect.size.width += 100.0f;
	newrect.origin.y += 0.0f; newrect.size.height += 95.0f;
	CurrentSpriteRenderer->setTextureRect(newrect);

	for(int i = 0; i < _canCount; i++) {
		Cans.push_back(new CanBox());
		Cans[i]->SetupItem(this->CurrentSpriteRenderer, Vec2(100,92), i);
	}

	this->ExplodePosition.set(50, 50);

	this->Awake();
}


void CanTossItem::set_CurrentCell(Cell* value) {
	Item::set_CurrentCell(value);
	if (this->get_CurrentCell() != nullptr) {
		this->TopLeft->set_CurrentCell( this->get_CurrentCell()->CurrentGrid->cell(this->get_CurrentCell()->X, this->get_CurrentCell()->Y + 1));
		this->TopRight->set_CurrentCell( this->get_CurrentCell()->CurrentGrid->cell(this->get_CurrentCell()->X + 1, this->get_CurrentCell()->Y + 1));
		this->BottomRight->set_CurrentCell(this->get_CurrentCell()->CurrentGrid->cell(this->get_CurrentCell()->X + 1, this->get_CurrentCell()->Y));
	}
	else
	{
		this->TopLeft->set_CurrentCell(nullptr);
		this->TopRight->set_CurrentCell(nullptr);
		this->BottomRight->set_CurrentCell(nullptr);
	}
}


void CanTossItem::StartCollect() {
	this->PlayExplodeAudio();
	this->PlayOnExplodeStartedAnimation();
	this->RemoveSelf();
}

void CanTossItem::PlayExplodeAudio() {
	//SoundManager::playEffectSound(SFX::S12);//AudioManager.Play(SFX.ItemCanClear, PlayMode.Frame, null, 1f);
}

void CanTossItem::RemoveSelf() {
	Item::RemoveSelf();
	BottomRight->RemoveSelf();
	TopLeft->RemoveSelf();
	TopRight->RemoveSelf();

	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
	set_CurrentCell(nullptr);
}


//////// non override
void CanTossItem::Awake() {
	//this->_canTossAnimationId = Animator->StringToHash("Base Layer.CanTossAnimation");
	for (int i = 0; i < (int)Cans.size(); i++) {
		Cans[i]->Id = i;
	}
}

bool CanTossItem::ExplodeBy(Item* item) {
	if(this->_isExploded)
		return false;
	if(!this->CurrentLevel->CanBeCollected(ItemType::CanToss))
		return false;
	this->_canCount--;
	if(this->_canCount < 0)
		return false;

	CanBox* canBox = Cans[8 - this->_canCount];
	PTCLLIB->explodeCanBox(this->CurrentSpriteRenderer->getPosition() - Vec2(this->CurrentSpriteRenderer->getTextureRect().size.width / 2, this->CurrentSpriteRenderer->getTextureRect().size.height / 2) + canBox->CurrentSpriteRenderer->getPosition());
	canBox->Remove();
	//AudioManager.Play(this->ChoseSFX(), PlayMode.Frame, null, 1f);
	//if (ParticlePool.Instance != null)
	//{
	//ParticlePlayer particlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.CanExplosion, canBox.get_transform().get_position(), true);
	//Quaternion identity = Quaternion.get_identity();
	//identity.set_eulerAngles((Random.Range(0, 10) <= 5) ? new Vector3(-102.4f, 90f, 0f) : new Vector3(-76.5f, 90f, 0f));
	//particlePlayer.MainParticle.get_transform().set_rotation(identity);
	//}
	if(this->_canCount > 0)
		this->PlayShakeAnimation();
	else
		this->_isExploded = true;

	if(Item::ToBeExplodedBy == ExplodeReason::Anvil || Item::ToBeExplodedBy == ExplodeReason::BoxingGlove || Item::ToBeExplodedBy == ExplodeReason::Hammer) {
		ScoreManager::RaiseScore(Item::GetScore(), this->CurrentSpriteRenderer->getPosition(), MatchType::None);
		Item::ToBeExplodedBy = ExplodeReason::None;
	}
	this->CurrentLevel->DecreaseGoal(ItemType::CanToss, false);

	ScnLevelPlay* toppanel = CurrentLevel->CurrentLevelBuilder->LevelScene;
	int goalidx = toppanel->getGoalIdx(ItemType::CanToss);
	if(goalidx >= 0)
		toppanel->playGoalFx(goalidx);

	this->CurrentLevel->IncreaseBlockWin();
	//new Task(CanTossItem.WaitAndAllowWin(this->CurrentLevel), true, LifeTime.Scene);
	this->WaitAndAllowWin(this->CurrentLevel);

	return this->_isExploded;
}

void CanTossItem::CheckIfExtraExplodeNeeded() {
	if(this->_isExploded)
		return;

	if(this->BombExplodeCount == 1 && this->get_CurrentCell() != nullptr) {
		this->get_CurrentCell()->CurrentGrid->ExplodeCell(this->get_CurrentCell(), nullptr);
	}
	this->BombExplodeCount = 0;
}

/////Protected:////////////
void CanTossItem::PlayOnExplodeStartedAnimation() {
	PTCLLIB->explodeCanToss(this->CurrentSpriteRenderer->getPosition() + ExplodePosition);
	/*if (ParticlePool.Instance != null) {
		ParticlePool.Instance.PlayParticle(ParticlePool.Instance.CanTossExplosion, this->ExplodePosition.get_position(), true);
	}//*/
}

/////Private: ////////
void CanTossItem::PlayShakeAnimation() {
	//this->CanTossAnimation.Play(this->_canTossAnimationId, 0, 0f);
	const int SHAKEANIMTAG = 0x2965;
	if(this->CurrentSpriteRenderer->getActionByTag(SHAKEANIMTAG) == nullptr) {
		Vec2 orgpos = this->CurrentSpriteRenderer->getPosition();
		Action* shakeanim = Sequence::create(MoveTo::create(0.05f, orgpos + Vec2(0, 10)), MoveTo::create(0.05f, orgpos), nullptr);
		shakeanim->setTag(SHAKEANIMTAG);
		this->CurrentSpriteRenderer->runAction(shakeanim);
	}
	for(int i = 0; i <= 8; i++) {
		CanBox* canBox = Cans[i];
		canBox->PlayShakeAnimation(this->_canCount);
	}
}

void CanTossItem::WaitAndAllowWin(Level* level) {
//case 0:
//	this.$current = new WaitForSeconds(0.5f);
//	if(!this.$disposing) {
//		this.$PC = 1;
//	}
//	return true;
//
//case 1:
//	this.level.DecreaseBlockWin();
//	this.$PC = -1;
//	break;
	this->CurrentSpriteRenderer->runAction(Sequence::create(DelayTime::create(0.5f), CallFunc::create([level]() {level->DecreaseBlockWin(); }), nullptr));
}