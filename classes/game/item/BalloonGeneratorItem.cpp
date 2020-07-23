#include "BalloonGeneratorItem.h"
#include "../Cell.h"
#include "../Level.h"
#include "../ItemGeneratorController.h"
#include "../Extension.h"
#include "../LevelBuilder.h"
#include "../ParticleLibrary.h"
#include "../ImageLibrary.h"

USING_NS_CC;

BalloonGeneratorItem::BalloonGeneratorItem() {
	Renderer = Sprite::create();
	Renderer->retain();
}

BalloonGeneratorItem::~BalloonGeneratorItem() {
	Renderer->release();
}
void BalloonGeneratorItem::SetupItem() {
	_sprite = PTCLLIB->cloneNodeForNodeModel(PTCLLIB->getBalloonGenNode());
	Renderer->addChild(_sprite);
	_sprite->setPosition(0, -10);
	_animation = PTCLLIB->getBalloonGenAnim()->clone();
	_sprite->runAction(_animation);
	_animation->play("idle", false);
}

void BalloonGeneratorItem::RemoveSelf() {
	GeneratorBasedItem::RemoveSelf();

	Renderer->removeFromParentAndCleanup(true);
}

void BalloonGeneratorItem::Start() {
	this->GenerateCount = 1;
	this->GenerateInverval = 1;
//	this->_throwHash = Animator.StringToHash("Base Layer.BalloonGeneratorThrow");
//	this->_sleepHash = Animator.StringToHash("Base Layer.BalloonGeneratorSleep");
}

void BalloonGeneratorItem::OnItemCreated(Level* currentLevel) {
	GeneratorBasedItem::OnItemCreated(currentLevel);
	this->GenerateItemType = ItemType::Balloon;
	ItemGeneratorController::getInstance()->RegisterGenerator(this->GenerateItemType, this);
}

bool BalloonGeneratorItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame())	{
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	GeneratorBasedItem::StartGeneratingItems();
	return false;
}

void BalloonGeneratorItem::Sleep() {
//	this->CurrentAnimator.Play(this->_sleepHash, 0, 0f);
	_animation->play("sleep", false);
	this->_isSleeping = true;
}

Cell* BalloonGeneratorItem::GetRandomCell() {
	return ItemGeneratorController::getInstance()->GetRandomCell();
}

