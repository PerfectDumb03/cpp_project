//
// Created by Luca on 06.07.2025.
//

#include "../include/GameModeFactory.h"
#include "../include/CatchSquares.h"
#include "../include/CatchBalls.h"

std::unique_ptr<GameMode> GameModeFactory::create(int gameMode, GameHandler& gameHandler) {
    switch (gameMode) {
        case 1:
            return std::make_unique<CatchBalls>(gameHandler);
        case 2:
            return std::make_unique<CatchSquares>(gameHandler);
        default:
            throw std::invalid_argument("Invalid game mode selected.");
    }
}