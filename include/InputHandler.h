#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
#include <map>

class InputHandler {
public:
    static std::string requestPlayerName();
    static int requestGameMode();
    static int requestObjectCount();
private:
    static const std::map<int, std::string> gameModes;
};

#endif //INPUTHANDLER_H
