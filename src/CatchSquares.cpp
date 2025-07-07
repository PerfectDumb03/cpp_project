//
// Created by Luca on 03.07.2025.
//

#include "../include/CatchSquares.h"
#include "../include/GameHandler.h"

//temporary for working version
CatchSquares::CatchSquares(GameHandler& gameHandler): GameMode(gameHandler) {
}


std::list<GraphicalSquare> CatchSquares::getSquares() {
    return m_squares;
}
void CatchSquares::addSquare(GraphicalSquare& newSquare) {
    m_squares.push_back(newSquare);
}

void CatchSquares::renderGraphics(cv::Mat &frame) {
    if (m_objectCount <= 0) {
        m_isGameOver = true;
        return;
    }

    for (auto& face : m_faceSquares) { //should be const for best practice
        face.draw(frame);
    }
    for (auto& square : m_squares) {
        square.draw(frame);
    }
    for (auto& circle : m_circles) {
        circle.draw(frame);
    }
    ++m_frameCount;
}

void CatchSquares::createObjects() {
    if (m_objectCount > 0) {
        if (m_frameCount % 25 == 0) {
            if (circleChance()) {
                GraphicalCircle circle(randXCoord(), {255, 0, 0});
                addCircle(circle);
            }
            else {
                GraphicalSquare square(randXCoord(),  {0, 255, 0});
                addSquare(square);
            }
        }
    }
}
void CatchSquares::move() {
    for (auto& square : m_squares) {
        square.move();
    }
    for (auto& circle : m_circles) {
        circle.move();
    }
}

bool CatchSquares::circleChance() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);
    if (dis(gen) < 33) {
        return true;
    }
    return false;
}

void CatchSquares::removeOutOfBounds() {
    int frameHeight = m_gameHandler.getFrameHeight();
    m_squares.remove_if([frameHeight, this](GraphicalSquare& square) {
        if (square.checkOutOfBounds(frameHeight)) {
            --m_objectCount;
            return true;
        }
        return false;
    });
    m_circles.remove_if([frameHeight, this](GraphicalCircle& circle) {
        if (circle.checkOutOfBounds(frameHeight)) {
            --m_objectCount;
            return true;
        }
        return false;
    });
}

void CatchSquares::checkFaceCollision() {
    for (auto& face : m_faceSquares) {
        m_squares.remove_if([&](GraphicalSquare& square) {
            if (square.checkCollision(face)) {
                m_gameHandler.addScore(1);
                --m_objectCount;
                return true;
            }
            return false;
        });
        m_circles.remove_if([&](GraphicalCircle& circle) {
            if (circle.checkCollision(face)) {
                m_gameHandler.addScore(-1);
                --m_objectCount;
                return true;
            }
            return false;
        });
    }
}





