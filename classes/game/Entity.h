#ifndef __ENGINE_ENTITY_H_
#define __ENGINE_ENTITY_H_


class LevelEntity {
public:
	int LevelNo;
	int Score;
	int Stars;
	int Synced;

	LevelEntity(int levelNo, int score, int stars, int synced) {
		this->LevelNo = levelNo;
		this->Score = score;
		this->Stars = stars;
		this->Synced = synced;
	}
};

#endif //__ENGINE_ENTITY_H_