#ifndef GAME_H
#define GAME_H

#include "GameHandler.h"
#include <opencv2/opencv.hpp>

class GameMode;

class Game {
public:
    Game(const std::string& cascadePath);
    virtual ~Game();
    bool initialize(GameHandler& gameHandler);
    void run(GameHandler& gameMode);
    std::vector<cv::Rect> getFaceRects(cv::Mat& frame);
private:
    void executeGameLoop(GameMode* currentGame, cv::Mat& frame);
    void showScoreIngame(GameHandler& gameHandler, cv::Mat& frame);
    cv::VideoCapture cap;
    cv::CascadeClassifier faceCascade;
    const std::string windowName = "Face Detection";
    int frameWidth;
    int frameHeight;
};

#endif // GAME_H
