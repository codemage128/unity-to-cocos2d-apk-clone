#include "SodaItem.h"
#include "SodaFakeItem.h"
#include "SodaBottle.h"
#include "../Grid.h"
#include "../Cell.h"
#include "../Extension.h"
#include "../Mathf.h"
#include "../Level.h"
#include "../Score.h"
#include "../ParticleLibrary.h"
#include "../ImageLibrary.h"
#include "../LevelBuilder.h"
#include "../../ScnLevelPlay.h"


SodaItem::SodaItem() {
	SodaBottlePositions5 = std::map<MatchType, cocos2d::Vec2> {{MatchType::Blue,cocos2d::Vec2(0.293f, -0.147f)},{MatchType::Green,cocos2d::Vec2(0.014f, -0.239f)},{MatchType::Red,cocos2d::Vec2(-0.583f, -0.057f)},{MatchType::Yellow,cocos2d::Vec2(-0.293f, -0.161f)},{MatchType::Purple,cocos2d::Vec2(0.595f, -0.052f)}};
	SodaBottlePositions4 = std::map<MatchType, cocos2d::Vec2> {{MatchType::Blue,cocos2d::Vec2(0.573f, -0.102f)},{MatchType::Green,cocos2d::Vec2(0.232f, -0.236f)},{MatchType::Red,cocos2d::Vec2(-0.546f, -0.099f)},{MatchType::Yellow,cocos2d::Vec2(-0.213f, -0.226f)}};
	
	TopLeft = new SodaFakeItem(); TopLeft->MasterItem = this;
	TopRight = new SodaFakeItem(); TopRight->MasterItem = this;
	BottomRight = new SodaFakeItem(); BottomRight->MasterItem = this;
	
	BackSpriteRenderer = cocos2d::Sprite::create();
	BackSpriteRenderer->retain();

	ImageLibrary::CopySprite(BackSpriteRenderer, IMGLIB->SodaFrame);
	cocos2d::Rect newrect = BackSpriteRenderer->getTextureRect();
	newrect.origin.x -= 100.0f; newrect.size.width += 100.0f;
	newrect.origin.y += 0.0f; newrect.size.height += 97.0f;
	BackSpriteRenderer->setTextureRect(newrect);

	Start();
}

SodaItem::~SodaItem() {
	delete TopLeft;
	delete TopRight;
	delete BottomRight;

	BackSpriteRenderer->release();
}

Cell* SodaItem::get_CurrentCell() {
	return Item::get_CurrentCell();
}

