#include "ImageLibrary.h"
#include "Item.h"

ImageLibrary* ImageLibrary::_instance = nullptr;

void ImageLibrary::cleanup() {
	NullImage->release(); NullImage = nullptr;

	for(cocos2d::Sprite* sp : BorderImages)
		sp->release();
	BorderImages.clear();
	for(cocos2d::Sprite* sp : SolidColorSprites)
		sp->release();
	SolidColorSprites.clear();
	for(cocos2d::Sprite* sp : SolidColorHintDiscoSprites)
		sp->release();
	SolidColorHintDiscoSprites.clear();
	for(cocos2d::Sprite* sp : SolidColorHintBombSprites)
		sp->release();
	SolidColorHintBombSprites.clear();
	for(cocos2d::Sprite* sp : SolidColorHintRocketSprites)
		sp->release();
	SolidColorHintRocketSprites.clear();
	for(cocos2d::Sprite* sp : DiscoBallSprites)
		sp->release();
	DiscoBallSprites.clear();

	blockGlow->release(); blockGlow = nullptr;
	horizontalRocket->release(); horizontalRocket = nullptr;
	verticalRocket->release(); verticalRocket = nullptr;
	topRocket->release(); topRocket = nullptr;
	rightRocket->release(); rightRocket = nullptr;
	bottomRocket->release(); bottomRocket = nullptr;
	leftRocket->release(); leftRocket = nullptr;

	for(cocos2d::Sprite* sp : DuckSprites)
		sp->release();
	DuckSprites.clear();
	for(cocos2d::Sprite* sp : GiantPinata)
		sp->release();
	GiantPinata.clear();
	GiantPinataPanel->release();
	GiantPinataRope->release();

	Bubble->release(); Bubble = nullptr;
	Bomb->release(); Bomb = nullptr;
	Rocket->release(); Rocket = nullptr;
	Balloon->release(); Balloon = nullptr;
	Pinata->release(); Pinata = nullptr;
	LightBulb->release(); LightBulb = nullptr;
	LightBulbOff->release(); LightBulbOff = nullptr;
	Crate->release(); Crate = nullptr;
	MagicHat->release(); MagicHat = nullptr;
	ColoredCrateGoal->release(); ColoredCrateGoal = nullptr;
	GiantDuck->release(); GiantDuck = nullptr;
	EasterEggGoal->release(); EasterEggGoal = nullptr;
	Carrot->release(); Carrot = nullptr;
	Jelly->release(); Jelly = nullptr;
	Can->release(); Can = nullptr;
	CanToss->release(); CanToss = nullptr;
	Frame->release(); Frame = nullptr;
	OysterGoal->release(); OysterGoal = nullptr;
	Soda->release(); Soda = nullptr;
	SodaFrame->release(); SodaFrame = nullptr;
	SodaBottleNeck->release(); SodaBottleNeck = nullptr;
	for (cocos2d::Sprite* sp : SodaBottleCaps)
		sp->release();
	SodaBottleCaps.clear();
	for(cocos2d::Sprite* sp : SodaBottles)
		sp->release();
	SodaBottles.clear();
	WaterMelon->release(); WaterMelon = nullptr;
	for(cocos2d::Sprite* sp : WaterMelonSprites)
		sp->release();
	WaterMelonSprites.clear();
	MetalCrate->release(); MetalCrate = nullptr;
	HoneyCube->release(); HoneyCube = nullptr;
	HoneyPot->release(); HoneyPot = nullptr;
	Diamond->release(); Diamond = nullptr;
	BillboardGoal->release(); BillboardGoal = nullptr;
	BillboardOn->release(); BillboardOn = nullptr;
	BillboardOff->release(); BillboardOff = nullptr;
	for(cocos2d::Sprite* sp : BillboardBorders)
		sp->release();
	BillboardBorders.clear();
	ColoredBalloonGoal->release(); ColoredBalloonGoal = nullptr;

	for (cocos2d::Sprite* sp : ColoredBalloonSprites)
		sp->release();
	ColoredBalloonSprites.clear();

	for (cocos2d::Sprite* sp : CrateLayerSprites)
		sp->release();
	CrateLayerSprites.clear();

	//colored Crate Layer Sprites
	for (cocos2d::Sprite* sp : YellowCrateLayerSprites)
		sp->release();
	YellowCrateLayerSprites.clear();

	for (cocos2d::Sprite* sp : RedCrateLayerSprites)
		sp->release();
	RedCrateLayerSprites.clear();

	for (cocos2d::Sprite* sp : BlueCrateLayerSprites)
		sp->release();
	BlueCrateLayerSprites.clear();

	for (cocos2d::Sprite* sp : GreenCrateLayerSprites)
		sp->release();
	GreenCrateLayerSprites.clear();

	for (cocos2d::Sprite* sp : PurpleCrateLayerSprites)
		sp->release();
	PurpleCrateLayerSprites.clear();

	for (cocos2d::Sprite* sp : OrangeCrateLayerSprites)
		sp->release();
	OrangeCrateLayerSprites.clear();

	for (cocos2d::Sprite* sp : EasterEggSprites)
		sp->release();
	EasterEggSprites.clear();

	if(_instance != nullptr)
		delete _instance;
	_instance = nullptr;
}

