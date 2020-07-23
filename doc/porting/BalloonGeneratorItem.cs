using Assets.Scripts.CasualTools.Common.Pooling;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.Utils;
using GamePlayScene.Mechanics.Animations;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public class BalloonGeneratorItem : GeneratorBasedItem
	{
		public Animator CurrentAnimator;

		public Transform Container;

		public SpriteRenderer[] SpriteRenderers;

		private int _throwHash;

		private int _sleepHash;

		private int _direction;

		private bool _isSleeping;

		public void Start()
		{
			this.GenerateCount = 1;
			this.GenerateInverval = 1;
			this._throwHash = Animator.StringToHash("Base Layer.BalloonGeneratorThrow");
			this._sleepHash = Animator.StringToHash("Base Layer.BalloonGeneratorSleep");
			this.ChangeSorting(this.GetSorting());
		}

		public override void ChangeSorting(Sorting s)
		{
			int num = (int)base.get_transform().get_localPosition().x;
			int num2 = (int)(8f - base.get_transform().get_localPosition().y);
			int num3 = this.SpriteRenderers.Length;
			for (int i = 0; i < num3; i++)
			{
				if (!(this.SpriteRenderers[i] == null))
				{
					this.SpriteRenderers[i].set_sortingLayerID(s.LayerId);
					this.SpriteRenderers[i].set_sortingOrder(i + (1200 + num2 * 20) + 10 * ((this._direction != 0) ? num : (10 - num)));
				}
			}
		}

		public override Sorting GetSorting()
		{
			return new Sorting(this.SpriteRenderers[0].get_sortingLayerID(), this.SpriteRenderers[0].get_sortingOrder());
		}

		public override void OnItemCreated(Level currentLevel)
		{
			base.OnItemCreated(currentLevel);
			this.GenerateItemType = ItemType.Balloon;
			ItemGeneratorController.Instance.RegisterGenerator(this.GenerateItemType, this);
		}

		public override ItemType GetItemType()
		{
			return ItemType.BalloonGenerator;
		}

		public override bool CanFall()
		{
			return false;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override int GetScore()
		{
			return 0;
		}

		public override bool TryExplode()
		{
			if (this.LatestExplode == (long)Time.get_frameCount())
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			base.StartGeneratingItems();
			return false;
		}

		public override void Sleep()
		{
			this.CurrentAnimator.Play(this._sleepHash, 0, 0f);
			this._isSleeping = true;
		}

		public override Cell GetRandomCell()
		{
			return ItemGeneratorController.Instance.GetRandomCell();
		}

		public override void PlayThrowAnimation(List<Cell> targetCells)
		{
			if (targetCells == null || targetCells.Count <= 0)
			{
				return;
			}
			int count = targetCells.Count;
			for (int i = 0; i < count; i++)
			{
				GameObject gameObject = this.CurrentLevel.CurrentLevelBuilder.BalloonGeneratorThrowAnimation.Spawn();
				BalloonGeneratorThrowAnimation component = gameObject.GetComponent<BalloonGeneratorThrowAnimation>();
				component.Prepare(this.CurrentCell, targetCells[i], this._direction, new Action<Cell>(this.OnThrowAnimationComplete));
				this.CurrentAnimator.Play(this._throwHash, 0, 0f);
				AudioManager.Play(AudioTag.ItemBalloonGeneratorThrow, PlayMode.Frame, null, 1f);
			}
			base.StartCoroutine(this.ThrowCompleted());
		}

		[DebuggerHidden]
		private IEnumerator ThrowCompleted()
		{
			BalloonGeneratorItem.<ThrowCompleted>c__Iterator0 <ThrowCompleted>c__Iterator = new BalloonGeneratorItem.<ThrowCompleted>c__Iterator0();
			<ThrowCompleted>c__Iterator.$this = this;
			return <ThrowCompleted>c__Iterator;
		}

		public void SetDirection(int direction)
		{
			this._direction = direction;
			if (this._direction == 1)
			{
				this.Container.get_transform().set_localScale(new Vector3(-1f, 1f, 1f));
				Quaternion.get_identity().set_eulerAngles(new Vector3(0f, 0f, 180f));
			}
		}
	}
}
