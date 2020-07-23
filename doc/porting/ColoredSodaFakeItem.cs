using Assets.Scripts.GamePlayScene.Mechanics.Items.SpecialItems;
using System;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class ColoredSodaFakeItem : Item
	{
		public ColoredSodaItem MasterItem;

		public override ItemType GetItemType()
		{
			return ItemType.ColoredSoda;
		}

		public override void ChangeSorting(Sorting s)
		{
		}

		public override int GetScore()
		{
			return this.MasterItem.GetScore();
		}

		public override Sorting GetSorting()
		{
			return default(Sorting);
		}

		public override bool TryExplode()
		{
			return this.MasterItem.ExplodeBy(this);
		}

		public override bool CanBeExplodedBySpecialItem()
		{
			return true;
		}

		public override bool CanBeTapped()
		{
			return true;
		}

		public override bool CanBeExplodedByBooster()
		{
			return true;
		}

		public override bool CanFall()
		{
			return false;
		}

		public override bool CanCastShadow()
		{
			return false;
		}

		public override void PlayWrongMove()
		{
			this.MasterItem.PlayWrongMove();
		}

		public override void StartCollect()
		{
			this.MasterItem.StartCollect();
		}

		public override void StartExplode()
		{
			this.MasterItem.StartExplode();
		}

		public override bool CanGenerateScoreOnEachTryExplode()
		{
			return true;
		}

		public override bool CanGenerateScoreThisTurn()
		{
			return this.MasterItem.CanGenerateScoreThisTurn();
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return this.MasterItem.CanExplodeDueToExplodeInNeigbour(sourceType);
		}

		public override void InformToBeExplodedBySpecialItem(SpecialItem specialItem, Direction comingFrom)
		{
			this.MasterItem.InformToBeExplodedBySpecialItem(specialItem, comingFrom);
		}
	}
}
