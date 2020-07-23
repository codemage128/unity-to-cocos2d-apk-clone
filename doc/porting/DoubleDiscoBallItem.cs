using Assets.Scripts.GamePlayScene.Mechanics.Items.SpecialItems;
using System;
using System.Collections;
using System.Diagnostics;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items.ComboItems
{
	public class DoubleDiscoBallItem : SpecialItem, IComboItem
	{
		public ParticleSystem ExplodeParticle;

		public ParticleSystem RingParticle;

		public GameObject ExplodeContainer;

		public GameObject AnimationContainer;

		public SpriteRenderer BackgroundSprite;

		private Material _gradientMaterial;

		protected MatchGroup ComboMatchGroup;

		protected int ComboMergeScores;

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
			return ItemType.DoubleDiscoBall;
		}

		public override int GetScore()
		{
			return 8000 + this.ComboMergeScores;
		}

		[DebuggerHidden]
		protected override IEnumerator ExplodeCells()
		{
			DoubleDiscoBallItem.<ExplodeCells>c__Iterator0 <ExplodeCells>c__Iterator = new DoubleDiscoBallItem.<ExplodeCells>c__Iterator0();
			<ExplodeCells>c__Iterator.$this = this;
			return <ExplodeCells>c__Iterator;
		}

		[DebuggerHidden]
		private IEnumerator WaitForAnimationComplete()
		{
			DoubleDiscoBallItem.<WaitForAnimationComplete>c__Iterator1 <WaitForAnimationComplete>c__Iterator = new DoubleDiscoBallItem.<WaitForAnimationComplete>c__Iterator1();
			<WaitForAnimationComplete>c__Iterator.$this = this;
			return <WaitForAnimationComplete>c__Iterator;
		}
	}
}
