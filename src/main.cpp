#include "../include/Game.h"
#include "../include/GameHandler.h"
#include "../include/GameOverScreen.h"

#include <string>

#include "../include/Leaderboard.h"

int main() {
    Player player;
    GameSettings gameSettings;
    GameHandler gameHandler(player, gameSettings);
    std::string cascadeFilePath = "../haarcascade_frontalface_default.xml";
    Game game(cascadeFilePath);
    gameHandler.gameStartInput();
    game.run(gameHandler);
    Leaderboard leaderboard("../leaderboard.txt");
    leaderboard.addPlayer(gameHandler.getPlayerName(), gameHandler.getScore());
    leaderboard.printLeaderboard();
    return 0;
}
