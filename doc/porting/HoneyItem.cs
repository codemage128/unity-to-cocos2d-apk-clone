using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.Utils;
using System;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public class HoneyItem : SpriteBasedItem
	{
		public Animator CurrentItemAnimator;

		private bool _canFall = true;

		private int _animationHash;

		private Sorting _currentSorting;

		private bool _animationIsPlaying;

		public void Awake()
		{
			this._animationHash = Animator.StringToHash("Base Layer.HoneyItemAnimation");
		}

		public override bool CanFall()
		{
			return this._canFall;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override bool CanCastShadow()
		{
			return true;
		}

		public override bool CanShadowDrop()
		{
			return true;
		}

		public override bool TryExplode()
		{
			if (this.LatestExplode == (long)Time.get_frameCount())
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			if (this._canFall)
			{
				this._canFall = false;
				this.CurrentSpriteRenderer.set_sprite(ImageLibrary.Instance.HoneyCube);
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.HoneyTransformParticle, this.CurrentCell.GetFrozenPosition(), true);
				this.CurrentItemAnimator.Play(this._animationHash, 0, 0f);
				AudioManager.Play(AudioTag.ItemHoneyBreak, PlayMode.Frame, null, 1f);
				return false;
			}
			return true;
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.ItemHoneyExplode, PlayMode.Frame, null, 1f);
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.HoneyExplodeParticle, base.get_transform().get_position(), true);
			}
		}

		public override int GetScore()
		{
			return 500;
		}

		public override ItemType GetItemType()
		{
			return ItemType.Honey;
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

		public override void ChangeSorting(Sorting s)
		{
			if (this._animationIsPlaying)
			{
				return;
			}
			base.ChangeSorting(s);
			this._currentSorting = s;
		}
	}
}
