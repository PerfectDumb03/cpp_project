#include "../include/Game.h"
#include "../include/GameHandlerOld.h"
#include <string>

#include "../include/GameOverScreen.h"

int main() {
    GameHandlerOld gameHandler;
    std::string cascadeFilePath = "../haarcascade_frontalface_default.xml";
    Game game(cascadeFilePath);
    gameHandler.gameStartInput();
    game.run(gameHandler);
    GameOverScreen::show(gameHandler.getName(), gameHandler.getScore());
    return 0;
}
