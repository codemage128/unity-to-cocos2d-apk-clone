using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.Utils;
using System;
using System.Collections;
using System.Diagnostics;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public class DiamondItem : SpriteBasedItem, IExplodeAware
	{
		public Animator CurrentAnimator;

		public SpriteRenderer OpenSpriteRenderer;

		public SpriteRenderer DiamondSpriteRenderer;

		public SpriteRenderer DoorSpriteRenderer;

		public SpriteRenderer DoorSpriteRenderer1;

		public SpriteRenderer DoorSpriteRenderer2;

		private bool _canBeExploded;

		private bool _isDestroyed;

		private int _transformToOpenHash;

		private int _transformToCloseHash;

		private void Awake()
		{
			this._transformToOpenHash = Animator.StringToHash("Base Layer.DiamondOpenAnimation");
			this._transformToCloseHash = Animator.StringToHash("Base Layer.DiamondCloseAnimation");
		}

		public void SwitchState()
		{
			if (this.CurrentCell == null || this.MasterItemExplode == Time.get_frameCount())
			{
				return;
			}
			this._canBeExploded = !this._canBeExploded;
			this.UpdateView(this._canBeExploded, true);
		}

		public void UpdateView(bool isOn, bool playParticle = true)
		{
			this._canBeExploded = isOn;
			if (playParticle && ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DiamondTransformParticle, base.get_transform().get_position(), true);
				AudioManager.Play(AudioTag.ItemDiamond1, PlayMode.Frame, null, 1f);
			}
			base.StopAllCoroutines();
			base.StartCoroutine(this.WaitAndStartAnimation(this._canBeExploded, playParticle));
		}

		[DebuggerHidden]
		private IEnumerator WaitAndStartAnimation(bool canBeExploded, bool playInstant)
		{
			DiamondItem.<WaitAndStartAnimation>c__Iterator0 <WaitAndStartAnimation>c__Iterator = new DiamondItem.<WaitAndStartAnimation>c__Iterator0();
			<WaitAndStartAnimation>c__Iterator.playInstant = playInstant;
			<WaitAndStartAnimation>c__Iterator.canBeExploded = canBeExploded;
			<WaitAndStartAnimation>c__Iterator.$this = this;
			return <WaitAndStartAnimation>c__Iterator;
		}

		public override bool CanShadowDrop()
		{
			return true;
		}

		public override void ChangeSorting(Sorting s)
		{
			int num = 0;
			if (this.CurrentCell != null)
			{
				num = 10 - this.CurrentCell.X;
			}
			this.OpenSpriteRenderer.set_sortingLayerID(s.LayerId);
			this.OpenSpriteRenderer.set_sortingOrder(s.Order + 1 + num);
			this.DiamondSpriteRenderer.set_sortingLayerID(s.LayerId);
			this.DiamondSpriteRenderer.set_sortingOrder(s.Order + 2 + num);
			this.DoorSpriteRenderer.set_sortingLayerID(s.LayerId);
			this.DoorSpriteRenderer.set_sortingOrder(s.Order + 4 + num);
			this.DoorSpriteRenderer1.set_sortingLayerID(s.LayerId);
			this.DoorSpriteRenderer1.set_sortingOrder(s.Order + 4 + num);
			this.DoorSpriteRenderer2.set_sortingLayerID(s.LayerId);
			this.DoorSpriteRenderer2.set_sortingOrder(s.Order + 3 + num);
			this.CurrentSpriteRenderer.set_sortingLayerID(s.LayerId);
			this.CurrentSpriteRenderer.set_sortingOrder(s.Order + num);
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DiamondExplosionParticle, base.get_transform().get_position(), true);
			}
		}

		public override void OnItemCreated(Level currentLevel)
		{
			base.OnItemCreated(currentLevel);
			this.CurrentLevel.ExplodeAwareItem.Add(this);
		}

		public override ItemType GetItemType()
		{
			return ItemType.Diamond;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override bool TryExplode()
		{
			if (this.LatestExplode == (long)Time.get_frameCount() || this._isDestroyed)
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			if (this.ToBeExplodedBy == ExplodeReason.Anvil || this.ToBeExplodedBy == ExplodeReason.BoxingGlove || this.ToBeExplodedBy == ExplodeReason.Hammer)
			{
				this._isDestroyed = true;
				this.ToBeExplodedBy = ExplodeReason.None;
				return true;
			}
			if (this._canBeExploded)
			{
				this._isDestroyed = true;
				return true;
			}
			return false;
		}

		public override int GetScore()
		{
			return 500;
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.ItemDiamond2, PlayMode.Frame, null, 1f);
		}

		public void ExplosionOccured(int moveCount)
		{
			if (this._isDestroyed)
			{
				return;
			}
			this.SwitchState();
		}
	}
}
