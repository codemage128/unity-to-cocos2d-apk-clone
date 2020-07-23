using Assets.Scripts.CasualTools.Common.Tasks;
using Assets.Scripts.Utils;
using System;
using System.Collections;
using System.Diagnostics;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class CanTossItem : SpriteBasedItem, ICanExplodeAtLeast2
	{
		public CanTossFakeItem BottomRight;

		public CanTossFakeItem TopLeft;

		public CanTossFakeItem TopRight;

		public CanBox[] Cans;

		public Transform ExplodePosition;

		public Animator CanTossAnimation;

		private int _canCount = 9;

		private bool _isAnimationPlaying;

		private bool _isExploded;

		private int _canTossAnimationId;

		private int audioTag;

		private readonly AudioTag[] tags = new AudioTag[]
		{
			AudioTag.ItemCan1,
			AudioTag.ItemCan2,
			AudioTag.ItemCan3
		};

		[HideInInspector]
		public int BombExplodeCount;

		public override Cell CurrentCell
		{
			get
			{
				return base.CurrentCell;
			}
			set
			{
				base.CurrentCell = value;
				if (this.CurrentCell != null)
				{
					this.TopLeft.CurrentCell = this.CurrentCell.CurrentGrid[this.CurrentCell.X, this.CurrentCell.Y + 1];
					this.TopRight.CurrentCell = this.CurrentCell.CurrentGrid[this.CurrentCell.X + 1, this.CurrentCell.Y + 1];
					this.BottomRight.CurrentCell = this.CurrentCell.CurrentGrid[this.CurrentCell.X + 1, this.CurrentCell.Y];
				}
				else
				{
					this.TopLeft.CurrentCell = null;
					this.TopRight.CurrentCell = null;
					this.BottomRight.CurrentCell = null;
				}
			}
		}

		public void Awake()
		{
			this._canTossAnimationId = Animator.StringToHash("Base Layer.CanTossAnimation");
			int num = this.Cans.Length;
			for (int i = 0; i < num; i++)
			{
				this.Cans[i].Id = i;
			}
		}

		public override ItemType GetItemType()
		{
			return ItemType.CanToss;
		}

		public override void ChangeSorting(Sorting s)
		{
			this.CurrentSpriteRenderer.set_sortingLayerID(s.LayerId);
			this.CurrentSpriteRenderer.set_sortingOrder(s.Order);
			int num = this.Cans.Length;
			for (int i = 0; i < num; i++)
			{
				this.Cans[i].CurrentSpriteRenderer.set_sortingLayerID(s.LayerId);
				this.Cans[i].CurrentSpriteRenderer.set_sortingOrder(s.Order - i + 10);
			}
		}

		public override int GetScore()
		{
			return 250;
		}

		public override bool CanBeExplodedBySpecialItem()
		{
			return true;
		}

		public override bool CanBeExplodedByBooster()
		{
			return true;
		}

		public override bool CanFall()
		{
			return false;
		}

		public override bool CanGenerateScoreOnEachTryExplode()
		{
			return true;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override void StartCollect()
		{
			this.PlayExplodeAudio();
			this.PlayOnExplodeStartedAnimation();
			this.RemoveSelf();
		}

		public override bool TryExplode()
		{
			return this.ExplodeBy(this);
		}

		public bool ExplodeBy(Item item)
		{
			if (this._isExploded)
			{
				return false;
			}
			if (!this.CurrentLevel.CanBeCollected(ItemType.CanToss))
			{
				return false;
			}
			this._canCount--;
			if (this._canCount < 0)
			{
				return false;
			}
			CanBox canBox = this.Cans[8 - this._canCount];
			canBox.Remove();
			AudioManager.Play(this.ChoseAudioTag(), PlayMode.Frame, null, 1f);
			if (ParticlePool.Instance != null)
			{
				ParticlePlayer particlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.CanExplosion, canBox.get_transform().get_position(), true);
				Quaternion identity = Quaternion.get_identity();
				identity.set_eulerAngles((Random.Range(0, 10) <= 5) ? new Vector3(-102.4f, 90f, 0f) : new Vector3(-76.5f, 90f, 0f));
				particlePlayer.MainParticle.get_transform().set_rotation(identity);
			}
			if (this._canCount > 0)
			{
				this.PlayShakeAnimation();
			}
			else
			{
				this._isExploded = true;
			}
			if (item.ToBeExplodedBy == ExplodeReason.Anvil || item.ToBeExplodedBy == ExplodeReason.BoxingGlove || item.ToBeExplodedBy == ExplodeReason.Hammer)
			{
				ScoreManager.RaiseScore(item.GetScore(), item.get_transform().get_position(), MatchType.None);
				item.ToBeExplodedBy = ExplodeReason.None;
			}
			this.CurrentLevel.DecreaseGoal(ItemType.CanToss, false);
			this.CurrentLevel.IncreaseBlockWin();
			new Task(CanTossItem.WaitAndAllowWin(this.CurrentLevel), true, LifeTime.Scene);
			return this._isExploded;
		}

		[DebuggerHidden]
		private static IEnumerator WaitAndAllowWin(Level level)
		{
			CanTossItem.<WaitAndAllowWin>c__Iterator0 <WaitAndAllowWin>c__Iterator = new CanTossItem.<WaitAndAllowWin>c__Iterator0();
			<WaitAndAllowWin>c__Iterator.level = level;
			return <WaitAndAllowWin>c__Iterator;
		}

		private AudioTag ChoseAudioTag()
		{
			return this.tags[this.audioTag++ % 3];
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.ItemCanClear, PlayMode.Frame, null, 1f);
		}

		public override void RemoveSelf()
		{
			base.RemoveSelf();
			this.BottomRight.RemoveSelf();
			this.TopLeft.RemoveSelf();
			this.TopRight.RemoveSelf();
		}

		private void PlayShakeAnimation()
		{
			this.CanTossAnimation.Play(this._canTossAnimationId, 0, 0f);
			for (int i = 0; i <= 8; i++)
			{
				CanBox canBox = this.Cans[i];
				canBox.PlayShakeAnimation(this._canCount);
			}
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.CanTossExplosion, this.ExplodePosition.get_position(), true);
			}
		}

		public void CheckIfExtraExplodeNeeded()
		{
			if (this._isExploded)
			{
				return;
			}
			if (this.BombExplodeCount == 1 && this.CurrentCell != null)
			{
				this.CurrentCell.CurrentGrid.ExplodeCell(this.CurrentCell, null);
			}
			this.BombExplodeCount = 0;
		}

		public void MarkShouldExplodeAtLeast2()
		{
			this.BombExplodeCount++;
		}
	}
}
