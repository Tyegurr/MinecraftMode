#include "HotbarCell.h"
#include "../MinecraftModeManager.h"
#include "../Utils.h"

bool HotbarCell::init() {
    if (!CCMenu::init()) return false;

    this->setAnchorPoint({ 0.5f, 0.5f });

    _background = CCScale9Sprite::createWithSpriteFrameName("plainwhitesquare.png"_spr);
    _background->setContentSize({ 24.0f, 24.0f });
    _background->setColor({ 60, 60, 60 });
    this->addChildAtPosition(_background, Anchor::Center);
    
    _blockPreviewSprite = CCSprite::create();
    this->addChildAtPosition(_blockPreviewSprite, Anchor::Center);

    this->setScale(0.88f);

    return true;
}

HotbarCell* HotbarCell::create() {
    HotbarCell* menu = new HotbarCell();
    menu->init();
    return menu;
}

void HotbarCell::setBlockPreviewToID(int id) {
    if (_blockPreviewSprite != nullptr) {

    }

    //_blockPreviewSprite = CCSprite::createWithSpriteFrameName(MinecraftModeManager::blockMetadatas.at(id)->spriteName);
    _blockPreviewSprite->initWithSpriteFrameName(MinecraftModeManager::blockMetadatas.at(id)->spriteName);
    Utils::SetNearestFilteringSprite(_blockPreviewSprite);
    _blockPreviewSprite->setScale(4.4f);
}