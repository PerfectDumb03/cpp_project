//
// Created by lucan on 11.07.2025.
//

#ifndef CATCHOBJECTS_H
#define CATCHOBJECTS_H

#include "../include/GameMode.h"



class CatchObjects : public GameMode {
    std::list<GraphicalSquare> m_squares;

    void createObjects() override;
    void removeOutOfBounds() override;
    bool circleChance() override;
    void checkFaceCollision() override;
};



#endif //CATCHOBJECTS_H
