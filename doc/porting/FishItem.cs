using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using System;
using System.Collections;
using System.Diagnostics;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public class FishItem : Item
	{
		public Animator CurrentAnimator;

		public Transform Container;

		public SpriteRenderer[] SpriteRenderers;

		public ParticleSystem ThrowParticle;

		private int _generatedBubbleCount = 1;

		private int _generateBubbleInterval = 1;

		private int _counter;

		private int _throwHash;

		private int _sleepHash;

		private int _direction;

		private bool _isSleeping;

		private bool _isPlayingAnimation;

		public void Start()
		{
			this._throwHash = Animator.StringToHash("Base Layer.BubbleGeneratorThrow");
			this._sleepHash = Animator.StringToHash("Base Layer.BubbleGeneratorSleep");
		}

		public override void ChangeSorting(Sorting s)
		{
			int num = this.SpriteRenderers.Length;
			if (num == 0)
			{
				return;
			}
			int num2 = (!(this.CurrentCell == null)) ? this.CurrentCell.X : 0;
			for (int i = 0; i < num; i++)
			{
				this.SpriteRenderers[i].set_sortingLayerID(s.LayerId);
				this.SpriteRenderers[i].set_sortingOrder(s.Order + i + 50 + num2 * 10);
			}
		}

		public override Sorting GetSorting()
		{
			return new Sorting(this.SpriteRenderers[0].get_sortingLayerID(), this.SpriteRenderers[0].get_sortingOrder());
		}

		public override ItemType GetItemType()
		{
			return ItemType.Fish;
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

		public override void OnItemCreated(Level currentLevel)
		{
			base.OnItemCreated(currentLevel);
			BubbleController.Instance.AddBubbleGeneratorItem(this);
		}

		public override bool TryExplode()
		{
			if (this.LatestExplode == (long)Time.get_frameCount())
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			base.StartCoroutine(this.GenerateBubbles());
			return false;
		}

		[DebuggerHidden]
		private IEnumerator GenerateBubbles()
		{
			FishItem.<GenerateBubbles>c__Iterator0 <GenerateBubbles>c__Iterator = new FishItem.<GenerateBubbles>c__Iterator0();
			<GenerateBubbles>c__Iterator.$this = this;
			return <GenerateBubbles>c__Iterator;
		}

		public void Sleep()
		{
			if (this._isSleeping)
			{
				return;
			}
			this._isSleeping = true;
			if (!this._isPlayingAnimation)
			{
				this.CurrentAnimator.Play(this._sleepHash, 0, 0f);
			}
		}

		private void OnThrowAnimationComplete()
		{
			this._isPlayingAnimation = false;
			if (this._isSleeping)
			{
				this.CurrentAnimator.Play(this._sleepHash, 0, 0f);
			}
		}

		public void SetDirection(int direction)
		{
			this._direction = direction;
			if (this._direction == 1)
			{
				this.Container.get_transform().set_localScale(new Vector3(-1f, 1f, 1f));
				Quaternion identity = Quaternion.get_identity();
				identity.set_eulerAngles(new Vector3(0f, 0f, 180f));
				this.ThrowParticle.get_transform().set_rotation(identity);
			}
		}
	}
}
