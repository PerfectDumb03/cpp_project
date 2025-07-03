//
// Created by Luca on 03.07.2025.
//

#ifndef CATCHSQUARES_H
#define CATCHSQUARES_H
#include <opencv2/opencv.hpp>
#include "GameMode.h"
#include "../include/GraphicalSquare.h"
#include "../include/GraphicalCircle.h"


class CatchSquares : public GameMode{
private:
    int m_score = 0;
    int m_objectCount;
    int m_frameCount = 0;
    std::vector<GraphicalSquare> m_faceSquares;
    std::list<GraphicalSquare> m_squares;
    std::list<GraphicalCircle> m_circles;

public:
    CatchSquares(int objectCount);
    ~CatchSquares() = default;

    std::vector<GraphicalSquare> getFaceSquares();
    std::list<GraphicalSquare> getSquares();
    std::list<GraphicalCircle> getCircles();
    int getObjectCount();
    int getFrameCount();

    void setFrameCount(int newValue);
    void setObjectCount(int newValue);
    void addFaceSquare(GraphicalSquare& newFace);
    void addSquare(GraphicalSquare& newSquare);
    void addCircle(GraphicalCircle& newCircle);
    void increaseScore();
    void decreaseScore();

    void resetFaceSquares();

    void renderGraphics(cv::Mat& frame);
    void removeOutOfBounds();
    void checkFaceCollision();
    void move();
    void createObjects();
    bool circleChance();
    int randXCoord();
};



#endif //CATCHSQUARES_H
