#ifndef __ENGINE_COLLECTORITEMSCONTROLLER_H__
#define __ENGINE_COLLECTORITEMSCONTROLLER_H__

#include "CollectorItems.h"
#include "BlasterItem.h"

class WallItem;

class IReset
{
public:
	virtual void Reset() = 0;
};

class CollectorItemsController : public IReset
{
private:
	static CollectorItemsController* _instance;
	int _collectorIdCounter = 0;

	CollectorItems<BlasterItem*> _blasters;
	CollectorItems<WallItem*> _walls;

public:
	int get_CollectorIdCounter() { return this->_collectorIdCounter++; }
	static CollectorItemsController* get_Instance() {
		if (CollectorItemsController::_instance == nullptr) {
				CollectorItemsController::_instance = new CollectorItemsController();
		}
		return CollectorItemsController::_instance;
	}

public:
	CollectorItems<BlasterItem*>& GetBlasters() {
//		if (this->_blasters == nullptr) {
//			this->_blasters = CollectorItems<BlasterItem*>();
//		}
		return this->_blasters;
	}

	CollectorItems<WallItem*>& GetWalls() {
//		if (this->_walls == nullptr) {
//			this->_walls = CollectorItems<WallItem*>();
//		}
		return this->_walls;
	}

	bool CanBeCollected(MatchType matchType) {
		return this->GetBlasters().CanBeCollected(matchType) || this->GetWalls().CanBeCollected(matchType);
	}

	void Reset() override {
		this->_collectorIdCounter = 0;
//		if (this->_blasters != null) {
			this->_blasters.Reset();
//		}
//		if (this->_walls != null) {
			this->_walls.Reset();
//		}
	}

	static void ResetSelf() {
		if (CollectorItemsController::_instance != nullptr) {
//			CollectorItemsController::_instance->_blasters = nullptr;
//			CollectorItemsController::_instance->_walls = nullptr;
		}
		CollectorItemsController::_instance = nullptr;
	}
};

#endif // __ENGINE_COLLECTORITEMSCONTROLLER_H__
