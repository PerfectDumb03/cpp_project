#include "../include/GameSettings.h"
#include "../include/InputHandler.h"
#include <iostream>

void GameSettings::setGameMode() {
    m_gameMode = InputHandler::requestGameMode();
}

int GameSettings::getGameMode() const {
    return m_gameMode;
}

void GameSettings::setObjectCount() {
    if (m_gameMode != 2) {
        std::cout << "This gamemode does not require an object count.\n";
    } else {
        m_objectCount = InputHandler::requestObjectCount();
    }
}

int GameSettings::getObjectCount() const {
    return m_objectCount;
}

int GameSettings::getframeHeight() const {
    return m_frameHeight;
}

void GameSettings::setFrameHeight(int height) {
    m_frameHeight = height;
}

int GameSettings::getFrameWidth() const {
    return m_frameWidth;
}

void GameSettings::setFrameWidth(int width) {
    m_frameWidth = width;
}