void ImageLibrary::CopySprite(cocos2d::Sprite* dest, cocos2d::Sprite* src) {
	dest->setTexture(src->getTexture());
	dest->setTextureRect(src->getTextureRect());
}

void ImageLibrary::init() {
	// prevent for re-init
	if(BorderImages.size() > 0) 
		return;

	// load null image
	NullImage = cocos2d::Sprite::create("image/common/empty.png"); NullImage->retain();

	// load border images
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrelb.png"));
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrb.png"));
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrerb.png"));
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrl.png"));
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrcell.png"));
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrr.png"));
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrelt.png"));
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrt.png"));
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrert.png"));
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrxdiag2.png"));
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrxdiag.png"));
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrxlb.png"));
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrxrb.png"));
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrxlt.png"));
	BorderImages.push_back(cocos2d::Sprite::create("image/play/border/bdrxrt.png"));
	for(cocos2d::Sprite* sp : BorderImages)
		sp->retain();


	// load solid color sprites
	SolidColorSprites.push_back(cocos2d::Sprite::create("image/play/solidcolor1.png"));//Yellow,
	SolidColorSprites.push_back(cocos2d::Sprite::create("image/play/solidcolor2.png"));//Red,
	SolidColorSprites.push_back(cocos2d::Sprite::create("image/play/solidcolor3.png"));//Blue,
	SolidColorSprites.push_back(cocos2d::Sprite::create("image/play/solidcolor4.png"));//Green,
	SolidColorSprites.push_back(cocos2d::Sprite::create("image/play/solidcolor5.png"));//Purple,
	SolidColorSprites.push_back(cocos2d::Sprite::create("image/play/solidcolor6.png"));//Orange,
	for(cocos2d::Sprite* sp : SolidColorSprites)
		sp->retain();

	// load solid color hint disco sprites
	SolidColorHintDiscoSprites.push_back(cocos2d::Sprite::create("image/play/blockyellowdisco.png"));
	SolidColorHintDiscoSprites.push_back(cocos2d::Sprite::create("image/play/blockreddisco.png"));
	SolidColorHintDiscoSprites.push_back(cocos2d::Sprite::create("image/play/blockbluedisco.png"));
	SolidColorHintDiscoSprites.push_back(cocos2d::Sprite::create("image/play/blockgreendisco.png"));
	SolidColorHintDiscoSprites.push_back(cocos2d::Sprite::create("image/play/blockpurpledisco.png"));
	SolidColorHintDiscoSprites.push_back(cocos2d::Sprite::create("image/play/blockorangedisco.png"));
	for(cocos2d::Sprite* sp : SolidColorHintDiscoSprites)
		sp->retain();

	// load solid color hint bomb sprites
	SolidColorHintBombSprites.push_back(cocos2d::Sprite::create("image/play/blockyellowbomb.png"));
	SolidColorHintBombSprites.push_back(cocos2d::Sprite::create("image/play/blockredbomb.png"));
	SolidColorHintBombSprites.push_back(cocos2d::Sprite::create("image/play/blockbluebomb.png"));
	SolidColorHintBombSprites.push_back(cocos2d::Sprite::create("image/play/blockgreenbomb.png"));
	SolidColorHintBombSprites.push_back(cocos2d::Sprite::create("image/play/blockpurplebomb.png"));
	SolidColorHintBombSprites.push_back(cocos2d::Sprite::create("image/play/blockorangebomb.png"));
	for(cocos2d::Sprite* sp : SolidColorHintBombSprites)
		sp->retain();

	// load solid color hint rocket sprites
	SolidColorHintRocketSprites.push_back(cocos2d::Sprite::create("image/play/blockyellowrocket.png"));
	SolidColorHintRocketSprites.push_back(cocos2d::Sprite::create("image/play/blockredrocket.png"));
	SolidColorHintRocketSprites.push_back(cocos2d::Sprite::create("image/play/blockbluerocket.png"));
	SolidColorHintRocketSprites.push_back(cocos2d::Sprite::create("image/play/blockgreenrocket.png"));
	SolidColorHintRocketSprites.push_back(cocos2d::Sprite::create("image/play/blockpurplerocket.png"));
	SolidColorHintRocketSprites.push_back(cocos2d::Sprite::create("image/play/blockorangerocket.png"));
	for(cocos2d::Sprite* sp : SolidColorHintRocketSprites)
		sp->retain();

	// load disco ball sprites
	DiscoBallSprites.push_back(cocos2d::Sprite::create("image/play/discoballcolor1.png"));
	DiscoBallSprites.push_back(cocos2d::Sprite::create("image/play/discoballcolor2.png"));
	DiscoBallSprites.push_back(cocos2d::Sprite::create("image/play/discoballcolor3.png"));
	DiscoBallSprites.push_back(cocos2d::Sprite::create("image/play/discoballcolor4.png"));
	DiscoBallSprites.push_back(cocos2d::Sprite::create("image/play/discoballcolor5.png"));
	DiscoBallSprites.push_back(cocos2d::Sprite::create("image/play/discoballcolor6.png"));
	for(cocos2d::Sprite* sp : DiscoBallSprites)
		sp->retain();

	// load glow
	blockGlow = cocos2d::Sprite::create("image/play/boxglow.png"); blockGlow->retain();
	// load rockets
	horizontalRocket = cocos2d::Sprite::create("image/play/rockethorizantal.png"); horizontalRocket->retain();
	verticalRocket = cocos2d::Sprite::create("image/play/rocketvertical.png"); verticalRocket->retain();
	topRocket = cocos2d::Sprite::create("image/play/rockettop.png"); topRocket->retain();
	rightRocket = cocos2d::Sprite::create("image/play/rocketright.png"); rightRocket->retain();
	bottomRocket = cocos2d::Sprite::create("image/play/rocketbottom.png"); bottomRocket->retain();
	leftRocket = cocos2d::Sprite::create("image/play/rocketleft.png"); leftRocket->retain();

	// load ducks
	DuckSprites.push_back(cocos2d::Sprite::create("image/play/duck1.png"));
	DuckSprites.push_back(cocos2d::Sprite::create("image/play/duck2.png"));
	DuckSprites.push_back(cocos2d::Sprite::create("image/play/duck3.png"));
	DuckSprites.push_back(cocos2d::Sprite::create("image/play/duck4.png"));
	DuckSprites.push_back(cocos2d::Sprite::create("image/play/duck5.png"));
	for(cocos2d::Sprite* sp : DuckSprites)
		sp->retain();

	//load giant pinatas
	GiantPinata.push_back(cocos2d::Sprite::create("image/play/giantpinata1.png"));
	GiantPinata.push_back(cocos2d::Sprite::create("image/play/giantpinata2.png"));
	GiantPinata.push_back(cocos2d::Sprite::create("image/play/giantpinata3.png"));
	for(cocos2d::Sprite* sp : GiantPinata)
		sp->retain();
	GiantPinataPanel = cocos2d::Sprite::create("image/play/giantpinatapanel.png"); GiantPinataPanel->retain();
	GiantPinataRope = cocos2d::Sprite::create("image/play/giantpinatarope.png"); GiantPinataRope->retain();

	// load sprites
	Bubble = cocos2d::Sprite::create("image/play/bubble.png"); Bubble->retain();
	Bomb = cocos2d::Sprite::create("image/play/bomb.png"); Bomb->retain();
	Rocket = cocos2d::Sprite::create("image/play/rocketvertical.png"); Rocket->retain();
	Balloon = cocos2d::Sprite::create("image/play/balloon.png"); Balloon->retain();
	Pinata = cocos2d::Sprite::create("image/play/pinata.png"); Pinata->retain();
	LightBulb = cocos2d::Sprite::create("image/play/lightbulbon.png"); LightBulb->retain();
	LightBulbOff = cocos2d::Sprite::create("image/play/lightbulboff.png"); LightBulbOff->retain();
	Crate = cocos2d::Sprite::create("image/play/crate.png"); Crate->retain();
	MagicHat = cocos2d::Sprite::create("image/play/magichat.png"); MagicHat->retain();
	ColoredCrateGoal = cocos2d::Sprite::create("image/play/boxall.png"); ColoredCrateGoal->retain();
	GiantDuck = cocos2d::Sprite::create("image/play/giantduck.png"); GiantDuck->retain();
	EasterEggGoal = cocos2d::Sprite::create("image/play/eggall.png"); EasterEggGoal->retain();
	Carrot = cocos2d::Sprite::create("image/play/carrot.png"); Carrot->retain();
	Jelly = cocos2d::Sprite::create("image/play/jelly.png"); Jelly->retain();
	Can = cocos2d::Sprite::create("image/play/cantoss.png"); Can->retain();
	CanToss = cocos2d::Sprite::create("image/play/cantossback.png"); CanToss->retain();
	Frame = cocos2d::Sprite::create("image/play/wire.png"); Frame->retain();
	OysterGoal = cocos2d::Sprite::create("image/play/oystergoal.png"); OysterGoal->retain();
	Soda = cocos2d::Sprite::create("image/play/bottleall.png"); Soda->retain();
	SodaFrame = cocos2d::Sprite::create("image/play/sodabottleback.png"); SodaFrame->retain();
	SodaBottleNeck = cocos2d::Sprite::create("image/play/coloredsodaneck.png"); SodaBottleNeck->retain();
	SodaBottleCaps.push_back(cocos2d::Sprite::create("image/play/coloredsodayellowcap.png"));
	SodaBottleCaps.push_back(cocos2d::Sprite::create("image/play/coloredsodaredcap.png"));
	SodaBottleCaps.push_back(cocos2d::Sprite::create("image/play/coloredsodabluecap.png"));
	SodaBottleCaps.push_back(cocos2d::Sprite::create("image/play/coloredsodagreencap.png"));
	SodaBottleCaps.push_back(cocos2d::Sprite::create("image/play/coloredsodapurplecap.png"));
	for (cocos2d::Sprite* sp : SodaBottleCaps)
		sp->retain();
	SodaBottles.push_back(cocos2d::Sprite::create("image/play/coloredsodayellow.png"));
	SodaBottles.push_back(cocos2d::Sprite::create("image/play/coloredsodared.png"));
	SodaBottles.push_back(cocos2d::Sprite::create("image/play/coloredsodablue.png"));
	SodaBottles.push_back(cocos2d::Sprite::create("image/play/coloredsodagreen.png"));
	SodaBottles.push_back(cocos2d::Sprite::create("image/play/coloredsodapurple.png"));
	for(cocos2d::Sprite* sp : SodaBottles)
		sp->retain();
	WaterMelon = cocos2d::Sprite::create("image/play/watermelon3.png"); WaterMelon->retain();
	WaterMelonSprites.push_back(cocos2d::Sprite::create("image/play/watermelon1.png"));
	WaterMelonSprites.push_back(cocos2d::Sprite::create("image/play/watermelon2.png"));
	WaterMelonSprites.push_back(cocos2d::Sprite::create("image/play/watermelon3.png"));
	for(cocos2d::Sprite* sp : WaterMelonSprites)
		sp->retain();
	MetalCrate = cocos2d::Sprite::create("image/play/metalcrate.png"); MetalCrate->retain();
	HoneyCube = cocos2d::Sprite::create("image/play/honey2.png"); HoneyCube->retain();
	HoneyPot = cocos2d::Sprite::create("image/play/honey1.png"); HoneyPot->retain();
	Diamond = cocos2d::Sprite::create("image/play/diamond/diamond.png"); Diamond->retain();
	BillboardGoal = cocos2d::Sprite::create("image/play/billboard/billboardon.png"); BillboardGoal->retain();
	BillboardOn = cocos2d::Sprite::create("image/play/billboard/billboardon.png"); BillboardOn->retain();
	BillboardOff = cocos2d::Sprite::create("image/play/billboard/billboardoff.png"); BillboardOff->retain();
	BillboardBorders.push_back(cocos2d::Sprite::create("image/play/billboard/billboardbackelt.png")); BillboardBorders[0]->retain(); //au
	BillboardBorders.push_back(cocos2d::Sprite::create("image/play/billboard/billboardbackelb.png")); BillboardBorders[1]->retain(); //ad
	BillboardBorders.push_back(cocos2d::Sprite::create("image/play/billboard/billboardbackt.png")); BillboardBorders[2]->retain(); //bu
	BillboardBorders.push_back(cocos2d::Sprite::create("image/play/billboard/billboardbackb.png")); BillboardBorders[3]->retain(); //bd
	BillboardBorders.push_back(cocos2d::Sprite::create("image/play/billboard/billboardbackxlt.png")); BillboardBorders[4]->retain(); //cu
	BillboardBorders.push_back(cocos2d::Sprite::create("image/play/billboard/billboardbackxlb.png")); BillboardBorders[5]->retain(); //cd
	BillboardBorders.push_back(cocos2d::Sprite::create("image/play/billboard/billboardbackcell.png")); BillboardBorders[6]->retain(); //du
	BillboardBorders.push_back(cocos2d::Sprite::create("image/play/billboard/billboardbackcell.png")); BillboardBorders[7]->retain(); //dd
	BillboardBorders.push_back(cocos2d::Sprite::create("image/play/billboard/billboardbackl.png")); BillboardBorders[8]->retain(); //eu
	BillboardBorders.push_back(cocos2d::Sprite::create("image/play/billboard/billboardbackl.png")); BillboardBorders[9]->retain(); //ed
	ColoredBalloonGoal = cocos2d::Sprite::create("image/play/coloredballoongoal.png"); ColoredBalloonGoal->retain();

	// load ColoredBalloonSprites
	ColoredBalloonSprites.push_back(cocos2d::Sprite::create("image/play/coloredballoon1.png"));//Yellow,
	ColoredBalloonSprites.push_back(cocos2d::Sprite::create("image/play/coloredballoon2.png"));//Red,
	ColoredBalloonSprites.push_back(cocos2d::Sprite::create("image/play/coloredballoon3.png"));//Blue,
	ColoredBalloonSprites.push_back(cocos2d::Sprite::create("image/play/coloredballoon4.png"));//Green,
	ColoredBalloonSprites.push_back(cocos2d::Sprite::create("image/play/coloredballoon5.png"));//Purple,
	ColoredBalloonSprites.push_back(cocos2d::Sprite::create("image/play/coloredballoon6.png"));//Orange,
	for (cocos2d::Sprite* sp : ColoredBalloonSprites)
		sp->retain();

	//load CrateLayerSprites
	CrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/crate.png"));
	CrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/cratelayer1.png"));
	CrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/cratelayer2.png"));
	CrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/cratelayer3.png"));
	for (cocos2d::Sprite* sp : CrateLayerSprites)
		sp->retain();

	//load YellowCrateLayerSprites
	YellowCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcrateyellow0.png"));
	YellowCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcrateyellow1.png"));
	YellowCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcrateyellow2.png"));
	for (cocos2d::Sprite* sp : YellowCrateLayerSprites)
		sp->retain();

	//load RedCrateLayerSprites
	RedCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcratered0.png"));
	RedCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcratered1.png"));
	RedCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcratered2.png"));
	for (cocos2d::Sprite* sp : RedCrateLayerSprites)
		sp->retain();

	//load BlueCrateLayerSprites
	BlueCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcrateblue0.png"));
	BlueCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcrateblue1.png"));
	BlueCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcrateblue2.png"));
	for (cocos2d::Sprite* sp : BlueCrateLayerSprites)
		sp->retain();

	//load GreenCrateLayerSprites
	GreenCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcrategreen0.png"));
	GreenCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcrategreen1.png"));
	GreenCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcrategreen2.png"));
	for (cocos2d::Sprite* sp : GreenCrateLayerSprites)
		sp->retain();

	//load PurpleCrateLayerSprites
	PurpleCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcratepurple0.png"));
	PurpleCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcratepurple1.png"));
	PurpleCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcratepurple2.png"));
	for (cocos2d::Sprite* sp : PurpleCrateLayerSprites)
		sp->retain();

	//load OrangeCrateLayerSprites
	OrangeCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcrateorange0.png"));
	OrangeCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcrateorange1.png"));
	OrangeCrateLayerSprites.push_back(cocos2d::Sprite::create("image/play/colorcrateorange2.png"));
	for (cocos2d::Sprite* sp : OrangeCrateLayerSprites)
		sp->retain();

	//load EasterEggSprites
	EasterEggSprites.push_back(cocos2d::Sprite::create("image/play/easteregg.png")); //White
	EasterEggSprites.push_back(cocos2d::Sprite::create("image/play/eggyellow.png"));//Yellow,
	EasterEggSprites.push_back(cocos2d::Sprite::create("image/play/eggred.png"));	//Red,
	EasterEggSprites.push_back(cocos2d::Sprite::create("image/play/eggblue.png"));	//Blue,
	EasterEggSprites.push_back(cocos2d::Sprite::create("image/play/egggreen.png"));	//Green,
	EasterEggSprites.push_back(cocos2d::Sprite::create("image/play/eggpurple.png"));//Purple,
	EasterEggSprites.push_back(cocos2d::Sprite::create("image/play/eggorange.png"));//Orange,
	for (cocos2d::Sprite* sp : EasterEggSprites)
		sp->retain();
}

