#ifndef __LOCALIZATION_H__
#define __LOCALIZATION_H__

//#define USE_JSON

#include "cocos2d.h"
#include "ext/List.h"
#ifdef USE_JSON
#include "json/document.h"
#endif

#define SUPPORTED_LANG_COUNT	2

class ILocalized;

class Localization
{
public:
	static Localization* getInstance();
	~Localization();

	cocos2d::LanguageType getCurrentLanguage() { return _lang; }
	int getCurrentLanguageIndex() { return _index; }
	cocos2d::LanguageType getSupportedLanguage(int index);

	bool changeLanguage(int index);
	bool changeLanguage(cocos2d::LanguageType lang);

	const char* getString(const char* key);

	void registerLocalized(ILocalized* localized);
	void unregisterLocalized(ILocalized* localized);

private:
	Localization();
	void loadData(int index);
	void onLanguageChanged();
	void readSettings();
	void saveSettings();
#ifndef USE_JSON
	void parseTextData(const char* buf);
#endif

private:
	static Localization* _instance;
	cocos2d::LanguageType _lang;
	int _index;
#ifdef USE_JSON
	rapidjson::Document _texts;
#else
	std::string _buffer;
	std::map<std::string, std::string> _texts;
#endif
	List<ILocalized*> _localizedList;
};

class ILocalized
{
public:
	ILocalized() { Localization::getInstance()->registerLocalized(this); }
	~ILocalized() { Localization::getInstance()->unregisterLocalized(this); }
	virtual void onLanguageChanged() = 0;
};

#endif //__LOCALIZATION_H__