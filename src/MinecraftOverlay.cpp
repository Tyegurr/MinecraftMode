#include "MinecraftOverlay.h"
#include "MinecraftModeManager.h"
#include <cmath>

void MinecraftOverlay::fitGeom() {
    CCSize sceneSize = CCScene::get()->getContentSize();

    _itemHotbar->setPosition({ (sceneSize.width / 2) - 120.0f, 16.0f });

    _batchContainer->setPosition({ MinecraftModeManager::get()->currentBatchLayer->getPositionX(), MinecraftModeManager::get()->currentBatchLayer->getPositionY() });
}
bool MinecraftOverlay::init() {
    if (!CCMenu::init()) return false;

    _selectorSprite = CCSprite::createWithSpriteFrameName("blockOutline_01_001.png");
    _selectorSprite->setID("selector-sprite");
    _selectorSprite->setColor({ 0, 0, 0 });
    _selectorSprite->setOpacity(128);
    _selectorSprite->setZOrder(16);

    _batchContainer = CCNode::create();
    _batchContainer->setID("batch-container");
    _batchContainer->setAnchorPoint({ 0.0f, 0.0f });
    _batchContainer->setPosition({ 0.0f, 0.0f });
    this->addChild(_batchContainer);

    _batchContainer->addChild(_selectorSprite);

    // crosshair sprite so the player knows where their mouse is
    _crosshairSprite = CCSprite::createWithSpriteFrameName("crosshair.png"_spr);
    _crosshairSprite->setID("crosshair");
    _crosshairSprite->setScale(1.2f);
    this->addChild(_crosshairSprite);

    _itemHotbar = Hotbar::create();
    this->addChild(_itemHotbar);

    fitGeom();

    scheduleUpdate();

    return true;
}

MinecraftOverlay* MinecraftOverlay::create() {
    MinecraftOverlay* menu = new MinecraftOverlay();
    menu->init();
    return menu;
}

void MinecraftOverlay::placeBlockAtPos(int blockId, cocos2d::CCPoint pos) {
    //TODO: lets work with the y pos with the batch container as well
    cocos2d::CCPoint newPoint = {
        15.0f + std::round((-_batchContainer->getPositionX() + pos.x - 15.0f) / 30.0f) * 30.0f,
        15.0f + std::round((-_batchContainer->getPositionY() + pos.y - 15.0f) / 30.0f) * 30.0f
    };

    CCSprite* sprite = CCSprite::createWithSpriteFrameName(MinecraftModeManager::blockMetadatas.at(blockId)->spriteName);
    sprite->setPosition(newPoint);
    sprite->setScale(0.94f);
    _batchContainer->addChild(sprite);

    // TODO: find a viable collision solution
    /*GameObject* GObj = GameObject::createWithKey(blockId);
    GObj->setPosition(newPoint);
    MinecraftModeManager::get()->currentPlayLayer->addToObjectsToShow(GObj);*/
}
void MinecraftOverlay::update(float delta) {
    // gets mouse position (duhh)
    CCPoint mousePos = geode::cocos::getMousePos();
    _crosshairSprite->setPosition(mousePos);

    _selectorSprite->setPosition({
        15.0f + std::round((-_batchContainer->getPositionX() + mousePos.x - 15.0f) / 30.0f) * 30.0f,
        15.0f + std::round((-_batchContainer->getPositionY() + mousePos.y - 15.0f) / 30.0f) * 30.0f
    });

    fitGeom();
}

Hotbar* MinecraftOverlay::getHotbar() {
    return _itemHotbar;
}