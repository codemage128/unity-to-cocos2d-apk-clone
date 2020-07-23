using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;

namespace GamePlayScene.Mechanics.Items
{
	public abstract class GeneratorBasedItem : Item
	{
		protected ItemType GenerateItemType;

		protected int GenerateCount = 1;

		protected int GenerateInverval = 1;

		protected int IntervalCounter;

		private readonly List<Cell> _targetCellList = new List<Cell>();

		private bool _waiting;

		public override ItemType GetItemType()
		{
			throw new NotImplementedException();
		}

		public override void ChangeSorting(Sorting s)
		{
			throw new NotImplementedException();
		}

		public override Sorting GetSorting()
		{
			throw new NotImplementedException();
		}

		public abstract void Sleep();

		public abstract Cell GetRandomCell();

		public abstract void PlayThrowAnimation(List<Cell> targetCells);

		protected void StartGeneratingItems()
		{
			base.StartCoroutine(this.GenerateItems());
		}

		[DebuggerHidden]
		private IEnumerator GenerateItems()
		{
			GeneratorBasedItem.<GenerateItems>c__Iterator0 <GenerateItems>c__Iterator = new GeneratorBasedItem.<GenerateItems>c__Iterator0();
			<GenerateItems>c__Iterator.$this = this;
			return <GenerateItems>c__Iterator;
		}

		protected virtual void OnThrowAnimationComplete(Cell targetCell)
		{
			if (targetCell != null)
			{
				targetCell.ApplyReservedItem();
			}
			this.CurrentLevel.DecreaseItemCount(this.GenerateItemType);
		}
	}
}
