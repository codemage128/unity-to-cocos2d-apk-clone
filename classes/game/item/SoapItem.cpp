#include "SoapItem.h"
#include "../Extension.h"
#include "../Score.h"
#include "../Cell.h"
#include "../Level.h"

bool SoapItem::TryExplode() {
	if (this->LatestExplode == (long)Ext_getCurrentFrame() || this->_isDestroyed) {
		return false;
	}
	this->LatestExplode = (long)Ext_getCurrentFrame();
	this->_canGenerateScore = false;
	this->_isDestroyed = true;
//	this->LastPosition = base.get_transform().get_position();
	if (this->CanRaiseScore()) {
//		ScoreManager::RaiseScore(this->GetScore(), base.get_transform().get_position(), MatchType::None);
	}
	this->ExplodeNextFrame();
	return false;
}

/*IEnumerator*/void SoapItem::ExplodeNextFrame() {
//	SoapItem.<ExplodeNextFrame>c__Iterator0 <ExplodeNextFrame>c__Iterator = new SoapItem.<ExplodeNextFrame>c__Iterator0();
//	<ExplodeNextFrame>c__Iterator.$this = this;
//	return <ExplodeNextFrame>c__Iterator;
}

void SoapItem::PlayBubbleAnimation(std::vector<Cell*> cells) {
	int count = cells.size();
	for (int i = 0; i < count; i++) {
		Cell* cell = cells[i];
		cell->AddBubble(true);
//		GameObject gameObject = ItemResourcesManager.Instance.GetResources(this->GetItemType()).Animators[0].Spawn();
//		gameObject.get_transform().set_position(base.get_transform().get_position());
//		SoapBubbleAnimation component = gameObject.GetComponent<SoapBubbleAnimation>();
//		component.Prepare(cell);
		this->CurrentLevel->IncreaseGoal(ItemType::Bubble);
	}
//	this->CurrentLevel->DecreaseItemCountOnGrid(this->GetItemType());
	this->CurrentLevel->DecreaseGoal(this->GetItemType(), false);
	if (count != 0) {
//		AudioManager.PlayAudioPropsLater(0.55f, ItemResourcesManager.Instance.GetResources(this->GetItemType()).AudioClips[0], PlayMode.Frame, null, 1f);
	}
	this->StartExplode();
}

void SoapItem::PlayOnExplodeStartedAnimation() {
//	if (ItemResourcesManager.Instance != nullptr) {
//		ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this->GetItemType()).Particles[0], this->LastPosition, true);
//		AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this->GetItemType()).AudioClips[1], PlayMode.Frame, null, 1f);
//	}
}

