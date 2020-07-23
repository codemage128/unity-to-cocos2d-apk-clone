using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.Utils;
using System;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public class HanoiItem : Item
	{
		public Animator CurrentAnimator;

		public SpriteRenderer[] SpriteRenderers;

		private int _layerCount = 4;

		private int _transformSequenceId = -1;

		private int[] _transformAnimation43;

		private int[] _transformAnimation32;

		private int[] _transformAnimation21;

		private Sorting _sorting;

		public override void OnItemCreated(Level currentLevel)
		{
			base.OnItemCreated(currentLevel);
			this._transformAnimation43 = new int[]
			{
				Animator.StringToHash("Base Layer.HanoiTransform4-3"),
				Animator.StringToHash("Base Layer.HanoiTransform4-3vers2"),
				Animator.StringToHash("Base Layer.HanoiTransform4-3vers3")
			};
			this._transformAnimation32 = new int[]
			{
				Animator.StringToHash("Base Layer.HanoiTransform3-2"),
				Animator.StringToHash("Base Layer.HanoiTransform3-2vers2"),
				Animator.StringToHash("Base Layer.HanoiTransform3-2vers3")
			};
			this._transformAnimation21 = new int[]
			{
				Animator.StringToHash("Base Layer.HanoiTransform2-1"),
				Animator.StringToHash("Base Layer.HanoiTransform2-1vers2"),
				Animator.StringToHash("Base Layer.HanoiTransform2-1vers3")
			};
		}

		public override bool CanFall()
		{
			return false;
		}

		public override bool CanBeTapped()
		{
			return false;
		}

		public override bool CanShadowDrop()
		{
			return true;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override int GetScore()
		{
			return 500;
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
					spriteRenderer.set_sortingOrder(this._sorting.Order + i);
				}
				i++;
			}
		}

		public override Sorting GetSorting()
		{
			return this._sorting;
		}

		public override ItemType GetItemType()
		{
			return ItemType.Hanoi;
		}

		public override void RemoveAllLayers()
		{
			this._layerCount = 1;
		}

		public override void ExplodeByBlasterItem()
		{
			this.RemoveAllLayers();
			base.ExplodeByBlasterItem();
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.PlayAudioProps(this.Resources.AudioClips[1], PlayMode.Frame, null, 1f);
		}

		public override bool TryExplode()
		{
			if (this.LatestExplode == (long)Time.get_frameCount())
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			if (this._layerCount == 1)
			{
				return true;
			}
			this._layerCount--;
			this.StartTranformationToNewLayer();
			return false;
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			ParticlePool.Instance.PlayParticle(this.Resources.Particles[3], base.get_transform().get_position(), true);
		}

		protected virtual void StartTranformationToNewLayer()
		{
			if (this._transformSequenceId == -1)
			{
				this._transformSequenceId = this.CurrentCell.X + this.CurrentCell.Y;
			}
			int layerCount = this._layerCount;
			if (layerCount != 3)
			{
				if (layerCount != 2)
				{
					if (layerCount == 1)
					{
						this.CurrentAnimator.Play(this._transformAnimation21[this._transformSequenceId % 3], -1, 0f);
					}
				}
				else
				{
					this.CurrentAnimator.Play(this._transformAnimation32[this._transformSequenceId % 3], -1, 0f);
				}
			}
			else
			{
				this.CurrentAnimator.Play(this._transformAnimation43[this._transformSequenceId % 3], -1, 0f);
			}
			int num = 3 - this._layerCount;
			AudioManager.PlayAudioProps(this.Resources.AudioClips[0], PlayMode.Frame, null, 1f);
			AudioManager.FilterQueue(AudioTag.ClassicExplode);
			ParticlePlayer particlePlayer = ParticlePool.Instance.PlayParticle(this.Resources.Particles[num], base.get_transform().get_position(), true);
			Quaternion identity = Quaternion.get_identity();
			identity.set_eulerAngles((Random.Range(0, 10) <= 5) ? new Vector3(0f, 0f, 0f) : new Vector3(0f, 180f, 0f));
			particlePlayer.MainParticle.get_transform().set_rotation(identity);
		}
	}
}
