#include "cocos2d.h"

class ComFollow: public cocos2d::Component {
private:
	cocos2d::Node* _target = nullptr;
	cocos2d::Vec2 _offset = cocos2d::Vec2::ZERO;

public:
	ComFollow();
	~ComFollow();

	CREATE_FUNC(ComFollow)

	void setTarget(cocos2d::Node* target, cocos2d::Vec2 offset=cocos2d::Vec2::ZERO) { _target = target; _offset = offset; }

	void update(float delta) override;
};