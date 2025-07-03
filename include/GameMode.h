//
// Created by Thomas on 03.07.2025.
//

#ifndef GAME_MODE_H
#define GAME_MODE_H

#include "Game.h"

class GameMode : public Player {
public:
    GameMode() = default;
    ~GameMode() override = default;


    void setPlayerNameFromInput();

    void setGameMode();
    int getGameMode() const;

    void setObjectCount();
    int getObjectCount() const;

    void gameStartInput();
    virtual void gameOver();

protected:
    int gameMode = 0;
    int objectCount = 0;
};

#endif // GAME_MODE_H