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
void GameMode::addFaceSquare(GraphicalSquare& newFace) {
    m_faceSquares.push_back(newFace);
}
void GameMode::addCircle(GraphicalCircle& newCircle) {
    m_circles.push_back(newCircle);
}
void GameMode::resetFaceSquares() {
    m_faceSquares.clear();
}
int GameMode::randXCoord() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 680); //toDo Use framewidth from Game
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
    if (m_objectCount > 0) {
        if (m_frameCount % 25 == 0) {
            GraphicalCircle circle(randXCoord(),  {-1, -1, -1});
            addCircle(circle);
            --m_objectCount;
        }
    }
}