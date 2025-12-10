#include "MinecraftOverlay.h"
#include "MinecraftModeManager.h"
#include <cmath>
#include "Utils.h"

void MinecraftOverlay::fitGeom() {
    CCSize sceneSize = CCScene::get()->getContentSize();

    _itemHotbar->setPosition({ (sceneSize.width / 2) - 108.0f, 16.0f });

    CCLayer* currentBatchLayer = MinecraftModeManager::get()->currentBatchLayer;

    _batchContainer->setPosition({ MinecraftModeManager::get()->currentBatchLayer->getPositionX(), MinecraftModeManager::get()->currentBatchLayer->getPositionY() });
    _batchContainer->setScale( currentBatchLayer->getScale() );
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

void MinecraftOverlay::deleteBlockAtPos(cocos2d::CCPoint pos) {
    cocos2d::CCPoint pointRelative = {
        pos.x,
        pos.y
    };

    World* currentWorld = MinecraftModeManager::get()->currentWorld;

    // gets every block in our batch container
    CCObject* obj = NULL;
    int idx = 0;
    CCARRAY_FOREACH(_batchContainer->getChildren(), obj)
    {
        CCSprite* sprite = typeinfo_cast<CCSprite*>(obj);
        CCPoint spritePosRelative = { _batchContainer->getPositionX() + sprite->getPositionX(), _batchContainer->getPositionY() + sprite->getPositionY() };
        CCSize spriteSize = sprite->getContentSize();
        spriteSize.width *= sprite->getScale();
        spriteSize.height *= sprite->getScale();

        bool inside = (pointRelative.x >= (spritePosRelative.x - (spriteSize.width / 2)) && pointRelative.x <= ( spritePosRelative.x + (spriteSize.width / 2) )) && (pointRelative.y >= (spritePosRelative.y - (spriteSize.height / 2)) && pointRelative.y <= (spritePosRelative.y + (spriteSize.height / 2)));

        if (inside) {
            // we must make sure we are not deleting the selector sprite otherwise this will cause a crash
            if (sprite == _selectorSprite) { idx++; continue; }

            // i forgot why i need all these
            currentWorld->positionsInOrder.erase(currentWorld->positionsInOrder.begin() + idx);
            currentWorld->rectsInOrder.erase(currentWorld->rectsInOrder.begin() + idx);
            currentWorld->spritesInOrder.erase(currentWorld->spritesInOrder.begin() + idx);

            _batchContainer->removeChild(sprite);
            //sprite->setVisible(false);
            break;
        }

        idx++;
    }
}
void MinecraftOverlay::placeBlockAtPos(int blockId, cocos2d::CCPoint pos) {
    cocos2d::CCPoint newPoint = {
        std::floor(15.0f + std::round((-_batchContainer->getPositionX() + pos.x - 15.0f) / 30.0f) * 30.0f),
        std::floor(15.0f + std::round((-_batchContainer->getPositionY() + pos.y - 15.0f) / 30.0f) * 30.0f)
    };

    World* currentWorld = MinecraftModeManager::get()->currentWorld;

    // we must make sure we don't have more than two objects in the same cell
    if (std::count(currentWorld->positionsInOrder.begin(), currentWorld->positionsInOrder.end(), newPoint) > 0) return;

    CCSprite* sprite = CCSprite::createWithSpriteFrameName(MinecraftModeManager::blockMetadatas.at(blockId)->spriteName);
    sprite->setPosition(newPoint);
    sprite->setScale(7.52f);
    Utils::SetNearestFilteringSprite(sprite);
    _batchContainer->addChild(sprite);

    float f = 3.76f;
    currentWorld->positionsInOrder.push_back(newPoint);
    currentWorld->rectsInOrder.push_back({ newPoint.x - (15.0f * f), newPoint.y + (15.0f * f), 30.0f * f, 30.0f * f });
    currentWorld->spritesInOrder.push_back(sprite);

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
        15.0f + std::round((-_batchContainer->getPositionX() + (mousePos.x / _batchContainer->getScale()) - 15.0f) / 30.0f) * 30.0f,
        15.0f + std::round((-_batchContainer->getPositionY() + (mousePos.y / _batchContainer->getScale()) - 15.0f) / 30.0f) * 30.0f
    });

    fitGeom();
}

Hotbar* MinecraftOverlay::getHotbar() {
    return _itemHotbar;
}