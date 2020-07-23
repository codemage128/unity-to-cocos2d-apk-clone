using Assets.Scripts.CasualTools.Common.Pooling;
using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.Utils;
using System;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class ColoredCrateItem : CrateItem
	{
		private MatchType _matchType = MatchType.None;

		private Sprite[] _imageGroup;

		public override ItemType GetItemType()
		{
			return ItemType.ColoredCrate;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return sourceType == this._matchType;
		}

		public override bool CanShadowDrop()
		{
			return true;
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance == null)
			{
				return;
			}
			ColoredCrateExplodeParticlePlayer coloredCrateExplodeParticlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.ColoredCrateExploded, base.get_transform().get_position(), false) as ColoredCrateExplodeParticlePlayer;
			coloredCrateExplodeParticlePlayer.SetColor(this._matchType);
			coloredCrateExplodeParticlePlayer.Play();
		}

		public void SetupItem(TiledEditorId tiledEditorId)
		{
			switch (tiledEditorId)
			{
			case TiledEditorId.ColorCrateBlue0:
			case TiledEditorId.ColorCrateGreen0:
			case TiledEditorId.ColorCratePurple0:
			case TiledEditorId.ColorCrateOrange0:
				break;
			case TiledEditorId.ColorCrateBlue1:
			case TiledEditorId.ColorCrateGreen1:
			case TiledEditorId.ColorCratePurple1:
			case TiledEditorId.ColorCrateOrange1:
				goto IL_6B;
			case TiledEditorId.ColorCrateBlue2:
			case TiledEditorId.ColorCrateGreen2:
			case TiledEditorId.ColorCratePurple2:
			case TiledEditorId.ColorCrateOrange2:
				goto IL_77;
			default:
				switch (tiledEditorId)
				{
				case TiledEditorId.ColorCrateYellow0:
				case TiledEditorId.ColorCrateRed0:
					break;
				case TiledEditorId.ColorCrateYellow1:
				case TiledEditorId.ColorCrateRed1:
					goto IL_6B;
				case TiledEditorId.ColorCrateYellow2:
				case TiledEditorId.ColorCrateRed2:
					goto IL_77;
				default:
					goto IL_83;
				}
				break;
			}
			this.LayerCount = 1;
			goto IL_83;
			IL_6B:
			this.LayerCount = 2;
			goto IL_83;
			IL_77:
			this.LayerCount = 3;
			IL_83:
			switch (tiledEditorId)
			{
			case TiledEditorId.ColorCrateBlue0:
			case TiledEditorId.ColorCrateBlue1:
			case TiledEditorId.ColorCrateBlue2:
				this._matchType = MatchType.Blue;
				this._imageGroup = ImageLibrary.Instance.BlueCrateLayerSprites;
				break;
			case TiledEditorId.ColorCrateGreen0:
			case TiledEditorId.ColorCrateGreen1:
			case TiledEditorId.ColorCrateGreen2:
				this._matchType = MatchType.Green;
				this._imageGroup = ImageLibrary.Instance.GreenCrateLayerSprites;
				break;
			case TiledEditorId.ColorCratePurple0:
			case TiledEditorId.ColorCratePurple1:
			case TiledEditorId.ColorCratePurple2:
				this._matchType = MatchType.Purple;
				this._imageGroup = ImageLibrary.Instance.PurpleCrateLayerSprites;
				break;
			case TiledEditorId.ColorCrateOrange0:
			case TiledEditorId.ColorCrateOrange1:
			case TiledEditorId.ColorCrateOrange2:
				this._matchType = MatchType.Orange;
				this._imageGroup = ImageLibrary.Instance.OrangeCrateLayerSprites;
				break;
			default:
				switch (tiledEditorId)
				{
				case TiledEditorId.ColorCrateYellow0:
				case TiledEditorId.ColorCrateYellow1:
				case TiledEditorId.ColorCrateYellow2:
					this._matchType = MatchType.Yellow;
					this._imageGroup = ImageLibrary.Instance.YellowCrateLayerSprites;
					break;
				case TiledEditorId.ColorCrateRed0:
				case TiledEditorId.ColorCrateRed1:
				case TiledEditorId.ColorCrateRed2:
					this._matchType = MatchType.Red;
					this._imageGroup = ImageLibrary.Instance.RedCrateLayerSprites;
					break;
				default:
					this._matchType = MatchType.Blue;
					this._imageGroup = ImageLibrary.Instance.BlueCrateLayerSprites;
					break;
				}
				break;
			}
			this.CurrentSpriteRenderer.set_sprite(this._imageGroup[this.LayerCount - 1]);
		}

		public override CollectAnimation GetCollectItem()
		{
			CollectAnimation component = this.CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(base.get_transform().get_position()).GetComponent<CollectAnimation>();
			component.Prepare(this.CurrentLevel, this.GetItemType(), this.GetSorting(), this._imageGroup[0], this.CurrentCell);
			return component;
		}

		protected override void StartTranformationToNewLayer()
		{
			int layerCount = this.LayerCount;
			if (layerCount != 3)
			{
				if (layerCount == 2 || layerCount == 1)
				{
					ColoredCrateLayerRemovedParticlePlayer coloredCrateLayerRemovedParticlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.ColoredCrateLayer2Or3Exploded, base.get_transform().get_position(), false) as ColoredCrateLayerRemovedParticlePlayer;
					coloredCrateLayerRemovedParticlePlayer.SetColor(this._matchType);
					coloredCrateLayerRemovedParticlePlayer.Play();
				}
			}
			int num = this.LayerCount - 1;
			if (num < this._imageGroup.Length)
			{
				this.CurrentSpriteRenderer.set_sprite(this._imageGroup[num]);
			}
		}
	}
}
