#include "MagicHatItem.h"
#include "../Cell.h"
#include "../Grid.h"
#include "../Extension.h"
#include "../Level.h"
#include "../Score.h"
#include "../ImageLibrary.h"
#include "../ParticleLibrary.h"
#include "../FallManager.h"
#include "../LevelBuilder.h"
#include "../Level.h"
#include "../../ScnLevelPlay.h"

USING_NS_CC;

void MagicHatItem::SetupItem() {
	//ImageLibrary::CopySprite(this->CurrentSpriteRenderer, IMGLIB->MagicHat);
	//cocos2d::Rect newrect = CurrentSpriteRenderer->getTextureRect();
	//newrect.origin.y -= 20.0f; newrect.size.height += 20.0f;
	//CurrentSpriteRenderer->setTextureRect(newrect);
	_hatNode = CSLoader::createNode("play/cellMagicHat.csb");
	_hatAnim = CSLoader::createTimeline("play/cellMagicHat.csb");
	_hatNode->setPosition(0, -5);
	CurrentSpriteRenderer->addChild(_hatNode);
	_hatNode->runAction(_hatAnim);
	_hatAnim->gotoFrameAndPause(0);

}

void MagicHatItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void MagicHatItem::Start() {
//	this->_throwHash = Animator.StringToHash("Base Layer.MagicHatThrowAnimation");

}

void MagicHatItem::StartCollect() {
	SpriteBasedItem::StopOtherAnimations();
//	new Task(this->PlayCollectAnimation());
	this->PlayCollectAnimation();
}

