//
// Created by Luca on 01.07.2025.
//

#include "../include/Shape.h"

Shape::Shape(int x, int y, int speed): m_x(x), m_y(y), m_speed(speed) {
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
