using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.Utils;
using DG.Tweening;
using System;
using UnityEngine;

namespace GamePlayScene.Mechanics.Items
{
	public class PotionItem : Item, IExplodeAware
	{
		public Animator CurrentAnimator;

		public SpriteRenderer[] SortingSprites;

		public SpriteRenderer SurfaceSpriteRenderer;

		public SpriteRenderer SurfaceNextSpriteRenderer;

		public SpriteRenderer InnerSpriteRenderer;

		public SpriteRenderer InnerNextSpriteRenderer;

		private static readonly Color[] SurfaceColors = new Color[]
		{
			new Color(0.996078432f, 0.9647059f, 0.7647059f),
			new Color(0.9882353f, 0.6431373f, 0.6f),
			new Color(0.6666667f, 0.8980392f, 0.992156863f),
			new Color(0.8627451f, 0.992156863f, 0.7294118f),
			new Color(0.8980392f, 0.698039234f, 0.9882353f),
			new Color(0.992156863f, 0.8235294f, 0.6039216f)
		};

		private readonly Color _zeroAlpha = new Color(1f, 1f, 1f, 0f);

		private readonly Color _fullAlpha = new Color(1f, 1f, 1f, 1f);

		private MatchType _matchType;

		private int _currentIndex;

		private bool _isDestroyed;

		private Sorting _sorting;

		private int[] _dropAnimations;

		private Sequence _transformSequence;

		public override void OnItemCreated(Level currentLevel)
		{
			base.OnItemCreated(currentLevel);
			this.CurrentLevel.ExplodeAwareItem.Add(this);
			this._dropAnimations = new int[3];
			this._dropAnimations[0] = Animator.StringToHash("Base Layer.PotionDropAnimation1");
			this._dropAnimations[1] = Animator.StringToHash("Base Layer.PotionDropAnimation2");
			this._dropAnimations[2] = Animator.StringToHash("Base Layer.PotionDropAnimation3");
			this.UpdateView();
		}

		public void Init(MatchType matchType)
		{
			this._matchType = matchType;
		}

		public override void ChangeSorting(Sorting s)
		{
			this._sorting = s;
			int i = 0;
			int num = this.SortingSprites.Length;
			while (i < num)
			{
				SpriteRenderer spriteRenderer = this.SortingSprites[i];
				if (!(spriteRenderer == null))
				{
					spriteRenderer.set_sortingLayerID(this._sorting.LayerId);
					spriteRenderer.set_sortingOrder(this._sorting.Order + i);
				}
				i++;
			}
		}

		public override Sorting GetSorting()
		{
			return this._sorting;
		}

		public override ItemType GetItemType()
		{
			return ItemType.Potion;
		}

		public override int GetScore()
		{
			return 500;
		}

		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return this._matchType == sourceType;
		}

		public override bool CanBeInsideBubble()
		{
			return true;
		}

		public override bool CanCastShadow()
		{
			return true;
		}

