#include "ColoredBalloonItem.h"
#include "../Match.h"
#include "../Animation.h"
#include "../ImageLibrary.h"
#include "../ParticleLibrary.h"
#include "../Level.h"
#include "../FallManager.h"
#include "global/SoundManager.h"


ColoredBalloonItem::ColoredBalloonItem() {
}

ColoredBalloonItem::~ColoredBalloonItem() {
}

void ColoredBalloonItem::Paint(MatchType mType) {
	switch (mType)
	{
	case MatchType::Yellow:		_type = ColoredBalloonType::Balloon1;		break;
	case MatchType::Red:		_type = ColoredBalloonType::Balloon2;		break;
	case MatchType::Blue:		_type = ColoredBalloonType::Balloon3;		break;
	case MatchType::Green:		_type = ColoredBalloonType::Balloon4;		break;
	case MatchType::Purple:		_type = ColoredBalloonType::Balloon5;		break;
	case MatchType::Orange:		_type = ColoredBalloonType::Balloon6;		break;
	default:
		if (mType != MatchType::None)
		{
		}
		break;
	}
	this->_currentMatchType = mType;
	//this->CurrentSpriteRenderer->set_sprite(ImageLibrary.Instance.ColoredBalloonSprites[this->_type - ColoredBalloonType::Balloon1]);
	ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->ColoredBalloonSprites[(int)this->_type - (int)ColoredBalloonType::Balloon1]);
	cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	newrect.origin.y -= 20.0f; newrect.size.height += 20.0f;
	CurrentSpriteRenderer->setTextureRect(newrect);
}

void ColoredBalloonItem::PlayExplodeAudio() {
	//SoundManager::playEffectSound(SFX::S12);//AudioManager.Play(AudioTag.ItemBalloon, PlayMode.Frame, null, 1f);
}

CollectAnimation ColoredBalloonItem::GetCollectItem() {
	//CollectAnimation component = this->CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(base.get_transform().get_position()).GetComponent<CollectAnimation>();
	//component.get_transform().set_position(this->CurrentSpriteRenderer.get_transform().get_position());
	//component.Prepare(this->CurrentLevel, this->GetItemType(), zorder(), ImageLibrary.Instance.ColoredBalloonSprites[this->_type - ColoredBalloonType::Balloon1], this->CurrentCell);

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

void ColoredBalloonItem::SetupItem(ColoredBalloonType type) {
	this->_type = type;
	switch (this->_type)
	{
	case ColoredBalloonType::Balloon1:		this->_currentMatchType = MatchType::Yellow;	break;
	case ColoredBalloonType::Balloon2:		this->_currentMatchType = MatchType::Red;		break;
	case ColoredBalloonType::Balloon3:		this->_currentMatchType = MatchType::Blue;		break;
	case ColoredBalloonType::Balloon4:		this->_currentMatchType = MatchType::Green;		break;
	case ColoredBalloonType::Balloon5:		this->_currentMatchType = MatchType::Purple;	break;
	case ColoredBalloonType::Balloon6:		this->_currentMatchType = MatchType::Orange;	break;
	default:
		CCLOG("!!! Cannot Initialize Colored Balloon item with type:%d", type);//LogManager.Error(LogTags.ColoredBalloonItem, "Cannot Initialize Colored Balloon item with type: " + type, new object[0]);
		CCASSERT(false, "break here"); 
		break;
	}
	//this->CurrentSpriteRenderer.set_sprite(ImageLibrary.Instance.ColoredBalloonSprites[this->_type - ColoredBalloonType::Balloon1]);
	ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->ColoredBalloonSprites[(int)this->_type - (int)ColoredBalloonType::Balloon1]);
	cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	newrect.origin.y -= 20.0f; newrect.size.height += 20.0f;
	CurrentSpriteRenderer->setTextureRect(newrect);
}

void ColoredBalloonItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}
//protected:
void ColoredBalloonItem::PlayOnExplodeStartedAnimation() {
	PTCLLIB->explodeColoredBalloon(GetMatchType(), this->CurrentSpriteRenderer->getPosition()); /*if (ParticlePool.Instance != null)
	{
		ParticlePlayer particlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.ColoredBalloon, base.get_transform().get_position(), true);
		ColoredBalloonParticlePlayer component = particlePlayer.GetComponent<ColoredBalloonParticlePlayer>();
		component.SetColor(this->_currentMatchType);
	}//*/
}