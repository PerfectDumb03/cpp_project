#include "../include/Game.h"
#include "../include/GameHandler.h"
#include "../include/GameOverScreen.h"

#include <string>

int main() {
    Player player;
    GameSettings gameSettings;
    GameHandler gameHandler(player, gameSettings);
    std::string cascadeFilePath = "../haarcascade_frontalface_default.xml";
    Game game(cascadeFilePath);
    gameHandler.gameStartInput();
    game.run(gameHandler);
    return 0;
}
