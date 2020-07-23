using Assets.Scripts.GamePlayScene.Mechanics.Items.SpecialItems;
using System;
using System.Collections;
using System.Diagnostics;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items.ComboItems
{
	public class DoubleBombItem : BombItem, IComboItem
	{
		private GameObject[] _shakePanels;

		public ParticleSystem[] CloseParticles;

		public SpriteRenderer GlowSprite;

		public Transform Shadow;

		public GameObject MainContainer;

		public ParticleSystem Sparks;

		public ParticleSystem StarGlow;

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

		public override void RemoveSelf()
		{
			this.OnBeforeRemove();
			Object.Destroy(base.get_gameObject());
		}

		public void AddScore(int v)
		{
			this.ComboMergeScores += v;
		}

		public void Awake()
		{
			this.RelativeContainer.SetActive(false);
		}

		public override ItemType GetItemType()
		{
			return ItemType.DoubleBomb;
		}

		public override int GetScore()
		{
			return 1000 + this.ComboMergeScores;
		}

		public override bool CanRaiseScore()
		{
			return false;
		}

		public override void ChangeSorting(Sorting s)
		{
		}

		protected override void OnExplodeSelf()
		{
			ParticlePool.Instance.PlayParticle(ParticlePool.Instance.ComboCreationParticle, this.CurrentCell.GetFrozenPosition(), true);
		}

		public override void PlayExplodeParticle()
		{
			ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DoubleBombExplodeParticle, base.get_transform().get_position(), true);
		}

		[DebuggerHidden]
		protected override IEnumerator ExplodeCells()
		{
			DoubleBombItem.<ExplodeCells>c__Iterator0 <ExplodeCells>c__Iterator = new DoubleBombItem.<ExplodeCells>c__Iterator0();
			<ExplodeCells>c__Iterator.$this = this;
			return <ExplodeCells>c__Iterator;
		}

		public override void OnBeforeRemove()
		{
			base.OnBeforeRemove();
			foreach (Cell current in this.ComboMatchGroup.AllCells)
			{
				current.AcceptsFallInside();
			}
			FallManager.DecreaseWaitingFallBlocker();
		}

		public void AddShakeReferences(GameObject[] panels)
		{
			this._shakePanels = panels;
		}
	}
}
