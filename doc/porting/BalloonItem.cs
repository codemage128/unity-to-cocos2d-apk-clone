using Assets.Scripts.GamePlayScene.Mechanics.Animations;
using Assets.Scripts.Utils;
using System;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public class BalloonItem : SpriteBasedItem
	{
		public override bool CanExplodeDueToExplodeInNeigbour(MatchType sourceType)
		{
			return true;
		}

		public override void BringToFront()
		{
			Sorting sorting = this.GetSorting();
			sorting.Order += 120;
			this.ChangeSorting(sorting);
		}

		public override void SendToBack()
		{
			this.OnCellChanged();
		}

		public override ItemType GetItemType()
		{
			return ItemType.Balloon;
		}

		public override int GetScore()
		{
			return 500;
		}

		public override bool CanCastShadow()
		{
			return true;
		}

		public override void ReactToUpperFall()
		{
			FallListener fallListener = base.GetFallListener();
			fallListener.EndFall(-1f);
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.ItemBalloon, PlayMode.Frame, null, 1f);
		}

		public override CollectAnimation GetCollectItem()
		{
			CollectAnimation collectItem = base.GetCollectItem();
			collectItem.get_transform().set_position(this.CurrentSpriteRenderer.get_transform().get_position());
			return collectItem;
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				BalloonParticlePlayer balloonParticlePlayer = ParticlePool.Instance.PlayParticle(ParticlePool.Instance.BalloonExplosionParticle, base.get_transform().get_position(), true) as BalloonParticlePlayer;
				balloonParticlePlayer.SetColor();
			}
		}
	}
}
