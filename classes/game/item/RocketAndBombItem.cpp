#include "RocketAndBombItem.h"
#include "../Grid.h"
#include "../Cell.h"
#include "../Level.h"
#include "../LevelBuilder.h"
#include "../Mathf.h"
#include "../Score.h"
#include "../Match.h"
#include "../ParticleLibrary.h"

#include "cocos2d.h"
USING_NS_CC;

int RocketAndBombItem::Explode(Grid* currentGrid, int x, int y) {
	if (x < 0 || x >= currentGrid->Width || y < 0 || y >= currentGrid->Height) {
		return 0;
	}
	Cell* cell = currentGrid->cell(x, y);
	Item* currentItem = cell->get_CurrentItem();
	int num = 0;
	bool flag = false;
	if (currentItem != nullptr) {
		num = currentItem->GetScore();
		flag = currentItem->CanGenerateScoreWithoutExplode();
	}
	if (this->ExplodeBySpecialItem(cell)) {
		return SpecialItem::GetScoreForSpecialItem(currentItem, cell);
	}
	int num2 = 0;
	if (cell->get_HasItem() && cell->get_CurrentItem()->CanGenerateScoreOnEachTryExplode() && cell->get_CurrentItem()->CanGenerateScoreThisTurn()) {
		num2 += num;
	}
	else if (!cell->get_HasItem() && flag && num > 0) {
		num2 += num;
	}
	if (cell->get_HasItem() && cell->get_CurrentItem()->IsSpecialItem()) {
		dynamic_cast<SpecialItem*>(currentItem)->SpecialItemCanOnlyExplodeSelf = false;
	}
	return num2;
}

