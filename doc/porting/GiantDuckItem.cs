using Assets.Scripts.CasualTools.Common.Pooling;
using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.GamePlayScene.Mechanics.Items.Features;
using Assets.Scripts.Utils;
using DG.Tweening;
using System;
using System.Collections;
using System.Diagnostics;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class GiantDuckItem : SpriteBasedItem
	{
		private bool _inExplodeState;

		public GiantDuckFakeItem BottomRight;

		public GiantDuckFakeItem TopLeft;

		public GiantDuckFakeItem TopRight;

		private bool _statIncreased;

		public override Cell CurrentCell
		{
			get
			{
				return base.CurrentCell;
			}
			set
			{
				base.CurrentCell = value;
				if (this.CurrentCell != null)
				{
					this.TopLeft.CurrentCell = this.CurrentCell.CurrentGrid[this.CurrentCell.X, this.CurrentCell.Y + 1];
					this.TopRight.CurrentCell = this.CurrentCell.CurrentGrid[this.CurrentCell.X + 1, this.CurrentCell.Y + 1];
					this.BottomRight.CurrentCell = this.CurrentCell.CurrentGrid[this.CurrentCell.X + 1, this.CurrentCell.Y];
				}
				else
				{
					this.TopLeft.CurrentCell = null;
					this.TopRight.CurrentCell = null;
					this.BottomRight.CurrentCell = null;
				}
			}
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
		}

		public override CollectAnimation GetCollectItem()
		{
			Vector3 position = base.get_transform().get_position();
			position.x += 0.5f;
			position.y += 0.4f;
			CollectAnimation component = this.CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(position).GetComponent<CollectAnimation>();
			component.Prepare(this.CurrentLevel, this.GetItemType(), this.GetSorting(), null, this.CurrentCell);
			return component;
		}

		public override void OnFallEnded()
		{
			base.OnFallEnded();
			Cell currentCell = this.BottomRight.CurrentCell;
			if (currentCell != null)
			{
				CanCastShadowComponent.CastShadowIfPossible(currentCell);
			}
		}

		public override ItemType GetItemType()
		{
			return ItemType.GiantDuck;
		}

		public override int GetScore()
		{
			return 10000;
		}

		public override bool CanCastShadow()
		{
			return true;
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

		public override bool CanFall()
		{
			Cell currentCell = this.BottomRight.CurrentCell;
			Cell firstExistingBottomCell = currentCell.FirstExistingBottomCell;
			return !currentCell.Exists || (firstExistingBottomCell != null && firstExistingBottomCell.Exists && !firstExistingBottomCell.HasItem && firstExistingBottomCell.CanItemsFallInside());
		}

		public void Squash(Sequence seq, Transform rt, float yScale, float time, float jumpEffect, Ease e = 1)
		{
			TweenSettingsExtensions.Append(seq, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOScale(rt, new Vector3(1f / yScale, yScale), time), e));
			float num = 1f * (yScale - 1f) / 2f;
			num += jumpEffect;
			TweenSettingsExtensions.Join(seq, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(rt, rt.get_localPosition().y + num, time, false), e));
		}

		[DebuggerHidden]
		private IEnumerator PlayGiantDuckRescue()
		{
			GiantDuckItem.<PlayGiantDuckRescue>c__Iterator0 <PlayGiantDuckRescue>c__Iterator = new GiantDuckItem.<PlayGiantDuckRescue>c__Iterator0();
			<PlayGiantDuckRescue>c__Iterator.$this = this;
			return <PlayGiantDuckRescue>c__Iterator;
		}

		public void Update()
		{
			if (this._inExplodeState || SlowCheckTime.ShouldPass() || this.IsFalling)
			{
				return;
			}
			Cell currentCell = this.BottomRight.CurrentCell;
			if ((this.CurrentCell == null || !this.CurrentCell.IsFloor) && (currentCell == null || !currentCell.IsFloor))
			{
				return;
			}
			this._inExplodeState = true;
			this.CurrentLevel.PreCheckDecreaseGoal(ItemType.Duck);
			if (!this._statIncreased)
			{
				this._statIncreased = true;
				FallManager.IncreaseStatAnimation();
			}
			base.StartCoroutine(this.PlayGiantDuckRescue());
		}
	}
}
