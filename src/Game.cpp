#include "../include/Game.h"
#include "../include/Leaderboard.h"
#include "../include/GameModeFactory.h"
#include "../include/GameOverScreen.h"

#include <iostream>

Game::Game(const std::string& cascadePath) : frameWidth(0), frameHeight(0) {
    faceCascade.load(cascadePath);
}

Game::~Game() {
    if (cap.isOpened()) {
        cap.release();
    }
    cv::destroyAllWindows();
}

bool Game::initialize(GameHandler& gameHandler) {
    cap.open(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera." << std::endl;
        return false;
    }
    frameWidth = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    frameHeight = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    if (frameWidth != 0 || frameHeight != 0) {
        gameHandler.setFrameWidth(frameWidth);
        cap.set(cv::CAP_PROP_FRAME_WIDTH, frameWidth);
        gameHandler.setFrameHeight(frameHeight);
        cap.set(cv::CAP_PROP_FRAME_HEIGHT, frameHeight);
    }
    if (faceCascade.empty()) {
        std::cerr << "Error: Could not load Haar cascade file." << std::endl;
        return false;
    }
    cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);
    return true;
}
std::vector<cv::Rect> Game::getFaceRects(cv::Mat& frame) {
    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(frame, faces, 1.1, 3, 0, cv::Size(60, 60));
    return faces;
}

void Game::executeGameLoop(GameMode* currentGame, cv::Mat& frame) {
    std::vector<cv::Rect> faces = getFaceRects(frame);
    currentGame->addFaceSquare(faces);
    currentGame->createObjects();
    currentGame->renderGraphics(frame);
    currentGame->checkFaceCollision();
    currentGame->move();
    currentGame->removeOutOfBounds();
    currentGame->resetFaceSquares();
}

void Game::showScoreIngame(GameHandler& gameHandler, cv::Mat& frame) {
    std::string scoreText = "Score: " + std::to_string(gameHandler.getScore());
    int font = cv::FONT_HERSHEY_SIMPLEX;
    cv::Size textSize = cv::getTextSize(scoreText, font, 1.5, 2, 0);
    cv::Point scoreTextPos((frame.cols - textSize.width) / 2, 100);
    cv::putText(frame, scoreText, cv::Point(5,30), font, 1.0, cv::Scalar(255, 0, 255), 2);
}

void Game::restartLoop() {
    std::cout << "Press 0 to end game.\nPress 1 to play new game." << std::endl;
    int input;
    std::cin >> input;
    if (input == 0) {
        breakLoop = true;
    } else if (input == 1) {
        breakLoop = false;
    } else {
        std::cout << "Invalid input. Try again.\n";
        restartLoop();
    }
}

void Game::loop() {
    while (breakLoop == false) {
        Player player;
        GameSettings gameSettings;
        GameHandler gameHandler(player, gameSettings);
        gameHandler.gameStartInput();
        run(gameHandler);
        Leaderboard leaderboard("../leaderboard.txt");
        leaderboard.addPlayer(gameHandler.getGameMode() , gameHandler.getPlayerName(), gameHandler.getScore());
        leaderboard.printLeaderboardByGamemode(gameHandler.getGameMode());
        restartLoop();
    }
}

void Game::run(GameHandler& gameHandler) {
    if (!initialize(gameHandler)) return;
    cv::Mat frame;
    auto currentGame = GameModeFactory::create(gameHandler.getGameMode(), gameHandler);

    while (true) {
        cap >> frame;
        if (frame.empty()) break;
        cv::flip(frame, frame, 1);

        executeGameLoop(currentGame.get(), frame);
        showScoreIngame(gameHandler, frame);

        cv::imshow(windowName, frame);
        int key = cv::waitKey(10);
        // Break if the window is closed using the red X or ESC to exit
        if (cv::getWindowProperty(windowName, cv::WND_PROP_VISIBLE) < 1 || key == 27 ||
            currentGame->getGameState()) {
            cv::destroyAllWindows();
            GameOverScreen::show(gameHandler.getPlayerName(), gameHandler.getScore());
            break;
        }
    }
}
