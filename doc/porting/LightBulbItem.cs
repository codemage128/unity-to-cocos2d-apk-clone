using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.Utils;
using System;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class LightBulbItem : SpriteBasedItem
	{
		[HideInInspector]
		public int LayerCount = 2;

		public SpriteRenderer LightOnBulb;

		public SpriteRenderer LightOnBase;

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

		public override bool CanCastShadow()
		{
			return true;
		}

		public override void ChangeSorting(Sorting s)
		{
			this.CurrentSpriteRenderer.set_sortingLayerID(s.LayerId);
			this.CurrentSpriteRenderer.set_sortingOrder(s.Order);
			this.LightOnBulb.set_sortingLayerID(s.LayerId);
			this.LightOnBulb.set_sortingOrder(s.Order + 101);
			this.LightOnBase.set_sortingLayerID(s.LayerId);
			this.LightOnBase.set_sortingOrder(s.Order);
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.ItemLightbulb2, PlayMode.Frame, null, 1f);
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
			AudioManager.Play(AudioTag.ItemLightbulb1, PlayMode.Frame, null, 1f);
			this.StartTranformationToLayer1();
			return false;
		}

		public override CollectAnimation GetCollectItem()
		{
			CollectAnimation collectItem = base.GetCollectItem();
			collectItem.get_transform().set_position(this.CurrentSpriteRenderer.get_transform().get_position());
			return collectItem;
		}

		private void StartTranformationToLayer1()
		{
			if (this.LayerCount != 1)
			{
				return;
			}
			this.CurrentSpriteRenderer.set_enabled(false);
			this.LightOnBulb.get_gameObject().SetActive(true);
			SortingParticlePlayer sortingParticlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.LightBulbStateChange, this.RelativeContainer.get_transform().get_position(), true) as SortingParticlePlayer;
			sortingParticlePlayer.Sort(this.CurrentSpriteRenderer.get_sortingOrder() + 1, 1);
			sortingParticlePlayer.get_transform().SetParent(base.get_gameObject().get_transform());
			sortingParticlePlayer.Play();
		}

		public override ItemType GetItemType()
		{
			return ItemType.LightBulb;
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.LightBulbExplosion, base.get_transform().get_position(), true);
			}
		}
	}
}
