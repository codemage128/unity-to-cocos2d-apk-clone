#include "ItemImpl.h"
#include "Tween.h"
#include "Animation.h"
#include "Match.h"
#include "ImageLibrary.h"
#include "ParticleLibrary.h"
#include "Extension.h"
#include "HintManager.h"
#include "FallManager.h"
#include "Cell.h"
#include "LevelBuilder.h"

#include "cocos2d.h"

//////////////SpriteBasedItem///////////////////////////////////////////
SpriteBasedItem::SpriteBasedItem() {
	CurrentSpriteRenderer = cocos2d::Sprite::create();
	CurrentSpriteRenderer->retain();
}
SpriteBasedItem::~SpriteBasedItem() {
	CurrentSpriteRenderer->release();
}

//////////////SolidColorItem///////////////////////////////////////////
SolidColorItem::SolidColorItem() {
	GlowSpriteRenderer = cocos2d::Sprite::createWithTexture(IMGLIB->blockGlow->getTexture());
	GlowSpriteRenderer->retain();
	GlowSpriteRenderer->setVisible(false);
}

SolidColorItem::~SolidColorItem() {
	GlowSpriteRenderer->release();
}

void SolidColorItem::HideCurrentlyUnderTap() {
	//if((this->_highlightTween != nullptr) && this->_highlightTween.IsPlaying()) {
	//	this->_highlightTween.Kill(false);
	//	this->RemoveHighlightTween();
	//}
	SpriteBasedItem::CurrentSpriteRenderer->setColor(cocos2d::Color3B::WHITE);
}

Tweener* SolidColorItem::MoveToSpecialItem(Cell* targetCell) {
	SpriteBasedItem::StopOtherAnimations();
	SpriteBasedItem::CurrentSpriteRenderer->setLocalZOrder(SpriteBasedItem::CurrentSpriteRenderer->getLocalZOrder() + 0x640);
	this->GlowSpriteRenderer->setVisible(true);
	//this->GlowSpriteRenderer->setLocalZOrder(0x640);
	GlowSpriteRenderer->setLocalZOrder(GlowSpriteRenderer->getLocalZOrder() + 0x640);
	//return this->_currentMoveToSpecialItemAnimation.MoveTo(this, targetCell);
	this->CurrentSpriteRenderer->runAction(cocos2d::Sequence::create(
		cocos2d::CallFunc::create([this]() {
			FallManager::getInstance()->IncreaseMechanicAnimation();
			FallManager::getInstance()->IncreaseWaitingFallBlocker();
		}),
		cocos2d::EaseBackIn::create(cocos2d::MoveTo::create(0.3f, targetCell->GetFrozenPosition())),
		cocos2d::CallFunc::create([this]() {
			FallManager::getInstance()->DecreaseMechanicAnimation();
			FallManager::getInstance()->DecreaseWaitingFallBlocker();
			this->RemoveSelf();
		}),
		nullptr));
	this->GlowSpriteRenderer->setPosition(CurrentSpriteRenderer->getPosition());
	this->GlowSpriteRenderer->runAction(cocos2d::EaseBackIn::create(cocos2d::MoveTo::create(0.3f, targetCell->GetFrozenPosition())));

	return nullptr;
}

void SolidColorItem::OnBeforeRemove() {
	SpriteBasedItem::OnBeforeRemove();
	//this->_currentMoveToSpecialItemAnimation.ResetMe();
}

void SolidColorItem::Paint(MatchType mType) {
	switch(mType) {
	case MatchType::Yellow: this->_itemType = ItemType::SolidColor1; break;
	case MatchType::Red: this->_itemType = ItemType::SolidColor2; break;
	case MatchType::Blue: this->_itemType = ItemType::SolidColor3; break;
	case MatchType::Green: this->_itemType = ItemType::SolidColor4; break;
	case MatchType::Purple: this->_itemType = ItemType::SolidColor5; break;
	case MatchType::Orange: this->_itemType = ItemType::SolidColor6; break;
	}
	this->_currentMatchType = mType;
	ImageLibrary::CopySprite(SpriteBasedItem::CurrentSpriteRenderer,IMGLIB->SolidColorSprites[(int)mType]);
}

void SolidColorItem::PlayOnExplodeStartedAnimation() {
	/*if(ParticlePool.Instance != nullptr) {
		SolidColorParticlePlayer player = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.SolidColorExplosion, base.get_transform().get_position() + Constants.LocalCenterOfCube, false) as SolidColorParticlePlayer;
		player.SetColor(this->GetItemType());
		player.EnableSmokeParticle(base.ToBeExplodedBy != ExplodeReason.Anvil);
		if(base.ToBeExplodedBy == ExplodeReason.Anvil) {
			player.SetParticleCount(2f);
		}
		player.Play();
	}*/
	PTCLLIB->explodeSolid(this->GetItemType(), CurrentSpriteRenderer->getPosition());
}

void SolidColorItem::RemoveHighlightTween() {
	//this->_highlightTween = nullptr;
}

void SolidColorItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->GlowSpriteRenderer->removeFromParentAndCleanup(true);
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void SolidColorItem::ResetAfterPool() {
	//if((this->_highlightTween != nullptr) && this->_highlightTween.IsPlaying()) {
	//	this->_highlightTween.Kill(false);
	//	this->RemoveHighlightTween();
	//}
	SpriteBasedItem::StopOtherAnimations();
	if(this->GlowSpriteRenderer != nullptr) this->GlowSpriteRenderer->setVisible(false);
	this->_currentMatchType = MatchType::None;
}

void SolidColorItem::SetupItem(ItemType type) {
	this->ResetAfterPool();
	this->_itemType = type;
	switch(type) {
	case ItemType::SolidColor1: this->_currentMatchType = MatchType::Yellow; break;
	case ItemType::SolidColor2: this->_currentMatchType = MatchType::Red; break;
	case ItemType::SolidColor3: this->_currentMatchType = MatchType::Blue; break;
	case ItemType::SolidColor4: this->_currentMatchType = MatchType::Green; break;
	case ItemType::SolidColor5: this->_currentMatchType = MatchType::Purple; break;
	case ItemType::SolidColor6: this->_currentMatchType = MatchType::Orange; break;
	default:
		//LogManager.Error(LogTags.SolidColorItem, "Cannot Initialize normal item with type: " + type, new object[0]);
		break;
	}
	ImageLibrary::CopySprite(SpriteBasedItem::CurrentSpriteRenderer, IMGLIB->SolidColorSprites[(int)this->_currentMatchType]);
}

CollectAnimation SolidColorItem::GetCollectItem() {
	SpriteBasedItem::GetCollectItem();
	return CollectAnimation::SolidColor;
}

void SolidColorItem::ShowCurrentlyUnderTap() {
	//this->_highlightTween = base.CurrentSpriteRenderer.DOColor(this->HighlightColor, 0.35f).SetEase<Tweener>(Ease.InExpo).OnComplete<Tweener>(new TweenCallback(this->RemoveHighlightTween));
}

void SolidColorItem::ShowMatchHint() {
	HintManager::getInstance()->createHintAnimation(SpriteBasedItem::CurrentSpriteRenderer);
	//base.CurrentSpriteRenderer.get_gameObject().GetComponentOrAdd<SharedShinyHintAnimation>().StartAnimation();
}

//////////////FrameItem///////////////////////////////////////////
void FrameItem::SetupItem() {
	_frameSprite = cocos2d::Sprite::create();
	ImageLibrary::CopySprite(this->_frameSprite, IMGLIB->Frame);
	this->CurrentSpriteRenderer->addChild(_frameSprite,200);
}

void FrameItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void FrameItem::set_InnerItem(Item* value) {
	this->_innerItem = value;
	if(this->_innerItem == nullptr) {
		this->_innerItemOriginalScale = cocos2d::Vec2::ZERO;
		return;
	}
	//cocos2d::Node* relativeContainer = this->_innerItem->RelativeContainer;
	//if(relativeContainer == nullptr)
	//	return;

	cocos2d::Sprite* innerSprite = LevelBuilder::getItemSprite(get_InnerItem());
	if(innerSprite != nullptr) {
		this->_innerItemOriginalScale = cocos2d::Vec2(innerSprite->getScale(), innerSprite->getScale());//cocos2d::Vec2(relativeContainer->getScaleX(), relativeContainer->getScaleY());
		/*relativeContainer*/innerSprite->setScale(this->_innerItemOriginalScale.x*0.9f);//(relativeContainer->getScaleX() * 0.9f, relativeContainer->getScaleY()*0.9f);
	}

	if(this->_innerItem->CanCastShadow()) {
		CanCastShadowComponent* shadowCaster = this->_innerItem->GetShadowCaster();
		if(shadowCaster != nullptr) {
			shadowCaster->HideShadow();
		}
	}
}


Item* FrameItem::ExtractSubItem() {
	if(this->_innerItem != nullptr) {
		cocos2d::Vec2 innerItemOriginalScale = this->_innerItemOriginalScale;
		if(innerItemOriginalScale!=cocos2d::Vec2::ZERO) {
			//cocos2d::Node* relativeContainer = this->get_InnerItem()->RelativeContainer;
			//relativeContainer->setScale(this->_innerItemOriginalScale.x, this->_innerItemOriginalScale.y);
			cocos2d::Sprite* innerSprite = LevelBuilder::getItemSprite(get_InnerItem());
			if(innerSprite != nullptr) {
				/*relativeContainer*/innerSprite->setScale(this->_innerItemOriginalScale.x);//(relativeContainer->getScaleX() * 0.9f, relativeContainer->getScaleY()*0.9f);
			}

			this->get_InnerItem()->MasterItemExplode = Ext_getCurrentFrame();
			return this->get_InnerItem();
		}
	}
	return this->get_InnerItem();
}


void FrameItem::PlayExplodeAudio() {
	//AudioManager.Play(AudioTag.ItemFrame, PlayMode.Frame, null, 1f);
}

void FrameItem::PlayOnExplodeStartedAnimation() {
	//if(ParticlePool.Instance != null) {
	//	ParticlePool.Instance.PlayParticle(ParticlePool.Instance.FrameItemExploded, base.get_transform().get_position(), true);
	//}
	PTCLLIB->explodeFrame(CurrentSpriteRenderer->getPosition());
}