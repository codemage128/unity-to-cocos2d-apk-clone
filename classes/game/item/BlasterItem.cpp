#include "BlasterItem.h"
#include "BlasterFakeItem.h"
#include "CollectorItemsController.h"
#include "../Cell.h"
#include "../Grid.h"
#include "../ImageLibrary.h"
#include "../Mathf.h"
#include "../Score.h"
#include "../Grid.h"
#include "../Level.h"
#include "../ItemImpl.h"

void BlasterItem::set_CurrentCell(Cell* value) {
	CollectorItem::set_CurrentCell(value);
	if (this->get_CurrentCell() != nullptr) {
		int num = this->get_CurrentCell()->X;
		int num2 = this->get_CurrentCell()->Y;
		switch (this->_direction) {
		case Direction::Up:
		case Direction::Down: num2++; break;
		case Direction::Left:
		case Direction::Right: num++; break;
		}
		this->FakeItem->set_CurrentCell(this->get_CurrentCell()->CurrentGrid->cell(num, num2));
	}
	else {
		this->FakeItem->set_CurrentCell(nullptr);
	}
}

void BlasterItem::Start() {
//	this->_collectHash = Animator.StringToHash("Base Layer.BlasterCollectAnimation");
//	this->_launchHash = Animator.StringToHash("Base Layer.BlasterLaunchAnimation");
}

void BlasterItem::BringToFront() {
//	Sorting sorting = this->GetSorting();
//	sorting.Order += 3000;
//	this->ChangeSorting(sorting);
}

void BlasterItem::Prepare(Direction direction, int capacity, int order, MatchType matchType) {
	this->_capacity = capacity;
	Order = order;
	matchType = matchType;
	this->_direction = direction;
	float identity = 0;
	cocos2d::Vec2 localPosition = cocos2d::Vec2();
	float num = 1.0f;
	cocos2d::Vec2 zero = cocos2d::Vec2::ZERO;
	cocos2d::Vec2 localPosition2 = cocos2d::Vec2();
	switch (direction)
	{
	case Direction::Up:
		identity = 0.0f;
		localPosition = cocos2d::Vec2(0.0f, 0.5f);
		localPosition2 = cocos2d::Vec2(0.0f, -0.463f);
		break;
	case Direction::Down:
		identity = 180.0f;
		localPosition = cocos2d::Vec2(0.0f, 0.5f);
		localPosition2 = cocos2d::Vec2(0.0f, -0.463f);
		break;
	case Direction::Left:
		identity = 90.0f;
		localPosition = cocos2d::Vec2(0.5f, 0.0f);
		localPosition2 = cocos2d::Vec2(0.135f, -0.425f);
		zero = cocos2d::Vec2(0.8f, -0.5f);
		num = 1.2f;
		break;
	case Direction::Right:
		identity = 270.0f;
		localPosition = cocos2d::Vec2(0.5f, 0.0f);
		localPosition2 = cocos2d::Vec2(0.0f, -0.425f);
		zero = cocos2d::Vec2(1.0f, -0.5f);
		num = 1.2f;
		break;
	default:
		throw;// new ArgumentOutOfRangeException("direction", direction, null);
		break;
	}
	this->ShadowSpriteRenderer->setPosition(localPosition2);
	this->ShadowSpriteRenderer->setScale(num);
	this->FakeShadowSpriteRenderer->setPosition(zero);
	this->FakeShadowSpriteRenderer->setScale(num);
	this->BlasterTransform->setRotation(identity);
	this->BlasterTransform->setPosition(localPosition);
	this->ChangeColor(matchType);
	this->ResetFill();
	this->CollectorId = CollectorItemsController::get_Instance()->GetBlasters().Register(this);
//	if (this->_selectedCells == nullptr) {
		this->_selectedCells = std::vector<Cell*>();
//	}
}

