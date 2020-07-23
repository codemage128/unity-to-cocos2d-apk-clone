#include "Animation.h"
#include "ItemImpl.h"
#include "Cell.h"
#include "FallManager.h"
#include "ItemFeature.h"
#include "LevelBuilder.h"
#include "Extension.h"

//////FALL ANIMATION//////////////////////////////////
FallAnimation* FallAnimation::create(Item* linkedItem) {
	FallAnimation* ret = new FallAnimation();
	ret->_linkedItem = linkedItem;
	FallManager::getInstance()->addFallAnimation(ret);
	return ret;
}

void FallAnimation::AppendFallTo(Cell* target, FallListener* fallListener) {	
	if(!_enabled) { //if(!base.get_enabled())
		_enabled = true; //base.set_enabled(true);
		this->_routes.clear();
		this->_currentSpeed = 6.0f*ITEM_SPRITE_SIZE_X;
		this->_fallMessageSend = false;
		this->_maxReached = false;
		this->State = FallAnimation::FallState::NotStarted;
	}
	this->_routes.push_back(target->GetFrozenPosition());
	if(this->State != FallAnimation::FallState::NotStarted) {
		return;
	}
	if(!this->_fallMessageSend) {
		this->_fallMessageSend = true;
		FallManager::AddOneFall();
	}
	this->_currentTarget = *this->_routes.begin();
	this->_item = _linkedItem;//base.GetComponent<Item>();
	//this->_item.CleanUpResources += new Action(this->CleanMe);
	this->_fallListener = fallListener;
}

void FallAnimation::CleanMe() {
	if(!_enabled) { //if(!base.get_enabled())
		return;
	}
	_enabled = false;//base.set_enabled(false);

	if(this->_fallMessageSend) {
		FallManager::RemoveOneFall();
	}
}

void FallAnimation::Update() {
	if(!_enabled) return;

	switch(this->State) {
	case FallAnimation::FallState::NotStarted:
		if(this->_routes.size() > 0)
			this->State = FallAnimation::FallState::StartFalling;

		break;
	case FallAnimation::FallState::StartFalling:
		this->_currentTarget = this->_routes.front(); this->_routes.pop_front();
		this->State = FallAnimation::FallState::Falling;
		if(this->_fallListener != nullptr)
			this->_fallListener->StartFall();
		break;
	case FallAnimation::FallState::Falling:
		this->Fall();
		break;
	case FallAnimation::FallState::Completed: {
		//base.get_transform().set_position(this->_currentTarget);
		cocos2d::Sprite* spItem = LevelBuilder::getItemSprite(this->_item);
		if(spItem != nullptr)
			spItem->setPosition(this->_currentTarget);

		this->_item->IsFalling = false;
		this->_item->FilledNewly = false;
		if(this->_fallListener != nullptr)
			this->_fallListener->EndFall(this->_currentSpeed);
		
		this->_item->OnFallEnded();
		Cell* currentCell = this->_item->get_CurrentCell();
		if(currentCell != nullptr) {
			Cell* justBelowCell = currentCell->JustBelowCell;
			if(justBelowCell != nullptr && justBelowCell->get_HasItem()) {
				justBelowCell->get_CurrentItem()->ReactToUpperFall();
				if(this->_item->CanCastShadow()) {
					if(justBelowCell->get_CurrentItem()->CanShadowDrop())
						this->_item->GetShadowCaster()->CastShadow();
					else
						this->_item->GetShadowCaster()->HideShadow();
				}
			}
			else if(this->_item->CanCastShadow())
				this->_item->GetShadowCaster()->HideShadow();
		}
		this->_currentSpeed = 0.0f;
		this->State = FallAnimation::FallState::Destroyed;
		this->CleanMe();
		return;
	}
	}
}

void FallAnimation::Fall() {
	cocos2d::Vec2 position;// = base.get_transform().get_position();
	cocos2d::Sprite* spItem = LevelBuilder::getItemSprite(this->_item);
	if (spItem != nullptr)
		position=spItem->getPosition();

	cocos2d::Vec2 currentTarget = this->_currentTarget;
	bool flag = this->_routes.size() > 0;
	float deltaTime = Ext_getFrameDeltaTime();// Time.get_deltaTime();
	float num = this->_currentSpeed * deltaTime + 40.0f * deltaTime * deltaTime;
	if(!this->_maxReached && this->_currentSpeed < 30.0f*ITEM_SPRITE_SIZE_X) {
		this->_currentSpeed += 40.0f * deltaTime*ITEM_SPRITE_SIZE_X;
		if(this->_currentSpeed > 30.0f*ITEM_SPRITE_SIZE_X) {
			this->_currentSpeed = 30.0f*ITEM_SPRITE_SIZE_X;
			this->_maxReached = true;
		}
	}
	position.y -= num;
	if(position.y < currentTarget.y) {
		if(!flag) {
			this->_item->IsFalling = false;
			this->State = FallAnimation::FallState::Completed;
			position.x = currentTarget.x;
			position.y = currentTarget.y;
			//base.get_gameObject().get_transform().set_position(position);
			if (spItem != nullptr)
				spItem->setPosition(position);

			this->Update();
			return;
		}
		this->_currentTarget = this->_routes.front(); this->_routes.pop_front();
	}
	//base.get_gameObject().get_transform().set_position(position);
	if (spItem != nullptr)
		spItem->setPosition(position);

}

bool FallAnimation::IsFalling() {
	return _enabled/*base.get_enabled()*/ && this->State != FallAnimation::FallState::Completed && this->State != FallAnimation::FallState::Destroyed;
}

void FallAnimation::Cancel() {
	if(!_enabled/*!base.get_enabled()*/ || this->State == FallAnimation::FallState::Destroyed) {
		return;
	}
	this->State = FallAnimation::FallState::Completed;
	this->Update();
}