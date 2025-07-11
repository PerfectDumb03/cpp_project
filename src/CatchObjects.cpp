//
// Created by lucan on 11.07.2025.
//

#include "../include/CatchObjects.h"

void CatchObjects::createObjects() {
    if (m_frameCount % 25 == 0) {
        if (circleChance()) {
            GraphicalCircle circle(randXCoord(), {255, 0, 0});
            addCircle(circle);
        } else {
            GraphicalSquare square(randXCoord(), {0, 255, 0});
            addSquare(square);
        }
    }
}
