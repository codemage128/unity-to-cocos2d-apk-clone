using Assets.Scripts.CasualTools.Common.Logging;
using Assets.Scripts.CasualTools.Common.Pooling;
using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.GamePlayScene.Mechanics.Items.Features;
using Assets.Scripts.Logging;
using Assets.Scripts.Utils;
using System;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class ColoredBalloonItem : SpriteBasedItem, ICanBePaint
	{
		private MatchType _currentMatchType;

		private ColoredBalloonType _type;

		public void Paint(MatchType mType)
		{
			switch (mType)
			{
			case MatchType.Yellow:
				this._type = ColoredBalloonType.Balloon1;
				break;
			case MatchType.Red:
				this._type = ColoredBalloonType.Balloon2;
				break;
			case MatchType.Blue:
				this._type = ColoredBalloonType.Balloon3;
				break;
			case MatchType.Green:
				this._type = ColoredBalloonType.Balloon4;
				break;
			case MatchType.Purple:
				this._type = ColoredBalloonType.Balloon5;
				break;
			case MatchType.Orange:
				this._type = ColoredBalloonType.Balloon6;
				break;
			default:
				if (mType != MatchType.None)
				{
				}
				break;
			}
			this._currentMatchType = mType;
			this.CurrentSpriteRenderer.set_sprite(ImageLibrary.Instance.ColoredBalloonSprites[this._type - ColoredBalloonType.Balloon1]);
		}

		public override int GetScore()
		{
			return 500;
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.ItemBalloon, PlayMode.Frame, null, 1f);
		}

		public override CollectAnimation GetCollectItem()
		{
			CollectAnimation component = this.CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(base.get_transform().get_position()).GetComponent<CollectAnimation>();
			component.get_transform().set_position(this.CurrentSpriteRenderer.get_transform().get_position());
			component.Prepare(this.CurrentLevel, this.GetItemType(), this.GetSorting(), ImageLibrary.Instance.ColoredBalloonSprites[this._type - ColoredBalloonType.Balloon1], this.CurrentCell);
			return component;
		}

		public void SetupItem(ColoredBalloonType type)
		{
			this._type = type;
			switch (this._type)
			{
			case ColoredBalloonType.Balloon1:
				this._currentMatchType = MatchType.Yellow;
				break;
			case ColoredBalloonType.Balloon2:
				this._currentMatchType = MatchType.Red;
				break;
			case ColoredBalloonType.Balloon3:
				this._currentMatchType = MatchType.Blue;
				break;
			case ColoredBalloonType.Balloon4:
				this._currentMatchType = MatchType.Green;
				break;
			case ColoredBalloonType.Balloon5:
				this._currentMatchType = MatchType.Purple;
				break;
			case ColoredBalloonType.Balloon6:
				this._currentMatchType = MatchType.Orange;
				break;
			default:
				LogManager.Error(LogTags.ColoredBalloonItem, "Cannot Initialize Colored Balloon item with type: " + type, new object[0]);
				break;
			}
			this.CurrentSpriteRenderer.set_sprite(ImageLibrary.Instance.ColoredBalloonSprites[this._type - ColoredBalloonType.Balloon1]);
		}

		public override bool CanBeTapped()
		{
			return false;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return sourceType == this.GetMatchType();
		}

		public override bool CanBeEffectedByDiscoBall()
		{
			return false;
		}

		public override MatchType GetMatchType()
		{
			return this._currentMatchType;
		}

		public override ItemType GetItemType()
		{
			return ItemType.ColoredBalloon;
		}

		public override bool CanBePaint()
		{
			return true;
		}

		public override bool CanCastShadow()
		{
			return true;
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePlayer particlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.ColoredBalloon, base.get_transform().get_position(), true);
				ColoredBalloonParticlePlayer component = particlePlayer.GetComponent<ColoredBalloonParticlePlayer>();
				component.SetColor(this._currentMatchType);
			}
		}
	}
}
