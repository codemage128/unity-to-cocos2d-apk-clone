#ifndef __SCENE_SPLASH_H_
#define __SCENE_SPLASH_H_

#include "cocos2d.h"
#include <editor-support/cocostudio/CocoStudio.h>

class ScnSplash: public cocos2d::Scene {
public:
	static cocos2d::Scene* createScene();

private:
    virtual bool init() override;
    CREATE_FUNC(ScnSplash);

};

#endif // __SCENE_SPLASH_H_
