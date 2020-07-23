using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.Utils;
using System;
using System.Collections.Generic;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public class BillboardItem : SpriteBasedItem
	{
		private static int GlobalBillboardId;

		public SpriteRenderer[] BillboardSpriteRenderers;

		public SpriteRenderer PlugSpriteRenderer;

		public SpriteRenderer GlowSpriteRenderer;

		[HideInInspector]
		public BillboardItem MasterItem;

		[HideInInspector]
		public bool IsMasterItem;

		[HideInInspector]
		public int BillboardId;

		private List<BillboardItem> _children;

		private int _collectCount;

		private bool _isCollected;

		private bool _canGenerateScore = true;

		private int _scoreCount;

		private int[] _cornerSortingOffsets = new int[4];

		private Sorting _sorting;

		public override bool CanRaiseScore()
		{
			return true;
		}

		public override int GetScore()
		{
			return 500;
		}

		public override bool CanFall()
		{
			return false;
		}

		public override bool CanShadowDrop()
		{
			return true;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override bool CanGenerateScoreOnEachTryExplode()
		{
			return this._canGenerateScore;
		}

		public override bool CanBeTapped()
		{
			return false;
		}

		public override ItemType GetItemType()
		{
			return ItemType.Billboard;
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.ItemDiamond2, PlayMode.Frame, null, 1f);
		}

		public override bool CanGenerateScoreWithoutExplode()
		{
			return true;
		}

		public override void ChangeSorting(Sorting s)
		{
			this._sorting = s;
			int num = this.BillboardSpriteRenderers.Length;
			this.PlugSpriteRenderer.set_sortingLayerID(s.LayerId);
			this.PlugSpriteRenderer.set_sortingOrder(s.Order + 60);
			for (int i = 0; i < num; i++)
			{
				this.BillboardSpriteRenderers[i].set_sortingLayerID(s.LayerId);
				this.BillboardSpriteRenderers[i].set_sortingOrder(s.Order + this._cornerSortingOffsets[i]);
			}
			this.CurrentSpriteRenderer.set_sortingLayerID(s.LayerId);
			this.CurrentSpriteRenderer.set_sortingOrder(s.Order + 70);
			this.GlowSpriteRenderer.set_sortingLayerID(s.LayerId);
			this.GlowSpriteRenderer.set_sortingOrder(s.Order + 101);
		}

		public override void PlayWrongMove()
		{
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.BillboardExplodeParticle, base.get_transform().get_position(), true);
			}
		}

		public override bool TryExplode()
		{
			this._scoreCount++;
			if (this._scoreCount > 1)
			{
				this._canGenerateScore = false;
			}
			if (this.LatestExplode == (long)Time.get_frameCount())
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			if (this._isCollected)
			{
				return false;
			}
			this._isCollected = true;
			this.CurrentLevel.DecreaseGoal(ItemType.Billboard, false);
			this.CurrentSpriteRenderer.set_enabled(false);
			this.GlowSpriteRenderer.set_enabled(false);
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.BillboardCollectParticle, base.get_transform().get_position(), true);
			}
			AudioManager.Play(AudioTag.ItemBillboardBreak, PlayMode.Frame, null, 1f);
			if (this.MasterItem != null)
			{
				this.MasterItem.NotifyItemCollected();
			}
			else
			{
				this.NotifyItemCollected();
			}
			if (this.ToBeExplodedBy == ExplodeReason.Anvil || this.ToBeExplodedBy == ExplodeReason.BoxingGlove || this.ToBeExplodedBy == ExplodeReason.Hammer)
			{
				ScoreManager.RaiseScore(this.GetScore(), base.get_transform().get_position(), MatchType.None);
				this.ToBeExplodedBy = ExplodeReason.None;
			}
			return false;
		}

		public void NotifyItemCollected()
		{
			this._collectCount--;
			if (this._collectCount != 0)
			{
				return;
			}
			if (this._children != null && this._children.Count > 0)
			{
				int count = this._children.Count;
				for (int i = 0; i < count; i++)
				{
					this._children[i].StartExplode();
				}
				this._children = null;
			}
			this.StartExplode();
			AudioManager.Play(AudioTag.ItemBillboardExplode, PlayMode.Frame, null, 1f);
		}

		private void UpdateView()
		{
			Grid currentGrid = this.CurrentCell.CurrentGrid;
			bool billboardItem = this.GetBillboardItem(currentGrid.GetCellWithDirection(this.CurrentCell, Direction.Up));
			bool billboardItem2 = this.GetBillboardItem(currentGrid.GetCellWithDirection(this.CurrentCell, Direction.Down));
			bool billboardItem3 = this.GetBillboardItem(currentGrid.GetCellWithDirection(this.CurrentCell, Direction.Left));
			bool billboardItem4 = this.GetBillboardItem(currentGrid.GetCellWithDirection(this.CurrentCell, Direction.Right));
			this.SetSprite(this.BillboardSpriteRenderers[0], billboardItem3, billboardItem, Direction.LeftUp, false, false);
			this.SetSprite(this.BillboardSpriteRenderers[1], billboardItem4, billboardItem, Direction.RightUp, true, false);
			this.SetSprite(this.BillboardSpriteRenderers[2], billboardItem4, billboardItem2, Direction.RightDown, true, true);
			this.SetSprite(this.BillboardSpriteRenderers[3], billboardItem3, billboardItem2, Direction.LeftDown, false, true);
		}

		private void SetSprite(SpriteRenderer spriteRenderer, bool x, bool y, Direction checkDirection, bool right, bool down)
		{
			Sprite sprite;
			if (x && y)
			{
				bool billboardItem = this.GetBillboardItem(this.CurrentCell.CurrentGrid.GetCellWithDirection(this.CurrentCell, checkDirection));
				if (billboardItem)
				{
					sprite = ((!down) ? ImageLibrary.Instance.Billboard_D_Up : ImageLibrary.Instance.Billboard_D_Down);
				}
				else
				{
					sprite = ((!down) ? ImageLibrary.Instance.Billboard_C_Up : ImageLibrary.Instance.Billboard_C_Down);
					spriteRenderer.get_transform().set_localPosition(new Vector3((!right) ? -0.5f : 0.5f, (!down) ? 0.4f : -0.6f, 0f));
					this.CurrentSpriteRenderer.get_transform().set_localPosition((!down) ? new Vector3(0f, -0.03f, 0f) : new Vector3(0f, -0.15f, 0f));
					this.PlugSpriteRenderer.get_transform().set_localPosition((!down) ? new Vector3(0f, -0.052f, 0f) : new Vector3(0f, -0.1f, 0f));
					Direction direction = (!down) ? Direction.Up : ((!right) ? Direction.Left : Direction.Right);
					Cell cellWithDirection = this.CurrentCell.CurrentGrid.GetCellWithDirection(this.CurrentCell, direction);
					if (cellWithDirection != null && cellWithDirection.HasItem)
					{
						BillboardItem component = cellWithDirection.CurrentItem.GetComponent<BillboardItem>();
						SpriteRenderer spriteRenderer2 = (!right) ? component.BillboardSpriteRenderers[(!down) ? 3 : 2] : component.BillboardSpriteRenderers[(!down) ? 2 : 3];
						if (spriteRenderer2.get_enabled())
						{
							spriteRenderer2.set_enabled(false);
						}
					}
					if (down)
					{
						this._cornerSortingOffsets[(!right) ? 3 : 2] = -80;
					}
					else
					{
						this._cornerSortingOffsets[(!right) ? 0 : 1] = 1;
					}
					this.ChangeSorting(this._sorting);
				}
			}
			else if (x)
			{
				sprite = ((!down) ? ImageLibrary.Instance.Billboard_B_Up : ImageLibrary.Instance.Billboard_B_Down);
			}
			else if (y)
			{
				sprite = ((!down) ? ImageLibrary.Instance.Billboard_E_Up : ImageLibrary.Instance.Billboard_E_Down);
			}
			else
			{
				sprite = ((!down) ? ImageLibrary.Instance.Billboard_A_Up : ImageLibrary.Instance.Billboard_A_Down);
			}
			spriteRenderer.set_sprite(sprite);
			spriteRenderer.set_flipX(right);
		}

		private bool GetBillboardItem(Cell cell)
		{
			return cell != null && cell.Exists && cell.HasItem && cell.CurrentItem is BillboardItem && ((BillboardItem)cell.CurrentItem).BillboardId == this.BillboardId;
		}

		public void LinkNeighbours(Cell cell)
		{
			if (!cell.Exists || !cell.HasItem)
			{
				return;
			}
			BillboardItem billboardItem = cell.CurrentItem as BillboardItem;
			if (billboardItem == null || billboardItem.MasterItem != null || billboardItem.IsMasterItem)
			{
				return;
			}
			if (billboardItem == this)
			{
				this.IsMasterItem = true;
				this._collectCount = 1;
				this.BillboardId = BillboardItem.GlobalBillboardId;
				BillboardItem.GlobalBillboardId++;
				if (this._children == null)
				{
					this._children = new List<BillboardItem>();
				}
			}
			else
			{
				this._collectCount++;
				billboardItem.MasterItem = this;
				billboardItem.BillboardId = this.BillboardId;
				this._children.Add(billboardItem);
			}
			Grid currentGrid = cell.CurrentGrid;
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
			billboardItem.UpdateView();
		}
	}
}
