#ifndef __ENGINE_DISCOBALLANDBOMBITEM_H__
#define __ENGINE_DISCOBALLANDBOMBITEM_H__

#include "DiscoBallAndRocketItem.h"

class DiscoBallAndBombItem : public DiscoBallAndRocketItem/*, public IComboItem*/
{
public:
	ItemType GetItemType() override { return ItemType::DiscoBallAndBomb; }
	bool CanBeCapturedByJelly() override { return false; }

protected:
	SpecialItem* CreateSpecialItem(Grid* theGrid, Cell* c) override;

public:
	void RemoveSelf() override;
	int GetScore() override { return 1500 + this->ComboMergeScores; }

protected:
	/*IEnumerator*/void PlayDiscoExplodes(cocos2d::Vector<cocos2d::FiniteTimeAction*>& seq) override;
};

#endif //__ENGINE_DISCOBALLANDBOMBITEM_H__