using Assets.Scripts.CasualTools.Common.Pooling;
using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.Utils;
using System;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class JellyItem : SpriteBasedItem
	{
		private GameObject _itemToBeDestoyedAtAnimationEnd;

		private JellyItem _jellyToBeEnabled;

		public Transform JellyAnimationOwner;

		private JellyAnimatorWaiter _jellyAnimatorWaiter;

		private bool _creatingJelly;

		private bool _destroyed;

		private JellyItem _newJelly;

		public JellyItem SpreadedBy;

		public override int GetScore()
		{
			return 500;
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.JellyBreak, PlayMode.Frame, null, 1f);
		}

		public void PlayJellySpread(Cell cellSelected)
		{
			if (this._creatingJelly || this._destroyed || cellSelected == null)
			{
				return;
			}
			AudioManager.Play(AudioTag.JellySpread, PlayMode.Frame, null, 1f);
			this._jellyAnimatorWaiter = this.CurrentLevel.CurrentLevelBuilder.JellyAnimatorPrefab.Spawn(this.JellyAnimationOwner.get_position()).GetComponent<JellyAnimatorWaiter>();
			this._jellyAnimatorWaiter.MasterJelly = this;
			int num = 0;
			GameObject prefab = ParticlePool.Instance.JellyCreationSideParticle;
			if (cellSelected.Y == this.CurrentCell.Y)
			{
				num = ((cellSelected.X >= this.CurrentCell.X) ? 3 : 1);
				this._jellyAnimatorWaiter.DisplaySortNo = this.CurrentSpriteRenderer.get_sortingOrder() + 5;
			}
			else if (cellSelected.X == this.CurrentCell.X)
			{
				if (cellSelected.Y < this.CurrentCell.Y)
				{
					num = 4;
					prefab = ParticlePool.Instance.JellyCreationDownParticle;
					this._jellyAnimatorWaiter.DisplaySortNo = this.CurrentSpriteRenderer.get_sortingOrder() - 1;
				}
				else
				{
					num = 2;
					prefab = ParticlePool.Instance.JellyCreationUpParticle;
					this._jellyAnimatorWaiter.DisplaySortNo = this.CurrentSpriteRenderer.get_sortingOrder() + 105;
				}
			}
			this._jellyAnimatorWaiter.HideIt();
			if (num == 0)
			{
				this._jellyAnimatorWaiter.MasterJelly = null;
				this._jellyAnimatorWaiter.get_gameObject().Recycle();
				return;
			}
			this._creatingJelly = true;
			this._jellyAnimatorWaiter.SpreadAnimator.SetInteger("DIRECTION", num);
			if (cellSelected.HasItem)
			{
				Item currentItem = cellSelected.CurrentItem;
				currentItem.CurrentCell = null;
				this._itemToBeDestoyedAtAnimationEnd = currentItem.get_gameObject();
			}
			this._newJelly = (this.CurrentLevel.CurrentLevelBuilder.CreateItem(new ItemDescription(ItemType.Jelly, TiledEditorId.Jelly, null)) as JellyItem);
			this._newJelly.get_transform().set_position(cellSelected.get_transform().get_position());
			this._newJelly.CurrentCell = cellSelected;
			this._newJelly.RelativeContainer.SetActive(false);
			this._newJelly.SpreadedBy = this;
			ParticlePlayer particlePlayer = ParticlePool.Instance.PlayParticle(prefab, this._newJelly.get_transform().get_position(), false);
			particlePlayer.get_transform().set_localScale((num != 3) ? Vector3.get_one() : new Vector3(-1f, 1f, 1f));
			particlePlayer.Play();
			this._jellyToBeEnabled = this._newJelly;
		}

		public override bool CanShadowDrop()
		{
			return true;
		}

		public void AnimationEnded()
		{
			if (this._newJelly != null)
			{
				this._newJelly.SpreadedBy = null;
				if (this._newJelly.CurrentCell != null)
				{
					this._newJelly.get_transform().set_position(this._newJelly.CurrentCell.get_transform().get_position());
				}
			}
			if (this._jellyAnimatorWaiter != null)
			{
				this._jellyAnimatorWaiter.SpreadAnimator.SetInteger("DIRECTION", 5);
				this._jellyAnimatorWaiter.MasterJelly = null;
				this._jellyAnimatorWaiter.HideIt();
				this._jellyAnimatorWaiter.get_gameObject().Recycle();
			}
			if (this._itemToBeDestoyedAtAnimationEnd != null)
			{
				this._itemToBeDestoyedAtAnimationEnd.GetComponent<Item>().RemoveSelf();
			}
			if (this._jellyToBeEnabled != null)
			{
				this._jellyToBeEnabled.RelativeContainer.SetActive(true);
			}
			this._jellyToBeEnabled = null;
			this._itemToBeDestoyedAtAnimationEnd = null;
			this._jellyAnimatorWaiter = null;
			this._creatingJelly = false;
		}

		public override void OnItemCreated(Level currentLevel)
		{
			base.OnItemCreated(currentLevel);
			this.CurrentLevel.JellyItemManager.Add(this);
		}

		public override void OnBeforeRemove()
		{
			if (this.SpreadedBy != null)
			{
				this.SpreadedBy.AnimationEnded();
			}
			this.AnimationEnded();
			base.OnBeforeRemove();
			this.CurrentLevel.JellyItemManager.Remove(this);
			this._destroyed = true;
		}

		public override void AfterPoolInit()
		{
			base.AfterPoolInit();
			this._destroyed = false;
		}

		public override void ReactToUpperFall()
		{
			FallListener fallListener = base.GetFallListener();
			fallListener.EndFall(-1f);
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.JellyExplodeParticle, base.get_transform().get_position(), true);
			}
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override bool CanFall()
		{
			return false;
		}

		public override bool TryExplode()
		{
			bool flag = base.TryExplode();
			if (flag)
			{
				this.CurrentLevel.JellyItemManager.InformJellyExplode();
			}
			return flag;
		}

		public override ItemType GetItemType()
		{
			return ItemType.Jelly;
		}
	}
}
