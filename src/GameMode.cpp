//
// Created by Thomas on 03.07.2025.
//

#include "../include/GameMode.h"
#include <limits>


#define MAX_OBJECT_COUNT 100

void GameMode::setPlayerNameFromInput() {
    std::string name;
    while (true) {
        std::cout << "Please enter your name (whitespace allowed; maximum 14 characters): ";
        std::getline(std::cin >> std::ws, name);
        if (!name.empty() && name.length() <= 14) {
            setName(name);
            break;
        }
        std::cout << "Name cannot be empty or longer than 14 characters. Try again.\n";
    }
}

void GameMode::setGameMode() {
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

int GameMode::getGameMode() const {
    return gameMode;
}

void GameMode::setObjectCount() {
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

int GameMode::getObjectCount() const {
    return objectCount;
}

void GameMode::gameStartInput() {
    setPlayerNameFromInput();
    setGameMode();
    setObjectCount();
}

// Destroy playing window before calling function (e.g., cv::destroyWindow(windowName);)
void GameMode::gameOver() {
    // Generate black frame
    cv::Mat gameOverFrame = cv::Mat::zeros(600, 800, CV_8UC3);

    // Define text
    std::string gameOverText = "GAME OVER";
    std::string scoreText = playerName + "'s Score: " + std::to_string(playerScore);
    std::string closeText = "Press any key to exit...";
    int font = cv::FONT_HERSHEY_SIMPLEX;

    //Center score text for names with different length
    cv::Size textSize = cv::getTextSize(scoreText, font, 1.5, 2, 0);
    cv::Point scoreTextPos((gameOverFrame.cols - textSize.width) / 2, 300);

    // Draw text
    cv::putText(gameOverFrame, gameOverText, cv::Point(200, 200), font, 2.0, cv::Scalar(0, 0, 255), 3); // rot
    cv::putText(gameOverFrame, scoreText, scoreTextPos, font, 1.5, cv::Scalar(255, 255, 255), 2); // weiß
    cv::putText(gameOverFrame, closeText, cv::Point(200, 400), font, 1.0, cv::Scalar(100, 255, 100), 1); // grünlich

    // Show image
    cv::imshow("Game Over", gameOverFrame);
    cv::waitKey();
}