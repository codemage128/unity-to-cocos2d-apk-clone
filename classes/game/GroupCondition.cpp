#include "GroupCondition.h"
#include "Level.h"
#include "Item.h"
#include "Extension.h"

//////////////////////GroupCondition///////////////////////////////////////////////
GroupCondition::GroupCondition(std::string condition) {
	std::regex _regex("(<=|>=|!=|=|>|<)\\s*([0-9]+)");
	std::smatch match;
	std::regex_match(condition, match, _regex);
	this->Operand = match[1];
	//*TODO*/this->Target = my_stoi(match[2]);
}

bool GroupCondition::IsMet(Level* level) {
	int num = this->ReadConditionValue(level);
	std::string operand = this->Operand;
	if(!operand.empty()) {
		if(operand == "=") { return num == this->Target; }
		if(operand == ">") { return num > this->Target; }
		if(operand == "<") { return num < this->Target; }
		if(operand == ">=") { return num >= this->Target; }
		if(operand == "<=") { return num <= this->Target; }
		if(operand == "!=") { return num != this->Target; }
	}
	//throw new std::exception(("[Group Condition] Unknown operand type:" + this->Operand).c_str());
	return false;
}

//////////////////////CountOfCondition///////////////////////////////////////////////
CountOfCondition::CountOfCondition(ItemType itemType, std::string condition): GroupCondition(condition) {
	this->_itemType = (int)itemType;
}
int CountOfCondition::ReadConditionValue(Level* level) {
	return level->ItemCounts[this->_itemType];
}