/*IEnumerator*/void MagicHatItem::PlayCollectAnimation() {
//case 0:
//    this.$this.CurrentAnimator.Play(this.$this._throwHash, 0, 0f);
//    AudioManager.Play(AudioTag.ItemMagichat, PlayMode.Frame, null, 1f);
//    this.$current = new WaitForSeconds(0.12f);
//    if (!this.$disposing)
//    {
//        this.$PC = 1;
//    }
//    goto Label_01AB;
//
//case 1:
//    if (ParticlePool.Instance != null)
//    {
//        ParticlePool.Instance.PlayParticle(ParticlePool.Instance.MagicHatExplosion, this.$this.get_transform().get_position(), true);
//    }
//    this.$current = new WaitForSeconds(0.03f);
//    if (!this.$disposing)
//    {
//        this.$PC = 2;
//    }
//    goto Label_01AB;
//
//case 2:
//    if (ParticlePool.Instance != null)
//    {
//        this.<carrot>__0 = this.$this.CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(this.$this.get_transform().get_position());
//        this.<carrotParticle>__0 = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.CarrotTrailParticle, Vector3.get_zero(), true);
//        this.<carrotCollectAnimation>__0 = this.<carrot>__0.GetComponent<CollectAnimation>();
//        this.<carrotCollectAnimation>__0.CollectSpriteRenderer.set_enabled(false);
//        this.<carrotCollectAnimation>__0.Prepare(this.$this.CurrentLevel, ItemType.Carrot, DefinedSo rting.Collecting.GetS orting(), ImageLibrary.Instance.CarrotCollectingImage, this.$this.CurrentCell).StartAnimation();
//        this.<carrotCollectAnimation>__0.SetParticle(this.<carrotParticle>__0);
//        this.$PC = -1;
//        break;
//    }
//    break;
//}
//return false;
//Label_01AB:
//return true;
	_hatAnim->play("collect", false);
	ParticleSystemQuad* carrotparticle = dynamic_cast<ParticleSystemQuad*>(_hatNode->getChildren().at(0)->getChildren().at(1));
	carrotparticle->resetSystem();
	carrotparticle->setPositionType(ParticleSystem::PositionType::FREE);

	_hatAnim->setAnimationEndCallFunc("collect", [this]() {
		//CollectAnimation Prepare(Level currentLevel, ItemType goalType, S orting s, Sprite sprite, Cell currentCell) {
		//	this.CurrentLevel = currentLevel;
		//	currentLevel.PreCheckDecreaseGoal(goalType);
		CurrentLevel->PreCheckDecreaseGoal(ItemType::Carrot);
		//	if(this._increaseRequested) {
		//		return this;
		//	}
		//	currentLevel.StopRefillIfNeeded(goalType);
		CurrentLevel->StopRefillIfNeeded(ItemType::Carrot);
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

		// cloning current item's sprite renderer
		cocos2d::Sprite* clonesprite = cocos2d::Sprite::create();
		Sprite* srcCarrot = dynamic_cast<Sprite*>(_hatNode->getChildren().at(0)->getChildren().at(1)->getChildren().at(0));
		cocos2d::Node* targetContainer = CurrentLevel->CurrentLevelBuilder->SceneContainer;
		targetContainer->addChild(clonesprite, ITEM_GOAL_ANIMATION_ZORDER_ONSCENEROOT);
		ImageLibrary::CopySprite(clonesprite, srcCarrot);
		clonesprite->setPosition(targetContainer->convertToNodeSpace(srcCarrot->convertToWorldSpaceAR(cocos2d::Vec2::ZERO)));
		clonesprite->setRotation(srcCarrot->getRotation());
		clonesprite->setScale((targetContainer->convertToNodeSpace(srcCarrot->convertToWorldSpaceAR(cocos2d::Vec2::ONE)) -
			targetContainer->convertToNodeSpace(srcCarrot->convertToWorldSpaceAR(cocos2d::Vec2::ZERO))).x);
		ParticleSystemQuad* cloneparticle = PTCLLIB->cloneParticle(dynamic_cast<ParticleSystemQuad*>(srcCarrot->getParent()));
		cloneparticle->setPosition(50, 47);
		cloneparticle->setScale(1 / clonesprite->getScale());
		clonesprite->addChild(cloneparticle);
		
		// apply collect animation
		ScnLevelPlay* toppanel = CurrentLevel->CurrentLevelBuilder->LevelScene;
		int goalidx = toppanel->getGoalIdx(ItemType::Carrot);
		if(goalidx >= 0) {
			Level* curlvl = CurrentLevel;
			// move item's sprite to goal position
			cocos2d::Vec2 tgtpos = toppanel->getGoalIconPos(goalidx);
			float tgtscale = toppanel->getGoalIconScale(goalidx);
			float duration = (0.4f + (7.3f - get_CurrentCell()->Y)*0.05f + Mathf::Abs(3.3f - get_CurrentCell()->X)*0.1f)*0.7f;
			clonesprite->runAction(cocos2d::EaseBackIn::create(cocos2d::ActionFloat::create(duration, clonesprite->getPositionY(), tgtpos.y, [clonesprite](float y) {clonesprite->setPositionY(y); })));
			clonesprite->runAction(cocos2d::ActionFloat::create(duration, clonesprite->getPositionX(), tgtpos.x, [clonesprite](float x) {clonesprite->setPositionX(x); }));
			clonesprite->runAction(cocos2d::EaseQuarticActionIn::create(cocos2d::ScaleTo::create(duration, tgtscale)));
			clonesprite->runAction(cocos2d::EaseSineIn::create(cocos2d::RotateTo::create(duration, 0)));
			// apply goal fx on top panel
			clonesprite->runAction(cocos2d::Sequence::create(
				cocos2d::DelayTime::create(duration),
				cocos2d::RemoveSelf::create(),
				cocos2d::CallFunc::create([toppanel, goalidx]() {toppanel->playGoalFx(goalidx); }),
				cocos2d::CallFunc::create([curlvl]() {curlvl->DecreaseGoal(ItemType::Carrot, true); }),
				nullptr));
		}


		_hatAnim->gotoFrameAndPause(0);
	});

}

bool MagicHatItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame()) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	if (!this->CurrentLevel->CanBeCollected(ItemType::Carrot)) {
		return false;
	}
	this->StartCollect();
	if (this->CanRaiseScore()) {
		ScoreManager::RaiseScore(this->GetScore(), CurrentSpriteRenderer->getPosition(), MatchType::None);
	}
	return false;
}
