using Assets.Scripts.CasualTools.Common.Pooling;
using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.Utils;
using System;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class OysterItem : SpriteBasedItem, IExplodeAware
	{
		public Animator CurrentAnimator;

		public SpriteRenderer[] SpriteRenderers;

		private int _latestTriggeredCount = -1;

		private int _state;

		private int _latestFrame;

		private bool _isDestroyed;

		private int _openAnimationHash;

		private int _closeAnimationHash;

		private Sorting _currentSorting;

		private bool _animationIsPlaying;

		public void Awake()
		{
			this._openAnimationHash = Animator.StringToHash("Base Layer.OysterOpenAnimation");
			this._closeAnimationHash = Animator.StringToHash("Base Layer.OysterCloseAnimation");
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override void OnItemCreated(Level currentLevel)
		{
			base.OnItemCreated(currentLevel);
			this.CurrentLevel.ExplodeAwareItem.Add(this);
		}

		public override void ChangeSorting(Sorting s)
		{
			if (this._animationIsPlaying)
			{
				return;
			}
			base.ChangeSorting(s);
			this._currentSorting = s;
			int num = this.SpriteRenderers.Length;
			for (int i = 0; i < num; i++)
			{
				SpriteRenderer spriteRenderer = this.SpriteRenderers[i];
				if (!(spriteRenderer == null))
				{
					spriteRenderer.set_sortingLayerID(s.LayerId);
					spriteRenderer.set_sortingOrder(s.Order + i);
				}
			}
		}

		public override bool TryExplode()
		{
			if (this.LatestExplode == (long)Time.get_frameCount())
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			int latestTriggeredCount = this._latestTriggeredCount;
			this._latestTriggeredCount = this.CurrentLevel.MovesLeft;
			if (this._state == 0)
			{
				this.MoveToState(1);
				return false;
			}
			this._isDestroyed = (latestTriggeredCount - this._latestTriggeredCount <= 1);
			if (this._isDestroyed)
			{
				AudioManager.Play(AudioTag.OysterExplode, PlayMode.Frame, null, 1f);
				this.CurrentLevel.ExplodeAwareItem.Remove(this);
			}
			return this._isDestroyed;
		}

		public override ItemType GetItemType()
		{
			return ItemType.Oyster;
		}

		public override int GetScore()
		{
			return 500;
		}

		public override bool CanCastShadow()
		{
			return true;
		}

		public override CollectAnimation GetCollectItem()
		{
			Sorting currentSorting = this._currentSorting;
			if (this.CurrentCell != null)
			{
				currentSorting.Order = 1490 - this.CurrentCell.Y;
			}
			else
			{
				currentSorting.Order = 1490;
			}
			CollectAnimation component = this.CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(this.CurrentSpriteRenderer.get_transform().get_position()).GetComponent<CollectAnimation>();
			component.Prepare(this.CurrentLevel, this.GetItemType(), currentSorting, ImageLibrary.Instance.Pearl, this.CurrentCell);
			return component;
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.OysterExplosionParticle, base.get_transform().get_position(), true);
			}
		}

		public void ExplosionOccured(int moveCount)
		{
			if (moveCount != this._latestTriggeredCount)
			{
				this.MoveToState(0);
			}
		}

		private void MoveToState(int i)
		{
			if (this._isDestroyed || this.CurrentSpriteRenderer == null || this._state == i)
			{
				return;
			}
			this._state = i;
			if (i != 0)
			{
				if (i == 1)
				{
					this.CurrentAnimator.Play(this._openAnimationHash, 0, 0f);
					if (ParticlePool.Instance != null)
					{
						ParticlePool.Instance.PlayParticle(ParticlePool.Instance.OysterOpenParticle, this, true);
					}
					AudioManager.Play(AudioTag.OysterOpen, PlayMode.Frame, null, 1f);
				}
			}
			else
			{
				this.CurrentAnimator.Play(this._closeAnimationHash, 0, 0f);
				if (ParticlePool.Instance != null)
				{
					ParticlePool.Instance.PlayParticle(ParticlePool.Instance.OysterCloseParticle, this, true);
				}
			}
		}

		public void BringToFront()
		{
			int order = 1300;
			if (this.CurrentCell != null)
			{
				order = 1300 + (10 - this.CurrentCell.Y * 10);
			}
			this._currentSorting.Order = order;
			this.ChangeSorting(this._currentSorting);
			this._animationIsPlaying = true;
		}

		public void SendToBack()
		{
			this._animationIsPlaying = false;
			this.OnCellChanged();
		}
	}
}
