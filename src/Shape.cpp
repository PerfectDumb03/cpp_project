//
// Created by Luca on 01.07.2025.
//

#include "../include/Shape.h"

Shape::Shape(int x, int y): m_x(x), m_y(y){

}

void Shape::move() {
    m_y += m_speed;
}

bool Shape::checkOutOfBounds(int frameHeight) {
    return m_y > frameHeight;
}

bool Shape::checkCollision(ShapeSquare& FaceRect) {
    return true;
}

int Shape::getX() {
    return m_x;
}

int Shape::getY() {
    return m_y;
}
int Shape::getSpeed() {
    return m_speed;
}

void Shape::setSpeed(int newValue) {
    m_speed = newValue;
}