/*IEnumerator*/void RocketAndBombItem::DoHorizantalMove(HorizontalRocketItem* horizontalRocketItem, cocos2d::Vec2 position, int height, int xAtExplodeTime, Grid* currentGrid, int y, int width, int direction) {
	Vector<FiniteTimeAction*> seq;
	// case 0:
	//	 this.$locvar0 = new <DoHorizantalMove>c__AnonStorey3();
	//	 this.$locvar0.<>f__ref$0 = this;
	//	 this.$locvar0.xAtExplodeTime = this.xAtExplodeTime;
	//	 this.$locvar0.currentGrid = this.currentGrid;
	//	 this.$locvar0.y = this.y;
	//	 this.<isEven>__0 = this.direction > 0;
	bool isEven = direction > 0;
	//	 this.horizontalRocketItem.SwitchToUseMode(!this.<isEven>__0, this.<isEven>__0, false, false, false);
	horizontalRocketItem->SwitchToUseMode(!isEven, isEven, false, false, false);
	//	 this.<seq>__0 = DOTween.Sequence();
	Vector<FiniteTimeAction*> movseq;
	for(int i = 0; i < width; i++) {
		//<DoHorizantalMove>c__AnonStorey4 storey = new <DoHorizantalMove>c__AnonStorey4 {
		//	 <>f__ref$0 = this,
		//	 <>f__ref$3 = this.$locvar0,
		//	 i = this.direction * i
		//};
		//this.<seq>__0.Append(this.horizontalRocketItem.get_transform().DOMoveX(((this.position.x - ((i != 0) ? (this.direction * 0.8f) : 0f)) + storey.i), ((i != 0) ? 0.07f : 0.001f), false).SetEase<Tweener>(Ease.Linear));
		//if((this.$locvar0.y >= 0) && (this.$locvar0.y < this.height)) {
		//	 this.<seq>__0.AppendCallback(new TweenCallback(storey.<>m__0));
		//}
		movseq.pushBack(MoveTo::create(((i != 0) ? 0.1f : 0.001f), Vec2((position.x - ((i != 0) ? (direction * /*0.8f*/ITEM_SPRITE_SIZE_X) : 0.0f)) + direction*i*ITEM_SPRITE_SIZE_X, horizontalRocketItem->CurrentSpriteRenderer->getPositionY()) ));
		if(y >= 0 && y < height)
			movseq.pushBack(CallFunc::create([this,currentGrid, xAtExplodeTime,y, direction, i]() {
			//int x = this.<>f__ref$3.xAtExplodeTime + this.i;
			//this.<>f__ref$0.$this._score += this.<>f__ref$0.$this.Explode(this.<>f__ref$3.currentGrid, x, this.<>f__ref$3.y);
			int x = xAtExplodeTime + direction*i;
			this->_score += this->Explode(currentGrid, x, y);
		}));
	}
	horizontalRocketItem->CurrentSpriteRenderer->runAction(Sequence::create(movseq));
	//	 this.$current = this.<seq>__0.WaitForCompletion();
	//	 if(!this.$disposing) {
	//		 this.$PC = 1;
	//	 }
	//	 return true;
	//
	seq.pushBack(DelayTime::create((width - 1)*0.1f + 0.001f));
	// case 1:
	// {
	//	 if(this.direction >= 0) {
	//		 Vector3 right = CameraHelper.Right;
	//		 right.x++;
	//		 float num4 = 0.07f * (right.x - this.horizontalRocketItem.get_transform().get_position().x);
	//		 this.horizontalRocketItem.get_transform().DOMoveX(right.x, num4, false).SetEase<Tweener>(Ease.Linear);
	//		 break;
	//	 }
	//	 Vector3 left = CameraHelper.Left;
	//	 left.x--;
	//	 float duration = 0.07f * (this.horizontalRocketItem.get_transform().get_position().x - left.x);
	//	 this.horizontalRocketItem.get_transform().DOMoveX(left.x, duration, false).SetEase<Tweener>(Ease.Linear);
	//	 break;
	// }
	seq.pushBack(CallFunc::create([direction, horizontalRocketItem]() {
		if(direction >= 0) {
			Vec2 right = Vec2::UNIT_X*ITEM_SPRITE_SIZE_X * 12;
			float duration = 0.1f*(right.x / ITEM_SPRITE_SIZE_X - horizontalRocketItem->CurrentSpriteRenderer->getPositionX() / ITEM_SPRITE_SIZE_X);
			horizontalRocketItem->CurrentSpriteRenderer->runAction(MoveTo::create(duration, Vec2(right.x, horizontalRocketItem->CurrentSpriteRenderer->getPositionY())));
		}
		else {
			Vec2 left = -Vec2::UNIT_X*ITEM_SPRITE_SIZE_X*(-3);
			float duration = 0.1f*(horizontalRocketItem->CurrentSpriteRenderer->getPositionX() / ITEM_SPRITE_SIZE_X - left.x/ ITEM_SPRITE_SIZE_X);
			horizontalRocketItem->CurrentSpriteRenderer->runAction(MoveTo::create(duration, Vec2(left.x, horizontalRocketItem->CurrentSpriteRenderer->getPositionY())));
		}
	}));
	// default:
	//	 goto Label_0293;
	//}
	//this.$PC = -1;
	//Label_0293:
	//return false;
	CurrentSpriteRenderer->runAction(Sequence::create(seq));
}

