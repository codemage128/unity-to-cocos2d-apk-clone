#include "ParticleLibrary.h"
#include "LevelBuilder.h"
#include "Level.h"
#include "Item.h"
#include "Extension.h"
#include "Mathf.h"

#include "cocostudio/CCComExtensionData.h"

USING_NS_CC;
using namespace cocostudio::timeline;

ParticleLibrary* ParticleLibrary::_instance = nullptr;

Node* loadPaticleNode(std::string file) {
	Node* node = CSLoader::createNode(file);
	node->retain();
	return node;
}

ActionTimeline* loadPaticleTimeline(std::string file) {
	ActionTimeline* timeline = CSLoader::createTimeline(file);
	timeline->retain();
	return timeline;
}

void ParticleLibrary::cleanUp() {
	////////////////////// ryr //////////////////////////
	// ===solid color block=============================================================
	for(Node* _node : _xSolidNode)
		_node->release();
	_xSolidNode.clear();
	discoRay->release();
	discoPoint->release();
	for(Node* _node : _discoStartFx)
		_node->release();
	_discoStartFx.clear();
	for(ActionTimeline* _anim : _discoStartFxAnim)
		_anim->release();
	_discoStartFxAnim.clear();
	_discoExplodeFx->release(); _discoExplodeFxAnim->release();
	_discoExplodeStartFx->release(); _discoExplodeStartFxAnim->release();
	_comboHint->release();
	_bombRocketMix->release(); _bombRocketMixAnim->release();
	_xBombRocket->release(); _xBombRocketAnim->release();
	_xBombBomb->release(); _xBombBombAnim->release();
	_xDiscoDisco->release(); _xDiscoDiscoAnim->release();
	_useHammer->release(); _useHammerAnim->release();
	_xHammer->release(); _xHammerAnim->release();
	_useBoxing->release(); _useBoxingAnim->release();
	_useAnvil->release(); _useAnvilAnim->release();
	_xAnvil->release(); _xAnvilAnim->release();
	for(Node* _node : _eggTransform)
		_node->release();
	_eggTransform.clear();
	for(ActionTimeline* _anim : _eggTransformAnim)
		_anim->release();
	_eggTransformAnim.clear();
	_oyster->release(); _oysterAnim->release();
	_fish->release(); _fishAnim->release();
	_fishBubble->release();
	_diamond->release(); _diamondAnim->release();
	_balloongen->release(); _balloongenAnim->release();

	////////////////////// kcs //////////////////////////
	_xDiamond->release();

	////////////////////// sun //////////////////////////

	////////////////////// ysg //////////////////////////
	// ===normal balloon=============================================================
	_xBalloon->release();

	// ===colored balloon=============================================================
	for (Node* _node : _xColoredBalloon)
		_node->release();
	_xColoredBalloon.clear();

	// ===colored crate=============================================================
	for (Node* _node : _xColoredCrate)
		_node->release();
	_xColoredCrate.clear();

	// ===colored crate layer=============================================================
	for (Node* _node : _xColoredCrateLayer)
		_node->release();
	_xColoredCrateLayer.clear();

	// ===disco=============================================================
	for (Node* _node : _xDisco)
		_node->release();
	_xDisco.clear();

	// ===normal crate=============================================================
	_xCrate->release();

	// ===normal crate layer=============================================================
	_xCrateLayer->release();

	// === frame =============================================================
	_xFrame->release();

	// === jelly =============================================================
	_xJelly->release();

	// === light bulb & billboard light bulb ==============================================
	_xLightBulb->release();

	// === turn on light bulb =============================================================
	_xLightBulbOn->release();

	// ===normal crate=============================================================
	_xMetalCrate->release();

	// ===solide block back=============================================================
	_xSolidBack->release();

	// ===disco=============================================================
	for (Node* _node : _xDisco)
		_node->release();
	_xDisco.clear();

	////////////////////// hgs //////////////////////////
	for(Node* node : _xSodaBottle)
		node->release();
	_xSodaBottle.clear();

	////////////////////// unr //////////////////////////

	// === Billboard =============================================================
	_xBillboard->release();

	// === Bomb =============================================================
	_xBomb->release();

	// === Bubble =============================================================
	_xBubble->release();

	// === CanBox =============================================================
	_xCanBox->release();

	// === CanToss =============================================================
	_xCanToss->release();
	
	// === ColoredSoda =============================================================
	for (Node* _node : _xColoredSoda)
		_node->release();
	_xColoredSoda.clear();

	// === EasterEgg =============================================================
	for (Node* _node : _xEasterEgg)
		_node->release();
	_xEasterEgg.clear();

	// === GiantPinata =============================================================
	for(Node* _node : _giantPinata)
		_node->release();
	_giantPinata.clear();
	for(ActionTimeline* _anim : _giantPinataAnim)
		_anim->release();
	_giantPinataAnim.clear();

	// === Honey =============================================================
	_xHoney->release();

	// === Honeyjar =============================================================
	_xHoneyJar->release();

	// === Oyster =============================================================
	_xOyster->release();

	// === Pinata =============================================================
	_xPinata->release();

	// === Watermelon =============================================================
	_xWaterMelon1->release();
	_xWaterMelon2->release();

	// === Create Special Item =============================================================
	_sCreateSpecialItem->release();
}

