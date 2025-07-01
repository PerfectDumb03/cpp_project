//
// Created by Luca on 01.07.2025.
//

#include "../include/Shape.h"

Shape::Shape(int x, int y, std::array<int,3> color = {0,255,0}): m_x(x), m_y(y), m_color(color={-1,-1,-1}) {
    if (color[0]==-1) {
        randomizeColor();
    }
}

void Shape::move() {
    m_y += m_speed;
}

bool Shape::checkOutOfBounds(int frameHeight) {
    return m_y > frameHeight;
}

bool Shape::checkCollision(const Shape& FaceRect) {
    return true;
}

void Shape::randomizeColor() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    for (int i = 0; i < 3; i++) {
        m_color[i] = dis(gen);
    }
}

int Shape::getX() {
    return m_x;
}

int Shape::getY() {
    return m_y;
}

void Shape::setSpeed(int newValue) {
    m_speed = newValue;
}

void Shape::setThickness(int newValue) {
    thickness = newValue;
}
