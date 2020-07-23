#include "DoubleRocketItem.h"
#include "../Mathf.h"
#include "../Cell.h"
#include "../Match.h"
#include "../Score.h"
#include "../FallManager.h"
#include "../ParticleLibrary.h"
#include "../ImageLibrary.h"
#include "../Grid.h"

#include "cocos2d.h"
USING_NS_CC;

void DoubleRocketItem::SetupItem() {
	HeadLeft = Sprite::create(); CurrentSpriteRenderer->addChild(HeadLeft); HeadLeft->setVisible(false);
	HeadRight = Sprite::create(); CurrentSpriteRenderer->addChild(HeadRight); HeadRight->setVisible(false);
	HeadDown = Sprite::create(); CurrentSpriteRenderer->addChild(HeadDown); HeadDown->setVisible(false);
	HeadUp = Sprite::create(); CurrentSpriteRenderer->addChild(HeadUp); HeadUp->setVisible(false);


	ImageLibrary::CopySprite(HeadLeft, IMGLIB->leftRocket);
	HeadLeft->setPosition(-12, -10);
	ImageLibrary::CopySprite(HeadRight, IMGLIB->rightRocket);
	HeadRight->setPosition(12, -10);

	TrailParticleLeft = ParticleSystemQuad::create("particle/rocketFire.plist");
	TrailParticleLeft->stopSystem();
	TrailParticleLeft->setVisible(false);
	TrailParticleLeft->setPosition(110, 36);
	HeadLeft->addChild(TrailParticleLeft);
	auto starparticle1 = ParticleSystemQuad::create("particle/lineOfStars1.plist");
	TrailParticleLeft->addChild(starparticle1);
	//starparticle1->stopSystem();

	TrailParticleRight = ParticleSystemQuad::create("particle/rocketFire.plist");
	TrailParticleRight->stopSystem();
	TrailParticleRight->setVisible(false);
	TrailParticleRight->setPosition(-40, 36);
	HeadRight->addChild(TrailParticleRight);
	auto starparticle2 = ParticleSystemQuad::create("particle/lineOfStars1.plist");
	TrailParticleRight->addChild(starparticle2);
	//starparticle2->stopSystem();

	ImageLibrary::CopySprite(HeadDown, IMGLIB->bottomRocket);
	HeadDown->setPosition(0, -22);
	ImageLibrary::CopySprite(HeadUp, IMGLIB->topRocket);
	//HeadUp->setPosition(0, 20);

	TrailParticleDown = ParticleSystemQuad::create("particle/rocketFire.plist");
	TrailParticleDown->stopSystem();
	TrailParticleDown->setVisible(false);
	TrailParticleDown->setPosition(35, 110);
	HeadDown->addChild(TrailParticleDown);
	auto starparticle3 = ParticleSystemQuad::create("particle/lineOfStars1.plist");
	TrailParticleDown->addChild(starparticle3);
	//starparticle3->stopSystem();

	TrailParticleUp = ParticleSystemQuad::create("particle/rocketFire.plist");
	TrailParticleUp->stopSystem();
	TrailParticleUp->setVisible(false);
	TrailParticleUp->setPosition(35, -40);
	HeadUp->addChild(TrailParticleUp);
	auto starparticle4 = ParticleSystemQuad::create("particle/lineOfStars1.plist");
	TrailParticleUp->addChild(starparticle4);
	//starparticle4->stopSystem();
}

void DoubleRocketItem::OnExplodeSelf() {
//	ParticlePool.Instance.PlayParticle(ParticlePool.Instance.ComboCreationParticle, this->CurrentCell.GetFrozenPosition(), true);
	PTCLLIB->createSpecialItem(this->get_CurrentCell()->GetFrozenPosition());
}

