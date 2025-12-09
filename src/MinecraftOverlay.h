#pragma once

#include <Geode/Geode.hpp>
#include "ui/hotbar.h"

using namespace geode::prelude;

class MinecraftOverlay : public CCMenu {
protected:
    bool init();
    MinecraftOverlay() {}

    CCSprite* _crosshairSprite;
    CCSprite* _selectorSprite;
    Hotbar* _itemHotbar;
    CCNode* _batchContainer;

    void fitGeom();
public:
    static MinecraftOverlay* create();

    void placeBlockAtPos(int blockId, cocos2d::CCPoint pos);
    void update(float delta);

    Hotbar* getHotbar();
};