#pragma once

#include <Geode/binding/PlayLayer.hpp>
#include "MinecraftOverlay.h"
#include "BlockData.h"
#include <vector>
#include <memory>

class MinecraftModeManager {
protected:
    static MinecraftModeManager* instancePtr;
    MinecraftModeManager() {}

    bool _isMinecraftMode;
public:
    PlayLayer* currentPlayLayer;
    MinecraftOverlay* mcOverlay;
    CCLayer* currentBatchLayer;
    static std::vector<std::shared_ptr<BlockMetadata>> blockMetadatas;

    int hotbarIdxPlacing = 0;

    MinecraftModeManager (const MinecraftModeManager& obj) = delete;
    static MinecraftModeManager* get();

    bool isMinecraftModeEnabled();
    void toggleMinecraftMode(bool toggle);
};