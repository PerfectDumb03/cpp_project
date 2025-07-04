//
// Created by Luca on 03.07.2025.
//

#include "../include/CatchSquares.h"

#include <codecvt>

#include "../include/GameHandler.h"

//temporary for working version
CatchSquares::CatchSquares(int catschSquaresobjectCount){
    objectCount = catschSquaresobjectCount;
}

std::vector<GraphicalSquare> CatchSquares::getFaceSquares() {
    return m_faceSquares;
}
std::list<GraphicalSquare> CatchSquares::getSquares() {
    return m_squares;
}
std::list<GraphicalCircle> CatchSquares::getCircles() {
    return m_circles;
}
int CatchSquares::getFrameCount() {
    return m_frameCount;
}
void CatchSquares::setFrameCount(int newValue) {
    m_frameCount = newValue;
}
void CatchSquares::addFaceSquare(GraphicalSquare& newFace) {
    m_faceSquares.push_back(newFace);
}
void CatchSquares::addSquare(GraphicalSquare& newSquare) {
    m_squares.push_back(newSquare);
}
void CatchSquares::addCircle(GraphicalCircle& newCircle) {
    m_circles.push_back(newCircle);
}
void CatchSquares::setObjectCount(int newValue) {
    objectCount = newValue;
}

void CatchSquares::renderGraphics(cv::Mat &frame) {
    for (auto& face : m_faceSquares) { //should be const for best practice
        face.draw(frame);
    }
    for (auto& square : m_squares) {
        square.draw(frame);
    }
    for (auto& circle : m_circles) {
        circle.draw(frame);
    }
    setFrameCount(getFrameCount() + 1);
}

void CatchSquares::createObjects() {
    int objectCount = getObjectCount();
    if (objectCount > 0) {
        int currentFrame = getFrameCount();
        if (currentFrame % 25 == 0) {
            if (circleChance()) {
                GraphicalCircle circle(randXCoord(), {255, 0, 0});
                addCircle(circle);
            }
            else {
                GraphicalSquare square(randXCoord(),  {0, 255, 0});
                addSquare(square);
            }
            setObjectCount(--objectCount);
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

int CatchSquares::randXCoord() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 680); //toDo Use framewidth from Game
    return dis(gen);
}

void CatchSquares::resetFaceSquares() {
    m_faceSquares.clear();
}

void CatchSquares::removeOutOfBounds() {
    int frameHeight = 480; // ToDo: Use actual frame height from Game

    m_squares.remove_if([frameHeight](GraphicalSquare& square) {
        return square.checkOutOfBounds(frameHeight);
    });

    m_circles.remove_if([frameHeight](GraphicalCircle& circle) {
        return circle.checkOutOfBounds(frameHeight);
    });
}

void CatchSquares::checkFaceCollision(GameHandler& gameHandler) {
    for (auto& face : m_faceSquares) {
        m_squares.remove_if([&](GraphicalSquare& square) {
            if (square.checkCollision(face)) {
                gameHandler.addScore(1);
                return true;
            }
            return false;
        });
        m_circles.remove_if([&](GraphicalCircle& circle) {
            if (circle.checkCollision(face)) {
                gameHandler.subtractScore(1);
                return true;
            }
            return false;
        });
    }
}

//not used anymore - Pending deletion
void CatchSquares::increaseScore() {
    addScore(1);
    std::cout << "Score increased!" << getScore() << std::endl;
}

//not used anymore - Pending deletion
void CatchSquares::decreaseScore() {
    subtractScore(1);
    std::cout << "Score decreased!" << getScore() << std::endl;
}





