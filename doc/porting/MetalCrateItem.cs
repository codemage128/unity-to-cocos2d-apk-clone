using Assets.Scripts.GamePlayScene;
using Assets.Scripts.GamePlayScene.Mechanics;
using Assets.Scripts.GamePlayScene.Mechanics.Items;
using Assets.Scripts.Utils;
using System;

namespace GamePlayScene.Mechanics.Items
{
	public class MetalCrateItem : SpriteBasedItem
	{
		public override ItemType GetItemType()
		{
			return ItemType.MetalCrate;
		}

		public override int GetScore()
		{
			return 1000;
		}

		public override bool CanCastShadow()
		{
			return false;
		}

		public override bool CanShadowDrop()
		{
			return true;
		}

		public override bool CanFall()
		{
			return false;
		}

		public override void PlayExplodeAudio()
		{
			AudioManager.Play(AudioTag.MetalCrate, PlayMode.Frame, null, 1f);
		}

		protected override void PlayOnExplodeStartedAnimation()
		{
			if (ParticlePool.Instance != null)
			{
				ParticlePool.Instance.PlayParticle(ParticlePool.Instance.MetalCrateParticle, base.get_transform().get_position(), true);
			}
		}
	}
}
