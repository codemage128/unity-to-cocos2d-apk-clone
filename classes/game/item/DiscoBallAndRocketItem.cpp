#include "DiscoBallAndRocketItem.h"
#include "../Cell.h"
#include "../FallManager.h"
#include "../Score.h"
#include "../Grid.h"
#include "../Level.h"
#include "../LevelBuilder.h"
#include "../ParticleLibrary.h"

#include "cocos2d.h"
USING_NS_CC;

DiscoBallAndRocketItem::DiscoBallAndRocketItem() {
	CreatedItems.reserve(10);
}

/*IEnumerator*/void DiscoBallAndRocketItem::OnRayReached(Cell* c, Item* i, cocos2d::FiniteTimeAction* tweener, cocos2d::ParticleSystemQuad* p) {
	Vector<FiniteTimeAction*> seq;
	//switch(num) {
	//case 0:
	seq.pushBack(DelayTime::create(0));
	//case 1:
	//if(this->tweener.IsActive() && this->tweener.IsPlaying()) {
	//	this->$current = null;
	//	if(!this->$disposing) {
	//		this->$PC = 1;
	//	}
	//	goto Label_01D4;
	//}
	seq.pushBack(DelayTime::create(tweener->getDuration()));
	//if(!this->c.HasItem) {
	//	goto Label_01D2;
	//}
	if(!c->get_HasItem())
		return;

	seq.pushBack(CallFunc::create([this, c]() {
		this->oldItem = c->get_CurrentItem();
		this->CurrentLevel->DecreaseGoal(this->oldItem->GetItemType(), false);
		this->createdSpecialItem = this->CreateSpecialItem(this->currentGrid, c);
		this->createdSpecialItem->CurrentSpriteRenderer->setVisible(false);
		this->createdSpecialItem->CanNotJoinToCombo = true;
		c->set_CurrentItem(this->createdSpecialItem);
		this->ChangedItems.push_back(this->createdSpecialItem);
		//CanCastShadowComponent.CastShadowIfPossible(this->c);
		this->oldItem->RemoveSelf();
		//ParticlePool.Instance.PlayParticle(ParticlePool.Instance.RemainingMoveReplaceParticle, this->c.GetFrozenPosition(), true);
		this->createdSpecialItem->CurrentSpriteRenderer->setVisible(true);
		//this-><itemParticle>__0 = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DiscoRayReachedParticle, this->c.GetFrozenPosition() + DiscoBallItem.ParticleStartOffset, false);
		//this-><itemParticle>__0.Play();
		PTCLLIB->createSpecialItem(c->GetFrozenPosition());
	}));

	//while(!this->_raysEnded) {
	//	this->$current = null;
	//	if(!this->$disposing) {
	//		this->$PC = 2;
	//	}
	//	goto Label_01D4;
	//}
	//this-><itemParticle>__0.Recycle<ParticlePlayer>();
	//this->$PC = -1;

	CurrentSpriteRenderer->runAction(Sequence::create(seq));
}

void DiscoBallAndRocketItem::_onRaysEnded() {
	_raysEnded = true;

}

void DiscoBallAndRocketItem::RemoveSelf() {
	this->OnBeforeRemove();
	if (!this->_destoyed) {
		// Object.Destroy(base.get_gameObject());
		this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
		//delete this;
		_destoyed = true;
	}
}

int DiscoBallAndRocketItem::Sorter(Item* a, Item* b) {
	Cell* currentCell = a->get_CurrentCell();
	Cell* currentCell2 = b->get_CurrentCell();
	return (currentCell2->Y - currentCell->Y) * 1000 - (currentCell2->X - currentCell->X);
}

