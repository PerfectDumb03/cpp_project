//
// Created by Luca on 04.07.2025.
//
#include "../include/CatchBalls.h"
#include "../include/GameHandler.h""

CatchBalls::CatchBalls(GameHandler& gameHandler):GameMode(gameHandler) {}


void CatchBalls::checkFaceCollision() {
    for (auto& face : m_faceSquares) {
        m_circles.remove_if([&](GraphicalCircle& circle) {
            if (circle.checkCollision(face)) {
                //ToDo end game
                return true;
            }
            return false;
        });
    }
}

void CatchBalls::removeOutOfBounds(GameHandler& gameHandler) {
    int frameheigt = 480; //ToDo add dynamic frame height
    for (auto& face : m_faceSquares) {
        m_circles.remove_if([&](GraphicalCircle& circle) {
            if (circle.checkOutOfBounds(frameheigt)) {
                gameHandler.addScore(1);
                return true;
            }
            return false;
        });
    }
}


