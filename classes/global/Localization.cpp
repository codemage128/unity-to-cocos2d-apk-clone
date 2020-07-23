#include "Localization.h"

USING_NS_CC;

static const LanguageType gSupportedLanguages[SUPPORTED_LANG_COUNT] = {
	LanguageType::ENGLISH,
	LanguageType::CHINESE,
};

static const char* szLanguageDataFiles[SUPPORTED_LANG_COUNT] = {
	"texts/English.txt",
	"texts/Chinese.txt",
};

Localization* Localization::_instance = nullptr;

Localization* Localization::getInstance()
{
	if (_instance == nullptr)
		_instance = new Localization();
	return _instance;
}

Localization::Localization()
{
	readSettings();
	_lang = gSupportedLanguages[_index];
	loadData(_index);
}

Localization::~Localization()
{
}

LanguageType Localization::getSupportedLanguage(int index)
{
	return gSupportedLanguages[index];
}

bool Localization::changeLanguage(cocos2d::LanguageType lang)
{
	if (lang != _lang)
	{
		for (int i = 0; i < SUPPORTED_LANG_COUNT; i++)
		{
			if (lang == gSupportedLanguages[i])
			{
				return changeLanguage(i);
			}
		}
	}
	return false;
}

bool Localization::changeLanguage(int index)
{
	if (index >= 0 && index < SUPPORTED_LANG_COUNT && index != _index)
	{
		loadData(index);
		_lang = gSupportedLanguages[index];
		_index = index;
		saveSettings();
		onLanguageChanged();
		return true;
	}
	return false;
}

void Localization::loadData(int index)
{
#ifdef USE_JSON
	std::string jsonContent = FileUtils::getInstance()->getStringFromFile(szLanguageDataFiles[index]);
	_texts.Parse<0>(jsonContent.c_str());
#else
	_buffer = FileUtils::getInstance()->getStringFromFile(szLanguageDataFiles[index]);
	parseTextData(_buffer.c_str());
#endif
}

#ifndef USE_JSON
void Localization::parseTextData(const char* buf)
{
	const char* line = buf;
	bool flag = false;
	while (!flag)
	{
		const char* end = strchr(line, '\n');
		if (end == nullptr)
			flag = true;
		else
		{
			if (end[-1] == '\r')
				*((char*)(end - 1)) = 0;
			*(char*)end = 0;
		}

		if (*line != 0 && *line == '/' && *(line + 1) == '/')//comment
		{
			if (!flag)
				line = end + 1;
			continue;
		}

		const char* mid = strchr(line, '=');
		if (mid == nullptr)
		{
			if (!flag)
				line = end + 1;
			continue;
		}
		char* p = (char*)(mid - 1);
		while (*p == ' ' || *p == '\t')
			p--;
		*(p + 1) = 0;
		const char* q = mid + 1;
		while (*q == ' ' || *q == '\t')
			q++;
		_texts[line] = q;
		if (!flag)
			line = end + 1;
	}
}
#endif

const char* Localization::getString(const char* key)
{
#ifdef USE_JSON
	return _texts[key].GetString();
#else
	return _texts[key].c_str();
#endif
}

void Localization::registerLocalized(ILocalized* localized)
{
	if (localized != nullptr && _localizedList.indexOf(localized) == -1)
		_localizedList.add(localized);
}

void Localization::unregisterLocalized(ILocalized* localized)
{
	_localizedList.remove(localized);
}

void Localization::onLanguageChanged()
{
	for (int i = 0; i < _localizedList.getCount(); i++)
		_localizedList[i]->onLanguageChanged();
}

void Localization::readSettings()
{
	_index = UserDefault::getInstance()->getIntegerForKey("cur_lang_index", 0);
	if (_index < 0 || _index > SUPPORTED_LANG_COUNT)
		_index = 0;
}

void Localization::saveSettings()
{
	UserDefault* ud = UserDefault::getInstance();
	ud->setIntegerForKey("cur_lang_index", _index);
	ud->flush();
}
