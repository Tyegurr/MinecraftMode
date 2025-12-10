#pragma once

#include <Geode/Geode.hpp>
using namespace geode::prelude;

#include "HotbarCell.h"
#include <vector>

class Hotbar : public CCMenu {
protected:
    bool init();
    Hotbar() {}

    CCScale9Sprite* _background;
    CCSprite* _selectionBoxSprite;

    std::vector<HotbarCell*> _hotbarCells;
public:
    int idsEquipped[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

    static Hotbar* create();

    void updateSelectionBox();
};