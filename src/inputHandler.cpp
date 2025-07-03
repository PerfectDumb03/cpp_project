//
// Created by Thomas on 03.07.2025.
//
#include <iostream>

#include "../include/InputHandler.h"

#define MAX_OBJECT_COUNT 100

//Setter
void InputHandler::setPlayerName() {
    std::cout << "Please enter your name: ";
    std::cin >> playerName;
}
void InputHandler::setGameMode() {
    std::cout << "Which gamemode do you want to play? Input an appropriate number." << std::endl;
    std::cout << "1: Dodge balls" << std::endl;
    std::cout << "2: Catch squares" << std::endl;
    std::cin >> gameMode;
    if (gameMode != 1 && gameMode != 2) {
        std::cout << "Invalid gamemode. Try again. " << std::endl;
        setGameMode();
    }
}

void InputHandler::setObjectCount() {
    switch (gameMode) {
        case 1:
            std::cout << "How many balls do you want to dodge? Input an appropriate number." << std::endl;
            std::cin >> objectCount;
            break;
        case 2:
            std::cout << "How many squares do you want to catch? Input an appropriate number." << std::endl;
            std::cin >> objectCount;
            break;
        default:
            std::cout << "Invalid gamemode. Try again. " << std::endl;
            setGameMode();
            setObjectCount();
            break;
    }
    if (objectCount < 1) {
        std::cout << "Invalid number of objects. Try again. " << std::endl;
        setObjectCount();
    } else if (objectCount > MAX_OBJECT_COUNT) {
        std::cout << "Too many objects. Try again. " << std::endl;
        setObjectCount();
    }
}

//Getter
std::string InputHandler::getPlayerName() const {
    return playerName;
}

int InputHandler::getGameMode() const {
    return gameMode;
}

int InputHandler::getObjectCount() const {
    return objectCount;
}