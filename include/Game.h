#ifndef GAME_H
#define GAME_H

#include "GameHandlerOld.h"

class Game {
public:
    Game(const std::string& cascadePath);
    virtual ~Game();
    bool initialize();
    void run(GameHandlerOld& gameMode);
    std::vector<cv::Rect> getFaceRects(cv::Mat& frame);
private:
    cv::VideoCapture cap;
    cv::CascadeClassifier faceCascade;
    const std::string windowName = "Face Detection";
    int frameWidth;
    int frameHeight;
};

#endif // GAME_H
