//
// Created by tvahl on 02.07.2025.
//

#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>

class InputHandler {
public:
    InputHandler() {};
    ~InputHandler() {};

    void setPlayerName();
    void setGameMode();
    void setObjectCount();

    std::string getPlayerName() const;
    int getGameMode() const;
    int getObjectCount() const;

private:
    std::string playerName;
    int gameMode = 0;
    int objectCount = 0;
};

#endif // INPUT_HANDLER_H