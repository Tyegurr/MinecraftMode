#include "MinecraftModeManager.h"

MinecraftModeManager* MinecraftModeManager::instancePtr = nullptr;
std::vector<std::shared_ptr<BlockMetadata>> MinecraftModeManager::blockMetadatas = {
    SharedBlockMetadata(0, "Dirt", "dirt.png"_spr), SharedBlockMetadata(1, "Grass", "grass.png"_spr), SharedBlockMetadata(2, "Stone", "stone.png"_spr)
};

MinecraftModeManager* MinecraftModeManager::get() {
    if (instancePtr == nullptr) {
        instancePtr = new MinecraftModeManager();
    }
    return instancePtr;
}

bool MinecraftModeManager::isMinecraftModeEnabled() {
    return _isMinecraftMode;
}
void MinecraftModeManager::toggleMinecraftMode(bool toggle) {
    _isMinecraftMode = toggle;

    if (toggle) {
        mcOverlay = MinecraftOverlay::create();
        mcOverlay->setID("mc-overlay");
        mcOverlay->setPosition({ 0.0f, 0.0f });
        currentPlayLayer->m_uiLayer->addChild(mcOverlay);
    }
}