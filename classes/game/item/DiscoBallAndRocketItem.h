#ifndef __ENGINE_DISCOBALLANDROCKETITEM_H__
#define __ENGINE_DISCOBALLANDROCKETITEM_H__

#include "../SpecialItem.h"

class DiscoBallAndRocketItem : public DiscoBallItem, public IComboItem
{
public:
	DiscoBallAndRocketItem();

protected:
	MatchGroup* ComboMatchGroup=nullptr;
	int ComboMergeScores=0;
	std::vector<SpecialItem*> ChangedItems;
	std::vector<SpecialItem*> CreatedItems;

private:
	bool _destoyed=false;
//	static Comparison<SpecialItem> <>f__mg$cache0;
	Item* oldItem = nullptr;
	SpecialItem* createdSpecialItem = nullptr;

public:
	void SetComboGroup(MatchGroup* mgroup) override { this->ComboMatchGroup = mgroup; }
	bool CanBeCapturedByJelly() override { return false; }
	void AddScore(int v) override { this->ComboMergeScores += v; }
	ItemType GetItemType() override { return ItemType::DiscoBallAndRocket; }
	bool CanRaiseScore() override { return true; }
	int GetScore() override { return 1250 + this->ComboMergeScores; }
	void RemoveSelf() override;
	bool ShouldRejectFallInside() override { return false; }
	bool ShouldBlockFalls() override { return false; }
	void OnDestroy() { this->_destoyed = true; }

protected:
	/*IEnumerator*/void OnRayReached(Cell* c, Item* i, cocos2d::FiniteTimeAction* tweener, cocos2d::ParticleSystemQuad* p) override;
	virtual SpecialItem* CreateSpecialItem(Grid* theGrid, Cell* c);
	void DoDie() override;
	/*IEnumerator*/void DoDiscoExpldoes(std::vector<Cell*>& explodeCells) override;
	virtual /*IEnumerator*/void PlayDiscoExplodes(cocos2d::Vector<cocos2d::FiniteTimeAction*>& seq);
	virtual void _onRaysEnded() override;
	
private:
	static int Sorter(Item* a, Item* b);
};

#endif //__ENGINE_DISCOBALLANDROCKETITEM_H__