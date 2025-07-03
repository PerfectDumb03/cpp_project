//
// Created by Thomas on 03.07.2025.
//

#ifndef GAME_MODE_H
#define GAME_MODE_H

#include "Player.h"
#include <opencv2/opencv.hpp>
#include <string>

class Game;

class GameMode : public Player {
public:
    GameMode() = default;
    ~GameMode() override = default;


    void setPlayerNameFromInput();

    void setGameMode();
    int getGameMode() const;

    void setObjectCount();
    virtual void setObjectCount(int newValue) {};
    int getObjectCount();

    void gameStartInput();
    virtual void gameOver();

protected:
    int gameMode = 0;
    int objectCount = 0;
};

#endif // GAME_MODE_H