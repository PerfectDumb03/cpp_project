//
// Created by Luca on 03.07.2025.
//

#ifndef CATCHSQUARES_H
#define CATCHSQUARES_H

#include "../include/GameMode.h"

class GameHandler;

class CatchSquares : public GameMode{
private:
    std::list<GraphicalSquare> m_squares;

public:
    CatchSquares(GameHandler& gameHandler);
    ~CatchSquares() = default;

    std::list<GraphicalSquare> getSquares();
    void addSquare(GraphicalSquare& newSquare);

    void renderGraphics(cv::Mat& frame) override;
    void move() override;
    void createObjects() override;
    void removeOutOfBounds() override;
    void checkFaceCollision() override;
    bool circleChance();
};



#endif //CATCHSQUARES_H