void ParticleLibrary::init() {
	////////////////////// ryr //////////////////////////
	// ===solid color block=============================================================
	_xSolidNode.push_back(loadPaticleNode("particle/solidYellow.csb"));
	_xSolidNode.push_back(loadPaticleNode("particle/solidRed.csb"));
	_xSolidNode.push_back(loadPaticleNode("particle/solidBlue.csb"));
	_xSolidNode.push_back(loadPaticleNode("particle/solidGreen.csb"));
	_xSolidNode.push_back(loadPaticleNode("particle/solidPurple.csb"));
	_xSolidNode.push_back(loadPaticleNode("particle/solidOrange.csb"));
	discoRay = ParticleSystemQuad::create("particle/discoFlame.plist"); discoRay->retain();
	discoPoint = ParticleSystemQuad::create("particle/discoCellPoint.plist"); discoPoint->retain();
	_discoStartFx.push_back(loadPaticleNode("particle/itemDiscoYellow.csb"));
	_discoStartFx.push_back(loadPaticleNode("particle/itemDiscoRed.csb"));
	_discoStartFx.push_back(loadPaticleNode("particle/itemDiscoBlue.csb"));
	_discoStartFx.push_back(loadPaticleNode("particle/itemDiscoGreen.csb"));
	_discoStartFx.push_back(loadPaticleNode("particle/itemDiscoPurple.csb"));
	_discoStartFx.push_back(loadPaticleNode("particle/itemDiscoOrange.csb"));
	_discoStartFxAnim.push_back(loadPaticleTimeline("particle/itemDiscoYellow.csb"));
	_discoStartFxAnim.push_back(loadPaticleTimeline("particle/itemDiscoRed.csb"));
	_discoStartFxAnim.push_back(loadPaticleTimeline("particle/itemDiscoBlue.csb"));
	_discoStartFxAnim.push_back(loadPaticleTimeline("particle/itemDiscoGreen.csb"));
	_discoStartFxAnim.push_back(loadPaticleTimeline("particle/itemDiscoPurple.csb"));
	_discoStartFxAnim.push_back(loadPaticleTimeline("particle/itemDiscoOrange.csb"));
	_discoExplodeFx = loadPaticleNode("particle/itemDiscoExplode.csb");
	_discoExplodeFxAnim = loadPaticleTimeline("particle/itemDiscoExplode.csb");
	_discoExplodeStartFx = loadPaticleNode("particle/itemDiscoBeforeExplode.csb");
	_discoExplodeStartFxAnim = loadPaticleTimeline("particle/itemDiscoBeforeExplode.csb");
	_comboHint = loadPaticleNode("particle/itemMixable.csb"); _comboHint->retain();
	_bombRocketMix = loadPaticleNode("particle/itemRocketBombMix.csb");
	_bombRocketMixAnim = loadPaticleTimeline("particle/itemRocketBombMix.csb");
	_xBombRocket = loadPaticleNode("particle/itemRocketBombExplode.csb");
	_xBombRocketAnim = loadPaticleTimeline("particle/itemRocketBombExplode.csb");
	_xBombBomb = loadPaticleNode("play/itemBombBomb.csb");
	_xBombBombAnim = loadPaticleTimeline("play/itemBombBomb.csb");
	_xDiscoDisco = loadPaticleNode("play/itemDoubleDisco.csb");
	_xDiscoDiscoAnim = loadPaticleTimeline("play/itemDoubleDisco.csb");
	_useHammer = loadPaticleNode("play/boosterHammer.csb");
	_useHammerAnim = loadPaticleTimeline("play/boosterHammer.csb");
	_xHammer = loadPaticleNode("play/boosterHammerFinish.csb");
	_xHammerAnim = loadPaticleTimeline("play/boosterHammerFinish.csb");
	_useBoxing = loadPaticleNode("play/boosterBoxingGlove.csb");
	_useBoxingAnim = loadPaticleTimeline("play/boosterBoxingGlove.csb");
	_useAnvil = loadPaticleNode("play/boosterAnvil.csb");
	_useAnvilAnim = loadPaticleTimeline("play/boosterAnvil.csb");
	_xAnvil = loadPaticleNode("play/boosterAnvilFinish.csb");
	_xAnvilAnim = loadPaticleTimeline("play/boosterAnvilFinish.csb");
	_eggTransform.push_back(loadPaticleNode("play/cellEggYellow.csb")); _eggTransformAnim.push_back(loadPaticleTimeline("play/cellEggYellow.csb"));
	_eggTransform.push_back(loadPaticleNode("play/cellEggRed.csb")); _eggTransformAnim.push_back(loadPaticleTimeline("play/cellEggRed.csb"));
	_eggTransform.push_back(loadPaticleNode("play/cellEggBlue.csb")); _eggTransformAnim.push_back(loadPaticleTimeline("play/cellEggBlue.csb"));
	_eggTransform.push_back(loadPaticleNode("play/cellEggGreen.csb")); _eggTransformAnim.push_back(loadPaticleTimeline("play/cellEggGreen.csb"));
	_eggTransform.push_back(loadPaticleNode("play/cellEggPurple.csb")); _eggTransformAnim.push_back(loadPaticleTimeline("play/cellEggPurple.csb"));
	_eggTransform.push_back(loadPaticleNode("play/cellEggOrange.csb")); _eggTransformAnim.push_back(loadPaticleTimeline("play/cellEggOrange.csb"));
	_oyster = loadPaticleNode("play/cellOyster.csb"); _oysterAnim = loadPaticleTimeline("play/cellOyster.csb");
	_fish = loadPaticleNode("play/cellFish.csb"); _fishAnim = loadPaticleTimeline("play/cellFish.csb");
	_fishBubble = loadPaticleNode("particle/waterthrow.csb");
	_diamond = loadPaticleNode("play/cellDiamond.csb"); _diamondAnim = loadPaticleTimeline("play/cellDiamond.csb");
	_balloongen = loadPaticleNode("play/cellPump.csb"); _balloongenAnim = loadPaticleTimeline("play/cellPump.csb");

	////////////////////// kcs //////////////////////////
	// === diamond =============================================================
	_xDiamond = loadPaticleNode("particle/diamond.csb");
	////////////////////// sun //////////////////////////

	////////////////////// ysg //////////////////////////
	// ===normal balloon=============================================================
	_xBalloon = loadPaticleNode("particle/balloon.csb");

	// ===colored balloon=============================================================
	_xColoredBalloon.push_back(loadPaticleNode("particle/balloon1.csb"));
	_xColoredBalloon.push_back(loadPaticleNode("particle/balloon2.csb"));
	_xColoredBalloon.push_back(loadPaticleNode("particle/balloon3.csb"));
	_xColoredBalloon.push_back(loadPaticleNode("particle/balloon4.csb"));
	_xColoredBalloon.push_back(loadPaticleNode("particle/balloon5.csb"));
	_xColoredBalloon.push_back(loadPaticleNode("particle/balloon6.csb"));

	// ===colored crate=============================================================
	_xColoredCrate.push_back(loadPaticleNode("particle/crateyellow.csb"));
	_xColoredCrate.push_back(loadPaticleNode("particle/cratered.csb"));
	_xColoredCrate.push_back(loadPaticleNode("particle/crateblue.csb"));
	_xColoredCrate.push_back(loadPaticleNode("particle/crategreen.csb"));
	_xColoredCrate.push_back(loadPaticleNode("particle/cratepurple.csb"));
	_xColoredCrate.push_back(loadPaticleNode("particle/crateorange.csb"));

	// ===colored crate layer=============================================================
	_xColoredCrateLayer.push_back(loadPaticleNode("particle/crateyellowlayer.csb"));
	_xColoredCrateLayer.push_back(loadPaticleNode("particle/crateredlayer.csb"));
	_xColoredCrateLayer.push_back(loadPaticleNode("particle/cratebluelayer.csb"));
	_xColoredCrateLayer.push_back(loadPaticleNode("particle/crategreenlayer.csb"));
	_xColoredCrateLayer.push_back(loadPaticleNode("particle/cratepurplelayer.csb"));
	_xColoredCrateLayer.push_back(loadPaticleNode("particle/crateorangelayer.csb"));

	// ===disco=============================================================
	_xDisco.push_back(loadPaticleNode("particle/discoYellowExplode.csb"));
	_xDisco.push_back(loadPaticleNode("particle/discoRedExplode.csb"));
	_xDisco.push_back(loadPaticleNode("particle/discoBlueExplode.csb"));
	_xDisco.push_back(loadPaticleNode("particle/discoGreenExplode.csb"));
	_xDisco.push_back(loadPaticleNode("particle/discoPurpleExplode.csb"));
	_xDisco.push_back(loadPaticleNode("particle/discoOrangeExplode.csb"));

	// ===normal crate=============================================================
	_xCrate = loadPaticleNode("particle/crate.csb");

	// ===normal crate layer=============================================================
	_xCrateLayer = loadPaticleNode("particle/cratelayer.csb");

	// === frame =============================================================
	_xFrame = loadPaticleNode("particle/cage.csb");

	// === jelly =============================================================
	_xJelly = loadPaticleNode("particle/jelly.csb");

	// === light bulb & billboard light bulb ==============================================
	_xLightBulb = loadPaticleNode("particle/glass.csb");

	// === turn on light bulb =============================================================
	_xLightBulbOn = loadPaticleNode("particle/lampon.csb");

	// ===normal crate=============================================================
	_xMetalCrate = loadPaticleNode("particle/cratemetal.csb");

	// ===solide block back=============================================================
	_xSolidBack = loadPaticleNode("particle/solidExplode.csb");

	// ===disco=============================================================
	_xDisco.push_back(loadPaticleNode("particle/discoYellowExplode.csb"));
	_xDisco.push_back(loadPaticleNode("particle/discoRedExplode.csb"));
	_xDisco.push_back(loadPaticleNode("particle/discoBlueExplode.csb"));
	_xDisco.push_back(loadPaticleNode("particle/discoGreenExplode.csb"));
	_xDisco.push_back(loadPaticleNode("particle/discoPurpleExplode.csb"));
	_xDisco.push_back(loadPaticleNode("particle/discoOrangeExplode.csb"));

	////////////////////// hgs //////////////////////////
	_xSodaBottle.push_back(loadPaticleNode("particle/sodabottle_yellow.csb"));
	_xSodaBottle.push_back(loadPaticleNode("particle/sodabottle_red.csb"));
	_xSodaBottle.push_back(loadPaticleNode("particle/sodabottle_blue.csb"));
	_xSodaBottle.push_back(loadPaticleNode("particle/sodabottle_green.csb"));
	_xSodaBottle.push_back(loadPaticleNode("particle/sodabottle_purple.csb"));
	_xSodaBottle.push_back(loadPaticleNode("particle/sodabottle_orange.csb"));
	////////////////////// unr //////////////////////////

	// === Billboard =============================================================
	_xBillboard = loadPaticleNode("particle/billboard.csb");

	// === Bubble =============================================================
	_xBubble = loadPaticleNode("particle/waterdrop.csb");

	// === Bomb =============================================================
	_xBomb = loadPaticleNode("particle/itemBomb.csb");

	// === CanBox =============================================================
	_xCanBox = loadPaticleNode("particle/canbox.csb");

	// === CanToss =============================================================
	_xCanToss = loadPaticleNode("particle/cantoss.csb");
	
	// === ColoredSoda =============================================================
	_xColoredSoda.push_back(loadPaticleNode("particle/sodabottle_yellow.csb"));
	_xColoredSoda.push_back(loadPaticleNode("particle/sodabottle_red.csb"));
	_xColoredSoda.push_back(loadPaticleNode("particle/sodabottle_blue.csb"));
	_xColoredSoda.push_back(loadPaticleNode("particle/sodabottle_green.csb"));
	_xColoredSoda.push_back(loadPaticleNode("particle/sodabottle_purple.csb"));
	_xColoredSoda.push_back(loadPaticleNode("particle/sodabottle_orange.csb"));

	// === EasterEgg =============================================================
	_xEasterEgg.push_back(loadPaticleNode("particle/eggyellow.csb"));
	_xEasterEgg.push_back(loadPaticleNode("particle/eggred.csb"));
	_xEasterEgg.push_back(loadPaticleNode("particle/eggblue.csb"));
	_xEasterEgg.push_back(loadPaticleNode("particle/egggreen.csb"));
	_xEasterEgg.push_back(loadPaticleNode("particle/eggpurple.csb"));
	_xEasterEgg.push_back(loadPaticleNode("particle/eggorange.csb"));

	// === GiantPinata =============================================================
	_giantPinata.push_back(loadPaticleNode("play/cellGiantPinata1.csb"));
	_giantPinataAnim.push_back( loadPaticleTimeline("play/cellGiantPinata1.csb"));
	_giantPinata.push_back(loadPaticleNode("play/cellGiantPinata2.csb"));
	_giantPinataAnim.push_back(loadPaticleTimeline("play/cellGiantPinata2.csb"));
	_giantPinata.push_back(loadPaticleNode("play/cellGiantPinata3.csb"));
	_giantPinataAnim.push_back(loadPaticleTimeline("play/cellGiantPinata3.csb"));

	// === Honey =============================================================
	_xHoney = loadPaticleNode("particle/honey.csb");

	// === Honey =============================================================
	_xHoneyJar = loadPaticleNode("particle/honeyjar.csb");

	// === Oyster =============================================================
	_xOyster = loadPaticleNode("particle/oyster.csb");

	// === Pinata =============================================================
	_xPinata = loadPaticleNode("particle/pinata.csb");
	_xPinataAction = loadPaticleTimeline("particle/pinata.csb");


	// === Watermelon =============================================================
	_xWaterMelon1 = loadPaticleNode("particle/watermelon1.csb");
	_xWaterMelon2 = loadPaticleNode("particle/watermelon2.csb");

	// === CreateItem =============================================================
	_sCreateSpecialItem = loadPaticleNode("particle/goalStar.csb");
	_sCreateSpecialItemAction = loadPaticleTimeline("particle/goalStar.csb");
}