/*IEnumerator*/void DiscoBallAndRocketItem::DoDiscoExpldoes(std::vector<Cell*>& explodeCells) {
	Vector<FiniteTimeAction*> seq;
	// case 0:
	//	 this.$locvar0 = this.$this.ComboMatchGroup.AllCells.GetEnumerator();
	//	 try {
	//		 while(this.$locvar0.MoveNext()) {
	//			 this.$locvar0.Current.AcceptsFallInside();
	//		 }
	//	 }
	//	 finally
	//	 {
	//		 this.$locvar0.Dispose();
	//	 }
	for(Cell* onecell : this->ComboMatchGroup->AllCells)
		onecell->AcceptsFallInside();
	//	 this.$current = new WaitForSeconds(0.7f);
	seq.pushBack(DelayTime::create(0.3f));
	//	 if(!this.$disposing) {
	//		 this.$PC = 1;
	//	 }
	//	 goto Label_0123;
	//
	// case 1:
	//	 if(DiscoBallAndRocketItem.<>f__mg$cache0 == null) {
	//		 DiscoBallAndRocketItem.<>f__mg$cache0 = new Comparison<SpecialItem>(DiscoBallAndRocketItem.Sorter);
	//	 }
	//	 this.$this.ChangedItems.Sort(DiscoBallAndRocketItem.<>f__mg$cache0);
	//std::sort(ChangedItems.begin(), ChangedItems.end(), std::bind(&DiscoBallAndRocketItem::Sorter, this, std::placeholders::_1, std::placeholders::_2));
	//	 this.<w>__0 = this.$this.PlayDiscoExplodes();
	//	 break;
	//
	// case 2:
	//	 break;
	//
	// default:
	//	 goto Label_0121;
	//}
	//while(this.<w>__0.MoveNext()) {
	//	this.$current = this.<w>__0.Current;
	//	if(!this.$disposing) {
	//		this.$PC = 2;
	//	}
	//	goto Label_0123;
	//}
	//this.$PC = -1;
	this->PlayDiscoExplodes(seq);

	CurrentSpriteRenderer->runAction(Sequence::create(seq));
}

/*IEnumerator*/void DiscoBallAndRocketItem::PlayDiscoExplodes(cocos2d::Vector<cocos2d::FiniteTimeAction*>& seq) {
	//case 0:
	//		this.<index>__1 = 0;
	//		goto Label_00C4;
	//
	//	case 1:
	//		break;
	//
	//	default:
	//		goto Label_00E6;
	//}
	//Label_00A6:
	//while(this.<w>__3.MoveNext()) {
	//	this.$current = this.<w>__3.Current;
	//	if(!this.$disposing) {
	//		this.$PC = 1;
	//	}
	//	return true;
	//}
	//Label_00B6:
	//this.<index>__1++;
	//Label_00C4:
	//if(this.<index>__1 < this.$this.ChangedItems.Count) {
	//	this.<c>__2 = this.$this.ChangedItems[this.<index>__1];
	//	if((this.<c>__2 == null) || this.<c>__2.ReCycled) {
	//		goto Label_00B6;
	//	}
	//	this.<w>__3 = this.<c>__2.StartAutoExplode(null);
	//	goto Label_00A6;
	//}
	//this.$PC = -1;
	for(int i = 0; i < (int)ChangedItems.size(); i++)
		seq.pushBack(Sequence::createWithTwoActions(
		DelayTime::create(0.3f),
		CallFunc::create([this, i]() {
		if(!ChangedItems[i]->isExploded)
			ChangedItems[i]->StartAutoExplode(0.0f);
	})));
}

void DiscoBallAndRocketItem::DoDie() {
	if (this->ShouldBlockFalls()) {
		FallManager::DecreaseWaitingFallBlocker();
	}
	if (this->_destoyed) {
		return;
	}
	ScoreManager::RaiseScore(this->Score + this->ComboMergeScores, CurrentSpriteRenderer->getPosition(), MatchType::None);
	FallManager::DecreaseMechanicAnimation();

	CurrentSpriteRenderer->runAction(Sequence::createWithTwoActions(DelayTime::create(0.7f + ChangedItems.size()*0.3f + 0.1f), CallFunc::create([this]() { this->RemoveSelf(); })));
}

SpecialItem* DiscoBallAndRocketItem::CreateSpecialItem(Grid* theGrid, Cell* c) {
	HorizontalRocketItem* horizontalRocketItem = theGrid->CurrentLevel->CurrentLevelBuilder->CreateRandomRocket(c->GetFrozenPosition());
	horizontalRocketItem->AllowBlockFalls();
	return horizontalRocketItem;
}

