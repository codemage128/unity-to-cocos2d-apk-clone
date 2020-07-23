using System;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items.ComboItems
{
	public interface IComboItem
	{
		void AddScore(int v);

		void SetComboGroup(MatchGroup mgroup);
	}
}
