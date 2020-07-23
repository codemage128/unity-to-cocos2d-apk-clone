#include "Extension.h"
#include "Mathf.h"
#include "cocos2d.h"
#include <time.h>
#include <cctype>

USING_NS_CC;

int ListExt_GetRandomWeightedIndex(std::vector<int>& weights) {
	if(weights.size() <= 1) {
		return 0;
	}
	int num = Mathf::Random::Range(0, weights[weights.size() - 1]);
	for(int i = 0; i <(int) weights.size(); i++) {
		if(num < weights[i]) {
			return i;
		}
	}
	return -1;
}


float Ext_getCurrentTime() {
	struct timeval now;
	gettimeofday(&now, nullptr);
	return now.tv_sec + now.tv_usec / 1000000.0f;
}

int Ext_getCurrentFrame() {
	return cocos2d::Director::getInstance()->getTotalFrames();
}

float Ext_getFrameDeltaTime() {
	return cocos2d::Director::getInstance()->getDeltaTime();
}

int Ext_stoi(std::string& s, int def/*=0*/) {
	int ret = 0;
	if(sscanf(s.c_str(), "%d", &ret) == 0)
		return def;
	return ret;
}

float Ext_stof(std::string& s, float def/*=0*/) {
	float ret = 0;
	if(sscanf(s.c_str(), "%f", &ret) == 0)
		return def;
	return ret;
}

std::string Ext_itos(int i) {
	char str[16];
	sprintf(str, "%d", i);
	return str;
}
std::string Ext_strlwr(std::string& s) {
	std::string ret=s;
	for(int i = 0; i < (int)ret.length(); i++)
		ret[i] = std::tolower(ret[i]);
	return ret;
}