/*IEnumerator*/void DoubleRocketItem::ExplodeCells() {
	cocos2d::Vector<FiniteTimeAction*> seq;
//case 0:
	this->_score = this->GetScore();
	this->_grid = this->get_CurrentCell()->CurrentGrid;
	this->_height = this->_grid->Height;
	this->_width = this->_grid->Width;
	this->_sx = this->get_CurrentCell()->X;
	this->_sy = this->get_CurrentCell()->Y;
	//this->_screenLeft = CameraHelper.Left.x - 2f;
	//this->_screenRight = CameraHelper.Right.x + 2f;
	//this->_screenUp = CameraHelper.Top.y + 2f;
	//this->_screenDown = CameraHelper.Bottom.y - 2f;
	this->_startDurationH = /*this->HeadRight.get_transform().get_localPosition().x*/0.05f * HorizontalRocketItem::ExplodeTime;
	this->_startDurationV = /*this->HeadUp.get_transform().get_localPosition().y*/0.05f * HorizontalRocketItem::ExplodeTime;
	FallManager::IncreaseWaitingFallBlocker();
//	this->$current = new WaitForSeconds(0.4f);
//	if(!this->$disposing) {
//		this->$PC = 1;
//	}	
	HeadLeft->setVisible(true); HeadRight->setVisible(true);
	HeadUp->setVisible(true); HeadDown->setVisible(true);
	seq.pushBack(DelayTime::create(0.4f));
//	goto nextframe;
//
//case 1:
//	this->RelativeContainer.SetActive(false);
//	this->HorizontalAnimation.SetActive(true);
//	this->VerticalAnimation.SetActive(true);
	seq.pushBack(CallFunc::create([this]() {
		this->TrailParticleLeft->resetSystem(); this->TrailParticleLeft->setVisible(true);
		this->TrailParticleRight->resetSystem(); this->TrailParticleRight->setVisible(true);
		this->TrailParticleUp->resetSystem(); this->TrailParticleUp->setVisible(true);
		this->TrailParticleDown->resetSystem(); this->TrailParticleDown->setVisible(true);
	}));
//	AudioManager.Play(AudioTag.ComboRocketRocket, PlayMode.Frame, null, 1f);
//	seq = DOTween.Sequence();
//	seq.AppendCallback(this->ExplodeLater(this->_grid, this->_sx, this->_sy));
	seq.pushBack(CallFunc::create([this]() {this->ExplodeLater(this->_grid, this->_sx, this->_sy); }));
	seq.pushBack(CallFunc::create([this]() {
		//	__step = 1;
		int __step = 1;
		//	this-><columnCompleted>__0 = false;
		bool __columnCompleted = false;
		//	__rowCompleted = false;
		bool __rowCompleted = false;
		while(!__columnCompleted || !__rowCompleted) {
			int topy = this->_sy + __step;
			int btmy = this->_sy - __step;
			int rgtx = this->_sx + __step;
			int lftx = this->_sx - __step;
			__columnCompleted = (topy >= this->_height) && (btmy < 0);
			__rowCompleted = (lftx < 0) && (rgtx >= this->_width);
			if(topy <= this->_height)
				this->StepRocketV(this->HeadUp, __step, 1);
			if(btmy >= -1)
				this->StepRocketV(this->HeadDown, __step, -1);
			if(lftx >= -1)
				this->StepRocketH(this->HeadLeft, __step, -1);
			if(rgtx <= this->_width)
				this->StepRocketH(this->HeadRight, __step, 1);
			__step++;
		}
		int __leftmoveamount = this->_sx - (-3); float __leftmovetime = HorizontalRocketItem::ExplodeTime*__leftmoveamount;
		int __rightmoveamount = 12 - this->_sx; float __rightmovetime = HorizontalRocketItem::ExplodeTime*__rightmoveamount;
		HeadLeft->runAction(MoveBy::create(__leftmovetime, -Vec2::UNIT_X*ITEM_SPRITE_SIZE_X*__leftmoveamount));
		HeadRight->runAction(MoveBy::create(__rightmovetime, Vec2::UNIT_X*ITEM_SPRITE_SIZE_X*__rightmoveamount));
		int __bottommoveamount = this->_sy - (-5); float __bottommovetime = HorizontalRocketItem::ExplodeTime*__bottommoveamount;
		int __topmoveamount = 14 - this->_sy; float __topmovetime = HorizontalRocketItem::ExplodeTime*__topmoveamount;
		HeadDown->runAction(MoveBy::create(__bottommovetime, -Vec2::UNIT_Y*ITEM_SPRITE_SIZE_X*__bottommoveamount));
		HeadUp->runAction(MoveBy::create(__topmovetime, Vec2::UNIT_Y*ITEM_SPRITE_SIZE_X*__topmoveamount));
	}));
	seq.pushBack(DelayTime::create(Mathf::Max(Mathf::Max(Mathf::Max(12 - _sx, _sx - (-3)), 14 - _sy), _sy - (-5))*HorizontalRocketItem::ExplodeTime + 0.1f));
//	seq.InsertCallback(this->_exitTime, new TweenCallback(this->AllowFalls));
	seq.pushBack(CallFunc::create([this]() {this->AllowFalls(); }));
//	break;
//[breakTo]
//while(this->_waitLastRocketExit) {
//	this->$current = null;
//	if(!this->$disposing) {
//		this->$PC = 2;
//	}
//	goto nextframe;
//
//case 2:
//	break;
//
//default:
//	goto Label_0464;
//}
//}
//this->$PC = -1;

	// ExplodeCells ended
	seq.pushBack(CallFunc::create([this]() {afterExplodeCells(); }));
	CurrentSpriteRenderer->runAction(Sequence::create(seq));
}

