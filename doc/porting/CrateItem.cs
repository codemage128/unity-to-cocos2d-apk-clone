using Assets.Scripts.Utils;
using System;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class CrateItem : SpriteBasedItem
	{
		[HideInInspector]
		public int LayerCount;

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

		public override ItemType GetItemType()
		{
			return ItemType.Crate;
		}

		public override void RemoveAllLayers()
		{
			this.LayerCount = 1;
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.ItemCrate1, PlayMode.Frame, null, 1f);
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
			this.StartTranformationToNewLayer();
			return false;
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.CrateExploded, base.get_transform().get_position(), true);
			}
		}

		protected virtual void StartTranformationToNewLayer()
		{
			int layerCount = this.LayerCount;
			if (layerCount == 3 || layerCount == 2 || layerCount == 1)
			{
				AudioManager.Play(AudioTag.ItemCrate23, PlayMode.Frame, null, 1f);
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.CrateLayer2Or3Exploded, base.get_transform().get_position(), true);
			}
			int num = this.LayerCount - 1;
			if (num < ImageLibrary.Instance.CrateLayerSprites.Length)
			{
				this.CurrentSpriteRenderer.set_sprite(ImageLibrary.Instance.CrateLayerSprites[num]);
			}
		}
	}
}
