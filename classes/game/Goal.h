#ifndef __ENGINE_GOAL_H__
#define __ENGINE_GOAL_H__

#include <string>

enum class ItemType;

class Goal {
public:
	int Count = 0;
	int Order = 0;
	int TotalCount = 0;
	int InstantCount = 0;
	ItemType Type = (ItemType)0;

public:
	Goal(std::string goalName, int count);
	Goal(ItemType goalType, int count);
	std::string ToString();
	void Decrease(int amount);
	void DecreaseInstant(int amount);
	void Increase(int amount);
};

#endif //__ENGINE_GOAL_H__