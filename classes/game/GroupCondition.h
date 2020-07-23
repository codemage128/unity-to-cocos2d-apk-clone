#ifndef __ENGINE_GROUPCONDIITON_H__
#define __ENGINE_GROUPCONDIITON_H__

#include <string>
#include <regex>
#include <stdlib.h>

class Level;
enum class ItemType;

class GroupCondition {
protected:
	GroupCondition(std::string condition);
public:
	std::string Operand;
	int Target = 0;

	bool IsMet(Level* level);
	virtual int ReadConditionValue(Level* level) = 0;
};


class CountOfCondition: public GroupCondition {
private:
	int _itemType = 0;

public:
	CountOfCondition(ItemType itemType, std::string condition);
	int ReadConditionValue(Level* level) override;
};

#endif //__ENGINE_GROUPCONDIITON_H__