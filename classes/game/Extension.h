#ifndef __ENGINE_EXTENSION_H__
#define __ENGINE_EXTENSION_H__

#include <vector>
#include <string>
#include "Mathf.h"

template<class T>
void ListExt_Shuffle(std::vector<T>& v) {
	int count = (int)v.size();
	while(count > 1) {
		count--;
		int num2 = Mathf::Random::Range(0, count + 1);
		T local = v[num2];
		v[num2] = v[count];
		v[count] = local;
	}
};

int ListExt_GetRandomWeightedIndex(std::vector<int>& weights);

float Ext_getCurrentTime();
int Ext_getCurrentFrame();
float Ext_getFrameDeltaTime();

int Ext_stoi(std::string& s, int def = 0);
float Ext_stof(std::string& s, float def=0.0f);
std::string Ext_itos(int i);
std::string Ext_strlwr(std::string& s);

#endif //__ENGINE_EXTENSION_H__