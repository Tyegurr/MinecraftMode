#include "MinecraftModeManager.h"

MinecraftModeManager* MinecraftModeManager::instancePtr = nullptr;

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
        currentWorld = new World();
    }
}
void MinecraftModeManager::onExitingPlayLayer() {
    _isMinecraftMode = false;
    // putting this in a try/catch clause because i'm insanely paranoid i will fuck something up
    try {
        currentWorld->positionsInOrder.clear();
        currentWorld->rectsInOrder.clear();
        currentWorld->spritesInOrder.clear();
    } catch (int ec) {
        log::warn("Couldn't clean up memory after exiting play layer."); // WHAT DO YOU MEAN YOU'RE PREGNANT!?
    }
}

std::vector<std::shared_ptr<BlockMetadata>> MinecraftModeManager::blockMetadatas = {
    SharedBlockMetadata(0, "Dirt", "dirt.png"_spr), SharedBlockMetadata(1, "Grass", "grass.png"_spr), SharedBlockMetadata(2, "Stone", "stone.png"_spr), SharedBlockMetadata(3, "Cobblestone", "cobblestone.png"_spr),
    SharedBlockMetadata(4, "Mossy Cobblestone", "mossy_cobblestone.png"_spr), SharedBlockMetadata(5, "Bricks", "bricks.png"_spr), SharedBlockMetadata(6, "Oak planks", "oak_planks.png"_spr), SharedBlockMetadata(7, "Oak log", "oak_log.png"_spr),
    SharedBlockMetadata(8, "Oak leaves", "oak_leaves.png"_spr)
};