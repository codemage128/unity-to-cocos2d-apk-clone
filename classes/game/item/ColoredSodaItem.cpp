#include "ColoredSodaItem.h"
#include "ColoredSodaFakeItem.h"
#include "SodaBottle.h"
#include "../Grid.h"
#include "../Cell.h"
#include "../Extension.h"
#include "../Mathf.h"
#include "../Level.h"
#include "../Score.h"
#include "../ImageLibrary.h"
#include "../ParticleLibrary.h"

USING_NS_CC;


ColoredSodaItem::ColoredSodaItem() {
	TopLeft = new ColoredSodaFakeItem(); TopLeft->MasterItem = this;
	TopRight = new ColoredSodaFakeItem(); TopRight->MasterItem = this;
	BottomRight = new ColoredSodaFakeItem(); BottomRight->MasterItem = this;

	BackSpriteRenderer = cocos2d::Sprite::create();
	BackSpriteRenderer->retain();

	ImageLibrary::CopySprite(BackSpriteRenderer, IMGLIB->SodaFrame);
	cocos2d::Rect newrect = BackSpriteRenderer->getTextureRect();
	newrect.origin.x -= 100.0f; newrect.size.width += 100.0f;
	newrect.origin.y += 0.0f; newrect.size.height += 97.0f;
	BackSpriteRenderer->setTextureRect(newrect);
}

ColoredSodaItem::~ColoredSodaItem() {
	delete TopLeft;
	delete TopRight;
	delete BottomRight;

	BackSpriteRenderer->release();
}

Cell* ColoredSodaItem::get_CurrentCell() {
	return Item::get_CurrentCell();
}

