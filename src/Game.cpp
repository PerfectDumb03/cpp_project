#include "../include/Game.h"
#include <iostream>

#include "../include/GameModeFactory.h"
#include "../include/GameOverScreen.h"

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
        std::cout << "Frame size: " << frameWidth << "x" << frameHeight << std::endl;
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
            (currentGame->getObjectCount() == 0 && currentGame->getObjectsCreated() == 0)) {
            cv::destroyAllWindows();
            GameOverScreen::show(gameHandler.getPlayerName(), gameHandler.getScore());
            break;
        }
    }
}
