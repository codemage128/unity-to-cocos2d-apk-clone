using Assets.Scripts.GamePlayScene.Mechanics.Items.SpecialItems;
using Assets.Scripts.Utils;
using GamePlayScene;
using System;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class SodaItem : Item
	{
		public SodaFakeItem BottomRight;

		public SodaFakeItem TopLeft;

		public SodaFakeItem TopRight;

		public Animator CurrentAnimator;

		public SpriteRenderer BackSpriteRenderer;

		public Transform ExplodePosition;

		public SodaBottle[] SodaBottles;

		private Dictionary<MatchType, SodaBottle> _availableBottles;

		private Sorting _sorting;

		private int[] _animations;

		private int _sodaCount;

		private bool _isExploded;

		private MatchType _removedType = MatchType.None;

		private float _explodedByNonSpecialItem;

		private Dictionary<MatchType, Vector2> SodaBottlePositions5 = new Dictionary<MatchType, Vector2>
		{
			{
				MatchType.Blue,
				new Vector2(0.293f, -0.147f)
			},
			{
				MatchType.Green,
				new Vector2(0.014f, -0.239f)
			},
			{
				MatchType.Red,
				new Vector2(-0.583f, -0.057f)
			},
			{
				MatchType.Yellow,
				new Vector2(-0.293f, -0.161f)
			},
			{
				MatchType.Purple,
				new Vector2(0.595f, -0.052f)
			}
		};

		private Dictionary<MatchType, Vector2> SodaBottlePositions4 = new Dictionary<MatchType, Vector2>
		{
			{
				MatchType.Blue,
				new Vector2(0.573f, -0.102f)
			},
			{
				MatchType.Green,
				new Vector2(0.232f, -0.236f)
			},
			{
				MatchType.Red,
				new Vector2(-0.546f, -0.099f)
			},
			{
				MatchType.Yellow,
				new Vector2(-0.213f, -0.226f)
			}
		};

		private bool _explodedBySpecialItem;

		private float _explodeTime;

		private readonly Dictionary<SpecialItem, float> _explodedBySpecialItemTime = new Dictionary<SpecialItem, float>();

		private bool _shouldSkipExplode;

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

		public void Start()
		{
			this._animations = new int[]
			{
				Animator.StringToHash("Base Layer.SodaItemShakeAnimation1")
			};
		}

		public void Init(int sodaCount)
		{
			this._availableBottles = new Dictionary<MatchType, SodaBottle>
			{
				{
					MatchType.Blue,
					this.SodaBottles[0]
				},
				{
					MatchType.Green,
					this.SodaBottles[1]
				},
				{
					MatchType.Red,
					this.SodaBottles[2]
				},
				{
					MatchType.Yellow,
					this.SodaBottles[3]
				},
				{
					MatchType.Purple,
					this.SodaBottles[4]
				}
			};
			this._sodaCount = sodaCount;
			Dictionary<MatchType, Vector2> dictionary = this.SodaBottlePositions5;
			if (this._sodaCount == 4)
			{
				Object.Destroy(this.SodaBottles[4].get_gameObject());
				this._availableBottles.Remove(MatchType.Purple);
				dictionary = this.SodaBottlePositions4;
			}
			foreach (KeyValuePair<MatchType, Vector2> current in dictionary)
			{
				this._availableBottles[current.Key].get_transform().set_localPosition(current.Value);
			}
		}

		public override void InformToBeExplodedBySpecialItem(SpecialItem specialItem, Direction comingFrom)
		{
			this._shouldSkipExplode = false;
			if (specialItem == null)
			{
				this._explodeTime = this._explodedByNonSpecialItem + 0.2f;
				this._explodedByNonSpecialItem = Time.get_time();
				this._explodedBySpecialItem = true;
				return;
			}
			float num = 0f;
			if (this._explodedBySpecialItemTime.TryGetValue(specialItem, out num) && Time.get_time() < num + 1f)
			{
				this._shouldSkipExplode = true;
				return;
			}
			this._explodedBySpecialItemTime[specialItem] = Time.get_time();
			this._explodedBySpecialItem = true;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			if (!this._availableBottles.ContainsKey(sourceType))
			{
				return false;
			}
			this._shouldSkipExplode = false;
			this._explodedBySpecialItem = false;
			this._removedType = sourceType;
			return true;
		}

		public override bool TryExplode()
		{
			return this.ExplodeBy(this);
		}

		public bool ExplodeBy(Item item)
		{
			if (this.LatestExplode == (long)Time.get_frameCount() || Time.get_time() < this._explodeTime)
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			if (this._isExploded)
			{
				return false;
			}
			if (this._shouldSkipExplode)
			{
				this._shouldSkipExplode = false;
				return false;
			}
			if (this._explodedBySpecialItem)
			{
				this._explodedBySpecialItem = false;
				this._removedType = this._availableBottles.ElementAt(Random.Range(0, this._availableBottles.Count)).Key;
			}
			this.CurrentLevel.DecreaseGoal(ItemType.Soda, false);
			this.PlayExplodeAnimation(this._removedType);
			if (item.ToBeExplodedBy == ExplodeReason.Anvil || item.ToBeExplodedBy == ExplodeReason.BoxingGlove || item.ToBeExplodedBy == ExplodeReason.Hammer)
			{
				ScoreManager.RaiseScore(item.GetScore(), item.get_transform().get_position(), MatchType.None);
				item.ToBeExplodedBy = ExplodeReason.None;
			}
			if (this._availableBottles.Count != 0)
			{
				return false;
			}
			this._isExploded = true;
			return true;
		}

		private void PlayExplodeAnimation(MatchType removed)
		{
			if (this._isExploded)
			{
				return;
			}
			foreach (KeyValuePair<MatchType, SodaBottle> current in this._availableBottles)
			{
				if (!(current.Value == null))
				{
					if (current.Key != removed)
					{
						current.Value.PlayShakeAnimation();
					}
				}
			}
			Vector3 position = base.get_transform().get_position();
			if (this._availableBottles.ContainsKey(removed))
			{
				position = this._availableBottles[removed].get_transform().get_position();
				Object.Destroy(this._availableBottles[removed].get_gameObject());
				this._availableBottles.Remove(removed);
			}
			int num = this._animations[Random.Range(0, this._animations.Length)];
			this.CurrentAnimator.Play(num, 0, 0f);
			AudioManager.Play(AudioTag.Soda1, PlayMode.Frame, null, 1f);
			if (ParticlePool.Instance == null)
			{
				return;
			}
			SodaBottleParticlePlayer component = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.SodaBottleParticleExplosion, position, true).GetComponent<SodaBottleParticlePlayer>();
			component.SetColor(removed);
		}

		public override ItemType GetItemType()
		{
			return ItemType.Soda;
		}

		public override Sorting GetSorting()
		{
			return this._sorting;
		}

		public override void ChangeSorting(Sorting s)
		{
			this._sorting = s;
			this.BackSpriteRenderer.set_sortingLayerID(this._sorting.LayerId);
			this.BackSpriteRenderer.set_sortingOrder(this._sorting.Order);
			this.SodaBottles[0].ChangeSorting(this._sorting, 20);
			this.SodaBottles[1].ChangeSorting(this._sorting, 30);
			this.SodaBottles[2].ChangeSorting(this._sorting, 10);
			this.SodaBottles[3].ChangeSorting(this._sorting, 20);
			this.SodaBottles[4].ChangeSorting(this._sorting, 10);
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.ItemCanClear, PlayMode.Frame, null, 1f);
		}

		public override bool CanFall()
		{
			return false;
		}

		public override int GetScore()
		{
			return 1000;
		}

		public override void StartCollect()
		{
			this.PlayExplodeAudio();
			this.PlayOnExplodeStartedAnimation();
			this.RemoveSelf();
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.SodaItemExplodeParticle, this.ExplodePosition.get_position(), true);
			}
		}

		public override void RemoveSelf()
		{
			base.RemoveSelf();
			this.BottomRight.RemoveSelf();
			this.TopLeft.RemoveSelf();
			this.TopRight.RemoveSelf();
		}

		public override bool CanGenerateScoreOnEachTryExplode()
		{
			return true;
		}
	}
}
