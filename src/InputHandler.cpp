#include "../include/InputHandler.h"
#include <limits>
#include <iostream>

#define MAX_OBJECT_COUNT 100

std::string InputHandler::requestPlayerName() {
    std::string name;
    while (true) {
        std::cout << "Please enter your name (whitespace allowed; maximum 14 characters): ";
        std::getline(std::cin >> std::ws, name);
        if (!name.empty() && name.length() <= 14) {
            return name;
        }
        std::cout << "Name cannot be empty or longer than 14 characters. Try again.\n";
    }
}

//For new gameMode implement input for game here
const std::map<int, std::string> InputHandler::gameModes = {
    {1, "DodgeBalls"},
    {2, "CatchSquares"}
};

int InputHandler::requestGameMode() {
    int gameMode;
    while (true) {
        std::cout << "Which gamemode do you want to play? Input an appropriate number.\n";
        for (const auto& [key, value] : gameModes) {
            std::cout << key << ": " << value << "\n";
        }
        std::cin >> gameMode;

        if (std::cin.fail()) {
            // Wrong input type (char, string, long, etc.)
            std::cin.clear(); // Reset fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // dismiss invalid input
            std::cout << "Invalid input type. Please enter a number.\n";
            continue;
        }

        if (gameModes.find(gameMode) != gameModes.end()) {
            std::cin.ignore();
            return gameMode;
        }

        std::cout << "Invalid gamemode. Try again.\n";
    }
}

int InputHandler::requestObjectCount() {
    int objectCount;
    while (true) {
        std::cout << "How many objects do you want to catch? (1 - " << MAX_OBJECT_COUNT << ")\n";
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
            return objectCount;
        }
    }
}