void ColoredSodaItem::set_CurrentCell(Cell* value) {
	Item::set_CurrentCell(value);
	if (this->get_CurrentCell() != nullptr) {
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

void ColoredSodaItem::ChangeBottleColors(MatchType matchType) {
	int num = 0;
	int num2 = 360;
	float saturation = 1.0f;
	float valueBrightness = 1.0f;
	int num3 = 360;
	float saturation2 = 1.0f;
	float valueBrightness2 = 1.0f;
	switch (matchType) {
	case MatchType::Yellow:
		num = 0;
		num2 = 161;
		saturation = 1.0f;
		valueBrightness = 1.66f;
		num3 = 158;
		saturation2 = 2.0f;
		valueBrightness2 = 1.55f;
		break;
	case MatchType::Red:
		num = 1;
		num2 = 202;
		saturation = 1.42f;
		valueBrightness = 0.97f;
		num3 = 158;
		saturation2 = 2.0f;
		valueBrightness2 = 1.55f;
		break;
	case MatchType::Blue:
		num = 2;
		break;
	case MatchType::Green:
		num = 3;
		num2 = 82;
		saturation = 1.05f;
		valueBrightness = 1.25f;
		num3 = 79;
		saturation2 = 1.4f;
		valueBrightness2 = 1.0f;
		break;
	case MatchType::Purple:
		num = 4;
		num2 = 252;
		saturation = 1.09f;
		valueBrightness = 0.93f;
		num3 = 249;
		saturation2 = 1.45f;
		valueBrightness2 = 1.0f;
		break;
	}
	int num4 = this->SodaBottles.size();
//	for (int i = 0; i < num4; i++) {
//		this->SodaBottles[i]->BottleSpriteRenderer.set_sprite(IMGLIB->SodaItemBottles[num]);
//		if (this->SodaBottles[i]->CapColor != nullptr) {
//			this->SodaBottles[i]->CapColor.HueShift = (float)num2;
//			this->SodaBottles[i]->CapColor.Saturation = saturation;
//			this->SodaBottles[i]->CapColor.ValueBrightness = valueBrightness;
//			this->SodaBottles[i]->CapColor.CallUpdate();
//		}
//		if (this->SodaBottles[i]->TopColor != nullptr) {
//			this->SodaBottles[i]->TopColor.HueShift = (float)num3;
//			this->SodaBottles[i]->TopColor.Saturation = saturation2;
//			this->SodaBottles[i]->TopColor.ValueBrightness = valueBrightness2;
//			this->SodaBottles[i]->TopColor.CallUpdate();
//		}
//	}

}

//void ColoredSodaItem::Start()
//{
//	this->_animations = new int[]
//	{
//		Animator.StringToHash("Base Layer.SodaItemShakeAnimation1")
//	};
//	this->ChangeBottleColors(this->_matchType);
//}

void ColoredSodaItem::Init(MatchType matchType) {
	Vec2 SodaBottlePositions4[] = {cocos2d::Vec2(0.573f, -0.102f), cocos2d::Vec2(0.232f, -0.236f), cocos2d::Vec2(-0.546f, -0.099f), cocos2d::Vec2(-0.213f, -0.226f)};
	for(int i = 0; i < 4; i++) {
		SodaBottle* newbottle = new SodaBottle();
		newbottle->SetupItem(BackSpriteRenderer, (int)matchType);
		newbottle->BottleSpriteRenderer->setPosition(SodaBottlePositions4[i]*ITEM_SPRITE_SIZE_X + Vec2(200, 185));
		this->SodaBottles.push_back(newbottle);
	}

	this->_matchType = matchType;
	this->_availableBottles = std::vector < SodaBottle* > {
		this->SodaBottles[0],
			this->SodaBottles[1],
			this->SodaBottles[2],
			this->SodaBottles[3]
	};
}

void ColoredSodaItem::InformToBeExplodedBySpecialItem(SpecialItem* specialItem, Direction comingFrom) {
	this->_shouldSkipExplode = false;
	if (specialItem == nullptr) {
		this->_explodeTime = this->_explodedByNonSpecialItem + 0.2f;
		this->_explodedByNonSpecialItem = Ext_getCurrentTime();
		this->_explodedBySpecialItem = true;
		return;
	}
	float num = 0.0f;
	if ((this->_explodedBySpecialItemTime.find(specialItem) != this->_explodedBySpecialItemTime.end()) &&
		(Ext_getCurrentTime() < this->_explodedBySpecialItemTime[specialItem] + 1.0f)) {
		this->_shouldSkipExplode = true;
		return;
	}
	this->_explodedBySpecialItemTime[specialItem] = Ext_getCurrentTime();
	this->_explodedBySpecialItem = true;
}

bool ColoredSodaItem::CanExplodeDueToExplodeInNeigbour(MatchType sourceType) {
	if (this->_matchType != sourceType) {
		return false;
	}
	this->_shouldSkipExplode = false;
	this->_explodedBySpecialItem = false;
	return true;
}

bool ColoredSodaItem::TryExplode() {
	return this->ExplodeBy(this);
}

bool ColoredSodaItem::ExplodeBy(Item* item) {
	this->_canGenerateScoreThisTurn = false;
	if (this->LatestExplode == (long)Ext_getCurrentFrame || Ext_getCurrentTime() < this->_explodeTime) {
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
	}
	this->_canGenerateScoreThisTurn = true;
	this->CurrentLevel->DecreaseGoal(ItemType::Soda, false);
	this->PlayExplodeAnimation();
	if (item->ToBeExplodedBy == ExplodeReason::Anvil || item->ToBeExplodedBy == ExplodeReason::BoxingGlove ||
		item->ToBeExplodedBy == ExplodeReason::Hammer) {
		ScoreManager::RaiseScore(item->GetScore(), BackSpriteRenderer->getPosition(), MatchType::None);
		item->ToBeExplodedBy = ExplodeReason::None;
	}
	if (this->_availableBottles.size() != 0) {
		return false;
	}
	this->_isExploded = true;
	return true;
}

void ColoredSodaItem::PlayExplodeAnimation() {
	if (this->_isExploded) {
		return;
	}
	int index = this->_availableBottles.size() - 1;
	SodaBottle* sodaBottle = this->_availableBottles[index];
	this->_availableBottles.erase(this->_availableBottles.begin() + index);
	for (int i = 0; i < (int)this->_availableBottles.size(); i++) {
		this->_availableBottles[i]->PlayShakeAnimation();
	}
//	cocos2d::Vec3 position = sodaBottle->get_transform().get_position();
	cocos2d::Vec2 position = BackSpriteRenderer->getPosition();
	position = sodaBottle->BottleSpriteRenderer->getPosition() + position - Vec2(BackSpriteRenderer->getTextureRect().size.width / 2, BackSpriteRenderer->getTextureRect().size.height / 2);
//	Object.Destroy(sodaBottle.get_gameObject());
	sodaBottle->Remove();
//	int num = this->_animations[Mathf::Random::Range(0, this->_animations.size())];
//	this->CurrentAnimator.Play(num, 0, 0.0f);
//	AudioManager.Play(AudioTag.Soda1, PlayMode.Frame, nullptr, 1.0f);
//	if (ParticlePool.Instance == nullptr) {
//		return;
//	}
//	SodaBottleParticlePlayer component = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.SodaBottleParticleExplosion, position, true).GetComponent<SodaBottleParticlePlayer>();
//	component.SetColor(this->_matchType);
	
	const int SHAKEANIMTAG = 0x7138;
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

	PTCLLIB->explodeSodaBottle(this->_matchType, position);
}


void ColoredSodaItem::PlayExplodeAudio() {
//	AudioManager.Play(AudioTag.ItemCanClear, PlayMode.Frame, nullptr, 1f);
}

void ColoredSodaItem::StartCollect() {
	this->PlayExplodeAudio();
	this->PlayOnExplodeStartedAnimation();
	this->RemoveSelf();
}

void ColoredSodaItem::PlayOnExplodeStartedAnimation() {
//	if (ParticlePool.Instance != nullptr) {
//		ParticlePool.Instance.PlayParticle(ParticlePool.Instance.SodaItemExplodeParticle, this->ExplodePosition.get_position(), true);
//	}
	PTCLLIB->explodeCrate(BackSpriteRenderer->getPosition() + Vec2(50, 50));
}

void ColoredSodaItem::RemoveSelf() {
	Item::RemoveSelf();
	this->BottomRight->RemoveSelf();
	this->TopLeft->RemoveSelf();
	this->TopRight->RemoveSelf();
	
	this->BackSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
	set_CurrentCell(nullptr);
}
