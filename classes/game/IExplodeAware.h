#ifndef __ENGINe_IEXPLODEAWARE_H_
#define __ENGINe_IEXPLODEAWARE_H_

class IExplodeAware {
public:
	virtual void ExplosionOccured(int moveCount) = 0;
};

#endif //__ENGINe_IEXPLODEAWARE_H_