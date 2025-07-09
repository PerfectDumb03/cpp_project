#include "../include/GameModeFactory.h"
#include "../include/CatchSquares.h"
#include "../include/DogeBalls.h"

std::unique_ptr<GameMode> GameModeFactory::create(int gameMode, GameHandler& gameHandler) {
    switch (gameMode) {
        case 1:
            return std::make_unique<DogeBalls>(gameHandler);
        case 2:
            return std::make_unique<CatchSquares>(gameHandler);
        default:
            throw std::invalid_argument("Invalid game mode selected.");
    }
}