void BlasterItem::ChangeColor(MatchType matchType)
{
	std::vector<cocos2d::Sprite*>* array = nullptr;
	switch (matchType)
	{
	case MatchType::Yellow:
		this->FillLayer->setColor(cocos2d::Color3B(255 * 0.8901961f, 255 * 0.772549033f, 255 * 0.180392161f));
		//		array = ImageLibrary::getInstance()->BlasterSpritesYellow;
		break;
	case MatchType::Red:
		this->FillLayer->setColor(cocos2d::Color3B(255 * 0.9843137f, 255 * 0.09803922f, 255 * 0.164705887f));
		//		array = ImageLibrary::getInstance()->BlasterSpritesRed;
		break;
	case MatchType::Blue:
		this->FillLayer->setColor(cocos2d::Color3B(255 * 0.180392161f, 255 * 0.5529412f, 255 * 0.8392157f));
		//		array = ImageLibrary::getInstance()->BlasterSpritesBlue;
		break;
	case MatchType::Green:
		this->FillLayer->setColor(cocos2d::Color3B(255 * 0.294117659f, 255 * 0.768627465f, 255 * 0.152941182f));
		//		array = ImageLibrary::getInstance()->BlasterSpritesGreen;
		break;
	case MatchType::Purple:
		this->FillLayer->setColor(cocos2d::Color3B(255 * 0.698039234f, 255 * 0.13333334f, 255 * 0.733333349f));
		//		array = ImageLibrary::getInstance()->BlasterSpritesPurple;
		break;
	default:
		//		LogManager.Error(LogTags.BlasterItem, "Error Changing color. Match type:{0} is not valid", new object[]
		//		{
		//			matchType
		//		});
		break;
	}
	ImageLibrary::CopySprite(this->ColoredSpriteRenderers[0], (*array)[0]);
	ImageLibrary::CopySprite(this->ColoredSpriteRenderers[1], (*array)[1]);
	ImageLibrary::CopySprite(this->ColoredSpriteRenderers[2], (*array)[2]);
}

void BlasterItem::StartCollectingItem() {
	this->_waitingCount++;
	if (this->_waitingCount == 1) {
		this->_shouldPlayCollectAudio = true;
	}
//	this->CurrentAnimator.SetBool("CollectCompleted", false);
	if (!this->_readyToLaunch && this->_waitingCount + this->_count >= this->_capacity) {
		this->_readyToLaunch = true;
//		TapListener.Instance.IncreaseBlockRequests();
		CollectorItemsController::get_Instance()->GetBlasters().AddToQueue(this->CollectorId);
	}
}

void BlasterItem::PlayCollectParticle() {
//	this->CollectParticle.Play();
}

void BlasterItem::OnItemCollectCompleted() {
	this->_count++;
	this->_waitingCount--;
	if (this->_shouldPlayCollectAudio) {
//		this->CollectHitParticle.Play();
		this->_shouldPlayCollectAudio = false;
//		if (ItemResourcesManager.Instance != null) {
//			AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this->GetItemType()).AudioClips[0], PlayMode.Frame, null, 1.0f);
//		}
	}
	int fullPathHash = 0;// this->CurrentAnimator.GetCurrentAnimatorStateInfo(0).get_fullPathHash();
	if (this->_waitingCount == 0) {
//		this->CurrentAnimator.SetBool("CollectCompleted", true);
		if (this->_collectHash != fullPathHash) {
//			this->CurrentAnimator.Play(this->_collectHash);
		}
		this->UpdateFill();
	}
	else {
//		this->CurrentAnimator.Play(this->_collectHash);
	}
	if (this->_waitingCount == 0 && this->_capacity - this->_count <= 0) {
		CollectorItemsController::get_Instance()->GetBlasters().UnRegister(this);
	}
}

void BlasterItem::ResetFill() {
	this->FillLayer->setPosition(cocos2d::Vec2(0.0f, -0.314f));
	this->FillLayer->setScaleX(0.26f);
	this->FillLayer->setScaleY(0.0f);
}

