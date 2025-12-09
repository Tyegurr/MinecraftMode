#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include "MinecraftModeManager.h"

using namespace geode::prelude;

class $modify(MCPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;

        MinecraftModeManager::get()->currentPlayLayer = this;
        MinecraftModeManager::get()->currentBatchLayer = static_cast<CCLayer*>(this->getChildByID("main-node")->getChildByID("batch-layer"));

        return true;
    }
};