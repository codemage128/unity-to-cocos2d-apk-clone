using Assets.Scripts.GamePlayScene.Mechanics.Items;
using System;
using System.Collections.Generic;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics
{
	public class JellyManager
	{
		private readonly Level _level;

		private readonly List<JellyItem> _items = new List<JellyItem>();

		private readonly List<CellPairs> _candidateCells = new List<CellPairs>(16);

		private readonly List<CellPairs> _candidateCellsSecondary = new List<CellPairs>(16);

		private int _jellyExplodedAtMovesLeft;

		private int _specialItemsInAction;

		private bool _jellyExplodedInSpecialItemChain;

		private bool _disabled;

		public JellyManager(Level level)
		{
			this._level = level;
		}

		public void Spread()
		{
			if (this._disabled || this._specialItemsInAction > 0 || this._level.MovesLeft == this._jellyExplodedAtMovesLeft)
			{
				return;
			}
			this.SpreadWithoutControl();
		}

		public void Add(JellyItem jellyItem)
		{
			this._items.Add(jellyItem);
			this._level.IncreaseGoal(ItemType.Jelly);
		}

		public void Remove(JellyItem jellyItem)
		{
			this._items.Remove(jellyItem);
		}

		public void InformJellyExplode()
		{
			if (this._specialItemsInAction == 0)
			{
				this._jellyExplodedAtMovesLeft = this._level.MovesLeft;
			}
		}

		public void WaitSpecialItem()
		{
			this._specialItemsInAction++;
		}

		public bool AreThereSpecialItemsInAction()
		{
			return this._specialItemsInAction > 0;
		}

		public void SpecialItemEnded(bool jellyExploded)
		{
			this._specialItemsInAction--;
			if (!this._jellyExplodedInSpecialItemChain && jellyExploded)
			{
				this._jellyExplodedInSpecialItemChain = true;
			}
			if (this._specialItemsInAction > 0)
			{
				return;
			}
			if (!this._jellyExplodedInSpecialItemChain && !this._disabled)
			{
				this.SpreadWithoutControl();
				this._jellyExplodedAtMovesLeft = this._level.MovesLeft;
			}
			this._specialItemsInAction = 0;
			this._jellyExplodedInSpecialItemChain = false;
		}

		private void SpreadWithoutControl()
		{
			int count = this._items.Count;
			if (count <= 0)
			{
				return;
			}
			this._candidateCells.Clear();
			this._candidateCellsSecondary.Clear();
			for (int i = 0; i < count; i++)
			{
				JellyItem jellyItem = this._items[i];
				Cell currentCell = jellyItem.CurrentCell;
				if (!(currentCell == null))
				{
					for (int j = 0; j < currentCell.GetCachedNeigbours(false).Length; j++)
					{
						Cell cell = currentCell.GetCachedNeigbours(false)[j];
						if (!cell.HasItem)
						{
							this._candidateCells.Add(new CellPairs(currentCell, cell));
						}
						else if (cell.CurrentItem.CanBeCapturedByJelly())
						{
							if (cell.CurrentItem.IsSpecialItem())
							{
								this._candidateCellsSecondary.Add(new CellPairs(currentCell, cell));
							}
							else
							{
								this._candidateCells.Add(new CellPairs(currentCell, cell));
							}
						}
					}
				}
			}
			CellPairs? cellPairs = null;
			if (this._candidateCells.Count > 0)
			{
				cellPairs = new CellPairs?(this._candidateCells[Random.Range(0, this._candidateCells.Count)]);
			}
			else if (this._candidateCellsSecondary.Count > 0)
			{
				cellPairs = new CellPairs?(this._candidateCellsSecondary[Random.Range(0, this._candidateCellsSecondary.Count)]);
			}
			if (!cellPairs.HasValue)
			{
				return;
			}
			CellPairs value = cellPairs.Value;
			JellyItem jellyItem2 = value.FromCell.CurrentItem as JellyItem;
			if (jellyItem2 != null)
			{
				jellyItem2.PlayJellySpread(value.ToCell);
			}
		}

		public void ResetExplodeCounter()
		{
			this._jellyExplodedAtMovesLeft = -100000;
		}

		public void Disable()
		{
			this._disabled = true;
		}
	}
}
