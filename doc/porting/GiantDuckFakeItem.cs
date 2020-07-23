using System;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class GiantDuckFakeItem : Item
	{
		public bool IsBottomRight;

		public GiantDuckItem MasterDuck;

		public override ItemType GetItemType()
		{
			return ItemType.GiantDuck;
		}

		public override int GetScore()
		{
			return 0;
		}

		public override bool CanBeExplodedBySpecialItem()
		{
			return false;
		}

		public override bool CanBeTapped()
		{
			return false;
		}

		public override bool CanBeExplodedByBooster()
		{
			return false;
		}

		public override bool BoosterAnvilCanBeUsed()
		{
			return true;
		}

		public override bool BoosterBoxingGloveCanBeUsed()
		{
			return true;
		}

		public override bool BoosterHammerCanBeUsed()
		{
			return false;
		}

		public override void PlayWrongMove()
		{
			this.MasterDuck.PlayWrongMove();
		}

		public override bool CanFall()
		{
			return false;
		}

		public override bool CanCastShadow()
		{
			return this.IsBottomRight;
		}

		public override void ChangeSorting(Sorting s)
		{
		}

		public override Sorting GetSorting()
		{
			return DefinedSorting.Borders.GetSorting();
		}
	}
}
