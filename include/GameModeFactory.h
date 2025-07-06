//
// Created by Luca on 06.07.2025.
//

#ifndef GAMEMODEFACTORY_H
#define GAMEMODEFACTORY_H

#include "../include/GameModeFactory.h"
#include "../include/GameMode.h"
#include <memory>

class GameModeFactory {
public:
    static std::unique_ptr<GameMode> create(int gameMode, GameHandler& gameHandler);
};


#endif //GAMEMODEFACTORY_H
