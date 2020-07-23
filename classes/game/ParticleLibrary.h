#ifndef __ENGINE_PARTICLELIBRARY_H_
#define __ENGINE_PARTICLELIBRARY_H_

#include <vector>

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"


#define PTCLLIB ParticleLibrary::getInstance()
#define PARTICLE_SOLID_ZORDER 400

enum class ItemType;
enum class MatchType;

class ParticleLibrary {
private:
	static ParticleLibrary* _instance;
public:
	static ParticleLibrary* getInstance() { if(_instance == nullptr) _instance = new ParticleLibrary(); return _instance; }

	void init();
	void cleanUp();

	////////////////////// ryr //////////////////////////
	void explodeSolid(ItemType type, cocos2d::Vec2 pos);
	cocos2d::ParticleSystemQuad* discoRay = nullptr;
	cocos2d::ParticleSystemQuad* discoPoint = nullptr;
	cocos2d::Node* showDiscoWhirl(MatchType type, cocos2d::Vec2 pos);
	void showDiscoSuction(cocos2d::Vec2 pos);
	void showDiscoExplode(cocos2d::Vec2 pos);
	cocos2d::Node* showComboHint(cocos2d::Vec2 pos);
	void showRocketBombMix(cocos2d::Vec2 pos);
	void showRocketBombExplode(cocos2d::Vec2 pos);
	void showBombBombExplode(cocos2d::Vec2 pos);
	void showDiscoDiscoExplode(cocos2d::Vec2 pos);
	void showUseHammer(cocos2d::Vec2 pos);
	void showHammerExplode(cocos2d::Vec2 pos);
	void showUseBoxingGlove(cocos2d::Vec2 pos);
	void showUseAnvil(cocos2d::Vec2 pos);
	void showAnvilExplode(cocos2d::Vec2 pos);
	void showEggTransform(MatchType type, cocos2d::Vec2 pos);
	cocos2d::Node* getGiantPinataNode(int i) { return _giantPinata[i]; }
	cocostudio::timeline::ActionTimeline* getGiantPinataAnim(int i) { return _giantPinataAnim[i]; }
	cocos2d::Node* getOysterNode() { return _oyster; }
	cocostudio::timeline::ActionTimeline* getOysterAnim() { return _oysterAnim; }
	cocos2d::Node* getFishNode() { return _fish; }
	cocostudio::timeline::ActionTimeline* getFishAnim() { return _fishAnim; }
	void showFishBubble(int direction, cocos2d::Vec2 pos);
	cocos2d::Node* getDiamondNode() { return _diamond; }
	cocostudio::timeline::ActionTimeline* getDiamondAnim() { return _diamondAnim; }
	cocos2d::Node* getBalloonGenNode() { return _balloongen; }
	cocostudio::timeline::ActionTimeline* getBalloonGenAnim() { return _balloongenAnim; }

	////////////////////// kcs //////////////////////////
	void explodeDiamond(cocos2d::Vec2 pos);

	////////////////////// sun //////////////////////////

	////////////////////// ysg //////////////////////////
	void explodeBalloon(cocos2d::Vec2 pos);
	void explodeColoredBalloon(MatchType type, cocos2d::Vec2 pos);
	void explodeColoredCrate(MatchType type, cocos2d::Vec2 pos);
	void explodeColoredCrateLayer(MatchType type, cocos2d::Vec2 pos);
	void explodeCrate(cocos2d::Vec2 pos);
	void explodeCrateLayer(cocos2d::Vec2 pos);
	void explodeFrame(cocos2d::Vec2 pos);
	void explodeJelly(cocos2d::Vec2 pos);
	void explodeLightBulb(cocos2d::Vec2 pos);
	void turnonLightBulb(cocos2d::Vec2 pos);
	void explodeMetalCrate(cocos2d::Vec2 pos);
	void explodeSolidBack(cocos2d::Vec2 pos);
	void explodeDisco(MatchType type, cocos2d::Vec2 pos);

