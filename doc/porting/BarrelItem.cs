using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.GamePlayScene.Mechanics.Items.SpecialItems;
using Assets.Scripts.Utils;
using DG.Tweening;
using System;
using System.Collections.Generic;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public class BarrelItem : Item
	{
		public SpriteRenderer CurrentSpriteRenderer;

		public Animator CurrentAnimator;

		public AnimationCurve AnimCurve;

		[HideInInspector]
		public int LayerCount = 3;

		private Sorting _sorting;

		private GroupId _groupId;

		private readonly int _animation2To1 = Animator.StringToHash("Base Layer.Barrel2-1");

		private Item _subItem;

		public void Init(GroupId groupId)
		{
			this._groupId = groupId;
		}

		public override ItemType GetItemType()
		{
			return ItemType.Barrel;
		}

		public override int GetScore()
		{
			return 0;
		}

		public override Sorting GetSorting()
		{
			return this._sorting;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override void RemoveAllLayers()
		{
			this.LayerCount = 1;
		}

		public override void ChangeSorting(Sorting s)
		{
			this._sorting = s;
			this.CurrentSpriteRenderer.set_sortingLayerID(s.LayerId);
			this.CurrentSpriteRenderer.set_sortingOrder(s.Order);
		}

		public override bool CanCastShadow()
		{
			return true;
		}

		public override void ExplodeByBlasterItem()
		{
			this.RemoveAllLayers();
			base.ExplodeByBlasterItem();
		}

		public override void PlayExplodeAudio()
		{
			if (ItemResourcesManager.Instance != null)
			{
				AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this.GetItemType()).AudioClips[1], PlayMode.Frame, null, 1f);
			}
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
			if (ItemResourcesManager.Instance != null)
			{
				AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this.GetItemType()).AudioClips[0], PlayMode.Frame, null, 1f);
			}
			this.StartTranformationToLayer();
			return false;
		}

		public override Item ExtractSubItem()
		{
			Dictionary<GroupId, ItemGroup> currentItemGroups = this.CurrentLevel.CurrentItemGroups;
			if (currentItemGroups != null && currentItemGroups.ContainsKey(this._groupId))
			{
				ItemType randomBarrelItemType = currentItemGroups[this._groupId].GetRandomBarrelItemType();
				this._subItem = this.CurrentLevel.CurrentLevelBuilder.CreateSpecialItemWithoutCell(randomBarrelItemType, MatchType.None, base.get_transform().get_position());
				this._subItem.get_transform().set_localScale(Vector3.get_one() * 0.5f);
				Tweener tweener = ShortcutExtensions.DOScale(this._subItem.get_transform(), 1f, 0.4f);
				TweenSettingsExtensions.SetEase<Tweener>(tweener, this.AnimCurve);
				((SpecialItem)this._subItem).StartAnimations();
				return this._subItem;
			}
			return null;
		}

		private void StartTranformationToLayer()
		{
			if (ItemResourcesManager.Instance != null)
			{
				ItemResources resources = ItemResourcesManager.Instance.GetResources(this.GetItemType());
				if (this.LayerCount == 2)
				{
					this.CurrentSpriteRenderer.set_sprite(resources.Sprites[1]);
					this.CurrentAnimator.Play(this._animation2To1, 0, 0f);
					ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this.GetItemType()).Particles[0], base.get_transform().get_position(), true);
				}
				else if (this.LayerCount == 1)
				{
					this.CurrentSpriteRenderer.set_sprite(resources.Sprites[0]);
					this.CurrentAnimator.Play(this._animation2To1, 0, 0f);
					ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this.GetItemType()).Particles[0], base.get_transform().get_position(), true);
				}
				AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this.GetItemType()).AudioClips[0], PlayMode.Frame, null, 1f);
			}
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null && ItemResourcesManager.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this.GetItemType()).Particles[1], base.get_transform().get_position(), true);
			}
		}
	}
}
