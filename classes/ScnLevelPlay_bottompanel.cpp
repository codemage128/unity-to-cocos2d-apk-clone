#include "ScnLevelPlay.h"
#include "cocostudio/CocoStudio.h"
#include "global/GameManager.h"
#include "global/SoundManager.h"
#include "common/Util.h"
#include "DlgLevelQuit.h"
#include "DlgLvlClear.h"
#include "DlgLvlFail.h"
#include "game/LevelBuilder.h"
#include "game/ImageLibrary.h"
#include "game/Extension.h"
#include "game/Booster.h"

void ScnLevelPlay::initBottomPanel() {
	Util::applyDefaultButtonPressFx(_btnBooster[0] = Util::getChildNode<ui::Button*>(_rootNode, "item1/btn", CC_CALLBACK_1(ScnLevelPlay::onBoosterHammerClicked,this)));
	Util::applyDefaultButtonPressFx(_btnBooster[1] = Util::getChildNode<ui::Button*>(_rootNode, "item2/btn", CC_CALLBACK_1(ScnLevelPlay::onBoosterBoxingGloveClicked, this)));
	Util::applyDefaultButtonPressFx(_btnBooster[2] = Util::getChildNode<ui::Button*>(_rootNode, "item3/btn", CC_CALLBACK_1(ScnLevelPlay::onBoosterAnvilClicked, this)));
	Util::applyDefaultButtonPressFx(_btnBooster[3] = Util::getChildNode<ui::Button*>(_rootNode, "item4/btn", CC_CALLBACK_1(ScnLevelPlay::onBoosterDiceClicked, this)));
	_btnBooster[0]->setVisible(GM->getBoosterHammerUseable());
	_btnBooster[1]->setVisible(GM->getBoosterBoxingUseable());
	_btnBooster[2]->setVisible(GM->getBoosterAnvilUseable());
	_btnBooster[3]->setVisible(GM->getBoosterShuffleUseable());
	_lblBoosterCount[0] = Util::getChildNode<ui::Text*>(_rootNode, "item1/btn/count");
	_lblBoosterCount[1] = Util::getChildNode<ui::Text*>(_rootNode, "item2/btn/count");
	_lblBoosterCount[2] = Util::getChildNode<ui::Text*>(_rootNode, "item3/btn/count");
	_lblBoosterCount[3] = Util::getChildNode<ui::Text*>(_rootNode, "item4/btn/count");
	updateBottomPanel();
}
void ScnLevelPlay::updateBottomPanel() {
	_lblBoosterCount[0]->setString(Ext_itos(GM->getBoosterHammerCount()));
	_lblBoosterCount[1]->setString(Ext_itos(GM->getBoosterBoxingCount()));
	_lblBoosterCount[2]->setString(Ext_itos(GM->getBoosterAnvilCount()));
	_lblBoosterCount[3]->setString(Ext_itos(GM->getBoosterShuffleCount()));
}
void ScnLevelPlay::hideBoosterDesc() {
	if(_boosterDesc == nullptr) return;
	_boosterDesc->removeFromParentAndCleanup(true);
	_boosterDesc = nullptr;
	_boosterDescAnim = nullptr;
}
void ScnLevelPlay::showBoosterDesc(InventoryItemType type) {
	hideBoosterDesc();
	_boosterDesc = CSLoader::createNode("dlgUseItem.csb");
	_boosterDescAnim = CSLoader::createTimeline("dlgUseItem.csb");
	_rootNode->addChild(_boosterDesc, BOOSTERDESC_ZORDER);
	_boosterDesc->runAction(_boosterDescAnim);
	_boosterDescAnim->play("flyIn", false);
	cocostudio::timeline::ActionTimeline* fxshine = CSLoader::createTimeline("fxShine.csb");
	Util::getChildNode<Node*>(_boosterDesc, "root/dlgbar/Panel/shine")->runAction(fxshine);
	fxshine->gotoFrameAndPlay(0, true);
	switch(type) {
	case InventoryItemType::BoxingGlove: Util::getChildNode<Node*>(_boosterDesc, "root/dlgbar/Panel/BoxingGloveNode")->setVisible(true); break;
	case InventoryItemType::Dice: Util::getChildNode<Node*>(_boosterDesc, "root/dlgbar/Panel/DiceNode")->setVisible(true); break;
	case InventoryItemType::Hammer: Util::getChildNode<Node*>(_boosterDesc, "root/dlgbar/Panel/HammerNode")->setVisible(true); break;
	case InventoryItemType::Anvil: Util::getChildNode<Node*>(_boosterDesc, "root/dlgbar/Panel/AnvilNode")->setVisible(true); break;
	}
}
void ScnLevelPlay::onBoosterHammerClicked(cocos2d::Ref*) {
	BoosterManager::getInstance()->HammerClicked();
}
void ScnLevelPlay::onBoosterBoxingGloveClicked(cocos2d::Ref*) {
	BoosterManager::getInstance()->BoxingGloveClicked();
}
void ScnLevelPlay::onBoosterAnvilClicked(cocos2d::Ref*) {
	BoosterManager::getInstance()->AnvilClicked();
}
void ScnLevelPlay::onBoosterDiceClicked(cocos2d::Ref*) {
	BoosterManager::getInstance()->ShuffleClicked();
}
void ScnLevelPlay::onBoosterPaintBrushClicked(cocos2d::Ref*) {
	BoosterManager::getInstance()->PaintBrushClicked();
}