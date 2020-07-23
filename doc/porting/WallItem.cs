using Assets.Scripts.CasualTools.Common.Tasks;
using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.GamePlayScene.Touches;
using Assets.Scripts.Utils;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using UnityEngine;
using Utils;

namespace GamePlayScene.Mechanics.Items
{
	public class WallItem : CollectorItem
	{
		public SpriteRenderer WallSpriteRenderer;

		public SpriteRenderer JointSpriteRenderer;

		public SpriteRenderer JointCornerSpriteRenderer;

		public Animator CollectAnimator;

		public Transform CollectTarget;

		public SpriteRenderer DynamiteSpriteRenderer;

		public SpriteRenderer DynamiteRibbonSpriteRenderer;

		public SpriteRenderer DynamiteDialSpriteRenderer;

		public SpriteRenderer DynamiteDialGlowSpriteRenderer;

		public SpriteRenderer DynamiteShadowSpriteRenderer;

		public BitmapNumberDisplay CurrentBitmapNumberDisplay;

		public WallEffect[] WallEffects;

		public GameObject[] SparksBig;

		public GameObject[] SparksSmall;

		public SpriteRenderer[] FuseSpriteRenderers;

		public SpriteRenderer[] DialSprites;

		public ParticleSystem HitParticle;

		[HideInInspector]
		public WallItem MasterItem;

		[HideInInspector]
		public bool IsMasterItem;

		[HideInInspector]
		public string Group;

		private List<WallItem> _children;

		private Item _innerItem;

		private Sorting _sorting;

		private int _capacity;

		private int _count;

		private float _dynamiteScale;

		private Vector2 _dynamiteOffset;

		private int _waitingCount;

		private bool _readyToLaunch;

		private Vector2 _leftBottom = new Vector2(3.40282347E+38f, 3.40282347E+38f);

		private Vector2 _rightTop = new Vector2(-3.40282347E+38f, -3.40282347E+38f);

		private ItemResources _resources;

		private Cell _upperCell;

		private int _upperSortingOrder;

		private bool _didScoreScaled;

		private const float _shakeDuration = 0.4f;

		private static readonly int ExplodeAnimationHash = Animator.StringToHash("WallItemExplode");

		public Item InnerItem
		{
			get
			{
				return this._innerItem;
			}
			set
			{
				this._innerItem = value;
				if (this._innerItem == null)
				{
					return;
				}
				this._innerItem.get_gameObject().SetActive(false);
			}
		}

		public void Prepare(ItemProperties properties)
		{
			this._capacity = properties.Capacity;
			this._dynamiteOffset = properties.Offset;
			this._dynamiteScale = properties.Scale;
			this._resources = ItemResourcesManager.Instance.GetResources(this.GetItemType());
			this.Group = properties.WallGroup;
			base.Order = properties.Order;
			base.MatchType = properties.MatchType;
			this.CurrentBitmapNumberDisplay.Sprites = new Sprite[]
			{
				this._resources.Sprites[20],
				this._resources.Sprites[21],
				this._resources.Sprites[22],
				this._resources.Sprites[23],
				this._resources.Sprites[24],
				this._resources.Sprites[25],
				this._resources.Sprites[26],
				this._resources.Sprites[27],
				this._resources.Sprites[28],
				this._resources.Sprites[29]
			};
			this.UpdateCollectTargetCount();
			this.UpdateCollectTargetColor();
		}

		private void UpdateCollectTargetColor()
		{
			Sprite[] sprites = this._resources.Sprites;
			switch (base.MatchType)
			{
			case MatchType.Yellow:
				this.DynamiteRibbonSpriteRenderer.set_sprite(sprites[8]);
				this.DynamiteDialSpriteRenderer.set_sprite(sprites[14]);
				break;
			case MatchType.Red:
				this.DynamiteRibbonSpriteRenderer.set_sprite(sprites[9]);
				this.DynamiteDialSpriteRenderer.set_sprite(sprites[15]);
				break;
			case MatchType.Blue:
				this.DynamiteRibbonSpriteRenderer.set_sprite(sprites[10]);
				this.DynamiteDialSpriteRenderer.set_sprite(sprites[16]);
				break;
			case MatchType.Green:
				this.DynamiteRibbonSpriteRenderer.set_sprite(sprites[11]);
				this.DynamiteDialSpriteRenderer.set_sprite(sprites[17]);
				break;
			case MatchType.Purple:
				this.DynamiteRibbonSpriteRenderer.set_sprite(sprites[12]);
				this.DynamiteDialSpriteRenderer.set_sprite(sprites[18]);
				break;
			case MatchType.Orange:
				this.DynamiteRibbonSpriteRenderer.set_sprite(sprites[13]);
				this.DynamiteDialSpriteRenderer.set_sprite(sprites[19]);
				break;
			}
		}

