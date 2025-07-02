//
// Created by tvahl on 02.07.2025.
//

#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>

class InputHandler {
public:
    static std::string getPlayerName();
    static int getGameMode();
    static int getObjectCount();
};

#endif // INPUT_HANDLER_H