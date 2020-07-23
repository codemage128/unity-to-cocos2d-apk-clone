using Assets.Scripts.GamePlayScene.Mechanics.Items.SpecialItems;
using System;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class GiantPinateFakeItem : Item
	{
		public GiantPinataItem MasterPinataItem;

		public Direction PositionRelativeToMaster;

		public override ItemType GetItemType()
		{
			return ItemType.GiantPinata;
		}

		public override void ChangeSorting(Sorting s)
		{
		}

		public override Sorting GetSorting()
		{
			return default(Sorting);
		}

		public override int GetScore()
		{
			return this.MasterPinataItem.GetScore();
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
			this.MasterPinataItem.PlayWrongMove();
		}

		public override void StartCollect()
		{
			this.MasterPinataItem.StartCollect();
		}

		public override bool CanShadowDrop()
		{
			return this.PositionRelativeToMaster == Direction.Up || this.PositionRelativeToMaster == Direction.RightUp;
		}

		public override void InformToBeExplodedBySpecialItem(SpecialItem specialItem, Direction comingFrom)
		{
			if (comingFrom == Direction.None && this.CurrentCell != null)
			{
				comingFrom = this.CurrentCell.GetDirectionTo(this.MasterPinataItem.CurrentCell);
			}
			this.MasterPinataItem.InformToBeExplodedBySpecialItem(specialItem, comingFrom);
		}

		public override bool TryExplode()
		{
			return this.MasterPinataItem.TryExplode();
		}

		public override void StartExplode()
		{
			this.MasterPinataItem.StartExplode();
		}
	}
}