void BalloonGeneratorItem::PlayThrowAnimation(std::vector<Cell*>* targetCells) {
	if(targetCells == nullptr || targetCells->size() <= 0) {
		return;
	}
	int count = targetCells->size();
	for(int i = 0; i < count; i++) {
//		GameObject gameObject = this->CurrentLevel->CurrentLevelBuilder->BalloonGeneratorThrowAnimation->Spawn();
//		BalloonGeneratorThrowAnimation component = gameObject.GetComponent<BalloonGeneratorThrowAnimation>();
//		component.Prepare(this->CurrentCell, targetCells[i], this->_direction, new Action<Cell>(this->OnThrowAnimationComplete));
		Sprite* _balloon = Sprite::createWithTexture(IMGLIB->Balloon->getTexture());
		Renderer->getParent()->addChild(_balloon, ITEM_BUBBLE_ZORDER_BASE + 20);
		_balloon->setVisible(false);
		_balloon->setScale(0.4f);
		Vector<FiniteTimeAction*> seq;

		Cell* from = this->get_CurrentCell();
		Cell* to = targetCells->at(i);
		//void Prepare(Cell from, Cell to, int direction, Action<Cell> onThrowAnimationComplete) {
		//<Prepare>c__AnonStorey1 storey = new <Prepare>c__AnonStorey1 {
		//	$this = this
		//};
		//this.Reset();
		//this._to = to;
		//this._direction = direction;
		//this._onThrowAnimationComplete = onThrowAnimationComplete;
		Vec2 startpos = from->GetFrozenPosition();
		startpos += Vec2(0.5f*ITEM_SPRITE_SIZE_X, 0.5f*ITEM_SPRITE_SIZE_X);
		Vec2 endpos = to->GetFrozenPosition();
		float _startMoveX = 1.5f;
		startpos.y += 0.08f*ITEM_SPRITE_SIZE_X;
		if(this->_direction == 0) {
			startpos.x += 0.15f*ITEM_SPRITE_SIZE_X;
			_startMoveX = (_startMoveX >= 0.0f) ? _startMoveX : -_startMoveX;
		}
		else {
			startpos.x -= 0.15f*ITEM_SPRITE_SIZE_X;
			_startMoveX = (_startMoveX <= 0.0f) ? _startMoveX : -_startMoveX;
		}
		//this.Container.get_transform().set_position(startpos);
		//Vector3 vector3 = new Vector3(startpos.x + _startMoveX, startpos.y + 1.5f, 0f);
		//Vector2 vector4 = new Vector2(_startMoveX, 1.5f);
		//float num = vector4.get_magnitude() / 0.25f;
		//if(this._sequence != null) {
		//	TweenExtensions.Kill(this._sequence, true);
		//}
		//this._sequence = DOTween.Sequence();
		//Vector3 vector5 = (Vector3)((endpos - vector3) * 0.3f);
		//float num2 = vector5.get_magnitude() * 2f;
		//Vector3 vector6 = new Vector3(-vector5.y, vector5.x);
		//Vector3 control = new Vector3(vector3.x + (vector5.x * 1f), vector3.y + (vector5.y * 1f));
		//control += (Vector3)((vector6.get_normalized() * num2) * ((vector5.y <= 0f) ? ((float)1) : ((float)(-1))));
		//Vector3[] vectorArray = new Vector3[50];
		//float[] numArray = new float[50];
		//for(int i = 1; i <= 50; i++) {
		//	float t = ((float)i) / 50f;
		//	float num5 = ((float)(i - 1)) / 50f;
		//	Vector3 vector8 = this.GetQuadraticBezierPosition(vector3, control, endpos, t);
		//	Vector3 vector9 = this.GetQuadraticBezierPosition(vector3, control, endpos, num5);
		//	float num6 = (vector8 - vector9).get_magnitude();
		//	numArray[i - 1] = num6 / num;
		//	vectorArray[i - 1] = vector8;
		//}
		//float num7 = 0f;
		//for(int j = 0; j < 50; j++) {
		//	TweenSettingsExtensions.Insert(this._sequence, 0.32f + num7, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMove(this.Container.get_transform(), vectorArray[j], numArray[j], false), 1));
		//	num7 += numArray[j];
		//}
		//TweenSettingsExtensions.InsertCallback(this._sequence, 0.2f, new TweenCallback(storey, (IntPtr) this.<>m__0));
		seq.pushBack(DelayTime::create(0.2f));
		float _flyperiod = endpos.distance(startpos) / ITEM_SPRITE_SIZE_X*0.12f;
		seq.pushBack(CallFunc::create([this, _balloon,_flyperiod]() {_balloon->runAction(EaseQuadraticActionOut::create(ScaleTo::create(_flyperiod,1))); }));
		seq.pushBack(TargetedAction::create(_balloon, Sequence::create(
			Place::create(startpos),
			Show::create(),
			EaseSineInOut::create(MoveTo::create(_flyperiod, endpos)),
			RemoveSelf::create(),
			nullptr)));
		//void <>m__0() {this->ShadowSprite.set_enabled(true);}
		//TweenSettingsExtensions.InsertCallback(this._sequence, 0.2f, new TweenCallback(storey, (IntPtr) this.<>m__1));
		// void <>m__1() {this->TrailParticle.get_emission().set_enabled(true); this->TrailParticle.Play(); this->TailSpriteRenderer.set_enabled(true); }
		//TweenSettingsExtensions.InsertCallback(this._sequence, 0.07f, new TweenCallback(storey, (IntPtr) this.<>m__2));
		//void <>m__2() {
		//	ShortcutExtensions.DOScale(this->Container.get_transform(), 1f, 0.4f);
		//	Vector3 vector = this->Container.get_transform().get_position();
		//	TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMove(this->Container.get_transform(), new Vector3(vector.x + this->_startMoveX, vector.y + 1.5f, 0f), 0.25f, false), 1);
		//	TweenSettingsExtensions.OnComplete<Tweener>(TweenSettingsExtensions.SetDelay<Tweener>(ShortcutExtensions.DOScaleX(this->BalloonTransform, 0.9f, 0.1f), 0f), new TweenCallback(this, (IntPtr) this.<>m__5));
		//	void <>m__5() {
		//		TweenSettingsExtensions.SetDelay<Tweener>(ShortcutExtensions.DOScaleX(this->BalloonTransform, 1.1f, 0.1f), 0.2f);
		//		TweenSettingsExtensions.SetDelay<Tweener>(ShortcutExtensions.DOScaleY(this->BalloonTransform, 0.9f, 0.1f), 0.2f);
		//	}
		//	TweenSettingsExtensions.SetDelay<Tweener>(ShortcutExtensions.DOScaleX(this->BalloonTransform, 1f, 0.2f), 0.5f);
		//	TweenSettingsExtensions.SetDelay<Tweener>(ShortcutExtensions.DOScaleY(this->BalloonTransform, 1f, 0.2f), 0.5f);
		//}
		//this.BalloonParentTransform.get_transform().set_localScale(Vector3.get_one());
		//storey.currentPos = this.Container.get_transform().get_position();
		//storey.isStarted = false;
		//float num9 = Time.get_realtimeSinceStartup();
		//storey.st = ((num9 + 0.25f) + 0.07f) - 0.3f;
		//TweenSettingsExtensions.OnUpdate<Sequence>(this._sequence, new TweenCallback(storey, (IntPtr) this.<>m__3));
		// void <>m__3() {
		//	if(!this.isStarted) {
		//		this.isStarted = true;
		//	}
		//	if(Time.get_realtimeSinceStartup() >= this.st) {
		//		this.prevPos = this.currentPos;
		//		this.currentPos = this->Container.get_transform().get_position();
		//		Vector3 vector = this.currentPos - this.prevPos;
		//		float f = 57.29578f * Mathf.Atan2(vector.y, vector.x);
		//		if(!float.IsNaN(f)) {
		//			Quaternion quaternion2 = new Quaternion();
		//			quaternion2.set_eulerAngles(new Vector3(0f, 0f, f));
		//			Quaternion quaternion = quaternion2;
		//			this->Container.get_transform().set_rotation(Quaternion.Slerp(this->Container.get_transform().get_rotation(), quaternion, 0.8f));
		//			Vector3 vector2 = this->BalloonTransform.get_position();
		//			vector2.y -= 0.6f;
		//			this->ShadowSprite.get_transform().set_position(vector2);
		//		}
		//	}
		//}
		//TweenSettingsExtensions.OnComplete<Sequence>(this._sequence, new TweenCallback(storey, (IntPtr) this.<>m__4));
		seq.pushBack(CallFunc::create([this,to]() {
		//void <>m__4() {
		//	if(ParticlePool.Instance != null) {
		//		AudioManager.Play(AudioTag.ItemBalloonGeneratorPlace, PlayMode.Frame, null, 1f);
		//	}
		//	this->_sequence = null;
		//	this->TrailParticle.get_emission().set_enabled(false);
		//	this->ShadowSprite.set_enabled(false);
		//	this->CurrentSpriteRenderer.set_enabled(false);
		//	this->TailSpriteRenderer.set_enabled(false);
		//	if(this->_onThrowAnimationComplete != null) {
				this->OnThrowAnimationComplete(to);
		//	}
		//	this->StartCoroutine(this->KillMe());
		//}
		//}
		}));
		Renderer->runAction(Sequence::create(seq));

//		this->CurrentAnimator.Play(this->_throwHash, 0, 0f);
		_animation->play("throw", false);
//		AudioManager.Play(AudioTag.ItemBalloonGeneratorThrow, PlayMode.Frame, null, 1f);
	}
	this->ThrowCompleted();
}