void BlasterItem::UpdateFill() {
	if (this->_fillSequence != nullptr) {
//		TweenExtensions.Kill(this->_fillSequence, false);
	}
	float num = (float)this->_count / (float)this->_capacity;
	float num2 = (this->_count < this->_capacity) ? 0.28f : 0.314f;
	float num3 = Mathf::Min(num, 1.0f);
	float num4 = 0.2f;
/*	this->_fillSequence = DOTween.Sequence();
	Tweener tweener = TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(this->FillLayer.get_transform(), -0.314f + num2 * num3, 0.6f, false), 30);
	tweener.easeOvershootOrAmplitude = 2f;
	TweenSettingsExtensions.Insert(this->_fillSequence, num4, tweener);
	Tweener tweener2 = TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOScaleY(this->FillLayer.get_transform(), 0.65f * num3, 0.6f), 30);
	tweener2.easeOvershootOrAmplitude = 2f;
	TweenSettingsExtensions.Insert(this->_fillSequence, num4, tweener2);
	TweenSettingsExtensions.OnComplete<Sequence>(this->_fillSequence, delegate
	{
		if (this->_waitingCount == 0 && this->_capacity - this->_count <= 0 && !this->_fillAnimationEnded)
		{
			this->_fillAnimationEnded = true;
			base.StartCoroutine(this->StartExplodeAnimation());
		}
	});*/
}

/*IEnumerator*/void BlasterItem::StartExplodeAnimation() {
//	BlasterItem.<StartExplodeAnimation>c__Iterator0 <StartExplodeAnimation>c__Iterator = new BlasterItem.<StartExplodeAnimation>c__Iterator0();
//	<StartExplodeAnimation>c__Iterator.$this = this;
//	return <StartExplodeAnimation>c__Iterator;
}

void BlasterItem::AcceptFalls() {
	ScoreManager::RaiseScore(this->ScoreGained, this->_scorePosition, MatchType::None);
	for (int i = 0; i < this->_selectedCells.size(); i++) {
		this->_selectedCells[i]->AcceptsFallInside();
	}
	this->_selectedCells.clear();
}

void BlasterItem::RemoveSelf() {
	this->OnBeforeRemove();
	this->_selectedCells.clear();
//	base.get_gameObject().Recycle();
}

void BlasterItem::CreateAnimation() {
	this->_selectedCells.clear();
	switch (this->_direction) {
	case Direction::Up:		this->CreateUpAnimation(); break;
	case Direction::Down:	this->CreateDownAnimation(); break;
	case Direction::Left:	this->CreateLeftAnimation(); break;
	case Direction::Right:	this->CreateRightAnimation(); break;
	}
}

void BlasterItem::ClearCells() {
	this->_selectedCells.push_back(this->get_CurrentCell());
	this->_selectedCells.push_back(this->FakeItem->get_CurrentCell());
	this->get_CurrentCell()->RejectsFallInside();
	this->FakeItem->set_CurrentCell(nullptr);
	this->set_CurrentCell(nullptr);
}

void BlasterItem::CreateRightAnimation() {
	if (this->get_CurrentCell() == nullptr) {
		return;
	}
/*	cocos2d::Sequence* sequence = DOTween.Sequence();
	TweenSettingsExtensions.SetEase<Sequence>(sequence, 1);
	int i = this->get_CurrentCell()->X;
	Grid* currentGrid = this->CurrentLevel->CurrentGrid;
	Cell* cellWithDirection = currentGrid->GetCellWithDirection(this->get_CurrentCell(), Direction::Right);
	TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveX(base.get_transform(), (float)i + this->_offset, this->_dt * this->_offset, false), 1));
	while (i < 9) {
		i++;
		cellWithDirection = currentGrid->GetCellWithDirection(cellWithDirection, Direction::Right);
		this->ExplodeCell(cellWithDirection, sequence);
		TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveX(base.get_transform(), (float)i + this->_offset, this->_dt, false), 1));
	}
	TweenSettingsExtensions.AppendCallback(sequence, delegate {
		this->_blasterAnimationCompleted = true;
	});
	float num = (float)(15 - i) - this->_offset;
	TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveX(base.get_transform(), 15.0f, this->_dt * num, false), 1));
*/	this->ClearCells();
}

