using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.Utils;
using GamePlayScene.Mechanics.Animations;
using System;
using System.Collections;
using System.Diagnostics;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public class UfoItem : Item, ITouchAware
	{
		public SwapAnimation SwapAnimation;

		public Animator CurrentAnimator;

		public SpriteRenderer[] SpriteRenderers;

		private Sorting _sorting;

		private int _lastExplodeTime;

		private int _delayerCount;

		private int _lastTurnNo;

		private int _swapAnimationHash;

		private bool _shouldMoveUp;

		private bool _isSwapping;

		private bool _statIncreased;

		private bool _inExplodeState;

		private float _lastActionTime;

		public override ItemType GetItemType()
		{
			return ItemType.Ufo;
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

		public override void PlayExplodeAudio()
		{
		}

		public override void ExplodeByBlasterItem()
		{
			if (this.CurrentCell.HasBubble)
			{
				this.CurrentCell.RemoveBubble();
			}
		}

		public override bool CanCastShadow()
		{
			return true;
		}

		public override bool CanBeCollectedWithAnimation()
		{
			return true;
		}

		public override void ChangeSorting(Sorting s)
		{
			this._sorting = s;
			int i = 0;
			int num = this.SpriteRenderers.Length;
			while (i < num)
			{
				SpriteRenderer spriteRenderer = this.SpriteRenderers[i];
				if (!(spriteRenderer == null))
				{
					spriteRenderer.set_sortingLayerID(this._sorting.LayerId);
					spriteRenderer.set_sortingOrder(this._sorting.Order + 200 + i);
				}
				i++;
			}
		}

		public override Sorting GetSorting()
		{
			return this._sorting;
		}

		public void Start()
		{
			this.CurrentAnimator.StopPlayback();
			this.CurrentAnimator.Play(Animator.StringToHash("Base Layer.UfoItemIdleAnimation"), -1, Random.Range(0f, 1f));
		}

		public override void OnItemCreated(Level currentLevel)
		{
			base.OnItemCreated(currentLevel);
			UfoController.Instance.RegisterUfoItem(this);
			this.CurrentLevel.TouchAwareItem.Add(this);
			this.SwapAnimation.OnComplete = new Action(this.OnSwapAnimationCompleted);
			this._lastTurnNo = this.CurrentLevel.TurnNo;
			this._swapAnimationHash = Animator.StringToHash("Base Layer.UfoItemSwapAnimation");
		}

		private void OnSwapAnimationCompleted()
		{
			this._isSwapping = false;
		}

		public void TouchOccured()
		{
			this._lastExplodeTime = Time.get_frameCount();
			int turnNo = this.CurrentLevel.TurnNo;
			if (this._lastTurnNo != turnNo)
			{
				this._shouldMoveUp = true;
				this._lastTurnNo = turnNo;
			}
		}

		public override void OnFallUpdated()
		{
			base.OnFallUpdated();
			this._shouldMoveUp = false;
		}

		public bool TrySwap()
		{
			if (this._isSwapping || !this._shouldMoveUp || this._lastExplodeTime == Time.get_frameCount() || this.CurrentCell == null || this.CurrentCell.IsFloor || FallManager.AreThereMechanicAnimations() || this.AreThereFallingItemsInMyColumn())
			{
				return false;
			}
			this._shouldMoveUp = false;
			this.StartSwap();
			return true;
		}

		private bool AreThereFallingItemsInMyColumn()
		{
			CaravanGrid currentGrid = this.CurrentLevel.CurrentGrid;
			int x = this.CurrentCell.X;
			int y = this.CurrentCell.Y;
			for (int i = y; i >= 0; i--)
			{
				Cell cell = currentGrid[x, i];
				if (cell.Exists && cell.HasItem && cell.CurrentItem.IsFalling)
				{
					return true;
				}
			}
			return false;
		}

		public void TryFall()
		{
			if (this._inExplodeState || this.IsFalling)
			{
				return;
			}
			if (this.CurrentCell == null || !this.CurrentCell.IsFloor)
			{
				return;
			}
			this.CurrentLevel.PreCheckDecreaseGoal(ItemType.Ufo);
			this._inExplodeState = true;
			if (!this._statIncreased)
			{
				this._statIncreased = true;
				FallManager.IncreaseStatAnimation();
			}
			base.StartCoroutine(this.PlayRescue());
		}

		private void StartSwap()
		{
			Cell cellWithDirection = this.CurrentCell.CurrentGrid.GetCellWithDirection(this.CurrentCell, Direction.Up);
			if (cellWithDirection == null || !cellWithDirection.Exists || cellWithDirection.ReservedForGeneratorItem)
			{
				return;
			}
			if (!cellWithDirection.HasItem)
			{
				CaravanGrid currentGrid = this.CurrentLevel.CurrentGrid;
				int x = this.CurrentCell.X;
				int y = this.CurrentCell.Y;
				for (int i = y + 1; i < currentGrid.Height; i++)
				{
					Cell cell = currentGrid[x, i];
					if (cell.Exists && cell.HasItem)
					{
						if (cell.CurrentItem.CanFall())
						{
							this._shouldMoveUp = true;
						}
						return;
					}
				}
				this._shouldMoveUp = true;
				return;
			}
			Item currentItem = cellWithDirection.CurrentItem;
			ItemType itemType = currentItem.GetItemType();
			if (!currentItem.CanFall() || itemType == ItemType.GiantDuck || itemType == ItemType.Ufo)
			{
				return;
			}
			if (currentItem.IsFalling)
			{
				this._shouldMoveUp = true;
				return;
			}
			this.SwapAnimation.Swap(currentItem);
			this._isSwapping = true;
		}

		public void PlaySwapAnimation()
		{
			AudioManager.PlayAudioProps(this.Resources.AudioClips[0], PlayMode.Frame, null, 1f);
			this.CurrentAnimator.Play(this._swapAnimationHash, -1, 0f);
		}

		public override CollectAnimation GetCollectItem()
		{
			CollectAnimation component = Object.Instantiate<GameObject>(this.Resources.Animators[0], this.CurrentCell.GetFrozenPosition(), Quaternion.get_identity()).GetComponent<CollectAnimation>();
			component.Prepare(this.CurrentLevel, this.GetItemType(), this.GetSorting(), SharedImageLibrary.Instance.UfoGoal, this.CurrentCell);
			return component;
		}

		[DebuggerHidden]
		private IEnumerator PlayRescue()
		{
			UfoItem.<PlayRescue>c__Iterator0 <PlayRescue>c__Iterator = new UfoItem.<PlayRescue>c__Iterator0();
			<PlayRescue>c__Iterator.$this = this;
			return <PlayRescue>c__Iterator;
		}
	}
}
