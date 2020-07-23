using Assets.Scripts.CasualTools.Common.Tasks;
using System;
using System.Collections;
using System.Diagnostics;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class MagicHatItem : SpriteBasedItem
	{
		public GameObject CarrotParticle;

		public Animator CurrentAnimator;

		public bool SortingUpdated;

		private Sorting _sorting;

		private int _throwHash;

		public override ItemType GetItemType()
		{
			return ItemType.MagicHat;
		}

		public override bool CanFall()
		{
			return false;
		}

		public override bool CanBeTapped()
		{
			return false;
		}

		public override bool CanBeMatchable()
		{
			return false;
		}

		public override int GetScore()
		{
			return 500;
		}

		public override bool CanBeExplodedBySpecialItem()
		{
			return true;
		}

		public override bool CanBeExplodedByBooster()
		{
			return true;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override bool CanCastShadow()
		{
			return true;
		}

		public void Start()
		{
			this._throwHash = Animator.StringToHash("Base Layer.MagicHatThrowAnimation");
			this._sorting = DefinedSortingsExtensions.GetItemSorting(this.CurrentCell.Y);
			this.UpdateSorting(-1);
		}

		public override void StartCollect()
		{
			base.StopOtherAnimations();
			new Task(this.PlayCollectAnimation());
		}

		[DebuggerHidden]
		private IEnumerator PlayCollectAnimation()
		{
			MagicHatItem.<PlayCollectAnimation>c__Iterator0 <PlayCollectAnimation>c__Iterator = new MagicHatItem.<PlayCollectAnimation>c__Iterator0();
			<PlayCollectAnimation>c__Iterator.$this = this;
			return <PlayCollectAnimation>c__Iterator;
		}

		public void UpdateSorting(int order = -1)
		{
			this.CurrentSpriteRenderer.set_sortingOrder((order != -1) ? order : (this._sorting.Order + 130));
			Cell cellWithDirection = this.CurrentCell.CurrentGrid.GetCellWithDirection(this.CurrentCell, Direction.Down);
			if (cellWithDirection == null || !cellWithDirection.Exists || !cellWithDirection.HasItem || cellWithDirection.CurrentItem.GetItemType() != ItemType.MagicHat)
			{
				return;
			}
			MagicHatItem magicHatItem = cellWithDirection.CurrentItem as MagicHatItem;
			magicHatItem.UpdateSorting(this.CurrentSpriteRenderer.get_sortingOrder() + 1);
		}

		public override void ChangeSorting(Sorting s)
		{
			this._sorting = s;
			this.CurrentSpriteRenderer.set_sortingLayerID(s.LayerId);
			this.CurrentSpriteRenderer.set_sortingOrder(s.Order + 130);
		}

		public override bool CanGenerateScoreOnEachTryExplode()
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
			if (!this.CurrentLevel.CanBeCollected(ItemType.Carrot))
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
	}
}