////////////////////// ryr //////////////////////////
void ParticleLibrary::explodeSolid(ItemType type, cocos2d::Vec2 pos) {
	showParticle(_xSolidNode[(int)type - (int)ItemType::SolidColor1], nullptr, pos);
}

Node* ParticleLibrary::showDiscoWhirl(MatchType type, cocos2d::Vec2 pos) {
	Node* newparticle = cloneNodeForParticleModel(_discoStartFx[(int)type]);
	LevelBuilder::ActiveLevel->CurrentLevelBuilder->ItemContainer->addChild(newparticle, PARTICLE_SOLID_ZORDER);
	newparticle->setPosition(pos);

	auto anim = _discoStartFxAnim[(int)type]->clone();
	newparticle->runAction(anim);
	anim->play("start",false);
	anim->setAnimationEndCallFunc("start", [anim]() {anim->play("cycle", true); });

	return newparticle;
}
void ParticleLibrary::showDiscoSuction(cocos2d::Vec2 pos) {
	showParticle(_discoExplodeStartFx, _discoExplodeStartFxAnim, pos);
}
void ParticleLibrary::showDiscoExplode(cocos2d::Vec2 pos) {
	showParticle(_discoExplodeFx, _discoExplodeFxAnim, pos);
}
cocos2d::Node* ParticleLibrary::showComboHint(cocos2d::Vec2 pos) {
	cocos2d::Node* ret = showParticle(_comboHint, nullptr, pos, 99999.9f);
	ret->setLocalZOrder(ITEM_COMBOHINT_ZORDER);
	ret->setPosition(ret->getPosition() - Vec2::UNIT_Y * 5);
	return ret;
}
void ParticleLibrary::showRocketBombMix(cocos2d::Vec2 pos) {
	showParticle(_bombRocketMix, _bombRocketMixAnim, pos, 0.0f);
}
void ParticleLibrary::showRocketBombExplode(cocos2d::Vec2 pos) {
	showParticle(_xBombRocket, _xBombRocketAnim, pos, 0.0f);
}
void ParticleLibrary::showBombBombExplode(cocos2d::Vec2 pos) {
	showParticle(_xBombBomb, _xBombBombAnim, pos, 0.0f);
}
void ParticleLibrary::showDiscoDiscoExplode(cocos2d::Vec2 pos) {
	showParticle(_xDiscoDisco, _xDiscoDiscoAnim, pos, 0.0f);
}
void ParticleLibrary::showUseHammer(cocos2d::Vec2 pos) {
	showParticle(_useHammer, _useHammerAnim, pos, 0.0f);
}
void ParticleLibrary::showHammerExplode(cocos2d::Vec2 pos) {
	showParticle(_xHammer, _xHammerAnim, pos, 0.0f);
}
void ParticleLibrary::showUseBoxingGlove(cocos2d::Vec2 pos) {
	showParticle(_useBoxing, _useBoxingAnim, pos, 0.0f);
}
void ParticleLibrary::showUseAnvil(cocos2d::Vec2 pos) {
	showParticle(_useAnvil, _useAnvilAnim, pos, 0.0f);
}
void ParticleLibrary::showAnvilExplode(cocos2d::Vec2 pos) {
	showParticle(_xAnvil, _xAnvilAnim, pos);
}
void ParticleLibrary::showEggTransform(MatchType type, cocos2d::Vec2 pos) {
	showParticle(_eggTransform[(int)type], _eggTransformAnim[(int)type], pos, 0.0f);
}
void ParticleLibrary::showFishBubble(int direction, cocos2d::Vec2 pos) {
	showParticle(_fishBubble,nullptr, pos)->setScaleX(direction == 1 ? -1 : 1);
}


