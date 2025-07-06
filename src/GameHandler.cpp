//
// Created by Thomas on 06.07.2025.
//

#include "../include/GameHandler.h"
#include "../include/Player.h"
#include "../include/GameSettings.h"

GameHandler::GameHandler(Player& player, GameSettings& settings)
    : m_player(player), m_gameSettings(settings) {
}

void GameHandler::gameStartInput() {
    m_player.setName();
    m_gameSettings.setGameMode();
    m_gameSettings.setObjectCount();
}

int GameHandler::getGameMode() const {
    return m_gameSettings.getGameMode();
}

int GameHandler::getObjectCount() const {
    return m_gameSettings.getObjectCount();
}

void GameHandler::addScore(int points) {
    m_player.addScore(points);
}

int GameHandler::getScore() const {
    return m_player.getScore();
}
int GameHandler::getFrameHeight() const {
    return m_gameSettings.getframeHeight();
}

void GameHandler::setFrameHeight(int height) {
    m_gameSettings.setFrameHeight(height);
}

int GameHandler::getFrameWidth() const {
    return m_gameSettings.getFrameWidth();
}

void GameHandler::setFrameWidth(int width) {
    m_gameSettings.setFrameWidth(width);
}

std::string GameHandler::getPlayerName() const {
    return m_player.getName();
}