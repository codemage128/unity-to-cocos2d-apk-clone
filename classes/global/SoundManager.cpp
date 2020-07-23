#include "SoundManager.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

USING_NS_CC;

#define sae		SimpleAudioEngine::getInstance()

#define BgMusic_Volume	0.7f
#define Effects_Volume	0.7f

const char* szMusicFiles[] = {
	"sound/mainbg.mp3",
	"sound/gamebg1.mp3",
	"sound/gamebg2.mp3"
};

const char* szEffectFiles[] = {
	"sound/buttonClick.wav",
	"sound/blockExplode.wav",
	"sound/wrongClick.wav"
};

bool SoundManager::_bgMusicOn = true;
bool SoundManager::_effectsOn = true;

void SoundManager::preloadSounds() {
	//for (int i = 0; i < (int)MusicKind::_MusicCount; i++)
	//	sae->preloadBackgroundMusic(szMusicFiles[i]);
	for(int i = 0; i < (int)SoundEffect::_SoundCount; i++)
		sae->preloadEffect(getEffectFileName((SoundEffect)i));
}

void SoundManager::playBgMusic(MusicKind kind) {
	sae->playBackgroundMusic(szMusicFiles[(int)kind], true);
	if(!_bgMusicOn)
		sae->pauseBackgroundMusic();
}

void SoundManager::pauseBgMusic() {
	sae->pauseBackgroundMusic();
}

void SoundManager::resumeBgMusic() {
	if(_bgMusicOn)
		sae->resumeBackgroundMusic();
}

void SoundManager::setBgMusicVolume(float volume) {
	sae->setBackgroundMusicVolume(volume);
}

void SoundManager::playEffectSound(SoundEffect effect) {
	if(_effectsOn && effect < _SoundCount)
		sae->playEffect(getEffectFileName(effect));
}

void SoundManager::playEffectSoundDelay(SoundEffect effect, float delay, Node* attachNode) {
	if(delay <= 0)
		playEffectSound(effect);
	else if(attachNode != nullptr) {
		attachNode->runAction(Sequence::createWithTwoActions(
			DelayTime::create(delay),
			CallFunc::create([effect]() { playEffectSound(effect); })));
	}
}

const char* SoundManager::getEffectFileName(SoundEffect effect) {
	return szEffectFiles[(int)effect];
}

void SoundManager::toggleBgMusicOn() {
	_bgMusicOn = !_bgMusicOn;
	//sae->setBackgroundMusicVolume(_bgMusicOn ? BgMusic_Volume : 0);
	if(_bgMusicOn)
		sae->resumeBackgroundMusic();
	else
		sae->pauseBackgroundMusic();
}

void SoundManager::toggleEffectsOn() {
	_effectsOn = !_effectsOn;
	//sae->setEffectsVolume(_effectsOn ? Effects_Volume : 0);
	if(!_effectsOn)
		sae->stopAllEffects();
}

void SoundManager::setEffectsOn(bool on) {
	_effectsOn = on;
	if(!_effectsOn)
		sae->stopAllEffects();
}

void SoundManager::setMusicOn(bool on) {
	_bgMusicOn = on;
	if(_bgMusicOn)
		sae->resumeBackgroundMusic();
	else
		sae->pauseBackgroundMusic();
}

void SoundManager::readSettings() {
	_bgMusicOn = UserDefault::getInstance()->getBoolForKey("bgMusicOn", true);
	_effectsOn = UserDefault::getInstance()->getBoolForKey("soundEffectsOn", true);
	sae->setBackgroundMusicVolume(_bgMusicOn ? BgMusic_Volume : 0);
	sae->setEffectsVolume(_effectsOn ? Effects_Volume : 0);
}

void SoundManager::saveSettings() {
	UserDefault* ud = UserDefault::getInstance();
	ud->setBoolForKey("bgMusicOn", _bgMusicOn);
	ud->setBoolForKey("soundEffectsOn", _effectsOn);
	ud->flush();
}
