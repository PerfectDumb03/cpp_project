//
// Created by Thomas on 03.07.2025.
//
#include <iostream>

#include "../include/InputHandler.h"

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
}

void InputHandler::setObjectCount() {
    std::cout << "With how many objects do you want to play? Input an appropriate number." << std::endl;
    std::cin >> objectCount;
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