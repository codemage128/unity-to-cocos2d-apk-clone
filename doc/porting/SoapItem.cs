using Assets.Scripts.CasualTools.Common.Pooling;
using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.Utils;
using GamePlayScene.Mechanics;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using UnityEngine;

public class SoapItem : Item
{
	public SpriteRenderer[] SpriteRenderers;

	private Sorting _currentSorting;

	private bool _isDestroyed;

	private bool _canGenerateScore = true;

	private Vector3 LastPosition
	{
		get;
		set;
	}

	public override ItemType GetItemType()
	{
		return ItemType.Soap;
	}

	public override void ChangeSorting(Sorting s)
	{
		this._currentSorting = s;
		for (int i = 0; i < this.SpriteRenderers.Length; i++)
		{
			SpriteRenderer spriteRenderer = this.SpriteRenderers[i];
			spriteRenderer.set_sortingLayerID(this._currentSorting.LayerId);
			spriteRenderer.set_sortingOrder(this._currentSorting.Order + i);
		}
	}

	public override Sorting GetSorting()
	{
		return this._currentSorting;
	}

	public override bool CanBeTapped()
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

	public override bool TryExplode()
	{
		if (this.LatestExplode == (long)Time.get_frameCount() || this._isDestroyed)
		{
			return false;
		}
		this.LatestExplode = (long)Time.get_frameCount();
		this._canGenerateScore = false;
		this._isDestroyed = true;
		this.LastPosition = base.get_transform().get_position();
		if (this.CanRaiseScore())
		{
			ScoreManager.RaiseScore(this.GetScore(), base.get_transform().get_position(), MatchType.None);
		}
		base.StartCoroutine(this.ExplodeNextFrame());
		return false;
	}

	[DebuggerHidden]
	private IEnumerator ExplodeNextFrame()
	{
		SoapItem.<ExplodeNextFrame>c__Iterator0 <ExplodeNextFrame>c__Iterator = new SoapItem.<ExplodeNextFrame>c__Iterator0();
		<ExplodeNextFrame>c__Iterator.$this = this;
		return <ExplodeNextFrame>c__Iterator;
	}

	private void PlayBubbleAnimation(List<Cell> cells)
	{
		int count = cells.Count;
		for (int i = 0; i < count; i++)
		{
			Cell cell = cells[i];
			cell.AddBubble(true);
			GameObject gameObject = ItemResourcesManager.Instance.GetResources(this.GetItemType()).Animators[0].Spawn();
			gameObject.get_transform().set_position(base.get_transform().get_position());
			SoapBubbleAnimation component = gameObject.GetComponent<SoapBubbleAnimation>();
			component.Prepare(cell);
			this.CurrentLevel.IncreaseGoal(ItemType.Bubble);
		}
		this.CurrentLevel.DecreaseItemCountOnGrid(this.GetItemType());
		this.CurrentLevel.DecreaseGoal(this.GetItemType(), false);
		if (count != 0)
		{
			AudioManager.PlayAudioPropsLater(0.55f, ItemResourcesManager.Instance.GetResources(this.GetItemType()).AudioClips[0], PlayMode.Frame, null, 1f);
		}
		this.StartExplode();
	}

	protected override void PlayOnExplodeStartedAnimation()
	{
		if (ItemResourcesManager.Instance != null)
		{
			ParticlePool.Instance.PlayParticle(ItemResourcesManager.Instance.GetResources(this.GetItemType()).Particles[0], this.LastPosition, true);
			AudioManager.PlayAudioProps(ItemResourcesManager.Instance.GetResources(this.GetItemType()).AudioClips[1], PlayMode.Frame, null, 1f);
		}
	}

	public override int GetScore()
	{
		return 500;
	}

	public override bool CanCastShadow()
	{
		return true;
	}
}