		public void LinkNeighbours(Cell cell)
		{
			if (!cell.Exists)
			{
				return;
			}
			cell.HideBubble();
			if (!cell.HasItem)
			{
				return;
			}
			WallItem wallItem = cell.CurrentItem as WallItem;
			if (wallItem == null || wallItem.MasterItem != null || wallItem.IsMasterItem)
			{
				return;
			}
			if (wallItem.Group != this.Group)
			{
				return;
			}
			if (wallItem == this)
			{
				this.IsMasterItem = true;
				if (this._children == null)
				{
					this._children = new List<WallItem>();
				}
				this.CollectorId = CollectorItemsController.Instance.GetWalls().Register(this);
				this.CollectTarget.get_gameObject().SetActive(true);
			}
			else
			{
				wallItem.MasterItem = this;
				wallItem.CollectorId = this.CollectorId;
				this._children.Add(wallItem);
			}
			Vector3 position = wallItem.get_transform().get_position();
			if (position.x < this._leftBottom.x)
			{
				this._leftBottom.x = position.x;
			}
			if (position.x > this._rightTop.x)
			{
				this._rightTop.x = position.x;
			}
			if (position.y < this._leftBottom.y)
			{
				this._leftBottom.y = position.y;
			}
			if (position.y > this._rightTop.y)
			{
				this._rightTop.y = position.y;
			}
			if (cell.Y > this._upperSortingOrder)
			{
				this._upperSortingOrder = cell.Y;
			}
			CaravanGrid currentGrid = cell.CurrentGrid;
			Cell cellWithDirection = currentGrid.GetCellWithDirection(cell, Direction.Left);
			if (cellWithDirection != null)
			{
				this.LinkNeighbours(cellWithDirection);
			}
			Cell cellWithDirection2 = currentGrid.GetCellWithDirection(cell, Direction.Right);
			if (cellWithDirection2 != null)
			{
				this.LinkNeighbours(cellWithDirection2);
			}
			Cell cellWithDirection3 = currentGrid.GetCellWithDirection(cell, Direction.Up);
			if (cellWithDirection3 != null)
			{
				this.LinkNeighbours(cellWithDirection3);
			}
			Cell cellWithDirection4 = currentGrid.GetCellWithDirection(cell, Direction.Down);
			if (cellWithDirection4 != null)
			{
				this.LinkNeighbours(cellWithDirection4);
			}
			wallItem.UpdateSprites();
			if (this.IsMasterItem)
			{
				this.CollectTarget.set_localScale(Vector3.get_one() * this._dynamiteScale);
				this.CollectTarget.set_position(new Vector3((this._leftBottom.x + this._rightTop.x) / 2f + this._dynamiteOffset.x, (this._leftBottom.y + this._rightTop.y) / 2f + this._dynamiteOffset.y, this.CollectTarget.get_position().z));
				Vector3 localPosition = this.CollectTarget.get_localPosition();
				localPosition.x += -0.02f;
				localPosition.y += -0.123f;
				this.CollectTarget.set_localPosition(localPosition);
				this.ChangeSorting(this._sorting);
			}
		}

