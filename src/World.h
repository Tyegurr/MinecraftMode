#pragma once

#include <Geode/Geode.hpp>
#include <vector>
#include <map>

class World {
public:
    //std::vector<c> occupiedSpaces;
    //std::map<Vec2I, cocos2d::CCSprite*> spaceToSprite;
    std::vector<cocos2d::CCPoint> positionsInOrder;
    std::vector<cocos2d::CCRect> rectsInOrder;
    std::vector<cocos2d::CCSprite*> spritesInOrder;

    World() {}
};