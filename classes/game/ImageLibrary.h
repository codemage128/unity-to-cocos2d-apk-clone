#ifndef __ENGINE_IMAGELIBRARY_H_
#define __ENGINE_IMAGELIBRARY_H_

#include <vector>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

#define IMGLIB ImageLibrary::getInstance()

enum class MatchType;
enum class ItemType;

class ImageLibrary {
private:
	static ImageLibrary* _instance;
public:
	static ImageLibrary* getInstance() { if(_instance == nullptr) _instance = new ImageLibrary(); return _instance; }
	static void CopySprite(cocos2d::Sprite* dest, cocos2d::Sprite* src);

	void init();
	void cleanup();
	cocos2d::Sprite* NullImage = nullptr;
	std::vector<cocos2d::Sprite*> BorderImages;
	std::vector<cocos2d::Sprite*> SolidColorSprites;
	std::vector<cocos2d::Sprite*> SolidColorHintDiscoSprites;
	std::vector<cocos2d::Sprite*> SolidColorHintBombSprites;
	std::vector<cocos2d::Sprite*> SolidColorHintRocketSprites;
	std::vector<cocos2d::Sprite*> DiscoBallSprites;
	cocos2d::Sprite* blockGlow = nullptr;
	cocos2d::Sprite* horizontalRocket = nullptr;
	cocos2d::Sprite* verticalRocket = nullptr;
	cocos2d::Sprite* topRocket = nullptr;
	cocos2d::Sprite* rightRocket = nullptr;
	cocos2d::Sprite* bottomRocket = nullptr;
	cocos2d::Sprite* leftRocket = nullptr;
	std::vector<cocos2d::Sprite*> DuckSprites;
	std::vector<cocos2d::Sprite*> GiantPinata;
	cocos2d::Sprite* GiantPinataPanel = nullptr;
	cocos2d::Sprite* GiantPinataRope = nullptr;
	cocos2d::Sprite* Bubble = nullptr;
	cocos2d::Sprite* Bomb = nullptr;
	cocos2d::Sprite* Rocket = nullptr;
	cocos2d::Sprite* Balloon = nullptr;
	cocos2d::Sprite* Pinata = nullptr;
	cocos2d::Sprite* LightBulb = nullptr;
	cocos2d::Sprite* LightBulbOff = nullptr;
	cocos2d::Sprite* Crate = nullptr;
	cocos2d::Sprite* MagicHat = nullptr;
	std::vector<cocos2d::Sprite*> CrateLayerSprites;
	std::vector<cocos2d::Sprite*> YellowCrateLayerSprites;
	std::vector<cocos2d::Sprite*> RedCrateLayerSprites;
	std::vector<cocos2d::Sprite*> BlueCrateLayerSprites;
	std::vector<cocos2d::Sprite*> GreenCrateLayerSprites;
	std::vector<cocos2d::Sprite*> PurpleCrateLayerSprites;
	std::vector<cocos2d::Sprite*> OrangeCrateLayerSprites;
	cocos2d::Sprite* ColoredCrateGoal = nullptr;
	cocos2d::Sprite* GiantDuck = nullptr;
	cocos2d::Sprite* EasterEggGoal = nullptr;
	std::vector<cocos2d::Sprite*> EasterEggSprites;
	cocos2d::Sprite* Carrot = nullptr;
	cocos2d::Sprite* Jelly = nullptr;
	cocos2d::Sprite* Can = nullptr;
	cocos2d::Sprite* CanToss = nullptr;
	cocos2d::Sprite* Frame = nullptr;
	cocos2d::Sprite* OysterGoal = nullptr;
	cocos2d::Sprite* Soda = nullptr;
	cocos2d::Sprite* SodaFrame = nullptr;
	cocos2d::Sprite* SodaBottleNeck = nullptr;
	std::vector<cocos2d::Sprite*> SodaBottleCaps;
	std::vector<cocos2d::Sprite*> SodaBottles;
	cocos2d::Sprite* WaterMelon = nullptr;
	std::vector<cocos2d::Sprite*> WaterMelonSprites;
	cocos2d::Sprite* MetalCrate = nullptr;
	cocos2d::Sprite* HoneyCube = nullptr;
	cocos2d::Sprite* HoneyPot = nullptr;
	cocos2d::Sprite* Diamond = nullptr;
	cocos2d::Sprite* BillboardGoal = nullptr;
	cocos2d::Sprite* BillboardOn = nullptr;
	cocos2d::Sprite* BillboardOff = nullptr;
	std::vector<cocos2d::Sprite*> BillboardBorders;
	cocos2d::Sprite* ColoredBalloonGoal = nullptr;
	std::vector<cocos2d::Sprite*> ColoredBalloonSprites;

	cocos2d::Sprite* GetGoalSpriteByItemType(ItemType itemType);
};

#endif //__ENGINE_IMAGELIBRARY_H_