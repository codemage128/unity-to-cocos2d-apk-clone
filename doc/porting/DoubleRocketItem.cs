using Assets.Scripts.GamePlayScene.Mechanics.Items.SpecialItems;
using DG.Tweening;
using System;
using System.Collections;
using System.Diagnostics;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items.ComboItems
{
	public class DoubleRocketItem : SpecialItem, IComboItem
	{
		private Grid _grid;

		private int _height;

		private float _screenDown;

		private float _screenLeft;

		private float _screenRight;

		private float _screenUp;

		private float _startDurationH;

		private float _startDurationV;

		private int _sx;

		private int _sy;

		private int _width;

		public Transform HeadDown;

		public Transform HeadLeft;

		public Transform HeadRight;

		public Transform HeadUp;

		public GameObject HorizontalAnimation;

		public ParticleSystem TrailParticleDown;

		public ParticleSystem TrailParticleLeft;

		public ParticleSystem TrailParticleRight;

		public ParticleSystem TrailParticleUp;

		public GameObject VerticalAnimation;

		protected MatchGroup ComboMatchGroup;

		protected int ComboMergeScores;

		private int _score;

		private float _exitTime;

		private bool _waitLastRocketExit = true;

		public void SetComboGroup(MatchGroup mgroup)
		{
			this.ComboMatchGroup = mgroup;
		}

		public void AddScore(int v)
		{
			this.ComboMergeScores += v;
		}

		public override ItemType GetItemType()
		{
			return ItemType.DoubleRocket;
		}

		public override bool CanBeCapturedByJelly()
		{
			return false;
		}

		public override bool ShouldRejectFallInside()
		{
			return false;
		}

		protected override void OnExplodeSelf()
		{
			ParticlePool.Instance.PlayParticle(ParticlePool.Instance.ComboCreationParticle, this.CurrentCell.GetFrozenPosition(), true);
		}

		[DebuggerHidden]
		protected override IEnumerator ExplodeCells()
		{
			DoubleRocketItem.<ExplodeCells>c__Iterator0 <ExplodeCells>c__Iterator = new DoubleRocketItem.<ExplodeCells>c__Iterator0();
			<ExplodeCells>c__Iterator.$this = this;
			return <ExplodeCells>c__Iterator;
		}

		[DebuggerHidden]
		private IEnumerator Die()
		{
			DoubleRocketItem.<Die>c__Iterator1 <Die>c__Iterator = new DoubleRocketItem.<Die>c__Iterator1();
			<Die>c__Iterator.$this = this;
			return <Die>c__Iterator;
		}

		public override int GetScore()
		{
			return 500 + this.ComboMergeScores;
		}

		private void StepRocketH(Transform rocket, int step, int direction, Sequence seq)
		{
			int num = this._sx + step * direction;
			bool flag = num >= 0 && num < this._width;
			int num2 = num + direction;
			float num3 = (step != 1) ? HorizontalRocketItem.ExplodeTime : this._startDurationH;
			float num4 = (step != 1) ? (HorizontalRocketItem.ExplodeTime * (float)(step - 2) + this._startDurationH) : 0f;
			float num5 = rocket.get_position().x + ((float)step - HorizontalRocketItem.Offset) * (float)direction;
			seq.Insert(num4, rocket.DOMoveX(num5, num3, false).SetEase(Ease.Linear));
			if (flag)
			{
				seq.InsertCallback(num4 + num3, this.ExplodeLater(this._grid, num, this._sy));
			}
			if (num2 >= this._width)
			{
				float duration = (this._screenRight - num5) * HorizontalRocketItem.ExplodeTime;
				float num6 = num4 + num3;
				this._exitTime = Mathf.Max(num6, this._exitTime);
				seq.Insert(num6, rocket.DOMoveX(this._screenRight, duration, false).SetEase(Ease.Linear));
			}
			else if (num2 < 0)
			{
				float duration2 = -(this._screenLeft - num5) * HorizontalRocketItem.ExplodeTime;
				float num7 = num4 + num3;
				this._exitTime = Mathf.Max(num7, this._exitTime);
				seq.Insert(num7, rocket.DOMoveX(this._screenLeft, duration2, false).SetEase(Ease.Linear));
			}
		}

		private void StepRocketV(Transform rocket, int step, int direction, Sequence seq)
		{
			int num = this._sy + step * direction;
			bool flag = num >= 0 && num < this._height;
			int num2 = num + direction;
			float num3 = (step != 1) ? HorizontalRocketItem.ExplodeTime : this._startDurationV;
			float num4 = (step != 1) ? (HorizontalRocketItem.ExplodeTime * (float)(step - 2) + this._startDurationV) : 0f;
			float num5 = rocket.get_position().y + ((float)step - HorizontalRocketItem.Offset) * (float)direction;
			seq.Insert(num4, rocket.DOMoveY(num5, num3, false).SetEase(Ease.Linear));
			if (flag)
			{
				seq.InsertCallback(num4 + num3, this.ExplodeLater(this._grid, this._sx, num));
			}
			if (num2 >= this._height)
			{
				float duration = (this._screenUp - num5) * HorizontalRocketItem.ExplodeTime;
				float num6 = num4 + num3;
				this._exitTime = Mathf.Max(num6, this._exitTime);
				seq.Insert(num6, rocket.DOMoveY(this._screenUp, duration, false).SetEase(Ease.Linear));
			}
			else if (num2 < 0)
			{
				float duration2 = -(this._screenDown - num5) * HorizontalRocketItem.ExplodeTime;
				float num7 = num4 + num3;
				this._exitTime = Mathf.Max(num7, this._exitTime);
				seq.Insert(num7, rocket.DOMoveY(this._screenDown, duration2, false).SetEase(Ease.Linear));
			}
		}

		private void AllowFalls()
		{
			foreach (Cell current in this.ComboMatchGroup.AllCells)
			{
				current.AcceptsFallInside();
			}
			ScoreManager.RaiseScore(this._score, this._grid[this._sx, this._sy].GetFrozenPosition(), MatchType.None);
			FallManager.DecreaseWaitingFallBlocker();
			this._waitLastRocketExit = false;
			if (base.get_gameObject().get_activeSelf())
			{
				base.StartCoroutine(this.Die());
			}
			else
			{
				this.RemoveSelf();
			}
		}

		protected TweenCallback ExplodeLater(Grid currentGrid, int x, int y)
		{
			return delegate
			{
				if (x < 0 || x >= currentGrid.Width || y < 0 || y >= currentGrid.Height)
				{
					return;
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
					this._score += SpecialItem.GetScoreForSpecialItem(currentItem, cell);
				}
				else if (cell.HasItem && cell.CurrentItem.CanGenerateScoreOnEachTryExplode() && cell.CurrentItem.CanGenerateScoreThisTurn())
				{
					this._score += currentItem.GetScore();
				}
				else if (!cell.HasItem && flag && num > 0)
				{
					this._score += num;
				}
			};
		}
	}
}
