#ifndef CATCHSQUARES_H
#define CATCHSQUARES_H

#include "../include/GameMode.h"

class GameHandler;

class CatchSquares : public GameMode{
private:
    int m_objectsDestroyed = 0;

public:
    CatchSquares(GameHandler& gameHandler);
    ~CatchSquares() = default;

    void renderGraphics(cv::Mat& frame) override;
    void move() override;
    void createObjects() override;
    void removeOutOfBounds() override;
    void checkFaceCollision() override;
};



#endif //CATCHSQUARES_H
