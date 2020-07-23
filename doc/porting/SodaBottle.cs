using System;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class SodaBottle : MonoBehaviour
	{
		public Animator CurrentAnimator;

		public SpriteRenderer[] BottleSpriteRenderers;

		public SpriteRenderer ShadowSpriteRenderer;

		public ParticleSystem ShakeParticle;

		public ParticleSystemRenderer ShakeParticleSystemRenderer;

		public SpriteRenderer BottleSpriteRenderer;

		public PeakFxColorChange CapColor;

		public PeakFxColorChange TopColor;

		private bool _isRemoved;

		private int[] _animations;

		private void Start()
		{
			this._animations = new int[]
			{
				Animator.StringToHash("Base Layer.SodaBottleShakeAnimation1"),
				Animator.StringToHash("Base Layer.SodaBottleShakeAnimation2"),
				Animator.StringToHash("Base Layer.SodaBottleShakeAnimation3"),
				Animator.StringToHash("Base Layer.SodaBottleShakeAnimation4"),
				Animator.StringToHash("Base Layer.SodaBottleShakeAnimation5")
			};
		}

		public void PlayShakeAnimation()
		{
			if (this._isRemoved)
			{
				return;
			}
			int num = this._animations[Random.Range(0, this._animations.Length)];
			this.CurrentAnimator.Play(num, 0, 0f);
			if (this.ShakeParticle != null)
			{
				this.ShakeParticle.Play();
			}
		}

		public void ChangeSorting(Sorting sorting, int order)
		{
			this.ShadowSpriteRenderer.set_sortingLayerID(sorting.LayerId);
			this.ShadowSpriteRenderer.set_sortingOrder(sorting.Order + 1);
			int num = sorting.Order + order + 1;
			int num2 = this.BottleSpriteRenderers.Length;
			for (int i = 0; i < num2; i++)
			{
				SpriteRenderer spriteRenderer = this.BottleSpriteRenderers[i];
				if (!(spriteRenderer == null))
				{
					spriteRenderer.set_sortingLayerID(sorting.LayerId);
					spriteRenderer.set_sortingOrder(num + i);
				}
			}
			this.ShakeParticleSystemRenderer.set_sortingLayerID(sorting.LayerId);
			this.ShakeParticleSystemRenderer.set_sortingOrder(num + num2);
		}

		public void Remove()
		{
			this._isRemoved = true;
			this.CurrentAnimator.StopPlayback();
		}

		public void OnDestroy()
		{
			this.Remove();
		}
	}
}
