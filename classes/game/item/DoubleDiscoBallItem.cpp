#include "DoubleDiscoBallItem.h"
#include "../Grid.h"
#include "../Cell.h"
#include "../FallManager.h"
#include "../ParticleLibrary.h"
#include "../Score.h"

USING_NS_CC;

std::map<int, std::set<Cell*>> DoubleDiscoBallItem::GetCircles(Grid* grid, Cell* centerPoint) {
	std::vector<std::vector<Vec2>> Offsets; std::vector<Vec2> fooVector;
	fooVector.clear(); fooVector.push_back(Vec2(-1, -1)); fooVector.push_back(Vec2(-1, 0)); fooVector.push_back(Vec2(-1, 1)); fooVector.push_back(Vec2(0, -1)); fooVector.push_back(Vec2(0, 1)); fooVector.push_back(Vec2(1, -1)); fooVector.push_back(Vec2(1, 0)); fooVector.push_back(Vec2(1, 1)); Offsets.push_back(fooVector);
	fooVector.clear(); fooVector.push_back(Vec2(-2, -1)); fooVector.push_back(Vec2(-2, 0)); fooVector.push_back(Vec2(-2, 1)); fooVector.push_back(Vec2(-1, -2)); fooVector.push_back(Vec2(-1, 2)); fooVector.push_back(Vec2(0, -2)); fooVector.push_back(Vec2(0, 2)); fooVector.push_back(Vec2(1, -2)); fooVector.push_back(Vec2(1, 2)); fooVector.push_back(Vec2(2, -1)); fooVector.push_back(Vec2(2, 0)); fooVector.push_back(Vec2(2, 1)); Offsets.push_back(fooVector);
	fooVector.clear(); fooVector.push_back(Vec2(-3, -1)); fooVector.push_back(Vec2(-3, 0)); fooVector.push_back(Vec2(-3, 1)); fooVector.push_back(Vec2(-2, -2)); fooVector.push_back(Vec2(-2, 2)); fooVector.push_back(Vec2(-1, -3)); fooVector.push_back(Vec2(-1, 3)); fooVector.push_back(Vec2(0, -3)); fooVector.push_back(Vec2(0, 3)); fooVector.push_back(Vec2(1, -3)); fooVector.push_back(Vec2(1, 3)); fooVector.push_back(Vec2(2, -2)); fooVector.push_back(Vec2(2, 2)); fooVector.push_back(Vec2(3, -1)); fooVector.push_back(Vec2(3, 0)); fooVector.push_back(Vec2(3, 1)); Offsets.push_back(fooVector);
	fooVector.clear(); fooVector.push_back(Vec2(-4, -1)); fooVector.push_back(Vec2(-4, 0)); fooVector.push_back(Vec2(-4, 1)); fooVector.push_back(Vec2(-3, -3)); fooVector.push_back(Vec2(-3, -2)); fooVector.push_back(Vec2(-3, 2)); fooVector.push_back(Vec2(-3, 3)); fooVector.push_back(Vec2(-2, -3)); fooVector.push_back(Vec2(-2, 3)); fooVector.push_back(Vec2(-1, -4)); fooVector.push_back(Vec2(-1, 4)); fooVector.push_back(Vec2(0, -4)); fooVector.push_back(Vec2(0, 4)); fooVector.push_back(Vec2(1, -4)); fooVector.push_back(Vec2(1, 4)); fooVector.push_back(Vec2(2, -3)); fooVector.push_back(Vec2(2, 3)); fooVector.push_back(Vec2(3, -3)); fooVector.push_back(Vec2(3, -2)); fooVector.push_back(Vec2(3, 2)); fooVector.push_back(Vec2(3, 3)); fooVector.push_back(Vec2(4, -1)); fooVector.push_back(Vec2(4, 0)); fooVector.push_back(Vec2(4, 1)); Offsets.push_back(fooVector);
	fooVector.clear(); fooVector.push_back(Vec2(-5, -2)); fooVector.push_back(Vec2(-5, -1)); fooVector.push_back(Vec2(-5, 0)); fooVector.push_back(Vec2(-5, 1)); fooVector.push_back(Vec2(-5, 2)); fooVector.push_back(Vec2(-4, -3)); fooVector.push_back(Vec2(-4, -2)); fooVector.push_back(Vec2(-4, 2)); fooVector.push_back(Vec2(-4, 3)); fooVector.push_back(Vec2(-3, -4)); fooVector.push_back(Vec2(-3, 4)); fooVector.push_back(Vec2(-2, -5)); fooVector.push_back(Vec2(-2, -4)); fooVector.push_back(Vec2(-2, 4)); fooVector.push_back(Vec2(-2, 5)); fooVector.push_back(Vec2(-1, -5)); fooVector.push_back(Vec2(-1, 5)); fooVector.push_back(Vec2(0, -5)); fooVector.push_back(Vec2(0, 5)); fooVector.push_back(Vec2(1, -5)); fooVector.push_back(Vec2(1, 5)); fooVector.push_back(Vec2(2, -5)); fooVector.push_back(Vec2(2, -4)); fooVector.push_back(Vec2(2, 4)); fooVector.push_back(Vec2(2, 5)); fooVector.push_back(Vec2(3, -4)); fooVector.push_back(Vec2(3, 4)); fooVector.push_back(Vec2(4, -3)); fooVector.push_back(Vec2(4, -2)); fooVector.push_back(Vec2(4, 2)); fooVector.push_back(Vec2(4, 3)); fooVector.push_back(Vec2(5, -2)); fooVector.push_back(Vec2(5, -1)); fooVector.push_back(Vec2(5, 0)); fooVector.push_back(Vec2(5, 1)); fooVector.push_back(Vec2(5, 2)); Offsets.push_back(fooVector);
	fooVector.clear(); fooVector.push_back(Vec2(-6, -2)); fooVector.push_back(Vec2(-6, -1)); fooVector.push_back(Vec2(-6, 0)); fooVector.push_back(Vec2(-6, 1)); fooVector.push_back(Vec2(-6, 2)); fooVector.push_back(Vec2(-5, -4)); fooVector.push_back(Vec2(-5, -3)); fooVector.push_back(Vec2(-5, 3)); fooVector.push_back(Vec2(-5, 4)); fooVector.push_back(Vec2(-4, -5)); fooVector.push_back(Vec2(-4, -4)); fooVector.push_back(Vec2(-4, 4)); fooVector.push_back(Vec2(-4, 5)); fooVector.push_back(Vec2(-3, -5)); fooVector.push_back(Vec2(-3, 5)); fooVector.push_back(Vec2(-2, -6)); fooVector.push_back(Vec2(-2, 6)); fooVector.push_back(Vec2(-1, -6)); fooVector.push_back(Vec2(-1, 6)); fooVector.push_back(Vec2(0, -6)); fooVector.push_back(Vec2(0, 6)); fooVector.push_back(Vec2(1, -6)); fooVector.push_back(Vec2(1, 6)); fooVector.push_back(Vec2(2, -6)); fooVector.push_back(Vec2(2, 6)); fooVector.push_back(Vec2(3, -5)); fooVector.push_back(Vec2(3, 5)); fooVector.push_back(Vec2(4, -5)); fooVector.push_back(Vec2(4, -4)); fooVector.push_back(Vec2(4, 4)); fooVector.push_back(Vec2(4, 5)); fooVector.push_back(Vec2(5, -4)); fooVector.push_back(Vec2(5, -3)); fooVector.push_back(Vec2(5, 3)); fooVector.push_back(Vec2(5, 4)); fooVector.push_back(Vec2(6, -2)); fooVector.push_back(Vec2(6, -1)); fooVector.push_back(Vec2(6, 0)); fooVector.push_back(Vec2(6, 1)); fooVector.push_back(Vec2(6, 2)); Offsets.push_back(fooVector);
	fooVector.clear(); fooVector.push_back(Vec2(-7, -2)); fooVector.push_back(Vec2(-7, -1)); fooVector.push_back(Vec2(-7, 0)); fooVector.push_back(Vec2(-7, 1)); fooVector.push_back(Vec2(-7, 2)); fooVector.push_back(Vec2(-6, -4)); fooVector.push_back(Vec2(-6, -3)); fooVector.push_back(Vec2(-6, 3)); fooVector.push_back(Vec2(-6, 4)); fooVector.push_back(Vec2(-5, -5)); fooVector.push_back(Vec2(-5, 5)); fooVector.push_back(Vec2(-4, -6)); fooVector.push_back(Vec2(-4, 6)); fooVector.push_back(Vec2(-3, -6)); fooVector.push_back(Vec2(-3, 6)); fooVector.push_back(Vec2(-2, -7)); fooVector.push_back(Vec2(-2, 7)); fooVector.push_back(Vec2(-1, -7)); fooVector.push_back(Vec2(-1, 7)); fooVector.push_back(Vec2(0, -7)); fooVector.push_back(Vec2(0, 7)); fooVector.push_back(Vec2(1, -7)); fooVector.push_back(Vec2(1, 7)); fooVector.push_back(Vec2(2, -7)); fooVector.push_back(Vec2(2, 7)); fooVector.push_back(Vec2(3, -6)); fooVector.push_back(Vec2(3, 6)); fooVector.push_back(Vec2(4, -6)); fooVector.push_back(Vec2(4, 6)); fooVector.push_back(Vec2(5, -5)); fooVector.push_back(Vec2(5, 5)); fooVector.push_back(Vec2(6, -4)); fooVector.push_back(Vec2(6, -3)); fooVector.push_back(Vec2(6, 3)); fooVector.push_back(Vec2(6, 4)); fooVector.push_back(Vec2(7, -2)); fooVector.push_back(Vec2(7, -1)); fooVector.push_back(Vec2(7, 0)); fooVector.push_back(Vec2(7, 1)); fooVector.push_back(Vec2(7, 2)); Offsets.push_back(fooVector);
	fooVector.clear(); fooVector.push_back(Vec2(-8, -2)); fooVector.push_back(Vec2(-8, -1)); fooVector.push_back(Vec2(-8, 0)); fooVector.push_back(Vec2(-8, 1)); fooVector.push_back(Vec2(-8, 2)); fooVector.push_back(Vec2(-7, -4)); fooVector.push_back(Vec2(-7, -3)); fooVector.push_back(Vec2(-7, 3)); fooVector.push_back(Vec2(-7, 4)); fooVector.push_back(Vec2(-6, -5)); fooVector.push_back(Vec2(-6, 5)); fooVector.push_back(Vec2(-5, -6)); fooVector.push_back(Vec2(-5, 6)); fooVector.push_back(Vec2(-4, -7)); fooVector.push_back(Vec2(-4, 7)); fooVector.push_back(Vec2(-3, -7)); fooVector.push_back(Vec2(-3, 7)); fooVector.push_back(Vec2(-2, -8)); fooVector.push_back(Vec2(-2, 8)); fooVector.push_back(Vec2(-1, -8)); fooVector.push_back(Vec2(-1, 8)); fooVector.push_back(Vec2(0, -8)); fooVector.push_back(Vec2(0, 8)); fooVector.push_back(Vec2(1, -8)); fooVector.push_back(Vec2(1, 8)); fooVector.push_back(Vec2(2, -8)); fooVector.push_back(Vec2(2, 8)); fooVector.push_back(Vec2(3, -7)); fooVector.push_back(Vec2(3, 7)); fooVector.push_back(Vec2(4, -7)); fooVector.push_back(Vec2(4, 7)); fooVector.push_back(Vec2(5, -6)); fooVector.push_back(Vec2(5, 6)); fooVector.push_back(Vec2(6, -5)); fooVector.push_back(Vec2(6, 5)); fooVector.push_back(Vec2(7, -4)); fooVector.push_back(Vec2(7, -3)); fooVector.push_back(Vec2(7, 3)); fooVector.push_back(Vec2(7, 4)); fooVector.push_back(Vec2(8, -2)); fooVector.push_back(Vec2(8, -1)); fooVector.push_back(Vec2(8, 0)); fooVector.push_back(Vec2(8, 1)); fooVector.push_back(Vec2(8, 2)); Offsets.push_back(fooVector);
	fooVector.clear(); fooVector.push_back(Vec2(-8, -4)); fooVector.push_back(Vec2(-8, -3)); fooVector.push_back(Vec2(-8, 3)); fooVector.push_back(Vec2(-8, 4)); fooVector.push_back(Vec2(-7, -6)); fooVector.push_back(Vec2(-7, -5)); fooVector.push_back(Vec2(-7, 5)); fooVector.push_back(Vec2(-7, 6)); fooVector.push_back(Vec2(-6, -7)); fooVector.push_back(Vec2(-6, -6)); fooVector.push_back(Vec2(-6, 6)); fooVector.push_back(Vec2(-6, 7)); fooVector.push_back(Vec2(-5, -7)); fooVector.push_back(Vec2(-5, 7)); fooVector.push_back(Vec2(-4, -8)); fooVector.push_back(Vec2(-4, 8)); fooVector.push_back(Vec2(-3, -8)); fooVector.push_back(Vec2(-3, 8)); fooVector.push_back(Vec2(3, -8)); fooVector.push_back(Vec2(3, 8)); fooVector.push_back(Vec2(4, -8)); fooVector.push_back(Vec2(4, 8)); fooVector.push_back(Vec2(5, -7)); fooVector.push_back(Vec2(5, 7)); fooVector.push_back(Vec2(6, -7)); fooVector.push_back(Vec2(6, -6)); fooVector.push_back(Vec2(6, 6)); fooVector.push_back(Vec2(6, 7)); fooVector.push_back(Vec2(7, -6)); fooVector.push_back(Vec2(7, -5)); fooVector.push_back(Vec2(7, 5)); fooVector.push_back(Vec2(7, 6)); fooVector.push_back(Vec2(8, -4)); fooVector.push_back(Vec2(8, -3)); fooVector.push_back(Vec2(8, 3)); fooVector.push_back(Vec2(8, 4)); Offsets.push_back(fooVector);
	fooVector.clear(); fooVector.push_back(Vec2(-8, -8)); fooVector.push_back(Vec2(-8, -7)); fooVector.push_back(Vec2(-8, -6)); fooVector.push_back(Vec2(-8, -5)); fooVector.push_back(Vec2(-8, 5)); fooVector.push_back(Vec2(-8, 6)); fooVector.push_back(Vec2(-8, 7)); fooVector.push_back(Vec2(-8, 8)); fooVector.push_back(Vec2(-7, -8)); fooVector.push_back(Vec2(-7, -7)); fooVector.push_back(Vec2(-7, 7)); fooVector.push_back(Vec2(-7, 8)); fooVector.push_back(Vec2(-6, -8)); fooVector.push_back(Vec2(-6, 8)); fooVector.push_back(Vec2(-5, -8)); fooVector.push_back(Vec2(-5, 8)); fooVector.push_back(Vec2(5, -8)); fooVector.push_back(Vec2(5, 8)); fooVector.push_back(Vec2(6, -8)); fooVector.push_back(Vec2(6, 8)); fooVector.push_back(Vec2(7, -8)); fooVector.push_back(Vec2(7, -7)); fooVector.push_back(Vec2(7, 7)); fooVector.push_back(Vec2(7, 8)); fooVector.push_back(Vec2(8, -8)); fooVector.push_back(Vec2(8, -7)); fooVector.push_back(Vec2(8, -6)); fooVector.push_back(Vec2(8, -5)); fooVector.push_back(Vec2(8, 5)); fooVector.push_back(Vec2(8, 6)); fooVector.push_back(Vec2(8, 7)); fooVector.push_back(Vec2(8, 8)); Offsets.push_back(fooVector);

	std::map<int, std::set<Cell*>> dictionary;
	for(int i = 0; i < (int)Offsets.size(); i++) {
		std::set<Cell*> __set;
		std::vector<Vec2> __vec = Offsets[i];
		for(int j = 0; j < (int)__vec.size(); j++) {
			Vec2 offsetpos = __vec[j];
			int x = centerPoint->X + ((int)offsetpos.x);
			int y = centerPoint->Y + ((int)offsetpos.y);
			if((((x < grid->Width) && (y < grid->Height)) && (x >= 0)) && (y >= 0)) {
				Cell* __item = grid->cell(x, y);
				if(__item != nullptr)
					__set.insert(__item);
			}
		}
		if((int)__set.size() > 0)
			dictionary.insert({i, __set});
	}
	return dictionary;
}