/*IEnumerator*/void RocketAndBombItem::DoVerticalMove(VerticalRocketItem* verticalrocketItem, cocos2d::Vec2 position, int height, int yAtExplodeTime, Grid* currentGrid, int x, int width, int direction) {
	Vector<FiniteTimeAction*> seq;
//case 0:
//	this.$locvar0 = new <DoVerticalMove>c__AnonStorey5();
//	this.$locvar0.<>f__ref$1 = this;
//	this.$locvar0.yAtExplodeTime = this.yAtExplodeTime;
//	this.$locvar0.currentGrid = this.currentGrid;
//	this.$locvar0.x = this.x;
//	this.<isEven>__0 = this.direction > 0;
	bool isEven = direction > 0;
//	this.verticalrocketItem.SwitchToUseMode(!this.<isEven>__0, this.<isEven>__0, false, false, false);
	verticalrocketItem->SwitchToUseMode(!isEven, isEven, false, false, false);
//	this.<seq>__0 = DOTween.Sequence();
	Vector<FiniteTimeAction*> movseq;
	for(int i = 0; i < height; i++) {
//		<DoVerticalMove>c__AnonStorey6 storey = new <DoVerticalMove>c__AnonStorey6 {
//			<>f__ref$1 = this,
//			<>f__ref$5 = this.$locvar0,
//			i = this.direction * i
//		};
//		this.<seq>__0.Append(this.verticalrocketItem.get_transform().DOMoveY(((this.position.y - ((i != 0) ? (this.direction * 0.8f) : 0f)) + storey.i), ((i != 0) ? 0.07f : 0.001f), false).SetEase<Tweener>(Ease.Linear));
//		if((this.$locvar0.x >= 0) && (this.$locvar0.x < this.width)) {
//			this.<seq>__0.AppendCallback(new TweenCallback(storey.<>m__0));
//		}
		movseq.pushBack(MoveTo::create(((i != 0) ? 0.1f : 0.001f), Vec2(verticalrocketItem->CurrentSpriteRenderer->getPositionX(), (position.y - ((i != 0) ? (direction * /*0.8f*/ITEM_SPRITE_SIZE_X) : 0.0f)) + direction*i*ITEM_SPRITE_SIZE_X)));
		if(x >= 0 && x < width)
			movseq.pushBack(CallFunc::create([this, currentGrid, yAtExplodeTime, x, direction, i]() {
			//int y = this.<>f__ref$5.yAtExplodeTime + this.i;
			//this.<>f__ref$1.$this._score += this.<>f__ref$1.$this.Explode(this.<>f__ref$5.currentGrid, this.<>f__ref$5.x, y);
			int y = yAtExplodeTime + direction*i;
			this->_score += this->Explode(currentGrid, x, y);
		}));
	}
//	this.<seq>__0.SetEase<Sequence>(Ease.Linear);
	verticalrocketItem->CurrentSpriteRenderer->runAction(Sequence::create(movseq));
//	this.$current = this.<seq>__0.WaitForCompletion();
//	if(!this.$disposing) {
//		this.$PC = 1;
//	}
//	return true;
	seq.pushBack(DelayTime::create((height - 1)*0.1f + 0.001f));
//case 1:
//{
//	if(this.direction >= 0) {
//		Vector3 top = CameraHelper.Top;
//		top.y++;
//		float num4 = 0.07f * (top.y - this.verticalrocketItem.get_transform().get_position().y);
//		this.verticalrocketItem.get_transform().DOMoveY(top.y, num4, false).SetEase<Tweener>(Ease.Linear);
//		break;
//	}
//	Vector3 bottom = CameraHelper.Bottom;
//	bottom.y--;
//	float duration = 0.07f * (this.verticalrocketItem.get_transform().get_position().y - bottom.y);
//	this.verticalrocketItem.get_transform().DOMoveY(bottom.y, duration, false).SetEase<Tweener>(Ease.Linear);
//	break;
//}
	seq.pushBack(CallFunc::create([direction, verticalrocketItem]() {
		if(direction >= 0) {
			Vec2 top = Vec2::UNIT_Y*ITEM_SPRITE_SIZE_X * 14;
			float duration = 0.1f*(top.y / ITEM_SPRITE_SIZE_X - verticalrocketItem->CurrentSpriteRenderer->getPositionY() / ITEM_SPRITE_SIZE_X);
			verticalrocketItem->CurrentSpriteRenderer->runAction(MoveTo::create(duration, Vec2(verticalrocketItem->CurrentSpriteRenderer->getPositionX(), top.y)));
		}
		else {
			Vec2 bottom = -Vec2::UNIT_Y*ITEM_SPRITE_SIZE_X*(-5);
			float duration = 0.1f*(verticalrocketItem->CurrentSpriteRenderer->getPositionY() / ITEM_SPRITE_SIZE_X - bottom.y / ITEM_SPRITE_SIZE_X);
			verticalrocketItem->CurrentSpriteRenderer->runAction(MoveTo::create(duration, Vec2(verticalrocketItem->CurrentSpriteRenderer->getPositionX(), bottom.y)));
		}
	}));
//default:
//	goto Label_02A0;
	CurrentSpriteRenderer->runAction(Sequence::create(seq));
}

