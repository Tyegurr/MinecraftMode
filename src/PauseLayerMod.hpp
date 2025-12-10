#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include "MinecraftModeManager.h"

using namespace geode::prelude;

class $modify(MCPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();

        cocos2d::CCMenu* centerButtonMenu = static_cast<cocos2d::CCMenu*>(this->getChildByID("center-button-menu"));

        // so apparently the center button menu doesn't have a layout so we have to make one
        SimpleAxisLayout* axisLayout = SimpleAxisLayout::create(Axis::Row);
        axisLayout->setGap(15.0f);
        centerButtonMenu->setLayout(axisLayout);

        auto MinecraftModeButton = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("MinecraftButton.png"_spr),
            this,
            menu_selector(MCPauseLayer::onMinecraftModeButton)
        );
        MinecraftModeButton->setScale(1.35f);
        MinecraftModeButton->m_baseScale = 1.35f;
        centerButtonMenu->addChild(MinecraftModeButton);
        centerButtonMenu->updateLayout();
    }

    void onMinecraftModeButton(CCObject* sender) {
        MinecraftModeManager::get()->currentPlayLayer->m_player1->togglePlatformerMode(true);
        MinecraftModeManager::get()->currentPlayLayer->resume();
        MinecraftModeManager::get()->toggleMinecraftMode(true);
        CCScene::get()->removeChild(this);
    }
};