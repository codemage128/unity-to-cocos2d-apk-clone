using Assets.Scripts.CasualTools.Common.Logging;
using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.Logging;
using Assets.Scripts.Utils;
using System;
using UnityEngine;
using UnityEngine.Rendering;

namespace GamePlayScene.Mechanics.Items
{
	public class MoleItem : Item, IExplodeAware
	{
		public Animator CurrentAnimator;

		public SortingGroup MoleSortingGroup;

		public SpriteRenderer BoardBackSpriteRenderer;

		public SpriteRenderer BoardFrontSpriteRenderer;

		private int _upAnimationHash;

		private int _downAnimationHash;

		private Sorting _sorting;

		private int _latestTriggeredMove = -1;

		private int _state;

		private bool _isDestroyed;

		private void Awake()
		{
			this._upAnimationHash = Animator.StringToHash("Base Layer.MoleUpAnimation");
			this._downAnimationHash = Animator.StringToHash("Base Layer.MoleDownAnimation");
		}

		public override void OnItemCreated(Level currentLevel)
		{
			base.OnItemCreated(currentLevel);
			this.CurrentLevel.ExplodeAwareItem.Add(this);
		}

		public override ItemType GetItemType()
		{
			return ItemType.Mole;
		}

		public override int GetScore()
		{
			return 500;
		}

		public override bool CanCastShadow()
		{
			return false;
		}

		public override bool CanFall()
		{
			return false;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override bool CanBeCollectedWithAnimation()
		{
			return false;
		}

		public override void ChangeSorting(Sorting s)
		{
			this._sorting = s;
			int num = 8 - this.CurrentCell.Y;
			int num2 = 1200 + num * 20;
			this.BoardBackSpriteRenderer.set_sortingLayerID(this._sorting.LayerId);
			this.BoardBackSpriteRenderer.set_sortingOrder(this._sorting.Order);
			this.BoardFrontSpriteRenderer.set_sortingLayerID(this._sorting.LayerId);
			this.BoardFrontSpriteRenderer.set_sortingOrder(num2 + 2);
			this.MoleSortingGroup.set_sortingLayerID(this._sorting.LayerId);
			this.MoleSortingGroup.set_sortingOrder(num2 + 1);
		}

		public override Sorting GetSorting()
		{
			return this._sorting;
		}

		public override void ExplodeByBlasterItem()
		{
			if (this._isDestroyed)
			{
				return;
			}
			this._latestTriggeredMove = this.CurrentLevel.MovesLeft + 1;
			this._state = 1;
			base.ExplodeByBlasterItem();
		}

		public override bool TryExplode()
		{
			if (this.LatestExplode == (long)Time.get_frameCount() || this._isDestroyed)
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			int latestTriggeredMove = this._latestTriggeredMove;
			this._latestTriggeredMove = this.CurrentLevel.MovesLeft;
			if (this._state == 0)
			{
				this.MoveToState(1);
				return false;
			}
			this._isDestroyed = (latestTriggeredMove - this._latestTriggeredMove <= 1);
			return this._isDestroyed;
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null && ItemResourcesManager.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this.GetItemType()).Particles[0], base.get_transform().get_position(), true);
			}
		}

		public override void PlayExplodeAudio()
		{
			if (ItemResourcesManager.Instance != null)
			{
				AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this.GetItemType()).AudioClips[1], PlayMode.Frame, null, 1f);
			}
		}

		public void ExplosionOccured(int moveCount)
		{
			if (moveCount != this._latestTriggeredMove)
			{
				this.MoveToState(0);
			}
		}

		private void MoveToState(int i)
		{
			try
			{
				if (!this._isDestroyed && this._state != i)
				{
					ItemResources itemResources = null;
					if (ItemResourcesManager.Instance != null)
					{
						itemResources = ItemResourcesManager.Instance.GetResources(this.GetItemType());
					}
					this._state = i;
					if (i != 0)
					{
						if (i == 1)
						{
							this.CurrentAnimator.Play(this._upAnimationHash, 0, 0f);
							AudioManager.PlayAudioProps(itemResources.AudioClips[0], PlayMode.Frame, null, 1f);
						}
					}
					else
					{
						this.CurrentAnimator.Play(this._downAnimationHash, 0, 0f);
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
			}
		}
	}
}
