#include "DoubleBombItem.h"
#include "../ParticleLibrary.h"
#include "../Match.h"
#include "../Cell.h"
#include "../FallManager.h"
#include "../ParticleLibrary.h"
#include "../LevelBuilder.h"
#include "../Score.h"
#include "../Level.h"
#include "../Mathf.h"
#include "../../ScnLevelPlay.h"

USING_NS_CC;

void DoubleBombItem::RemoveSelf() {
	this->OnBeforeRemove();
//	Object.Destroy(base.get_gameObject());
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

void DoubleBombItem::OnExplodeSelf() {
//	ParticlePool.Instance.PlayParticle(ParticlePool.Instance.ComboCreationParticle, this->CurrentCell.GetFrozenPosition(), true);
	PTCLLIB->createSpecialItem(this->get_CurrentCell()->GetFrozenPosition());
}

void DoubleBombItem::PlayExplodeParticle() {
//	ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DoubleBombExplodeParticle, base.get_transform().get_position(), true);
	PTCLLIB->showBombBombExplode(this->_scorepos);
}

/*IEnumerator*/void DoubleBombItem::ExplodeCells() {
	Vector<FiniteTimeAction*> seq;

//	switch (num)
//    {
//        case 0:
//            AudioManager.Play(AudioTag.ComboBombBomb, PlayMode.Frame, null, 1f);
//            this.<neighbours>__0 = this.$this.GetNeigbours(3);
//            this.<scorePosition>__0 = this.$this.CurrentCell.GetFrozenPosition();
//            this.<score>__0 = 0;
	this->_neigbours = this->GetNeigbours(3);
	this->_scorepos = this->get_CurrentCell()->GetFrozenPosition();
	this->_score = 0;
//            this.$this.RelativeContainer.SetActive(true);
//            this.$this.RelativeContainer.get_transform().set_localPosition(new Vector3(0f, -0.06f, 0f));
//            this.$this.Sparks.Play();
//            this.$current = new WaitForSeconds(1.2f);
//            if (!this.$disposing)
//            {
//                this.$PC = 1;
//            }
//            goto Label_059A;
//
//        case 1:
//            this.$locvar0 = this.$this.CloseParticles;
//            this.$locvar1 = 0;
//            while (this.$locvar1 < this.$locvar0.Length)
//            {
//                this.$locvar0[this.$locvar1].Stop();
//                this.$locvar1++;
//            }
//            this.$current = new WaitForSeconds(0.2f);
//            if (!this.$disposing)
//            {
//                this.$PC = 2;
//            }
//            goto Label_059A;
//
//        case 2:
//            this.$this.StarGlow.Play();
//            this.$this.GlowSprite.set_enabled(true);
//            this.$this.GlowSprite.set_color(new Color(1f, 1f, 1f, 0.5f));
//            this.$this.GlowSprite.DOColor(new Color(1f, 1f, 1f, 1f), 0.07f).SetLoops<Tweener>(100, LoopType.Yoyo);
//            this.$current = new WaitForSeconds(0.1f);
//            if (!this.$disposing)
//            {
//                this.$PC = 3;
//            }
//            goto Label_059A;
//
//        case 3:
//            this.<shadowShake>__0 = this.$this.Shadow.get_gameObject().GetComponentOrAdd<ShakeAnimation>();
//            this.<shadowShake>__0.Shake(0.7f, 0.06f, 0.06f, ShakeAnimation.Direction.XY);
//            this.<sa>__0 = this.$this.RelativeContainer.GetComponentOrAdd<ShakeAnimation>();
//            this.<sa>__0.Shake(0.7f, 0.06f, 0.06f, ShakeAnimation.Direction.XY);
//            break;
//
//        case 4:
//            break;
//
//        case 5:
//            this.$locvar3 = this.<toWait>__0.GetEnumerator();
//            num = 0xfffffffd;
//            goto Label_04B6;
//
//        case 6:
//            goto Label_04B6;
//
//        default:
//            goto Label_0598;
//    }
//    if (!this.<sa>__0.IsShakedCompleted)
//    {
//        this.$current = null;
//        if (!this.$disposing)
//        {
//            this.$PC = 4;
//        }
//    }
//    else
//    {
//        this.$this.PlayExplodeParticle();
//        this.<toWait>__0 = new List<ShakeAnimation>();
//        for (int i = 0; i < this.$this._shakePanels.Length; i++)
//        {
//            ShakeAnimation componentOrAdd = this.$this._shakePanels[i].GetComponentOrAdd<ShakeAnimation>();
//            componentOrAdd.Shake(0.4f, 0.2f, 0.2f, ShakeAnimation.Direction.XY);
//            this.<toWait>__0.Add(componentOrAdd);
//        }
	seq.pushBack(CallFunc::create([this]() {this->PlayExplodeParticle(); }));
	seq.pushBack(DelayTime::create(2.5f));

	seq.pushBack(CallFunc::create([this]() {
		for(Cell* current : this->_neigbours) {
//        this.$locvar2 = this.<neighbours>__0.GetEnumerator();
//        try
//        {
//            while (this.$locvar2.MoveNext())
//            {
//                Cell current = this.$locvar2.Current;
//                current.RejectsFallInside();
			current->RejectsFallInside();
			if(current->get_HasItem()) {
				Item* currentItem = current->get_CurrentItem();
				int score = 0;
				bool flag2 = false;
				if(currentItem != nullptr) {
					score = currentItem->GetScore();
					flag2 = currentItem->CanGenerateScoreWithoutExplode();
				}
				if(this->ExplodeBySpecialItem(current)) {
					this->_score += SpecialItem::GetScoreForSpecialItem(currentItem, current);
				}
				else if((current->get_HasItem() && current->get_CurrentItem()->CanGenerateScoreOnEachTryExplode()) && current->get_CurrentItem()->CanGenerateScoreThisTurn()) {
					this->_score += currentItem->GetScore();
				}
				else if((!current->get_HasItem() && flag2) && (this->_score > 0)) {
					this->_score += score;
				}
				this->MarkShouldExplodeAtLeast2(currentItem);
			}
		}
//        finally
//        {
//            this.$locvar2.Dispose();
//        }
//        this.$this.ExplodeMoreIfNeeded();
		this->ExplodeMoreIfNeeded();
//        ScoreManager.RaiseScore(this.$this.GetScore() + this.<score>__0, this.<scorePosition>__0, MatchType.None);
		ScoreManager::RaiseScore(this->GetScore() + this->_score, this->_scorepos, MatchType::None);
//        this.$this.RelativeContainer.SetActive(false);
	}));
//        this.$current = new WaitForSeconds(0.41f);
//        if (!this.$disposing)
//        {
//            this.$PC = 5;
//        }
	Node* sceneroot = CurrentLevel->CurrentLevelBuilder->LevelScene;
	Vector<FiniteTimeAction*> shakeanim;
	for(int i = 0; i < 15; i++)
		shakeanim.pushBack(MoveTo::create(0.025f, sceneroot->getPosition() + Vec2(Mathf::Random::Range(-40.0f, 40.0f), Mathf::Random::Range(-40.0f, 40.0f))));
	shakeanim.pushBack(MoveTo::create(0.025f,sceneroot->getPosition()));
	//sceneroot->runAction(Sequence::create(shakeanim));
	seq.pushBack(TargetedAction::create(sceneroot, Sequence::create(shakeanim)));
//    }
//    goto Label_059A;
//Label_04B6:
//    try
//    {
//        switch (num)
//        {
//            case 6:
//                goto Label_04FA;
//        }
//        while (this.$locvar3.MoveNext())
//        {
//            this.<w>__1 = this.$locvar3.Current;
//        Label_04FA:
//            while (!this.<w>__1.IsShakedCompleted)
//            {
//                this.$current = null;
//                if (!this.$disposing)
//                {
//                    this.$PC = 6;
//                }
//                flag = true;
//                goto Label_059A;
//            }
//        }
//    }
//    finally
//    {
//        if (!flag)
//        {
//        }
//        this.$locvar3.Dispose();
//    }
//    this.$locvar4 = this.<neighbours>__0.GetEnumerator();
//    try
//    {
//        while (this.$locvar4.MoveNext())
//        {
//            this.$locvar4.Current.AcceptsFallInside();
//        }
//    }

	seq.pushBack(CallFunc::create([this]() {
		for(Cell* current : _neigbours)
			current->AcceptsFallInside();
		//    finally
		//    {
		//        this.$locvar4.Dispose();
		//    }
		//    this.$this.RemoveSelf();
		this->RemoveSelf();
	}));
//    this.$PC = -1;
//Label_0598:
//    return false;
//Label_059A:
//    return true;


	// ExplodeCells ended
	seq.pushBack(CallFunc::create([this]() {afterExplodeCells(); }));
	CurrentSpriteRenderer->runAction(Sequence::create(seq));
}

void DoubleBombItem::OnBeforeRemove() {
	BombItem::OnBeforeRemove();
	for (Cell* current : this->ComboMatchGroup->AllCells) {
		current->AcceptsFallInside();
	}
	FallManager::DecreaseWaitingFallBlocker();
}

void DoubleBombItem::AddShakeReferences(std::vector<cocos2d::Node*>* panels)
{
	this->_shakePanels = panels;
}
