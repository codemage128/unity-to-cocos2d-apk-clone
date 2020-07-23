#include "EasterEggItem.h"
#include "../Extension.h"
#include "../Match.h"
#include "../Level.h"
#include "../Animation.h"
#include "../ParticleLibrary.h"
#include "../ImageLibrary.h"
#include "../Level.h"
#include "../FallManager.h"
#include "../Group.h"

EasterEggItem::EasterEggItem() {

}

EasterEggItem::~EasterEggItem() {
}

void EasterEggItem::SetupItem() {
	ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->EasterEggSprites[0]);
	cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	newrect.origin.y -= 20.0f; newrect.size.height += 20.0f;
	CurrentSpriteRenderer->setTextureRect(newrect);
}

void EasterEggItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

bool EasterEggItem::CanExplodeDueToExplodeInNeigbour(MatchType sourceType) {
	if (this->EffectiveType != MatchType::None)
		return this->EffectiveType == sourceType;

	this->LatestExplode = Ext_getCurrentFrame(); //(long)Time.get_frameCount();
	this->EffectiveType = sourceType;
	this->PlayTransformationAnimation();
	return this->EffectiveType == sourceType;
}

void EasterEggItem::TransformationEnded() {
	this->CurrentSpriteRenderer->setColor(cocos2d::Color3B::WHITE);
	//this->BlurSpriteRenderer.get_gameObject().SetActive(false);
	//this->EggLinesRenderer.get_gameObject().SetActive(false);
	//this->EggLinesRenderer2.get_gameObject().SetActive(false);
}


bool EasterEggItem::TryExplode() {
	if (this->LatestExplode == Ext_getCurrentFrame()) //(long)Time.get_frameCount())
		return false;

	this->LatestExplode = Ext_getCurrentFrame(); //(long)Time.get_frameCount();
	if (this->EffectiveType != MatchType::None)
		return true;

	/*try*/	{
		ItemType randomItemType = this->CurrentLevel->CurrentItemGroups[GroupId::Group1]->GetRandomItemType();
		this->EffectiveType = ItemTypeAsMatchType(randomItemType);
	}
	/*catch {
		CCLOG("Can not find a match from Group!");//LogManager.Error(LogTags.EasterEgg, "Can not find a match from Group!", new object[0]);
		this->EffectiveType = MatchType::Blue;
	}//*/
	this->PlayTransformationAnimation();
	return false;
}

CollectAnimation EasterEggItem::GetCollectItem() {
	//CollectAnimation component = this->CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(base.get_transform().get_position()).GetComponent<CollectAnimation>();
	//component.Prepare(this->CurrentLevel, this->GetItemType(), this->zorder), this->CurrentSpriteRenderer.get_sprite(), this->CurrentCell);

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

	//component.get_transform().set_position(this->CurrentSpriteRenderer.get_transform().get_position());
	//return component;
	return CollectAnimation::Instant;
}

void EasterEggItem::PlayExplodeAudio() {
	//AudioManager.Play(AudioTag.EasterEggExplode, PlayMode.Frame, null, 1f);
}

//protected:
void EasterEggItem::PlayOnExplodeStartedAnimation() {
	PTCLLIB->explodeEasterEgg(this->EffectiveType, this->CurrentSpriteRenderer->getPosition()); /*
	if (ParticlePool.Instance == nullptr)
		return;

	ParticlePlayer particlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.EasterEggExplosion, base.get_transform().get_position(), true);
	EasterEggExplosionParticle component = particlePlayer.GetComponent<EasterEggExplosionParticle>();
	component.SetColor(this->EffectiveType);//*/
}

//private:

void EasterEggItem::PlayTransformationAnimation() {
	if (this->_transformationApplied)
		return;

	//AudioManager.Play(AudioTag.EasterEggTransform, PlayMode.Frame, null, 1f);
	this->_transformationApplied = true;

	Color color = Color::YELLOW;
	Color particle = Color::YELLOW;
	cocos2d::Sprite* sprite;
	switch (this->EffectiveType)
	{
	case MatchType::Yellow:
		sprite = IMGLIB->EasterEggSprites[1];
		color = this->YellowMain;
		particle = this->YellowParticle;
		break;
	case MatchType::Red:
		sprite = IMGLIB->EasterEggSprites[2];
		color = this->RedMain;
		particle = this->RedParticle;
		break;
	case MatchType::Blue:
		sprite = IMGLIB->EasterEggSprites[3];
		color = this->BlueMain;
		particle = this->BlueParticle;
		break;
	case MatchType::Green:
		sprite = IMGLIB->EasterEggSprites[4];
		color = this->GreenMain;
		particle = this->GreenParticle;
		break;
	case MatchType::Purple:
		sprite = IMGLIB->EasterEggSprites[5];
		color = this->PurpleMain;
		particle = this->PurpleParticle;
		break;
	case MatchType::Orange:
		sprite = IMGLIB->EasterEggSprites[6];
		color = this->OrangeMain;
		particle = this->OrangeParticle;
		break;
	default:
		sprite = IMGLIB->EasterEggSprites[0];
		break;
	}

	ImageLibrary::CopySprite(this->CurrentSpriteRenderer, sprite);
	cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	newrect.origin.y -= 20.0f; newrect.size.height += 20.0f;
	CurrentSpriteRenderer->setTextureRect(newrect);

	cocos2d::Vec2 position = this->CurrentSpriteRenderer->getPosition();
	position.y -= 10.0f;

	if(EffectiveType != MatchType::None) {
		PTCLLIB->showEggTransform(EffectiveType, position);

		CurrentSpriteRenderer->setVisible(false);
		CurrentSpriteRenderer->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(40.0f/120-0.03f), cocos2d::Show::create()));
	}
	/*
	ParticlePlayer particlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.EasterEggTransformExplosion, this, false);
	particlePlayer.get_gameObject().get_transform().set_position(position);
	particlePlayer.GetComponent<EasterEggTransformationParticle>().SetStartColors(particle, this->CurrentSpriteRenderer.zOrder() + 110);
	base.StartCoroutine(EasterEggItem.ExplodeParticle(particlePlayer, 0.15f)); //*/

	//this->TransformationAnimator.set_enabled(true);
	//this->CurrentSpriteRenderer->setColor(new Color(1.0f, 1.0f, 1.0f, 0.0f));
	//this->BlurSpriteRenderer.get_gameObject().SetActive(true);
	//this->EggLinesRenderer.get_gameObject().SetActive(true);
	//this->EggLinesRenderer2.get_gameObject().SetActive(true);
	//ShortcutExtensions43.DOColor(this->BlurSpriteRenderer, color, 0.27f);

}