////////////////////// kcs //////////////////////////
void ParticleLibrary::explodeDiamond(cocos2d::Vec2 pos) {
	showParticle(_xDiamond, nullptr, pos);
}

////////////////////// sun //////////////////////////

////////////////////// ysg //////////////////////////
void ParticleLibrary::explodeBalloon(cocos2d::Vec2 pos) {
	showParticle(_xBalloon, nullptr, pos);
}

void ParticleLibrary::explodeColoredBalloon(MatchType type, cocos2d::Vec2 pos) {
	showParticle(_xColoredBalloon[(int)type], nullptr, pos);
}

void ParticleLibrary::explodeColoredCrate(MatchType type, cocos2d::Vec2 pos) {
	showParticle(_xColoredCrate[(int)type], nullptr, pos);
}

void ParticleLibrary::explodeColoredCrateLayer(MatchType type, cocos2d::Vec2 pos) {
	showParticle(_xColoredCrateLayer[(int)type], nullptr, pos);
}

void ParticleLibrary::explodeCrate(cocos2d::Vec2 pos) {
	showParticle(_xCrate, nullptr, pos);
}

void ParticleLibrary::explodeCrateLayer(cocos2d::Vec2 pos) {
	showParticle(_xCrateLayer, nullptr, pos);
}

void ParticleLibrary::explodeFrame(cocos2d::Vec2 pos) {
	showParticle(_xFrame, nullptr, pos);
}

