#pragma once

#include <Geode/Geode.hpp>
using namespace geode::prelude;

class HotbarCell : public CCMenu {
protected:
    bool init();
    HotbarCell() {}

    CCScale9Sprite* _background;
    CCSprite* _blockPreviewSprite;
public:
    static HotbarCell* create();

    void setBlockPreviewToID(int id);
};