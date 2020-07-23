using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.Utils;
using System;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public class GiftItem : Item
	{
		public GameObject SnowGlobeContainer;

		public Animator CurrentAnimator;

		public SnowParticlePlayer CurrentSnowParticlePlayer;

		public SpriteRenderer[] Renderers;

		private int _snowGlobeShakeAnimationHash;

		private int _stateId;

		private static int[] _bounceAnimationHashes;

		private static int _transformAnimationHash;

		private static int _bounceAnimationCount;

		private Sorting _currentSorting;

		private bool _canFall;

		public override bool CanFall()
		{
			return this._canFall;
		}

		public override void OnFallEnded()
		{
			base.OnFallEnded();
			if (GiftItem._bounceAnimationHashes == null)
			{
				GiftItem._bounceAnimationHashes = new int[]
				{
					Animator.StringToHash("Base Layer.SnowGlobeBounceAnimation1"),
					Animator.StringToHash("Base Layer.SnowGlobeBounceAnimation2"),
					Animator.StringToHash("Base Layer.SnowGlobeBounceAnimation3"),
					Animator.StringToHash("Base Layer.SnowGlobeBounceAnimation4"),
					Animator.StringToHash("Base Layer.SnowGlobeBounceAnimation5")
				};
			}
			GiftItem._bounceAnimationCount++;
			this.CurrentAnimator.Play(GiftItem._bounceAnimationHashes[GiftItem._bounceAnimationCount % 5], -1, 0f);
			this.CurrentSnowParticlePlayer.Shake();
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override int GetScore()
		{
			return 500;
		}

		public override ItemType GetItemType()
		{
			return ItemType.Gift;
		}

		public override void ChangeSorting(Sorting s)
		{
			for (int i = 0; i < this.Renderers.Length; i++)
			{
				SpriteRenderer spriteRenderer = this.Renderers[i];
				if (!(spriteRenderer == null))
				{
					spriteRenderer.set_sortingLayerID(s.LayerId);
					spriteRenderer.set_sortingOrder(s.Order + i * 2);
				}
			}
			this._currentSorting = s;
			Sorting s2 = s;
			s2.Order += 15;
			this.CurrentSnowParticlePlayer.UpdateSorting(s2);
		}

		public override Sorting GetSorting()
		{
			return this._currentSorting;
		}

		public override void PlayWrongMove()
		{
			base.PlayWrongMove();
			if (this._stateId == 1)
			{
				this.CurrentSnowParticlePlayer.Shake();
			}
		}

		public override void ExplodeByBlasterItem()
		{
			this._canFall = true;
			this._stateId = 1;
			base.ExplodeByBlasterItem();
		}

		public override bool TryExplode()
		{
			if (this.LatestExplode == (long)Time.get_frameCount())
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			if (this._stateId == 0)
			{
				this._stateId = 1;
				this.TransformToSnowGlobe();
				return false;
			}
			return true;
		}

		private void TransformToSnowGlobe()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(this.Resources.Particles[0], this.CurrentCell.GetFrozenPosition(), true);
			}
			AudioManager.PlayAudioProps(this.Resources.AudioClips[0], PlayMode.Frame, null, 1f);
			if (GiftItem._transformAnimationHash == 0)
			{
				GiftItem._transformAnimationHash = Animator.StringToHash("Base Layer.SnowGlobeTransitionAnimation");
			}
			this.CurrentAnimator.Play(GiftItem._transformAnimationHash, -1, 0f);
			this.SnowGlobeContainer.SetActive(true);
			this.Renderers[4].set_enabled(false);
			this.CurrentSnowParticlePlayer.get_gameObject().SetActive(true);
			this.CurrentSnowParticlePlayer.Init();
			Sorting currentSorting = this._currentSorting;
			currentSorting.Order += 15;
			this.CurrentSnowParticlePlayer.UpdateSorting(currentSorting);
			this._canFall = true;
			this.CurrentSnowParticlePlayer.Shake();
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.PlayAudioProps(this.Resources.AudioClips[1], PlayMode.Frame, null, 1f);
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(this.Resources.Particles[1], base.get_transform().get_position(), true);
			}
		}
	}
}
