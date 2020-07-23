#include "FishItem.h"
#include "../BubbleController.h"
#include "../Extension.h"
#include "../ParticleLibrary.h"
#include "../ImageLibrary.h"
#include "../Level.h"
#include "../Cell.h"

USING_NS_CC;

FishItem::FishItem() {
	this->Renderer = Sprite::create();
	this->Renderer->retain();
}
FishItem::~FishItem() {
	this->Renderer->release();
}

void FishItem::SetupItem() {
	_sprite = ParticleLibrary::cloneNodeForNodeModel(PTCLLIB->getFishNode());
	this->Renderer->addChild(_sprite);
	_sprite->setPosition(0, -8);
	_animation = PTCLLIB->getFishAnim()->clone();
	_sprite->runAction(_animation);
	_animation->play("idle", false);

	_bubble = Sprite::create();
	IMGLIB->CopySprite(_bubble, IMGLIB->Bubble);
	this->Renderer->getParent()->addChild(_bubble,ITEM_BUBBLE_ZORDER_BASE);
	_bubble->setVisible(false);
}

void FishItem::RemoveSelf() {
	this->OnBeforeRemove();
	//base.get_gameObject().Recycle();
	this->Renderer->removeFromParentAndCleanup(true);
	this->_bubble->removeFromParentAndCleanup(true);
	//delete this;
}

void FishItem::Start() {
//	this->_throwHash = Animator.StringToHash("Base Layer.BubbleGeneratorThrow");
//	this->_sleepHash = Animator.StringToHash("Base Layer.BubbleGeneratorSleep");
}

void FishItem::OnItemCreated(Level* currentLevel) {
	Item::OnItemCreated(currentLevel);
	BubbleController::getInstance()->AddBubbleGeneratorItem(this);
}

bool FishItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame()) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	this->GenerateBubbles();
	return false;
}

/*IEnumerator*/void FishItem::GenerateBubbles() {
	//case 0:
	//	this->$current = null;
	//	if(!this->$disposing) {
	//		this->$PC = 1;
	//	}
	//	return true;
	//
	//case 1:
	bool shouldSleep = CurrentLevel->LeftBubbleCount() < 2 && !_isSleeping;
	if(CurrentLevel->LeftBubbleCount() >= 1) {
		//		try {
		bool flag = false;
		this->_counter++;
		if((this->_counter % this->_generateBubbleInterval) == 0) {
			this->_counter = 0;
			for(int i = 0; i < this->_generatedBubbleCount; i++) {
				Cell* randomCell = BubbleController::getInstance()->GetRandomCell();
				if(randomCell == nullptr) {
					break;
				}
				flag = true;
				randomCell->AddBubble(true);
				//this->CurrentLevel->CurrentLevelBuilder.BubbleAnimationItem.Spawn().GetComponent<BubbleAnimation>().Prepare(this->CurrentCell, randomCell, this->_direction, this->ThrowParticle, new Action(this->OnThrowAnimationComplete));
				onThrow(this->get_CurrentCell(), randomCell, this->_direction);
				this->_isPlayingAnimation = true;
				if(shouldSleep) {
					BubbleController::getInstance()->TrySleepGenerators();
				}
			}
		}
		if(flag) {
			//this->CurrentAnimator.Play(this->_throwHash, 0, 0f);
			_animation->play("throw", false);
		}
		//		}
		//		catch(Exception exception) {
		//			object[] arguments = new object[] { exception.Message, exception.StackTrace };
		//			LogManager.Error(LogTags.FishItem, "Generate Bubbles Error:{0} Stack:{1} ", arguments);
		//		}
		//		this->$PC = -1;
		//		break;
	}
	//	break;
}

