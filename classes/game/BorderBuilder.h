#ifndef __ENGINE_BORDERBUILDER_H__
#define __ENGINE_BORDERBUILDER_H__

#include <vector>
#include "cocos2d.h"

class Grid;
class Cell;

class BorderBuilder {
private:
	Grid* _grid = nullptr;

public:
	std::vector<cocos2d::Sprite*> BorderImages;

	BorderBuilder(Grid* grid, std::vector<cocos2d::Sprite*>& borderImages);

	void Build();

private:
	static void RemoveUnusedCells(Cell* cell);
	static void FillBorderSpace(Cell* cell, int localPos, cocos2d::Sprite* sprite);
	cocos2d::Sprite* SelectLineGap(bool top, bool bottom);
	cocos2d::Sprite* SelectColumnGap(bool left, bool right);
	cocos2d::Sprite* SelectCorner(bool rightTop, bool rightBottom, bool leftTop, bool leftBottom);
};

#endif //__ENGINE_BORDERBUILDER_H__