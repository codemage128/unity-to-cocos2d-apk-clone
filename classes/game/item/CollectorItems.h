#ifndef __ENGINE_COLLECTORITEMS_H__
#define __ENGINE_COLLECTORITEMS_H__

#include "CollectorItem.h"
#include "CollectorItemsController.h"

template<class T>
class CollectorItems
{
private:
	std::map<MatchType, std::map<int, T>> _items;
	std::list<int> _launchQueue;
	int _nextExplodeId = -1;
	int _readyToExplodeCount = 0;

public:
	int get_NextExplodeId() { return this->_nextExplodeId; }
	void Reset() {
		//		if (this->_items != nullptr) {
		this->_items.clear();
		//		}
		this->_launchQueue.clear();
		this->_nextExplodeId = -1;
		this->_readyToExplodeCount = 0;
	}

	int Register(T item) {
		//		if (this->_items == nullptr) {
		this->_items = std::map < MatchType, std::map<int, T> >(); //new Dictionary<MatchType, SortedList<int, T>>();
		//		}
		if (this->_items.find(item->matchType) == this->_items.end()) {
			this->_items.insert(std::make_pair(item->matchType, std::map<int, T>()));
		}
		this->_items[item->matchType].insert(std::make_pair(item->Order, item));
		return CollectorItemsController::get_Instance()->get_CollectorIdCounter();
	}

	void UnRegister(T item) {
		if (/*this->_items == nullptr || */this->_items.find(item->matchType) == this->_items.end()) {
			return;
		}
		if (this->_items[item->matchType].find(item->Order) != this->_items[item->matchType].end()) {
			this->_items[item->matchType].erase(this->_items[item->matchType].find(item->Order));
		}
		if (this->_items[item->matchType].size() == 0) {
			this->_items.erase(item->matchType);
		}
	}

	T GetActiveItem(MatchType matchType) {
		if (/*this->_items == nullptr || */this->_items.find(matchType) == this->_items.end() ||
			/*this->_items[matchType] == nullptr || */this->_items[matchType].size() == 0)	{
			return (T)(nullptr);
		}
		T t = this->_items[matchType].Values[0];
		bool flag = this->_items[matchType].Values.Count > 1;
		if (!t.IsAvailable() && flag)
		{
			this->_items[t.MatchType].Remove(t.Order);
			if (this->_items[matchType].Values.Count == 0)
			{
				return (T)((object)nullptr);
			}
		}
		return this->_items[matchType].Values[0];
	}

	bool CanBeCollected(MatchType matchType) {
		return /*this->_items != nullptr && */ this->_items.find(matchType) != this->_items.end()  && !this->_items[matchType].empty();
	}

	void AddToQueue(int blasterId) {
		if (std::find(this->_launchQueue.begin(), this->_launchQueue.end(), blasterId) != this->_launchQueue.end()) {
			return;
		}
		this->_launchQueue.push_back(blasterId); //Enqueue
		this->_nextExplodeId = *(this->_launchQueue.begin());//Peek
		this->_readyToExplodeCount++;
	}

	int WaitingToLaunchCount() {
		return this->_readyToExplodeCount;
	}

	void RemoveNextLaunchItem()  {
		if (this->_launchQueue.size() == 0) {
			return;
		}
		this->_launchQueue.pop_front(); // Dequeue
		if (this->_launchQueue.Count > 0) {
			this->_nextExplodeId = *(this->_launchQueue.begin());//Peek
		}
		this->_readyToExplodeCount--;
	}
};

#endif // __ENGINE_COLLECTORITEMS_H__