using Assets.Scripts.CasualTools.Common.Pooling;
using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.Utils;
using DG.Tweening;
using System;
using System.Collections;
using System.Diagnostics;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class DuckItem : SpriteBasedItem
	{
		private static int _delayerCount;

		private static float _lastActionTime;

		private bool _inExplodeState;

		[HideInInspector]
		public TiledEditorId TiledEditorId;

		private bool _statIncreased;

		public override ItemType GetItemType()
		{
			return ItemType.Duck;
		}

		public override bool CanBeExplodedBySpecialItem()
		{
			return false;
		}

		public override bool CanBeTapped()
		{
			return false;
		}

		public override bool CanBeExplodedByBooster()
		{
			return false;
		}

		public override bool BoosterAnvilCanBeUsed()
		{
			return true;
		}

		public override bool BoosterBoxingGloveCanBeUsed()
		{
			return true;
		}

		public override bool BoosterHammerCanBeUsed()
		{
			return false;
		}

		public override int GetScore()
		{
			return 2500;
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
		}

		public override bool CanCastShadow()
		{
			return true;
		}

		public override CollectAnimation GetCollectItem()
		{
			CollectAnimation component = this.CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(base.get_transform().get_position()).GetComponent<CollectAnimation>();
			component.Prepare(this.CurrentLevel, this.GetItemType(), this.GetSorting(), this.CurrentSpriteRenderer.get_sprite(), this.CurrentCell);
			return component;
		}

		public void Squash(Sequence seq, Transform rt, float yScale, float time, float jumpEffect, Ease e = 1)
		{
			TweenSettingsExtensions.Append(seq, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOScale(rt, new Vector3(1f / yScale, yScale), time), e));
			float num = 1f * (yScale - 1f) / 2f;
			num += jumpEffect;
			TweenSettingsExtensions.Join(seq, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(rt, rt.get_localPosition().y + num, time, false), e));
		}

		private static int GetDelayerCount()
		{
			float time = Time.get_time();
			if (time - DuckItem._lastActionTime > 0.1f)
			{
				DuckItem._delayerCount = 0;
				DuckItem._lastActionTime = time;
				return DuckItem._delayerCount;
			}
			DuckItem._delayerCount++;
			DuckItem._lastActionTime = time;
			return DuckItem._delayerCount;
		}

		[DebuggerHidden]
		private IEnumerator PlayDuckRescue()
		{
			DuckItem.<PlayDuckRescue>c__Iterator0 <PlayDuckRescue>c__Iterator = new DuckItem.<PlayDuckRescue>c__Iterator0();
			<PlayDuckRescue>c__Iterator.$this = this;
			return <PlayDuckRescue>c__Iterator;
		}

		public void Update()
		{
			if (this._inExplodeState || SlowCheckTime.ShouldPass() || this.IsFalling)
			{
				return;
			}
			if (this.CurrentCell == null || !this.CurrentCell.IsFloor)
			{
				return;
			}
			this.CurrentLevel.PreCheckDecreaseGoal(ItemType.Duck);
			this._inExplodeState = true;
			if (!this._statIncreased)
			{
				this._statIncreased = true;
				FallManager.IncreaseStatAnimation();
			}
			base.StartCoroutine(this.PlayDuckRescue());
		}

		public void SetupItem(TiledEditorId tiledId)
		{
			int num = -1;
			switch (tiledId)
			{
			case TiledEditorId.Duck1:
				num = 0;
				break;
			case TiledEditorId.Duck2:
				num = 1;
				break;
			case TiledEditorId.Duck3:
				num = 2;
				break;
			case TiledEditorId.Duck4:
				num = 3;
				break;
			case TiledEditorId.Duck5:
				num = 4;
				break;
			}
			if (num >= 0)
			{
				this.CurrentSpriteRenderer.set_sprite(ImageLibrary.Instance.DuckSprites[num]);
			}
		}
	}
}
