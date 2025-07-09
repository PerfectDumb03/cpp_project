#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>

class InputHandler {
public:
    static std::string requestPlayerName();
    static int requestGameMode();
    static int requestObjectCount(int gameMode);
};

#endif //INPUTHANDLER_H