/*IEnumerator*/void BalloonGeneratorItem::ThrowCompleted() {
//case 0:
//	this.$current = new WaitForSeconds(0.2f);
//	if(!this.$disposing) {
//		this.$PC = 1;
//	}
//	return true;
//
//case 1:
//	if(this.$this._isSleeping) {
//		AudioManager.Play(AudioTag.ItemBalloonGeneratorPlace, PlayMode.Frame, null, 1f);
//		this.$this.CurrentAnimator.Play(this.$this._sleepHash, 0, 0f);
//	}
//	this.$PC = -1;
//	break;
	Renderer->runAction(Sequence::create(
		DelayTime::create(0.2f),
		CallFunc::create([this]() {
		if(this->_isSleeping) {
			//AudioManager.Play(AudioTag.ItemBalloonGeneratorPlace, PlayMode.Frame, null, 1f);
			_animation->play("sleep", false);
		}
		}),
		nullptr));
}

void BalloonGeneratorItem::SetDirection(int direction) {
	this->_direction = direction;
	if (this->_direction == 1) {
//		this->Container.get_transform().set_localScale(new Vector3(-1f, 1f, 1f));
//		Quaternion.get_identity().set_eulerAngles(new Vector3(0f, 0f, 180f));
		_sprite->setScaleX(-1);
	}
}

