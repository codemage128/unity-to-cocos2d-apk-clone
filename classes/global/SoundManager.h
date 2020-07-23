#ifndef __SOUNDMANAGER_H__
#define __SOUNDMANAGER_H__

#include "cocos2d.h"

class SoundManager {
public:
	enum class MusicKind { 
		mainbg,
		gamebg1,
		gamebg2,
		_MusicCount
	};

	enum SoundEffect {
		buttonClick,
		blockExplode,
		wrongClick,

		_SoundCount
	};

public:
	static void preloadSounds();

	static void playBgMusic(MusicKind kind);
	static void pauseBgMusic();
	static void resumeBgMusic();
	static void setBgMusicVolume(float volume);

	static void playEffectSound(SoundEffect effect);
	static void playEffectSoundDelay(SoundEffect effect, float delay, cocos2d::Node* attachNode);
	static const char* getEffectFileName(SoundEffect effect);

	static void toggleBgMusicOn();
	static void toggleEffectsOn();

	static bool isBgMusicOn() { return _bgMusicOn; }
	static bool isEffectsOn() { return _effectsOn; }
	static void setMusicOn(bool on);
	static void setEffectsOn(bool on);

	static void readSettings();
	static void saveSettings();

private:
	static bool _bgMusicOn;
	static bool _effectsOn;
};


typedef SoundManager::SoundEffect SFX;

#endif //__SOUNDMANAGER_H__