using Assets.Scripts.CasualTools.Common.Pooling;
using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.GamePlayScene.Mechanics.Items.Features;
using Assets.Scripts.GamePlayScene.Mechanics.Items.SpecialItems;
using Assets.Scripts.Utils;
using Medvedya.SpriteDeformerTools;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class GiantPinataItem : Item
	{
		private Direction _lastDirection;

		public Animator GiantPinataAnimator;

		public GiantPinateFakeItem BottomRight;

		public GiantPinateFakeItem TopLeft;

		public GiantPinateFakeItem TopRight;

		public SpriteRenderer BaseImage;

		public MeshRenderer DonkeyMesh;

		public MeshRenderer RopeMesh;

		public ParticleSystem ToDownParticle;

		public ParticleSystem ToLeftParticle;

		public ParticleSystem ToRightParticle;

		public ParticleSystem ToUpParticle;

		public ParticlePlayer FinalParticle;

		public SpriteDeformerAnimation DonkeyImage;

		public Transform DonkeyImagePosition;

		public SpriteDeformerAnimation RopeImage;

		private int _explodeNo;

		private bool _exploded;

		private readonly Dictionary<SpecialItem, float> _explodedBySpecialItemTime = new Dictionary<SpecialItem, float>();

		private float explodedByNonSpecialItem;

		private bool justExploded;

		private bool _inExplode;

		private Sorting _sorting;

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

		public void SetLastDirection(Direction direction)
		{
			this._lastDirection = direction;
		}

		public override Sorting GetSorting()
		{
			return this._sorting;
		}

		public override void ChangeSorting(Sorting s)
		{
			this._sorting = s;
			this.DonkeyMesh.set_sortingLayerID(s.LayerId);
			this.DonkeyMesh.set_sortingOrder(s.Order + 270);
			this.RopeMesh.set_sortingLayerID(s.LayerId);
			this.RopeMesh.set_sortingOrder(s.Order);
			this.BaseImage.set_sortingLayerID(s.LayerId);
			this.BaseImage.set_sortingOrder(s.Order + 1);
		}

		public override int GetScore()
		{
			return 5000;
		}

		public override void OnFallEnded()
		{
			base.OnFallEnded();
			Cell currentCell = this.BottomRight.CurrentCell;
			if (currentCell != null)
			{
				CanCastShadowComponent.CastShadowIfPossible(currentCell);
			}
		}

		public override bool CanFall()
		{
			return false;
		}

		public override ItemType GetItemType()
		{
			return ItemType.GiantPinata;
		}

		public override void InformToBeExplodedBySpecialItem(SpecialItem specialItem, Direction comingFrom)
		{
			base.InformToBeExplodedBySpecialItem(specialItem, comingFrom);
			this._lastDirection = comingFrom;
			if (specialItem == null)
			{
				this.justExploded = (Time.get_time() < this.explodedByNonSpecialItem + 0.2f);
				this.explodedByNonSpecialItem = Time.get_time();
				return;
			}
			float num;
			if (this._explodedBySpecialItemTime.TryGetValue(specialItem, out num))
			{
				this.justExploded = (Time.get_time() < num + 1f);
			}
			else
			{
				this.justExploded = false;
			}
			this._explodedBySpecialItemTime[specialItem] = Time.get_time();
		}

		public override bool TryExplode()
		{
			if (this.justExploded || this.LatestExplode == (long)Time.get_frameCount())
			{
				return false;
			}
			this.LatestExplode = (long)Time.get_frameCount();
			if (this._exploded)
			{
				return false;
			}
			this._explodeNo++;
			int num = this.GiantPinataAnimator.GetInteger("DIRECTION");
			if (num == 0 || (this.GiantPinataAnimator.GetInteger("STATE") == 1 && this._explodeNo == 2))
			{
				this.GiantPinataAnimator.SetInteger("STATE", this._explodeNo);
				switch (this._lastDirection)
				{
				case Direction.Up:
					this.EnableAndPlay(this.ToDownParticle);
					num = 3;
					goto IL_104;
				case Direction.Down:
					this.EnableAndPlay(this.ToUpParticle);
					num = 1;
					goto IL_104;
				case Direction.Left:
					this.EnableAndPlay(this.ToRightParticle);
					num = 2;
					goto IL_104;
				}
				this.EnableAndPlay(this.ToLeftParticle);
				num = 4;
				IL_104:
				this.GiantPinataAnimator.SetInteger("DIRECTION", num);
			}
			if (this._explodeNo < 3)
			{
				AudioManager.Play(AudioTag.ItemGiantPinata_1_2, PlayMode.Frame, null, 1f);
			}
			base.StartCoroutine(this.ChangeImage());
			if (this._explodeNo != 3)
			{
				return false;
			}
			this._exploded = true;
			this.FinalParticle.get_gameObject().SetActive(true);
			this.FinalParticle.PlayWithoutParent();
			return true;
		}

		private void EnableAndPlay(ParticleSystem target)
		{
			this.UpdateParticle(target, this.ToUpParticle);
			this.UpdateParticle(target, this.ToDownParticle);
			this.UpdateParticle(target, this.ToLeftParticle);
			this.UpdateParticle(target, this.ToRightParticle);
		}

		private void UpdateParticle(Component target, ParticleSystem target2)
		{
			GameObject gameObject = target2.get_gameObject();
			if (target == target2)
			{
				gameObject.SetActive(true);
				target2.Play();
			}
			else if (gameObject.get_activeSelf())
			{
				gameObject.SetActive(false);
			}
		}

		public override CollectAnimation GetCollectItem()
		{
			CollectAnimation component = this.CurrentLevel.CurrentLevelBuilder.GenericCollectItem.Spawn(this.DonkeyImagePosition.get_position()).GetComponent<CollectAnimation>();
			Sorting sorting = this._sorting;
			sorting.Order += 270;
			component.Prepare(this.CurrentLevel, this.GetItemType(), sorting, null, this.CurrentCell);
			return component;
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.ItemGiantPinata_3, PlayMode.Frame, null, 1f);
		}

		[DebuggerHidden]
		private IEnumerator ChangeImage()
		{
			GiantPinataItem.<ChangeImage>c__Iterator0 <ChangeImage>c__Iterator = new GiantPinataItem.<ChangeImage>c__Iterator0();
			<ChangeImage>c__Iterator.$this = this;
			return <ChangeImage>c__Iterator;
		}

		public override void StartExplode()
		{
			if (this._inExplode)
			{
				return;
			}
			this._inExplode = true;
			base.StartExplode();
		}
	}
}
