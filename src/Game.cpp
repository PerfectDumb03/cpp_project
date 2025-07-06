#include "../include/Game.h"
#include <iostream>

#include "../include/CatchSquares.h"
#include "../include/GameHandler.h"
#include "../include/GraphicalSquare.h"
#include "../include/GraphicalCircle.h"
#include "../include/CatchBalls.h"

Game::Game(const std::string& cascadePath) : frameWidth(0), frameHeight(0) {
    faceCascade.load(cascadePath);
}

Game::~Game() {
    if (cap.isOpened()) {
        cap.release();
    }
    cv::destroyAllWindows();
}

bool Game::initialize() {
    cap.open(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera." << std::endl;
        return false;
    }
    frameWidth = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    frameHeight = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    if (frameWidth == 0 || frameHeight == 0) {
        frameWidth = 640;
        frameHeight = 480;
        cap.set(cv::CAP_PROP_FRAME_WIDTH, frameWidth);
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


void Game::run(GameHandler& gameHandler) {
    if (!initialize()) return;
    cv::Mat frame;
    CatchSquares currentGame(gameHandler);
    while (true) {
        cap >> frame;
        if (frame.empty()) break;
        cv::flip(frame, frame, 1);
        std::vector<cv::Rect> faces = getFaceRects(frame);
        for (auto& face : faces) {
            GraphicalSquare faceSquare(face, 2, {0, 0, 255});
            currentGame.addFaceSquare(faceSquare);
        }

        currentGame.createObjects();
        currentGame.renderGraphics(frame);
        currentGame.checkFaceCollision();
        currentGame.move();
        currentGame.removeOutOfBounds();
        currentGame.resetFaceSquares();
        if (currentGame.getObjectCount() == 0 && currentGame.getObjectsCreated() == 0) {
            cv::destroyWindow(windowName);
            break;
        }

        cv::imshow(windowName, frame);
        int key = cv::waitKey(10);
        if (key == 27) break; // ESC to exit
        // Break if the window is closed using the red X
        if (cv::getWindowProperty(windowName, cv::WND_PROP_VISIBLE) < 1) {
            cv::destroyWindow(windowName);
            break;
        }
    }
}
