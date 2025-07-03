#ifndef GAME_H
#define GAME_H

#include "InputHandler.h"
#include "Player.h"
#include <opencv2/opencv.hpp>
#include <string>

class Game {
public:
    Game(const std::string& cascadePath);
    ~Game();
    bool initialize();
    void run();
    void gameStartInput(InputHandler& input, Player& player);
    std::vector<cv::Rect> getFaceRects(cv::Mat& frame);
private:
    cv::VideoCapture cap;
    cv::CascadeClassifier faceCascade;
    const std::string windowName = "Face Detection";
    int frameWidth;
    int frameHeight;
};

#endif // GAME_H