/*IEnumerator*/void RocketAndBombItem::ExplodeCells() {
	isExploded = true;
	Vector<FiniteTimeAction*> seq;

//case 0:
//	AudioManager.Play(AudioTag.ComboRocketBombSpin, PlayMode.Frame, null, 1f);
//	this.$this.InUseObjects.SetActive(true);
//	this.$this.CurrentSpriteRenderer.set_enabled(false);
	this->CurrentSpriteRenderer->setOpacity(0);
	this->__currentGrid = this->get_CurrentCell()->CurrentGrid;
	this->__width = this->__currentGrid->Width;
	this->__height = this->__currentGrid->Height;
	this->__yAtExplodeTime = this->get_CurrentCell()->Y;
	this->__xAtExplodeTime = this->get_CurrentCell()->X;
	this->__originPos = this->get_CurrentCell()->GetFrozenPosition();
//	this.$this._score = this.$this.GetScore();
	this->_score = this->GetScore();
	for(int j = this->__xAtExplodeTime - 1; j <= this->__xAtExplodeTime + 1; j++) {
		if((j >= 0) && (j < this->__width)) {
			for(int k = 0; k < this->__height; k++) {
				this->get_CurrentCell()->CurrentGrid->cell(j,k)->RejectsFallInside();
			}
		}
	}

	for(int m = 0; m < 6; m++) {
		Vec2 position = __originPos;
		int num5 = (m / 2) - 1;
		position.y += num5*ITEM_SPRITE_SIZE_X;
		hrockets[m] = this->CurrentLevel->CurrentLevelBuilder->CreateHorizantalRocket(position);
		hrockets[m]->CurrentSpriteRenderer->setVisible(false);
	}
	//	this.vrocket = new VerticalRocketItem[6];
	for(int n = 0; n < 6; n++) {
		Vec2 vector2 = __originPos;
		int num7 = (n / 2) - 1;
		vector2.x += num7*ITEM_SPRITE_SIZE_X;
		this->vrockets[n] = this->CurrentLevel->CurrentLevelBuilder->CreateVerticallRocket(vector2);
		this->vrockets[n]->CurrentSpriteRenderer->setVisible(false);
	}

//	this.$this.TheAnimator.set_speed(0.25f);
//	DOTween.To(new DOGetter<float>(this.<>m__0), new DOSetter<float>(this.<>m__1), 1f, 0.6f).SetEase<TweenerCore<float, float, FloatOptions>>(Ease.Linear);
//	this.$current = new WaitForSeconds(1.07f);
//	if(!this.$disposing) {
//		this.$PC = 1;
//	}
	PTCLLIB->showRocketBombMix(__originPos);
//	goto next frame;
	seq.pushBack(DelayTime::create(2.033f));
//case 1:
//	ParticlePool.Instance.PlayParticle(ParticlePool.Instance.RocketAndBombParticle, this.originPos, true);
	seq.pushBack(CallFunc::create([this]() {PTCLLIB->showRocketBombExplode(__originPos);}));
//	AudioManager.Play(AudioTag.ComboRocketBombExplode, PlayMode.Frame, null, 1f);
//	this.$current = new WaitForSeconds(0.05f);
//	if(!this.$disposing) {
//		this.$PC = 2;
//	}
//	goto next frame;
	seq.pushBack(DelayTime::create(0.05f));
//
//case 2:
//	hrockets = new HorizontalRocketItem[6];
	seq.pushBack(CallFunc::create([this]() {
		for(int m = 0; m < 6; m++) {
			//Vec2 position = __originPos;
			//int num5 = (m / 2) - 1;
			//position.y += num5*ITEM_SPRITE_SIZE_X;
			//hrockets[m] = this->CurrentLevel->CurrentLevelBuilder->CreateHorizantalRocket(position);
			//hrockets[m].RelativeContainer.SetActive(false);
			hrockets[m]->CurrentSpriteRenderer->setVisible(true);
		}
		//	this.vrocket = new VerticalRocketItem[6];
		for(int n = 0; n < 6; n++) {
			//Vec2 vector2 = __originPos;
			//int num7 = (n / 2) - 1;
			//vector2.x += num7*ITEM_SPRITE_SIZE_X;
			//this->vrockets[n] = this->CurrentLevel->CurrentLevelBuilder->CreateVerticallRocket(vector2);
			//this.vrockets[n].RelativeContainer.SetActive(false);
			this->vrockets[n]->CurrentSpriteRenderer->setVisible(true);
		}
		//	this.<t>__0 = new Task(this.$this.DoVerticalMove(this.vrockets[0], originPos, this.<height>__0, this.<yAtExplodeTime>__0, this.<currentGrid>__0, this.<xAtExplodeTime>__0 - 1, this.<width>__0, 1));
		this->DoVerticalMove(this->vrockets[0], __originPos, __height, __yAtExplodeTime, __currentGrid, __xAtExplodeTime - 1, __width, 1);
		//	new Task(this.$this.DoVerticalMove(this.vrockets[2], originPos, this.<height>__0, this.<yAtExplodeTime>__0, this.<currentGrid>__0, this.<xAtExplodeTime>__0, this.<width>__0, 1));
		this->DoVerticalMove(this->vrockets[2], __originPos, __height, __yAtExplodeTime, __currentGrid, __xAtExplodeTime, __width, 1);
		//	new Task(this.$this.DoVerticalMove(this.vrocket[4], originPos, this.<height>__0, this.<yAtExplodeTime>__0, this.<currentGrid>__0, this.<xAtExplodeTime>__0 + 1, this.<width>__0, 1));
		this->DoVerticalMove(this->vrockets[4], __originPos, __height, __yAtExplodeTime, __currentGrid, __xAtExplodeTime + 1, __width, 1);
		//	new Task(this.$this.DoHorizantalMove(hrockets[4], originPos, this.<height>__0, this.<xAtExplodeTime>__0, this.<currentGrid>__0, this.<yAtExplodeTime>__0 + 1, this.<width>__0, 1));
		this->DoHorizantalMove(hrockets[4], __originPos, __height, __xAtExplodeTime, __currentGrid, __yAtExplodeTime + 1, __width, 1);
		//	new Task(this.$this.DoHorizantalMove(hrockets[2], originPos, this.<height>__0, this.<xAtExplodeTime>__0, this.<currentGrid>__0, this.<yAtExplodeTime>__0, this.<width>__0, 1));
		this->DoHorizantalMove(hrockets[2], __originPos, __height, __xAtExplodeTime, __currentGrid, __yAtExplodeTime, __width, 1);
		//	new Task(this.$this.DoHorizantalMove(hrockets[0], originPos, this.<height>__0, this.<xAtExplodeTime>__0, this.<currentGrid>__0, this.<yAtExplodeTime>__0 - 1, this.<width>__0, 1));
		this->DoHorizantalMove(hrockets[0], __originPos, __height, __xAtExplodeTime, __currentGrid, __yAtExplodeTime - 1, __width, 1);
		//	new Task(this.$this.DoVerticalMove(this.vrockets[5], originPos, this.<height>__0, this.<yAtExplodeTime>__0, this.<currentGrid>__0, this.<xAtExplodeTime>__0 + 1, this.<width>__0, -1));
		this->DoVerticalMove(this->vrockets[5], __originPos, __height, __yAtExplodeTime, __currentGrid, __xAtExplodeTime + 1, __width, -1);
		//	new Task(this.$this.DoVerticalMove(this.vrockets[3], originPos, this.<height>__0, this.<yAtExplodeTime>__0, this.<currentGrid>__0, this.<xAtExplodeTime>__0, this.<width>__0, -1));
		this->DoVerticalMove(this->vrockets[3], __originPos, __height, __yAtExplodeTime, __currentGrid, __xAtExplodeTime, __width, -1);
		//	new Task(this.$this.DoVerticalMove(this.vrockets[1], originPos, this.<height>__0, this.<yAtExplodeTime>__0, this.<currentGrid>__0, this.<xAtExplodeTime>__0 - 1, this.<width>__0, -1));
		this->DoVerticalMove(this->vrockets[1], __originPos, __height, __yAtExplodeTime, __currentGrid, __xAtExplodeTime - 1, __width, -1);
		//	new Task(this.$this.DoHorizantalMove(hrockets[1], originPos, this.<height>__0, this.<xAtExplodeTime>__0, this.<currentGrid>__0, this.<yAtExplodeTime>__0 - 1, this.<width>__0, -1));
		this->DoHorizantalMove(hrockets[1], __originPos, __height, __xAtExplodeTime, __currentGrid, __yAtExplodeTime - 1, __width, -1);
		//	new Task(this.$this.DoHorizantalMove(hrockets[3], originPos, this.<height>__0, this.<xAtExplodeTime>__0, this.<currentGrid>__0, this.<yAtExplodeTime>__0, this.<width>__0, -1));
		this->DoHorizantalMove(hrockets[3], __originPos, __height, __xAtExplodeTime, __currentGrid, __yAtExplodeTime, __width, -1);
		//	new Task(this.$this.DoHorizantalMove(hrockets[5], originPos, this.<height>__0, this.<xAtExplodeTime>__0, this.<currentGrid>__0, this.<yAtExplodeTime>__0 + 1, this.<width>__0, -1));
		this->DoHorizantalMove(hrockets[5], __originPos, __height, __xAtExplodeTime, __currentGrid, __yAtExplodeTime + 1, __width, -1);
		//	this.$this.RocketAndBombParticle1.Stop();
		//	this.$this.RocketAndBombParticle2.Stop();
	}));
//	this.$current = new WaitForSeconds(0.01f);
//	if(!this.$disposing) {
//		this.$PC = 3;
//	}
	seq.pushBack(DelayTime::create(0.01f));
//	goto next frame;
//
//case 3:
//	Object.Destroy(this.$this.InUseAnimation);
//	this.$current = new WaitForSeconds(0.2f);
//	if(!this.$disposing) {
//		this.$PC = 4;
//	}
//	goto next frame;
	seq.pushBack(DelayTime::create(0.04f));
//
//case 4:
	seq.pushBack(CallFunc::create([this]() {
		for(int num8 = 0; num8 < 6; num8++) {
			if((num8 % 2) == 0) {
				hrockets[num8]->Head2TrailParticle->resetSystem(); hrockets[num8]->Head2TrailParticle->setVisible(true);
				vrockets[num8]->Head2TrailParticle->resetSystem(); vrockets[num8]->Head2TrailParticle->setVisible(true);
			}
			else {
				hrockets[num8]->Head1TrailParticle->resetSystem(); hrockets[num8]->Head1TrailParticle->setVisible(true);
				vrockets[num8]->Head1TrailParticle->resetSystem(); vrockets[num8]->Head1TrailParticle->setVisible(true);
			}
		}
	}));
//	break;
//
//	case 5:
//		break;
//[break]
//while(this.<t>__0.Running) {
//	this.$current = null;
//	if(!this.$disposing) {
//		this.$PC = 5;
//	}
//	goto next frame;
//}
	seq.pushBack(DelayTime::create(Mathf::Max(Mathf::Max(Mathf::Max(12 - __xAtExplodeTime, __xAtExplodeTime - (-3)), 14 - __yAtExplodeTime), __yAtExplodeTime - (-5))*0.1f - 0.01f - 0.04f));
//this.$this.RelativeContainer.SetActive(false);
	seq.pushBack(CallFunc::create([this]() {
		for(int i = 0; i < 6; i++) {
			//new Task(hrockets[i].Die());
			hrockets[i]->Die();
		}
	}));
//this.$current = null;
//if(!this.$disposing) {
//	this.$PC = 6;
//}
//goto next frame;
//
//case 6:
	seq.pushBack(CallFunc::create([this]() {
		ScoreManager::RaiseScore(this->_score, __originPos, MatchType::None);
		for(int num10 = 0; num10 < 6; num10++) {
			//new Task(this.vrocket[num10].Die());
			this->vrockets[num10]->Die();
		}
		for(int num11 = this->__xAtExplodeTime - 1; num11 <= this->__xAtExplodeTime + 1; num11++) {
			if((num11 >= 0) && (num11 < this->__width)) {
				for(int num12 = 0; num12 < this->__height; num12++) {
					this->__currentGrid->cell(num11, num12)->AcceptsFallInside();
				}
			}
		}
		std::vector<Cell*>& allcells = this->ComboMatchGroup->AllCells;
		for(int num13 = 0; num13 < (int)allcells.size(); num13++) {
			allcells[num13]->AcceptsFallInside();
		}
		this->RemoveSelf();
	}));
//	this.$PC = -1;
//	goto Label_0874;
//
//default:
//	goto Label_0874;
//}
//Label_0874:
//return false;
//next frame:
//return true;

	// ExplodeCells ended
	seq.pushBack(CallFunc::create([this]() {afterExplodeCells(); }));
	CurrentSpriteRenderer->runAction(Sequence::create(seq));
}
