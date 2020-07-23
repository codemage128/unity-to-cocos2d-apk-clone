#ifndef __ENGINE_COLLECTORITEM_H__
#define __ENGINE_COLLECTORITEM_H__

#include "../Item.h"
#include "../Match.h"

class CollectorItem : public Item
{
public:
	int CollectorId = 0;

public:
	MatchType matchType = MatchType::None;
	int Order = 0;

public:
	virtual void StartCollectingItem() = 0;
	virtual void OnItemCollectCompleted() = 0;
	virtual bool IsAvailable() = 0;
};

#endif //__ENGINE_COLLECTORITEM_H__

