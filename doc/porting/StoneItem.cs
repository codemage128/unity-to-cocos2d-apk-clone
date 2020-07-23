using Assets.Scripts.CasualTools.Common.Tasks;
using Assets.Scripts.Extensions;
using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.Utils;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public class StoneItem : SpriteBasedItem
	{
		public ParticleSystem AnimationParticle;

		public Transform EffectsContainer;

		public SpriteRenderer[] Tiles;

		public SpriteRenderer[] Effects;

		public Animator CurrentAnimator;

		[HideInInspector]
		public StoneItem MasterItem;

		[HideInInspector]
		public bool IsMasterItem;

		[HideInInspector]
		public int StoneId;

		[HideInInspector]
		public int ExplosionOrder = 1000;

		private static int _globalStoneId;

		private List<StoneItem> _children;

		private int _layer = 5;

		private Sorting _sorting;

		private readonly int[] _cornerSortingOffsets = new int[4];

		private ItemResources _resources;

		private const int Sprite_None = 0;

		private const int Sprite_Bottom_1 = 1;

		private const int Sprite_Bottom_2 = 2;

		private const int Sprite_Bottom_3 = 3;

		private const int Sprite_BottomCorner = 4;

		private const int Sprite_Corner_A = 5;

		private const int Sprite_Corner_B = 6;

		private const int Sprite_Mid = 7;

		private const int Sprite_Side_1 = 8;

		private const int Sprite_Side_2 = 9;

		private const int Sprite_Side_3 = 10;

		private const int Sprite_Top_1 = 11;

		private const int Sprite_Top_2 = 18;

		private const int Sprite_TopCorner_Left = 12;

		private const int Sprite_TopCorner_Right = 13;

		private const int Sprite_Mid_70 = 14;

		private const int Sprite_Side_1_70 = 15;

		private const int Sprite_Side_2_70 = 16;

		private const int Sprite_Side_3_70 = 17;

		private const int Sprite_Effects_Count = 5;

		private const int Sprite_Effects_Start_Index = 19;

		private const int Sprite_State_1 = 29;

		private const int Sprite_State_2 = 30;

		private const int Sprite_State_3 = 31;

		private const int Sprite_State_4 = 32;

		private static readonly List<int> topSprites = new List<int>
		{
			11,
			18
		};

		private static readonly List<int> bottomSprites = new List<int>
		{
			3,
			3,
			3,
			2,
			1
		};

		private static readonly List<int> sideSprites = new List<int>
		{
			8,
			9,
			10
		};

		private static readonly List<int> side70Sprites = new List<int>
		{
			15,
			16,
			17
		};

		private static readonly int[] stateSprites = new int[]
		{
			29,
			30,
			31,
			32
		};

		private readonly int _animationStage2To1Hash = Animator.StringToHash("StoneItemAnimation2_1");

		private bool _isExploded;

		public override ItemType GetItemType()
		{
			return ItemType.Stone;
		}

		public override int GetScore()
		{
			return 500;
		}

		public override bool CanRaiseScore()
		{
			return true;
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

		public override bool CanBeTapped()
		{
			return false;
		}

		public override bool CanGenerateScoreWithoutExplode()
		{
			return true;
		}

		public override bool CanBeInsideBubble()
		{
			return false;
		}

		public override void PlayWrongMove()
		{
		}

		public override void ChangeSorting(Sorting s)
		{
			this._sorting = s;
			for (int i = 0; i < 4; i++)
			{
				this.Tiles[i].set_sortingLayerID(s.LayerId);
				this.Tiles[i].set_sortingOrder(s.Order + this._cornerSortingOffsets[i]);
			}
			for (int j = 0; j < 2; j++)
			{
				this.Effects[j].set_sortingLayerID(s.LayerId);
				this.Effects[j].set_sortingOrder(s.Order + 21 + j);
			}
			this.CurrentSpriteRenderer.set_sortingLayerID(s.LayerId);
			this.CurrentSpriteRenderer.set_sortingOrder(s.Order + 31);
		}

		private void UpdateSprites()
		{
			CaravanGrid currentGrid = this.CurrentCell.CurrentGrid;
			bool stoneItem = this.GetStoneItem(currentGrid.GetCellWithDirection(this.CurrentCell, Direction.Up));
			bool stoneItem2 = this.GetStoneItem(currentGrid.GetCellWithDirection(this.CurrentCell, Direction.Down));
			bool stoneItem3 = this.GetStoneItem(currentGrid.GetCellWithDirection(this.CurrentCell, Direction.Left));
			bool stoneItem4 = this.GetStoneItem(currentGrid.GetCellWithDirection(this.CurrentCell, Direction.Right));
			this.SetSprite(this.Tiles[0], stoneItem3, stoneItem, Direction.LeftUp, false, false);
			this.SetSprite(this.Tiles[1], stoneItem4, stoneItem, Direction.RightUp, true, false);
			this.SetSprite(this.Tiles[2], stoneItem4, stoneItem2, Direction.RightDown, true, true);
			this.SetSprite(this.Tiles[3], stoneItem3, stoneItem2, Direction.LeftDown, false, true);
			this.SetEffect();
		}

		private void SetSprite(SpriteRenderer spriteRenderer, bool x, bool y, Direction checkDirection, bool right, bool down)
		{
			if (this._resources == null)
			{
				this._resources = ItemResourcesManager.Instance.GetResources(this.GetItemType());
			}
			Sprite sprite;
			if (x && y)
			{
				bool stoneItem = this.GetStoneItem(this.CurrentCell.CurrentGrid.GetCellWithDirection(this.CurrentCell, checkDirection));
				if (stoneItem)
				{
					sprite = ((!down) ? this._resources.Sprites[14] : this._resources.Sprites[7]);
				}
				else
				{
					sprite = ((!down) ? this._resources.Sprites[5] : this._resources.Sprites[6]);
					spriteRenderer.get_transform().set_localPosition(new Vector3((!right) ? -0.5f : 0.5f, (!down) ? 0.4f : -0.6f, 0f));
					Direction direction = (!down) ? Direction.Up : ((!right) ? Direction.Left : Direction.Right);
					Cell cellWithDirection = this.CurrentCell.CurrentGrid.GetCellWithDirection(this.CurrentCell, direction);
					if (cellWithDirection != null && cellWithDirection.HasItem)
					{
						StoneItem component = cellWithDirection.CurrentItem.GetComponent<StoneItem>();
						SpriteRenderer spriteRenderer2 = (!right) ? component.Tiles[(!down) ? 3 : 2] : component.Tiles[(!down) ? 2 : 3];
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
				sprite = ((!down) ? this.SelectSprite(StoneItem.topSprites) : this.SelectSprite(StoneItem.bottomSprites));
			}
			else if (y)
			{
				sprite = ((!down) ? this.SelectSprite(StoneItem.side70Sprites) : this.SelectSprite(StoneItem.sideSprites));
			}
			else if (down)
			{
				sprite = this._resources.Sprites[4];
			}
			else if (right)
			{
				sprite = this._resources.Sprites[13];
				right = false;
			}
			else
			{
				sprite = this._resources.Sprites[12];
			}
			spriteRenderer.set_sprite(sprite);
			spriteRenderer.set_flipX(right);
		}

		private Sprite SelectSprite(IList<int> spriteIndexes)
		{
			spriteIndexes.Shuffle<int>();
			return this._resources.Sprites[spriteIndexes[0]];
		}

		private void SetEffect()
		{
			int num = 19 + Random.Range(0, 5) * 2;
			SpriteRenderer spriteRenderer = this.Effects[0];
			SpriteRenderer spriteRenderer2 = this.Effects[1];
			spriteRenderer.set_sprite(this._resources.Sprites[num]);
			spriteRenderer2.set_sprite(this._resources.Sprites[num + 1]);
			spriteRenderer.set_enabled(spriteRenderer.get_sprite() != null && Random.Range(0, 10) >= 6);
			spriteRenderer2.set_enabled(spriteRenderer2.get_sprite() != null && Random.Range(0, 10) >= 6);
			if (Random.Range(0, 10) >= 5)
			{
				this.EffectsContainer.set_localScale(new Vector3(-1f, 1f, 1f));
			}
		}

		private bool GetStoneItem(Cell cell)
		{
			return cell != null && cell.Exists && cell.HasItem && cell.CurrentItem is StoneItem && ((StoneItem)cell.CurrentItem).StoneId == this.StoneId;
		}

		public void LinkNeighbours(Cell cell)
		{
			if (!cell.Exists || !cell.HasItem)
			{
				return;
			}
			if (this._resources == null)
			{
				this._resources = ItemResourcesManager.Instance.GetResources(this.GetItemType());
			}
			StoneItem stoneItem = cell.CurrentItem as StoneItem;
			if (stoneItem == null || stoneItem.MasterItem != null || stoneItem.IsMasterItem)
			{
				stoneItem = (cell.CurrentItem.GetSubItem() as StoneItem);
				if (stoneItem == null || stoneItem.MasterItem != null || stoneItem.IsMasterItem)
				{
					return;
				}
			}
			if (stoneItem == this)
			{
				this.IsMasterItem = true;
				this.StoneId = StoneItem._globalStoneId;
				StoneItem._globalStoneId++;
				if (this._children == null)
				{
					this._children = new List<StoneItem>();
				}
			}
			else
			{
				stoneItem.StoneId = this.StoneId;
			}
			stoneItem.MasterItem = this;
			this._children.Add(stoneItem);
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
			stoneItem.UpdateSprites();
		}

		public override void PlayExplodeAudio()
		{
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			this.PlayItemParticle(4);
		}

		public override bool TryExplode()
		{
			if (this.LatestExplode == (long)Time.get_frameCount())
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			bool flag = this.TransformToNextLayer();
			if (flag)
			{
				return false;
			}
			this.PrepareExplosionOrder(this.CurrentCell, 0);
			this.MasterItem.NotifyItemCollected();
			if (this.ToBeExplodedBy == ExplodeReason.Anvil || this.ToBeExplodedBy == ExplodeReason.BoxingGlove || this.ToBeExplodedBy == ExplodeReason.Hammer)
			{
				ScoreManager.RaiseScore(this.GetScore(), base.get_transform().get_position(), MatchType.None);
				this.ToBeExplodedBy = ExplodeReason.None;
			}
			return false;
		}

		private void PrepareExplosionOrder(Cell cell, int order)
		{
			if (!cell.Exists || !cell.HasItem)
			{
				return;
			}
			StoneItem stoneItem = cell.CurrentItem as StoneItem;
			if (stoneItem == null)
			{
				return;
			}
			if (stoneItem.ExplosionOrder <= order)
			{
				return;
			}
			stoneItem.ExplosionOrder = order;
			int order2 = order + 1;
			CaravanGrid currentGrid = cell.CurrentGrid;
			Cell cellWithDirection = currentGrid.GetCellWithDirection(cell, Direction.Left);
			if (cellWithDirection != null)
			{
				this.PrepareExplosionOrder(cellWithDirection, order2);
			}
			Cell cellWithDirection2 = currentGrid.GetCellWithDirection(cell, Direction.Right);
			if (cellWithDirection2 != null)
			{
				this.PrepareExplosionOrder(cellWithDirection2, order2);
			}
			Cell cellWithDirection3 = currentGrid.GetCellWithDirection(cell, Direction.Up);
			if (cellWithDirection3 != null)
			{
				this.PrepareExplosionOrder(cellWithDirection3, order2);
			}
			Cell cellWithDirection4 = currentGrid.GetCellWithDirection(cell, Direction.Down);
			if (cellWithDirection4 != null)
			{
				this.PrepareExplosionOrder(cellWithDirection4, order2);
			}
		}

		private bool TransformToNextLayer()
		{
			this._layer--;
			if (this._layer > 0)
			{
				this.CurrentSpriteRenderer.set_sprite(this._resources.Sprites[StoneItem.stateSprites[this._layer - 1]]);
				this.CurrentSpriteRenderer.get_transform().set_localEulerAngles(Vector3.get_zero());
				switch (this._layer)
				{
				case 1:
					AudioManager.PlayAudioProps(this._resources.AudioClips[1], PlayMode.Frame, null, 1f);
					this.PlayItemParticle(3);
					this.AnimationParticle.Play();
					this.CurrentAnimator.Play(this._animationStage2To1Hash);
					break;
				case 2:
					AudioManager.PlayAudioProps(this._resources.AudioClips[1], PlayMode.Frame, null, 1f);
					this.PlayItemParticle(2);
					break;
				case 3:
					AudioManager.PlayAudioProps(this._resources.AudioClips[1], PlayMode.Frame, null, 1f);
					this.PlayItemParticle(1);
					break;
				case 4:
					AudioManager.PlayAudioProps(this._resources.AudioClips[0], PlayMode.Frame, null, 1f);
					this.PlayItemParticle(0);
					this.CurrentSpriteRenderer.get_transform().set_localEulerAngles(Vector3.get_forward() * Random.Range(-70f, 71f));
					break;
				}
				return true;
			}
			this.CurrentSpriteRenderer.set_enabled(false);
			return false;
		}

		private void PlayItemParticle(int particleIndex)
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(this._resources.Particles[particleIndex], base.get_transform().get_position(), true);
			}
		}

		private void NotifyItemCollected()
		{
			this._children.Sort(delegate(StoneItem a, StoneItem b)
			{
				if (a.ExplosionOrder == b.ExplosionOrder)
				{
					return 0;
				}
				return (a.ExplosionOrder <= b.ExplosionOrder) ? -1 : 1;
			});
			List<StoneItemOder> list = new List<StoneItemOder>();
			for (int i = 0; i < this._children.Count; i++)
			{
				list.Add(new StoneItemOder
				{
					Item = this._children[i],
					Order = this._children[i].ExplosionOrder
				});
			}
			new Task(this.StartExplosionChain(list));
		}

		[DebuggerHidden]
		private IEnumerator StartExplosionChain(List<StoneItemOder> children)
		{
			StoneItem.<StartExplosionChain>c__Iterator0 <StartExplosionChain>c__Iterator = new StoneItem.<StartExplosionChain>c__Iterator0();
			<StartExplosionChain>c__Iterator.children = children;
			return <StartExplosionChain>c__Iterator;
		}

		public override void StartExplode()
		{
			if (this._isExploded)
			{
				return;
			}
			this._isExploded = true;
			AudioManager.PlayAudioProps(this._resources.AudioClips[2], PlayMode.Frame, null, 1f);
			this.CurrentLevel.DecreaseGoal(ItemType.Stone, false);
			ScoreManager.RaiseScore(this.GetScore(), base.get_transform().get_position(), MatchType.None);
			base.StartExplode();
		}

		public override void RemoveSelf()
		{
			base.StartCoroutine(this.Remove());
		}

		[DebuggerHidden]
		private IEnumerator Remove()
		{
			StoneItem.<Remove>c__Iterator1 <Remove>c__Iterator = new StoneItem.<Remove>c__Iterator1();
			<Remove>c__Iterator.$this = this;
			return <Remove>c__Iterator;
		}
	}
}
