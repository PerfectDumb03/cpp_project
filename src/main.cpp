#include "../include/Game.h"
#include "../include/GameMode.h"
#include <string>

int main() {
    GameMode gameMode;
    std::string cascadeFilePath = "../haarcascade_frontalface_default.xml";
    Game game(cascadeFilePath);
    gameMode.gameStartInput();
    game.run(gameMode);
    gameMode.gameOver();
    return 0;
}
