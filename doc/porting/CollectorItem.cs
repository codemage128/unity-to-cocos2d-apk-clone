using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using System;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public abstract class CollectorItem : Item
	{
		[HideInInspector]
		public int CollectorId;

		public MatchType MatchType
		{
			get;
			protected set;
		}

		public int Order
		{
			get;
			protected set;
		}

		public abstract void StartCollectingItem();

		public abstract void OnItemCollectCompleted();

		public abstract bool IsAvailable();
	}
}
