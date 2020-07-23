using Assets.Scripts.CasualTools.Common.Pooling;
using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.Utils;
using System;
using System.Collections.Generic;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public class BirdHouseItem : SpriteBasedItem
	{
		public Animator CurrentAnimator;

		public SpriteRenderer[] SortingLayers;

		public static readonly List<BirdHouseItem> BirdHouseItems = new List<BirdHouseItem>();

		private Sorting _sorting;

		private int _throwHash;

		public void Start()
		{
			this._throwHash = Animator.StringToHash("Base Layer.BirdHouseThrowAnimation");
			this._sorting = DefinedSortingsExtensions.GetItemSorting(this.CurrentCell.Y);
		}

		public override ItemType GetItemType()
		{
			return ItemType.BirdHouse;
		}

		public override int GetScore()
		{
			return 500;
		}

		public override bool CanFall()
		{
			return false;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override bool CanGenerateScoreOnEachTryExplode()
		{
			return true;
		}

		public override bool CanBeInsideBubble()
		{
			return false;
		}

		public override bool CanCastShadow()
		{
			return true;
		}

		public override void OnItemCreated(Level currentLevel)
		{
			base.OnItemCreated(currentLevel);
			BirdHouseItem.BirdHouseItems.Add(this);
		}

		public override void ChangeSorting(Sorting s)
		{
			this._sorting = s;
			if (this.SortingLayers.Length == 0)
			{
				return;
			}
			int i = 0;
			int num = this.SortingLayers.Length;
			while (i < num)
			{
				SpriteRenderer spriteRenderer = this.SortingLayers[i];
				if (!(spriteRenderer == null))
				{
					spriteRenderer.set_sortingLayerID(this._sorting.LayerId);
					spriteRenderer.set_sortingOrder(this._sorting.Order + i);
				}
				i++;
			}
		}

		public override bool TryExplode()
		{
			if (this.LatestExplode == (long)Time.get_frameCount())
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			if (!this.CurrentLevel.CanBeCollected(ItemType.Bird))
			{
				return false;
			}
			this.StartCollect();
			if (this.CanRaiseScore())
			{
				ScoreManager.RaiseScore(this.GetScore(), base.get_transform().get_position(), MatchType.None);
			}
			return false;
		}

		public override void StartCollect()
		{
			base.StopOtherAnimations();
			this.PlayCollectAnimation();
		}

		private void PlayCollectAnimation()
		{
			this.CurrentAnimator.Play(this._throwHash, 0, 0f);
			CollectAnimation component = ItemResourcesManager.Instance.GetResources(this.GetItemType()).Animators[0].Spawn(base.get_transform().get_position()).GetComponent<CollectAnimation>();
			component.Prepare(this.CurrentLevel, ItemType.Bird, DefinedSorting.Collecting.GetSorting(), SharedImageLibrary.Instance.BirdSprite, this.CurrentCell).StartAnimation();
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this.GetItemType()).AudioClips[1], PlayMode.Frame, null, 1f);
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null && ItemResourcesManager.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this.GetItemType()).Particles[1], base.get_transform().get_position(), true);
			}
		}

		public static void ClearAllBirdHouses()
		{
			if (LevelBuilder.ActiveLevel == null)
			{
				return;
			}
			int i = 0;
			int count = BirdHouseItem.BirdHouseItems.Count;
			while (i < count)
			{
				BirdHouseItem birdHouseItem = BirdHouseItem.BirdHouseItems[i];
				if (birdHouseItem != null)
				{
					birdHouseItem.StartExplode();
				}
				i++;
			}
			BirdHouseItem.BirdHouseItems.Clear();
		}
	}
}
