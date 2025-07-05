//
// Created by Luca on 04.07.2025.
//

#ifndef GAMEMODE_H
#define GAMEMODE_H
#include "../include/GraphicalSquare.h"
#include "../include/GraphicalCircle.h"
#include <opencv2/opencv.hpp>


class GameHandler;

class GameMode{
protected:
    GameHandler& m_gameHandler;
    int m_frameCount = 0;
    int m_objectCount;
    std::vector<GraphicalSquare> m_faceSquares;
    std::list<GraphicalCircle> m_circles;

public:
    GameMode(GameHandler& gameHandler);
    virtual ~GameMode() = default;

    std::vector<GraphicalSquare> getFaceSquares();
    std::list<GraphicalCircle> getCircles();
    int getObjectCount();

    void addFaceSquare(GraphicalSquare& newFace);
    void addCircle(GraphicalCircle& newCircle);

    virtual void resetFaceSquares();

    virtual int randXCoord();
    virtual void renderGraphics(cv::Mat& frame);
    virtual void move();
    virtual void createObjects();
    virtual void checkFaceCollision();
    virtual void removeOutOfBounds();
};

#endif //GAMEMODE_H