/*IEnumerator*/void DoubleRocketItem::Die() {
	//case 0:
	// this.$current = new WaitForSeconds(1f);
	// if(!this.$disposing) {
	//	 this.$PC = 1;
	// }
	// return true;
	//
	//case 1:
	// this.$this.RemoveSelf();
	// this.$PC = -1;
	// break;

	this->CurrentSpriteRenderer->runAction(Sequence::createWithTwoActions(DelayTime::create(1.0f), RemoveSelf::create()));
}

void DoubleRocketItem::StepRocketH(/*Transform*/cocos2d::Node* rocket, int step, int direction/*, cocos2d::Vector<cocos2d::FiniteTimeAction*>& seq*/) {
	int x = this->_sx + step * direction;
	bool isInside = x >= 0 && x < this->_width;
	if(isInside)
		rocket->runAction(Sequence::createWithTwoActions(
		DelayTime::create(Mathf::Abs(step)*HorizontalRocketItem::ExplodeTime),
		CallFunc::create([this, x]() {this->ExplodeLater(this->_grid, x, this->_sy); })));
	return;
	//int nextx = x + direction;
	//float duration = (step != 1) ? HorizontalRocketItem::ExplodeTime : this->_startDurationH;
	//float atPosition = (step != 1) ? (HorizontalRocketItem::ExplodeTime * (float)(step - 2) + this->_startDurationH) : 0.0f;
	//float endValue = rocket->getPosition().x + ((float)step - HorizontalRocketItem::Offset) * (float)direction*ITEM_SPRITE_SIZE_X;
	////seq.Insert(atPosition, rocket.DOMoveX(endValue, duration, false).SetEase(Ease.Linear));
	//seq.pushBack(MoveTo::create(duration, Vec2(endValue, rocket->getPositionY())));
	//if(isInside)
	//	//seq.InsertCallback(atPosition + duration, this->ExplodeLater(this->_grid, x, this->_sy));
	//	seq.pushBack(CallFunc::create([this, x]() {this->ExplodeLater(this->_grid, x, this->_sy); }));
	//
	//if(nextx >= this->_width) {
	//	float duration = (this->_screenRight - endValue) * HorizontalRocketItem::ExplodeTime;
	//	float num6 = atPosition + duration;
	//	this->_exitTime = Mathf::Max(num6, this->_exitTime);
	//	//seq.Insert(num6, rocket.DOMoveX(this->_screenRight, duration, false).SetEase(Ease.Linear));
	//	seq.pushBack(MoveTo::create(duration, Vec2(12 * ITEM_SPRITE_SIZE_X, rocket->getPositionY())));
	//}
	//else if(nextx < 0) {
	//	float duration2 = -(this->_screenLeft - endValue) * HorizontalRocketItem::ExplodeTime;
	//	float num7 = atPosition + duration;
	//	this->_exitTime = Mathf::Max(num7, this->_exitTime);
	//	//seq.Insert(num7, rocket.DOMoveX(this->_screenLeft, duration2, false).SetEase(Ease.Linear));
	//	seq.pushBack(MoveTo::create(duration, Vec2(-3 * ITEM_SPRITE_SIZE_X, rocket->getPositionY())));
	//}
}

