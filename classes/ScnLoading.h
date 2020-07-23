#ifndef __SCENE_LOADING_H_
#define __SCENE_LOADING_H_

#include "cocos2d.h"
#include <editor-support/cocostudio/CocoStudio.h>

class ScnLoading : public cocos2d::Layer {
public:
	enum class Type { App, Level, Lobby };
    static cocos2d::Scene* createScene(Type type);

private:
    virtual bool init(Type type);  
	static ScnLoading* create(Type type);

};

#endif // __SCENE_LOADING_H_
