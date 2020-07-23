using Assets.Scripts.GamePlayScene.Mechanics.Items.SpecialItems;
using System;
using System.Collections;
using System.Diagnostics;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items.ComboItems
{
	public class RocketAndBombItem : SpecialItem, IComboItem
	{
		public GameObject InUseObjects;

		protected MatchGroup ComboMatchGroup;

		protected int ComboMergeScores;

		private int _score;

		private const float RocketSpeed = 0.07f;

		public ParticleSystem RocketAndBombParticle1;

		public ParticleSystem RocketAndBombParticle2;

		public GameObject InUseAnimation;

		public Animator TheAnimator;

		protected override void OnExplodeSelf()
		{
		}

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
			return ItemType.RocketAndBomb;
		}

		public override int GetScore()
		{
			return 750 + this.ComboMergeScores;
		}

		private int Explode(Grid currentGrid, int x, int y)
		{
			if (x < 0 || x >= currentGrid.Width || y < 0 || y >= currentGrid.Height)
			{
				return 0;
			}
			Cell cell = currentGrid[x, y];
			Item currentItem = cell.CurrentItem;
			int num = 0;
			bool flag = false;
			if (currentItem != null)
			{
				num = currentItem.GetScore();
				flag = currentItem.CanGenerateScoreWithoutExplode();
			}
			if (this.ExplodeBySpecialItem(cell))
			{
				return SpecialItem.GetScoreForSpecialItem(currentItem, cell);
			}
			int num2 = 0;
			if (cell.HasItem && cell.CurrentItem.CanGenerateScoreOnEachTryExplode() && cell.CurrentItem.CanGenerateScoreThisTurn())
			{
				num2 += num;
			}
			else if (!cell.HasItem && flag && num > 0)
			{
				num2 += num;
			}
			if (cell.HasItem && cell.CurrentItem.IsSpecialItem())
			{
				((SpecialItem)currentItem).SpecialItemCanOnlyExplodeSelf = false;
			}
			return num2;
		}

		[DebuggerHidden]
		private IEnumerator DoHorizantalMove(HorizontalRocketItem horizontalRocketItem, Vector3 position, int height, int xAtExplodeTime, Grid currentGrid, int y, int width, int direction)
		{
			RocketAndBombItem.<DoHorizantalMove>c__Iterator0 <DoHorizantalMove>c__Iterator = new RocketAndBombItem.<DoHorizantalMove>c__Iterator0();
			<DoHorizantalMove>c__Iterator.direction = direction;
			<DoHorizantalMove>c__Iterator.horizontalRocketItem = horizontalRocketItem;
			<DoHorizantalMove>c__Iterator.width = width;
			<DoHorizantalMove>c__Iterator.position = position;
			<DoHorizantalMove>c__Iterator.y = y;
			<DoHorizantalMove>c__Iterator.height = height;
			<DoHorizantalMove>c__Iterator.xAtExplodeTime = xAtExplodeTime;
			<DoHorizantalMove>c__Iterator.currentGrid = currentGrid;
			<DoHorizantalMove>c__Iterator.$this = this;
			return <DoHorizantalMove>c__Iterator;
		}

		[DebuggerHidden]
		private IEnumerator DoVerticalMove(VerticalRocketItem verticalrocketItem, Vector3 position, int height, int yAtExplodeTime, Grid currentGrid, int x, int width, int direction)
		{
			RocketAndBombItem.<DoVerticalMove>c__Iterator1 <DoVerticalMove>c__Iterator = new RocketAndBombItem.<DoVerticalMove>c__Iterator1();
			<DoVerticalMove>c__Iterator.direction = direction;
			<DoVerticalMove>c__Iterator.verticalrocketItem = verticalrocketItem;
			<DoVerticalMove>c__Iterator.height = height;
			<DoVerticalMove>c__Iterator.position = position;
			<DoVerticalMove>c__Iterator.x = x;
			<DoVerticalMove>c__Iterator.width = width;
			<DoVerticalMove>c__Iterator.yAtExplodeTime = yAtExplodeTime;
			<DoVerticalMove>c__Iterator.currentGrid = currentGrid;
			<DoVerticalMove>c__Iterator.$this = this;
			return <DoVerticalMove>c__Iterator;
		}

		[DebuggerHidden]
		protected override IEnumerator ExplodeCells()
		{
			RocketAndBombItem.<ExplodeCells>c__Iterator2 <ExplodeCells>c__Iterator = new RocketAndBombItem.<ExplodeCells>c__Iterator2();
			<ExplodeCells>c__Iterator.$this = this;
			return <ExplodeCells>c__Iterator;
		}
	}
}