void ParticleLibrary::explodeJelly(cocos2d::Vec2 pos) {
	showParticle(_xJelly, nullptr, pos);
}

void ParticleLibrary::explodeLightBulb(cocos2d::Vec2 pos) {
	showParticle(_xLightBulb, nullptr, pos);
}

void ParticleLibrary::turnonLightBulb(cocos2d::Vec2 pos) {
	showParticle(_xLightBulbOn, nullptr, pos);
}

void ParticleLibrary::explodeMetalCrate(cocos2d::Vec2 pos) {
	showParticle(_xMetalCrate, nullptr, pos);
}

void ParticleLibrary::explodeSolidBack(cocos2d::Vec2 pos) {
	showParticle(_xSolidBack, nullptr, pos);
}
void ParticleLibrary::explodeDisco(MatchType type, cocos2d::Vec2 pos) {
	showParticle(_xDisco[(int)type], nullptr, pos);
}

////////////////////// hgs //////////////////////////
void ParticleLibrary::explodeSodaBottle(MatchType type, cocos2d::Vec2 pos) {
	showParticle(_xSodaBottle[(int)type], nullptr, pos);
}
////////////////////// unr //////////////////////////

void ParticleLibrary::explodeBillboard(cocos2d::Vec2 pos) {
	showParticle(_xBillboard, nullptr, pos);
}

