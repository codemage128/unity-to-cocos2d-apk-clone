using Assets.Scripts.Utils;
using GamePlayScene.Mechanics.Items;
using System;
using System.Collections.Generic;
using UnityEngine;

namespace GamePlayScene.Mechanics
{
	public class UfoController : MonoBehaviour
	{
		private static UfoController _instance;

		private readonly List<UfoItem> _ufoItemList = new List<UfoItem>();

		public static UfoController Instance
		{
			get
			{
				if (UfoController._instance == null)
				{
					GameObject gameObject = new GameObject();
					gameObject.AddComponent<UfoController>();
					UfoController._instance = gameObject.GetComponent<UfoController>();
				}
				return UfoController._instance;
			}
		}

		public void RegisterUfoItem(UfoItem ufoItem)
		{
			this._ufoItemList.Add(ufoItem);
		}

		private void Update()
		{
			if (SlowCheckTime.ShouldPass())
			{
				return;
			}
			int i = 0;
			int count = this._ufoItemList.Count;
			while (i < count)
			{
				UfoItem ufoItem = this._ufoItemList[i];
				if (!(ufoItem == null) && !ufoItem.TrySwap())
				{
					ufoItem.TryFall();
				}
				i++;
			}
		}

		public void ResetSelf()
		{
			this._ufoItemList.Clear();
		}
	}
}
