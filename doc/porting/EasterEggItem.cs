using Assets.Scripts.CasualTools.Common.Logging;
using Assets.Scripts.CasualTools.Common.Pooling;
using Assets.Scripts.Extensions;
using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.Logging;
using Assets.Scripts.Utils;
using DG.Tweening;
using System;
using System.Collections;
using System.Diagnostics;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class EasterEggItem : SpriteBasedItem
	{
		[HideInInspector]
		public MatchType EffectiveType = MatchType.None;

		public SpriteRenderer BlurSpriteRenderer;

		public SpriteRenderer EggLinesRenderer;

		public SpriteRenderer EggLinesRenderer2;

		public Animator TransformationAnimator;

		public Color GreenMain = new Color(0.07450981f, 0.933333337f, 0.329411775f, 1f);

		public Color RedMain = new Color(1f, 0.211764708f, 0.211764708f, 1f);

		public Color BlueMain = new Color(0.6431373f, 1f, 1f, 1f);

		public Color YellowMain = new Color(1f, 0.9098039f, 0.0235294122f, 1f);

		public Color PurpleMain = new Color(0.858823538f, 0.329411775f, 1f, 1f);

		public Color OrangeMain = new Color(1f, 0.6392157f, 0.02745098f, 1f);

		public Color GreenParticle = new Color(0.156862751f, 0.9254902f, 0.192156866f, 1f);

		public Color RedParticle = new Color(1f, 0.211764708f, 0.211764708f, 1f);

		public Color BlueParticle = new Color(0.141176477f, 0.6039216f, 1f, 1f);

		public Color YellowParticle = new Color(1f, 1f, 0.384313732f, 1f);

		public Color PurpleParticle = new Color(0.7372549f, 0.20784314f, 0.78039217f, 1f);

		public Color OrangeParticle = new Color(1f, 0.56078434f, 0f, 1f);

		private bool _transformationApplied;

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			if (this.EffectiveType != MatchType.None)
			{
				return this.EffectiveType == sourceType;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			this.EffectiveType = sourceType;
			this.PlayTransformationAnimation();
			return this.EffectiveType == sourceType;
		}

		public void TransformationEnded()
		{
			this.CurrentSpriteRenderer.set_color(Color.get_white());
			this.BlurSpriteRenderer.get_gameObject().SetActive(false);
			this.EggLinesRenderer.get_gameObject().SetActive(false);
			this.EggLinesRenderer2.get_gameObject().SetActive(false);
		}

		public override void ChangeSorting(Sorting s)
		{
			base.ChangeSorting(s);
			this.BlurSpriteRenderer.set_sortingLayerID(s.LayerId);
			this.BlurSpriteRenderer.set_sortingOrder(s.Order + 1);
			this.EggLinesRenderer.set_sortingLayerID(s.LayerId);
			this.EggLinesRenderer.set_sortingOrder(s.Order + 2);
			this.EggLinesRenderer2.set_sortingLayerID(s.LayerId);
			this.EggLinesRenderer2.set_sortingOrder(s.Order + 2);
		}

		private void PlayTransformationAnimation()
		{
			if (this._transformationApplied)
			{
				return;
			}
			AudioManager.Play(AudioTag.EasterEggTransform, PlayMode.Frame, null, 1f);
			this._transformationApplied = true;
			Color color = Color.get_yellow();
			Color particle = Color.get_yellow();
			Sprite sprite;
			switch (this.EffectiveType)
			{
			case MatchType.Yellow:
				sprite = ImageLibrary.Instance.EasterEggSprites[1];
				color = this.YellowMain;
				particle = this.YellowParticle;
				break;
			case MatchType.Red:
				sprite = ImageLibrary.Instance.EasterEggSprites[2];
				color = this.RedMain;
				particle = this.RedParticle;
				break;
			case MatchType.Blue:
				sprite = ImageLibrary.Instance.EasterEggSprites[3];
				color = this.BlueMain;
				particle = this.BlueParticle;
				break;
			case MatchType.Green:
				sprite = ImageLibrary.Instance.EasterEggSprites[4];
				color = this.GreenMain;
				particle = this.GreenParticle;
				break;
			case MatchType.Purple:
				sprite = ImageLibrary.Instance.EasterEggSprites[5];
				color = this.PurpleMain;
				particle = this.PurpleParticle;
				break;
			case MatchType.Orange:
				sprite = ImageLibrary.Instance.EasterEggSprites[6];
				color = this.OrangeMain;
				particle = this.OrangeParticle;
				break;
			default:
				sprite = ImageLibrary.Instance.EasterEggSprites[1];
				break;
			}
			this.CurrentSpriteRenderer.set_sprite(sprite);
			Vector3 position = base.get_gameObject().get_transform().get_position();
			position.y -= 0.1f;
			ParticlePlayer particlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.EasterEggTransformExplosion, this, false);
			particlePlayer.get_gameObject().get_transform().set_position(position);
			particlePlayer.GetComponent<EasterEggTransformationParticle>().SetStartColors(particle, this.CurrentSpriteRenderer.get_sortingOrder() + 110);
			base.StartCoroutine(EasterEggItem.ExplodeParticle(particlePlayer, 0.15f));
			this.TransformationAnimator.set_enabled(true);
			this.CurrentSpriteRenderer.set_color(new Color(1f, 1f, 1f, 0f));
			this.BlurSpriteRenderer.get_gameObject().SetActive(true);
			this.EggLinesRenderer.get_gameObject().SetActive(true);
			this.EggLinesRenderer2.get_gameObject().SetActive(true);
			ShortcutExtensions43.DOColor(this.BlurSpriteRenderer, color, 0.27f);
		}

		[DebuggerHidden]
		private static IEnumerator ExplodeParticle(ParticlePlayer easterEggTransformParticle, float delay)
		{
			EasterEggItem.<ExplodeParticle>c__Iterator0 <ExplodeParticle>c__Iterator = new EasterEggItem.<ExplodeParticle>c__Iterator0();
			<ExplodeParticle>c__Iterator.delay = delay;
			<ExplodeParticle>c__Iterator.easterEggTransformParticle = easterEggTransformParticle;
			return <ExplodeParticle>c__Iterator;
		}

		public override bool TryExplode()
		{
			if (this.LatestExplode == (long)Time.get_frameCount())
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			if (this.EffectiveType != MatchType.None)
			{
				return true;
			}
			try
			{
				ItemType randomItemType = this.CurrentLevel.CurrentItemGroups[GroupId.Group1].GetRandomItemType();
				this.EffectiveType = randomItemType.AsMatchType();
			}
			catch
			{
				LogManager.Error(LogTags.EasterEgg, "Can not find a match from Group!", new object[0]);
				this.EffectiveType = MatchType.Blue;
			}
			this.PlayTransformationAnimation();
			return false;
		}

		public override int GetScore()
		{
			return 500;
		}

		public override bool CanCastShadow()
		{
			return true;
		}

		public override CollectAnimation GetCollectItem()
		{
			CollectAnimation component = this.CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(base.get_transform().get_position()).GetComponent<CollectAnimation>();
			component.Prepare(this.CurrentLevel, this.GetItemType(), this.GetSorting(), this.CurrentSpriteRenderer.get_sprite(), this.CurrentCell);
			component.get_transform().set_position(this.CurrentSpriteRenderer.get_transform().get_position());
			return component;
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.EasterEggExplode, PlayMode.Frame, null, 1f);
		}

		public override ItemType GetItemType()
		{
			return ItemType.EasterEgg;
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance == null)
			{
				return;
			}
			ParticlePlayer particlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.EasterEggExplosion, base.get_transform().get_position(), true);
			EasterEggExplosionParticle component = particlePlayer.GetComponent<EasterEggExplosionParticle>();
			component.SetColor(this.EffectiveType);
		}
	}
}