void ParticleLibrary::explodeBubble(cocos2d::Vec2 pos) {
	showParticle(_xBubble, nullptr, pos);
}

void ParticleLibrary::explodeBomb(cocos2d::Vec2 pos) {
	showParticle(_xBomb, nullptr, pos);
}

void ParticleLibrary::explodeCanBox(cocos2d::Vec2 pos) {
	showParticle(_xCanBox, nullptr, pos);
}

void ParticleLibrary::explodeCanToss(cocos2d::Vec2 pos) {
	showParticle(_xCanToss, nullptr, pos);
}

void ParticleLibrary::explodeColoredSoda(MatchType type, cocos2d::Vec2 pos) {
	showParticle(_xColoredSoda[(int)type], nullptr, pos);
}

void ParticleLibrary::explodeEasterEgg(MatchType type, cocos2d::Vec2 pos) {
	showParticle(_xEasterEgg[(int)type], nullptr, pos);
}

void ParticleLibrary::explodeHoney(cocos2d::Vec2 pos) {
	showParticle(_xHoney, nullptr, pos);
}

void ParticleLibrary::explodeHoneyJar(cocos2d::Vec2 pos) {
	showParticle(_xHoneyJar, nullptr, pos);
}

void ParticleLibrary::explodeOyster(cocos2d::Vec2 pos) {
	showParticle(_xOyster, nullptr, pos);
}

