#include "ComFollow.h"

USING_NS_CC;

ComFollow::ComFollow() { _name = "FollowComponent"; }
ComFollow::~ComFollow() {}

void ComFollow::update(float delta) {
	if(_enabled == false || _target == nullptr)
		return;
	getOwner()->setPosition(_target->getPosition() + _offset);
}