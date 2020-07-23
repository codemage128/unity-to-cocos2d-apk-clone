#include "Mathf.h"
#include <ctime>

using namespace Mathf;

int Random::Range(int a/*inclusive*/, int b/*exclusive*/) {
	return (((unsigned int)rand()) % (b - a)) + a;
}
float Random::Range(float a/*inclusive*/, float b/*inclusive*/) {
	return (b - a)*rand() / (float)(RAND_MAX - 1) + a;
}
void Random::Init() {
	time_t t;
	srand((unsigned int)time(&t));
}