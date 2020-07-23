#include "DiscoBallAndBombItem.h"
#include "../Grid.h"
#include "../Cell.h"
#include "../Level.h"
#include "../LevelBuilder.h"

#include "cocos2d.h"
USING_NS_CC;

SpecialItem* DiscoBallAndBombItem::CreateSpecialItem(Grid* theGrid, Cell* c) {
	SpecialItem* specialItem = dynamic_cast<SpecialItem*>(theGrid->CurrentLevel->CurrentLevelBuilder->CreateItem(new ItemDescription(ItemType::Bomb, TiledEditorId::None, nullptr)));
	specialItem->CurrentSpriteRenderer->setPosition(c->GetFrozenPosition());
	return specialItem;
}

void DiscoBallAndBombItem::RemoveSelf() {
	this->OnBeforeRemove();
	//	Object.Destroy(base.get_gameObject());
	this->CurrentSpriteRenderer->removeFromParentAndCleanup(true);
	//delete this;
}

/*IEnumerator*/void DiscoBallAndBombItem::PlayDiscoExplodes(cocos2d::Vector<cocos2d::FiniteTimeAction*>& seq) {
//case 0:
//	this.$locvar0 = this.$this.ChangedItems.GetEnumerator();
//	num = 0xfffffffd;
//	break;
//
//case 1:
//case 2:
//	break;
//
//default:
//	goto Label_0132;
//}
//try {
//	switch(num) {
//	case 1:
//		goto Label_00CA;
//	}
//	while(this.$locvar0.MoveNext()) {
//		this.<c>__1 = this.$locvar0.Current;
//		if((this.<c>__1 == null) || this.<c>__1.ReCycled) {
//			continue;
//		}
//		this.<w>__2 = this.<c>__1.StartAutoExplode(null);
//	Label_00CA:
//		while(this.<w>__2.MoveNext()) {
//			this.$current = this.<w>__2.Current;
//			if(!this.$disposing) {
//				this.$PC = 1;
//			}
//			flag = true;
//			goto Label_0134;
//		}
//		this.$current = new WaitForSeconds(0.1f);
//		if(!this.$disposing) {
//			this.$PC = 2;
//		}
//		flag = true;
//		goto Label_0134;
//	}
//}
//finally
//{
//	if(!flag) {
//	}
//	this.$locvar0.Dispose();
//}
//this.$PC = -1;
//Label_0132:
//return false;
//Label_0134:
//return true;
	for(int i = 0; i < (int)ChangedItems.size(); i++)
		seq.pushBack(Sequence::createWithTwoActions(
		DelayTime::create(0.2f),
		CallFunc::create([this, i]() {
		if(!ChangedItems[i]->isExploded)
			ChangedItems[i]->StartAutoExplode(0.0f);
	})));
}