void BlasterItem::CreateLeftAnimation()
{
	if (this->get_CurrentCell() == nullptr) {
		return;
	}
/*	cocos2d::Sequence* sequence = DOTween.Sequence();
	TweenSettingsExtensions.SetEase<Sequence>(sequence, 1);
	int i = this->get_CurrentCell()->X;
	Grid* currentGrid = this->CurrentLevel->CurrentGrid;
	Cell* cell = this->get_CurrentCell();
	TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveX(base.get_transform(), (float)i - this->_offset, this->_dt * this->_offset, false), 1));
	while (i >= 0) {
		i--;
		cell = currentGrid->GetCellWithDirection(cell, Direction::Left);
		this->ExplodeCell(cell, sequence);
		TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveX(base.get_transform(), (float)i - this->_offset, this->_dt, false), 1));
	}
	TweenSettingsExtensions.AppendCallback(sequence, delegate {
		this->_blasterAnimationCompleted = true;
	});
	float num = (float)(15 - i) - this->_offset;
	TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveX(base.get_transform(), -15.0f, this->_dt * num, false), 1));
*/	this->ClearCells();
}

void BlasterItem::CreateUpAnimation()
{
	if (this->get_CurrentCell() == nullptr) {
		return;
	}
/*	cocos2d::Sequence* sequence = DOTween.Sequence();
	TweenSettingsExtensions.SetEase<Sequence>(sequence, 1);
	int i = this->get_CurrentCell()->Y;
	Grid* currentGrid = this->CurrentLevel->CurrentGrid;
	Cell* cellWithDirection = currentGrid->GetCellWithDirection(this->get_CurrentCell(), Direction::Up);
	TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(base.get_transform(), (float)i + this->_offset, this->_dt * this->_offset, false), 1));
	while (i < 9) {
		i++;
		cellWithDirection = currentGrid->GetCellWithDirection(cellWithDirection, Direction::Up);
		this->ExplodeCell(cellWithDirection, sequence);
		TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(base.get_transform(), (float)i + this->_offset, this->_dt, false), 1));
	}
	TweenSettingsExtensions.AppendCallback(sequence, delegate {
		this->_blasterAnimationCompleted = true;
	});
	float num = (float)(15 - i) - this->_offset;
	TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(base.get_transform(), 15f, this->_dt * num, false), 1));
*/	this->ClearCells();
}

void BlasterItem::CreateDownAnimation()
{
	if (this->get_CurrentCell() == nullptr)	{
		return;
	}
/*	cocos2d::Sequence* sequence = DOTween.Sequence();
	TweenSettingsExtensions.SetEase<Sequence>(sequence, 1);
	int i = this->get_CurrentCell()->Y;
	Grid* currentGrid = this->CurrentLevel->CurrentGrid;
	Cell* cell = this->get_CurrentCell();
	TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(base.get_transform(), (float)i - this->_offset, this->_dt * this->_offset, false), 1));
	while (i >= 0) {
		i--;
		cell = currentGrid->GetCellWithDirection(cell, Direction::Down);
		this->ExplodeCell(cell, sequence);
		TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(base.get_transform(), (float)i - this->_offset, this->_dt, false), 1));
	}
	TweenSettingsExtensions.AppendCallback(sequence, delegate {
		this->_blasterAnimationCompleted = true;
	});
	float num = (float)(15 - i) - this->_offset;
	TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(base.get_transform(), -15f, this->_dt * num, false), 1));
*/	this->ClearCells();
}

void BlasterItem::ExplodeCell(Cell* c, cocos2d::Sequence* seq) {
	if (c != nullptr && c->Exists) {
		c->RejectsFallInside();
		this->_selectedCells.push_back(c);

/*		TweenSettingsExtensions.AppendCallback(seq, delegate {
			if (c->get_HasItem()) {
				Item* currentItem = c->get_CurrentItem();
				if (currentItem != nullptr)	{
					currentItem->PreventRaiseScore();
					this->ScoreGained += currentItem->GetScore();
					FrameItem* cageItem = dynamic_cast<FrameItem*>(currentItem);
					if (cageItem != nullptr) {
						this->ScoreGained += cageItem->get_InnerItem()->GetScore();
					}
					//				currentItem->ExplodeByBlasterItem();
				}
			}
			bool hasBubble = c->HasBubble;
			if (hasBubble) {
				c->RemoveBubble();
			}
		});*/
	}
}
