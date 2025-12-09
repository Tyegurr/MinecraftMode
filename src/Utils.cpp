#include "Utils.h"

void Utils::SetNearestFilteringSprite(cocos2d::CCSprite* spr) {
    // thanks alphalaneous
    cocos2d::ccTexParams params = {GL_NEAREST, GL_NEAREST, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE};
    spr->getTexture()->setTexParameters(&params);
}