void FishItem::onThrow(Cell* from, Cell* to, int direction) {
	const int FISHANIMTAG = 0x7779;
	Vector<FiniteTimeAction*> seq;
	Vec2 startpos = from->GetFrozenPosition();
	Vec2 endPos = to->GetFrozenPosition();
	if(direction == 0) {
		startpos.x += 0.6f*ITEM_SPRITE_SIZE_X;
	}
	else {
		startpos.x -= 0.6f*ITEM_SPRITE_SIZE_X;
	}
	//this.BubbleContainer.get_transform().set_position(startpos);
	//this.BubbleContainer.get_transform().set_localScale(new Vector3(0.1f, 0.1f, 1f));
	//Quaternion quaternion = Quaternion.get_identity();
	//quaternion.set_eulerAngles(new Vector3(-66.7f, 0f, 0f));
	//this.BubbleContainer.get_transform().set_rotation(quaternion);
	//int num = 10;
	//Vector3 vector2 = (Vector3)((storey2.endPos - startpos) * 0.5f);
	//int num2 = (vector2.y <= 0f) ? 1 : -1;
	//if(this._direction == 1) {
	//	num2 *= -1;
	//}
	//float num3 = vector2.get_magnitude() * 0.5f;
	//float num4 = vector2.get_magnitude() * 0.25f;
	//num4 = Math.Min(0.8f, Math.Max(0.3f, num4));
	//float num5 = num4 / ((float)num);
	//Vector3 vector4 = new Vector3(-vector2.y, vector2.x).get_normalized();
	//Vector3 control = Vector3.get_zero();
	//control.x = startpos.x + vector2.x;
	//control.y = startpos.y + vector2.y;
	//control += (Vector3)((vector4 * num3) * num2);
	if(Renderer->getActionByTag(FISHANIMTAG) != nullptr) {
		Renderer->stopActionByTag(FISHANIMTAG);
	}
	//AudioManager.Play(AudioTag.ItemFish, PlayMode.Frame, null, 1f);
	//this._sequence = DOTween.Sequence();
	//TweenSettingsExtensions.AppendInterval(this._sequence, 0.15f);
	seq.pushBack(DelayTime::create(0.15f));
	//TweenSettingsExtensions.AppendCallback(this._sequence, new TweenCallback(storey2, (IntPtr) this.<>m__0));
	seq.pushBack(CallFunc::create([this, startpos, direction]() {
		ParticleLibrary::getInstance()->showFishBubble(direction, startpos);
		this->OnThrowAnimationComplete();
	}));
	//TweenSettingsExtensions.InsertCallback(this._sequence, 0.2f, new TweenCallback(storey2, (IntPtr) this.<>m__1));
	seq.pushBack(DelayTime::create(0.05f));
	seq.pushBack(CallFunc::create([this]() {
		//this.<>f__ref$0.$this.BubbleContainer.get_gameObject().SetActive(true);
		//ShortcutExtensions.DOKill(this.<>f__ref$0.$this.Bubble.get_transform(), false);
		//this.<>f__ref$0.$this.Bubble.get_transform().set_localScale(Vector3.get_one());
		//TweenSettingsExtensions.SetEase<Tweener>(TweenSettingsExtensions.SetLoops<Tweener>(ShortcutExtensions.DOScaleX(this.<>f__ref$0.$this.Bubble.get_transform(), 1.2f, 0.1f), -1, 1), 1);
		//TweenSettingsExtensions.SetDelay<Tweener>(TweenSettingsExtensions.SetEase<Tweener>(TweenSettingsExtensions.SetLoops<Tweener>(ShortcutExtensions.DOScaleY(this.<>f__ref$0.$this.Bubble.get_transform(), 1.2f, 0.1f), -1, 1), 1), 0.1f);
	}));
	//for(int i = 1; i <= num; i++) {
	//	float t = ((float)i) / ((float)num);
	//	Vector3 vector6 = this.GetBezierPosition(startpos, control, storey2.endPos, t);
	//	TweenSettingsExtensions.Insert(this._sequence, 0.2f + (num5 * i), TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOMove(this.BubbleContainer.get_transform(), vector6, num5, false), 1));
	//}
	//TweenSettingsExtensions.Insert(this._sequence, 0.2f + num5, ShortcutExtensions.DORotate(this.BubbleContainer.get_transform(), Vector3.get_zero(), 0.3f, 0));
	//TweenSettingsExtensions.Insert(this._sequence, 0.2f + num5, ShortcutExtensions.DOScale(this.BubbleContainer.get_transform(), 0.4f, 0.1f));
	//TweenSettingsExtensions.Insert(this._sequence, 0.2f + num5, ShortcutExtensions.DOScale(this.BubbleContainer.get_transform(), 1f, num4 - 0.1f));
	seq.pushBack(TargetedAction::create(_bubble, Sequence::create(
		Place::create(startpos),
		Show::create(),
		EaseSineInOut::create(MoveTo::create(endPos.distance(startpos)/ITEM_SPRITE_SIZE_X*0.15f,endPos)),
		Hide::create(),
		nullptr)));

	//TweenSettingsExtensions.OnComplete<Sequence>(this._sequence, new TweenCallback(storey2, (IntPtr) this.<>m__2));
	seq.pushBack(CallFunc::create([this, to]() {
		//if(ParticlePool.Instance != null) {
		//	ParticlePool.Instance.PlayParticle(ParticlePool.Instance.BubbleSnapParticle, this.endPos, true);
		//}
		if(to != nullptr) {
			to->ApplyReservedBubble();
		}
		//this.<>f__ref$0.$this._sequence = null;
		//this.<>f__ref$0.$this.get_gameObject().Recycle();
	}));

	Action* fishanim = Sequence::create(seq);
	fishanim->setTag(FISHANIMTAG);
	Renderer->runAction(fishanim);
}

void FishItem::Sleep() {
	if (this->_isSleeping) {
		return;
	}
	this->_isSleeping = true;
	if (!this->_isPlayingAnimation) {
//		this->CurrentAnimator.Play(this->_sleepHash, 0, 0f);
		_animation->play("sleep", false);
	}
}

void FishItem::OnThrowAnimationComplete() {
	this->_isPlayingAnimation = false;
	if (this->_isSleeping) {
//		this->CurrentAnimator.Play(this->_sleepHash, 0, 0f);
		_animation->play("sleep", false);
	}
}

void FishItem::SetDirection(int direction) {
	this->_direction = direction;
	if (this->_direction == 1) {
//		this->Container.get_transform().set_localScale(new Vector3(-1f, 1f, 1f));
//		Quaternion identity = Quaternion.get_identity();
//		identity.set_eulerAngles(new Vector3(0f, 0f, 180f));
//		this->ThrowParticle.get_transform().set_rotation(identity);
		_sprite->setScaleX(-1);
	}
}

