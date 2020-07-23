#include "MoleItem.h"
#include "../Level.h"
#include "../Extension.h"

void MoleItem::Awake() {
//	this->_upAnimationHash = Animator.StringToHash("Base Layer.MoleUpAnimation");
//	this->_downAnimationHash = Animator.StringToHash("Base Layer.MoleDownAnimation");
}

void MoleItem::OnItemCreated(Level* currentLevel) {
	Item::OnItemCreated(currentLevel);
	this->CurrentLevel->ExplodeAwareItem.push_back(this);
}

void MoleItem::ExplodeByBlasterItem() {
	if (this->_isDestroyed) {
		return;
	}
	this->_latestTriggeredMove = this->CurrentLevel->get_MovesLeft() + 1;
	this->_state = 1;
//	Item::ExplodeByBlasterItem();
}

bool MoleItem::TryExplode()
{
	if (this->LatestExplode == (long)Ext_getCurrentFrame() || this->_isDestroyed) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	int latestTriggeredMove = this->_latestTriggeredMove;
	this->_latestTriggeredMove = this->CurrentLevel->get_MovesLeft();
	if (this->_state == 0) {
		this->MoveToState(1);
		return false;
	}
	this->_isDestroyed = (latestTriggeredMove - this->_latestTriggeredMove <= 1);
	return this->_isDestroyed;
}

void MoleItem::PlayOnExplodeStartedAnimation() {
//	if (ParticlePool.Instance != null && ItemResourcesManager.Instance != null)	{
//		ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this->GetItemType()).Particles[0], Item::get_transform().get_position(), true);
//	}
}

void MoleItem::PlayExplodeAudio() {
//	if (ItemResourcesManager.Instance != null) {
//		AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this->GetItemType()).AudioClips[1], PlayMode.Frame, null, 1f);
//	}
}

void MoleItem::ExplosionOccured(int moveCount) {
	if (moveCount != this->_latestTriggeredMove) {
		this->MoveToState(0);
	}
}

void MoleItem::MoveToState(int i) {
/*	try	{
		if (!this->_isDestroyed && this->_state != i) {
			ItemResources itemResources = null;
			if (ItemResourcesManager.Instance != null) {
				itemResources = ItemResourcesManager.Instance.GetResources(this->GetItemType());
			}
			this->_state = i;
			if (i != 0)	{
				if (i == 1)	{
					this->CurrentAnimator.Play(this->_upAnimationHash, 0, 0f);
					AudioManager.PlayAudioProps(itemResources.AudioClips[0], PlayMode.Frame, null, 1f);
				}
			}
			else			{
				this->CurrentAnimator.Play(this->_downAnimationHash, 0, 0f);
			}
		}
	}
	catch (Exception ex)
	{
		LogManager.Warning(LogTags.GamePlay, "Mole Item Move to state:{0} Error:{1} Stack:{2}", new object[]
		{
			i,
			ex.Message,
			ex.StackTrace
		});
	}*/
}

