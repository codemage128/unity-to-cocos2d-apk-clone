using Assets.Scripts.DataHelpers;
using Assets.Scripts.GamePlayScene.Mechanics;
using GamePlayScene.Mechanics.Items;
using System;

namespace GamePlayScene.Mechanics
{
	public class CollectorItemsController : IReset
	{
		private static CollectorItemsController _instance;

		private int _collectorIdCounter;

		private CollectorItems<BlasterItem> _blasters;

		private CollectorItems<WallItem> _walls;

		public int CollectorIdCounter
		{
			get
			{
				return this._collectorIdCounter++;
			}
		}

		public static CollectorItemsController Instance
		{
			get
			{
				CollectorItemsController arg_17_0;
				if ((arg_17_0 = CollectorItemsController._instance) == null)
				{
					arg_17_0 = (CollectorItemsController._instance = new CollectorItemsController());
				}
				return arg_17_0;
			}
		}

		public CollectorItems<BlasterItem> GetBlasters()
		{
			CollectorItems<BlasterItem> arg_1B_0;
			if ((arg_1B_0 = this._blasters) == null)
			{
				arg_1B_0 = (this._blasters = new CollectorItems<BlasterItem>());
			}
			return arg_1B_0;
		}

		public CollectorItems<WallItem> GetWalls()
		{
			CollectorItems<WallItem> arg_1B_0;
			if ((arg_1B_0 = this._walls) == null)
			{
				arg_1B_0 = (this._walls = new CollectorItems<WallItem>());
			}
			return arg_1B_0;
		}

		public bool CanBeCollected(MatchType matchType)
		{
			return this.GetBlasters().CanBeCollected(matchType) || this.GetWalls().CanBeCollected(matchType);
		}

		public void Reset()
		{
			this._collectorIdCounter = 0;
			if (this._blasters != null)
			{
				this._blasters.Reset();
			}
			if (this._walls != null)
			{
				this._walls.Reset();
			}
		}

		public static void ResetSelf()
		{
			if (CollectorItemsController._instance != null)
			{
				CollectorItemsController._instance._blasters = null;
				CollectorItemsController._instance._walls = null;
			}
			CollectorItemsController._instance = null;
		}
	}
}
