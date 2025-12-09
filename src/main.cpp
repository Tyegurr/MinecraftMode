#include "PlayLayerMod.hpp"
#include "PauseLayerMod.hpp"
#include "MinecraftModeManager.h"

#include <Geode/Geode.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>
using namespace geode::prelude;

class $modify(KeybaordDispatcherMod, CCKeyboardDispatcher) {
    bool dispatchKeyboardMSG(cocos2d::enumKeyCodes key, bool isKeyDown, bool isKeyRepeat) {
        if (isKeyDown) {
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
            if (key == KEY_Q) {
                // delete
            }
            if (key == KEY_E) {
                // place
                MinecraftModeManager::get()->mcOverlay->placeBlockAtPos(MinecraftModeManager::get()->hotbarIdxPlacing, geode::cocos::getMousePos());
            }
        }

        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat);
    }
};