void SodaItem::set_CurrentCell(Cell* value) {
	Item::set_CurrentCell(value);
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

void SodaItem::Start() {
	//	this->_animations = new int[]
	//	{
	//		Animator.StringToHash("Base Layer.SodaItemShakeAnimation1")
	//	};
	for(int i = 0; i < 5; i++)
		this->SodaBottles.push_back(new SodaBottle());

	this->SodaBottles[0]->SetupItem(BackSpriteRenderer, (int)MatchType::Blue); this->SodaBottles[0]->BottleSpriteRenderer->setLocalZOrder(4);
	this->SodaBottles[1]->SetupItem(BackSpriteRenderer, (int)MatchType::Green); this->SodaBottles[1]->BottleSpriteRenderer->setLocalZOrder(5);
	this->SodaBottles[2]->SetupItem(BackSpriteRenderer, (int)MatchType::Red); this->SodaBottles[2]->BottleSpriteRenderer->setLocalZOrder(1);
	this->SodaBottles[3]->SetupItem(BackSpriteRenderer, (int)MatchType::Yellow); this->SodaBottles[3]->BottleSpriteRenderer->setLocalZOrder(3);
	this->SodaBottles[4]->SetupItem(BackSpriteRenderer, (int)MatchType::Purple); this->SodaBottles[4]->BottleSpriteRenderer->setLocalZOrder(2);
}

void SodaItem::Init(int sodaCount) {
	this->_availableBottles = std::map < MatchType, SodaBottle* > {
		{MatchType::Blue, this->SodaBottles[0]},
		{MatchType::Green, this->SodaBottles[1]},
		{MatchType::Red, this->SodaBottles[2]},
		{MatchType::Yellow, this->SodaBottles[3]},
		{MatchType::Purple, this->SodaBottles[4]}
	};
	this->_sodaCount = sodaCount;
	std::map<MatchType, cocos2d::Vec2>* dictionary = &this->SodaBottlePositions5;
	if(this->_sodaCount == 4) {
		this->SodaBottles[4]->Remove();
		this->_availableBottles.erase(MatchType::Purple);
		dictionary = &this->SodaBottlePositions4;
	}
	for(std::pair<const MatchType, cocos2d::Vec2>& current : *dictionary) {
		this->_availableBottles[current.first]->BottleSpriteRenderer->setPosition(current.second*ITEM_SPRITE_SIZE_X + Vec2(200, 185));
	}
}

void SodaItem::InformToBeExplodedBySpecialItem(SpecialItem* specialItem, Direction comingFrom) {
	this->_shouldSkipExplode = false;
	if (specialItem == nullptr) {
		this->_explodeTime = this->_explodedByNonSpecialItem + 0.2f;
		this->_explodedByNonSpecialItem = Ext_getCurrentTime();
		this->_explodedBySpecialItem = true;
		return;
	}
	float num = 0.0f;
	if ((this->_explodedBySpecialItemTime.find(specialItem) != this->_explodedBySpecialItemTime.end()) && (Ext_getCurrentTime() < this->_explodedBySpecialItemTime[specialItem] + 1.0f)) {
		this->_shouldSkipExplode = true;
		return;
	}
	this->_explodedBySpecialItemTime[specialItem] = Ext_getCurrentTime();
	this->_explodedBySpecialItem = true;
}

bool SodaItem::CanExplodeDueToExplodeInNeigbour(MatchType sourceType) {
	if (this->_availableBottles.find(sourceType) == this->_availableBottles.end()) {
		return false;
	}
	this->_shouldSkipExplode = false;
	this->_explodedBySpecialItem = false;
	this->_removedType = sourceType;
	return true;
}

bool SodaItem::TryExplode() {
	return this->ExplodeBy(this);
}

bool SodaItem::ExplodeBy(Item* item) {
	if (this->LatestExplode == (long)Ext_getCurrentFrame() || Ext_getCurrentTime() < this->_explodeTime) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	if (this->_isExploded) {
		return false;
	}
	if (this->_shouldSkipExplode) {
		this->_shouldSkipExplode = false;
		return false;
	}
	if (this->_explodedBySpecialItem) {
		this->_explodedBySpecialItem = false;
		int idx = Mathf::Random::Range(0, this->_availableBottles.size());
		std::map<const MatchType, SodaBottle*>::iterator it = this->_availableBottles.begin();
		for (int i = 0; i < idx; i++) it++;
		this->_removedType = it->first;
	}
	this->CurrentLevel->DecreaseGoal(ItemType::Soda, false);

	ScnLevelPlay* toppanel = CurrentLevel->CurrentLevelBuilder->LevelScene;
	int goalidx = toppanel->getGoalIdx(ItemType::Soda);
	if(goalidx >= 0)
		toppanel->playGoalFx(goalidx);

	this->PlayExplodeAnimation(this->_removedType);
	if (item->ToBeExplodedBy == ExplodeReason::Anvil || item->ToBeExplodedBy == ExplodeReason::BoxingGlove || item->ToBeExplodedBy == ExplodeReason::Hammer) {
		ScoreManager::RaiseScore(item->GetScore(), this->BackSpriteRenderer->getPosition(), MatchType::None);
		item->ToBeExplodedBy = ExplodeReason::None;
	}
	if (this->_availableBottles.size() != 0)
		return false;
	
	this->_isExploded = true;
	return true;
}

void SodaItem::PlayExplodeAnimation(MatchType removed) {
	if (this->_isExploded) {
		return;
	}
	for (std::pair<const MatchType, SodaBottle*>& current : this->_availableBottles)//foreach (KeyValuePair<MatchType, SodaBottle> current in this->_availableBottles)
	{
		if (!(current.second == nullptr)) {
			if (current.first != removed) {
				current.second->PlayShakeAnimation();
			}
		}
	}
	cocos2d::Vec2 position = BackSpriteRenderer->getPosition();// Item::get_transform().get_position();
	if(this->_availableBottles.find(removed) != this->_availableBottles.end()) {
		position = this->_availableBottles[removed]->BottleSpriteRenderer->getPosition() + position - Vec2(BackSpriteRenderer->getTextureRect().size.width / 2, BackSpriteRenderer->getTextureRect().size.height / 2);
		//Object.Destroy(this->_availableBottles[removed].get_gameObject());
		this->_availableBottles[removed]->Remove();
		this->_availableBottles.erase(removed);
	}
//	int num = this->_animations[Mathf::Random::Range(0, this->_animations.size())];
//	this->CurrentAnimator.Play(num, 0, 0.0f);
//	AudioManager.Play(AudioTag.Soda1, PlayMode.Frame, nullptr, 1.0f);
//	if (ParticlePool.Instance == nullptr) {
//		return;
//	}
//	SodaBottleParticlePlayer component = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.SodaBottleParticleExplosion, position, true).GetComponent<SodaBottleParticlePlayer>();
//	component.SetColor(removed);

	const int SHAKEANIMTAG = 0x6931;
	if(this->BackSpriteRenderer->getActionByTag(SHAKEANIMTAG) == nullptr) {
		Vec2 orgpos = this->BackSpriteRenderer->getPosition();
		Action* shakeanim = Sequence::create(
			MoveTo::create(0.08f, orgpos + Vec2(0, 10)),
			MoveTo::create(0.08f, orgpos),
			MoveTo::create(0.08f, orgpos + Vec2(0, 10)),
			MoveTo::create(0.08f, orgpos),
			nullptr);
		shakeanim->setTag(SHAKEANIMTAG);
		this->BackSpriteRenderer->runAction(shakeanim);
	}

	PTCLLIB->explodeSodaBottle(removed, position);
}


void SodaItem::PlayExplodeAudio() {
//	AudioManager.Play(AudioTag.ItemCanClear, PlayMode.Frame, nullptr, 1f);
}

void SodaItem::StartCollect() {
	this->PlayExplodeAudio();
	this->PlayOnExplodeStartedAnimation();
	this->RemoveSelf();
}

void SodaItem::PlayOnExplodeStartedAnimation() {
//	if (ParticlePool.Instance != nullptr) {
//		ParticlePool.Instance.PlayParticle(ParticlePool.Instance.SodaItemExplodeParticle, this->ExplodePosition.get_position(), true);
//	}
	PTCLLIB->explodeCrate(BackSpriteRenderer->getPosition() + Vec2(50, 50));
}

void SodaItem::RemoveSelf() {
	Item::RemoveSelf();
	this->BottomRight->RemoveSelf();
	this->TopLeft->RemoveSelf();
	this->TopRight->RemoveSelf();

	this->BackSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
	set_CurrentCell(nullptr);
}