cocos2d::Sprite* ImageLibrary::GetGoalSpriteByItemType(ItemType itemType) {
	switch(itemType) {
	case ItemType::Bomb: return this->Bomb;
	case ItemType::Rocket: return this->Rocket;
	case ItemType::SolidColor1: return this->SolidColorSprites[0];
	case ItemType::SolidColor2: return this->SolidColorSprites[1];
	case ItemType::SolidColor3: return this->SolidColorSprites[2];
	case ItemType::SolidColor4: return this->SolidColorSprites[3];
	case ItemType::SolidColor5: return this->SolidColorSprites[4];
	case ItemType::SolidColor6: return this->SolidColorSprites[5];
	case ItemType::Duck: return this->DuckSprites[0];
	case ItemType::Balloon: return this->Balloon;
	case ItemType::Pinata: return this->Pinata;
	case ItemType::LightBulb: return this->LightBulb;
	case ItemType::Crate: return this->Crate;
	case ItemType::ColoredCrate: return this->ColoredCrateGoal;
	case ItemType::Bubble: return this->Bubble;
	case ItemType::GiantDuck: return this->GiantDuck;
	case ItemType::EasterEgg: return this->EasterEggGoal;
	case ItemType::Carrot: return this->Carrot;
	case ItemType::Jelly: return this->Jelly;
	case ItemType::CanToss: return this->Can;
	case ItemType::Frame: return this->Frame;
	case ItemType::GiantPinata: return this->GiantPinata[0];
	case ItemType::Oyster: return this->OysterGoal;
	case ItemType::Soda: return this->Soda;
	case ItemType::WaterMelon: return this->WaterMelon;
	case ItemType::MetalCrate: return this->MetalCrate;
	case ItemType::Honey: return this->HoneyCube;
	case ItemType::Diamond: return this->Diamond;
	case ItemType::Billboard: return this->BillboardGoal;
	case ItemType::ColoredSoda: return this->Soda;
	case ItemType::ColoredBalloon: return this->ColoredBalloonGoal;
	}
	return nullptr;
}