//
// Created by Luca on 04.07.2025.
//

#include "../include/GameMode.h"
#include "../include/GameHandler.h"

GameMode::GameMode(GameHandler& gameHandler) : m_gameHandler(gameHandler), m_objectCount(gameHandler.getObjectCount()) {}

std::vector<GraphicalSquare> GameMode::getFaceSquares() {
    return m_faceSquares;
}
std::list<GraphicalCircle> GameMode::getCircles() {
    return m_circles;
}
int GameMode::getObjectCount() {
    return m_objectCount;
}
int GameMode::getObjectsCreated() {
    return m_objectsCreated;
}
bool GameMode::getGameState() {
    return m_isGameOver;
}
void GameMode::addFaceSquare(std::vector<cv::Rect>& faceRects) {
    for (auto& face : faceRects) {
        GraphicalSquare faceSquare(face, 2, {0, 0, 255});
        m_faceSquares.push_back(faceSquare);
    }
}
void GameMode::addCircle(GraphicalCircle& newCircle) {
    m_circles.push_back(newCircle);
    m_objectsCreated++;
}
void GameMode::resetFaceSquares() {
    m_faceSquares.clear();
}
int GameMode::randXCoord() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, m_gameHandler.getFrameWidth() - 50); //50 is max "width" of a circle
    return dis(gen);
}
void GameMode::renderGraphics(cv::Mat &frame) {
    for (auto& face : m_faceSquares) { //should be const for best practice
        face.draw(frame);
    }
    for (auto& circle : m_circles) {
        circle.draw(frame);
    }
    ++m_frameCount;
}
void GameMode::move() {
    for (auto& circle : m_circles) {
        circle.move();
    }
}
void GameMode::createObjects() {
    if (m_frameCount % 25 == 0) {
        GraphicalCircle circle(randXCoord(),  {-1, -1, -1});
        addCircle(circle);
    }
}
void GameMode::checkFaceCollision() {
    for (auto& face : m_faceSquares) {
        m_circles.remove_if([&](GraphicalCircle& circle) {
            if (circle.checkCollision(face)) {
                m_isGameOver = true;
                return true;
            }
            return false;
        });
    }
}

void GameMode::removeOutOfBounds() {
     m_circles.remove_if([&](GraphicalCircle& circle) {
         if (circle.checkOutOfBounds(m_gameHandler.getFrameHeight())) {
             m_gameHandler.addScore(1);
             m_objectsCreated--;
             return true;
         }
         return false;
     });
}