	////////////////////// hgs //////////////////////////
	void explodeSodaBottle(MatchType type, cocos2d::Vec2 pos);
	////////////////////// unr //////////////////////////
	void explodeBillboard(cocos2d::Vec2 pos);
	void explodeBomb(cocos2d::Vec2 pos);
	void explodeBubble(cocos2d::Vec2 pos);
	void explodeCanBox(cocos2d::Vec2 pos);
	void explodeCanToss(cocos2d::Vec2 pos);
	void explodeColoredEgg(MatchType type, cocos2d::Vec2 pos);
	void explodeColoredSoda(MatchType type, cocos2d::Vec2 pos);
	void explodeEasterEgg(MatchType type, cocos2d::Vec2 pos);
	void explodeHoneyJar(cocos2d::Vec2 pos);
	void explodeHoney(cocos2d::Vec2 pos);
	void explodeOyster(cocos2d::Vec2 pos);
	void explodePinata(cocos2d::Vec2 pos);
	void explodeWatermelon1(cocos2d::Vec2 pos);
	void explodeWatermelon2(cocos2d::Vec2 pos);
	void createSpecialItem(cocos2d::Vec2 pos);
private:
	std::vector<cocos2d::Node*> _discoStartFx; std::vector<cocostudio::timeline::ActionTimeline*> _discoStartFxAnim;
	cocos2d::Node* _discoExplodeStartFx = nullptr; cocostudio::timeline::ActionTimeline* _discoExplodeStartFxAnim = nullptr;
	cocos2d::Node* _discoExplodeFx = nullptr; cocostudio::timeline::ActionTimeline* _discoExplodeFxAnim = nullptr;
	cocos2d::Node* _comboHint = nullptr;
	cocos2d::Node* _bombRocketMix = nullptr; cocostudio::timeline::ActionTimeline*_bombRocketMixAnim = nullptr;
	cocos2d::Node* _xBombRocket = nullptr; cocostudio::timeline::ActionTimeline* _xBombRocketAnim = nullptr;
	cocos2d::Node* _xBombBomb = nullptr; cocostudio::timeline::ActionTimeline* _xBombBombAnim = nullptr;
	cocos2d::Node* _xDiscoDisco = nullptr; cocostudio::timeline::ActionTimeline* _xDiscoDiscoAnim = nullptr;
	cocos2d::Node* _useHammer = nullptr; cocostudio::timeline::ActionTimeline* _useHammerAnim = nullptr;
	cocos2d::Node* _xHammer = nullptr; cocostudio::timeline::ActionTimeline* _xHammerAnim = nullptr;
	cocos2d::Node* _useBoxing = nullptr; cocostudio::timeline::ActionTimeline* _useBoxingAnim = nullptr;
	cocos2d::Node* _useAnvil = nullptr; cocostudio::timeline::ActionTimeline* _useAnvilAnim = nullptr;
	cocos2d::Node* _xAnvil = nullptr; cocostudio::timeline::ActionTimeline* _xAnvilAnim = nullptr;
	std::vector<cocos2d::Node*> _eggTransform; std::vector<cocostudio::timeline::ActionTimeline*> _eggTransformAnim;
	cocos2d::Node* _oyster = nullptr; cocostudio::timeline::ActionTimeline* _oysterAnim = nullptr;
	cocos2d::Node* _fish = nullptr; cocostudio::timeline::ActionTimeline* _fishAnim = nullptr;
	cocos2d::Node* _fishBubble = nullptr;
	cocos2d::Node* _diamond = nullptr; cocostudio::timeline::ActionTimeline* _diamondAnim = nullptr;
	cocos2d::Node* _balloongen = nullptr; cocostudio::timeline::ActionTimeline* _balloongenAnim = nullptr;

	cocos2d::Node*				_xBalloon;
	cocos2d::Node*				_xBalloonGenerator;
	cocos2d::Node*				_xBillboard;
	cocos2d::Node*				_xBillboardLamp;
	cocos2d::Node*				_xBomb;
	cocos2d::Node*				_xBubble;
	cocos2d::Node*				_xCanBox;
	cocos2d::Node*				_xCanToss;
	cocos2d::Node*				_xCarrot;
	std::vector<cocos2d::Node*>	_xColoredBalloon;
	std::vector<cocos2d::Node*>	_xColoredCrate;
	std::vector<cocos2d::Node*>	_xColoredCrateLayer;
	std::vector<cocos2d::Node*>	_xColoredSoda; 
	cocos2d::Node*				_xCrate;
	cocos2d::Node*				_xCrateLayer;
	std::vector<cocos2d::Node*> _xDisco;
	cocos2d::Node*				_xDiamond;
	cocos2d::Node*				_xDiscoBallAndBomb;
	cocos2d::Node*				_xDiscoBallAndRocket;
	cocos2d::Node*				_xDoubleBomb;
	cocos2d::Node*				_xDoubleDiscoBall;
	cocos2d::Node*				_xDoubleRocket;
	cocos2d::Node*				_xDuck;
	std::vector<cocos2d::Node*>	_xEasterEgg;
	cocos2d::Node*				_xFish;
	cocos2d::Node*				_xFrame;
	cocos2d::Node*				_xGiantDuck;
	std::vector<cocos2d::Node*>	_giantPinata; std::vector<cocostudio::timeline::ActionTimeline*> _giantPinataAnim;
	cocos2d::Node*				_xHoney;
	cocos2d::Node*				_xHoneyJar;
	cocos2d::Node*				_xJelly;
	cocos2d::Node*				_xLightBulb;
	cocos2d::Node*				_xLightBulbOn;
	cocos2d::Node*				_xMagicHat;
	cocos2d::Node*				_xMetalCrate;
	cocos2d::Node*				_xOyster;
	cocos2d::Node*				_xPinata; cocostudio::timeline::ActionTimeline* _xPinataAction;
	cocos2d::Node*				_xRocketAndBomb;
	cocos2d::Node*				_xRocket;
	cocos2d::Node*				_xSoda;
	cocos2d::Node*				_xSolidBack;
	std::vector<cocos2d::Node*> _xSolidNode; //1~6	//complete
	cocos2d::Node*				_xWaterMelon1;	//complete
	cocos2d::Node*				_xWaterMelon2;	//complete
	cocos2d::Node*				_sCreateSpecialItem; cocostudio::timeline::ActionTimeline* _sCreateSpecialItemAction;

	std::vector<cocos2d::Node*> _xSodaBottle;

	
	
	
	
	
	
private:
	cocos2d::Node* showParticle(cocos2d::Node* node, cocostudio::timeline::ActionTimeline* anim, cocos2d::Vec2& pos, float lifetime=3.0f);

public:
	static cocos2d::Node* cloneNodeForParticleModel(cocos2d::Node* src);
	static cocos2d::Node* cloneNodeForNodeModel(cocos2d::Node* src);

	static void copyNode(cocos2d::Node* dst, cocos2d::Node* src);
	static cocos2d::Node* cloneNode(cocos2d::Node* src);
	static void copySprite(cocos2d::Sprite* dst, cocos2d::Sprite* src);
	static cocos2d::Sprite* cloneSprite(cocos2d::Sprite* src);
	static void copyParticle(cocos2d::ParticleSystemQuad* dst, cocos2d::ParticleSystemQuad* src);
	static cocos2d::ParticleSystemQuad* cloneParticle(cocos2d::ParticleSystemQuad* src);

};

#endif //__ENGINE_PARTICLELIBRARY_H_