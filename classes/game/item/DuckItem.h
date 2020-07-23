#ifndef __ENGINE_DUCKITEM_H__
#define __ENGINE_DUCKITEM_H__

#include "../ItemImpl.h"

enum class CollectAnimation;

class DuckItem : public SpriteBasedItem 
{
public:
	DuckItem();
	virtual ~DuckItem();

	TiledEditorId tiledEditorId = TiledEditorId::None;
	
	ItemType GetItemType() override { return ItemType::Duck; }
	bool CanBeExplodedBySpecialItem() override { return false; }
	bool CanBeTapped() override { return false; }
	bool CanBeExplodedByBooster() override { return false; }
	bool BoosterAnvilCanBeUsed() override { return true; }
	bool BoosterBoxingGloveCanBeUsed() override { return true; }
	bool BoosterHammerCanBeUsed() override { return false; }
	int GetScore() override { return 2500; }
	bool CanCastShadow() override { return true; }
	CollectAnimation GetCollectItem() override;

	/*public void Squash(Sequence seq, Transform rt, float yScale, float time, float jumpEffect, Ease e = 1)
	{
		TweenSettingsExtensions.Append(seq, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOScale(rt, new Vector3(1f / yScale, yScale), time), e));
		float num = 1f * (yScale - 1f) / 2f;
		num += jumpEffect;
		TweenSettingsExtensions.Join(seq, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(rt, rt.get_localPosition().y + num, time, false), e));
	}//*/

	void Update(float);
	void SetupItem(TiledEditorId tiledId);
	virtual void RemoveSelf() override;

protected:
	void PlayOnExplodeStartedAnimation() override { }
	static int GetDelayerCount();
	/*[DebuggerHidden]
	IEnumerator//*/ void PlayDuckRescue();

private:
	static int _delayerCount;
	static float _lastActionTime;

	bool _inExplodeState = false;
	bool _statIncreased = false;
};


#endif //__ENGINE_DUCKITEM_H__