void ParticleLibrary::explodePinata(cocos2d::Vec2 pos) {
	showParticle(_xPinata, _xPinataAction, pos);
}

void ParticleLibrary::explodeWatermelon1(cocos2d::Vec2 pos) {
	showParticle(_xWaterMelon1, nullptr, pos);
}

void ParticleLibrary::explodeWatermelon2(cocos2d::Vec2 pos) {
	showParticle(_xWaterMelon2, nullptr, pos);
}

void ParticleLibrary::createSpecialItem(cocos2d::Vec2 pos) {
	showParticle(_sCreateSpecialItem, _sCreateSpecialItemAction, pos);
}

cocos2d::Node* ParticleLibrary::showParticle(cocos2d::Node* node, cocostudio::timeline::ActionTimeline* anim, Vec2& pos, float lifetime/*=3.0f*/) {
	Node* newparticle = cloneNodeForParticleModel(node);
	LevelBuilder::ActiveLevel->CurrentLevelBuilder->ItemContainer->addChild(newparticle, PARTICLE_SOLID_ZORDER);
	newparticle->setPosition(pos);

	// if need, run cloned animation
	if(anim != nullptr) {
		anim = anim->clone();
		newparticle->runAction(anim);
		anim->gotoFrameAndPlay(0, false);
		lifetime = Mathf::Max(anim->getDuration() / 60.0f / anim->getTimeSpeed(), lifetime);
	}

	newparticle->runAction(Sequence::createWithTwoActions(DelayTime::create(lifetime), RemoveSelf::create()));
	return newparticle;
}


cocos2d::Node* ParticleLibrary::cloneNodeForNodeModel(cocos2d::Node* src) {
	Node* ret = nullptr;

	Sprite* sn = dynamic_cast<Sprite*>(src);
	if(sn != nullptr)
		ret = static_cast<Node*>(cloneSprite(sn));
	else {
		ret = cloneNode(src);
	}

	for(Node* subnode : src->getChildren()) {
		Node* subclone = cloneNodeForNodeModel(subnode);
		ret->addChild(subclone);
	}

	cocostudio::ComExtensionData* data = dynamic_cast<cocostudio::ComExtensionData*>(src->getComponent("ComExtensionData"));
	if(data != nullptr) {
		cocostudio::ComExtensionData* cloned = cocostudio::ComExtensionData::create();
		cloned->setActionTag(data->getActionTag());
		cloned->setName("ComExtensionData");
		ret->addComponent(cloned);
	}

	return ret;
}

cocos2d::Node* ParticleLibrary::cloneNodeForParticleModel(cocos2d::Node* src) {
	Node* ret = nullptr;
	ParticleSystemQuad* pn = dynamic_cast<ParticleSystemQuad*>(src);
	if(pn != nullptr)
		ret = static_cast<Node*>(cloneParticle(pn));
	else {
		Sprite* sn = dynamic_cast<Sprite*>(src);
		if(sn != nullptr)
			ret = static_cast<Node*>(cloneSprite(sn));
		else {
			ret = cloneNode(src);
		}
	}
	for(Node* subnode : src->getChildren()) {
		Node* subclone = cloneNodeForParticleModel(subnode);
		ret->addChild(subclone);
	}

	cocostudio::ComExtensionData* data = dynamic_cast<cocostudio::ComExtensionData*>(src->getComponent("ComExtensionData"));
	if(data != nullptr) {
		cocostudio::ComExtensionData* cloned = cocostudio::ComExtensionData::create();
		cloned->setActionTag(data->getActionTag());
		cloned->setName("ComExtensionData");
		ret->addComponent(cloned);
	}

	return ret;
}


