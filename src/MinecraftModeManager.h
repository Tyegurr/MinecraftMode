#pragma once

#include <Geode/binding/PlayLayer.hpp>
#include "MinecraftOverlay.h"
#include "BlockData.h"
#include <vector>
#include <memory>
#include "World.h"

class MinecraftModeManager {
protected:
    static MinecraftModeManager* instancePtr;
    MinecraftModeManager() {}

    bool _isMinecraftMode = false;
public:
    PlayLayer* currentPlayLayer;
    MinecraftOverlay* mcOverlay;
    CCLayer* currentBatchLayer;
    static std::vector<std::shared_ptr<BlockMetadata>> blockMetadatas;
    World* currentWorld;

    int hotbarIdxPlacing = 0;

    MinecraftModeManager (const MinecraftModeManager& obj) = delete;
    static MinecraftModeManager* get();

    bool isMinecraftModeEnabled();
    void toggleMinecraftMode(bool toggle);
    void onExitingPlayLayer();
};