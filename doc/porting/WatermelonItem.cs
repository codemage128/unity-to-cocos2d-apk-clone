using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.Utils;
using System;
using System.Collections;
using System.Diagnostics;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class WatermelonItem : Item
	{
		[HideInInspector]
		public int LayerCount = 3;

		public Animator CurrentAnimator;

		private readonly int _state3To2 = Animator.StringToHash("Base Layer.Watermelon3-2");

		private readonly int _state2To1 = Animator.StringToHash("Base Layer.Watermelon2-1");

		public SpriteRenderer[] Renderers;

		private Sorting _sorting;

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override void RemoveAllLayers()
		{
			this.LayerCount = 1;
		}

		public override int GetScore()
		{
			return 500;
		}

		public override void ChangeSorting(Sorting s)
		{
			this._sorting = s;
			for (int i = 0; i < this.Renderers.Length; i++)
			{
				SpriteRenderer spriteRenderer = this.Renderers[i];
				spriteRenderer.set_sortingLayerID(s.LayerId);
				spriteRenderer.set_sortingOrder(s.Order + i);
			}
		}

		public override Sorting GetSorting()
		{
			return this._sorting;
		}

		public override bool CanCastShadow()
		{
			return true;
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.ItemWaterMelon2, PlayMode.Frame, null, 1f);
		}

		public override bool TryExplode()
		{
			if (this.LatestExplode == (long)Time.get_frameCount())
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			if (this.LayerCount == 1)
			{
				return true;
			}
			this.LayerCount--;
			AudioManager.Play(AudioTag.ItemWaterMelon1, PlayMode.Frame, null, 1f);
			this.StartTranformationToLayer();
			return false;
		}

		public override CollectAnimation GetCollectItem()
		{
			CollectAnimation collectItem = base.GetCollectItem();
			collectItem.get_transform().set_position(this.Renderers[0].get_transform().get_position());
			return collectItem;
		}

		private void StartTranformationToLayer()
		{
			if (this.LayerCount == 2)
			{
				base.StartCoroutine(this.PlayDelayedParticle(ParticlePool.Instance.WaterMelonStateParticle1));
				this.CurrentAnimator.Play(this._state3To2, 0, 0f);
			}
			else if (this.LayerCount == 1)
			{
				base.StartCoroutine(this.PlayDelayedParticle(ParticlePool.Instance.WaterMelonStateParticle2));
				this.CurrentAnimator.Play(this._state2To1, 0, 0f);
			}
			AudioManager.Play(AudioTag.ItemWaterMelon1, PlayMode.Frame, null, 1f);
		}

		[DebuggerHidden]
		private IEnumerator PlayDelayedParticle(GameObject particle)
		{
			WatermelonItem.<PlayDelayedParticle>c__Iterator0 <PlayDelayedParticle>c__Iterator = new WatermelonItem.<PlayDelayedParticle>c__Iterator0();
			<PlayDelayedParticle>c__Iterator.particle = particle;
			<PlayDelayedParticle>c__Iterator.$this = this;
			return <PlayDelayedParticle>c__Iterator;
		}

		public override ItemType GetItemType()
		{
			return ItemType.WaterMelon;
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.WaterMelonExplosionParticle, base.get_transform().get_position(), true);
			}
		}
	}
}
