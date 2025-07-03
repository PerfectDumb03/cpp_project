#include "../include/Game.h"
#include <string>

int main() {
    InputHandler input;
    Player player;
    std::string cascadeFilePath = "../haarcascade_frontalface_default.xml";
    Game game(cascadeFilePath);
    //game.gameStartInput(input, player);
    game.run();
    return 0;
}