		public override bool TryExplode()
		{
			if (this.LatestExplode == (long)Time.get_frameCount())
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			this._isDestroyed = true;
			return true;
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this.GetItemType()).AudioClips[3], PlayMode.Frame, null, 1f);
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			ItemResources resources = ItemResourcesManager.Instance.GetResources(this.GetItemType());
			if (ParticlePool.Instance != null && resources != null)
			{
				PotionParticlePlayer component = ParticlePool.Instance.PlayParticle(resources.Particles[1], base.get_transform().get_position(), true).GetComponent<PotionParticlePlayer>();
				component.SetColor(this._matchType);
			}
		}

		private int TransformToColorByMatchType(MatchType matchType, bool instantColor = true)
		{
			int num;
			switch (matchType)
			{
			case MatchType.Yellow:
				num = 0;
				break;
			case MatchType.Red:
				num = 1;
				break;
			case MatchType.Blue:
				num = 2;
				break;
			case MatchType.Green:
				num = 3;
				break;
			case MatchType.Purple:
				num = 4;
				break;
			case MatchType.Orange:
				num = 5;
				break;
			default:
				num = -1;
				break;
			}
			if (num == -1)
			{
				this.InnerSpriteRenderer.set_sprite(null);
				return num;
			}
			if (instantColor)
			{
				ItemResources resources = ItemResourcesManager.Instance.GetResources(this.GetItemType());
				this.InnerSpriteRenderer.set_sprite(resources.Sprites[num]);
				this.SurfaceSpriteRenderer.set_color(PotionItem.SurfaceColors[num]);
			}
			return num;
		}

		private void PlayTransformAnimation(int nextIndex)
		{
			if (nextIndex == -1)
			{
				return;
			}
			this._transformSequence = DOTween.Sequence();
			ItemResources resources = ItemResourcesManager.Instance.GetResources(this.GetItemType());
			this.InnerNextSpriteRenderer.set_sprite(resources.Sprites[nextIndex]);
			this.InnerNextSpriteRenderer.set_color(this._zeroAlpha);
			Color surfaceNextColor = PotionItem.SurfaceColors[nextIndex];
			surfaceNextColor.a = 0f;
			this.SurfaceNextSpriteRenderer.set_color(surfaceNextColor);
			TweenSettingsExtensions.Insert(this._transformSequence, 0f, ShortcutExtensions43.DOFade(this.InnerSpriteRenderer, 0.8f, 0.5f));
			TweenSettingsExtensions.Insert(this._transformSequence, 0f, ShortcutExtensions43.DOFade(this.InnerNextSpriteRenderer, 1f, 0.5f));
			TweenSettingsExtensions.Insert(this._transformSequence, 0f, ShortcutExtensions43.DOFade(this.SurfaceSpriteRenderer, 0.8f, 0.5f));
			TweenSettingsExtensions.Insert(this._transformSequence, 0f, ShortcutExtensions43.DOFade(this.SurfaceNextSpriteRenderer, 1f, 0.5f));
			if (ParticlePool.Instance != null && resources != null)
			{
				PotionParticlePlayer component = ParticlePool.Instance.PlayParticle(resources.Particles[0], this, true).GetComponent<PotionParticlePlayer>();
				component.SetColor(this._matchType);
				ItemResources.AudioProps audioProps = resources.AudioClips[Random.Range(0, 3)];
				AudioManager.PlayAudioProps(audioProps, PlayMode.Frame, null, 1f);
			}
			TweenSettingsExtensions.OnComplete<Sequence>(this._transformSequence, delegate
			{
				this.InnerSpriteRenderer.set_sprite(this.InnerNextSpriteRenderer.get_sprite());
				this.InnerSpriteRenderer.set_color(this._fullAlpha);
				this.InnerNextSpriteRenderer.set_color(this._zeroAlpha);
				surfaceNextColor.a = 1f;
				this.SurfaceSpriteRenderer.set_color(surfaceNextColor);
				surfaceNextColor.a = 0f;
				this.SurfaceNextSpriteRenderer.set_color(surfaceNextColor);
			});
		}

		public void ExplosionOccured(int moveCount)
		{
			if (this._isDestroyed)
			{
				return;
			}
			this._matchType = this.CurrentLevel.GetNextMatchType(ref this._currentIndex);
			TweenExtensions.Kill(this._transformSequence, false);
			this.PlayTransformAnimation(this.TransformToColorByMatchType(this._matchType, false));
		}

		public override void OnFallEnded()
		{
			base.OnFallEnded();
			this.CurrentAnimator.Play(this._dropAnimations[Random.Range(0, 3)], 0, 0f);
		}

		public override void UpdateView()
		{
			this._currentIndex = this.CurrentLevel.GetPotionMatchTypeIndex(this._matchType);
			if (this._currentIndex == -1)
			{
				this._matchType = this.CurrentLevel.GetRandomMatchType(ref this._currentIndex);
			}
			this.TransformToColorByMatchType(this._matchType, true);
		}
	}
}
