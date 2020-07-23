using System;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items
{
	public interface ICanExplodeAtLeast2
	{
		void CheckIfExtraExplodeNeeded();

		void MarkShouldExplodeAtLeast2();
	}
}
