//
// Created by Thomas on 06.07.2025.
//

#ifndef GAMEHANDLERNEW_H
#define GAMEHANDLERNEW_H

#include "GameSettings.h"
#include "Player.h"

class GameSettings;
class Player;

class GameHandler {
public:
    GameHandler(Player& player, GameSettings& settings);
    virtual ~GameHandler() = default;

    void gameStartInput();

    int getGameMode() const;

    int getObjectCount() const;

    void addScore(int points); // positiv and negativ
    int getScore() const;

    std::string getPlayerName() const;


protected:
    Player& m_player;
    GameSettings& m_gameSettings;
};

#endif //GAMEHANDLERNEW_H