void DoubleRocketItem::StepRocketV(/*Transform*/cocos2d::Node* rocket, int step, int direction/*, cocos2d::Vector<cocos2d::FiniteTimeAction*>& seq*/) {
	int y = this->_sy + step * direction;
	bool isInside = y >= 0 && y < this->_height;
	if(isInside)
		rocket->runAction(Sequence::createWithTwoActions(
		DelayTime::create(Mathf::Abs(step)*HorizontalRocketItem::ExplodeTime),
		CallFunc::create([this, y]() {this->ExplodeLater(this->_grid, this->_sx, y); })));
	return;

	//int nexty = y + direction;
	//float duration = (step != 1) ? HorizontalRocketItem::ExplodeTime : this->_startDurationV;
	//float atPosition = (step != 1) ? (HorizontalRocketItem::ExplodeTime * (float)(step - 2) + this->_startDurationV) : 0.0f;
	//float endValue = rocket->getPosition().y + ((float)step - HorizontalRocketItem::Offset) * (float)direction*ITEM_SPRITE_SIZE_X;
	////seq.Insert(atPosition, rocket.DOMoveY(endValue, duration, false).SetEase(Ease.Linear));
	//seq.pushBack(MoveTo::create(duration, Vec2(rocket->getPositionX(), endValue)));
	//if(isInside)
	//	//seq.InsertCallback(atPosition + duration, this->ExplodeLater(this->_grid, this->_sx, y));
	//	seq.pushBack(CallFunc::create([this, y]() {this->ExplodeLater(this->_grid, this->_sx, y); }));
	//
	//if(nexty >= this->_height) {
	//	float duration = (this->_screenUp - endValue) * HorizontalRocketItem::ExplodeTime;
	//	float num6 = atPosition + duration;
	//	this->_exitTime = Mathf::Max(num6, this->_exitTime);
	//	//seq.Insert(num6, rocket.DOMoveY(this->_screenUp, duration, false).SetEase(Ease.Linear));
	//	seq.pushBack(MoveTo::create(duration, Vec2(rocket->getPositionX(), 14 * ITEM_SPRITE_SIZE_X)));
	//}
	//else if(nexty < 0) {
	//	float duration2 = -(this->_screenDown - endValue) * HorizontalRocketItem::ExplodeTime;
	//	float num7 = atPosition + duration;
	//	this->_exitTime = Mathf::Max(num7, this->_exitTime);
	//	//seq.Insert(num7, rocket.DOMoveY(this->_screenDown, duration2, false).SetEase(Ease.Linear));
	//	seq.pushBack(MoveTo::create(duration, Vec2(rocket->getPositionX(), -5 * ITEM_SPRITE_SIZE_X)));
	//}
}

void DoubleRocketItem::AllowFalls() {
	for(Cell* current : this->ComboMatchGroup->AllCells)
		current->AcceptsFallInside();

	ScoreManager::RaiseScore(this->_score, this->_grid->cell(this->_sx, this->_sy)->GetFrozenPosition(), MatchType::None);
	FallManager::DecreaseWaitingFallBlocker();
	this->_waitLastRocketExit = false;
	if(this->CurrentSpriteRenderer->isVisible())
		this->Die();
	else
		this->RemoveSelf();
}

/*TweenCallback*/void DoubleRocketItem::ExplodeLater(Grid* currentGrid, int x, int y) {
	//return;/* delegate*/ 	{
	if(x < 0 || x >= currentGrid->Width || y < 0 || y >= currentGrid->Height)
		return;

	Cell* cell = currentGrid->cell(x, y);
	Item* currentItem = cell->get_CurrentItem();
	int num = 0;
	bool flag = false;
	if(currentItem != nullptr) {
		num = currentItem->GetScore();
		flag = currentItem->CanGenerateScoreWithoutExplode();
	}
	if(this->ExplodeBySpecialItem(cell))
		this->_score += SpecialItem::GetScoreForSpecialItem(currentItem, cell);
	else if(cell->get_HasItem() && cell->get_CurrentItem()->CanGenerateScoreOnEachTryExplode() && cell->get_CurrentItem()->CanGenerateScoreThisTurn())
		this->_score += currentItem->GetScore();
	else if(!cell->get_HasItem() && flag && num > 0)
		this->_score += num;
	//};
}