		private void UpdateSprites()
		{
			Sprite[] sprites = ItemResourcesManager.Instance.GetResources(this.GetItemType()).Sprites;
			CaravanGrid currentGrid = this.CurrentCell.CurrentGrid;
			int i = 0;
			int num = this.WallEffects.Length;
			while (i < num)
			{
				WallEffect wallEffect = this.WallEffects[i];
				if (wallEffect != null)
				{
					wallEffect.Init();
				}
				i++;
			}
			bool wallItem = this.GetWallItem(currentGrid.GetCellWithDirection(this.CurrentCell, Direction.Down));
			bool wallItem2 = this.GetWallItem(currentGrid.GetCellWithDirection(this.CurrentCell, Direction.Left));
			bool wallItem3 = this.GetWallItem(currentGrid.GetCellWithDirection(this.CurrentCell, Direction.Right));
			int num2;
			if (!wallItem2)
			{
				num2 = 0;
			}
			else if (!wallItem3)
			{
				num2 = 2;
			}
			else
			{
				num2 = 1;
			}
			this.WallSpriteRenderer.set_sprite(sprites[num2]);
			this.JointSpriteRenderer.set_sprite(null);
			this.JointCornerSpriteRenderer.set_sprite(null);
			if (wallItem)
			{
				if (!wallItem2)
				{
					this.JointSpriteRenderer.set_sprite(sprites[3]);
				}
				else if (!wallItem3)
				{
					this.JointSpriteRenderer.set_sprite(sprites[5]);
				}
				else
				{
					bool wallItem4 = this.GetWallItem(currentGrid.GetCellWithDirection(this.CurrentCell, Direction.LeftDown));
					bool wallItem5 = this.GetWallItem(currentGrid.GetCellWithDirection(this.CurrentCell, Direction.RightDown));
					if (!wallItem4)
					{
						this.JointCornerSpriteRenderer.set_sprite(sprites[6]);
					}
					else if (!wallItem5)
					{
						this.JointCornerSpriteRenderer.set_sprite(sprites[7]);
					}
					else
					{
						this.JointSpriteRenderer.set_sprite(sprites[4]);
					}
				}
			}
			this.JointCornerSpriteRenderer.set_enabled(this.JointCornerSpriteRenderer.get_sprite() != null);
			this.JointSpriteRenderer.set_enabled(this.JointSpriteRenderer.get_sprite() != null);
			if (Random.Range(0, 10) < 5)
			{
				this.WallEffects[num2].ShowOverlays(6);
			}
		}

		private bool GetWallItem(Cell cell)
		{
			return cell != null && cell.Exists && cell.HasItem && cell.CurrentItem is WallItem && ((WallItem)cell.CurrentItem).Group == this.Group;
		}

		public override void ExplodeByBlasterItem()
		{
		}

		public override bool CanFall()
		{
			return false;
		}

		public override bool CanBeTapped()
		{
			return false;
		}

		public override void ChangeSorting(Sorting s)
		{
			this._sorting = s;
			this.WallSpriteRenderer.set_sortingLayerID(this._sorting.LayerId);
			this.WallSpriteRenderer.set_sortingOrder(this._sorting.Order);
			this.JointSpriteRenderer.set_sortingLayerID(this._sorting.LayerId);
			this.JointSpriteRenderer.set_sortingOrder(this._sorting.Order + 10);
			this.JointCornerSpriteRenderer.set_sortingLayerID(this._sorting.LayerId);
			this.JointCornerSpriteRenderer.set_sortingOrder(this._sorting.Order + 10);
			int i = 0;
			int num = this.WallEffects.Length;
			while (i < num)
			{
				WallEffect wallEffect = this.WallEffects[i];
				if (wallEffect != null)
				{
					wallEffect.UpdateSorting(this._sorting);
				}
				i++;
			}
			int num2 = this._sorting.Order + this._upperSortingOrder * 100;
			this.DynamiteShadowSpriteRenderer.set_sortingLayerID(this._sorting.LayerId);
			this.DynamiteShadowSpriteRenderer.set_sortingOrder(num2 + 10);
			this.DynamiteSpriteRenderer.set_sortingLayerID(this._sorting.LayerId);
			this.DynamiteSpriteRenderer.set_sortingOrder(num2 + 11);
			this.DynamiteRibbonSpriteRenderer.set_sortingLayerID(this._sorting.LayerId);
			this.DynamiteRibbonSpriteRenderer.set_sortingOrder(num2 + 12);
			for (int j = 0; j < 3; j++)
			{
				this.FuseSpriteRenderers[j].set_sortingLayerID(this._sorting.LayerId);
				this.FuseSpriteRenderers[j].set_sortingOrder(num2 + 13);
			}
			for (int k = 0; k < 3; k++)
			{
				this.DialSprites[k].set_sortingLayerID(this._sorting.LayerId);
				this.DialSprites[k].set_sortingOrder(num2 + k + 14);
			}
			this.DynamiteDialGlowSpriteRenderer.set_sortingLayerID(this._sorting.LayerId);
			this.DynamiteDialGlowSpriteRenderer.set_sortingOrder(num2 + 17);
		}

