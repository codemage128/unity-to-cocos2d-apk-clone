#ifndef __ENGINE_UFOCONTROLLER_H__
#define __ENGINE_UFOCONTROLLER_H__

#include <vector>

class UfoItem;

class UfoController
{
private:
	static UfoController* _instance;
	std::vector<UfoItem*> _ufoItemList;

public:
	static UfoController* get_Instance() {
		if (UfoController::_instance == nullptr) {
//			GameObject gameObject = new GameObject();
//			gameObject.AddComponent<UfoController>();
//			UfoController::_instance = gameObject.GetComponent<UfoController>();
		}
		return UfoController::_instance;
	}

	void RegisterUfoItem(UfoItem* ufoItem) { this->_ufoItemList.push_back(ufoItem); }

private:
	void Update();
	
public:
	void ResetSelf() { this->_ufoItemList.clear(); }
};

#endif // __ENGINE_UFOCONTROLLER_H__
