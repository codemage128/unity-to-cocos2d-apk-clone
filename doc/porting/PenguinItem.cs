using Assets.Scripts.CasualTools.Common.Pooling;
using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.Utils;
using System;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public class PenguinItem : SpriteBasedItem
	{
		private int _currentState = 1;

		public override ItemType GetItemType()
		{
			return ItemType.Penguin;
		}

		public override bool CanFall()
		{
			return true;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
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
			if (this._currentState > 5)
			{
				return false;
			}
			this.StartTransform();
			return this._currentState == 5;
		}

		private void StartTransform()
		{
			this._currentState++;
			ItemResources resources = ItemResourcesManager.Instance.GetResources(this.GetItemType());
			Sprite sprite = SharedImageLibrary.Instance.PenguinSprites[0];
			if (this._currentState == 2)
			{
				sprite = SharedImageLibrary.Instance.PenguinSprites[1];
				ParticlePool.Instance.PlayParticle(resources.Particles[0], this, true);
				AudioManager.PlayAudioProps(resources.AudioClips[0], PlayMode.Frame, null, 1f);
			}
			else if (this._currentState == 3)
			{
				sprite = SharedImageLibrary.Instance.PenguinSprites[2];
				ParticlePool.Instance.PlayParticle(resources.Particles[1], this, true);
				AudioManager.PlayAudioProps(resources.AudioClips[1], PlayMode.Frame, null, 1f);
			}
			else if (this._currentState == 4)
			{
				sprite = SharedImageLibrary.Instance.PenguinSprites[3];
				ParticlePool.Instance.PlayParticle(resources.Particles[2], this, true);
				AudioManager.PlayAudioProps(resources.AudioClips[1], PlayMode.Frame, null, 1f);
			}
			this.CurrentSpriteRenderer.set_sprite(sprite);
		}

		public override int GetScore()
		{
			return 500;
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this.GetItemType()).AudioClips[2], PlayMode.Frame, null, 1f);
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this.GetItemType()).Particles[3], base.get_transform().get_position(), true);
		}

		public override void RemoveAllLayers()
		{
			this._currentState = 4;
		}

		public override void ExplodeByBlasterItem()
		{
			this.RemoveAllLayers();
			base.ExplodeByBlasterItem();
		}

		public override bool CanBeCollectedWithAnimation()
		{
			return true;
		}

		public override CollectAnimation GetCollectItem()
		{
			CollectAnimation component = ItemResourcesManager.Instance.GetResources(this.GetItemType()).Animators[0].Spawn(base.get_transform().get_position()).GetComponent<CollectAnimation>();
			component.Prepare(this.CurrentLevel, this.GetItemType(), this.GetSorting(), null, this.CurrentCell);
			return component;
		}
	}
}
