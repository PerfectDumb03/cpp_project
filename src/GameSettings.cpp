//
// Created by Thomas on 06.07.2025.
//
#include <iostream>

#include "../include/GameSettings.h"
#include "../include/InputHandler.h"

void GameSettings::setGameMode() {
    m_gameMode = InputHandler::requestGameMode();
}

int GameSettings::getGameMode() const {
    return m_gameMode;
}

void GameSettings::setObjectCount() {
    do {
        switch (m_gameMode) {
        case 1:
            std::cout << "How many balls do you want to dodge? Input an appropriate number: ";
            break;
        case 2:
            std::cout << "How many squares do you want to catch? Input an appropriate number: ";
            break;
        default:
            std::cout << "Invalid gamemode. Try again.\n";
            setGameMode();
        }
    } while (m_gameMode != 1 && m_gameMode != 2);
    m_objectCount = InputHandler::requestObjectCount(m_gameMode);
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