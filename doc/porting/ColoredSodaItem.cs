using Assets.Scripts.GamePlayScene.Mechanics.Items.SpecialItems;
using Assets.Scripts.Utils;
using GamePlayScene;
using System;
using System.Collections.Generic;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class ColoredSodaItem : Item
	{
		public ColoredSodaFakeItem BottomRight;

		public ColoredSodaFakeItem TopLeft;

		public ColoredSodaFakeItem TopRight;

		public Animator CurrentAnimator;

		public SpriteRenderer BackSpriteRenderer;

		public Transform ExplodePosition;

		public SodaBottle[] SodaBottles;

		private List<SodaBottle> _availableBottles;

		private MatchType _matchType;

		private Sorting _sorting;

		private int[] _animations;

		private bool _isExploded;

		private float _explodedByNonSpecialItem;

		private bool _explodedBySpecialItem;

		private float _explodeTime;

		private readonly Dictionary<SpecialItem, float> _explodedBySpecialItemTime = new Dictionary<SpecialItem, float>();

		private bool _shouldSkipExplode;

		private bool _canGenerateScoreThisTurn = true;

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

		private void ChangeBottleColors(MatchType matchType)
		{
			int num = 0;
			int num2 = 360;
			float saturation = 1f;
			float valueBrightness = 1f;
			int num3 = 360;
			float saturation2 = 1f;
			float valueBrightness2 = 1f;
			switch (matchType)
			{
			case MatchType.Yellow:
				num = 0;
				num2 = 161;
				saturation = 1f;
				valueBrightness = 1.66f;
				num3 = 158;
				saturation2 = 2f;
				valueBrightness2 = 1.55f;
				break;
			case MatchType.Red:
				num = 1;
				num2 = 202;
				saturation = 1.42f;
				valueBrightness = 0.97f;
				num3 = 158;
				saturation2 = 2f;
				valueBrightness2 = 1.55f;
				break;
			case MatchType.Blue:
				num = 2;
				break;
			case MatchType.Green:
				num = 3;
				num2 = 82;
				saturation = 1.05f;
				valueBrightness = 1.25f;
				num3 = 79;
				saturation2 = 1.4f;
				valueBrightness2 = 1f;
				break;
			case MatchType.Purple:
				num = 4;
				num2 = 252;
				saturation = 1.09f;
				valueBrightness = 0.93f;
				num3 = 249;
				saturation2 = 1.45f;
				valueBrightness2 = 1f;
				break;
			}
			int num4 = this.SodaBottles.Length;
			for (int i = 0; i < num4; i++)
			{
				this.SodaBottles[i].BottleSpriteRenderer.set_sprite(ImageLibrary.Instance.SodaItemBottles[num]);
				if (this.SodaBottles[i].CapColor != null)
				{
					this.SodaBottles[i].CapColor.HueShift = (float)num2;
					this.SodaBottles[i].CapColor.Saturation = saturation;
					this.SodaBottles[i].CapColor.ValueBrightness = valueBrightness;
					this.SodaBottles[i].CapColor.CallUpdate();
				}
				if (this.SodaBottles[i].TopColor != null)
				{
					this.SodaBottles[i].TopColor.HueShift = (float)num3;
					this.SodaBottles[i].TopColor.Saturation = saturation2;
					this.SodaBottles[i].TopColor.ValueBrightness = valueBrightness2;
					this.SodaBottles[i].TopColor.CallUpdate();
				}
			}
		}

		public void Start()
		{
			this._animations = new int[]
			{
				Animator.StringToHash("Base Layer.SodaItemShakeAnimation1")
			};
			this.ChangeBottleColors(this._matchType);
		}

		public void Init(MatchType matchType)
		{
			this._matchType = matchType;
			this._availableBottles = new List<SodaBottle>
			{
				this.SodaBottles[0],
				this.SodaBottles[1],
				this.SodaBottles[2],
				this.SodaBottles[3]
			};
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
			if (this._matchType != sourceType)
			{
				return false;
			}
			this._shouldSkipExplode = false;
			this._explodedBySpecialItem = false;
			return true;
		}

		public override bool TryExplode()
		{
			return this.ExplodeBy(this);
		}

		public override bool CanGenerateScoreThisTurn()
		{
			return this._canGenerateScoreThisTurn;
		}

		public bool ExplodeBy(Item item)
		{
			this._canGenerateScoreThisTurn = false;
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
			}
			this._canGenerateScoreThisTurn = true;
			this.CurrentLevel.DecreaseGoal(ItemType.Soda, false);
			this.PlayExplodeAnimation();
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

		private void PlayExplodeAnimation()
		{
			if (this._isExploded)
			{
				return;
			}
			int index = this._availableBottles.Count - 1;
			SodaBottle sodaBottle = this._availableBottles[index];
			this._availableBottles.RemoveAt(index);
			for (int i = 0; i < this._availableBottles.Count; i++)
			{
				this._availableBottles[i].PlayShakeAnimation();
			}
			Vector3 position = sodaBottle.get_transform().get_position();
			Object.Destroy(sodaBottle.get_gameObject());
			int num = this._animations[Random.Range(0, this._animations.Length)];
			this.CurrentAnimator.Play(num, 0, 0f);
			AudioManager.Play(AudioTag.Soda1, PlayMode.Frame, null, 1f);
			if (ParticlePool.Instance == null)
			{
				return;
			}
			SodaBottleParticlePlayer component = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.SodaBottleParticleExplosion, position, true).GetComponent<SodaBottleParticlePlayer>();
			component.SetColor(this._matchType);
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