void ParticleLibrary::copyNode(cocos2d::Node* dst, cocos2d::Node* src) {
	dst->setAnchorPoint(src->getAnchorPoint());
	dst->setPosition(src->getPosition());
	dst->setSkewX(src->getSkewX()); dst->setSkewY(src->getSkewY());
	dst->setScaleX(src->getScaleX()); dst->setScaleY(src->getScaleY()); dst->setScaleZ(src->getScaleZ());
	dst->setRotationSkewX(src->getRotationSkewX()); dst->setRotationSkewY(src->getRotationSkewY());
	dst->setRotation(src->getRotation());
	dst->setColor(src->getColor());
	dst->setOpacity(src->getOpacity());
	dst->setLocalZOrder(src->getLocalZOrder());
	dst->setName(src->getName());
	dst->setTag(src->getTag());
	dst->setVisible(src->isVisible());
}
cocos2d::Node* ParticleLibrary::cloneNode(cocos2d::Node* src) {
	Node* ret = Node::create();
	copyNode(ret, src);
	return ret;
}

void ParticleLibrary::copySprite(cocos2d::Sprite* dst, cocos2d::Sprite* src) {
	copyNode(dst, src);
	dst->setTexture(src->getTexture());
	dst->setTextureRect(src->getTextureRect());
	dst->setBlendFunc(src->getBlendFunc());
}
cocos2d::Sprite* ParticleLibrary::cloneSprite(cocos2d::Sprite* src) {
	Sprite* ret = Sprite::create();
	copySprite(ret, src);
	return ret;
}

void ParticleLibrary::copyParticle(cocos2d::ParticleSystemQuad* dst, cocos2d::ParticleSystemQuad* src) {
	copyNode(dst, src);
	dst->setTexture(src->getTexture());
	dst->setScale(src->getScale());
	dst->setRotation(src->getRotation());
	dst->setScaleX(src->getScaleX()); dst->setScaleY(src->getScaleY());
	dst->setGravity(src->getGravity());
	dst->setSpeed(src->getSpeed());
	dst->setSpeedVar(src->getSpeedVar());
	dst->setTangentialAccel(src->getTangentialAccel());
	dst->setTangentialAccelVar(src->getTangentialAccelVar());
	dst->setRadialAccel(src->getRadialAccel());
	dst->setRadialAccelVar(src->getRadialAccelVar());
	dst->setRotationIsDir(src->getRotationIsDir());
	dst->setStartRadius(src->getStartRadius());
	dst->setStartRadiusVar(src->getStartRadiusVar());
	dst->setEndRadius(src->getEndRadius());
	dst->setEndRadiusVar(src->getEndRadiusVar());
	dst->setRotatePerSecond(src->getRotatePerSecond());
	dst->setRotatePerSecondVar(src->getRotatePerSecondVar());
	dst->setBlendAdditive(src->isBlendAdditive());
	dst->setAtlasIndex(src->getAtlasIndex());
	dst->setDuration(src->getDuration());
	dst->setSourcePosition(src->getSourcePosition());
	dst->setPosVar(src->getPosVar());
	dst->setLife(src->getLife());
	dst->setLifeVar(src->getLifeVar());
	dst->setAngle(src->getAngle());
	dst->setAngleVar(src->getAngleVar());
	dst->setEmitterMode(src->getEmitterMode());
	dst->setStartSize(src->getStartSize());
	dst->setStartSizeVar(src->getStartSizeVar());
	dst->setEndSize(src->getEndSize());
	dst->setEndSizeVar(src->getEndSizeVar());
	dst->setStartColor(src->getStartColor());
	dst->setStartColorVar(src->getStartColorVar());
	dst->setEndColor(src->getEndColor());
	dst->setEndColorVar(src->getEndColorVar());
	dst->setStartSpin(src->getStartSpin());
	dst->setStartSpinVar(src->getStartSpinVar());
	dst->setEndSpin(src->getEndSpin());
	dst->setEndSpinVar(src->getEndSpinVar());
	dst->setEmissionRate(src->getEmissionRate());
	dst->setTotalParticles(src->getTotalParticles());
	dst->setOpacityModifyRGB(src->isOpacityModifyRGB());
	dst->setPositionType(src->getPositionType());
	dst->setBlendFunc(src->getBlendFunc());
}
cocos2d::ParticleSystemQuad* ParticleLibrary::cloneParticle(cocos2d::ParticleSystemQuad* src) {
	ParticleSystemQuad* ret = ParticleSystemQuad::create();
	copyParticle(ret, src);
	// prevent for remove itself
	ret->setAutoRemoveOnFinish(false);
	return ret;
}
