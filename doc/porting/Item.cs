using Assets.Scripts.CasualTools.Common.Pooling;
using Assets.Scripts.Extensions;
using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.GamePlayScene.Mechanics.Items.Features;
using Assets.Scripts.GamePlayScene.Mechanics.Items.SpecialItems;
using Assets.Scripts.Utils;
using DG.Tweening;
using System;
using System.Threading;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public abstract class Item : MonoBehaviour
	{
		private bool _createByFactory;

		protected Level CurrentLevel;

		private Cell _currentCell;

		public int MasterItemExplode;

		[HideInInspector]
		public ExplodeReason ToBeExplodedBy;

		[HideInInspector]
		public bool FilledNewly;

		[HideInInspector]
		public long LatestExplode;

		[HideInInspector]
		public bool IsFalling;

		private CanCastShadowComponent _shadowCaster;

		private bool _canRaiseScoreOnExplode = true;

		public FallListener FallListener;

		public GameObject RelativeContainer;

		private Sequence _wrongAnimation;

		public FallAnimation CurrentFallAnimation;

		[HideInInspector]
		public bool ReCycled;

		public event Action CleanUpResources
		{
			add
			{
				Action action = this.CleanUpResources;
				Action action2;
				do
				{
					action2 = action;
					action = Interlocked.CompareExchange<Action>(ref this.CleanUpResources, (Action)Delegate.Combine(action2, value), action);
				}
				while (action != action2);
			}
			remove
			{
				Action action = this.CleanUpResources;
				Action action2;
				do
				{
					action2 = action;
					action = Interlocked.CompareExchange<Action>(ref this.CleanUpResources, (Action)Delegate.Remove(action2, value), action);
				}
				while (action != action2);
			}
		}

		public virtual Cell CurrentCell
		{
			get
			{
				return this._currentCell;
			}
			set
			{
				if (this._currentCell == value)
				{
					return;
				}
				Cell currentCell = this._currentCell;
				this._currentCell = value;
				if (currentCell != null && currentCell.CurrentItem == this)
				{
					currentCell.CurrentItem = null;
				}
				if (value != null)
				{
					value.CurrentItem = this;
				}
				this.OnCellChanged();
			}
		}

		public virtual void OnBeforeRemove()
		{
			if (this.CleanUpResources != null)
			{
				this.CleanUpResources();
				this.CleanUpResources = null;
			}
			FallManager.StartRunning();
			if (!this._createByFactory)
			{
				return;
			}
			this.CurrentLevel.ItemCounts[(int)this.GetItemType()]--;
			this._createByFactory = false;
			this.ReCycled = true;
		}

		public virtual void AfterPoolInit()
		{
			this.ReCycled = false;
			this.FilledNewly = false;
			this.LatestExplode = 0L;
			this.MasterItemExplode = 0;
			this.IsFalling = false;
			this._canRaiseScoreOnExplode = true;
		}

		public virtual void OnItemCreated(Level currentLevel)
		{
			this.CurrentLevel = currentLevel;
			this.CurrentLevel.ItemCounts[(int)this.GetItemType()]++;
			this.CurrentLevel.StopRefillIfNeeded(this.GetItemType());
			this._createByFactory = true;
		}

		protected virtual void OnCellChanged()
		{
			if (this.CurrentCell == null)
			{
				return;
			}
			Sorting itemSorting = DefinedSortingsExtensions.GetItemSorting(this.CurrentCell.Y);
			this.ChangeSorting(itemSorting);
			CanCastShadowComponent shadowCaster = this.GetShadowCaster();
			if (shadowCaster == null)
			{
				return;
			}
			SpriteRenderer shadowSpriteRenderer = shadowCaster.ShadowSpriteRenderer;
			shadowSpriteRenderer.set_sortingOrder(itemSorting.Order - 1);
			shadowSpriteRenderer.set_sortingLayerID(itemSorting.LayerId);
		}

		public virtual Item ExtractSubItem()
		{
			return null;
		}

		public virtual void OnFallEnded()
		{
		}

		public virtual bool CanFall()
		{
			return true;
		}

		public virtual bool CanBeEffectedByDiscoBall()
		{
			return true;
		}

		public virtual bool IsSpecialItem()
		{
			return false;
		}

		public virtual bool CanBeCapturedByJelly()
		{
			return false;
		}

		public virtual bool CanBeTapped()
		{
			return true;
		}

		public virtual bool CanBeMatchable()
		{
			return false;
		}

		public virtual bool CanGenerateScoreOnEachTryExplode()
		{
			return false;
		}

		public virtual bool CanGenerateScoreWithoutExplode()
		{
			return false;
		}

		public virtual bool CanGenerateScoreThisTurn()
		{
			return true;
		}

		public virtual bool CanBeExplodedBySpecialItem()
		{
			return true;
		}

		public virtual bool CanBeExplodedByBooster()
		{
			return true;
		}

		public virtual bool BoosterAnvilCanBeUsed()
		{
			return true;
		}

		public virtual bool BoosterBoxingGloveCanBeUsed()
		{
			return true;
		}

		public virtual bool BoosterHammerCanBeUsed()
		{
			return true;
		}

		public virtual MatchType GetMatchType()
		{
			return MatchType.None;
		}

		public abstract ItemType GetItemType();

		public virtual bool CanShuffle()
		{
			return false;
		}

		public virtual bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return false;
		}

		public virtual bool TryExplode()
		{
			if (this.LatestExplode == (long)Time.get_frameCount())
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			return true;
		}

		public virtual void RemoveAllLayers()
		{
		}

		public virtual bool CanBeReplacedByPreLevelBooster()
		{
			return false;
		}

		public virtual bool CanBePaint()
		{
			return false;
		}

		public virtual bool CanCastShadow()
		{
			return false;
		}

		public CanCastShadowComponent GetShadowCaster()
		{
			if (!this.CanCastShadow())
			{
				return null;
			}
			if (this._shadowCaster == null)
			{
				this._shadowCaster = base.GetComponent<CanCastShadowComponent>();
			}
			return this._shadowCaster;
		}

		public virtual bool CanShadowDrop()
		{
			return false;
		}

		public virtual int GetScore()
		{
			return 10;
		}

		public virtual bool CanRaiseScore()
		{
			return this._canRaiseScoreOnExplode;
		}

		public void PreventRaiseScore()
		{
			this._canRaiseScoreOnExplode = false;
		}

		internal void AllowRaiseScore()
		{
			this._canRaiseScoreOnExplode = true;
		}

		public void DoShuffleAnimation(Cell targetCell, Cell oldReference)
		{
			Sorting itemSorting = DefinedSortingsExtensions.GetItemSorting(targetCell.Y);
			Sorting itemSorting2 = DefinedSortingsExtensions.GetItemSorting(oldReference.Y);
			this.CurrentCell = targetCell;
			this.ChangeSorting(itemSorting2);
			ShuffleAnimation componentOrAdd = base.get_gameObject().GetComponentOrAdd<ShuffleAnimation>();
			componentOrAdd.SetSortingOrder(this, itemSorting);
			componentOrAdd.ShuffleWith(targetCell);
		}

		public abstract void ChangeSorting(Sorting s);

		public abstract Sorting GetSorting();

		public virtual void StartExplode()
		{
			this.StopOtherAnimations();
			this.PlayExplodeAudio();
			this.PlayOnExplodeStartedAnimation();
			this.RemoveSelf();
		}

		public virtual void RemoveSelf()
		{
			this.OnBeforeRemove();
			Object.Destroy(base.get_gameObject());
		}

		public virtual void OnBeforeNewLevel()
		{
			this.CurrentLevel = null;
		}

		public virtual CollectAnimation GetCollectItem()
		{
			CollectAnimation component = this.CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(base.get_transform().get_position()).GetComponent<CollectAnimation>();
			component.Prepare(this.CurrentLevel, this.GetItemType(), this.GetSorting(), null, this.CurrentCell);
			return component;
		}

		public virtual void StartCollect()
		{
			this.StopOtherAnimations();
			CollectAnimation collectItem = this.GetCollectItem();
			collectItem.StartAnimation();
			this.PlayExplodeAudio();
			this.PlayOnExplodeStartedAnimation();
			this.RemoveSelf();
		}

		public virtual void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.ClassicExplode, PlayMode.Frame, null, 1f);
		}

		public virtual void PlayWrongMove()
		{
			if (this._wrongAnimation != null)
			{
				TweenExtensions.Kill(this._wrongAnimation, true);
			}
			AudioManager.Play(AudioTag.InvalidTap, PlayMode.Frame, null, 1f);
			this._wrongAnimation = DOTween.Sequence();
			TweenSettingsExtensions.Append(this._wrongAnimation, ShortcutExtensions.DOLocalRotate(this.RelativeContainer.get_transform(), new Vector3(0f, 0f, 15f), 0.035f, 0));
			TweenSettingsExtensions.Join(this._wrongAnimation, ShortcutExtensions.DOScale(this.RelativeContainer.get_transform(), 0.93f, 0.035f));
			TweenSettingsExtensions.Append(this._wrongAnimation, ShortcutExtensions.DOLocalRotate(this.RelativeContainer.get_transform(), new Vector3(0f, 0f, -15f), 0.07f, 0));
			TweenSettingsExtensions.Append(this._wrongAnimation, ShortcutExtensions.DOLocalRotate(this.RelativeContainer.get_transform(), new Vector3(0f, 0f, 0f), 0.035f, 0));
			TweenSettingsExtensions.Append(this._wrongAnimation, ShortcutExtensions.DOLocalRotate(this.RelativeContainer.get_transform(), new Vector3(0f, 0f, 15f), 0.035f, 0));
			TweenSettingsExtensions.Append(this._wrongAnimation, ShortcutExtensions.DOLocalRotate(this.RelativeContainer.get_transform(), new Vector3(0f, 0f, -15f), 0.07f, 0));
			TweenSettingsExtensions.Append(this._wrongAnimation, ShortcutExtensions.DOLocalRotate(this.RelativeContainer.get_transform(), new Vector3(0f, 0f, 0f), 0.035f, 0));
			TweenSettingsExtensions.Join(this._wrongAnimation, ShortcutExtensions.DOScale(this.RelativeContainer.get_transform(), 1f, 0.035f));
			TweenSettingsExtensions.OnComplete<Sequence>(this._wrongAnimation, new TweenCallback(this.RemoveWrongAnimation));
		}

		private void RemoveWrongAnimation()
		{
			this._wrongAnimation = null;
		}

		public void AppendFallAnimation(Cell targetCell)
		{
			if (this._wrongAnimation != null)
			{
				TweenExtensions.Kill(this._wrongAnimation, true);
				this._wrongAnimation = null;
			}
			if (this.CurrentFallAnimation == null)
			{
				this.CurrentFallAnimation = base.get_gameObject().AddComponent<FallAnimation>();
			}
			this.CurrentFallAnimation.AppendFallTo(targetCell, this.GetFallListener());
		}

		protected void StopOtherAnimations()
		{
			if (this._wrongAnimation != null)
			{
				TweenExtensions.Kill(this._wrongAnimation, true);
				this._wrongAnimation = null;
			}
			if (this.CurrentFallAnimation != null)
			{
				this.CurrentFallAnimation.Cancel();
			}
		}

		public virtual void ReactToUpperFall()
		{
		}

		protected virtual void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.DefaultExplosion, base.get_transform().get_position(), true);
			}
		}

		public virtual bool CanShowMatchHint()
		{
			return false;
		}

		public virtual bool CanShowCurrentlyUnderTap()
		{
			return false;
		}

		protected FallListener GetFallListener()
		{
			return this.FallListener;
		}

		public virtual void InformToBeExplodedBySpecialItem(SpecialItem specialItem, Direction comingFrom)
		{
		}

		public virtual void BringToFront()
		{
		}

		public virtual void SendToBack()
		{
		}
	}
}
