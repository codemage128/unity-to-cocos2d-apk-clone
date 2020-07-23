using System;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class JellyAnimatorWaiter : MonoBehaviour
	{
		[HideInInspector]
		public JellyItem MasterJelly;

		public Animator SpreadAnimator;

		public Renderer SpreadingSprite;

		public int DisplaySortNo;

		public void InformAnimationEnded()
		{
			this.SpreadAnimator.SetInteger("DIRECTION", 5);
			if (this.MasterJelly != null)
			{
				this.MasterJelly.AnimationEnded();
			}
		}

		public void DisplayAtFront()
		{
			this.SpreadingSprite.set_sortingLayerName("Mechanics");
			this.SpreadingSprite.set_sortingOrder(this.DisplaySortNo);
		}

		public void HideIt()
		{
			this.SpreadingSprite.set_sortingLayerName("Default");
			this.SpreadingSprite.set_sortingOrder(-10);
		}
	}
}
