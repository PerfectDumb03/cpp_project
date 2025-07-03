//
// Created by Thomas on 03.07.2025.
//

#include "../include/Game.h"

void gameStartInputPrint(InputHandler& input, Player& player) {
    std::cout << "Gamemode: " << input.getGameMode() << std::endl;
    std::cout << "ObjectCount: " << input.getObjectCount() << std::endl;
    std::cout << "Player: " << player.getName() << std::endl;
    std::cout << "Score: " << player.getScore() << std::endl;
}

void Game::gameStartInput(InputHandler& input, Player& player) {
    input.setPlayerName();
    player.setName(input.getPlayerName());
    player.setScore(0);
    input.setGameMode();
    input.setObjectCount();
    gameStartInputPrint(input, player);
}

