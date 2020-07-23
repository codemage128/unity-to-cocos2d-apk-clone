using Assets.Scripts.GamePlayScene.Mechanics;
using GamePlayScene.Mechanics.Items;
using System;
using System.Collections.Generic;

namespace GamePlayScene.Mechanics
{
	public class CollectorItems<T> where T : CollectorItem
	{
		private Dictionary<MatchType, SortedList<int, T>> _items;

		private readonly Queue<int> _launchQueue = new Queue<int>();

		private int _nextExplodeId = -1;

		private int _readyToExplodeCount;

		public int NextExplodeId
		{
			get
			{
				return this._nextExplodeId;
			}
		}

		public void Reset()
		{
			if (this._items != null)
			{
				this._items.Clear();
			}
			this._launchQueue.Clear();
			this._nextExplodeId = -1;
			this._readyToExplodeCount = 0;
		}

		public int Register(T item)
		{
			if (this._items == null)
			{
				this._items = new Dictionary<MatchType, SortedList<int, T>>();
			}
			if (!this._items.ContainsKey(item.MatchType))
			{
				this._items.Add(item.MatchType, new SortedList<int, T>());
			}
			this._items[item.MatchType].Add(item.Order, item);
			return CollectorItemsController.Instance.CollectorIdCounter;
		}

		public void UnRegister(T item)
		{
			if (this._items == null || !this._items.ContainsKey(item.MatchType))
			{
				return;
			}
			if (this._items[item.MatchType].ContainsKey(item.Order))
			{
				this._items[item.MatchType].Remove(item.Order);
			}
			if (this._items[item.MatchType].Count == 0)
			{
				this._items.Remove(item.MatchType);
			}
		}

		public T GetActiveItem(MatchType matchType)
		{
			if (this._items == null || !this._items.ContainsKey(matchType) || this._items[matchType] == null || this._items[matchType].Values.Count == 0)
			{
				return (T)((object)null);
			}
			T t = this._items[matchType].Values[0];
			bool flag = this._items[matchType].Values.Count > 1;
			if (!t.IsAvailable() && flag)
			{
				this._items[t.MatchType].Remove(t.Order);
				if (this._items[matchType].Values.Count == 0)
				{
					return (T)((object)null);
				}
			}
			return this._items[matchType].Values[0];
		}

		public bool CanBeCollected(MatchType matchType)
		{
			return this._items != null && this._items.ContainsKey(matchType) && this._items[matchType] != null;
		}

		public void AddToQueue(int blasterId)
		{
			if (this._launchQueue.Contains(blasterId))
			{
				return;
			}
			this._launchQueue.Enqueue(blasterId);
			this._nextExplodeId = this._launchQueue.Peek();
			this._readyToExplodeCount++;
		}

		public int WaitingToLaunchCount()
		{
			return this._readyToExplodeCount;
		}

		public void RemoveNextLaunchItem()
		{
			if (this._launchQueue.Count == 0)
			{
				return;
			}
			this._launchQueue.Dequeue();
			if (this._launchQueue.Count > 0)
			{
				this._nextExplodeId = this._launchQueue.Peek();
			}
			this._readyToExplodeCount--;
		}
	}
}