/*IEnumerator*/void DoubleDiscoBallItem::ExplodeCells() {
	isExploded = true;
	Vector<FiniteTimeAction*> seq;
//uint num = (uint) this.$PC;
//this.$PC = -1;
//switch(num) {
//case 0:
//	AudioManager.Play(AudioTag.ComboDiscoDisco, PlayMode.Frame, null, 1f);
//	this.<currentGrid>__0 = this.$this.CurrentCell.CurrentGrid;
//	this.<position>__0 = this.$this.CurrentCell.GetFrozenPosition();
//	this.<circles>__0 = this.<currentGrid>__0.GetCircles(this.$this.CurrentCell);
//	this.<score>__0 = this.$this.GetScore();
	this->__currentGrid = this->get_CurrentCell()->CurrentGrid;
	this->originPos = this->get_CurrentCell()->GetFrozenPosition();
	this->__circle=this->GetCircles(__currentGrid, this->get_CurrentCell());
	this->__score = this->GetScore();
//	this.$current = null;
//	if(!this.$disposing) {
//		this.$PC = 1;
//	}
//	goto next frame;
//
//case 1:
	seq.pushBack(CallFunc::create([this]() {PTCLLIB->showDiscoDiscoExplode(this->originPos); }));
//	this.$this.BackgroundSprite.get_transform().set_position(Vector3.get_zero());
//	this.$this.BackgroundSprite.get_transform().set_localScale(new Vector3(CameraHelper.Width, CameraHelper.Height, 1f));
//	this.$this._gradientMaterial = this.$this.BackgroundSprite.get_material();
//	this.$this._gradientMaterial.SetFloat("_scaleX", CameraHelper.Width);
//	this.$this._gradientMaterial.SetFloat("_scaleY", CameraHelper.Height);
//	this.$this._gradientMaterial.SetFloat("_x", (this.<position>__0.x + (CameraHelper.Width * 0.5f)) / CameraHelper.Width);
//	this.$this._gradientMaterial.SetFloat("_y", (this.<position>__0.y + (CameraHelper.Height * 0.5f)) / CameraHelper.Height);
//	this.$this._gradientMaterial.SetFloat("_slide", 0.2f);
//	this.$this._gradientMaterial.SetFloat("_alpha", 0f);
//	this.$this.ExplodeContainer.SetActive(true);
//	this.$this.BackgroundSprite.get_gameObject().SetActive(true);
//	DOVirtual.Float(0f, 0.6f, 0.35f, new TweenCallback<float>(this.<>m__0)).SetEase<Tweener>(Ease.Linear);
//	this.$current = new WaitForSeconds(2.3f);
	seq.pushBack(DelayTime::create(3.167f));
	seq.pushBack(CallFunc::create([]() {FallManager::IncreaseWaitingFallBlocker(); }));
//	if(!this.$disposing) {
//		this.$PC = 2;
//	}
//	goto next frame;
//
//case 2:
//	this.$this.ExplodeParticle.Play();
//	DOVirtual.Float(0.2f, -8f, 1.7f, new TweenCallback<float>(this.<>m__1)).SetEase<Tweener>(Ease.Linear);
//	this.$this.RingParticle.Play();
//	this.$this.CurrentSpriteRenderer.set_enabled(false);
//	this.<i>__1 = 0;
//	goto Label_0451;
//
//case 3:
	for(std::map<int, std::set<Cell*>>::iterator iter = __circle.begin(); iter != __circle.end(); iter++) {
//	if(this.<circles>__0.TryGetValue(this.<i>__1, out this.<ccells>__2)) {
//		this.$locvar0 = this.<ccells>__2.GetEnumerator();
		seq.pushBack(CallFunc::create([this, iter]() {
		for(Cell* current : iter->second) {
//		try {
//			while(this.$locvar0.MoveNext()) {
//				Cell current = this.$locvar0.Current;
			if(current->get_HasItem()) {
				Item* currentItem = current->get_CurrentItem();
				if(currentItem->IsSpecialItem())
					dynamic_cast<SpecialItem*>(currentItem)->SpecialItemCanOnlyExplodeSelf = true;
				int score = 0;
				bool flag = false;
				if(currentItem != nullptr) {
					score = currentItem->GetScore();
					flag = currentItem->CanGenerateScoreWithoutExplode();
				}
				if(this->ExplodeBySpecialItem(current))
					this->__score += SpecialItem::GetScoreForSpecialItem(currentItem, current);
				else if((current->get_HasItem() && current->get_CurrentItem()->CanGenerateScoreOnEachTryExplode()) && current->get_CurrentItem()->CanGenerateScoreThisTurn())
					this->__score += score;
				else if((!current->get_HasItem() && flag) && (this->__score > 0))
					this->__score += score;
				if((currentItem != nullptr) && currentItem->IsSpecialItem())
					dynamic_cast<SpecialItem*>(currentItem)->SpecialItemCanOnlyExplodeSelf = false;
			}
		}
		}));
//		finally
//		{
//			this.$locvar0.Dispose();
//		}
//		break;
//	}
//	break;
//
//default:
//	goto end;
//}
//this.<i>__1++;
//abel_0451:
//if(this.<i>__1 <= 10) {
//	this.$current = new WaitForSeconds(0.11f);
//	if(!this.$disposing) {
//		this.$PC = 3;
//	}
//	goto next frame;
//}
		seq.pushBack(DelayTime::create(0.11f));
	}

	seq.pushBack(CallFunc::create([this]() {
		ScoreManager::RaiseScore(this->__score, this->originPos, MatchType::None);
		for(Cell* oncell : this->ComboMatchGroup->AllCells)
			oncell->AcceptsFallInside();
		FallManager::DecreaseWaitingFallBlocker();
		if(this->CurrentSpriteRenderer->isVisible())
			this->WaitForAnimationComplete();
		else
			this->RemoveSelf();
	}));
//this.$PC = -1;
	// ExplodeCells ended
	seq.pushBack(CallFunc::create([this]() {afterExplodeCells(); }));
	CurrentSpriteRenderer->runAction(Sequence::create(seq));
}

/*IEnumerator*/void DoubleDiscoBallItem::WaitForAnimationComplete() {
//uint num = (uint) this.$PC;
//this.$PC = -1;
//switch(num) {
//case 0:
//	this.$current = new WaitForSeconds(0.5f);
//	if(!this.$disposing) {
//		this.$PC = 1;
//	}
//	return true;
//
//case 1:
//	this.$this.RemoveSelf();
//	this.$PC = -1;
//	break;
//}
//return false;
	CurrentSpriteRenderer->runAction(Sequence::createWithTwoActions(DelayTime::create(0.5f), RemoveSelf::create()));
}
