#include "PlayLayerMod.hpp"
#include "PauseLayerMod.hpp"
#include "MinecraftModeManager.h"

#include <Geode/Geode.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>
using namespace geode::prelude;

class $modify(KeybaordDispatcherMod, CCKeyboardDispatcher) {
    bool dispatchKeyboardMSG(cocos2d::enumKeyCodes key, bool isKeyDown, bool isKeyRepeat) {
        if (isKeyDown && MinecraftModeManager::get()->isMinecraftModeEnabled()) {
            if (key == KEY_One) {
                MinecraftModeManager::get()->hotbarIdxPlacing = 0;
                MinecraftModeManager::get()->mcOverlay->getHotbar()->updateSelectionBox();
            }
            if (key == KEY_Two) {
                MinecraftModeManager::get()->hotbarIdxPlacing = 1;
                MinecraftModeManager::get()->mcOverlay->getHotbar()->updateSelectionBox();
            }
            if (key == KEY_Three) {
                MinecraftModeManager::get()->hotbarIdxPlacing = 2;
                MinecraftModeManager::get()->mcOverlay->getHotbar()->updateSelectionBox();
            }
            if (key == KEY_Four) {
                MinecraftModeManager::get()->hotbarIdxPlacing = 3;
                MinecraftModeManager::get()->mcOverlay->getHotbar()->updateSelectionBox();
            }
            if (key == KEY_Five) {
                MinecraftModeManager::get()->hotbarIdxPlacing = 4;
                MinecraftModeManager::get()->mcOverlay->getHotbar()->updateSelectionBox();
            }
            if (key == KEY_Six) {
                MinecraftModeManager::get()->hotbarIdxPlacing = 5;
                MinecraftModeManager::get()->mcOverlay->getHotbar()->updateSelectionBox();
            }
            if (key == KEY_Seven) {
                MinecraftModeManager::get()->hotbarIdxPlacing = 6;
                MinecraftModeManager::get()->mcOverlay->getHotbar()->updateSelectionBox();
            }
            if (key == KEY_Eight) {
                MinecraftModeManager::get()->hotbarIdxPlacing = 7;
                MinecraftModeManager::get()->mcOverlay->getHotbar()->updateSelectionBox();
            }
            if (key == KEY_Nine) {
                MinecraftModeManager::get()->hotbarIdxPlacing = 8;
                MinecraftModeManager::get()->mcOverlay->getHotbar()->updateSelectionBox();
            }
            if (key == KEY_Q) {
                // delete
                if (MinecraftModeManager::get()->isMinecraftModeEnabled() == true)
                    MinecraftModeManager::get()->mcOverlay->deleteBlockAtPos(geode::cocos::getMousePos());
            }
            if (key == KEY_E) {
                // place
                if (MinecraftModeManager::get()->isMinecraftModeEnabled() == true)
                    MinecraftModeManager::get()->mcOverlay->placeBlockAtPos(MinecraftModeManager::get()->hotbarIdxPlacing, geode::cocos::getMousePos());
            }
        }

        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat);
    }
};