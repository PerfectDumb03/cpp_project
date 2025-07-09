#include "../include/Game.h"
#include "../include/GameHandler.h"
#include "../include/GameOverScreen.h"

#include <string>

#include "../include/Leaderboard.h"

int main() {
    std::string cascadeFilePath = "../haarcascade_frontalface_default.xml";
    Game game(cascadeFilePath);
    game.loop();
    return 0;
}
