//
// Created by Luca on 04.07.2025.
//

#ifndef CATCHBALLS_H
#define CATCHBALLS_H
#include "GameMode.h"

class CatchBalls: public GameMode {
public:
    CatchBalls(GameHandler& gameHandler);
    ~CatchBalls() = default;

    void checkFaceCollision();
    void removeOutOfBounds(GameHandler& gameHandler);
};
#endif //CATCHBALLS_H
