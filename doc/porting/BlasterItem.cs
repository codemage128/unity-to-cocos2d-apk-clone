using Assets.Scripts.CasualTools.Common.Logging;
using Assets.Scripts.CasualTools.Common.Pooling;
using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.GamePlayScene.Touches;
using Assets.Scripts.Logging;
using Assets.Scripts.Utils;
using DG.Tweening;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public class BlasterItem : CollectorItem
	{
		public Transform BlasterTransform;

		public SpriteRenderer FillLayer;

		public ParticleSystem TrailParticles;

		public Animator CurrentAnimator;

		public SpriteRenderer ShadowSpriteRenderer;

		public SpriteRenderer FakeShadowSpriteRenderer;

		public ParticleSystem CollectParticle;

		public ParticleSystem CollectHitParticle;

		public Transform CollectTarget;

		public BlasterFakeItem FakeItem;

		public SpriteRenderer[] ColoredSpriteRenderers;

		public SpriteRenderer[] SpriteRenderers;

		private int _capacity;

		private int _count;

		private int _waitingCount;

		private Direction _direction;

		private Sorting _sorting;

		private bool _blasterAnimationCompleted;

		private float _offset;

		private float _dt = 0.07f;

		private List<Cell> _selectedCells;

		private int _collectHash;

		private int _launchHash;

		private Vector3 _scorePosition;

		private Sequence _fillSequence;

		private bool _readyToLaunch;

		private bool _shouldPlayCollectAudio;

		private bool _fillAnimationEnded;

		private const float ShakeDuration = 0.4f;

		private const float ShakeX = 0.1f;

		private const float ShakeY = 0.1f;

		private const float ShakeWait = 0.12f;

		private const float WaitAnimation = 0.4f;

		private int ScoreGained;

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
					int num = this.CurrentCell.X;
					int num2 = this.CurrentCell.Y;
					switch (this._direction)
					{
					case Direction.Up:
					case Direction.Down:
						num2++;
						break;
					case Direction.Left:
					case Direction.Right:
						num++;
						break;
					}
					this.FakeItem.CurrentCell = this.CurrentCell.CurrentGrid[num, num2];
				}
				else
				{
					this.FakeItem.CurrentCell = null;
				}
			}
		}

		private void Start()
		{
			this._collectHash = Animator.StringToHash("Base Layer.BlasterCollectAnimation");
			this._launchHash = Animator.StringToHash("Base Layer.BlasterLaunchAnimation");
		}

		public override void BringToFront()
		{
			Sorting sorting = this.GetSorting();
			sorting.Order += 3000;
			this.ChangeSorting(sorting);
		}

		public void Prepare(Direction direction, int capacity, int order, MatchType matchType)
		{
			this._capacity = capacity;
			base.Order = order;
			base.MatchType = matchType;
			this._direction = direction;
			Quaternion identity = Quaternion.get_identity();
			Vector3 localPosition = default(Vector3);
			float num = 1f;
			Vector3 zero = Vector3.get_zero();
			Vector3 localPosition2;
			switch (direction)
			{
			case Direction.Up:
				identity.set_eulerAngles(Vector3.get_zero());
				localPosition = new Vector3(0f, 0.5f);
				localPosition2 = new Vector3(0f, -0.463f);
				goto IL_19A;
			case Direction.Down:
				identity.set_eulerAngles(new Vector3(0f, 0f, 180f));
				localPosition = new Vector3(0f, 0.5f);
				localPosition2 = new Vector3(0f, -0.463f);
				goto IL_19A;
			case Direction.Left:
				identity.set_eulerAngles(new Vector3(0f, 0f, 90f));
				localPosition = new Vector3(0.5f, 0f);
				localPosition2 = new Vector3(0.135f, -0.425f);
				zero = new Vector3(0.8f, -0.5f);
				num = 1.2f;
				goto IL_19A;
			case Direction.Right:
				identity.set_eulerAngles(new Vector3(0f, 0f, 270f));
				localPosition = new Vector3(0.5f, 0f);
				localPosition2 = new Vector3(0f, -0.425f);
				zero = new Vector3(1f, -0.5f);
				num = 1.2f;
				goto IL_19A;
			}
			throw new ArgumentOutOfRangeException("direction", direction, null);
			IL_19A:
			this.ShadowSpriteRenderer.get_transform().set_localPosition(localPosition2);
			this.ShadowSpriteRenderer.get_transform().set_localScale(Vector3.get_one() * num);
			this.FakeShadowSpriteRenderer.get_transform().set_localPosition(zero);
			this.FakeShadowSpriteRenderer.get_transform().set_localScale(Vector3.get_one() * num);
			this.BlasterTransform.set_localRotation(identity);
			this.BlasterTransform.set_localPosition(localPosition);
			this.ChangeColor(base.MatchType);
			this.ResetFill();
			this.CollectorId = CollectorItemsController.Instance.GetBlasters().Register(this);
			if (this._selectedCells == null)
			{
				this._selectedCells = new List<Cell>();
			}
		}

		private void ChangeColor(MatchType matchType)
		{
			Sprite[] array = null;
			switch (matchType)
			{
			case MatchType.Yellow:
				this.FillLayer.set_color(new Color(0.8901961f, 0.772549033f, 0.180392161f));
				array = SharedImageLibrary.Instance.BlasterSpritesYellow;
				break;
			case MatchType.Red:
				this.FillLayer.set_color(new Color(0.9843137f, 0.09803922f, 0.164705887f));
				array = SharedImageLibrary.Instance.BlasterSpritesRed;
				break;
			case MatchType.Blue:
				this.FillLayer.set_color(new Color(0.180392161f, 0.5529412f, 0.8392157f));
				array = SharedImageLibrary.Instance.BlasterSpritesBlue;
				break;
			case MatchType.Green:
				this.FillLayer.set_color(new Color(0.294117659f, 0.768627465f, 0.152941182f));
				array = SharedImageLibrary.Instance.BlasterSpritesGreen;
				break;
			case MatchType.Purple:
				this.FillLayer.set_color(new Color(0.698039234f, 0.13333334f, 0.733333349f));
				array = SharedImageLibrary.Instance.BlasterSpritesPurple;
				break;
			default:
				LogManager.Error(LogTags.BlasterItem, "Error Changing color. Match type:{0} is not valid", new object[]
				{
					matchType
				});
				break;
			}
			this.ColoredSpriteRenderers[0].set_sprite(array[0]);
			this.ColoredSpriteRenderers[1].set_sprite(array[1]);
			this.ColoredSpriteRenderers[2].set_sprite(array[2]);
		}

		public override void StartCollectingItem()
		{
			this._waitingCount++;
			if (this._waitingCount == 1)
			{
				this._shouldPlayCollectAudio = true;
			}
			this.CurrentAnimator.SetBool("CollectCompleted", false);
			if (!this._readyToLaunch && this._waitingCount + this._count >= this._capacity)
			{
				this._readyToLaunch = true;
				TapListener.Instance.IncreaseBlockRequests();
				CollectorItemsController.Instance.GetBlasters().AddToQueue(this.CollectorId);
			}
		}

		public void PlayCollectParticle()
		{
			this.CollectParticle.Play();
		}

		public override void OnItemCollectCompleted()
		{
			this._count++;
			this._waitingCount--;
			if (this._shouldPlayCollectAudio)
			{
				this.CollectHitParticle.Play();
				this._shouldPlayCollectAudio = false;
				if (ItemResourcesManager.Instance != null)
				{
					AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this.GetItemType()).AudioClips[0], PlayMode.Frame, null, 1f);
				}
			}
			int fullPathHash = this.CurrentAnimator.GetCurrentAnimatorStateInfo(0).get_fullPathHash();
			if (this._waitingCount == 0)
			{
				this.CurrentAnimator.SetBool("CollectCompleted", true);
				if (this._collectHash != fullPathHash)
				{
					this.CurrentAnimator.Play(this._collectHash);
				}
				this.UpdateFill();
			}
			else
			{
				this.CurrentAnimator.Play(this._collectHash);
			}
			if (this._waitingCount == 0 && this._capacity - this._count <= 0)
			{
				CollectorItemsController.Instance.GetBlasters().UnRegister(this);
			}
		}

		private void ResetFill()
		{
			this.FillLayer.get_transform().set_localPosition(new Vector3(0f, -0.314f));
			this.FillLayer.get_transform().set_localScale(new Vector3(0.26f, 0f));
		}

		private void UpdateFill()
		{
			if (this._fillSequence != null)
			{
				TweenExtensions.Kill(this._fillSequence, false);
			}
			float num = (float)this._count / (float)this._capacity;
			float num2 = (this._count < this._capacity) ? 0.28f : 0.314f;
			float num3 = Mathf.Min(num, 1f);
			float num4 = 0.2f;
			this._fillSequence = DOTween.Sequence();
			Tweener tweener = TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(this.FillLayer.get_transform(), -0.314f + num2 * num3, 0.6f, false), 30);
			tweener.easeOvershootOrAmplitude = 2f;
			TweenSettingsExtensions.Insert(this._fillSequence, num4, tweener);
			Tweener tweener2 = TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOScaleY(this.FillLayer.get_transform(), 0.65f * num3, 0.6f), 30);
			tweener2.easeOvershootOrAmplitude = 2f;
			TweenSettingsExtensions.Insert(this._fillSequence, num4, tweener2);
			TweenSettingsExtensions.OnComplete<Sequence>(this._fillSequence, delegate
			{
				if (this._waitingCount == 0 && this._capacity - this._count <= 0 && !this._fillAnimationEnded)
				{
					this._fillAnimationEnded = true;
					base.StartCoroutine(this.StartExplodeAnimation());
				}
			});
		}

		public override bool IsAvailable()
		{
			return this._capacity - (this._count + this._waitingCount) > 0;
		}

		[DebuggerHidden]
		private IEnumerator StartExplodeAnimation()
		{
			BlasterItem.<StartExplodeAnimation>c__Iterator0 <StartExplodeAnimation>c__Iterator = new BlasterItem.<StartExplodeAnimation>c__Iterator0();
			<StartExplodeAnimation>c__Iterator.$this = this;
			return <StartExplodeAnimation>c__Iterator;
		}

		private void AcceptFalls()
		{
			ScoreManager.RaiseScore(this.ScoreGained, this._scorePosition, MatchType.None);
			for (int i = 0; i < this._selectedCells.Count; i++)
			{
				this._selectedCells[i].AcceptsFallInside();
			}
			this._selectedCells.Clear();
		}

		public override void RemoveSelf()
		{
			this.OnBeforeRemove();
			this._selectedCells.Clear();
			base.get_gameObject().Recycle();
		}

		private void CreateAnimation()
		{
			this._selectedCells.Clear();
			switch (this._direction)
			{
			case Direction.Up:
				this.CreateUpAnimation();
				break;
			case Direction.Down:
				this.CreateDownAnimation();
				break;
			case Direction.Left:
				this.CreateLeftAnimation();
				break;
			case Direction.Right:
				this.CreateRightAnimation();
				break;
			}
		}

		private void ClearCells()
		{
			this._selectedCells.Add(this.CurrentCell);
			this._selectedCells.Add(this.FakeItem.CurrentCell);
			this.CurrentCell.RejectsFallInside();
			this.FakeItem.CurrentCell = null;
			this.CurrentCell = null;
		}

		private void CreateRightAnimation()
		{
			if (this.CurrentCell == null)
			{
				return;
			}
			Sequence sequence = DOTween.Sequence();
			TweenSettingsExtensions.SetEase<Sequence>(sequence, 1);
			int i = this.CurrentCell.X;
			CaravanGrid currentGrid = this.CurrentLevel.CurrentGrid;
			Cell cellWithDirection = currentGrid.GetCellWithDirection(this.CurrentCell, Direction.Right);
			TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveX(base.get_transform(), (float)i + this._offset, this._dt * this._offset, false), 1));
			while (i < 9)
			{
				i++;
				cellWithDirection = currentGrid.GetCellWithDirection(cellWithDirection, Direction.Right);
				this.ExplodeCell(cellWithDirection, sequence);
				TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveX(base.get_transform(), (float)i + this._offset, this._dt, false), 1));
			}
			TweenSettingsExtensions.AppendCallback(sequence, delegate
			{
				this._blasterAnimationCompleted = true;
			});
			float num = (float)(15 - i) - this._offset;
			TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveX(base.get_transform(), 15f, this._dt * num, false), 1));
			this.ClearCells();
		}

		private void CreateLeftAnimation()
		{
			if (this.CurrentCell == null)
			{
				return;
			}
			Sequence sequence = DOTween.Sequence();
			TweenSettingsExtensions.SetEase<Sequence>(sequence, 1);
			int i = this.CurrentCell.X;
			CaravanGrid currentGrid = this.CurrentLevel.CurrentGrid;
			Cell cell = this.CurrentCell;
			TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveX(base.get_transform(), (float)i - this._offset, this._dt * this._offset, false), 1));
			while (i >= 0)
			{
				i--;
				cell = currentGrid.GetCellWithDirection(cell, Direction.Left);
				this.ExplodeCell(cell, sequence);
				TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveX(base.get_transform(), (float)i - this._offset, this._dt, false), 1));
			}
			TweenSettingsExtensions.AppendCallback(sequence, delegate
			{
				this._blasterAnimationCompleted = true;
			});
			float num = (float)(15 - i) - this._offset;
			TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveX(base.get_transform(), -15f, this._dt * num, false), 1));
			this.ClearCells();
		}

		private void CreateUpAnimation()
		{
			if (this.CurrentCell == null)
			{
				return;
			}
			Sequence sequence = DOTween.Sequence();
			TweenSettingsExtensions.SetEase<Sequence>(sequence, 1);
			int i = this.CurrentCell.Y;
			CaravanGrid currentGrid = this.CurrentLevel.CurrentGrid;
			Cell cellWithDirection = currentGrid.GetCellWithDirection(this.CurrentCell, Direction.Up);
			TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(base.get_transform(), (float)i + this._offset, this._dt * this._offset, false), 1));
			while (i < 9)
			{
				i++;
				cellWithDirection = currentGrid.GetCellWithDirection(cellWithDirection, Direction.Up);
				this.ExplodeCell(cellWithDirection, sequence);
				TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(base.get_transform(), (float)i + this._offset, this._dt, false), 1));
			}
			TweenSettingsExtensions.AppendCallback(sequence, delegate
			{
				this._blasterAnimationCompleted = true;
			});
			float num = (float)(15 - i) - this._offset;
			TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(base.get_transform(), 15f, this._dt * num, false), 1));
			this.ClearCells();
		}

		private void CreateDownAnimation()
		{
			if (this.CurrentCell == null)
			{
				return;
			}
			Sequence sequence = DOTween.Sequence();
			TweenSettingsExtensions.SetEase<Sequence>(sequence, 1);
			int i = this.CurrentCell.Y;
			CaravanGrid currentGrid = this.CurrentLevel.CurrentGrid;
			Cell cell = this.CurrentCell;
			TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(base.get_transform(), (float)i - this._offset, this._dt * this._offset, false), 1));
			while (i >= 0)
			{
				i--;
				cell = currentGrid.GetCellWithDirection(cell, Direction.Down);
				this.ExplodeCell(cell, sequence);
				TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(base.get_transform(), (float)i - this._offset, this._dt, false), 1));
			}
			TweenSettingsExtensions.AppendCallback(sequence, delegate
			{
				this._blasterAnimationCompleted = true;
			});
			float num = (float)(15 - i) - this._offset;
			TweenSettingsExtensions.Append(sequence, TweenSettingsExtensions.SetEase<Tweener>(ShortcutExtensions.DOLocalMoveY(base.get_transform(), -15f, this._dt * num, false), 1));
			this.ClearCells();
		}

		private void ExplodeCell(Cell c, Sequence seq)
		{
			if (c != null && c.Exists)
			{
				c.RejectsFallInside();
				this._selectedCells.Add(c);
				TweenSettingsExtensions.AppendCallback(seq, delegate
				{
					if (c.HasItem)
					{
						Item currentItem = c.CurrentItem;
						if (currentItem != null)
						{
							currentItem.PreventRaiseScore();
							this.ScoreGained += currentItem.GetScore();
							CageItem cageItem = currentItem as CageItem;
							if (cageItem != null)
							{
								this.ScoreGained += cageItem.InnerItem.GetScore();
							}
							currentItem.ExplodeByBlasterItem();
						}
					}
					bool hasBubble = c.HasBubble;
					if (hasBubble)
					{
						c.RemoveBubble();
					}
				});
			}
		}

		public override ItemType GetItemType()
		{
			return ItemType.Blaster;
		}

		public override void ChangeSorting(Sorting s)
		{
			this._sorting = s;
			for (int i = 0; i < this.SpriteRenderers.Length; i++)
			{
				SpriteRenderer spriteRenderer = this.SpriteRenderers[i];
				if (!(spriteRenderer == null))
				{
					spriteRenderer.set_sortingLayerID(this._sorting.LayerId);
					spriteRenderer.set_sortingOrder(this._sorting.Order + 200 + i);
				}
			}
		}

		public override Sorting GetSorting()
		{
			return this._sorting;
		}

		public override bool CanFall()
		{
			return false;
		}

		public override bool CanBeEffectedByDiscoBall()
		{
			return false;
		}

		public override bool CanBeExplodedBySpecialItem()
		{
			return false;
		}

		public override bool CanBeExplodedByBooster()
		{
			return false;
		}

		public override bool BoosterAnvilCanBeUsed()
		{
			return true;
		}

		public override bool BoosterBoxingGloveCanBeUsed()
		{
			return true;
		}

		public override bool BoosterHammerCanBeUsed()
		{
			return false;
		}

		public override void ExplodeByBlasterItem()
		{
		}

		public override bool CanCastShadow()
		{
			return true;
		}

		public override int GetScore()
		{
			return 0;
		}

		public override bool CanBeInsideBubble()
		{
			return false;
		}
	}
}
