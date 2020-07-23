using System;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class CanTossFakeItem : Item, ICanExplodeAtLeast2
	{
		public CanTossItem MasterCanToss;

		public override ItemType GetItemType()
		{
			return ItemType.CanToss;
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
			return 250;
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

		public override bool CanGenerateScoreOnEachTryExplode()
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
			this.MasterCanToss.PlayWrongMove();
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override void StartCollect()
		{
			this.MasterCanToss.StartCollect();
		}

		public override bool TryExplode()
		{
			return this.MasterCanToss.ExplodeBy(this);
		}

		public override void StartExplode()
		{
			this.MasterCanToss.StartExplode();
		}

		public void CheckIfExtraExplodeNeeded()
		{
			this.MasterCanToss.CheckIfExtraExplodeNeeded();
		}

		public void MarkShouldExplodeAtLeast2()
		{
			this.MasterCanToss.MarkShouldExplodeAtLeast2();
		}
	}
}
