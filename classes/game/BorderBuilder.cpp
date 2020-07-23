#include "BorderBuilder.h"
#include "Grid.h"
#include "Cell.h"
#include "ImageLibrary.h"

BorderBuilder::BorderBuilder(Grid* grid, std::vector<cocos2d::Sprite*>& borderImages) {
	this->BorderImages = borderImages;
	this->_grid = grid;
}

void BorderBuilder::Build() {
	int width = this->_grid->Width;
	int height = this->_grid->Height;
	for(int i = 0; i < width; i++) {
		for(int j = 0; j < height; j++) {
			bool exists = this->_grid->cell(i, j)->Exists;
			bool bottom = j - 1 >= 0 && this->_grid->cell(i, j - 1)->Exists; // bottom exists
			bool left = i - 1 >= 0 && this->_grid->cell(i - 1, j)->Exists; // left exists
			bool leftBottom = i - 1 >= 0 && j - 1 >= 0 && this->_grid->cell(i - 1, j - 1)->Exists; // left bottom exists
			Cell* cell = this->_grid->cell(i, j);
			if(exists)
				BorderBuilder::FillBorderSpace(cell, 5, this->BorderImages[4]);
			
			BorderBuilder::FillBorderSpace(cell, 2, this->SelectLineGap(exists, bottom));
			BorderBuilder::FillBorderSpace(cell, 4, this->SelectColumnGap(left, exists));
			BorderBuilder::FillBorderSpace(cell, 1, this->SelectCorner(exists, bottom, left, leftBottom));
			// for right edge cell
			if(i == width - 1) {
				// for right top corner
				if(j == height - 1 && exists) 
					BorderBuilder::FillBorderSpace(cell, 9, this->BorderImages[8]);
				
				bool right = i + 1 < width && this->_grid->cell(i + 1, j)->Exists;
				bool rightBottom = i + 1 < width && j - 1 >= 0 && this->_grid->cell(i + 1, j - 1)->Exists;
				BorderBuilder::FillBorderSpace(cell, 6, this->SelectColumnGap(exists, right));
				BorderBuilder::FillBorderSpace(cell, 3, this->SelectCorner(right, rightBottom, exists, bottom));
			}

			if(j != height - 1) {
				BorderBuilder::RemoveUnusedCells(cell);
			}
			// for top edge cell
			else {
				bool top = j + 1 < height && this->_grid->cell(i, j + 1)->Exists;
				bool leftTop = j + 1 < height && i - 1 >= 0 && this->_grid->cell(i - 1, j + 1)->Exists;
				BorderBuilder::FillBorderSpace(cell, 8, this->SelectLineGap(top, exists));
				BorderBuilder::FillBorderSpace(cell, 7, this->SelectCorner(top, exists, leftTop, left));
				BorderBuilder::RemoveUnusedCells(cell);
			}
		}
	}
}

void BorderBuilder::RemoveUnusedCells(Cell* cell) {
	for(int i = 0; i < (int)cell->Borders.size(); i++) {
		cocos2d::Sprite*& spriteRenderer = cell->Borders[i];
		if(!(spriteRenderer == nullptr)) {
			if(!spriteRenderer->isVisible()) {
				spriteRenderer->removeFromParentAndCleanup(true);
				spriteRenderer = nullptr;
			}
		}
	}
}

void BorderBuilder::FillBorderSpace(Cell* cell, int localPos, cocos2d::Sprite* sprite) {
	if(sprite == nullptr) 
		return;
	
	cell->Borders[localPos]->setVisible(true);
	ImageLibrary::CopySprite(cell->Borders[localPos], sprite);
}

cocos2d::Sprite* BorderBuilder::SelectLineGap(bool top, bool bottom) {
	if(top && bottom)
		return this->BorderImages[4];	
	if(bottom) 
		return this->BorderImages[7];
	
	return (!top) ? nullptr : this->BorderImages[1];
}

cocos2d::Sprite* BorderBuilder::SelectColumnGap(bool left, bool right) {
	if(left && right)
		return this->BorderImages[4];	
	if(left)
		return this->BorderImages[5];
	
	return (!right) ? nullptr : this->BorderImages[3];
}

cocos2d::Sprite* BorderBuilder::SelectCorner(bool rightTop, bool rightBottom, bool leftTop, bool leftBottom) {
	if(rightTop && rightBottom && leftTop && leftBottom)
		return this->BorderImages[4];
	if(rightTop && rightBottom && leftTop)
		return this->BorderImages[11];
	if(rightTop && rightBottom && leftBottom)
		return this->BorderImages[13];
	if(rightTop && rightBottom)
		return this->BorderImages[3];
	if(rightTop && leftTop && leftBottom)
		return this->BorderImages[12];
	if(rightTop && leftTop)
		return this->BorderImages[1];
	if(rightTop && leftBottom)
		return this->BorderImages[10];
	if(rightTop)
		return this->BorderImages[0];
	if(rightBottom && leftTop && leftBottom)
		return this->BorderImages[14];
	if(rightBottom && leftTop)
		return this->BorderImages[9];
	if(rightBottom && leftBottom)
		return this->BorderImages[7];
	if(rightBottom)
		return this->BorderImages[6];
	if(leftTop && leftBottom)
		return this->BorderImages[5];
	if(leftTop)
		return this->BorderImages[2];

	return (!leftBottom) ? nullptr : this->BorderImages[8];
}
