#include "ColoredCrateItem.h"
#include "../Animation.h"
#include "../Match.h"
#include "../ImageLibrary.h"
#include "../ParticleLibrary.h"
#include "../Level.h"
#include "../FallManager.h"
#include "global/SoundManager.h"


ColoredCrateItem::ColoredCrateItem() {
}

ColoredCrateItem::~ColoredCrateItem() {
}

CollectAnimation ColoredCrateItem::GetCollectItem() {
	//CollectAnimation* component = this->CurrentLevel->CurrentLevelBuilder->GenericCollectItem->Spawn(this->CurrentSpriteRenderer->getPosition())->GetComponent<CollectAnimation*>();
	//cormponent->Prepare(this->CurrentLevel, this->GetItemType(), zorder(), this->_imageGroup->at(0), this->get_CurrentCell());

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
	//return component;
	return CollectAnimation::Instant;
}

void ColoredCrateItem::SetupItem(TiledEditorId tiledEditorId) {
	switch(tiledEditorId) {
	case TiledEditorId::ColorCrateBlue0:
	case TiledEditorId::ColorCrateGreen0:
	case TiledEditorId::ColorCratePurple0:
	case TiledEditorId::ColorCrateOrange0:
	case TiledEditorId::ColorCrateYellow0:
	case TiledEditorId::ColorCrateRed0:
		this->LayerCount = 1;
		break;
	case TiledEditorId::ColorCrateBlue1:
	case TiledEditorId::ColorCrateGreen1:
	case TiledEditorId::ColorCratePurple1:
	case TiledEditorId::ColorCrateOrange1:
	case TiledEditorId::ColorCrateYellow1:
	case TiledEditorId::ColorCrateRed1:
		this->LayerCount = 2;
		break;
	case TiledEditorId::ColorCrateBlue2:
	case TiledEditorId::ColorCrateGreen2:
	case TiledEditorId::ColorCratePurple2:
	case TiledEditorId::ColorCrateOrange2:
	case TiledEditorId::ColorCrateYellow2:
	case TiledEditorId::ColorCrateRed2:
		this->LayerCount = 3;
		break;
	}

	switch(tiledEditorId) {
	case TiledEditorId::ColorCrateYellow0:
	case TiledEditorId::ColorCrateYellow1:
	case TiledEditorId::ColorCrateYellow2:
		this->_matchType = MatchType::Yellow;
		this->_imageGroup = &IMGLIB->YellowCrateLayerSprites;
		break;
	case TiledEditorId::ColorCrateRed0:
	case TiledEditorId::ColorCrateRed1:
	case TiledEditorId::ColorCrateRed2:
		this->_matchType = MatchType::Red;
		this->_imageGroup = &IMGLIB->RedCrateLayerSprites;
		break;
	case TiledEditorId::ColorCrateBlue0:
	case TiledEditorId::ColorCrateBlue1:
	case TiledEditorId::ColorCrateBlue2:
		this->_matchType = MatchType::Blue;
		this->_imageGroup = &IMGLIB->BlueCrateLayerSprites;
		break;
	case TiledEditorId::ColorCrateGreen0:
	case TiledEditorId::ColorCrateGreen1:
	case TiledEditorId::ColorCrateGreen2:
		this->_matchType = MatchType::Green;
		this->_imageGroup = &IMGLIB->GreenCrateLayerSprites;
		break;
	case TiledEditorId::ColorCratePurple0:
	case TiledEditorId::ColorCratePurple1:
	case TiledEditorId::ColorCratePurple2:
		this->_matchType = MatchType::Purple;
		this->_imageGroup = &IMGLIB->PurpleCrateLayerSprites;
		break;
	case TiledEditorId::ColorCrateOrange0:
	case TiledEditorId::ColorCrateOrange1:
	case TiledEditorId::ColorCrateOrange2:
		this->_matchType = MatchType::Orange;
		this->_imageGroup = &IMGLIB->OrangeCrateLayerSprites;
		break;
	default:
		this->_matchType = MatchType::Blue;
		this->_imageGroup = &IMGLIB->BlueCrateLayerSprites;
		break;
	}
	ImageLibrary::CopySprite(this->CurrentSpriteRenderer, this->_imageGroup->at(this->LayerCount - 1));
}

void ColoredCrateItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void ColoredCrateItem::PlayOnExplodeStartedAnimation() {
	PTCLLIB->explodeColoredCrate(this->_matchType, this->CurrentSpriteRenderer->getPosition());/*
	if (ParticlePool.Instance == null)
		return;
	ColoredCrateExplodeParticlePlayer coloredCrateExplodeParticlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.ColoredCrateExploded, base.get_transform().get_position(), false) as ColoredCrateExplodeParticlePlayer;
	coloredCrateExplodeParticlePlayer.SetColor(this->_matchType);
	coloredCrateExplodeParticlePlayer.Play();//*/
}
void ColoredCrateItem::StartTranformationToNewLayer() {
	int layerCount = this->LayerCount;
	if (layerCount != 3) {
		if (layerCount == 2 || layerCount == 1)	{
			PTCLLIB->explodeColoredCrateLayer(_matchType, this->CurrentSpriteRenderer->getPosition());/*
			ColoredCrateLayerRemovedParticlePlayer coloredCrateLayerRemovedParticlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.ColoredCrateLayer2Or3Exploded, base.get_transform().get_position(), false) as ColoredCrateLayerRemovedParticlePlayer;
			coloredCrateLayerRemovedParticlePlayer.SetColor(this->_matchType);
			coloredCrateLayerRemovedParticlePlayer.Play();//*/
		}
	}
	int num = this->LayerCount - 1;
	if (num < (int)this->_imageGroup->size())
		ImageLibrary::CopySprite(this->CurrentSpriteRenderer, this->_imageGroup->at(num));
}
