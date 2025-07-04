#include "../include/Game.h"
#include "../include/GameHandler.h"
#include <string>

int main() {
    GameHandler gameMode;
    std::string cascadeFilePath = "../haarcascade_frontalface_default.xml";
    Game game(cascadeFilePath);
    gameMode.gameStartInput();
    game.run(gameMode);
    gameMode.gameOver();
    return 0;
}
