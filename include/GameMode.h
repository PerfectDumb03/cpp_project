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
    int m_frameCount = 0;
    int m_objectCount;
    std::vector<GraphicalSquare> m_faceSquares;
    std::list<GraphicalCircle> m_circles;

public:
    GameMode(int objectCount);
    virtual ~GameMode() = default;

    virtual std::vector<GraphicalSquare> getFaceSquares();
    virtual std::list<GraphicalCircle> getCircles();
    int getObjectCount();

    virtual void addFaceSquare(GraphicalSquare& newFace);
    virtual void addCircle(GraphicalCircle& newCircle);

    virtual void resetFaceSquares();

    virtual int randXCoord();
    virtual void renderGraphics(cv::Mat& frame);
    virtual void move();
    virtual void createObjects();
};


#endif //GAMEMODE_H