		public override Sorting GetSorting()
		{
			return this._sorting;
		}

		public override Item ExtractSubItem()
		{
			if (this._innerItem == null)
			{
				return this.InnerItem;
			}
			this._innerItem.get_gameObject().SetActive(true);
			this.InnerItem.MasterItemExplode = Time.get_frameCount();
			return this.InnerItem;
		}

		public override bool CanShadowDrop()
		{
			return true;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return false;
		}

		public override int GetScore()
		{
			return 0;
		}

		public override ItemType GetItemType()
		{
			return ItemType.Wall;
		}

		public override bool CanBeInsideBubble()
		{
			return false;
		}

		public override Item GetSubItem()
		{
			return this.InnerItem;
		}

		public override bool CanBeExplodedBySpecialItem()
		{
			return false;
		}

		public override bool CanBeExplodedByBooster()
		{
			return false;
		}

		public override void PlayWrongMove()
		{
		}

		public override bool BoosterHammerCanBeUsed()
		{
			return false;
		}

		public override bool BoosterAnvilCanBeUsed()
		{
			return false;
		}

		public override bool BoosterBoxingGloveCanBeUsed()
		{
			return false;
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.PlayAudioProps(this._resources.AudioClips[2], PlayMode.Frame, null, 1f);
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null && ItemResourcesManager.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this.GetItemType()).Particles[0], base.get_transform().get_position(), true);
			}
		}

		private void UpdateCollectTargetCount()
		{
			int num = this._capacity - this._count;
			if (num < 0)
			{
				return;
			}
			if (num < 6 && !this.SparksSmall[0].get_activeSelf())
			{
				for (int i = 0; i < 3; i++)
				{
					this.SparksSmall[i].SetActive(true);
				}
			}
			if (num < 10 && !this._didScoreScaled)
			{
				this._didScoreScaled = true;
				this.CurrentBitmapNumberDisplay.get_transform().set_localScale(Vector3.get_one() * 0.8f);
				this.CurrentBitmapNumberDisplay.get_transform().set_localPosition(new Vector3(0.076f, 0.004f, 0f));
			}
			this.CurrentBitmapNumberDisplay.Show(num);
		}

		public override bool IsAvailable()
		{
			return this._capacity - (this._count + this._waitingCount) > 0;
		}

		public override void StartCollectingItem()
		{
			this._waitingCount++;
			if (!this._readyToLaunch && this._waitingCount + this._count >= this._capacity)
			{
				this._readyToLaunch = true;
				TapListener.Instance.IncreaseBlockRequests();
			}
		}

		public override void OnItemCollectCompleted()
		{
			this._count++;
			this._waitingCount--;
			AudioManager.PlayAudioProps(this._resources.AudioClips[0], PlayMode.Frame, null, 1f);
			this.HitParticle.Play();
			this.UpdateCollectTargetCount();
			if (this._waitingCount == 0)
			{
				this.CollectAnimator.SetBool("single_collect", true);
				this.CollectAnimator.SetBool("collect", false);
				base.StartCoroutine(this.WaitCollectAnimation());
			}
			else
			{
				this.CollectAnimator.SetBool("collect", true);
			}
			if (this._waitingCount == 0 && this._capacity - this._count <= 0)
			{
				CollectorItemsController.Instance.GetWalls().UnRegister(this);
				new Task(this.ExplodeWall(), true, LifeTime.Scene);
			}
		}

		[DebuggerHidden]
		private IEnumerator WaitCollectAnimation()
		{
			WallItem.<WaitCollectAnimation>c__Iterator0 <WaitCollectAnimation>c__Iterator = new WallItem.<WaitCollectAnimation>c__Iterator0();
			<WaitCollectAnimation>c__Iterator.$this = this;
			return <WaitCollectAnimation>c__Iterator;
		}

		[DebuggerHidden]
		private IEnumerator ExplodeWall()
		{
			WallItem.<ExplodeWall>c__Iterator1 <ExplodeWall>c__Iterator = new WallItem.<ExplodeWall>c__Iterator1();
			<ExplodeWall>c__Iterator.$this = this;
			return <ExplodeWall>c__Iterator;
		}
	}
}
