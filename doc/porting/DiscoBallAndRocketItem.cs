using Assets.Scripts.GamePlayScene.Mechanics.Items.SpecialItems;
using DG.Tweening;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Runtime.CompilerServices;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items.ComboItems
{
	public class DiscoBallAndRocketItem : DiscoBallItem, IComboItem
	{
		protected MatchGroup ComboMatchGroup;

		protected int ComboMergeScores;

		protected List<SpecialItem> ChangedItems = new List<SpecialItem>();

		protected List<SpecialItem> CreatedItems = new List<SpecialItem>(10);

		private bool _destoyed;

		[CompilerGenerated]
		private static Comparison<SpecialItem> <>f__mg$cache0;

		public void SetComboGroup(MatchGroup mgroup)
		{
			this.ComboMatchGroup = mgroup;
		}

		public override bool CanBeCapturedByJelly()
		{
			return false;
		}

		public void AddScore(int v)
		{
			this.ComboMergeScores += v;
		}

		public override ItemType GetItemType()
		{
			return ItemType.DiscoBallAndRocket;
		}

		public override bool CanRaiseScore()
		{
			return true;
		}

		public override int GetScore()
		{
			return 1250 + this.ComboMergeScores;
		}

		[DebuggerHidden]
		protected override IEnumerator OnRayReached(Cell c, Item i, Tweener tweener, ParticlePlayer p)
		{
			DiscoBallAndRocketItem.<OnRayReached>c__Iterator0 <OnRayReached>c__Iterator = new DiscoBallAndRocketItem.<OnRayReached>c__Iterator0();
			<OnRayReached>c__Iterator.tweener = tweener;
			<OnRayReached>c__Iterator.c = c;
			<OnRayReached>c__Iterator.$this = this;
			return <OnRayReached>c__Iterator;
		}

		public override void RemoveSelf()
		{
			this.OnBeforeRemove();
			if (!this._destoyed)
			{
				Object.Destroy(base.get_gameObject());
			}
		}

		private static int Sorter(Item a, Item b)
		{
			Cell currentCell = a.CurrentCell;
			Cell currentCell2 = b.CurrentCell;
			return (currentCell2.Y - currentCell.Y) * 1000 - (currentCell2.X - currentCell.X);
		}

		[DebuggerHidden]
		protected override IEnumerator DoDiscoExpldoes(List<Cell> explodeCells)
		{
			DiscoBallAndRocketItem.<DoDiscoExpldoes>c__Iterator1 <DoDiscoExpldoes>c__Iterator = new DiscoBallAndRocketItem.<DoDiscoExpldoes>c__Iterator1();
			<DoDiscoExpldoes>c__Iterator.$this = this;
			return <DoDiscoExpldoes>c__Iterator;
		}

		[DebuggerHidden]
		protected virtual IEnumerator PlayDiscoExplodes()
		{
			DiscoBallAndRocketItem.<PlayDiscoExplodes>c__Iterator2 <PlayDiscoExplodes>c__Iterator = new DiscoBallAndRocketItem.<PlayDiscoExplodes>c__Iterator2();
			<PlayDiscoExplodes>c__Iterator.$this = this;
			return <PlayDiscoExplodes>c__Iterator;
		}

		public override bool ShouldRejectFallInside()
		{
			return false;
		}

		public override bool ShouldBlockFalls()
		{
			return false;
		}

		public void OnDestroy()
		{
			this._destoyed = true;
		}

		protected override void DoDie()
		{
			if (this.ShouldBlockFalls())
			{
				FallManager.DecreaseWaitingFallBlocker();
			}
			if (this._destoyed)
			{
				return;
			}
			ScoreManager.RaiseScore(this.Score + this.ComboMergeScores, base.get_transform().get_position(), MatchType.None);
			FallManager.DecreaseMechanicAnimation();
			this.RemoveSelf();
		}

		protected virtual SpecialItem CreateSpecialItem(Grid theGrid, Cell c)
		{
			HorizontalRocketItem horizontalRocketItem = theGrid.CurrentLevel.CurrentLevelBuilder.CreateRandomRocket(c.GetFrozenPosition());
			horizontalRocketItem.AllowBlockFalls();
			return horizontalRocketItem;
		}
	}
}
