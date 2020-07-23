using Assets.Scripts.GamePlayScene.Mechanics.Items.SpecialItems;
using System;
using System.Collections;
using System.Diagnostics;
using UnityEngine;

namespace Assets.Scripts.GamePlayScene.Mechanics.Items.ComboItems
{
	public class DiscoBallAndBombItem : DiscoBallAndRocketItem, IComboItem
	{
		public override ItemType GetItemType()
		{
			return ItemType.DiscoBallAndBomb;
		}

		public override bool CanBeCapturedByJelly()
		{
			return false;
		}

		protected override SpecialItem CreateSpecialItem(Grid theGrid, Cell c)
		{
			SpecialItem specialItem = theGrid.CurrentLevel.CurrentLevelBuilder.CreateItem(new ItemDescription(ItemType.Bomb, TiledEditorId.None, null)) as SpecialItem;
			specialItem.get_transform().set_position(c.GetFrozenPosition());
			return specialItem;
		}

		public override void RemoveSelf()
		{
			this.OnBeforeRemove();
			Object.Destroy(base.get_gameObject());
		}

		public override int GetScore()
		{
			return 1500 + this.ComboMergeScores;
		}

		[DebuggerHidden]
		protected override IEnumerator PlayDiscoExplodes()
		{
			DiscoBallAndBombItem.<PlayDiscoExplodes>c__Iterator0 <PlayDiscoExplodes>c__Iterator = new DiscoBallAndBombItem.<PlayDiscoExplodes>c__Iterator0();
			<PlayDiscoExplodes>c__Iterator.$this = this;
			return <PlayDiscoExplodes>c__Iterator;
		}
	}
}
