#ifndef __ENGINE_GROUP_H__
#define __ENGINE_GROUP_H__

#include <vector>
#include <string>

enum class GroupId {
	None,
	All,
	Group1,
	Group2,
	Group3,
	Group4,
	Group5,
	Group6,
	Group7,
	Group8,
	Group9,
	Group10,
	Group11
};

class GroupIdComparer {
public:
	bool Equals(GroupId x, GroupId y) {
		return x == y;
	}

	int GetHashCode(GroupId obj) {
		return (int)obj;
	}
};

#endif // __ENGINE_GROUP_H__