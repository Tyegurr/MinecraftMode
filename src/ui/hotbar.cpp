#include "hotbar.h"
#include "../MinecraftModeManager.h"

bool Hotbar::init() {
    if (!CCMenu::init()) return false;

    this->setID("item-hotbar");
    this->setContentSize({ 240.0f, 24.0f });

    _background = CCScale9Sprite::createWithSpriteFrameName("plainwhitesquare.png"_spr);
    _background->setContentSize({ 240.0f, 24.0f });
    _background->setColor({ 200, 200, 200 });
    _background->setAnchorPoint({ 0.0f, 0.0f });
    this->addChild(_background);

    _selectionBoxSprite = CCSprite::createWithSpriteFrameName("plainwhitesquare.png"_spr);
    _selectionBoxSprite->setPosition({ 12.0f, 0.0f });
    this->addChild(_selectionBoxSprite);

    for (int i = 0; i < 9; i++) {
        HotbarCell* cell = HotbarCell::create();
        cell->setPosition({ 12.0f + (i * 24.0f), 12.0f });
        this->addChild(cell);
        _hotbarCells.push_back(cell);
    }

    for (int idx = 0; idx < 9; idx++) {
        int hotbarIdxID = idsEquipped[idx];

        if (hotbarIdxID >= 0) {
            _hotbarCells.at(idx)->setBlockPreviewToID(hotbarIdxID);
        }
    }

    return true;
}
Hotbar* Hotbar::create() {
    Hotbar* menu = new Hotbar();
    menu->init();
    return menu;
}
void Hotbar::updateSelectionBox() {
    _selectionBoxSprite->setPositionX( 12.0f + (MinecraftModeManager::get()->hotbarIdxPlacing * 24.0f) );
}