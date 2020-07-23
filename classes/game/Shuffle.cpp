#include "Shuffle.h"
#include "Match.h"
#include "Grid.h"
#include "Cell.h"
#include "Item.h"
#include "Mathf.h"
#include "Extension.h"

#include "cocos2d.h"

ShuffleManager* ShuffleManager::_instance = nullptr;

bool ShuffleManager::Shuffle(Grid* grid) {
	//LogManager.Debug(LogTags.ShuffleManager, "Shuffling Board", new object[0]);
	std::map<MatchType, int> typeCounts;
	std::vector<Cell*> cellList;
	std::vector<ShuffleItem*> shuffleList;
	for(Cell* onecell : grid->WalkOnExistings()) {
		if(onecell->get_HasItem() && onecell->get_CurrentItem()->CanShuffle()) {
			cellList.push_back(onecell);
			shuffleList.push_back(new ShuffleItem(onecell->get_CurrentItem(), onecell));
			Item* cellitem = onecell->get_CurrentItem();
			MatchType matchType = cellitem->GetMatchType();
			if(matchType != MatchType::None) {
				if(typeCounts.find(matchType) == typeCounts.end())
					typeCounts[matchType] = 1;
				else
					typeCounts[matchType]++;
			}
		}
	}
	MatchType onemultipletype = MatchType::None;
	std::vector<MatchType> multipleTypes;
	for(std::pair<MatchType, int> onetype : typeCounts) {
		if(onetype.second >= 2) {
			multipleTypes.push_back(onetype.first);
		}
	}
	int count = (int)multipleTypes.size();
	if(count <= 0) {
		//LogManager.Debug(LogTags.ShuffleManager, "There are not enough items of the same ItemType to create a match", new object[0]);
		return false;
	}
	onemultipletype = multipleTypes[Mathf::Random::Range(0, count)];
	ListExt_Shuffle<Cell*>(cellList);
	std::vector<Cell*> list4;
	bool flag = false;
	for(int i = 0; i < (int)cellList.size() && !flag; i++) {
		Cell* cell = cellList[i];
		std::vector<Cell*> cachedNeigbours = cell->GetCachedNeigbours(false);
		if(cachedNeigbours.size() >= 1) {
			list4.clear();
			list4.push_back(cell);
			for(int i2 = 0; i2 < (int)cachedNeigbours.size(); i2++) {
				Cell* cell2 = cachedNeigbours[i2];
				if(cell2->get_HasItem() && cell2->get_CurrentItem()->CanShuffle()) {
					list4.push_back(cell2);
					flag = true;
					break;
				}
			}
		}
	}
	if(!flag) {
		//LogManager.Debug(LogTags.ShuffleManager, "There is no place to put the shuffled items that creates a match.", new object[0]);
		return false;
	}
	for(Cell* current3 : list4) {
		for(int i = shuffleList.size() - 1; i >= 0; i--) {
			if(shuffleList[i]->CurrentItem->GetMatchType() == onemultipletype) {
				shuffleList[i]->CurrentItem->DoShuffleAnimation(current3, shuffleList[i]->OldReference);
				shuffleList.erase(shuffleList.begin() + i);
				break;
			}
		}
	}
	cellList.erase(std::find(cellList.begin(), cellList.end(), list4[0]));
	cellList.erase(std::find(cellList.begin(), cellList.end(), list4[1]));
	ListExt_Shuffle<ShuffleItem*>(shuffleList);
	for(int i = 0; i < (int)shuffleList.size(); i++) {
		if(shuffleList[i]->OldReference == cellList[i]) {
			int num3 = (i <= 0) ? 1 : -1;
			Cell* value = cellList[i];
			cellList[i] = cellList[i + num3];
			cellList[i + num3] = value;
		}
	}
	for(int i = 0; i < (int)shuffleList.size(); i++) {
		shuffleList[i]->CurrentItem->DoShuffleAnimation(cellList[i], shuffleList[i]->OldReference);
	}
	//Sequence sequence = DOTween.Sequence();
	//TweenSettingsExtensions.InsertCallback(sequence, 0.8f, delegate
	//{
	//	HintManager.Instance.EnableHints();
	//});
	//LogManager.Debug(LogTags.ShuffleManager, "Shuffle completed.", new object[0]);
	return true;
}