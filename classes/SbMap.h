#ifndef __DIALOGS_H__
#define __DIALOGS_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Ext/Popup.h"
#include "global/Localization.h"
#include "global/GameManager.h"

USING_NS_CC;
using namespace cocos2d::ui;


class MapDialog : public Popup
{
public:
	MapDialog();
	CREATE_FUNC(MapDialog);
	virtual bool init();

	virtual void onBeforeShow() override;
	virtual FiniteTimeAction* getDefaultShowAction() override;
	virtual FiniteTimeAction* getDefaultCloseAction() override;
};

#endif //__DIALOGS_H__