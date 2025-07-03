//
// Created by Thomas on 03.07.2025.
//
#include <iostream>
#include <limits>

#include "../include/InputHandler.h"

#define MAX_OBJECT_COUNT 100

//Setter
void InputHandler::setPlayerName() {
    while (true) {
        std::cout << "Please enter your name (whitespace allowed): ";
        std::getline(std::cin >> std::ws, playerName);

        if (!playerName.empty())
            break;

        std::cout << "Name cannot be empty. Try again.\n";
    }
}

void InputHandler::setGameMode() {
    while (true) {
        std::cout << "Which gamemode do you want to play? Input an appropriate number.\n";
        std::cout << "1: Dodge balls\n";
        std::cout << "2: Catch squares\n";
        std::cin >> gameMode;

        if (std::cin.fail()) {
            // Wrong input type (char, string, long, etc.)
            std::cin.clear(); // Reset fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // dismiss invalid input
            std::cout << "Invalid input type. Please enter a number.\n";
            continue;
        }

        if (gameMode == 1 || gameMode == 2) {
            std::cin.ignore();
            break;
        }

        std::cout << "Invalid gamemode. Try again.\n";
    }
}

void InputHandler::setObjectCount() {
    while (true) {
        switch (gameMode) {
            case 1:
                std::cout << "How many balls do you want to dodge? Input an appropriate number: ";
                break;
            case 2:
                std::cout << "How many squares do you want to catch? Input an appropriate number: ";
                break;
            default:
                std::cout << "Invalid gamemode. Try again.\n";
                setGameMode();
                continue;
        }

        std::cin >> objectCount;

        if (std::cin.fail()) {
            std::cin.clear(); // Reset fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // dismiss invalid input
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove additional input

        if (objectCount < 1) {
            std::cout << "Invalid number of objects. Must be at least 1. Try again.\n";
        } else if (objectCount > MAX_OBJECT_COUNT) {
            std::cout << "Too many objects (max: " << MAX_OBJECT_COUNT << "). Try again.\n";
        } else {
            break;
        }
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