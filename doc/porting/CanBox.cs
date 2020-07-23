using System;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class CanBox : MonoBehaviour
	{
		public SpriteRenderer CurrentSpriteRenderer;

		public Animator CurrentAnimator;

		[HideInInspector]
		public int Id;

		private bool _isRemoved;

		private int[] _upperAnimations;

		private int[] _belowAnimations;

		public void Awake()
		{
			this._upperAnimations = new int[]
			{
				Animator.StringToHash("Base Layer.CanItemShakeUp1"),
				Animator.StringToHash("Base Layer.CanItemShakeUp2"),
				Animator.StringToHash("Base Layer.CanItemShakeUp3")
			};
			this._belowAnimations = new int[]
			{
				Animator.StringToHash("Base Layer.CanItemShakeDown1"),
				Animator.StringToHash("Base Layer.CanItemShakeDown2"),
				Animator.StringToHash("Base Layer.CanItemShakeDown3"),
				Animator.StringToHash("Base Layer.CanItemShakeDown4"),
				Animator.StringToHash("Base Layer.CanItemShakeDown5")
			};
		}

		public void PlayShakeAnimation(int totalCount = 8)
		{
			if (this._isRemoved)
			{
				return;
			}
			int num;
			if (this.Id < 3)
			{
				num = this._upperAnimations[Random.Range(0, this._upperAnimations.Length)];
			}
			else if (this.Id < 6 && totalCount < 8)
			{
				num = this._upperAnimations[Random.Range(0, this._upperAnimations.Length)];
			}
			else if (this.Id < 9 && totalCount < 5)
			{
				num = this._upperAnimations[Random.Range(0, this._upperAnimations.Length)];
			}
			else
			{
				num = this._belowAnimations[Random.Range(0, this._belowAnimations.Length)];
			}
			this.CurrentAnimator.Play(num, 0, 0f);
		}

		public void Remove()
		{
			this._isRemoved = true;
			this.CurrentSpriteRenderer.set_enabled(false);
			this.CurrentAnimator.StopPlayback();
		}

		public void OnDestroy()
		{
			this.Remove();
		}
	}
}
