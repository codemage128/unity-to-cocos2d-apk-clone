using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using System;

namespace GamePlayScene.Mechanics.Items
{
	public class BlasterFakeItem : Item
	{
		public BlasterItem MasterItem;

		public override ItemType GetItemType()
		{
			return ItemType.Blaster;
		}

		public override void ChangeSorting(Sorting s)
		{
			this.MasterItem.ChangeSorting(s);
		}

		public override Sorting GetSorting()
		{
			return this.MasterItem.GetSorting();
		}

		public override bool CanFall()
		{
			return this.MasterItem.CanFall();
		}

		public override bool CanBeEffectedByDiscoBall()
		{
			return this.MasterItem.CanBeEffectedByDiscoBall();
		}

		public override bool CanBeExplodedBySpecialItem()
		{
			return this.MasterItem.CanBeExplodedBySpecialItem();
		}

		public override bool CanBeExplodedByBooster()
		{
			return this.MasterItem.CanBeExplodedByBooster();
		}

		public override bool BoosterAnvilCanBeUsed()
		{
			return this.MasterItem.BoosterAnvilCanBeUsed();
		}

		public override bool BoosterBoxingGloveCanBeUsed()
		{
			return this.MasterItem.BoosterBoxingGloveCanBeUsed();
		}

		public override bool BoosterHammerCanBeUsed()
		{
			return this.MasterItem.BoosterHammerCanBeUsed();
		}

		public override void PlayWrongMove()
		{
			this.MasterItem.PlayWrongMove();
		}

		public override void ExplodeByBlasterItem()
		{
		}

		public override bool CanCastShadow()
		{
			return true;
		}

		public override bool CanBeInsideBubble()
		{
			return this.MasterItem.CanBeInsideBubble();
		}
	}
}
